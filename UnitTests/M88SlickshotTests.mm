//
//  M88SlickshotTests.m
//  UnitTests
//
//  Created by Wu Tang on 6/4/26.
//

#import <Foundation/Foundation.h>

#include <XCTest/XCTest.h>
#include "M88.hpp"
#include <array>
#include <cstdint>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

@interface M88SlickshotTests : XCTestCase
@end

@implementation M88SlickshotTests

static std::size_t HammingDistance64(
    const std::array<std::uint8_t, 64>& a,
    const std::array<std::uint8_t, 64>& b
) {
    std::size_t distance = 0;

    for (std::size_t i = 0; i < 64U; ++i) {
        if (a[i] != b[i]) {
            ++distance;
        }
    }

    return distance;
}

struct SlickshotState {
    std::array<std::uint8_t, 64> data;
    std::array<std::uint8_t, 64> before;
    std::array<std::uint8_t, 64> after;

    bool operator==(const SlickshotState& other) const {
        return data == other.data &&
               before == other.before &&
               after == other.after;
    }
};

struct SlickshotStateHash {
    std::size_t operator()(const SlickshotState& state) const {
        std::size_t h = 1469598103934665603ULL;

        auto mix = [&h](std::uint8_t b) {
            h ^= static_cast<std::size_t>(b);
            h *= 1099511628211ULL;
        };

        for (std::uint8_t b : state.data) {
            mix(b);
        }

        for (std::uint8_t b : state.before) {
            mix(b);
        }

        for (std::uint8_t b : state.after) {
            mix(b);
        }

        return h;
    }
};

static SlickshotState CaptureState(const M88& m88) {
    SlickshotState state;

    std::memcpy(state.data.data(),   m88.mData,   state.data.size());
    std::memcpy(state.before.data(), m88.mBefore, state.before.size());
    std::memcpy(state.after.data(),  m88.mAfter,  state.after.size());

    return state;
}

static SlickshotState RunMini(std::uint8_t byte) {
    M88 m88;
    m88.Reset();
    m88.SlickshotMini(byte);
    return CaptureState(m88);
}

static SlickshotState RunQuadA(std::uint8_t byte) {
    M88 m88;
    m88.Reset();
    m88.SlickshotQuadA(byte);
    return CaptureState(m88);
}

static SlickshotState RunQuadB(std::uint8_t byte) {
    M88 m88;
    m88.Reset();
    m88.SlickshotQuadB(byte);
    return CaptureState(m88);
}

static SlickshotState RunQuadC(std::uint8_t byte) {
    M88 m88;
    m88.Reset();
    m88.SlickshotQuadC(byte);
    return CaptureState(m88);
}

static SlickshotState RunQuadD(std::uint8_t byte) {
    M88 m88;
    m88.Reset();
    m88.SlickshotQuadD(byte);
    return CaptureState(m88);
}

- (void)testSlickshotFunctionsArePairwiseDistinctFromReset {
    
    struct Candidate {
        const char* name;
        SlickshotState (*run)(std::uint8_t byte);
        std::uint8_t byte;
    };

    std::vector<Candidate> candidates;

    for (std::uint32_t i = 0; i < 256; ++i) {
        const std::uint8_t byte = static_cast<std::uint8_t>(i);

        candidates.push_back({ "Mini",  RunMini,  byte });
        candidates.push_back({ "QuadA", RunQuadA, byte });
        candidates.push_back({ "QuadB", RunQuadB, byte });
        candidates.push_back({ "QuadC", RunQuadC, byte });
        candidates.push_back({ "QuadD", RunQuadD, byte });
    }

    std::unordered_map<
        SlickshotState,
        std::string,
        SlickshotStateHash
    > seen;

    for (const Candidate& candidate : candidates) {
        
        const SlickshotState state = candidate.run(candidate.byte);

        char label[64];
        std::snprintf(
            label,
            sizeof(label),
            "%s[%02X]",
            candidate.name,
            candidate.byte
        );

        const auto found = seen.find(state);

        if (found != seen.end()) {
            XCTFail(
                @"Equivalent slickshot result from Reset(): %s == %s",
                found->second.c_str(),
                label
            );
        }

        seen.emplace(state, label);
    }
}

- (void)testSlickshotHammingDistancesFromReset {
    
    struct TransformResult {
        std::string name;
        std::array<std::uint8_t, 64> data;
        std::size_t distanceFromIdentity;
    };

    auto captureData = [](const M88& m88) {
        std::array<std::uint8_t, 64> data;
        std::memcpy(data.data(), m88.mData, data.size());
        return data;
    };

    auto identity = [] {
        std::array<std::uint8_t, 64> data;

        for (std::size_t i = 0; i < 64U; ++i) {
            data[i] = static_cast<std::uint8_t>(i);
        }

        return data;
    }();

    auto run = [&](const char* family, std::uint8_t byte) {
        M88 m88;
        m88.Reset();

        if (std::strcmp(family, "Mini") == 0) {
            m88.SlickshotMini(byte);
        } else if (std::strcmp(family, "QuadA") == 0) {
            m88.SlickshotQuadA(byte);
        } else if (std::strcmp(family, "QuadB") == 0) {
            m88.SlickshotQuadB(byte);
        } else if (std::strcmp(family, "QuadC") == 0) {
            m88.SlickshotQuadC(byte);
        } else if (std::strcmp(family, "QuadD") == 0) {
            m88.SlickshotQuadD(byte);
        }

        char label[64];
        std::snprintf(label, sizeof(label), "%s[%02X]", family, byte);

        const auto data = captureData(m88);

        return TransformResult {
            label,
            data,
            HammingDistance64(identity, data)
        };
    };

    std::vector<TransformResult> minis;
    std::vector<TransformResult> quads;

    for (std::uint32_t i = 0; i < 256U; ++i) {
        const std::uint8_t byte = static_cast<std::uint8_t>(i);

        minis.push_back(run("Mini", byte));

        quads.push_back(run("QuadA", byte));
        quads.push_back(run("QuadB", byte));
        quads.push_back(run("QuadC", byte));
        quads.push_back(run("QuadD", byte));
    }

    /*
        Identity distance report.

        Any distance of 0 means that transform is equivalent to identity
        on the reset state.
    */
    for (const TransformResult& result : minis) {
        if (result.distanceFromIdentity == 0U) {
            XCTFail(@"%s is equivalent to identity", result.name.c_str());
        }
    }

    for (const TransformResult& result : quads) {
        if (result.distanceFromIdentity == 0U) {
            XCTFail(@"%s is equivalent to identity", result.name.c_str());
        }
    }

    /*
        Compare minis to quads.
        This skips mini-to-mini comparisons.
    */
    for (const TransformResult& mini : minis) {
        for (const TransformResult& quad : quads) {
            const std::size_t distance = HammingDistance64(mini.data, quad.data);

            if (distance == 0U) {
                XCTFail(
                    @"Equivalent transform from Reset(): %s == %s",
                    mini.name.c_str(),
                    quad.name.c_str()
                );
            }
        }
    }

    /*
        Compare quads to quads.
        This checks QuadA/B/C/D against each other and within each quad family.
    */
    for (std::size_t i = 0; i < quads.size(); ++i) {
        for (std::size_t j = i + 1; j < quads.size(); ++j) {
            const std::size_t distance = HammingDistance64(
                quads[i].data,
                quads[j].data
            );

            if (distance == 0U) {
                XCTFail(
                    @"Equivalent transform from Reset(): %s == %s",
                    quads[i].name.c_str(),
                    quads[j].name.c_str()
                );
            }
        }
    }
}

@end

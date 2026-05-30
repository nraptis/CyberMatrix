//
//  TestSlickshotSix.m
//  UnitTests
//
//  Created by nick on 5/30/26.
//

#import <XCTest/XCTest.h>

#include "M88.hpp"
#include "Logging.hpp"

#include <array>
#include <cstdint>
#include <cstdio>
#include <random>
#include <set>
#include <string>

@interface TestSlickshotSix : XCTestCase

@end

@implementation TestSlickshotSix

static std::string MatrixKey(const M88 &pMatrix) {
    std::string aResult;
    aResult.reserve(64);

    for (std::size_t i = 0; i < 64U; i++) {
        aResult.push_back(static_cast<char>(pMatrix.mData[i]));
    }

    return aResult;
}

static bool SameMatrix(const M88 &pA, const M88 &pB) {
    for (std::size_t i = 0; i < 64U; i++) {
        if (pA.mData[i] != pB.mData[i]) {
            return false;
        }
    }

    return true;
}

static M88 RandomMatrix(std::mt19937 &pRng) {
    M88 aMatrix;

    std::array<std::uint8_t, 64> aBytes;
    for (std::size_t i = 0; i < 64U; i++) {
        aBytes[i] = static_cast<std::uint8_t>(i);
    }

    std::shuffle(aBytes.begin(), aBytes.end(), pRng);

    for (std::size_t i = 0; i < 64U; i++) {
        aMatrix.mData[i] = aBytes[i];
    }

    return aMatrix;
}

- (void)testSlickshotSixAllBytesUniqueFromReset {
    M88 aBefore;
    aBefore.Reset();

    std::set<std::string> aSeen;

    for (int byte = 0; byte < 256; byte++) {
        M88 aAfter = aBefore;
        aAfter.SlickshotSix(static_cast<std::uint8_t>(byte));

        const std::string aKey = MatrixKey(aAfter);

        if (aSeen.find(aKey) != aSeen.end()) {
            Logging::Log("Before", aBefore);
            Logging::Log("Duplicate After", aAfter);

            XCTFail(@"SlickshotSix duplicate result for byte %d / 0x%02X",
                    byte,
                    byte);
            return;
        }

        aSeen.insert(aKey);
    }

    XCTAssertEqual(aSeen.size(), static_cast<std::size_t>(256));
}

- (void)testSlickshotSixAllBytesUniqueRandomMatrices {
    std::mt19937 aRng(0xC0FFEEU);

    constexpr int kMatrixCount = 256;

    for (int trial = 0; trial < kMatrixCount; trial++) {
        M88 aBefore = RandomMatrix(aRng);

        std::set<std::string> aSeen;

        for (int byte = 0; byte < 256; byte++) {
            M88 aAfter = aBefore;
            aAfter.SlickshotSix(static_cast<std::uint8_t>(byte));

            const std::string aKey = MatrixKey(aAfter);

            if (aSeen.find(aKey) != aSeen.end()) {
                Logging::Log("Before", aBefore);
                Logging::Log("Duplicate After", aAfter);

                XCTFail(@"SlickshotSix duplicate result on trial %d for byte %d / 0x%02X",
                        trial,
                        byte,
                        byte);
                return;
            }

            aSeen.insert(aKey);
        }

        if ((trial & 31) == 31) {
            NSLog(@"SlickshotSix uniqueness trial %d / %d passed",
                  trial + 1,
                  kMatrixCount);
        }
    }
}

- (void)testSlickshotSixRandomWalkDoesNotCorruptPermutation {
    std::mt19937 aRng(0xBAD5EEDU);
    std::uniform_int_distribution<int> aByteDist(0, 255);

    constexpr int kTrialCount = 128 * 1024 * 32;
    constexpr int kOpsPerTrial = 512;

    for (int trial = 0; trial < kTrialCount; trial++) {
        M88 aMatrix = RandomMatrix(aRng);

        for (int op = 0; op < kOpsPerTrial; op++) {
            const std::uint8_t aByte = static_cast<std::uint8_t>(aByteDist(aRng));
            aMatrix.SlickshotSix(aByte);
        }

        bool aSeen[256] = { false };

        for (std::size_t i = 0; i < 64U; i++) {
            const std::uint8_t aValue = aMatrix.mData[i];

            if (aSeen[aValue]) {
                Logging::Log("Corrupt Matrix", aMatrix);

                XCTFail(@"Duplicate byte %u after random walk trial %d",
                        static_cast<unsigned>(aValue),
                        trial);
                return;
            }

            aSeen[aValue] = true;
        }
    }
}

@end

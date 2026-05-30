//
//  VerifyQuarter.cpp
//  CyberMatrixTests
//
//  Created by nick on 5/29/26.
//

#include "VerifyQuarter.hpp"

#include <cstdio>
#include <cstdint>

M88 VerifyQuarter::SpawnTestMatrixQuarterA() {
    return SpawnTestMatrixQuarter(0);
}

M88 VerifyQuarter::SpawnTestMatrixQuarterB() {
    return SpawnTestMatrixQuarter(1);
}

M88 VerifyQuarter::SpawnTestMatrixQuarterC() {
    return SpawnTestMatrixQuarter(2);
}

M88 VerifyQuarter::SpawnTestMatrixQuarterD() {
    return SpawnTestMatrixQuarter(3);
}

M VerifyQuarter::QuarterBefore() {
    return {
        {  0,  1,  2,  3 },
        {  4,  5,  6,  7 },
        {  8,  9, 10, 11 },
        { 12, 13, 14, 15 }
    };
}

M VerifyQuarter::QuarterRotAExpected() {
    return {
        { 12,  8,  4,  0 },
        { 13,  9,  5,  1 },
        { 14, 10,  6,  2 },
        { 15, 11,  7,  3 }
    };
}

M VerifyQuarter::QuarterRotBExpected() {
    return {
        {  3,  7, 11, 15 },
        {  2,  6, 10, 14 },
        {  1,  5,  9, 13 },
        {  0,  4,  8, 12 }
    };
}

M VerifyQuarter::QuarterRotCExpected() {
    return {
        { 15, 14, 13, 12 },
        { 11, 10,  9,  8 },
        {  7,  6,  5,  4 },
        {  3,  2,  1,  0 }
    };
}

M VerifyQuarter::QuarterPinAExpected() {
    return {
        { 12,  8,  4,  0 },
        { 13,  6, 10,  1 },
        { 14,  5,  9,  2 },
        { 15, 11,  7,  3 }
    };
}

M VerifyQuarter::QuarterPinBExpected() {
    return {
        {  3,  7, 11, 15 },
        {  2,  9,  5, 14 },
        {  1, 10,  6, 13 },
        {  0,  4,  8, 12 }
    };
}

M VerifyQuarter::QuarterCastleAExpected() {
    return {
        {  6, 11,  7, 10 },
        {  1, 12,  0, 13 },
        {  2, 15,  3, 14 },
        {  5,  8,  4,  9 }
    };
}

M VerifyQuarter::QuarterCastleBExpected() {
    return {
        {  9,  4,  8,  5 },
        { 14,  3, 15,  2 },
        { 13,  0, 12,  1 },
        { 10,  7, 11,  6 }
    };
}

bool VerifyQuarter::CheckQuarterA(const M88 &pBefore,
                                  const M88 &pAfter,
                                  const M &pExpected) {
    return CheckQuarter(0, pBefore, pAfter, pExpected);
}

bool VerifyQuarter::CheckQuarterB(const M88 &pBefore,
                                  const M88 &pAfter,
                                  const M &pExpected) {
    return CheckQuarter(1, pBefore, pAfter, pExpected);
}

bool VerifyQuarter::CheckQuarterC(const M88 &pBefore,
                                  const M88 &pAfter,
                                  const M &pExpected) {
    return CheckQuarter(2, pBefore, pAfter, pExpected);
}

bool VerifyQuarter::CheckQuarterD(const M88 &pBefore,
                                  const M88 &pAfter,
                                  const M &pExpected) {
    return CheckQuarter(3, pBefore, pAfter, pExpected);
}

bool VerifyQuarter::CheckQuarter(std::size_t pQuarter,
                                 const M88 &pBefore,
                                 const M88 &pAfter,
                                 const M &pExpected) {
    if (pExpected.size() != 4) {
        std::printf("Expected matrix height is not 4.\n");
        return false;
    }

    for (std::size_t y = 0; y < 4; y++) {
        if (pExpected[y].size() != 4) {
            std::printf("Expected matrix row %zu width is not 4.\n", y);
            return false;
        }
    }

    const std::size_t qx = (pQuarter & 1U) * 4U;
    const std::size_t qy = (pQuarter >> 1U) * 4U;

    for (std::size_t y = 0; y < 8; y++) {
        for (std::size_t x = 0; x < 8; x++) {
            const bool aInsideQuarter =
                (x >= qx) && (x < qx + 4U) &&
                (y >= qy) && (y < qy + 4U);

            const std::size_t aSlot = M88::Slot(x, y);
            const std::uint8_t aGot = pAfter.mData[aSlot];

            if (aInsideQuarter) {
                const std::uint8_t aWant = pExpected[y - qy][x - qx];

                if (aGot != aWant) {
                    std::printf("Quarter mismatch at global (%zu,%zu), local (%zu,%zu): got %02u, want %02u\n",
                                x,
                                y,
                                x - qx,
                                y - qy,
                                static_cast<unsigned>(aGot),
                                static_cast<unsigned>(aWant));
                    return false;
                }
            } else {
                const std::uint8_t aWant = pBefore.mData[aSlot];

                if (aGot != aWant) {
                    std::printf("Outside-quarter byte changed at (%zu,%zu): got %02u, want %02u\n",
                                x,
                                y,
                                static_cast<unsigned>(aGot),
                                static_cast<unsigned>(aWant));
                    return false;
                }
            }
        }
    }

    return true;
}

M88 VerifyQuarter::SpawnTestMatrixQuarter(std::size_t pQuarter) {
    M88 aMatrix;

    std::uint8_t aValue = 255U;
    for (std::size_t y = 0; y < 8; y++) {
        for (std::size_t x = 0; x < 8; x++) {
            aMatrix.mData[M88::Slot(x, y)] = aValue;
            aValue--;
        }
    }

    const std::size_t qx = (pQuarter & 1U) * 4U;
    const std::size_t qy = (pQuarter >> 1U) * 4U;

    std::uint8_t aQuarterValue = 0U;
    for (std::size_t y = 0; y < 4; y++) {
        for (std::size_t x = 0; x < 4; x++) {
            aMatrix.mData[M88::Slot(qx + x, qy + y)] = aQuarterValue;
            aQuarterValue++;
        }
    }

    return aMatrix;
}

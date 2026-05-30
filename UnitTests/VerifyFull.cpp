//
//  VerifyFull.cpp
//  CyberMatrixTests
//
//  Created by nick on 5/29/26.
//

#include "VerifyFull.hpp"

#include <cstdio>
#include <cstdint>

M88 VerifyFull::SpawnTestMatrixFull() {
    M88 aMatrix;

    std::uint8_t aValue = 0U;
    for (std::size_t y = 0; y < 8; y++) {
        for (std::size_t x = 0; x < 8; x++) {
            aMatrix.mData[M88::Slot(x, y)] = aValue;
            aValue++;
        }
    }

    return aMatrix;
}

M VerifyFull::FullBefore() {
    return {
        {  0,  1,  2,  3,  4,  5,  6,  7 },
        {  8,  9, 10, 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20, 21, 22, 23 },
        { 24, 25, 26, 27, 28, 29, 30, 31 },
        { 32, 33, 34, 35, 36, 37, 38, 39 },
        { 40, 41, 42, 43, 44, 45, 46, 47 },
        { 48, 49, 50, 51, 52, 53, 54, 55 },
        { 56, 57, 58, 59, 60, 61, 62, 63 }
    };
}

M VerifyFull::FullRotAExpected() {
    return {
        { 56, 48, 40, 32, 24, 16,  8,  0 },
        { 57, 49, 41, 33, 25, 17,  9,  1 },
        { 58, 50, 42, 34, 26, 18, 10,  2 },
        { 59, 51, 43, 35, 27, 19, 11,  3 },
        { 60, 52, 44, 36, 28, 20, 12,  4 },
        { 61, 53, 45, 37, 29, 21, 13,  5 },
        { 62, 54, 46, 38, 30, 22, 14,  6 },
        { 63, 55, 47, 39, 31, 23, 15,  7 }
    };
}

M VerifyFull::FullRotBExpected() {
    return {
        {  7, 15, 23, 31, 39, 47, 55, 63 },
        {  6, 14, 22, 30, 38, 46, 54, 62 },
        {  5, 13, 21, 29, 37, 45, 53, 61 },
        {  4, 12, 20, 28, 36, 44, 52, 60 },
        {  3, 11, 19, 27, 35, 43, 51, 59 },
        {  2, 10, 18, 26, 34, 42, 50, 58 },
        {  1,  9, 17, 25, 33, 41, 49, 57 },
        {  0,  8, 16, 24, 32, 40, 48, 56 }
    };
}

M VerifyFull::FullRotCExpected() {
    return {
        { 63, 62, 61, 60, 59, 58, 57, 56 },
        { 55, 54, 53, 52, 51, 50, 49, 48 },
        { 47, 46, 45, 44, 43, 42, 41, 40 },
        { 39, 38, 37, 36, 35, 34, 33, 32 },
        { 31, 30, 29, 28, 27, 26, 25, 24 },
        { 23, 22, 21, 20, 19, 18, 17, 16 },
        { 15, 14, 13, 12, 11, 10,  9,  8 },
        {  7,  6,  5,  4,  3,  2,  1,  0 }
    };
}

M VerifyFull::FullBlockRotAExpected() {
    return {
        { 32, 33, 34, 35,  0,  1,  2,  3 },
        { 40, 41, 42, 43,  8,  9, 10, 11 },
        { 48, 49, 50, 51, 16, 17, 18, 19 },
        { 56, 57, 58, 59, 24, 25, 26, 27 },
        { 36, 37, 38, 39,  4,  5,  6,  7 },
        { 44, 45, 46, 47, 12, 13, 14, 15 },
        { 52, 53, 54, 55, 20, 21, 22, 23 },
        { 60, 61, 62, 63, 28, 29, 30, 31 }
    };
}

M VerifyFull::FullBlockRotBExpected() {
    return {
        {  4,  5,  6,  7, 36, 37, 38, 39 },
        { 12, 13, 14, 15, 44, 45, 46, 47 },
        { 20, 21, 22, 23, 52, 53, 54, 55 },
        { 28, 29, 30, 31, 60, 61, 62, 63 },
        {  0,  1,  2,  3, 32, 33, 34, 35 },
        {  8,  9, 10, 11, 40, 41, 42, 43 },
        { 16, 17, 18, 19, 48, 49, 50, 51 },
        { 24, 25, 26, 27, 56, 57, 58, 59 }
    };
}

M VerifyFull::FullBlockRotCExpected() {
    return {
        { 36, 37, 38, 39, 32, 33, 34, 35 },
        { 44, 45, 46, 47, 40, 41, 42, 43 },
        { 52, 53, 54, 55, 48, 49, 50, 51 },
        { 60, 61, 62, 63, 56, 57, 58, 59 },
        {  4,  5,  6,  7,  0,  1,  2,  3 },
        { 12, 13, 14, 15,  8,  9, 10, 11 },
        { 20, 21, 22, 23, 16, 17, 18, 19 },
        { 28, 29, 30, 31, 24, 25, 26, 27 }
    };
}

M VerifyFull::FullPylonRotAExpected() {
    return {
        { 48, 49, 32, 33, 16, 17,  0,  1 },
        { 56, 57, 40, 41, 24, 25,  8,  9 },
        { 50, 51, 34, 35, 18, 19,  2,  3 },
        { 58, 59, 42, 43, 26, 27, 10, 11 },
        { 52, 53, 36, 37, 20, 21,  4,  5 },
        { 60, 61, 44, 45, 28, 29, 12, 13 },
        { 54, 55, 38, 39, 22, 23,  6,  7 },
        { 62, 63, 46, 47, 30, 31, 14, 15 }
    };
}

M VerifyFull::FullPylonRotBExpected() {
    return {
        {  6,  7, 22, 23, 38, 39, 54, 55 },
        { 14, 15, 30, 31, 46, 47, 62, 63 },
        {  4,  5, 20, 21, 36, 37, 52, 53 },
        { 12, 13, 28, 29, 44, 45, 60, 61 },
        {  2,  3, 18, 19, 34, 35, 50, 51 },
        { 10, 11, 26, 27, 42, 43, 58, 59 },
        {  0,  1, 16, 17, 32, 33, 48, 49 },
        {  8,  9, 24, 25, 40, 41, 56, 57 }
    };
}

M VerifyFull::FullPylonRotCExpected() {
    return {
        { 54, 55, 52, 53, 50, 51, 48, 49 },
        { 62, 63, 60, 61, 58, 59, 56, 57 },
        { 38, 39, 36, 37, 34, 35, 32, 33 },
        { 46, 47, 44, 45, 42, 43, 40, 41 },
        { 22, 23, 20, 21, 18, 19, 16, 17 },
        { 30, 31, 28, 29, 26, 27, 24, 25 },
        {  6,  7,  4,  5,  2,  3,  0,  1 },
        { 14, 15, 12, 13, 10, 11,  8,  9 }
    };
}

bool VerifyFull::CheckFull(const M88 &pBefore,
                           const M88 &pAfter,
                           const M &pExpected) {
    if (pExpected.size() != 8) {
        std::printf("Expected matrix height is not 8.\n");
        return false;
    }

    for (std::size_t y = 0; y < 8; y++) {
        if (pExpected[y].size() != 8) {
            std::printf("Expected matrix row %zu width is not 8.\n", y);
            return false;
        }
    }

    for (std::size_t y = 0; y < 8; y++) {
        for (std::size_t x = 0; x < 8; x++) {
            const std::size_t aSlot = M88::Slot(x, y);
            const std::uint8_t aGot = pAfter.mData[aSlot];
            const std::uint8_t aWant = pExpected[y][x];

            if (aGot != aWant) {
                std::printf("Full mismatch at (%zu,%zu): got %02u, want %02u; before was %02u\n",
                            x,
                            y,
                            static_cast<unsigned>(aGot),
                            static_cast<unsigned>(aWant),
                            static_cast<unsigned>(pBefore.mData[aSlot]));
                return false;
            }
        }
    }

    return true;
}

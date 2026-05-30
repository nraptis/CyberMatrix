//
//  VerifySixteenth.cpp
//  CyberMatrixTests
//
//  Created by nick on 5/29/26.
//

#include "VerifySixteenth.hpp"

#include <cstdio>
#include <cstdint>

M88 VerifySixteenth::SpawnTestMatrixSixteenthA() {
    return SpawnTestMatrixSixteenth(0);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthB() {
    return SpawnTestMatrixSixteenth(1);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthC() {
    return SpawnTestMatrixSixteenth(2);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthD() {
    return SpawnTestMatrixSixteenth(3);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthE() {
    return SpawnTestMatrixSixteenth(4);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthF() {
    return SpawnTestMatrixSixteenth(5);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthG() {
    return SpawnTestMatrixSixteenth(6);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthH() {
    return SpawnTestMatrixSixteenth(7);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthI() {
    return SpawnTestMatrixSixteenth(8);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthJ() {
    return SpawnTestMatrixSixteenth(9);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthK() {
    return SpawnTestMatrixSixteenth(10);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthL() {
    return SpawnTestMatrixSixteenth(11);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthM() {
    return SpawnTestMatrixSixteenth(12);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthN() {
    return SpawnTestMatrixSixteenth(13);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthO() {
    return SpawnTestMatrixSixteenth(14);
}

M88 VerifySixteenth::SpawnTestMatrixSixteenthP() {
    return SpawnTestMatrixSixteenth(15);
}

M VerifySixteenth::SixteenthBefore() {
    return {
        { 0, 1 },
        { 2, 3 }
    };
}

M VerifySixteenth::SixteenthRotAExpected() {
    return {
        { 2, 0 },
        { 3, 1 }
    };
}

M VerifySixteenth::SixteenthRotBExpected() {
    return {
        { 1, 3 },
        { 0, 2 }
    };
}

M VerifySixteenth::SixteenthFlipAExpected() {
    return {
        { 1, 0 },
        { 3, 2 }
    };
}

M VerifySixteenth::SixteenthFlipBExpected() {
    return {
        { 2, 3 },
        { 0, 1 }
    };
}

M VerifySixteenth::SixteenthTriadAAExpected() {
    // BCAD
    return {
        { 1, 2 },
        { 0, 3 }
    };
}

M VerifySixteenth::SixteenthTriadABExpected() {
    // CABD
    return {
        { 2, 0 },
        { 1, 3 }
    };
}

M VerifySixteenth::SixteenthTriadBAExpected() {
    // BDCA
    return {
        { 1, 3 },
        { 2, 0 }
    };
}

M VerifySixteenth::SixteenthTriadBBExpected() {
    // DACB
    return {
        { 3, 0 },
        { 2, 1 }
    };
}

M VerifySixteenth::SixteenthTriadCAExpected() {
    // CBDA
    return {
        { 2, 1 },
        { 3, 0 }
    };
}

M VerifySixteenth::SixteenthTriadCBExpected() {
    // DBAC
    return {
        { 3, 1 },
        { 0, 2 }
    };
}

M VerifySixteenth::SixteenthTriadDAExpected() {
    // ACDB
    return {
        { 0, 2 },
        { 3, 1 }
    };
}

M VerifySixteenth::SixteenthTriadDBExpected() {
    // ADBC
    return {
        { 0, 3 },
        { 1, 2 }
    };
}

M VerifySixteenth::SixteenthSnakeAExpected() {
    // BCDA
    return {
        { 1, 2 },
        { 3, 0 }
    };
}

M VerifySixteenth::SixteenthSnakeBExpected() {
    // DABC
    return {
        { 3, 0 },
        { 1, 2 }
    };
}

M VerifySixteenth::SixteenthSnakeCExpected() {
    // CDBA
    return {
        { 2, 3 },
        { 1, 0 }
    };
}

M VerifySixteenth::SixteenthSnakeDExpected() {
    // DCAB
    return {
        { 3, 2 },
        { 0, 1 }
    };
}

bool VerifySixteenth::CheckSixteenthA(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(0, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthB(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(1, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthC(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(2, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthD(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(3, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthE(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(4, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthF(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(5, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthG(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(6, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthH(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(7, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthI(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(8, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthJ(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(9, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthK(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(10, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthL(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(11, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthM(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(12, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthN(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(13, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthO(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(14, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenthP(const M88 &pBefore,
                                      const M88 &pAfter,
                                      const M &pExpected) {
    return CheckSixteenth(15, pBefore, pAfter, pExpected);
}

bool VerifySixteenth::CheckSixteenth(std::size_t pSixteenth,
                                     const M88 &pBefore,
                                     const M88 &pAfter,
                                     const M &pExpected) {
    if (pExpected.size() != 2) {
        std::printf("Expected matrix height is not 2.\n");
        return false;
    }

    for (std::size_t y = 0; y < 2; y++) {
        if (pExpected[y].size() != 2) {
            std::printf("Expected matrix row %zu width is not 2.\n", y);
            return false;
        }
    }

    const std::size_t sx = (pSixteenth & 3U) * 2U;
    const std::size_t sy = (pSixteenth >> 2U) * 2U;

    for (std::size_t y = 0; y < 8; y++) {
        for (std::size_t x = 0; x < 8; x++) {
            const bool aInsideSixteenth =
                (x >= sx) && (x < sx + 2U) &&
                (y >= sy) && (y < sy + 2U);

            const std::size_t aSlot = M88::Slot(x, y);
            const std::uint8_t aGot = pAfter.mData[aSlot];

            if (aInsideSixteenth) {
                const std::uint8_t aWant = pExpected[y - sy][x - sx];

                if (aGot != aWant) {
                    std::printf("Sixteenth mismatch at global (%zu,%zu), local (%zu,%zu): got %02u, want %02u\n",
                                x,
                                y,
                                x - sx,
                                y - sy,
                                static_cast<unsigned>(aGot),
                                static_cast<unsigned>(aWant));
                    return false;
                }
            } else {
                const std::uint8_t aWant = pBefore.mData[aSlot];

                if (aGot != aWant) {
                    std::printf("Outside-sixteenth byte changed at (%zu,%zu): got %02u, want %02u\n",
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

M88 VerifySixteenth::SpawnTestMatrixSixteenth(std::size_t pSixteenth) {
    M88 aMatrix;

    std::uint8_t aValue = 255U;
    for (std::size_t y = 0; y < 8; y++) {
        for (std::size_t x = 0; x < 8; x++) {
            aMatrix.mData[M88::Slot(x, y)] = aValue;
            aValue--;
        }
    }

    const std::size_t sx = (pSixteenth & 3U) * 2U;
    const std::size_t sy = (pSixteenth >> 2U) * 2U;

    std::uint8_t aSixteenthValue = 0U;
    for (std::size_t y = 0; y < 2; y++) {
        for (std::size_t x = 0; x < 2; x++) {
            aMatrix.mData[M88::Slot(sx + x, sy + y)] = aSixteenthValue;
            aSixteenthValue++;
        }
    }

    return aMatrix;
}

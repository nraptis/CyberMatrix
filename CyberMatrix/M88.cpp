//
//  M88.cpp
//  CyberMatrix
//
//  Created by nick on 5/29/26.
//

#include "M88.hpp"

#include <cstdio>
#include <cstring>

M88::M88() {
    Reset();
}

void M88::Reset() {
    for (std::size_t i = 0; i < 64U; i++) {
        mData[i] = static_cast<std::uint8_t>(i);
    }

    std::memset(mBefore, 0, sizeof(mBefore));
    std::memset(mAfter, 0, sizeof(mAfter));
    
}

std::size_t M88::Slot(std::size_t pX, std::size_t pY) {
    return pY * 8U + pX;
}

std::size_t M88::X(std::size_t pSlot) {
    return pSlot % 8U;
}

std::size_t M88::Y(std::size_t pSlot) {
    return pSlot / 8U;
}

#include <cstdint>
#include <cstddef>

static inline std::uint8_t ConstantTimeMask8(std::uint8_t pBit)
{
    // pBit must be 0 or 1.
    // Returns 0xFF if pBit == 1, else 0x00.
    return static_cast<std::uint8_t>(0U - pBit);
}

static inline std::uint8_t ConstantTimeEqual8(std::uint8_t pLeft, std::uint8_t pRight) {
    std::uint8_t aDiff = static_cast<std::uint8_t>(pLeft ^ pRight);
    aDiff |= static_cast<std::uint8_t>(aDiff >> 4);
    aDiff |= static_cast<std::uint8_t>(aDiff >> 2);
    aDiff |= static_cast<std::uint8_t>(aDiff >> 1);
    return static_cast<std::uint8_t>((aDiff ^ 1U) & 1U);
}

static inline std::uint8_t ConstantTimeSelect8(std::uint8_t pMask, std::uint8_t pYes, std::uint8_t pNo) {
    return static_cast<std::uint8_t>((pYes & pMask) | (pNo & ~pMask));
}

void M88::SwapRows(std::uint8_t pRowA, std::uint8_t pRowB) {
    pRowA = static_cast<std::uint8_t>(pRowA & 0x07U);
    pRowB = static_cast<std::uint8_t>(pRowB & 0x07U);

    std::uint8_t aTempA[8];
    std::uint8_t aTempB[8];

    for (std::size_t aX = 0; aX < 8; ++aX) {
        aTempA[aX] = 0;
        aTempB[aX] = 0;
    }

    // Extract pRowA and pRowB while scanning every row.
    for (std::size_t aY = 0; aY < 8; ++aY) {
        const std::uint8_t aY8 = static_cast<std::uint8_t>(aY);

        const std::uint8_t aMaskA =
            ConstantTimeMask8(ConstantTimeEqual8(aY8, pRowA));

        const std::uint8_t aMaskB =
            ConstantTimeMask8(ConstantTimeEqual8(aY8, pRowB));

        for (std::size_t aX = 0; aX < 8; ++aX) {
            const std::uint8_t aValue = mData[Slot(aX, aY)];

            aTempA[aX] = ConstantTimeSelect8(aMaskA, aValue, aTempA[aX]);
            aTempB[aX] = ConstantTimeSelect8(aMaskB, aValue, aTempB[aX]);
        }
    }

    // Write every row back. Only pRowA and pRowB actually change.
    for (std::size_t aY = 0; aY < 8; ++aY) {
        const std::uint8_t aY8 = static_cast<std::uint8_t>(aY);

        const std::uint8_t aMaskA =
            ConstantTimeMask8(ConstantTimeEqual8(aY8, pRowA));

        const std::uint8_t aMaskB =
            ConstantTimeMask8(ConstantTimeEqual8(aY8, pRowB));

        for (std::size_t aX = 0; aX < 8; ++aX) {
            std::uint8_t aValue = mData[Slot(aX, aY)];

            aValue = ConstantTimeSelect8(aMaskA, aTempB[aX], aValue);
            aValue = ConstantTimeSelect8(aMaskB, aTempA[aX], aValue);

            mData[Slot(aX, aY)] = aValue;
        }
    }
}

void M88::SwapRows(std::uint8_t pInstruction)
{
    const std::uint8_t aRowA =
        static_cast<std::uint8_t>((pInstruction >> 4U) & 0x07U);

    const std::uint8_t aRowB =
        static_cast<std::uint8_t>(pInstruction & 0x07U);

    SwapRows(aRowA, aRowB);
}

void M88::SwapCols(std::uint8_t pColA, std::uint8_t pColB) {
    pColA = static_cast<std::uint8_t>(pColA & 0x07U);
    pColB = static_cast<std::uint8_t>(pColB & 0x07U);

    std::uint8_t aTempA[8];
    std::uint8_t aTempB[8];

    for (std::size_t aY = 0; aY < 8; ++aY) {
        aTempA[aY] = 0;
        aTempB[aY] = 0;
    }

    // Extract pColA and pColB while scanning every column.
    for (std::size_t aX = 0; aX < 8; ++aX) {
        const std::uint8_t aX8 = static_cast<std::uint8_t>(aX);
        const std::uint8_t aMaskA = ConstantTimeMask8(ConstantTimeEqual8(aX8, pColA));
        const std::uint8_t aMaskB = ConstantTimeMask8(ConstantTimeEqual8(aX8, pColB));
        for (std::size_t aY = 0; aY < 8; ++aY) {
            const std::uint8_t aValue = mData[Slot(aX, aY)];
            aTempA[aY] = ConstantTimeSelect8(aMaskA, aValue, aTempA[aY]);
            aTempB[aY] = ConstantTimeSelect8(aMaskB, aValue, aTempB[aY]);
        }
    }

    // Write every column back. Only pColA and pColB actually change.
    for (std::size_t aX = 0; aX < 8; ++aX) {
        const std::uint8_t aX8 = static_cast<std::uint8_t>(aX);
        const std::uint8_t aMaskA = ConstantTimeMask8(ConstantTimeEqual8(aX8, pColA));
        const std::uint8_t aMaskB = ConstantTimeMask8(ConstantTimeEqual8(aX8, pColB));
        for (std::size_t aY = 0; aY < 8; ++aY) {
            std::uint8_t aValue = mData[Slot(aX, aY)];
            aValue = ConstantTimeSelect8(aMaskA, aTempB[aY], aValue);
            aValue = ConstantTimeSelect8(aMaskB, aTempA[aY], aValue);
            mData[Slot(aX, aY)] = aValue;
        }
    }
}

void M88::SwapCols(std::uint8_t pInstruction)
{
    const std::uint8_t aColA =
        static_cast<std::uint8_t>((pInstruction >> 4U) & 0x07U);

    const std::uint8_t aColB =
        static_cast<std::uint8_t>(pInstruction & 0x07U);

    SwapCols(aColA, aColB);
}


void M88::RecordStart() {
    std::memcpy(mBefore, mData, sizeof(mData));
}

void M88::RecordStop() {
    std::memcpy(mAfter, mData, sizeof(mData));
}

bool M88::HasChange() const {
    return std::memcmp(mBefore, mAfter, sizeof(mData)) != 0;
}

void M88::RecordPrintFunction(std::vector<std::string> pNameChunks) {
    std::printf("Generated candidate: ");

    for (std::size_t i = 0; i < pNameChunks.size(); i++) {
        std::printf("%s", pNameChunks[i].c_str());
    }

    std::printf("\n");
}

void M88::RecordPrintFunction(const char *pOpName,
                              const char *pPartName,
                              int pNumber) {
    std::printf("Generated candidate: %s%s%c\n",
                pOpName,
                pPartName,
                static_cast<char>('A' + pNumber));
}

void M88::Paste(Slice pSlice) {
    for (std::size_t x = 0; x < pSlice.mSize; x++) {
        for (std::size_t y = 0; y < pSlice.mSize; y++) {
            const std::size_t aSlot = pSlice.mSlot[x][y];
            mData[aSlot] = pSlice.mData[x][y];
        }
    }
}

Slice M88::Get(std::size_t pX, std::size_t pY, std::size_t pSize) {
    Slice aResult;
    aResult.Make(pX, pY, pSize);
    aResult.Flood(*this);
    return aResult;
}

Slice M88::GetFull() {
    return Get(0, 0, 8);
}

Slice M88::GetQuad(int pWhich) {
    switch (pWhich % 4) {
        case 0: return GetQuadA();
        case 1: return GetQuadB();
        case 2: return GetQuadC();
        default: return GetQuadD();
    }
}

Slice M88::GetQuadA() {
    return Get(0, 0, 4);
}

Slice M88::GetQuadB() {
    return Get(4, 0, 4);
}

Slice M88::GetQuadC() {
    return Get(0, 4, 4);
}

Slice M88::GetQuadD() {
    return Get(4, 4, 4);
}

Slice M88::GetMini(int pWhich) {
    switch (pWhich % 16) {
        case 0:  return GetMiniA();
        case 1:  return GetMiniB();
        case 2:  return GetMiniC();
        case 3:  return GetMiniD();
        case 4:  return GetMiniE();
        case 5:  return GetMiniF();
        case 6:  return GetMiniG();
        case 7:  return GetMiniH();
        case 8:  return GetMiniI();
        case 9:  return GetMiniJ();
        case 10: return GetMiniK();
        case 11: return GetMiniL();
        case 12: return GetMiniM();
        case 13: return GetMiniN();
        case 14: return GetMiniO();
        default: return GetMiniP();
    }
}

Slice M88::GetMiniA() {
    return Get(0, 0, 2);
}

Slice M88::GetMiniB() {
    return Get(2, 0, 2);
}

Slice M88::GetMiniC() {
    return Get(4, 0, 2);
}

Slice M88::GetMiniD() {
    return Get(6, 0, 2);
}

Slice M88::GetMiniE() {
    return Get(0, 2, 2);
}

Slice M88::GetMiniF() {
    return Get(2, 2, 2);
}

Slice M88::GetMiniG() {
    return Get(4, 2, 2);
}

Slice M88::GetMiniH() {
    return Get(6, 2, 2);
}

Slice M88::GetMiniI() {
    return Get(0, 4, 2);
}

Slice M88::GetMiniJ() {
    return Get(2, 4, 2);
}

Slice M88::GetMiniK() {
    return Get(4, 4, 2);
}

Slice M88::GetMiniL() {
    return Get(6, 4, 2);
}

Slice M88::GetMiniM() {
    return Get(0, 6, 2);
}

Slice M88::GetMiniN() {
    return Get(2, 6, 2);
}

Slice M88::GetMiniO() {
    return Get(4, 6, 2);
}

Slice M88::GetMiniP() {
    return Get(6, 6, 2);
}

void M88::SlickshotMini(std::uint8_t pByte) {
    
    typedef void (M88::*Fn)();

    static const Fn kTable[16][16] = {
        {
            &M88::Mini_RotA_2x2_A,
            &M88::Mini_RotA_2x2_B,
            &M88::Mini_RotA_2x2_C,
            &M88::Mini_RotA_2x2_D,
            &M88::Mini_RotA_2x2_E,
            &M88::Mini_RotA_2x2_F,
            &M88::Mini_RotA_2x2_G,
            &M88::Mini_RotA_2x2_H,
            &M88::Mini_RotA_2x2_I,
            &M88::Mini_RotA_2x2_J,
            &M88::Mini_RotA_2x2_K,
            &M88::Mini_RotA_2x2_L,
            &M88::Mini_RotA_2x2_M,
            &M88::Mini_RotA_2x2_N,
            &M88::Mini_RotA_2x2_O,
            &M88::Mini_RotA_2x2_P
        },
        {
            &M88::Mini_RotB_2x2_A,
            &M88::Mini_RotB_2x2_B,
            &M88::Mini_RotB_2x2_C,
            &M88::Mini_RotB_2x2_D,
            &M88::Mini_RotB_2x2_E,
            &M88::Mini_RotB_2x2_F,
            &M88::Mini_RotB_2x2_G,
            &M88::Mini_RotB_2x2_H,
            &M88::Mini_RotB_2x2_I,
            &M88::Mini_RotB_2x2_J,
            &M88::Mini_RotB_2x2_K,
            &M88::Mini_RotB_2x2_L,
            &M88::Mini_RotB_2x2_M,
            &M88::Mini_RotB_2x2_N,
            &M88::Mini_RotB_2x2_O,
            &M88::Mini_RotB_2x2_P
        },
        {
            &M88::Mini_FlipA_2x2_A,
            &M88::Mini_FlipA_2x2_B,
            &M88::Mini_FlipA_2x2_C,
            &M88::Mini_FlipA_2x2_D,
            &M88::Mini_FlipA_2x2_E,
            &M88::Mini_FlipA_2x2_F,
            &M88::Mini_FlipA_2x2_G,
            &M88::Mini_FlipA_2x2_H,
            &M88::Mini_FlipA_2x2_I,
            &M88::Mini_FlipA_2x2_J,
            &M88::Mini_FlipA_2x2_K,
            &M88::Mini_FlipA_2x2_L,
            &M88::Mini_FlipA_2x2_M,
            &M88::Mini_FlipA_2x2_N,
            &M88::Mini_FlipA_2x2_O,
            &M88::Mini_FlipA_2x2_P
        },
        {
            &M88::Mini_FlipB_2x2_A,
            &M88::Mini_FlipB_2x2_B,
            &M88::Mini_FlipB_2x2_C,
            &M88::Mini_FlipB_2x2_D,
            &M88::Mini_FlipB_2x2_E,
            &M88::Mini_FlipB_2x2_F,
            &M88::Mini_FlipB_2x2_G,
            &M88::Mini_FlipB_2x2_H,
            &M88::Mini_FlipB_2x2_I,
            &M88::Mini_FlipB_2x2_J,
            &M88::Mini_FlipB_2x2_K,
            &M88::Mini_FlipB_2x2_L,
            &M88::Mini_FlipB_2x2_M,
            &M88::Mini_FlipB_2x2_N,
            &M88::Mini_FlipB_2x2_O,
            &M88::Mini_FlipB_2x2_P
        },
        {
            &M88::Mini_SnakeA_2x2_A,
            &M88::Mini_SnakeA_2x2_B,
            &M88::Mini_SnakeA_2x2_C,
            &M88::Mini_SnakeA_2x2_D,
            &M88::Mini_SnakeA_2x2_E,
            &M88::Mini_SnakeA_2x2_F,
            &M88::Mini_SnakeA_2x2_G,
            &M88::Mini_SnakeA_2x2_H,
            &M88::Mini_SnakeA_2x2_I,
            &M88::Mini_SnakeA_2x2_J,
            &M88::Mini_SnakeA_2x2_K,
            &M88::Mini_SnakeA_2x2_L,
            &M88::Mini_SnakeA_2x2_M,
            &M88::Mini_SnakeA_2x2_N,
            &M88::Mini_SnakeA_2x2_O,
            &M88::Mini_SnakeA_2x2_P
        },
        {
            &M88::Mini_SnakeB_2x2_A,
            &M88::Mini_SnakeB_2x2_B,
            &M88::Mini_SnakeB_2x2_C,
            &M88::Mini_SnakeB_2x2_D,
            &M88::Mini_SnakeB_2x2_E,
            &M88::Mini_SnakeB_2x2_F,
            &M88::Mini_SnakeB_2x2_G,
            &M88::Mini_SnakeB_2x2_H,
            &M88::Mini_SnakeB_2x2_I,
            &M88::Mini_SnakeB_2x2_J,
            &M88::Mini_SnakeB_2x2_K,
            &M88::Mini_SnakeB_2x2_L,
            &M88::Mini_SnakeB_2x2_M,
            &M88::Mini_SnakeB_2x2_N,
            &M88::Mini_SnakeB_2x2_O,
            &M88::Mini_SnakeB_2x2_P
        },
        {
            &M88::Mini_SnakeC_2x2_A,
            &M88::Mini_SnakeC_2x2_B,
            &M88::Mini_SnakeC_2x2_C,
            &M88::Mini_SnakeC_2x2_D,
            &M88::Mini_SnakeC_2x2_E,
            &M88::Mini_SnakeC_2x2_F,
            &M88::Mini_SnakeC_2x2_G,
            &M88::Mini_SnakeC_2x2_H,
            &M88::Mini_SnakeC_2x2_I,
            &M88::Mini_SnakeC_2x2_J,
            &M88::Mini_SnakeC_2x2_K,
            &M88::Mini_SnakeC_2x2_L,
            &M88::Mini_SnakeC_2x2_M,
            &M88::Mini_SnakeC_2x2_N,
            &M88::Mini_SnakeC_2x2_O,
            &M88::Mini_SnakeC_2x2_P
        },
        {
            &M88::Mini_SnakeD_2x2_A,
            &M88::Mini_SnakeD_2x2_B,
            &M88::Mini_SnakeD_2x2_C,
            &M88::Mini_SnakeD_2x2_D,
            &M88::Mini_SnakeD_2x2_E,
            &M88::Mini_SnakeD_2x2_F,
            &M88::Mini_SnakeD_2x2_G,
            &M88::Mini_SnakeD_2x2_H,
            &M88::Mini_SnakeD_2x2_I,
            &M88::Mini_SnakeD_2x2_J,
            &M88::Mini_SnakeD_2x2_K,
            &M88::Mini_SnakeD_2x2_L,
            &M88::Mini_SnakeD_2x2_M,
            &M88::Mini_SnakeD_2x2_N,
            &M88::Mini_SnakeD_2x2_O,
            &M88::Mini_SnakeD_2x2_P
        },
        {
            &M88::Mini_TriadA_2x2_A,
            &M88::Mini_TriadA_2x2_B,
            &M88::Mini_TriadA_2x2_C,
            &M88::Mini_TriadA_2x2_D,
            &M88::Mini_TriadA_2x2_E,
            &M88::Mini_TriadA_2x2_F,
            &M88::Mini_TriadA_2x2_G,
            &M88::Mini_TriadA_2x2_H,
            &M88::Mini_TriadA_2x2_I,
            &M88::Mini_TriadA_2x2_J,
            &M88::Mini_TriadA_2x2_K,
            &M88::Mini_TriadA_2x2_L,
            &M88::Mini_TriadA_2x2_M,
            &M88::Mini_TriadA_2x2_N,
            &M88::Mini_TriadA_2x2_O,
            &M88::Mini_TriadA_2x2_P
        },
        {
            &M88::Mini_TriadB_2x2_A,
            &M88::Mini_TriadB_2x2_B,
            &M88::Mini_TriadB_2x2_C,
            &M88::Mini_TriadB_2x2_D,
            &M88::Mini_TriadB_2x2_E,
            &M88::Mini_TriadB_2x2_F,
            &M88::Mini_TriadB_2x2_G,
            &M88::Mini_TriadB_2x2_H,
            &M88::Mini_TriadB_2x2_I,
            &M88::Mini_TriadB_2x2_J,
            &M88::Mini_TriadB_2x2_K,
            &M88::Mini_TriadB_2x2_L,
            &M88::Mini_TriadB_2x2_M,
            &M88::Mini_TriadB_2x2_N,
            &M88::Mini_TriadB_2x2_O,
            &M88::Mini_TriadB_2x2_P
        },
        {
            &M88::Mini_TriadC_2x2_A,
            &M88::Mini_TriadC_2x2_B,
            &M88::Mini_TriadC_2x2_C,
            &M88::Mini_TriadC_2x2_D,
            &M88::Mini_TriadC_2x2_E,
            &M88::Mini_TriadC_2x2_F,
            &M88::Mini_TriadC_2x2_G,
            &M88::Mini_TriadC_2x2_H,
            &M88::Mini_TriadC_2x2_I,
            &M88::Mini_TriadC_2x2_J,
            &M88::Mini_TriadC_2x2_K,
            &M88::Mini_TriadC_2x2_L,
            &M88::Mini_TriadC_2x2_M,
            &M88::Mini_TriadC_2x2_N,
            &M88::Mini_TriadC_2x2_O,
            &M88::Mini_TriadC_2x2_P
        },
        {
            &M88::Mini_TriadD_2x2_A,
            &M88::Mini_TriadD_2x2_B,
            &M88::Mini_TriadD_2x2_C,
            &M88::Mini_TriadD_2x2_D,
            &M88::Mini_TriadD_2x2_E,
            &M88::Mini_TriadD_2x2_F,
            &M88::Mini_TriadD_2x2_G,
            &M88::Mini_TriadD_2x2_H,
            &M88::Mini_TriadD_2x2_I,
            &M88::Mini_TriadD_2x2_J,
            &M88::Mini_TriadD_2x2_K,
            &M88::Mini_TriadD_2x2_L,
            &M88::Mini_TriadD_2x2_M,
            &M88::Mini_TriadD_2x2_N,
            &M88::Mini_TriadD_2x2_O,
            &M88::Mini_TriadD_2x2_P
        },
        {
            &M88::Mini_TriadE_2x2_A,
            &M88::Mini_TriadE_2x2_B,
            &M88::Mini_TriadE_2x2_C,
            &M88::Mini_TriadE_2x2_D,
            &M88::Mini_TriadE_2x2_E,
            &M88::Mini_TriadE_2x2_F,
            &M88::Mini_TriadE_2x2_G,
            &M88::Mini_TriadE_2x2_H,
            &M88::Mini_TriadE_2x2_I,
            &M88::Mini_TriadE_2x2_J,
            &M88::Mini_TriadE_2x2_K,
            &M88::Mini_TriadE_2x2_L,
            &M88::Mini_TriadE_2x2_M,
            &M88::Mini_TriadE_2x2_N,
            &M88::Mini_TriadE_2x2_O,
            &M88::Mini_TriadE_2x2_P
        },
        {
            &M88::Mini_TriadF_2x2_A,
            &M88::Mini_TriadF_2x2_B,
            &M88::Mini_TriadF_2x2_C,
            &M88::Mini_TriadF_2x2_D,
            &M88::Mini_TriadF_2x2_E,
            &M88::Mini_TriadF_2x2_F,
            &M88::Mini_TriadF_2x2_G,
            &M88::Mini_TriadF_2x2_H,
            &M88::Mini_TriadF_2x2_I,
            &M88::Mini_TriadF_2x2_J,
            &M88::Mini_TriadF_2x2_K,
            &M88::Mini_TriadF_2x2_L,
            &M88::Mini_TriadF_2x2_M,
            &M88::Mini_TriadF_2x2_N,
            &M88::Mini_TriadF_2x2_O,
            &M88::Mini_TriadF_2x2_P
        },
        {
            &M88::Mini_TriadG_2x2_A,
            &M88::Mini_TriadG_2x2_B,
            &M88::Mini_TriadG_2x2_C,
            &M88::Mini_TriadG_2x2_D,
            &M88::Mini_TriadG_2x2_E,
            &M88::Mini_TriadG_2x2_F,
            &M88::Mini_TriadG_2x2_G,
            &M88::Mini_TriadG_2x2_H,
            &M88::Mini_TriadG_2x2_I,
            &M88::Mini_TriadG_2x2_J,
            &M88::Mini_TriadG_2x2_K,
            &M88::Mini_TriadG_2x2_L,
            &M88::Mini_TriadG_2x2_M,
            &M88::Mini_TriadG_2x2_N,
            &M88::Mini_TriadG_2x2_O,
            &M88::Mini_TriadG_2x2_P
        },
        {
            &M88::Mini_TriadH_2x2_A,
            &M88::Mini_TriadH_2x2_B,
            &M88::Mini_TriadH_2x2_C,
            &M88::Mini_TriadH_2x2_D,
            &M88::Mini_TriadH_2x2_E,
            &M88::Mini_TriadH_2x2_F,
            &M88::Mini_TriadH_2x2_G,
            &M88::Mini_TriadH_2x2_H,
            &M88::Mini_TriadH_2x2_I,
            &M88::Mini_TriadH_2x2_J,
            &M88::Mini_TriadH_2x2_K,
            &M88::Mini_TriadH_2x2_L,
            &M88::Mini_TriadH_2x2_M,
            &M88::Mini_TriadH_2x2_N,
            &M88::Mini_TriadH_2x2_O,
            &M88::Mini_TriadH_2x2_P
        }
    };
    
    const std::uint8_t aMini = pByte & 0x0FU;
    const std::uint8_t aOp = (pByte >> 4U) & 0x0FU;
    (this->*kTable[aOp][aMini])();
}


// ---------- CPP ----------
void M88::Full_RotA_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = mData[36]; mData[36] = mData[4]; mData[4] = aHold;
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = mData[37]; mData[37] = mData[5]; mData[5] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = mData[38]; mData[38] = mData[6]; mData[6] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = mData[39]; mData[39] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = mData[44]; mData[44] = mData[12]; mData[12] = aHold;
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = mData[45]; mData[45] = mData[13]; mData[13] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = mData[46]; mData[46] = mData[14]; mData[14] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = mData[47]; mData[47] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = mData[52]; mData[52] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = mData[53]; mData[53] = mData[21]; mData[21] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = mData[54]; mData[54] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = mData[55]; mData[55] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = mData[60]; mData[60] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = mData[61]; mData[61] = mData[29]; mData[29] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = mData[62]; mData[62] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = mData[63]; mData[63] = mData[31]; mData[31] = aHold;
}

void M88::Full_RotA_EachQuad_2x2() {
    Quad_RotA_2x2_A();
    Quad_RotA_2x2_B();
    Quad_RotA_2x2_C();
    Quad_RotA_2x2_D();
}

void M88::Full_RotA_EachMini_2x2() {
    Mini_RotA_2x2_A();
    Mini_RotA_2x2_B();
    Mini_RotA_2x2_C();
    Mini_RotA_2x2_D();
    Mini_RotA_2x2_E();
    Mini_RotA_2x2_F();
    Mini_RotA_2x2_G();
    Mini_RotA_2x2_H();
    Mini_RotA_2x2_I();
    Mini_RotA_2x2_J();
    Mini_RotA_2x2_K();
    Mini_RotA_2x2_L();
    Mini_RotA_2x2_M();
    Mini_RotA_2x2_N();
    Mini_RotA_2x2_O();
    Mini_RotA_2x2_P();
}

void M88::Quad_RotA_EachMini_2x2_A() {
    Mini_RotA_2x2_A();
    Mini_RotA_2x2_B();
    Mini_RotA_2x2_E();
    Mini_RotA_2x2_F();
}

void M88::Quad_RotA_EachMini_2x2_B() {
    Mini_RotA_2x2_C();
    Mini_RotA_2x2_D();
    Mini_RotA_2x2_G();
    Mini_RotA_2x2_H();
}

void M88::Quad_RotA_EachMini_2x2_C() {
    Mini_RotA_2x2_I();
    Mini_RotA_2x2_J();
    Mini_RotA_2x2_M();
    Mini_RotA_2x2_N();
}

void M88::Quad_RotA_EachMini_2x2_D() {
    Mini_RotA_2x2_K();
    Mini_RotA_2x2_L();
    Mini_RotA_2x2_O();
    Mini_RotA_2x2_P();
}

void M88::Quad_RotA_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = mData[18]; mData[18] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = mData[19]; mData[19] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = mData[26]; mData[26] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = mData[27]; mData[27] = mData[11]; mData[11] = aHold;
}

void M88::Quad_RotA_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = mData[22]; mData[22] = mData[6]; mData[6] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = mData[23]; mData[23] = mData[7]; mData[7] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = mData[30]; mData[30] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = mData[31]; mData[31] = mData[15]; mData[15] = aHold;
}

void M88::Quad_RotA_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = mData[50]; mData[50] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = mData[51]; mData[51] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = mData[58]; mData[58] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = mData[59]; mData[59] = mData[43]; mData[43] = aHold;
}

void M88::Quad_RotA_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = mData[54]; mData[54] = mData[38]; mData[38] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = mData[55]; mData[55] = mData[39]; mData[39] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = mData[62]; mData[62] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = mData[63]; mData[63] = mData[47]; mData[47] = aHold;
}

void M88::Mini_RotA_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = mData[9]; mData[9] = mData[1]; mData[1] = aHold;
}

void M88::Mini_RotA_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = mData[11]; mData[11] = mData[3]; mData[3] = aHold;
}

void M88::Mini_RotA_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = mData[13]; mData[13] = mData[5]; mData[5] = aHold;
}

void M88::Mini_RotA_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = mData[15]; mData[15] = mData[7]; mData[7] = aHold;
}

void M88::Mini_RotA_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = mData[25]; mData[25] = mData[17]; mData[17] = aHold;
}

void M88::Mini_RotA_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = mData[27]; mData[27] = mData[19]; mData[19] = aHold;
}

void M88::Mini_RotA_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = mData[29]; mData[29] = mData[21]; mData[21] = aHold;
}

void M88::Mini_RotA_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = mData[31]; mData[31] = mData[23]; mData[23] = aHold;
}

void M88::Mini_RotA_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = mData[41]; mData[41] = mData[33]; mData[33] = aHold;
}

void M88::Mini_RotA_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = mData[43]; mData[43] = mData[35]; mData[35] = aHold;
}

void M88::Mini_RotA_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = mData[45]; mData[45] = mData[37]; mData[37] = aHold;
}

void M88::Mini_RotA_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = mData[47]; mData[47] = mData[39]; mData[39] = aHold;
}

void M88::Mini_RotA_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = mData[57]; mData[57] = mData[49]; mData[49] = aHold;
}

void M88::Mini_RotA_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = mData[59]; mData[59] = mData[51]; mData[51] = aHold;
}

void M88::Mini_RotA_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = mData[61]; mData[61] = mData[53]; mData[53] = aHold;
}

void M88::Mini_RotA_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = mData[63]; mData[63] = mData[55]; mData[55] = aHold;
}







// ---------- CPP ----------
void M88::Full_RotA_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[48]; mData[48] = mData[54]; mData[54] = mData[6]; mData[6] = aHold;
    aHold = mData[1]; mData[1] = mData[49]; mData[49] = mData[55]; mData[55] = mData[7]; mData[7] = aHold;
    aHold = mData[2]; mData[2] = mData[32]; mData[32] = mData[52]; mData[52] = mData[22]; mData[22] = aHold;
    aHold = mData[3]; mData[3] = mData[33]; mData[33] = mData[53]; mData[53] = mData[23]; mData[23] = aHold;
    aHold = mData[4]; mData[4] = mData[16]; mData[16] = mData[50]; mData[50] = mData[38]; mData[38] = aHold;
    aHold = mData[5]; mData[5] = mData[17]; mData[17] = mData[51]; mData[51] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[56]; mData[56] = mData[62]; mData[62] = mData[14]; mData[14] = aHold;
    aHold = mData[9]; mData[9] = mData[57]; mData[57] = mData[63]; mData[63] = mData[15]; mData[15] = aHold;
    aHold = mData[10]; mData[10] = mData[40]; mData[40] = mData[60]; mData[60] = mData[30]; mData[30] = aHold;
    aHold = mData[11]; mData[11] = mData[41]; mData[41] = mData[61]; mData[61] = mData[31]; mData[31] = aHold;
    aHold = mData[12]; mData[12] = mData[24]; mData[24] = mData[58]; mData[58] = mData[46]; mData[46] = aHold;
    aHold = mData[13]; mData[13] = mData[25]; mData[25] = mData[59]; mData[59] = mData[47]; mData[47] = aHold;
    aHold = mData[18]; mData[18] = mData[34]; mData[34] = mData[36]; mData[36] = mData[20]; mData[20] = aHold;
    aHold = mData[19]; mData[19] = mData[35]; mData[35] = mData[37]; mData[37] = mData[21]; mData[21] = aHold;
    aHold = mData[26]; mData[26] = mData[42]; mData[42] = mData[44]; mData[44] = mData[28]; mData[28] = aHold;
    aHold = mData[27]; mData[27] = mData[43]; mData[43] = mData[45]; mData[45] = mData[29]; mData[29] = aHold;
}

void M88::Full_RotA_EachQuad_4x4() {
    Quad_RotA_4x4_A();
    Quad_RotA_4x4_B();
    Quad_RotA_4x4_C();
    Quad_RotA_4x4_D();
}

void M88::Quad_RotA_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[24]; mData[24] = mData[27]; mData[27] = mData[3]; mData[3] = aHold;
    aHold = mData[1]; mData[1] = mData[16]; mData[16] = mData[26]; mData[26] = mData[11]; mData[11] = aHold;
    aHold = mData[2]; mData[2] = mData[8]; mData[8] = mData[25]; mData[25] = mData[19]; mData[19] = aHold;
    aHold = mData[9]; mData[9] = mData[17]; mData[17] = mData[18]; mData[18] = mData[10]; mData[10] = aHold;
}

void M88::Quad_RotA_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[28]; mData[28] = mData[31]; mData[31] = mData[7]; mData[7] = aHold;
    aHold = mData[5]; mData[5] = mData[20]; mData[20] = mData[30]; mData[30] = mData[15]; mData[15] = aHold;
    aHold = mData[6]; mData[6] = mData[12]; mData[12] = mData[29]; mData[29] = mData[23]; mData[23] = aHold;
    aHold = mData[13]; mData[13] = mData[21]; mData[21] = mData[22]; mData[22] = mData[14]; mData[14] = aHold;
}

void M88::Quad_RotA_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[56]; mData[56] = mData[59]; mData[59] = mData[35]; mData[35] = aHold;
    aHold = mData[33]; mData[33] = mData[48]; mData[48] = mData[58]; mData[58] = mData[43]; mData[43] = aHold;
    aHold = mData[34]; mData[34] = mData[40]; mData[40] = mData[57]; mData[57] = mData[51]; mData[51] = aHold;
    aHold = mData[41]; mData[41] = mData[49]; mData[49] = mData[50]; mData[50] = mData[42]; mData[42] = aHold;
}

void M88::Quad_RotA_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[60]; mData[60] = mData[63]; mData[63] = mData[39]; mData[39] = aHold;
    aHold = mData[37]; mData[37] = mData[52]; mData[52] = mData[62]; mData[62] = mData[47]; mData[47] = aHold;
    aHold = mData[38]; mData[38] = mData[44]; mData[44] = mData[61]; mData[61] = mData[55]; mData[55] = aHold;
    aHold = mData[45]; mData[45] = mData[53]; mData[53] = mData[54]; mData[54] = mData[46]; mData[46] = aHold;
}



void M88::Full_RotA_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[56]; mData[56] = mData[63]; mData[63] = mData[7]; mData[7] = aHold;
    aHold = mData[1]; mData[1] = mData[48]; mData[48] = mData[62]; mData[62] = mData[15]; mData[15] = aHold;
    aHold = mData[2]; mData[2] = mData[40]; mData[40] = mData[61]; mData[61] = mData[23]; mData[23] = aHold;
    aHold = mData[3]; mData[3] = mData[32]; mData[32] = mData[60]; mData[60] = mData[31]; mData[31] = aHold;
    aHold = mData[4]; mData[4] = mData[24]; mData[24] = mData[59]; mData[59] = mData[39]; mData[39] = aHold;
    aHold = mData[5]; mData[5] = mData[16]; mData[16] = mData[58]; mData[58] = mData[47]; mData[47] = aHold;
    aHold = mData[6]; mData[6] = mData[8]; mData[8] = mData[57]; mData[57] = mData[55]; mData[55] = aHold;
    aHold = mData[9]; mData[9] = mData[49]; mData[49] = mData[54]; mData[54] = mData[14]; mData[14] = aHold;
    aHold = mData[10]; mData[10] = mData[41]; mData[41] = mData[53]; mData[53] = mData[22]; mData[22] = aHold;
    aHold = mData[11]; mData[11] = mData[33]; mData[33] = mData[52]; mData[52] = mData[30]; mData[30] = aHold;
    aHold = mData[12]; mData[12] = mData[25]; mData[25] = mData[51]; mData[51] = mData[38]; mData[38] = aHold;
    aHold = mData[13]; mData[13] = mData[17]; mData[17] = mData[50]; mData[50] = mData[46]; mData[46] = aHold;
    aHold = mData[18]; mData[18] = mData[42]; mData[42] = mData[45]; mData[45] = mData[21]; mData[21] = aHold;
    aHold = mData[19]; mData[19] = mData[34]; mData[34] = mData[44]; mData[44] = mData[29]; mData[29] = aHold;
    aHold = mData[20]; mData[20] = mData[26]; mData[26] = mData[43]; mData[43] = mData[37]; mData[37] = aHold;
    aHold = mData[27]; mData[27] = mData[35]; mData[35] = mData[36]; mData[36] = mData[28]; mData[28] = aHold;
}

void M88::Full_RotB_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = mData[36]; mData[36] = mData[32]; mData[32] = aHold;
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = mData[37]; mData[37] = mData[33]; mData[33] = aHold;
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = mData[38]; mData[38] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = mData[39]; mData[39] = mData[35]; mData[35] = aHold;
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = mData[44]; mData[44] = mData[40]; mData[40] = aHold;
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = mData[45]; mData[45] = mData[41]; mData[41] = aHold;
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = mData[46]; mData[46] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = mData[47]; mData[47] = mData[43]; mData[43] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = mData[52]; mData[52] = mData[48]; mData[48] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = mData[53]; mData[53] = mData[49]; mData[49] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = mData[54]; mData[54] = mData[50]; mData[50] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = mData[55]; mData[55] = mData[51]; mData[51] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = mData[60]; mData[60] = mData[56]; mData[56] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = mData[61]; mData[61] = mData[57]; mData[57] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = mData[62]; mData[62] = mData[58]; mData[58] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = mData[63]; mData[63] = mData[59]; mData[59] = aHold;
}

void M88::Full_RotB_EachQuad_2x2() {
    Quad_RotB_2x2_A();
    Quad_RotB_2x2_B();
    Quad_RotB_2x2_C();
    Quad_RotB_2x2_D();
}

void M88::Full_RotB_EachMini_2x2() {
    Mini_RotB_2x2_A();
    Mini_RotB_2x2_B();
    Mini_RotB_2x2_C();
    Mini_RotB_2x2_D();
    Mini_RotB_2x2_E();
    Mini_RotB_2x2_F();
    Mini_RotB_2x2_G();
    Mini_RotB_2x2_H();
    Mini_RotB_2x2_I();
    Mini_RotB_2x2_J();
    Mini_RotB_2x2_K();
    Mini_RotB_2x2_L();
    Mini_RotB_2x2_M();
    Mini_RotB_2x2_N();
    Mini_RotB_2x2_O();
    Mini_RotB_2x2_P();
}

void M88::Quad_RotB_EachMini_2x2_A() {
    Mini_RotB_2x2_A();
    Mini_RotB_2x2_B();
    Mini_RotB_2x2_E();
    Mini_RotB_2x2_F();
}

void M88::Quad_RotB_EachMini_2x2_B() {
    Mini_RotB_2x2_C();
    Mini_RotB_2x2_D();
    Mini_RotB_2x2_G();
    Mini_RotB_2x2_H();
}

void M88::Quad_RotB_EachMini_2x2_C() {
    Mini_RotB_2x2_I();
    Mini_RotB_2x2_J();
    Mini_RotB_2x2_M();
    Mini_RotB_2x2_N();
}

void M88::Quad_RotB_EachMini_2x2_D() {
    Mini_RotB_2x2_K();
    Mini_RotB_2x2_L();
    Mini_RotB_2x2_O();
    Mini_RotB_2x2_P();
}

void M88::Quad_RotB_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = mData[18]; mData[18] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = mData[19]; mData[19] = mData[17]; mData[17] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = mData[26]; mData[26] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = mData[27]; mData[27] = mData[25]; mData[25] = aHold;
}

void M88::Quad_RotB_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = mData[22]; mData[22] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = mData[23]; mData[23] = mData[21]; mData[21] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = mData[30]; mData[30] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = mData[31]; mData[31] = mData[29]; mData[29] = aHold;
}

void M88::Quad_RotB_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = mData[50]; mData[50] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = mData[51]; mData[51] = mData[49]; mData[49] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = mData[58]; mData[58] = mData[56]; mData[56] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = mData[59]; mData[59] = mData[57]; mData[57] = aHold;
}

void M88::Quad_RotB_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = mData[54]; mData[54] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = mData[55]; mData[55] = mData[53]; mData[53] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = mData[62]; mData[62] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = mData[63]; mData[63] = mData[61]; mData[61] = aHold;
}

void M88::Mini_RotB_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = mData[9]; mData[9] = mData[8]; mData[8] = aHold;
}

void M88::Mini_RotB_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = mData[11]; mData[11] = mData[10]; mData[10] = aHold;
}

void M88::Mini_RotB_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = mData[13]; mData[13] = mData[12]; mData[12] = aHold;
}

void M88::Mini_RotB_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = mData[15]; mData[15] = mData[14]; mData[14] = aHold;
}

void M88::Mini_RotB_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = mData[25]; mData[25] = mData[24]; mData[24] = aHold;
}

void M88::Mini_RotB_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = mData[27]; mData[27] = mData[26]; mData[26] = aHold;
}

void M88::Mini_RotB_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = mData[29]; mData[29] = mData[28]; mData[28] = aHold;
}

void M88::Mini_RotB_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = mData[31]; mData[31] = mData[30]; mData[30] = aHold;
}

void M88::Mini_RotB_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = mData[41]; mData[41] = mData[40]; mData[40] = aHold;
}

void M88::Mini_RotB_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = mData[43]; mData[43] = mData[42]; mData[42] = aHold;
}

void M88::Mini_RotB_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = mData[45]; mData[45] = mData[44]; mData[44] = aHold;
}

void M88::Mini_RotB_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = mData[47]; mData[47] = mData[46]; mData[46] = aHold;
}

void M88::Mini_RotB_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = mData[57]; mData[57] = mData[56]; mData[56] = aHold;
}

void M88::Mini_RotB_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = mData[59]; mData[59] = mData[58]; mData[58] = aHold;
}

void M88::Mini_RotB_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = mData[61]; mData[61] = mData[60]; mData[60] = aHold;
}

void M88::Mini_RotB_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = mData[63]; mData[63] = mData[62]; mData[62] = aHold;
}



void M88::Full_RotB_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[6]; mData[6] = mData[54]; mData[54] = mData[48]; mData[48] = aHold;
    aHold = mData[1]; mData[1] = mData[7]; mData[7] = mData[55]; mData[55] = mData[49]; mData[49] = aHold;
    aHold = mData[2]; mData[2] = mData[22]; mData[22] = mData[52]; mData[52] = mData[32]; mData[32] = aHold;
    aHold = mData[3]; mData[3] = mData[23]; mData[23] = mData[53]; mData[53] = mData[33]; mData[33] = aHold;
    aHold = mData[4]; mData[4] = mData[38]; mData[38] = mData[50]; mData[50] = mData[16]; mData[16] = aHold;
    aHold = mData[5]; mData[5] = mData[39]; mData[39] = mData[51]; mData[51] = mData[17]; mData[17] = aHold;
    aHold = mData[8]; mData[8] = mData[14]; mData[14] = mData[62]; mData[62] = mData[56]; mData[56] = aHold;
    aHold = mData[9]; mData[9] = mData[15]; mData[15] = mData[63]; mData[63] = mData[57]; mData[57] = aHold;
    aHold = mData[10]; mData[10] = mData[30]; mData[30] = mData[60]; mData[60] = mData[40]; mData[40] = aHold;
    aHold = mData[11]; mData[11] = mData[31]; mData[31] = mData[61]; mData[61] = mData[41]; mData[41] = aHold;
    aHold = mData[12]; mData[12] = mData[46]; mData[46] = mData[58]; mData[58] = mData[24]; mData[24] = aHold;
    aHold = mData[13]; mData[13] = mData[47]; mData[47] = mData[59]; mData[59] = mData[25]; mData[25] = aHold;
    aHold = mData[18]; mData[18] = mData[20]; mData[20] = mData[36]; mData[36] = mData[34]; mData[34] = aHold;
    aHold = mData[19]; mData[19] = mData[21]; mData[21] = mData[37]; mData[37] = mData[35]; mData[35] = aHold;
    aHold = mData[26]; mData[26] = mData[28]; mData[28] = mData[44]; mData[44] = mData[42]; mData[42] = aHold;
    aHold = mData[27]; mData[27] = mData[29]; mData[29] = mData[45]; mData[45] = mData[43]; mData[43] = aHold;
}

void M88::Full_RotB_EachQuad_4x4() {
    Quad_RotB_4x4_A();
    Quad_RotB_4x4_B();
    Quad_RotB_4x4_C();
    Quad_RotB_4x4_D();
}

void M88::Quad_RotB_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[3]; mData[3] = mData[27]; mData[27] = mData[24]; mData[24] = aHold;
    aHold = mData[1]; mData[1] = mData[11]; mData[11] = mData[26]; mData[26] = mData[16]; mData[16] = aHold;
    aHold = mData[2]; mData[2] = mData[19]; mData[19] = mData[25]; mData[25] = mData[8]; mData[8] = aHold;
    aHold = mData[9]; mData[9] = mData[10]; mData[10] = mData[18]; mData[18] = mData[17]; mData[17] = aHold;
}

void M88::Quad_RotB_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[7]; mData[7] = mData[31]; mData[31] = mData[28]; mData[28] = aHold;
    aHold = mData[5]; mData[5] = mData[15]; mData[15] = mData[30]; mData[30] = mData[20]; mData[20] = aHold;
    aHold = mData[6]; mData[6] = mData[23]; mData[23] = mData[29]; mData[29] = mData[12]; mData[12] = aHold;
    aHold = mData[13]; mData[13] = mData[14]; mData[14] = mData[22]; mData[22] = mData[21]; mData[21] = aHold;
}

void M88::Quad_RotB_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[35]; mData[35] = mData[59]; mData[59] = mData[56]; mData[56] = aHold;
    aHold = mData[33]; mData[33] = mData[43]; mData[43] = mData[58]; mData[58] = mData[48]; mData[48] = aHold;
    aHold = mData[34]; mData[34] = mData[51]; mData[51] = mData[57]; mData[57] = mData[40]; mData[40] = aHold;
    aHold = mData[41]; mData[41] = mData[42]; mData[42] = mData[50]; mData[50] = mData[49]; mData[49] = aHold;
}

void M88::Quad_RotB_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[39]; mData[39] = mData[63]; mData[63] = mData[60]; mData[60] = aHold;
    aHold = mData[37]; mData[37] = mData[47]; mData[47] = mData[62]; mData[62] = mData[52]; mData[52] = aHold;
    aHold = mData[38]; mData[38] = mData[55]; mData[55] = mData[61]; mData[61] = mData[44]; mData[44] = aHold;
    aHold = mData[45]; mData[45] = mData[46]; mData[46] = mData[54]; mData[54] = mData[53]; mData[53] = aHold;
}


void M88::Full_RotB_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[7]; mData[7] = mData[63]; mData[63] = mData[56]; mData[56] = aHold;
    aHold = mData[1]; mData[1] = mData[15]; mData[15] = mData[62]; mData[62] = mData[48]; mData[48] = aHold;
    aHold = mData[2]; mData[2] = mData[23]; mData[23] = mData[61]; mData[61] = mData[40]; mData[40] = aHold;
    aHold = mData[3]; mData[3] = mData[31]; mData[31] = mData[60]; mData[60] = mData[32]; mData[32] = aHold;
    aHold = mData[4]; mData[4] = mData[39]; mData[39] = mData[59]; mData[59] = mData[24]; mData[24] = aHold;
    aHold = mData[5]; mData[5] = mData[47]; mData[47] = mData[58]; mData[58] = mData[16]; mData[16] = aHold;
    aHold = mData[6]; mData[6] = mData[55]; mData[55] = mData[57]; mData[57] = mData[8]; mData[8] = aHold;
    aHold = mData[9]; mData[9] = mData[14]; mData[14] = mData[54]; mData[54] = mData[49]; mData[49] = aHold;
    aHold = mData[10]; mData[10] = mData[22]; mData[22] = mData[53]; mData[53] = mData[41]; mData[41] = aHold;
    aHold = mData[11]; mData[11] = mData[30]; mData[30] = mData[52]; mData[52] = mData[33]; mData[33] = aHold;
    aHold = mData[12]; mData[12] = mData[38]; mData[38] = mData[51]; mData[51] = mData[25]; mData[25] = aHold;
    aHold = mData[13]; mData[13] = mData[46]; mData[46] = mData[50]; mData[50] = mData[17]; mData[17] = aHold;
    aHold = mData[18]; mData[18] = mData[21]; mData[21] = mData[45]; mData[45] = mData[42]; mData[42] = aHold;
    aHold = mData[19]; mData[19] = mData[29]; mData[29] = mData[44]; mData[44] = mData[34]; mData[34] = aHold;
    aHold = mData[20]; mData[20] = mData[37]; mData[37] = mData[43]; mData[43] = mData[26]; mData[26] = aHold;
    aHold = mData[27]; mData[27] = mData[28]; mData[28] = mData[36]; mData[36] = mData[35]; mData[35] = aHold;
}


void M88::Full_RotC_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[36]; mData[36] = aHold;
    aHold = mData[1]; mData[1] = mData[37]; mData[37] = aHold;
    aHold = mData[2]; mData[2] = mData[38]; mData[38] = aHold;
    aHold = mData[3]; mData[3] = mData[39]; mData[39] = aHold;
    aHold = mData[4]; mData[4] = mData[32]; mData[32] = aHold;
    aHold = mData[5]; mData[5] = mData[33]; mData[33] = aHold;
    aHold = mData[6]; mData[6] = mData[34]; mData[34] = aHold;
    aHold = mData[7]; mData[7] = mData[35]; mData[35] = aHold;
    aHold = mData[8]; mData[8] = mData[44]; mData[44] = aHold;
    aHold = mData[9]; mData[9] = mData[45]; mData[45] = aHold;
    aHold = mData[10]; mData[10] = mData[46]; mData[46] = aHold;
    aHold = mData[11]; mData[11] = mData[47]; mData[47] = aHold;
    aHold = mData[12]; mData[12] = mData[40]; mData[40] = aHold;
    aHold = mData[13]; mData[13] = mData[41]; mData[41] = aHold;
    aHold = mData[14]; mData[14] = mData[42]; mData[42] = aHold;
    aHold = mData[15]; mData[15] = mData[43]; mData[43] = aHold;
    aHold = mData[16]; mData[16] = mData[52]; mData[52] = aHold;
    aHold = mData[17]; mData[17] = mData[53]; mData[53] = aHold;
    aHold = mData[18]; mData[18] = mData[54]; mData[54] = aHold;
    aHold = mData[19]; mData[19] = mData[55]; mData[55] = aHold;
    aHold = mData[20]; mData[20] = mData[48]; mData[48] = aHold;
    aHold = mData[21]; mData[21] = mData[49]; mData[49] = aHold;
    aHold = mData[22]; mData[22] = mData[50]; mData[50] = aHold;
    aHold = mData[23]; mData[23] = mData[51]; mData[51] = aHold;
    aHold = mData[24]; mData[24] = mData[60]; mData[60] = aHold;
    aHold = mData[25]; mData[25] = mData[61]; mData[61] = aHold;
    aHold = mData[26]; mData[26] = mData[62]; mData[62] = aHold;
    aHold = mData[27]; mData[27] = mData[63]; mData[63] = aHold;
    aHold = mData[28]; mData[28] = mData[56]; mData[56] = aHold;
    aHold = mData[29]; mData[29] = mData[57]; mData[57] = aHold;
    aHold = mData[30]; mData[30] = mData[58]; mData[58] = aHold;
    aHold = mData[31]; mData[31] = mData[59]; mData[59] = aHold;
}

void M88::Full_RotC_EachQuad_2x2() {
    Quad_RotC_2x2_A();
    Quad_RotC_2x2_B();
    Quad_RotC_2x2_C();
    Quad_RotC_2x2_D();
}

void M88::Full_RotC_EachMini_2x2() {
    Mini_RotC_2x2_A();
    Mini_RotC_2x2_B();
    Mini_RotC_2x2_C();
    Mini_RotC_2x2_D();
    Mini_RotC_2x2_E();
    Mini_RotC_2x2_F();
    Mini_RotC_2x2_G();
    Mini_RotC_2x2_H();
    Mini_RotC_2x2_I();
    Mini_RotC_2x2_J();
    Mini_RotC_2x2_K();
    Mini_RotC_2x2_L();
    Mini_RotC_2x2_M();
    Mini_RotC_2x2_N();
    Mini_RotC_2x2_O();
    Mini_RotC_2x2_P();
}

void M88::Quad_RotC_EachMini_2x2_A() {
    Mini_RotC_2x2_A();
    Mini_RotC_2x2_B();
    Mini_RotC_2x2_E();
    Mini_RotC_2x2_F();
}

void M88::Quad_RotC_EachMini_2x2_B() {
    Mini_RotC_2x2_C();
    Mini_RotC_2x2_D();
    Mini_RotC_2x2_G();
    Mini_RotC_2x2_H();
}

void M88::Quad_RotC_EachMini_2x2_C() {
    Mini_RotC_2x2_I();
    Mini_RotC_2x2_J();
    Mini_RotC_2x2_M();
    Mini_RotC_2x2_N();
}

void M88::Quad_RotC_EachMini_2x2_D() {
    Mini_RotC_2x2_K();
    Mini_RotC_2x2_L();
    Mini_RotC_2x2_O();
    Mini_RotC_2x2_P();
}

void M88::Quad_RotC_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[18]; mData[18] = aHold;
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = aHold;
    aHold = mData[2]; mData[2] = mData[16]; mData[16] = aHold;
    aHold = mData[3]; mData[3] = mData[17]; mData[17] = aHold;
    aHold = mData[8]; mData[8] = mData[26]; mData[26] = aHold;
    aHold = mData[9]; mData[9] = mData[27]; mData[27] = aHold;
    aHold = mData[10]; mData[10] = mData[24]; mData[24] = aHold;
    aHold = mData[11]; mData[11] = mData[25]; mData[25] = aHold;
}

void M88::Quad_RotC_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[22]; mData[22] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = aHold;
    aHold = mData[6]; mData[6] = mData[20]; mData[20] = aHold;
    aHold = mData[7]; mData[7] = mData[21]; mData[21] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[31]; mData[31] = aHold;
    aHold = mData[14]; mData[14] = mData[28]; mData[28] = aHold;
    aHold = mData[15]; mData[15] = mData[29]; mData[29] = aHold;
}

void M88::Quad_RotC_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[50]; mData[50] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = aHold;
    aHold = mData[34]; mData[34] = mData[48]; mData[48] = aHold;
    aHold = mData[35]; mData[35] = mData[49]; mData[49] = aHold;
    aHold = mData[40]; mData[40] = mData[58]; mData[58] = aHold;
    aHold = mData[41]; mData[41] = mData[59]; mData[59] = aHold;
    aHold = mData[42]; mData[42] = mData[56]; mData[56] = aHold;
    aHold = mData[43]; mData[43] = mData[57]; mData[57] = aHold;
}

void M88::Quad_RotC_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[54]; mData[54] = aHold;
    aHold = mData[37]; mData[37] = mData[55]; mData[55] = aHold;
    aHold = mData[38]; mData[38] = mData[52]; mData[52] = aHold;
    aHold = mData[39]; mData[39] = mData[53]; mData[53] = aHold;
    aHold = mData[44]; mData[44] = mData[62]; mData[62] = aHold;
    aHold = mData[45]; mData[45] = mData[63]; mData[63] = aHold;
    aHold = mData[46]; mData[46] = mData[60]; mData[60] = aHold;
    aHold = mData[47]; mData[47] = mData[61]; mData[61] = aHold;
}

void M88::Mini_RotC_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = aHold;
    aHold = mData[1]; mData[1] = mData[8]; mData[8] = aHold;
}

void M88::Mini_RotC_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = aHold;
    aHold = mData[3]; mData[3] = mData[10]; mData[10] = aHold;
}

void M88::Mini_RotC_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = aHold;
    aHold = mData[5]; mData[5] = mData[12]; mData[12] = aHold;
}

void M88::Mini_RotC_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = aHold;
    aHold = mData[7]; mData[7] = mData[14]; mData[14] = aHold;
}

void M88::Mini_RotC_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = aHold;
    aHold = mData[17]; mData[17] = mData[24]; mData[24] = aHold;
}

void M88::Mini_RotC_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = aHold;
    aHold = mData[19]; mData[19] = mData[26]; mData[26] = aHold;
}

void M88::Mini_RotC_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = aHold;
    aHold = mData[21]; mData[21] = mData[28]; mData[28] = aHold;
}

void M88::Mini_RotC_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = aHold;
    aHold = mData[23]; mData[23] = mData[30]; mData[30] = aHold;
}

void M88::Mini_RotC_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = aHold;
    aHold = mData[33]; mData[33] = mData[40]; mData[40] = aHold;
}

void M88::Mini_RotC_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = aHold;
    aHold = mData[35]; mData[35] = mData[42]; mData[42] = aHold;
}

void M88::Mini_RotC_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = aHold;
    aHold = mData[37]; mData[37] = mData[44]; mData[44] = aHold;
}

void M88::Mini_RotC_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = aHold;
    aHold = mData[39]; mData[39] = mData[46]; mData[46] = aHold;
}

void M88::Mini_RotC_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = aHold;
    aHold = mData[49]; mData[49] = mData[56]; mData[56] = aHold;
}

void M88::Mini_RotC_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = aHold;
    aHold = mData[51]; mData[51] = mData[58]; mData[58] = aHold;
}

void M88::Mini_RotC_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = aHold;
    aHold = mData[53]; mData[53] = mData[60]; mData[60] = aHold;
}

void M88::Mini_RotC_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = aHold;
    aHold = mData[55]; mData[55] = mData[62]; mData[62] = aHold;
}

void M88::Full_RotC_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[54]; mData[54] = aHold;
    aHold = mData[1]; mData[1] = mData[55]; mData[55] = aHold;
    aHold = mData[2]; mData[2] = mData[52]; mData[52] = aHold;
    aHold = mData[3]; mData[3] = mData[53]; mData[53] = aHold;
    aHold = mData[4]; mData[4] = mData[50]; mData[50] = aHold;
    aHold = mData[5]; mData[5] = mData[51]; mData[51] = aHold;
    aHold = mData[6]; mData[6] = mData[48]; mData[48] = aHold;
    aHold = mData[7]; mData[7] = mData[49]; mData[49] = aHold;
    aHold = mData[8]; mData[8] = mData[62]; mData[62] = aHold;
    aHold = mData[9]; mData[9] = mData[63]; mData[63] = aHold;
    aHold = mData[10]; mData[10] = mData[60]; mData[60] = aHold;
    aHold = mData[11]; mData[11] = mData[61]; mData[61] = aHold;
    aHold = mData[12]; mData[12] = mData[58]; mData[58] = aHold;
    aHold = mData[13]; mData[13] = mData[59]; mData[59] = aHold;
    aHold = mData[14]; mData[14] = mData[56]; mData[56] = aHold;
    aHold = mData[15]; mData[15] = mData[57]; mData[57] = aHold;
    aHold = mData[16]; mData[16] = mData[38]; mData[38] = aHold;
    aHold = mData[17]; mData[17] = mData[39]; mData[39] = aHold;
    aHold = mData[18]; mData[18] = mData[36]; mData[36] = aHold;
    aHold = mData[19]; mData[19] = mData[37]; mData[37] = aHold;
    aHold = mData[20]; mData[20] = mData[34]; mData[34] = aHold;
    aHold = mData[21]; mData[21] = mData[35]; mData[35] = aHold;
    aHold = mData[22]; mData[22] = mData[32]; mData[32] = aHold;
    aHold = mData[23]; mData[23] = mData[33]; mData[33] = aHold;
    aHold = mData[24]; mData[24] = mData[46]; mData[46] = aHold;
    aHold = mData[25]; mData[25] = mData[47]; mData[47] = aHold;
    aHold = mData[26]; mData[26] = mData[44]; mData[44] = aHold;
    aHold = mData[27]; mData[27] = mData[45]; mData[45] = aHold;
    aHold = mData[28]; mData[28] = mData[42]; mData[42] = aHold;
    aHold = mData[29]; mData[29] = mData[43]; mData[43] = aHold;
    aHold = mData[30]; mData[30] = mData[40]; mData[40] = aHold;
    aHold = mData[31]; mData[31] = mData[41]; mData[41] = aHold;
}

void M88::Full_RotC_EachQuad_4x4() {
    Quad_RotC_4x4_A();
    Quad_RotC_4x4_B();
    Quad_RotC_4x4_C();
    Quad_RotC_4x4_D();
}

void M88::Quad_RotC_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[27]; mData[27] = aHold;
    aHold = mData[1]; mData[1] = mData[26]; mData[26] = aHold;
    aHold = mData[2]; mData[2] = mData[25]; mData[25] = aHold;
    aHold = mData[3]; mData[3] = mData[24]; mData[24] = aHold;
    aHold = mData[8]; mData[8] = mData[19]; mData[19] = aHold;
    aHold = mData[9]; mData[9] = mData[18]; mData[18] = aHold;
    aHold = mData[10]; mData[10] = mData[17]; mData[17] = aHold;
    aHold = mData[11]; mData[11] = mData[16]; mData[16] = aHold;
}

void M88::Quad_RotC_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[31]; mData[31] = aHold;
    aHold = mData[5]; mData[5] = mData[30]; mData[30] = aHold;
    aHold = mData[6]; mData[6] = mData[29]; mData[29] = aHold;
    aHold = mData[7]; mData[7] = mData[28]; mData[28] = aHold;
    aHold = mData[12]; mData[12] = mData[23]; mData[23] = aHold;
    aHold = mData[13]; mData[13] = mData[22]; mData[22] = aHold;
    aHold = mData[14]; mData[14] = mData[21]; mData[21] = aHold;
    aHold = mData[15]; mData[15] = mData[20]; mData[20] = aHold;
}

void M88::Quad_RotC_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[59]; mData[59] = aHold;
    aHold = mData[33]; mData[33] = mData[58]; mData[58] = aHold;
    aHold = mData[34]; mData[34] = mData[57]; mData[57] = aHold;
    aHold = mData[35]; mData[35] = mData[56]; mData[56] = aHold;
    aHold = mData[40]; mData[40] = mData[51]; mData[51] = aHold;
    aHold = mData[41]; mData[41] = mData[50]; mData[50] = aHold;
    aHold = mData[42]; mData[42] = mData[49]; mData[49] = aHold;
    aHold = mData[43]; mData[43] = mData[48]; mData[48] = aHold;
}

void M88::Quad_RotC_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[63]; mData[63] = aHold;
    aHold = mData[37]; mData[37] = mData[62]; mData[62] = aHold;
    aHold = mData[38]; mData[38] = mData[61]; mData[61] = aHold;
    aHold = mData[39]; mData[39] = mData[60]; mData[60] = aHold;
    aHold = mData[44]; mData[44] = mData[55]; mData[55] = aHold;
    aHold = mData[45]; mData[45] = mData[54]; mData[54] = aHold;
    aHold = mData[46]; mData[46] = mData[53]; mData[53] = aHold;
    aHold = mData[47]; mData[47] = mData[52]; mData[52] = aHold;
}

void M88::Full_RotC_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[63]; mData[63] = aHold;
    aHold = mData[1]; mData[1] = mData[62]; mData[62] = aHold;
    aHold = mData[2]; mData[2] = mData[61]; mData[61] = aHold;
    aHold = mData[3]; mData[3] = mData[60]; mData[60] = aHold;
    aHold = mData[4]; mData[4] = mData[59]; mData[59] = aHold;
    aHold = mData[5]; mData[5] = mData[58]; mData[58] = aHold;
    aHold = mData[6]; mData[6] = mData[57]; mData[57] = aHold;
    aHold = mData[7]; mData[7] = mData[56]; mData[56] = aHold;
    aHold = mData[8]; mData[8] = mData[55]; mData[55] = aHold;
    aHold = mData[9]; mData[9] = mData[54]; mData[54] = aHold;
    aHold = mData[10]; mData[10] = mData[53]; mData[53] = aHold;
    aHold = mData[11]; mData[11] = mData[52]; mData[52] = aHold;
    aHold = mData[12]; mData[12] = mData[51]; mData[51] = aHold;
    aHold = mData[13]; mData[13] = mData[50]; mData[50] = aHold;
    aHold = mData[14]; mData[14] = mData[49]; mData[49] = aHold;
    aHold = mData[15]; mData[15] = mData[48]; mData[48] = aHold;
    aHold = mData[16]; mData[16] = mData[47]; mData[47] = aHold;
    aHold = mData[17]; mData[17] = mData[46]; mData[46] = aHold;
    aHold = mData[18]; mData[18] = mData[45]; mData[45] = aHold;
    aHold = mData[19]; mData[19] = mData[44]; mData[44] = aHold;
    aHold = mData[20]; mData[20] = mData[43]; mData[43] = aHold;
    aHold = mData[21]; mData[21] = mData[42]; mData[42] = aHold;
    aHold = mData[22]; mData[22] = mData[41]; mData[41] = aHold;
    aHold = mData[23]; mData[23] = mData[40]; mData[40] = aHold;
    aHold = mData[24]; mData[24] = mData[39]; mData[39] = aHold;
    aHold = mData[25]; mData[25] = mData[38]; mData[38] = aHold;
    aHold = mData[26]; mData[26] = mData[37]; mData[37] = aHold;
    aHold = mData[27]; mData[27] = mData[36]; mData[36] = aHold;
    aHold = mData[28]; mData[28] = mData[35]; mData[35] = aHold;
    aHold = mData[29]; mData[29] = mData[34]; mData[34] = aHold;
    aHold = mData[30]; mData[30] = mData[33]; mData[33] = aHold;
    aHold = mData[31]; mData[31] = mData[32]; mData[32] = aHold;
}




// ---------- CPP ----------
void M88::Full_FlipA_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = aHold;
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = aHold;
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = aHold;
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = aHold;
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = aHold;
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = aHold;
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[36]; mData[36] = aHold;
    aHold = mData[33]; mData[33] = mData[37]; mData[37] = aHold;
    aHold = mData[34]; mData[34] = mData[38]; mData[38] = aHold;
    aHold = mData[35]; mData[35] = mData[39]; mData[39] = aHold;
    aHold = mData[40]; mData[40] = mData[44]; mData[44] = aHold;
    aHold = mData[41]; mData[41] = mData[45]; mData[45] = aHold;
    aHold = mData[42]; mData[42] = mData[46]; mData[46] = aHold;
    aHold = mData[43]; mData[43] = mData[47]; mData[47] = aHold;
    aHold = mData[48]; mData[48] = mData[52]; mData[52] = aHold;
    aHold = mData[49]; mData[49] = mData[53]; mData[53] = aHold;
    aHold = mData[50]; mData[50] = mData[54]; mData[54] = aHold;
    aHold = mData[51]; mData[51] = mData[55]; mData[55] = aHold;
    aHold = mData[56]; mData[56] = mData[60]; mData[60] = aHold;
    aHold = mData[57]; mData[57] = mData[61]; mData[61] = aHold;
    aHold = mData[58]; mData[58] = mData[62]; mData[62] = aHold;
    aHold = mData[59]; mData[59] = mData[63]; mData[63] = aHold;
}

void M88::Full_FlipA_EachQuad_2x2() {
    Quad_FlipA_2x2_A();
    Quad_FlipA_2x2_B();
    Quad_FlipA_2x2_C();
    Quad_FlipA_2x2_D();
}

void M88::Full_FlipA_EachMini_2x2() {
    Mini_FlipA_2x2_A();
    Mini_FlipA_2x2_B();
    Mini_FlipA_2x2_C();
    Mini_FlipA_2x2_D();
    Mini_FlipA_2x2_E();
    Mini_FlipA_2x2_F();
    Mini_FlipA_2x2_G();
    Mini_FlipA_2x2_H();
    Mini_FlipA_2x2_I();
    Mini_FlipA_2x2_J();
    Mini_FlipA_2x2_K();
    Mini_FlipA_2x2_L();
    Mini_FlipA_2x2_M();
    Mini_FlipA_2x2_N();
    Mini_FlipA_2x2_O();
    Mini_FlipA_2x2_P();
}

void M88::Quad_FlipA_EachMini_2x2_A() {
    Mini_FlipA_2x2_A();
    Mini_FlipA_2x2_B();
    Mini_FlipA_2x2_E();
    Mini_FlipA_2x2_F();
}

void M88::Quad_FlipA_EachMini_2x2_B() {
    Mini_FlipA_2x2_C();
    Mini_FlipA_2x2_D();
    Mini_FlipA_2x2_G();
    Mini_FlipA_2x2_H();
}

void M88::Quad_FlipA_EachMini_2x2_C() {
    Mini_FlipA_2x2_I();
    Mini_FlipA_2x2_J();
    Mini_FlipA_2x2_M();
    Mini_FlipA_2x2_N();
}

void M88::Quad_FlipA_EachMini_2x2_D() {
    Mini_FlipA_2x2_K();
    Mini_FlipA_2x2_L();
    Mini_FlipA_2x2_O();
    Mini_FlipA_2x2_P();
}

void M88::Quad_FlipA_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
    aHold = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
}

void M88::Quad_FlipA_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = aHold;
    aHold = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
}

void M88::Quad_FlipA_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
    aHold = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
}

void M88::Quad_FlipA_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = aHold;
    aHold = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
    aHold = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}

void M88::Mini_FlipA_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = aHold;
    aHold = mData[8]; mData[8] = mData[9]; mData[9] = aHold;
}

void M88::Mini_FlipA_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = aHold;
    aHold = mData[10]; mData[10] = mData[11]; mData[11] = aHold;
}

void M88::Mini_FlipA_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = aHold;
    aHold = mData[12]; mData[12] = mData[13]; mData[13] = aHold;
}

void M88::Mini_FlipA_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = aHold;
    aHold = mData[14]; mData[14] = mData[15]; mData[15] = aHold;
}

void M88::Mini_FlipA_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = aHold;
    aHold = mData[24]; mData[24] = mData[25]; mData[25] = aHold;
}

void M88::Mini_FlipA_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = aHold;
    aHold = mData[26]; mData[26] = mData[27]; mData[27] = aHold;
}

void M88::Mini_FlipA_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = aHold;
    aHold = mData[28]; mData[28] = mData[29]; mData[29] = aHold;
}

void M88::Mini_FlipA_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = aHold;
    aHold = mData[30]; mData[30] = mData[31]; mData[31] = aHold;
}

void M88::Mini_FlipA_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = aHold;
    aHold = mData[40]; mData[40] = mData[41]; mData[41] = aHold;
}

void M88::Mini_FlipA_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = aHold;
    aHold = mData[42]; mData[42] = mData[43]; mData[43] = aHold;
}

void M88::Mini_FlipA_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = aHold;
    aHold = mData[44]; mData[44] = mData[45]; mData[45] = aHold;
}

void M88::Mini_FlipA_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = aHold;
    aHold = mData[46]; mData[46] = mData[47]; mData[47] = aHold;
}

void M88::Mini_FlipA_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = aHold;
    aHold = mData[56]; mData[56] = mData[57]; mData[57] = aHold;
}

void M88::Mini_FlipA_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = aHold;
    aHold = mData[58]; mData[58] = mData[59]; mData[59] = aHold;
}

void M88::Mini_FlipA_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = aHold;
    aHold = mData[60]; mData[60] = mData[61]; mData[61] = aHold;
}

void M88::Mini_FlipA_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = aHold;
    aHold = mData[62]; mData[62] = mData[63]; mData[63] = aHold;
}



void M88::Full_FlipA_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[6]; mData[6] = aHold;
    aHold = mData[1]; mData[1] = mData[7]; mData[7] = aHold;
    aHold = mData[2]; mData[2] = mData[4]; mData[4] = aHold;
    aHold = mData[3]; mData[3] = mData[5]; mData[5] = aHold;
    aHold = mData[8]; mData[8] = mData[14]; mData[14] = aHold;
    aHold = mData[9]; mData[9] = mData[15]; mData[15] = aHold;
    aHold = mData[10]; mData[10] = mData[12]; mData[12] = aHold;
    aHold = mData[11]; mData[11] = mData[13]; mData[13] = aHold;
    aHold = mData[16]; mData[16] = mData[22]; mData[22] = aHold;
    aHold = mData[17]; mData[17] = mData[23]; mData[23] = aHold;
    aHold = mData[18]; mData[18] = mData[20]; mData[20] = aHold;
    aHold = mData[19]; mData[19] = mData[21]; mData[21] = aHold;
    aHold = mData[24]; mData[24] = mData[30]; mData[30] = aHold;
    aHold = mData[25]; mData[25] = mData[31]; mData[31] = aHold;
    aHold = mData[26]; mData[26] = mData[28]; mData[28] = aHold;
    aHold = mData[27]; mData[27] = mData[29]; mData[29] = aHold;
    aHold = mData[32]; mData[32] = mData[38]; mData[38] = aHold;
    aHold = mData[33]; mData[33] = mData[39]; mData[39] = aHold;
    aHold = mData[34]; mData[34] = mData[36]; mData[36] = aHold;
    aHold = mData[35]; mData[35] = mData[37]; mData[37] = aHold;
    aHold = mData[40]; mData[40] = mData[46]; mData[46] = aHold;
    aHold = mData[41]; mData[41] = mData[47]; mData[47] = aHold;
    aHold = mData[42]; mData[42] = mData[44]; mData[44] = aHold;
    aHold = mData[43]; mData[43] = mData[45]; mData[45] = aHold;
    aHold = mData[48]; mData[48] = mData[54]; mData[54] = aHold;
    aHold = mData[49]; mData[49] = mData[55]; mData[55] = aHold;
    aHold = mData[50]; mData[50] = mData[52]; mData[52] = aHold;
    aHold = mData[51]; mData[51] = mData[53]; mData[53] = aHold;
    aHold = mData[56]; mData[56] = mData[62]; mData[62] = aHold;
    aHold = mData[57]; mData[57] = mData[63]; mData[63] = aHold;
    aHold = mData[58]; mData[58] = mData[60]; mData[60] = aHold;
    aHold = mData[59]; mData[59] = mData[61]; mData[61] = aHold;
}

void M88::Full_FlipA_EachQuad_4x4() {
    Quad_FlipA_4x4_A();
    Quad_FlipA_4x4_B();
    Quad_FlipA_4x4_C();
    Quad_FlipA_4x4_D();
}

void M88::Quad_FlipA_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[3]; mData[3] = aHold;
    aHold = mData[1]; mData[1] = mData[2]; mData[2] = aHold;
    aHold = mData[8]; mData[8] = mData[11]; mData[11] = aHold;
    aHold = mData[9]; mData[9] = mData[10]; mData[10] = aHold;
    aHold = mData[16]; mData[16] = mData[19]; mData[19] = aHold;
    aHold = mData[17]; mData[17] = mData[18]; mData[18] = aHold;
    aHold = mData[24]; mData[24] = mData[27]; mData[27] = aHold;
    aHold = mData[25]; mData[25] = mData[26]; mData[26] = aHold;
}

void M88::Quad_FlipA_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[7]; mData[7] = aHold;
    aHold = mData[5]; mData[5] = mData[6]; mData[6] = aHold;
    aHold = mData[12]; mData[12] = mData[15]; mData[15] = aHold;
    aHold = mData[13]; mData[13] = mData[14]; mData[14] = aHold;
    aHold = mData[20]; mData[20] = mData[23]; mData[23] = aHold;
    aHold = mData[21]; mData[21] = mData[22]; mData[22] = aHold;
    aHold = mData[28]; mData[28] = mData[31]; mData[31] = aHold;
    aHold = mData[29]; mData[29] = mData[30]; mData[30] = aHold;
}

void M88::Quad_FlipA_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[35]; mData[35] = aHold;
    aHold = mData[33]; mData[33] = mData[34]; mData[34] = aHold;
    aHold = mData[40]; mData[40] = mData[43]; mData[43] = aHold;
    aHold = mData[41]; mData[41] = mData[42]; mData[42] = aHold;
    aHold = mData[48]; mData[48] = mData[51]; mData[51] = aHold;
    aHold = mData[49]; mData[49] = mData[50]; mData[50] = aHold;
    aHold = mData[56]; mData[56] = mData[59]; mData[59] = aHold;
    aHold = mData[57]; mData[57] = mData[58]; mData[58] = aHold;
}

void M88::Quad_FlipA_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[39]; mData[39] = aHold;
    aHold = mData[37]; mData[37] = mData[38]; mData[38] = aHold;
    aHold = mData[44]; mData[44] = mData[47]; mData[47] = aHold;
    aHold = mData[45]; mData[45] = mData[46]; mData[46] = aHold;
    aHold = mData[52]; mData[52] = mData[55]; mData[55] = aHold;
    aHold = mData[53]; mData[53] = mData[54]; mData[54] = aHold;
    aHold = mData[60]; mData[60] = mData[63]; mData[63] = aHold;
    aHold = mData[61]; mData[61] = mData[62]; mData[62] = aHold;
}


void M88::Full_FlipA_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[7]; mData[7] = aHold;
    aHold = mData[1]; mData[1] = mData[6]; mData[6] = aHold;
    aHold = mData[2]; mData[2] = mData[5]; mData[5] = aHold;
    aHold = mData[3]; mData[3] = mData[4]; mData[4] = aHold;
    aHold = mData[8]; mData[8] = mData[15]; mData[15] = aHold;
    aHold = mData[9]; mData[9] = mData[14]; mData[14] = aHold;
    aHold = mData[10]; mData[10] = mData[13]; mData[13] = aHold;
    aHold = mData[11]; mData[11] = mData[12]; mData[12] = aHold;
    aHold = mData[16]; mData[16] = mData[23]; mData[23] = aHold;
    aHold = mData[17]; mData[17] = mData[22]; mData[22] = aHold;
    aHold = mData[18]; mData[18] = mData[21]; mData[21] = aHold;
    aHold = mData[19]; mData[19] = mData[20]; mData[20] = aHold;
    aHold = mData[24]; mData[24] = mData[31]; mData[31] = aHold;
    aHold = mData[25]; mData[25] = mData[30]; mData[30] = aHold;
    aHold = mData[26]; mData[26] = mData[29]; mData[29] = aHold;
    aHold = mData[27]; mData[27] = mData[28]; mData[28] = aHold;
    aHold = mData[32]; mData[32] = mData[39]; mData[39] = aHold;
    aHold = mData[33]; mData[33] = mData[38]; mData[38] = aHold;
    aHold = mData[34]; mData[34] = mData[37]; mData[37] = aHold;
    aHold = mData[35]; mData[35] = mData[36]; mData[36] = aHold;
    aHold = mData[40]; mData[40] = mData[47]; mData[47] = aHold;
    aHold = mData[41]; mData[41] = mData[46]; mData[46] = aHold;
    aHold = mData[42]; mData[42] = mData[45]; mData[45] = aHold;
    aHold = mData[43]; mData[43] = mData[44]; mData[44] = aHold;
    aHold = mData[48]; mData[48] = mData[55]; mData[55] = aHold;
    aHold = mData[49]; mData[49] = mData[54]; mData[54] = aHold;
    aHold = mData[50]; mData[50] = mData[53]; mData[53] = aHold;
    aHold = mData[51]; mData[51] = mData[52]; mData[52] = aHold;
    aHold = mData[56]; mData[56] = mData[63]; mData[63] = aHold;
    aHold = mData[57]; mData[57] = mData[62]; mData[62] = aHold;
    aHold = mData[58]; mData[58] = mData[61]; mData[61] = aHold;
    aHold = mData[59]; mData[59] = mData[60]; mData[60] = aHold;
}


void M88::Full_FlipB_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = aHold;
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = aHold;
    aHold = mData[4]; mData[4] = mData[36]; mData[36] = aHold;
    aHold = mData[5]; mData[5] = mData[37]; mData[37] = aHold;
    aHold = mData[6]; mData[6] = mData[38]; mData[38] = aHold;
    aHold = mData[7]; mData[7] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = aHold;
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = aHold;
    aHold = mData[12]; mData[12] = mData[44]; mData[44] = aHold;
    aHold = mData[13]; mData[13] = mData[45]; mData[45] = aHold;
    aHold = mData[14]; mData[14] = mData[46]; mData[46] = aHold;
    aHold = mData[15]; mData[15] = mData[47]; mData[47] = aHold;
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = aHold;
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = aHold;
    aHold = mData[20]; mData[20] = mData[52]; mData[52] = aHold;
    aHold = mData[21]; mData[21] = mData[53]; mData[53] = aHold;
    aHold = mData[22]; mData[22] = mData[54]; mData[54] = aHold;
    aHold = mData[23]; mData[23] = mData[55]; mData[55] = aHold;
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = aHold;
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = aHold;
    aHold = mData[28]; mData[28] = mData[60]; mData[60] = aHold;
    aHold = mData[29]; mData[29] = mData[61]; mData[61] = aHold;
    aHold = mData[30]; mData[30] = mData[62]; mData[62] = aHold;
    aHold = mData[31]; mData[31] = mData[63]; mData[63] = aHold;
}

void M88::Full_FlipB_EachQuad_2x2() {
    Quad_FlipB_2x2_A();
    Quad_FlipB_2x2_B();
    Quad_FlipB_2x2_C();
    Quad_FlipB_2x2_D();
}

void M88::Full_FlipB_EachMini_2x2() {
    Mini_FlipB_2x2_A();
    Mini_FlipB_2x2_B();
    Mini_FlipB_2x2_C();
    Mini_FlipB_2x2_D();
    Mini_FlipB_2x2_E();
    Mini_FlipB_2x2_F();
    Mini_FlipB_2x2_G();
    Mini_FlipB_2x2_H();
    Mini_FlipB_2x2_I();
    Mini_FlipB_2x2_J();
    Mini_FlipB_2x2_K();
    Mini_FlipB_2x2_L();
    Mini_FlipB_2x2_M();
    Mini_FlipB_2x2_N();
    Mini_FlipB_2x2_O();
    Mini_FlipB_2x2_P();
}

void M88::Quad_FlipB_EachMini_2x2_A() {
    Mini_FlipB_2x2_A();
    Mini_FlipB_2x2_B();
    Mini_FlipB_2x2_E();
    Mini_FlipB_2x2_F();
}

void M88::Quad_FlipB_EachMini_2x2_B() {
    Mini_FlipB_2x2_C();
    Mini_FlipB_2x2_D();
    Mini_FlipB_2x2_G();
    Mini_FlipB_2x2_H();
}

void M88::Quad_FlipB_EachMini_2x2_C() {
    Mini_FlipB_2x2_I();
    Mini_FlipB_2x2_J();
    Mini_FlipB_2x2_M();
    Mini_FlipB_2x2_N();
}

void M88::Quad_FlipB_EachMini_2x2_D() {
    Mini_FlipB_2x2_K();
    Mini_FlipB_2x2_L();
    Mini_FlipB_2x2_O();
    Mini_FlipB_2x2_P();
}

void M88::Quad_FlipB_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = aHold;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[19]; mData[19] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[27]; mData[27] = aHold;
}

void M88::Quad_FlipB_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = aHold;
    aHold = mData[6]; mData[6] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[23]; mData[23] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = aHold;
    aHold = mData[14]; mData[14] = mData[30]; mData[30] = aHold;
    aHold = mData[15]; mData[15] = mData[31]; mData[31] = aHold;
}

void M88::Quad_FlipB_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = aHold;
    aHold = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = aHold;
    aHold = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
}

void M88::Quad_FlipB_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = aHold;
    aHold = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = aHold;
    aHold = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
}

void M88::Mini_FlipB_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = aHold;
    aHold = mData[1]; mData[1] = mData[9]; mData[9] = aHold;
}

void M88::Mini_FlipB_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = aHold;
    aHold = mData[3]; mData[3] = mData[11]; mData[11] = aHold;
}

void M88::Mini_FlipB_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = aHold;
    aHold = mData[5]; mData[5] = mData[13]; mData[13] = aHold;
}

void M88::Mini_FlipB_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = aHold;
    aHold = mData[7]; mData[7] = mData[15]; mData[15] = aHold;
}

void M88::Mini_FlipB_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = aHold;
    aHold = mData[17]; mData[17] = mData[25]; mData[25] = aHold;
}

void M88::Mini_FlipB_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = aHold;
    aHold = mData[19]; mData[19] = mData[27]; mData[27] = aHold;
}

void M88::Mini_FlipB_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = aHold;
    aHold = mData[21]; mData[21] = mData[29]; mData[29] = aHold;
}

void M88::Mini_FlipB_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = aHold;
    aHold = mData[23]; mData[23] = mData[31]; mData[31] = aHold;
}

void M88::Mini_FlipB_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = aHold;
    aHold = mData[33]; mData[33] = mData[41]; mData[41] = aHold;
}

void M88::Mini_FlipB_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = aHold;
    aHold = mData[35]; mData[35] = mData[43]; mData[43] = aHold;
}

void M88::Mini_FlipB_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = aHold;
    aHold = mData[37]; mData[37] = mData[45]; mData[45] = aHold;
}

void M88::Mini_FlipB_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = aHold;
    aHold = mData[39]; mData[39] = mData[47]; mData[47] = aHold;
}

void M88::Mini_FlipB_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = aHold;
    aHold = mData[49]; mData[49] = mData[57]; mData[57] = aHold;
}

void M88::Mini_FlipB_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = aHold;
    aHold = mData[51]; mData[51] = mData[59]; mData[59] = aHold;
}

void M88::Mini_FlipB_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = aHold;
    aHold = mData[53]; mData[53] = mData[61]; mData[61] = aHold;
}

void M88::Mini_FlipB_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = aHold;
    aHold = mData[55]; mData[55] = mData[63]; mData[63] = aHold;
}


void M88::Full_FlipB_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[48]; mData[48] = aHold;
    aHold = mData[1]; mData[1] = mData[49]; mData[49] = aHold;
    aHold = mData[2]; mData[2] = mData[50]; mData[50] = aHold;
    aHold = mData[3]; mData[3] = mData[51]; mData[51] = aHold;
    aHold = mData[4]; mData[4] = mData[52]; mData[52] = aHold;
    aHold = mData[5]; mData[5] = mData[53]; mData[53] = aHold;
    aHold = mData[6]; mData[6] = mData[54]; mData[54] = aHold;
    aHold = mData[7]; mData[7] = mData[55]; mData[55] = aHold;
    aHold = mData[8]; mData[8] = mData[56]; mData[56] = aHold;
    aHold = mData[9]; mData[9] = mData[57]; mData[57] = aHold;
    aHold = mData[10]; mData[10] = mData[58]; mData[58] = aHold;
    aHold = mData[11]; mData[11] = mData[59]; mData[59] = aHold;
    aHold = mData[12]; mData[12] = mData[60]; mData[60] = aHold;
    aHold = mData[13]; mData[13] = mData[61]; mData[61] = aHold;
    aHold = mData[14]; mData[14] = mData[62]; mData[62] = aHold;
    aHold = mData[15]; mData[15] = mData[63]; mData[63] = aHold;
    aHold = mData[16]; mData[16] = mData[32]; mData[32] = aHold;
    aHold = mData[17]; mData[17] = mData[33]; mData[33] = aHold;
    aHold = mData[18]; mData[18] = mData[34]; mData[34] = aHold;
    aHold = mData[19]; mData[19] = mData[35]; mData[35] = aHold;
    aHold = mData[20]; mData[20] = mData[36]; mData[36] = aHold;
    aHold = mData[21]; mData[21] = mData[37]; mData[37] = aHold;
    aHold = mData[22]; mData[22] = mData[38]; mData[38] = aHold;
    aHold = mData[23]; mData[23] = mData[39]; mData[39] = aHold;
    aHold = mData[24]; mData[24] = mData[40]; mData[40] = aHold;
    aHold = mData[25]; mData[25] = mData[41]; mData[41] = aHold;
    aHold = mData[26]; mData[26] = mData[42]; mData[42] = aHold;
    aHold = mData[27]; mData[27] = mData[43]; mData[43] = aHold;
    aHold = mData[28]; mData[28] = mData[44]; mData[44] = aHold;
    aHold = mData[29]; mData[29] = mData[45]; mData[45] = aHold;
    aHold = mData[30]; mData[30] = mData[46]; mData[46] = aHold;
    aHold = mData[31]; mData[31] = mData[47]; mData[47] = aHold;
}

void M88::Full_FlipB_EachQuad_4x4() {
    Quad_FlipB_4x4_A();
    Quad_FlipB_4x4_B();
    Quad_FlipB_4x4_C();
    Quad_FlipB_4x4_D();
}

void M88::Quad_FlipB_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[24]; mData[24] = aHold;
    aHold = mData[1]; mData[1] = mData[25]; mData[25] = aHold;
    aHold = mData[2]; mData[2] = mData[26]; mData[26] = aHold;
    aHold = mData[3]; mData[3] = mData[27]; mData[27] = aHold;
    aHold = mData[8]; mData[8] = mData[16]; mData[16] = aHold;
    aHold = mData[9]; mData[9] = mData[17]; mData[17] = aHold;
    aHold = mData[10]; mData[10] = mData[18]; mData[18] = aHold;
    aHold = mData[11]; mData[11] = mData[19]; mData[19] = aHold;
}

void M88::Quad_FlipB_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[28]; mData[28] = aHold;
    aHold = mData[5]; mData[5] = mData[29]; mData[29] = aHold;
    aHold = mData[6]; mData[6] = mData[30]; mData[30] = aHold;
    aHold = mData[7]; mData[7] = mData[31]; mData[31] = aHold;
    aHold = mData[12]; mData[12] = mData[20]; mData[20] = aHold;
    aHold = mData[13]; mData[13] = mData[21]; mData[21] = aHold;
    aHold = mData[14]; mData[14] = mData[22]; mData[22] = aHold;
    aHold = mData[15]; mData[15] = mData[23]; mData[23] = aHold;
}

void M88::Quad_FlipB_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[56]; mData[56] = aHold;
    aHold = mData[33]; mData[33] = mData[57]; mData[57] = aHold;
    aHold = mData[34]; mData[34] = mData[58]; mData[58] = aHold;
    aHold = mData[35]; mData[35] = mData[59]; mData[59] = aHold;
    aHold = mData[40]; mData[40] = mData[48]; mData[48] = aHold;
    aHold = mData[41]; mData[41] = mData[49]; mData[49] = aHold;
    aHold = mData[42]; mData[42] = mData[50]; mData[50] = aHold;
    aHold = mData[43]; mData[43] = mData[51]; mData[51] = aHold;
}

void M88::Quad_FlipB_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[60]; mData[60] = aHold;
    aHold = mData[37]; mData[37] = mData[61]; mData[61] = aHold;
    aHold = mData[38]; mData[38] = mData[62]; mData[62] = aHold;
    aHold = mData[39]; mData[39] = mData[63]; mData[63] = aHold;
    aHold = mData[44]; mData[44] = mData[52]; mData[52] = aHold;
    aHold = mData[45]; mData[45] = mData[53]; mData[53] = aHold;
    aHold = mData[46]; mData[46] = mData[54]; mData[54] = aHold;
    aHold = mData[47]; mData[47] = mData[55]; mData[55] = aHold;
}

void M88::Full_FlipB_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[56]; mData[56] = aHold;
    aHold = mData[1]; mData[1] = mData[57]; mData[57] = aHold;
    aHold = mData[2]; mData[2] = mData[58]; mData[58] = aHold;
    aHold = mData[3]; mData[3] = mData[59]; mData[59] = aHold;
    aHold = mData[4]; mData[4] = mData[60]; mData[60] = aHold;
    aHold = mData[5]; mData[5] = mData[61]; mData[61] = aHold;
    aHold = mData[6]; mData[6] = mData[62]; mData[62] = aHold;
    aHold = mData[7]; mData[7] = mData[63]; mData[63] = aHold;
    aHold = mData[8]; mData[8] = mData[48]; mData[48] = aHold;
    aHold = mData[9]; mData[9] = mData[49]; mData[49] = aHold;
    aHold = mData[10]; mData[10] = mData[50]; mData[50] = aHold;
    aHold = mData[11]; mData[11] = mData[51]; mData[51] = aHold;
    aHold = mData[12]; mData[12] = mData[52]; mData[52] = aHold;
    aHold = mData[13]; mData[13] = mData[53]; mData[53] = aHold;
    aHold = mData[14]; mData[14] = mData[54]; mData[54] = aHold;
    aHold = mData[15]; mData[15] = mData[55]; mData[55] = aHold;
    aHold = mData[16]; mData[16] = mData[40]; mData[40] = aHold;
    aHold = mData[17]; mData[17] = mData[41]; mData[41] = aHold;
    aHold = mData[18]; mData[18] = mData[42]; mData[42] = aHold;
    aHold = mData[19]; mData[19] = mData[43]; mData[43] = aHold;
    aHold = mData[20]; mData[20] = mData[44]; mData[44] = aHold;
    aHold = mData[21]; mData[21] = mData[45]; mData[45] = aHold;
    aHold = mData[22]; mData[22] = mData[46]; mData[46] = aHold;
    aHold = mData[23]; mData[23] = mData[47]; mData[47] = aHold;
    aHold = mData[24]; mData[24] = mData[32]; mData[32] = aHold;
    aHold = mData[25]; mData[25] = mData[33]; mData[33] = aHold;
    aHold = mData[26]; mData[26] = mData[34]; mData[34] = aHold;
    aHold = mData[27]; mData[27] = mData[35]; mData[35] = aHold;
    aHold = mData[28]; mData[28] = mData[36]; mData[36] = aHold;
    aHold = mData[29]; mData[29] = mData[37]; mData[37] = aHold;
    aHold = mData[30]; mData[30] = mData[38]; mData[38] = aHold;
    aHold = mData[31]; mData[31] = mData[39]; mData[39] = aHold;
}


void M88::Full_FlipC_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[32]; mData[32] = aHold;
    aHold = mData[5]; mData[5] = mData[33]; mData[33] = aHold;
    aHold = mData[6]; mData[6] = mData[34]; mData[34] = aHold;
    aHold = mData[7]; mData[7] = mData[35]; mData[35] = aHold;
    aHold = mData[12]; mData[12] = mData[40]; mData[40] = aHold;
    aHold = mData[13]; mData[13] = mData[41]; mData[41] = aHold;
    aHold = mData[14]; mData[14] = mData[42]; mData[42] = aHold;
    aHold = mData[15]; mData[15] = mData[43]; mData[43] = aHold;
    aHold = mData[20]; mData[20] = mData[48]; mData[48] = aHold;
    aHold = mData[21]; mData[21] = mData[49]; mData[49] = aHold;
    aHold = mData[22]; mData[22] = mData[50]; mData[50] = aHold;
    aHold = mData[23]; mData[23] = mData[51]; mData[51] = aHold;
    aHold = mData[28]; mData[28] = mData[56]; mData[56] = aHold;
    aHold = mData[29]; mData[29] = mData[57]; mData[57] = aHold;
    aHold = mData[30]; mData[30] = mData[58]; mData[58] = aHold;
    aHold = mData[31]; mData[31] = mData[59]; mData[59] = aHold;
}

void M88::Full_FlipC_EachQuad_2x2() {
    Quad_FlipC_2x2_A();
    Quad_FlipC_2x2_B();
    Quad_FlipC_2x2_C();
    Quad_FlipC_2x2_D();
}

void M88::Full_FlipC_EachMini_2x2() {
    Mini_FlipC_2x2_A();
    Mini_FlipC_2x2_B();
    Mini_FlipC_2x2_C();
    Mini_FlipC_2x2_D();
    Mini_FlipC_2x2_E();
    Mini_FlipC_2x2_F();
    Mini_FlipC_2x2_G();
    Mini_FlipC_2x2_H();
    Mini_FlipC_2x2_I();
    Mini_FlipC_2x2_J();
    Mini_FlipC_2x2_K();
    Mini_FlipC_2x2_L();
    Mini_FlipC_2x2_M();
    Mini_FlipC_2x2_N();
    Mini_FlipC_2x2_O();
    Mini_FlipC_2x2_P();
}

void M88::Quad_FlipC_EachMini_2x2_A() {
    Mini_FlipC_2x2_A();
    Mini_FlipC_2x2_B();
    Mini_FlipC_2x2_E();
    Mini_FlipC_2x2_F();
}

void M88::Quad_FlipC_EachMini_2x2_B() {
    Mini_FlipC_2x2_C();
    Mini_FlipC_2x2_D();
    Mini_FlipC_2x2_G();
    Mini_FlipC_2x2_H();
}

void M88::Quad_FlipC_EachMini_2x2_C() {
    Mini_FlipC_2x2_I();
    Mini_FlipC_2x2_J();
    Mini_FlipC_2x2_M();
    Mini_FlipC_2x2_N();
}

void M88::Quad_FlipC_EachMini_2x2_D() {
    Mini_FlipC_2x2_K();
    Mini_FlipC_2x2_L();
    Mini_FlipC_2x2_O();
    Mini_FlipC_2x2_P();
}

void M88::Quad_FlipC_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[16]; mData[16] = aHold;
    aHold = mData[3]; mData[3] = mData[17]; mData[17] = aHold;
    aHold = mData[10]; mData[10] = mData[24]; mData[24] = aHold;
    aHold = mData[11]; mData[11] = mData[25]; mData[25] = aHold;
}

void M88::Quad_FlipC_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[20]; mData[20] = aHold;
    aHold = mData[7]; mData[7] = mData[21]; mData[21] = aHold;
    aHold = mData[14]; mData[14] = mData[28]; mData[28] = aHold;
    aHold = mData[15]; mData[15] = mData[29]; mData[29] = aHold;
}

void M88::Quad_FlipC_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[48]; mData[48] = aHold;
    aHold = mData[35]; mData[35] = mData[49]; mData[49] = aHold;
    aHold = mData[42]; mData[42] = mData[56]; mData[56] = aHold;
    aHold = mData[43]; mData[43] = mData[57]; mData[57] = aHold;
}

void M88::Quad_FlipC_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[52]; mData[52] = aHold;
    aHold = mData[39]; mData[39] = mData[53]; mData[53] = aHold;
    aHold = mData[46]; mData[46] = mData[60]; mData[60] = aHold;
    aHold = mData[47]; mData[47] = mData[61]; mData[61] = aHold;
}

void M88::Mini_FlipC_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[1]; mData[1] = mData[8]; mData[8] = aHold;
}

void M88::Mini_FlipC_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[3]; mData[3] = mData[10]; mData[10] = aHold;
}

void M88::Mini_FlipC_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[5]; mData[5] = mData[12]; mData[12] = aHold;
}

void M88::Mini_FlipC_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[7]; mData[7] = mData[14]; mData[14] = aHold;
}

void M88::Mini_FlipC_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[17]; mData[17] = mData[24]; mData[24] = aHold;
}

void M88::Mini_FlipC_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[19]; mData[19] = mData[26]; mData[26] = aHold;
}

void M88::Mini_FlipC_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[21]; mData[21] = mData[28]; mData[28] = aHold;
}

void M88::Mini_FlipC_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[23]; mData[23] = mData[30]; mData[30] = aHold;
}

void M88::Mini_FlipC_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[33]; mData[33] = mData[40]; mData[40] = aHold;
}

void M88::Mini_FlipC_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[35]; mData[35] = mData[42]; mData[42] = aHold;
}

void M88::Mini_FlipC_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[37]; mData[37] = mData[44]; mData[44] = aHold;
}

void M88::Mini_FlipC_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[39]; mData[39] = mData[46]; mData[46] = aHold;
}

void M88::Mini_FlipC_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[49]; mData[49] = mData[56]; mData[56] = aHold;
}

void M88::Mini_FlipC_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[51]; mData[51] = mData[58]; mData[58] = aHold;
}

void M88::Mini_FlipC_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[53]; mData[53] = mData[60]; mData[60] = aHold;
}

void M88::Mini_FlipC_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[55]; mData[55] = mData[62]; mData[62] = aHold;
}


void M88::Full_FlipC_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[16]; mData[16] = aHold;
    aHold = mData[3]; mData[3] = mData[17]; mData[17] = aHold;
    aHold = mData[4]; mData[4] = mData[32]; mData[32] = aHold;
    aHold = mData[5]; mData[5] = mData[33]; mData[33] = aHold;
    aHold = mData[6]; mData[6] = mData[48]; mData[48] = aHold;
    aHold = mData[7]; mData[7] = mData[49]; mData[49] = aHold;
    aHold = mData[10]; mData[10] = mData[24]; mData[24] = aHold;
    aHold = mData[11]; mData[11] = mData[25]; mData[25] = aHold;
    aHold = mData[12]; mData[12] = mData[40]; mData[40] = aHold;
    aHold = mData[13]; mData[13] = mData[41]; mData[41] = aHold;
    aHold = mData[14]; mData[14] = mData[56]; mData[56] = aHold;
    aHold = mData[15]; mData[15] = mData[57]; mData[57] = aHold;
    aHold = mData[20]; mData[20] = mData[34]; mData[34] = aHold;
    aHold = mData[21]; mData[21] = mData[35]; mData[35] = aHold;
    aHold = mData[22]; mData[22] = mData[50]; mData[50] = aHold;
    aHold = mData[23]; mData[23] = mData[51]; mData[51] = aHold;
    aHold = mData[28]; mData[28] = mData[42]; mData[42] = aHold;
    aHold = mData[29]; mData[29] = mData[43]; mData[43] = aHold;
    aHold = mData[30]; mData[30] = mData[58]; mData[58] = aHold;
    aHold = mData[31]; mData[31] = mData[59]; mData[59] = aHold;
    aHold = mData[38]; mData[38] = mData[52]; mData[52] = aHold;
    aHold = mData[39]; mData[39] = mData[53]; mData[53] = aHold;
    aHold = mData[46]; mData[46] = mData[60]; mData[60] = aHold;
    aHold = mData[47]; mData[47] = mData[61]; mData[61] = aHold;
}

void M88::Full_FlipC_EachQuad_4x4() {
    Quad_FlipC_4x4_A();
    Quad_FlipC_4x4_B();
    Quad_FlipC_4x4_C();
    Quad_FlipC_4x4_D();
}

void M88::Quad_FlipC_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[1]; mData[1] = mData[8]; mData[8] = aHold;
    aHold = mData[2]; mData[2] = mData[16]; mData[16] = aHold;
    aHold = mData[3]; mData[3] = mData[24]; mData[24] = aHold;
    aHold = mData[10]; mData[10] = mData[17]; mData[17] = aHold;
    aHold = mData[11]; mData[11] = mData[25]; mData[25] = aHold;
    aHold = mData[19]; mData[19] = mData[26]; mData[26] = aHold;
}

void M88::Quad_FlipC_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[5]; mData[5] = mData[12]; mData[12] = aHold;
    aHold = mData[6]; mData[6] = mData[20]; mData[20] = aHold;
    aHold = mData[7]; mData[7] = mData[28]; mData[28] = aHold;
    aHold = mData[14]; mData[14] = mData[21]; mData[21] = aHold;
    aHold = mData[15]; mData[15] = mData[29]; mData[29] = aHold;
    aHold = mData[23]; mData[23] = mData[30]; mData[30] = aHold;
}

void M88::Quad_FlipC_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[33]; mData[33] = mData[40]; mData[40] = aHold;
    aHold = mData[34]; mData[34] = mData[48]; mData[48] = aHold;
    aHold = mData[35]; mData[35] = mData[56]; mData[56] = aHold;
    aHold = mData[42]; mData[42] = mData[49]; mData[49] = aHold;
    aHold = mData[43]; mData[43] = mData[57]; mData[57] = aHold;
    aHold = mData[51]; mData[51] = mData[58]; mData[58] = aHold;
}

void M88::Quad_FlipC_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[37]; mData[37] = mData[44]; mData[44] = aHold;
    aHold = mData[38]; mData[38] = mData[52]; mData[52] = aHold;
    aHold = mData[39]; mData[39] = mData[60]; mData[60] = aHold;
    aHold = mData[46]; mData[46] = mData[53]; mData[53] = aHold;
    aHold = mData[47]; mData[47] = mData[61]; mData[61] = aHold;
    aHold = mData[55]; mData[55] = mData[62]; mData[62] = aHold;
}


void M88::Full_FlipC_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[1]; mData[1] = mData[8]; mData[8] = aHold;
    aHold = mData[2]; mData[2] = mData[16]; mData[16] = aHold;
    aHold = mData[3]; mData[3] = mData[24]; mData[24] = aHold;
    aHold = mData[4]; mData[4] = mData[32]; mData[32] = aHold;
    aHold = mData[5]; mData[5] = mData[40]; mData[40] = aHold;
    aHold = mData[6]; mData[6] = mData[48]; mData[48] = aHold;
    aHold = mData[7]; mData[7] = mData[56]; mData[56] = aHold;
    aHold = mData[10]; mData[10] = mData[17]; mData[17] = aHold;
    aHold = mData[11]; mData[11] = mData[25]; mData[25] = aHold;
    aHold = mData[12]; mData[12] = mData[33]; mData[33] = aHold;
    aHold = mData[13]; mData[13] = mData[41]; mData[41] = aHold;
    aHold = mData[14]; mData[14] = mData[49]; mData[49] = aHold;
    aHold = mData[15]; mData[15] = mData[57]; mData[57] = aHold;
    aHold = mData[19]; mData[19] = mData[26]; mData[26] = aHold;
    aHold = mData[20]; mData[20] = mData[34]; mData[34] = aHold;
    aHold = mData[21]; mData[21] = mData[42]; mData[42] = aHold;
    aHold = mData[22]; mData[22] = mData[50]; mData[50] = aHold;
    aHold = mData[23]; mData[23] = mData[58]; mData[58] = aHold;
    aHold = mData[28]; mData[28] = mData[35]; mData[35] = aHold;
    aHold = mData[29]; mData[29] = mData[43]; mData[43] = aHold;
    aHold = mData[30]; mData[30] = mData[51]; mData[51] = aHold;
    aHold = mData[31]; mData[31] = mData[59]; mData[59] = aHold;
    aHold = mData[37]; mData[37] = mData[44]; mData[44] = aHold;
    aHold = mData[38]; mData[38] = mData[52]; mData[52] = aHold;
    aHold = mData[39]; mData[39] = mData[60]; mData[60] = aHold;
    aHold = mData[46]; mData[46] = mData[53]; mData[53] = aHold;
    aHold = mData[47]; mData[47] = mData[61]; mData[61] = aHold;
    aHold = mData[55]; mData[55] = mData[62]; mData[62] = aHold;
}


void M88::Full_FlipD_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[36]; mData[36] = aHold;
    aHold = mData[1]; mData[1] = mData[37]; mData[37] = aHold;
    aHold = mData[2]; mData[2] = mData[38]; mData[38] = aHold;
    aHold = mData[3]; mData[3] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[44]; mData[44] = aHold;
    aHold = mData[9]; mData[9] = mData[45]; mData[45] = aHold;
    aHold = mData[10]; mData[10] = mData[46]; mData[46] = aHold;
    aHold = mData[11]; mData[11] = mData[47]; mData[47] = aHold;
    aHold = mData[16]; mData[16] = mData[52]; mData[52] = aHold;
    aHold = mData[17]; mData[17] = mData[53]; mData[53] = aHold;
    aHold = mData[18]; mData[18] = mData[54]; mData[54] = aHold;
    aHold = mData[19]; mData[19] = mData[55]; mData[55] = aHold;
    aHold = mData[24]; mData[24] = mData[60]; mData[60] = aHold;
    aHold = mData[25]; mData[25] = mData[61]; mData[61] = aHold;
    aHold = mData[26]; mData[26] = mData[62]; mData[62] = aHold;
    aHold = mData[27]; mData[27] = mData[63]; mData[63] = aHold;
}

void M88::Full_FlipD_EachQuad_2x2() {
    Quad_FlipD_2x2_A();
    Quad_FlipD_2x2_B();
    Quad_FlipD_2x2_C();
    Quad_FlipD_2x2_D();
}

void M88::Full_FlipD_EachMini_2x2() {
    Mini_FlipD_2x2_A();
    Mini_FlipD_2x2_B();
    Mini_FlipD_2x2_C();
    Mini_FlipD_2x2_D();
    Mini_FlipD_2x2_E();
    Mini_FlipD_2x2_F();
    Mini_FlipD_2x2_G();
    Mini_FlipD_2x2_H();
    Mini_FlipD_2x2_I();
    Mini_FlipD_2x2_J();
    Mini_FlipD_2x2_K();
    Mini_FlipD_2x2_L();
    Mini_FlipD_2x2_M();
    Mini_FlipD_2x2_N();
    Mini_FlipD_2x2_O();
    Mini_FlipD_2x2_P();
}

void M88::Quad_FlipD_EachMini_2x2_A() {
    Mini_FlipD_2x2_A();
    Mini_FlipD_2x2_B();
    Mini_FlipD_2x2_E();
    Mini_FlipD_2x2_F();
}

void M88::Quad_FlipD_EachMini_2x2_B() {
    Mini_FlipD_2x2_C();
    Mini_FlipD_2x2_D();
    Mini_FlipD_2x2_G();
    Mini_FlipD_2x2_H();
}

void M88::Quad_FlipD_EachMini_2x2_C() {
    Mini_FlipD_2x2_I();
    Mini_FlipD_2x2_J();
    Mini_FlipD_2x2_M();
    Mini_FlipD_2x2_N();
}

void M88::Quad_FlipD_EachMini_2x2_D() {
    Mini_FlipD_2x2_K();
    Mini_FlipD_2x2_L();
    Mini_FlipD_2x2_O();
    Mini_FlipD_2x2_P();
}

void M88::Quad_FlipD_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[18]; mData[18] = aHold;
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = aHold;
    aHold = mData[8]; mData[8] = mData[26]; mData[26] = aHold;
    aHold = mData[9]; mData[9] = mData[27]; mData[27] = aHold;
}

void M88::Quad_FlipD_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[22]; mData[22] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[31]; mData[31] = aHold;
}

void M88::Quad_FlipD_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[50]; mData[50] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = aHold;
    aHold = mData[40]; mData[40] = mData[58]; mData[58] = aHold;
    aHold = mData[41]; mData[41] = mData[59]; mData[59] = aHold;
}

void M88::Quad_FlipD_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[54]; mData[54] = aHold;
    aHold = mData[37]; mData[37] = mData[55]; mData[55] = aHold;
    aHold = mData[44]; mData[44] = mData[62]; mData[62] = aHold;
    aHold = mData[45]; mData[45] = mData[63]; mData[63] = aHold;
}

void M88::Mini_FlipD_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = aHold;
}

void M88::Mini_FlipD_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = aHold;
}

void M88::Mini_FlipD_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = aHold;
}

void M88::Mini_FlipD_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = aHold;
}

void M88::Mini_FlipD_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = aHold;
}

void M88::Mini_FlipD_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = aHold;
}

void M88::Mini_FlipD_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = aHold;
}

void M88::Mini_FlipD_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = aHold;
}

void M88::Mini_FlipD_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = aHold;
}

void M88::Mini_FlipD_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = aHold;
}

void M88::Mini_FlipD_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = aHold;
}

void M88::Mini_FlipD_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = aHold;
}

void M88::Mini_FlipD_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = aHold;
}

void M88::Mini_FlipD_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = aHold;
}

void M88::Mini_FlipD_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = aHold;
}

void M88::Mini_FlipD_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = aHold;
}


void M88::Full_FlipD_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[54]; mData[54] = aHold;
    aHold = mData[1]; mData[1] = mData[55]; mData[55] = aHold;
    aHold = mData[2]; mData[2] = mData[38]; mData[38] = aHold;
    aHold = mData[3]; mData[3] = mData[39]; mData[39] = aHold;
    aHold = mData[4]; mData[4] = mData[22]; mData[22] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = aHold;
    aHold = mData[8]; mData[8] = mData[62]; mData[62] = aHold;
    aHold = mData[9]; mData[9] = mData[63]; mData[63] = aHold;
    aHold = mData[10]; mData[10] = mData[46]; mData[46] = aHold;
    aHold = mData[11]; mData[11] = mData[47]; mData[47] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[31]; mData[31] = aHold;
    aHold = mData[16]; mData[16] = mData[52]; mData[52] = aHold;
    aHold = mData[17]; mData[17] = mData[53]; mData[53] = aHold;
    aHold = mData[18]; mData[18] = mData[36]; mData[36] = aHold;
    aHold = mData[19]; mData[19] = mData[37]; mData[37] = aHold;
    aHold = mData[24]; mData[24] = mData[60]; mData[60] = aHold;
    aHold = mData[25]; mData[25] = mData[61]; mData[61] = aHold;
    aHold = mData[26]; mData[26] = mData[44]; mData[44] = aHold;
    aHold = mData[27]; mData[27] = mData[45]; mData[45] = aHold;
    aHold = mData[32]; mData[32] = mData[50]; mData[50] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = aHold;
    aHold = mData[40]; mData[40] = mData[58]; mData[58] = aHold;
    aHold = mData[41]; mData[41] = mData[59]; mData[59] = aHold;
}

void M88::Full_FlipD_EachQuad_4x4() {
    Quad_FlipD_4x4_A();
    Quad_FlipD_4x4_B();
    Quad_FlipD_4x4_C();
    Quad_FlipD_4x4_D();
}

void M88::Quad_FlipD_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[27]; mData[27] = aHold;
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = aHold;
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = aHold;
    aHold = mData[8]; mData[8] = mData[26]; mData[26] = aHold;
    aHold = mData[9]; mData[9] = mData[18]; mData[18] = aHold;
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = aHold;
}

void M88::Quad_FlipD_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[31]; mData[31] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = aHold;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[22]; mData[22] = aHold;
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = aHold;
}

void M88::Quad_FlipD_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[59]; mData[59] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = aHold;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = aHold;
    aHold = mData[40]; mData[40] = mData[58]; mData[58] = aHold;
    aHold = mData[41]; mData[41] = mData[50]; mData[50] = aHold;
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = aHold;
}

void M88::Quad_FlipD_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[63]; mData[63] = aHold;
    aHold = mData[37]; mData[37] = mData[55]; mData[55] = aHold;
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = aHold;
    aHold = mData[44]; mData[44] = mData[62]; mData[62] = aHold;
    aHold = mData[45]; mData[45] = mData[54]; mData[54] = aHold;
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = aHold;
}


void M88::Full_FlipD_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[63]; mData[63] = aHold;
    aHold = mData[1]; mData[1] = mData[55]; mData[55] = aHold;
    aHold = mData[2]; mData[2] = mData[47]; mData[47] = aHold;
    aHold = mData[3]; mData[3] = mData[39]; mData[39] = aHold;
    aHold = mData[4]; mData[4] = mData[31]; mData[31] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = aHold;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = aHold;
    aHold = mData[8]; mData[8] = mData[62]; mData[62] = aHold;
    aHold = mData[9]; mData[9] = mData[54]; mData[54] = aHold;
    aHold = mData[10]; mData[10] = mData[46]; mData[46] = aHold;
    aHold = mData[11]; mData[11] = mData[38]; mData[38] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[22]; mData[22] = aHold;
    aHold = mData[16]; mData[16] = mData[61]; mData[61] = aHold;
    aHold = mData[17]; mData[17] = mData[53]; mData[53] = aHold;
    aHold = mData[18]; mData[18] = mData[45]; mData[45] = aHold;
    aHold = mData[19]; mData[19] = mData[37]; mData[37] = aHold;
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = aHold;
    aHold = mData[24]; mData[24] = mData[60]; mData[60] = aHold;
    aHold = mData[25]; mData[25] = mData[52]; mData[52] = aHold;
    aHold = mData[26]; mData[26] = mData[44]; mData[44] = aHold;
    aHold = mData[27]; mData[27] = mData[36]; mData[36] = aHold;
    aHold = mData[32]; mData[32] = mData[59]; mData[59] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = aHold;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = aHold;
    aHold = mData[40]; mData[40] = mData[58]; mData[58] = aHold;
    aHold = mData[41]; mData[41] = mData[50]; mData[50] = aHold;
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = aHold;
}




void M88::Full_SnakeA_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = mData[32]; mData[32] = mData[36]; mData[36] = aHold;
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = mData[33]; mData[33] = mData[37]; mData[37] = aHold;
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = mData[34]; mData[34] = mData[38]; mData[38] = aHold;
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = mData[35]; mData[35] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = mData[40]; mData[40] = mData[44]; mData[44] = aHold;
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = mData[41]; mData[41] = mData[45]; mData[45] = aHold;
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = mData[42]; mData[42] = mData[46]; mData[46] = aHold;
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = mData[43]; mData[43] = mData[47]; mData[47] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = mData[48]; mData[48] = mData[52]; mData[52] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = mData[49]; mData[49] = mData[53]; mData[53] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = mData[50]; mData[50] = mData[54]; mData[54] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = mData[51]; mData[51] = mData[55]; mData[55] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = mData[56]; mData[56] = mData[60]; mData[60] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = mData[57]; mData[57] = mData[61]; mData[61] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = mData[58]; mData[58] = mData[62]; mData[62] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = mData[59]; mData[59] = mData[63]; mData[63] = aHold;
}

void M88::Full_SnakeA_EachQuad_2x2() {
    Quad_SnakeA_2x2_A();
    Quad_SnakeA_2x2_B();
    Quad_SnakeA_2x2_C();
    Quad_SnakeA_2x2_D();
}

void M88::Full_SnakeA_EachMini_2x2() {
    Mini_SnakeA_2x2_A();
    Mini_SnakeA_2x2_B();
    Mini_SnakeA_2x2_C();
    Mini_SnakeA_2x2_D();
    Mini_SnakeA_2x2_E();
    Mini_SnakeA_2x2_F();
    Mini_SnakeA_2x2_G();
    Mini_SnakeA_2x2_H();
    Mini_SnakeA_2x2_I();
    Mini_SnakeA_2x2_J();
    Mini_SnakeA_2x2_K();
    Mini_SnakeA_2x2_L();
    Mini_SnakeA_2x2_M();
    Mini_SnakeA_2x2_N();
    Mini_SnakeA_2x2_O();
    Mini_SnakeA_2x2_P();
}

void M88::Quad_SnakeA_EachMini_2x2_A() {
    Mini_SnakeA_2x2_A();
    Mini_SnakeA_2x2_B();
    Mini_SnakeA_2x2_E();
    Mini_SnakeA_2x2_F();
}

void M88::Quad_SnakeA_EachMini_2x2_B() {
    Mini_SnakeA_2x2_C();
    Mini_SnakeA_2x2_D();
    Mini_SnakeA_2x2_G();
    Mini_SnakeA_2x2_H();
}

void M88::Quad_SnakeA_EachMini_2x2_C() {
    Mini_SnakeA_2x2_I();
    Mini_SnakeA_2x2_J();
    Mini_SnakeA_2x2_M();
    Mini_SnakeA_2x2_N();
}

void M88::Quad_SnakeA_EachMini_2x2_D() {
    Mini_SnakeA_2x2_K();
    Mini_SnakeA_2x2_L();
    Mini_SnakeA_2x2_O();
    Mini_SnakeA_2x2_P();
}

void M88::Quad_SnakeA_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
}

void M88::Quad_SnakeA_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
}

void M88::Quad_SnakeA_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
}

void M88::Quad_SnakeA_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}

void M88::Mini_SnakeA_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = mData[8]; mData[8] = mData[9]; mData[9] = aHold;
}

void M88::Mini_SnakeA_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = mData[10]; mData[10] = mData[11]; mData[11] = aHold;
}

void M88::Mini_SnakeA_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = mData[12]; mData[12] = mData[13]; mData[13] = aHold;
}

void M88::Mini_SnakeA_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = mData[14]; mData[14] = mData[15]; mData[15] = aHold;
}

void M88::Mini_SnakeA_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = mData[24]; mData[24] = mData[25]; mData[25] = aHold;
}

void M88::Mini_SnakeA_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = mData[26]; mData[26] = mData[27]; mData[27] = aHold;
}

void M88::Mini_SnakeA_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = mData[28]; mData[28] = mData[29]; mData[29] = aHold;
}

void M88::Mini_SnakeA_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = mData[30]; mData[30] = mData[31]; mData[31] = aHold;
}

void M88::Mini_SnakeA_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = mData[40]; mData[40] = mData[41]; mData[41] = aHold;
}

void M88::Mini_SnakeA_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = mData[42]; mData[42] = mData[43]; mData[43] = aHold;
}

void M88::Mini_SnakeA_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = mData[44]; mData[44] = mData[45]; mData[45] = aHold;
}

void M88::Mini_SnakeA_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = mData[46]; mData[46] = mData[47]; mData[47] = aHold;
}

void M88::Mini_SnakeA_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = mData[56]; mData[56] = mData[57]; mData[57] = aHold;
}

void M88::Mini_SnakeA_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = mData[58]; mData[58] = mData[59]; mData[59] = aHold;
}

void M88::Mini_SnakeA_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = mData[60]; mData[60] = mData[61]; mData[61] = aHold;
}

void M88::Mini_SnakeA_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = mData[62]; mData[62] = mData[63]; mData[63] = aHold;
}






void M88::Full_SnakeB_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[36]; mData[36] = mData[32]; mData[32] = mData[4]; mData[4] = aHold;
    aHold = mData[1]; mData[1] = mData[37]; mData[37] = mData[33]; mData[33] = mData[5]; mData[5] = aHold;
    aHold = mData[2]; mData[2] = mData[38]; mData[38] = mData[34]; mData[34] = mData[6]; mData[6] = aHold;
    aHold = mData[3]; mData[3] = mData[39]; mData[39] = mData[35]; mData[35] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[44]; mData[44] = mData[40]; mData[40] = mData[12]; mData[12] = aHold;
    aHold = mData[9]; mData[9] = mData[45]; mData[45] = mData[41]; mData[41] = mData[13]; mData[13] = aHold;
    aHold = mData[10]; mData[10] = mData[46]; mData[46] = mData[42]; mData[42] = mData[14]; mData[14] = aHold;
    aHold = mData[11]; mData[11] = mData[47]; mData[47] = mData[43]; mData[43] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[52]; mData[52] = mData[48]; mData[48] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[53]; mData[53] = mData[49]; mData[49] = mData[21]; mData[21] = aHold;
    aHold = mData[18]; mData[18] = mData[54]; mData[54] = mData[50]; mData[50] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[55]; mData[55] = mData[51]; mData[51] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[60]; mData[60] = mData[56]; mData[56] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[61]; mData[61] = mData[57]; mData[57] = mData[29]; mData[29] = aHold;
    aHold = mData[26]; mData[26] = mData[62]; mData[62] = mData[58]; mData[58] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[63]; mData[63] = mData[59]; mData[59] = mData[31]; mData[31] = aHold;
}

void M88::Full_SnakeB_EachQuad_2x2() {
    Quad_SnakeB_2x2_A();
    Quad_SnakeB_2x2_B();
    Quad_SnakeB_2x2_C();
    Quad_SnakeB_2x2_D();
}

void M88::Full_SnakeB_EachMini_2x2() {
    Mini_SnakeB_2x2_A();
    Mini_SnakeB_2x2_B();
    Mini_SnakeB_2x2_C();
    Mini_SnakeB_2x2_D();
    Mini_SnakeB_2x2_E();
    Mini_SnakeB_2x2_F();
    Mini_SnakeB_2x2_G();
    Mini_SnakeB_2x2_H();
    Mini_SnakeB_2x2_I();
    Mini_SnakeB_2x2_J();
    Mini_SnakeB_2x2_K();
    Mini_SnakeB_2x2_L();
    Mini_SnakeB_2x2_M();
    Mini_SnakeB_2x2_N();
    Mini_SnakeB_2x2_O();
    Mini_SnakeB_2x2_P();
}

void M88::Quad_SnakeB_EachMini_2x2_A() {
    Mini_SnakeB_2x2_A();
    Mini_SnakeB_2x2_B();
    Mini_SnakeB_2x2_E();
    Mini_SnakeB_2x2_F();
}

void M88::Quad_SnakeB_EachMini_2x2_B() {
    Mini_SnakeB_2x2_C();
    Mini_SnakeB_2x2_D();
    Mini_SnakeB_2x2_G();
    Mini_SnakeB_2x2_H();
}

void M88::Quad_SnakeB_EachMini_2x2_C() {
    Mini_SnakeB_2x2_I();
    Mini_SnakeB_2x2_J();
    Mini_SnakeB_2x2_M();
    Mini_SnakeB_2x2_N();
}

void M88::Quad_SnakeB_EachMini_2x2_D() {
    Mini_SnakeB_2x2_K();
    Mini_SnakeB_2x2_L();
    Mini_SnakeB_2x2_O();
    Mini_SnakeB_2x2_P();
}

void M88::Quad_SnakeB_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[18]; mData[18] = mData[16]; mData[16] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = mData[17]; mData[17] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[26]; mData[26] = mData[24]; mData[24] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[27]; mData[27] = mData[25]; mData[25] = mData[11]; mData[11] = aHold;
}

void M88::Quad_SnakeB_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[22]; mData[22] = mData[20]; mData[20] = mData[6]; mData[6] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = mData[21]; mData[21] = mData[7]; mData[7] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = mData[28]; mData[28] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[31]; mData[31] = mData[29]; mData[29] = mData[15]; mData[15] = aHold;
}

void M88::Quad_SnakeB_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[50]; mData[50] = mData[48]; mData[48] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = mData[49]; mData[49] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[58]; mData[58] = mData[56]; mData[56] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[59]; mData[59] = mData[57]; mData[57] = mData[43]; mData[43] = aHold;
}

void M88::Quad_SnakeB_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[54]; mData[54] = mData[52]; mData[52] = mData[38]; mData[38] = aHold;
    aHold = mData[37]; mData[37] = mData[55]; mData[55] = mData[53]; mData[53] = mData[39]; mData[39] = aHold;
    aHold = mData[44]; mData[44] = mData[62]; mData[62] = mData[60]; mData[60] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[63]; mData[63] = mData[61]; mData[61] = mData[47]; mData[47] = aHold;
}

void M88::Mini_SnakeB_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = mData[8]; mData[8] = mData[1]; mData[1] = aHold;
}

void M88::Mini_SnakeB_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = mData[10]; mData[10] = mData[3]; mData[3] = aHold;
}

void M88::Mini_SnakeB_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = mData[12]; mData[12] = mData[5]; mData[5] = aHold;
}

void M88::Mini_SnakeB_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = mData[14]; mData[14] = mData[7]; mData[7] = aHold;
}

void M88::Mini_SnakeB_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = mData[24]; mData[24] = mData[17]; mData[17] = aHold;
}

void M88::Mini_SnakeB_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = mData[26]; mData[26] = mData[19]; mData[19] = aHold;
}

void M88::Mini_SnakeB_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = mData[28]; mData[28] = mData[21]; mData[21] = aHold;
}

void M88::Mini_SnakeB_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = mData[30]; mData[30] = mData[23]; mData[23] = aHold;
}

void M88::Mini_SnakeB_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = mData[40]; mData[40] = mData[33]; mData[33] = aHold;
}

void M88::Mini_SnakeB_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = mData[42]; mData[42] = mData[35]; mData[35] = aHold;
}

void M88::Mini_SnakeB_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = mData[44]; mData[44] = mData[37]; mData[37] = aHold;
}

void M88::Mini_SnakeB_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = mData[46]; mData[46] = mData[39]; mData[39] = aHold;
}

void M88::Mini_SnakeB_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = mData[56]; mData[56] = mData[49]; mData[49] = aHold;
}

void M88::Mini_SnakeB_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = mData[58]; mData[58] = mData[51]; mData[51] = aHold;
}

void M88::Mini_SnakeB_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = mData[60]; mData[60] = mData[53]; mData[53] = aHold;
}

void M88::Mini_SnakeB_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = mData[62]; mData[62] = mData[55]; mData[55] = aHold;
}





void M88::Full_SnakeC_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = mData[4]; mData[4] = mData[36]; mData[36] = aHold;
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = mData[5]; mData[5] = mData[37]; mData[37] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = mData[6]; mData[6] = mData[38]; mData[38] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = mData[7]; mData[7] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = mData[12]; mData[12] = mData[44]; mData[44] = aHold;
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = mData[13]; mData[13] = mData[45]; mData[45] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = mData[14]; mData[14] = mData[46]; mData[46] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = mData[15]; mData[15] = mData[47]; mData[47] = aHold;
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = mData[20]; mData[20] = mData[52]; mData[52] = aHold;
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = mData[21]; mData[21] = mData[53]; mData[53] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = mData[22]; mData[22] = mData[54]; mData[54] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = mData[23]; mData[23] = mData[55]; mData[55] = aHold;
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = mData[28]; mData[28] = mData[60]; mData[60] = aHold;
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = mData[29]; mData[29] = mData[61]; mData[61] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = mData[30]; mData[30] = mData[62]; mData[62] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = mData[31]; mData[31] = mData[63]; mData[63] = aHold;
}

void M88::Full_SnakeC_EachQuad_2x2() {
    Quad_SnakeC_2x2_A();
    Quad_SnakeC_2x2_B();
    Quad_SnakeC_2x2_C();
    Quad_SnakeC_2x2_D();
}

void M88::Full_SnakeC_EachMini_2x2() {
    Mini_SnakeC_2x2_A();
    Mini_SnakeC_2x2_B();
    Mini_SnakeC_2x2_C();
    Mini_SnakeC_2x2_D();
    Mini_SnakeC_2x2_E();
    Mini_SnakeC_2x2_F();
    Mini_SnakeC_2x2_G();
    Mini_SnakeC_2x2_H();
    Mini_SnakeC_2x2_I();
    Mini_SnakeC_2x2_J();
    Mini_SnakeC_2x2_K();
    Mini_SnakeC_2x2_L();
    Mini_SnakeC_2x2_M();
    Mini_SnakeC_2x2_N();
    Mini_SnakeC_2x2_O();
    Mini_SnakeC_2x2_P();
}

void M88::Quad_SnakeC_EachMini_2x2_A() {
    Mini_SnakeC_2x2_A();
    Mini_SnakeC_2x2_B();
    Mini_SnakeC_2x2_E();
    Mini_SnakeC_2x2_F();
}

void M88::Quad_SnakeC_EachMini_2x2_B() {
    Mini_SnakeC_2x2_C();
    Mini_SnakeC_2x2_D();
    Mini_SnakeC_2x2_G();
    Mini_SnakeC_2x2_H();
}

void M88::Quad_SnakeC_EachMini_2x2_C() {
    Mini_SnakeC_2x2_I();
    Mini_SnakeC_2x2_J();
    Mini_SnakeC_2x2_M();
    Mini_SnakeC_2x2_N();
}

void M88::Quad_SnakeC_EachMini_2x2_D() {
    Mini_SnakeC_2x2_K();
    Mini_SnakeC_2x2_L();
    Mini_SnakeC_2x2_O();
    Mini_SnakeC_2x2_P();
}

void M88::Quad_SnakeC_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = mData[3]; mData[3] = mData[19]; mData[19] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = mData[11]; mData[11] = mData[27]; mData[27] = aHold;
}

void M88::Quad_SnakeC_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = mData[6]; mData[6] = mData[22]; mData[22] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = mData[7]; mData[7] = mData[23]; mData[23] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = mData[14]; mData[14] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = mData[15]; mData[15] = mData[31]; mData[31] = aHold;
}

void M88::Quad_SnakeC_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
}

void M88::Quad_SnakeC_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
}

void M88::Mini_SnakeC_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = mData[1]; mData[1] = mData[9]; mData[9] = aHold;
}

void M88::Mini_SnakeC_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = mData[3]; mData[3] = mData[11]; mData[11] = aHold;
}

void M88::Mini_SnakeC_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = mData[5]; mData[5] = mData[13]; mData[13] = aHold;
}

void M88::Mini_SnakeC_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = mData[7]; mData[7] = mData[15]; mData[15] = aHold;
}

void M88::Mini_SnakeC_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = mData[17]; mData[17] = mData[25]; mData[25] = aHold;
}

void M88::Mini_SnakeC_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = mData[19]; mData[19] = mData[27]; mData[27] = aHold;
}

void M88::Mini_SnakeC_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = mData[21]; mData[21] = mData[29]; mData[29] = aHold;
}

void M88::Mini_SnakeC_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = mData[23]; mData[23] = mData[31]; mData[31] = aHold;
}

void M88::Mini_SnakeC_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = mData[33]; mData[33] = mData[41]; mData[41] = aHold;
}

void M88::Mini_SnakeC_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = mData[35]; mData[35] = mData[43]; mData[43] = aHold;
}

void M88::Mini_SnakeC_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = mData[37]; mData[37] = mData[45]; mData[45] = aHold;
}

void M88::Mini_SnakeC_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = mData[39]; mData[39] = mData[47]; mData[47] = aHold;
}

void M88::Mini_SnakeC_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = mData[49]; mData[49] = mData[57]; mData[57] = aHold;
}

void M88::Mini_SnakeC_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = mData[51]; mData[51] = mData[59]; mData[59] = aHold;
}

void M88::Mini_SnakeC_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = mData[53]; mData[53] = mData[61]; mData[61] = aHold;
}

void M88::Mini_SnakeC_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = mData[55]; mData[55] = mData[63]; mData[63] = aHold;
}





void M88::Full_SnakeD_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[36]; mData[36] = mData[4]; mData[4] = mData[32]; mData[32] = aHold;
    aHold = mData[1]; mData[1] = mData[37]; mData[37] = mData[5]; mData[5] = mData[33]; mData[33] = aHold;
    aHold = mData[2]; mData[2] = mData[38]; mData[38] = mData[6]; mData[6] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[39]; mData[39] = mData[7]; mData[7] = mData[35]; mData[35] = aHold;
    aHold = mData[8]; mData[8] = mData[44]; mData[44] = mData[12]; mData[12] = mData[40]; mData[40] = aHold;
    aHold = mData[9]; mData[9] = mData[45]; mData[45] = mData[13]; mData[13] = mData[41]; mData[41] = aHold;
    aHold = mData[10]; mData[10] = mData[46]; mData[46] = mData[14]; mData[14] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[47]; mData[47] = mData[15]; mData[15] = mData[43]; mData[43] = aHold;
    aHold = mData[16]; mData[16] = mData[52]; mData[52] = mData[20]; mData[20] = mData[48]; mData[48] = aHold;
    aHold = mData[17]; mData[17] = mData[53]; mData[53] = mData[21]; mData[21] = mData[49]; mData[49] = aHold;
    aHold = mData[18]; mData[18] = mData[54]; mData[54] = mData[22]; mData[22] = mData[50]; mData[50] = aHold;
    aHold = mData[19]; mData[19] = mData[55]; mData[55] = mData[23]; mData[23] = mData[51]; mData[51] = aHold;
    aHold = mData[24]; mData[24] = mData[60]; mData[60] = mData[28]; mData[28] = mData[56]; mData[56] = aHold;
    aHold = mData[25]; mData[25] = mData[61]; mData[61] = mData[29]; mData[29] = mData[57]; mData[57] = aHold;
    aHold = mData[26]; mData[26] = mData[62]; mData[62] = mData[30]; mData[30] = mData[58]; mData[58] = aHold;
    aHold = mData[27]; mData[27] = mData[63]; mData[63] = mData[31]; mData[31] = mData[59]; mData[59] = aHold;
}

void M88::Full_SnakeD_EachQuad_2x2() {
    Quad_SnakeD_2x2_A();
    Quad_SnakeD_2x2_B();
    Quad_SnakeD_2x2_C();
    Quad_SnakeD_2x2_D();
}

void M88::Full_SnakeD_EachMini_2x2() {
    Mini_SnakeD_2x2_A();
    Mini_SnakeD_2x2_B();
    Mini_SnakeD_2x2_C();
    Mini_SnakeD_2x2_D();
    Mini_SnakeD_2x2_E();
    Mini_SnakeD_2x2_F();
    Mini_SnakeD_2x2_G();
    Mini_SnakeD_2x2_H();
    Mini_SnakeD_2x2_I();
    Mini_SnakeD_2x2_J();
    Mini_SnakeD_2x2_K();
    Mini_SnakeD_2x2_L();
    Mini_SnakeD_2x2_M();
    Mini_SnakeD_2x2_N();
    Mini_SnakeD_2x2_O();
    Mini_SnakeD_2x2_P();
}

void M88::Quad_SnakeD_EachMini_2x2_A() {
    Mini_SnakeD_2x2_A();
    Mini_SnakeD_2x2_B();
    Mini_SnakeD_2x2_E();
    Mini_SnakeD_2x2_F();
}

void M88::Quad_SnakeD_EachMini_2x2_B() {
    Mini_SnakeD_2x2_C();
    Mini_SnakeD_2x2_D();
    Mini_SnakeD_2x2_G();
    Mini_SnakeD_2x2_H();
}

void M88::Quad_SnakeD_EachMini_2x2_C() {
    Mini_SnakeD_2x2_I();
    Mini_SnakeD_2x2_J();
    Mini_SnakeD_2x2_M();
    Mini_SnakeD_2x2_N();
}

void M88::Quad_SnakeD_EachMini_2x2_D() {
    Mini_SnakeD_2x2_K();
    Mini_SnakeD_2x2_L();
    Mini_SnakeD_2x2_O();
    Mini_SnakeD_2x2_P();
}

void M88::Quad_SnakeD_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[18]; mData[18] = mData[2]; mData[2] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = mData[3]; mData[3] = mData[17]; mData[17] = aHold;
    aHold = mData[8]; mData[8] = mData[26]; mData[26] = mData[10]; mData[10] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[27]; mData[27] = mData[11]; mData[11] = mData[25]; mData[25] = aHold;
}

void M88::Quad_SnakeD_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[22]; mData[22] = mData[6]; mData[6] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = mData[7]; mData[7] = mData[21]; mData[21] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = mData[14]; mData[14] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[31]; mData[31] = mData[15]; mData[15] = mData[29]; mData[29] = aHold;
}

void M88::Quad_SnakeD_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[50]; mData[50] = mData[34]; mData[34] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = mData[35]; mData[35] = mData[49]; mData[49] = aHold;
    aHold = mData[40]; mData[40] = mData[58]; mData[58] = mData[42]; mData[42] = mData[56]; mData[56] = aHold;
    aHold = mData[41]; mData[41] = mData[59]; mData[59] = mData[43]; mData[43] = mData[57]; mData[57] = aHold;
}

void M88::Quad_SnakeD_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[54]; mData[54] = mData[38]; mData[38] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[55]; mData[55] = mData[39]; mData[39] = mData[53]; mData[53] = aHold;
    aHold = mData[44]; mData[44] = mData[62]; mData[62] = mData[46]; mData[46] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[63]; mData[63] = mData[47]; mData[47] = mData[61]; mData[61] = aHold;
}

void M88::Mini_SnakeD_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = mData[1]; mData[1] = mData[8]; mData[8] = aHold;
}

void M88::Mini_SnakeD_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = mData[3]; mData[3] = mData[10]; mData[10] = aHold;
}

void M88::Mini_SnakeD_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = mData[5]; mData[5] = mData[12]; mData[12] = aHold;
}

void M88::Mini_SnakeD_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = mData[7]; mData[7] = mData[14]; mData[14] = aHold;
}

void M88::Mini_SnakeD_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = mData[17]; mData[17] = mData[24]; mData[24] = aHold;
}

void M88::Mini_SnakeD_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = mData[19]; mData[19] = mData[26]; mData[26] = aHold;
}

void M88::Mini_SnakeD_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = mData[21]; mData[21] = mData[28]; mData[28] = aHold;
}

void M88::Mini_SnakeD_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = mData[23]; mData[23] = mData[30]; mData[30] = aHold;
}

void M88::Mini_SnakeD_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = mData[33]; mData[33] = mData[40]; mData[40] = aHold;
}

void M88::Mini_SnakeD_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = mData[35]; mData[35] = mData[42]; mData[42] = aHold;
}

void M88::Mini_SnakeD_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = mData[37]; mData[37] = mData[44]; mData[44] = aHold;
}

void M88::Mini_SnakeD_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = mData[39]; mData[39] = mData[46]; mData[46] = aHold;
}

void M88::Mini_SnakeD_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = mData[49]; mData[49] = mData[56]; mData[56] = aHold;
}

void M88::Mini_SnakeD_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = mData[51]; mData[51] = mData[58]; mData[58] = aHold;
}

void M88::Mini_SnakeD_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = mData[53]; mData[53] = mData[60]; mData[60] = aHold;
}

void M88::Mini_SnakeD_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = mData[55]; mData[55] = mData[62]; mData[62] = aHold;
}



void M88::Full_TriadA_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = mData[32]; mData[32] = aHold;
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = mData[33]; mData[33] = aHold;
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = mData[35]; mData[35] = aHold;
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = mData[40]; mData[40] = aHold;
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = mData[41]; mData[41] = aHold;
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = mData[43]; mData[43] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = mData[48]; mData[48] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = mData[49]; mData[49] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = mData[50]; mData[50] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = mData[51]; mData[51] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = mData[56]; mData[56] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = mData[57]; mData[57] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = mData[58]; mData[58] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = mData[59]; mData[59] = aHold;
}

void M88::Full_TriadA_EachQuad_2x2() {
    Quad_TriadA_2x2_A();
    Quad_TriadA_2x2_B();
    Quad_TriadA_2x2_C();
    Quad_TriadA_2x2_D();
}

void M88::Full_TriadA_EachMini_2x2() {
    Mini_TriadA_2x2_A();
    Mini_TriadA_2x2_B();
    Mini_TriadA_2x2_C();
    Mini_TriadA_2x2_D();
    Mini_TriadA_2x2_E();
    Mini_TriadA_2x2_F();
    Mini_TriadA_2x2_G();
    Mini_TriadA_2x2_H();
    Mini_TriadA_2x2_I();
    Mini_TriadA_2x2_J();
    Mini_TriadA_2x2_K();
    Mini_TriadA_2x2_L();
    Mini_TriadA_2x2_M();
    Mini_TriadA_2x2_N();
    Mini_TriadA_2x2_O();
    Mini_TriadA_2x2_P();
}

void M88::Quad_TriadA_EachMini_2x2_A() {
    Mini_TriadA_2x2_A();
    Mini_TriadA_2x2_B();
    Mini_TriadA_2x2_E();
    Mini_TriadA_2x2_F();
}

void M88::Quad_TriadA_EachMini_2x2_B() {
    Mini_TriadA_2x2_C();
    Mini_TriadA_2x2_D();
    Mini_TriadA_2x2_G();
    Mini_TriadA_2x2_H();
}

void M88::Quad_TriadA_EachMini_2x2_C() {
    Mini_TriadA_2x2_I();
    Mini_TriadA_2x2_J();
    Mini_TriadA_2x2_M();
    Mini_TriadA_2x2_N();
}

void M88::Quad_TriadA_EachMini_2x2_D() {
    Mini_TriadA_2x2_K();
    Mini_TriadA_2x2_L();
    Mini_TriadA_2x2_O();
    Mini_TriadA_2x2_P();
}

void M88::Quad_TriadA_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = mData[17]; mData[17] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = mData[25]; mData[25] = aHold;
}

void M88::Quad_TriadA_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = mData[21]; mData[21] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = mData[29]; mData[29] = aHold;
}

void M88::Quad_TriadA_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = mData[49]; mData[49] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = mData[56]; mData[56] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = mData[57]; mData[57] = aHold;
}

void M88::Quad_TriadA_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = mData[53]; mData[53] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = mData[61]; mData[61] = aHold;
}

void M88::Mini_TriadA_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = mData[8]; mData[8] = aHold;
}

void M88::Mini_TriadA_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = mData[10]; mData[10] = aHold;
}

void M88::Mini_TriadA_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = mData[12]; mData[12] = aHold;
}

void M88::Mini_TriadA_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = mData[14]; mData[14] = aHold;
}

void M88::Mini_TriadA_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = mData[24]; mData[24] = aHold;
}

void M88::Mini_TriadA_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = mData[26]; mData[26] = aHold;
}

void M88::Mini_TriadA_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = mData[28]; mData[28] = aHold;
}

void M88::Mini_TriadA_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = mData[30]; mData[30] = aHold;
}

void M88::Mini_TriadA_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = mData[40]; mData[40] = aHold;
}

void M88::Mini_TriadA_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = mData[42]; mData[42] = aHold;
}

void M88::Mini_TriadA_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = mData[44]; mData[44] = aHold;
}

void M88::Mini_TriadA_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = mData[46]; mData[46] = aHold;
}

void M88::Mini_TriadA_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = mData[56]; mData[56] = aHold;
}

void M88::Mini_TriadA_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = mData[58]; mData[58] = aHold;
}

void M88::Mini_TriadA_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = mData[60]; mData[60] = aHold;
}

void M88::Mini_TriadA_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = mData[62]; mData[62] = aHold;
}



void M88::Full_TriadB_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = mData[4]; mData[4] = aHold;
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = mData[5]; mData[5] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = mData[6]; mData[6] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = mData[12]; mData[12] = aHold;
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = mData[13]; mData[13] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = mData[14]; mData[14] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = mData[21]; mData[21] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = mData[29]; mData[29] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = mData[31]; mData[31] = aHold;
}

void M88::Full_TriadB_EachQuad_2x2() {
    Quad_TriadB_2x2_A();
    Quad_TriadB_2x2_B();
    Quad_TriadB_2x2_C();
    Quad_TriadB_2x2_D();
}

void M88::Full_TriadB_EachMini_2x2() {
    Mini_TriadB_2x2_A();
    Mini_TriadB_2x2_B();
    Mini_TriadB_2x2_C();
    Mini_TriadB_2x2_D();
    Mini_TriadB_2x2_E();
    Mini_TriadB_2x2_F();
    Mini_TriadB_2x2_G();
    Mini_TriadB_2x2_H();
    Mini_TriadB_2x2_I();
    Mini_TriadB_2x2_J();
    Mini_TriadB_2x2_K();
    Mini_TriadB_2x2_L();
    Mini_TriadB_2x2_M();
    Mini_TriadB_2x2_N();
    Mini_TriadB_2x2_O();
    Mini_TriadB_2x2_P();
}

void M88::Quad_TriadB_EachMini_2x2_A() {
    Mini_TriadB_2x2_A();
    Mini_TriadB_2x2_B();
    Mini_TriadB_2x2_E();
    Mini_TriadB_2x2_F();
}

void M88::Quad_TriadB_EachMini_2x2_B() {
    Mini_TriadB_2x2_C();
    Mini_TriadB_2x2_D();
    Mini_TriadB_2x2_G();
    Mini_TriadB_2x2_H();
}

void M88::Quad_TriadB_EachMini_2x2_C() {
    Mini_TriadB_2x2_I();
    Mini_TriadB_2x2_J();
    Mini_TriadB_2x2_M();
    Mini_TriadB_2x2_N();
}

void M88::Quad_TriadB_EachMini_2x2_D() {
    Mini_TriadB_2x2_K();
    Mini_TriadB_2x2_L();
    Mini_TriadB_2x2_O();
    Mini_TriadB_2x2_P();
}

void M88::Quad_TriadB_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = mData[11]; mData[11] = aHold;
}

void M88::Quad_TriadB_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = mData[6]; mData[6] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = mData[7]; mData[7] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = mData[15]; mData[15] = aHold;
}

void M88::Quad_TriadB_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = mData[43]; mData[43] = aHold;
}

void M88::Quad_TriadB_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = mData[38]; mData[38] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = mData[39]; mData[39] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = mData[47]; mData[47] = aHold;
}

void M88::Mini_TriadB_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = mData[1]; mData[1] = aHold;
}

void M88::Mini_TriadB_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = mData[3]; mData[3] = aHold;
}

void M88::Mini_TriadB_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = mData[5]; mData[5] = aHold;
}

void M88::Mini_TriadB_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = mData[7]; mData[7] = aHold;
}

void M88::Mini_TriadB_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = mData[17]; mData[17] = aHold;
}

void M88::Mini_TriadB_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = mData[19]; mData[19] = aHold;
}

void M88::Mini_TriadB_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = mData[21]; mData[21] = aHold;
}

void M88::Mini_TriadB_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = mData[23]; mData[23] = aHold;
}

void M88::Mini_TriadB_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = mData[33]; mData[33] = aHold;
}

void M88::Mini_TriadB_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = mData[35]; mData[35] = aHold;
}

void M88::Mini_TriadB_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = mData[37]; mData[37] = aHold;
}

void M88::Mini_TriadB_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = mData[39]; mData[39] = aHold;
}

void M88::Mini_TriadB_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = mData[49]; mData[49] = aHold;
}

void M88::Mini_TriadB_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = mData[51]; mData[51] = aHold;
}

void M88::Mini_TriadB_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = mData[53]; mData[53] = aHold;
}

void M88::Mini_TriadB_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = mData[55]; mData[55] = aHold;
}



void M88::Full_TriadC_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = mData[36]; mData[36] = aHold;
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = mData[37]; mData[37] = aHold;
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = mData[38]; mData[38] = aHold;
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = mData[44]; mData[44] = aHold;
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = mData[45]; mData[45] = aHold;
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = mData[46]; mData[46] = aHold;
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = mData[47]; mData[47] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = mData[52]; mData[52] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = mData[53]; mData[53] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = mData[54]; mData[54] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = mData[55]; mData[55] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = mData[60]; mData[60] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = mData[61]; mData[61] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = mData[62]; mData[62] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = mData[63]; mData[63] = aHold;
}

void M88::Full_TriadC_EachQuad_2x2() {
    Quad_TriadC_2x2_A();
    Quad_TriadC_2x2_B();
    Quad_TriadC_2x2_C();
    Quad_TriadC_2x2_D();
}

void M88::Full_TriadC_EachMini_2x2() {
    Mini_TriadC_2x2_A();
    Mini_TriadC_2x2_B();
    Mini_TriadC_2x2_C();
    Mini_TriadC_2x2_D();
    Mini_TriadC_2x2_E();
    Mini_TriadC_2x2_F();
    Mini_TriadC_2x2_G();
    Mini_TriadC_2x2_H();
    Mini_TriadC_2x2_I();
    Mini_TriadC_2x2_J();
    Mini_TriadC_2x2_K();
    Mini_TriadC_2x2_L();
    Mini_TriadC_2x2_M();
    Mini_TriadC_2x2_N();
    Mini_TriadC_2x2_O();
    Mini_TriadC_2x2_P();
}

void M88::Quad_TriadC_EachMini_2x2_A() {
    Mini_TriadC_2x2_A();
    Mini_TriadC_2x2_B();
    Mini_TriadC_2x2_E();
    Mini_TriadC_2x2_F();
}

void M88::Quad_TriadC_EachMini_2x2_B() {
    Mini_TriadC_2x2_C();
    Mini_TriadC_2x2_D();
    Mini_TriadC_2x2_G();
    Mini_TriadC_2x2_H();
}

void M88::Quad_TriadC_EachMini_2x2_C() {
    Mini_TriadC_2x2_I();
    Mini_TriadC_2x2_J();
    Mini_TriadC_2x2_M();
    Mini_TriadC_2x2_N();
}

void M88::Quad_TriadC_EachMini_2x2_D() {
    Mini_TriadC_2x2_K();
    Mini_TriadC_2x2_L();
    Mini_TriadC_2x2_O();
    Mini_TriadC_2x2_P();
}

void M88::Quad_TriadC_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = mData[19]; mData[19] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = mData[27]; mData[27] = aHold;
}

void M88::Quad_TriadC_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = mData[22]; mData[22] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = mData[23]; mData[23] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = mData[31]; mData[31] = aHold;
}

void M88::Quad_TriadC_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
}

void M88::Quad_TriadC_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
}

void M88::Mini_TriadC_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = mData[9]; mData[9] = aHold;
}

void M88::Mini_TriadC_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = mData[11]; mData[11] = aHold;
}

void M88::Mini_TriadC_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = mData[13]; mData[13] = aHold;
}

void M88::Mini_TriadC_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = mData[15]; mData[15] = aHold;
}

void M88::Mini_TriadC_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = mData[25]; mData[25] = aHold;
}

void M88::Mini_TriadC_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = mData[27]; mData[27] = aHold;
}

void M88::Mini_TriadC_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = mData[29]; mData[29] = aHold;
}

void M88::Mini_TriadC_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = mData[31]; mData[31] = aHold;
}

void M88::Mini_TriadC_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = mData[41]; mData[41] = aHold;
}

void M88::Mini_TriadC_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = mData[43]; mData[43] = aHold;
}

void M88::Mini_TriadC_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = mData[45]; mData[45] = aHold;
}

void M88::Mini_TriadC_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = mData[47]; mData[47] = aHold;
}

void M88::Mini_TriadC_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = mData[57]; mData[57] = aHold;
}

void M88::Mini_TriadC_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = mData[59]; mData[59] = aHold;
}

void M88::Mini_TriadC_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = mData[61]; mData[61] = aHold;
}

void M88::Mini_TriadC_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = mData[63]; mData[63] = aHold;
}




void M88::Full_TriadD_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[36]; mData[36] = mData[4]; mData[4] = aHold;
    aHold = mData[1]; mData[1] = mData[37]; mData[37] = mData[5]; mData[5] = aHold;
    aHold = mData[2]; mData[2] = mData[38]; mData[38] = mData[6]; mData[6] = aHold;
    aHold = mData[3]; mData[3] = mData[39]; mData[39] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[44]; mData[44] = mData[12]; mData[12] = aHold;
    aHold = mData[9]; mData[9] = mData[45]; mData[45] = mData[13]; mData[13] = aHold;
    aHold = mData[10]; mData[10] = mData[46]; mData[46] = mData[14]; mData[14] = aHold;
    aHold = mData[11]; mData[11] = mData[47]; mData[47] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[52]; mData[52] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[53]; mData[53] = mData[21]; mData[21] = aHold;
    aHold = mData[18]; mData[18] = mData[54]; mData[54] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[55]; mData[55] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[60]; mData[60] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[61]; mData[61] = mData[29]; mData[29] = aHold;
    aHold = mData[26]; mData[26] = mData[62]; mData[62] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[63]; mData[63] = mData[31]; mData[31] = aHold;
}

void M88::Full_TriadD_EachQuad_2x2() {
    Quad_TriadD_2x2_A();
    Quad_TriadD_2x2_B();
    Quad_TriadD_2x2_C();
    Quad_TriadD_2x2_D();
}

void M88::Full_TriadD_EachMini_2x2() {
    Mini_TriadD_2x2_A();
    Mini_TriadD_2x2_B();
    Mini_TriadD_2x2_C();
    Mini_TriadD_2x2_D();
    Mini_TriadD_2x2_E();
    Mini_TriadD_2x2_F();
    Mini_TriadD_2x2_G();
    Mini_TriadD_2x2_H();
    Mini_TriadD_2x2_I();
    Mini_TriadD_2x2_J();
    Mini_TriadD_2x2_K();
    Mini_TriadD_2x2_L();
    Mini_TriadD_2x2_M();
    Mini_TriadD_2x2_N();
    Mini_TriadD_2x2_O();
    Mini_TriadD_2x2_P();
}

void M88::Quad_TriadD_EachMini_2x2_A() {
    Mini_TriadD_2x2_A();
    Mini_TriadD_2x2_B();
    Mini_TriadD_2x2_E();
    Mini_TriadD_2x2_F();
}

void M88::Quad_TriadD_EachMini_2x2_B() {
    Mini_TriadD_2x2_C();
    Mini_TriadD_2x2_D();
    Mini_TriadD_2x2_G();
    Mini_TriadD_2x2_H();
}

void M88::Quad_TriadD_EachMini_2x2_C() {
    Mini_TriadD_2x2_I();
    Mini_TriadD_2x2_J();
    Mini_TriadD_2x2_M();
    Mini_TriadD_2x2_N();
}

void M88::Quad_TriadD_EachMini_2x2_D() {
    Mini_TriadD_2x2_K();
    Mini_TriadD_2x2_L();
    Mini_TriadD_2x2_O();
    Mini_TriadD_2x2_P();
}

void M88::Quad_TriadD_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[18]; mData[18] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[26]; mData[26] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[27]; mData[27] = mData[11]; mData[11] = aHold;
}

void M88::Quad_TriadD_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[22]; mData[22] = mData[6]; mData[6] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = mData[7]; mData[7] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[31]; mData[31] = mData[15]; mData[15] = aHold;
}

void M88::Quad_TriadD_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[50]; mData[50] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[58]; mData[58] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[59]; mData[59] = mData[43]; mData[43] = aHold;
}

void M88::Quad_TriadD_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[54]; mData[54] = mData[38]; mData[38] = aHold;
    aHold = mData[37]; mData[37] = mData[55]; mData[55] = mData[39]; mData[39] = aHold;
    aHold = mData[44]; mData[44] = mData[62]; mData[62] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[63]; mData[63] = mData[47]; mData[47] = aHold;
}

void M88::Mini_TriadD_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = mData[1]; mData[1] = aHold;
}

void M88::Mini_TriadD_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = mData[3]; mData[3] = aHold;
}

void M88::Mini_TriadD_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = mData[5]; mData[5] = aHold;
}

void M88::Mini_TriadD_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = mData[7]; mData[7] = aHold;
}

void M88::Mini_TriadD_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = mData[17]; mData[17] = aHold;
}

void M88::Mini_TriadD_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = mData[19]; mData[19] = aHold;
}

void M88::Mini_TriadD_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = mData[21]; mData[21] = aHold;
}

void M88::Mini_TriadD_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = mData[23]; mData[23] = aHold;
}

void M88::Mini_TriadD_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = mData[33]; mData[33] = aHold;
}

void M88::Mini_TriadD_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = mData[35]; mData[35] = aHold;
}

void M88::Mini_TriadD_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = mData[37]; mData[37] = aHold;
}

void M88::Mini_TriadD_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = mData[39]; mData[39] = aHold;
}

void M88::Mini_TriadD_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = mData[49]; mData[49] = aHold;
}

void M88::Mini_TriadD_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = mData[51]; mData[51] = aHold;
}

void M88::Mini_TriadD_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = mData[53]; mData[53] = aHold;
}

void M88::Mini_TriadD_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = mData[55]; mData[55] = aHold;
}




void M88::Full_TriadE_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = mData[36]; mData[36] = aHold;
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = mData[37]; mData[37] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = mData[38]; mData[38] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = mData[44]; mData[44] = aHold;
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = mData[45]; mData[45] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = mData[46]; mData[46] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = mData[47]; mData[47] = aHold;
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = mData[52]; mData[52] = aHold;
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = mData[53]; mData[53] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = mData[54]; mData[54] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = mData[55]; mData[55] = aHold;
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = mData[60]; mData[60] = aHold;
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = mData[61]; mData[61] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = mData[62]; mData[62] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = mData[63]; mData[63] = aHold;
}

void M88::Full_TriadE_EachQuad_2x2() {
    Quad_TriadE_2x2_A();
    Quad_TriadE_2x2_B();
    Quad_TriadE_2x2_C();
    Quad_TriadE_2x2_D();
}

void M88::Full_TriadE_EachMini_2x2() {
    Mini_TriadE_2x2_A();
    Mini_TriadE_2x2_B();
    Mini_TriadE_2x2_C();
    Mini_TriadE_2x2_D();
    Mini_TriadE_2x2_E();
    Mini_TriadE_2x2_F();
    Mini_TriadE_2x2_G();
    Mini_TriadE_2x2_H();
    Mini_TriadE_2x2_I();
    Mini_TriadE_2x2_J();
    Mini_TriadE_2x2_K();
    Mini_TriadE_2x2_L();
    Mini_TriadE_2x2_M();
    Mini_TriadE_2x2_N();
    Mini_TriadE_2x2_O();
    Mini_TriadE_2x2_P();
}

void M88::Quad_TriadE_EachMini_2x2_A() {
    Mini_TriadE_2x2_A();
    Mini_TriadE_2x2_B();
    Mini_TriadE_2x2_E();
    Mini_TriadE_2x2_F();
}

void M88::Quad_TriadE_EachMini_2x2_B() {
    Mini_TriadE_2x2_C();
    Mini_TriadE_2x2_D();
    Mini_TriadE_2x2_G();
    Mini_TriadE_2x2_H();
}

void M88::Quad_TriadE_EachMini_2x2_C() {
    Mini_TriadE_2x2_I();
    Mini_TriadE_2x2_J();
    Mini_TriadE_2x2_M();
    Mini_TriadE_2x2_N();
}

void M88::Quad_TriadE_EachMini_2x2_D() {
    Mini_TriadE_2x2_K();
    Mini_TriadE_2x2_L();
    Mini_TriadE_2x2_O();
    Mini_TriadE_2x2_P();
}

void M88::Quad_TriadE_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
}

void M88::Quad_TriadE_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
}

void M88::Quad_TriadE_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
}

void M88::Quad_TriadE_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}

void M88::Mini_TriadE_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = mData[9]; mData[9] = aHold;
}

void M88::Mini_TriadE_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = mData[11]; mData[11] = aHold;
}

void M88::Mini_TriadE_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = mData[13]; mData[13] = aHold;
}

void M88::Mini_TriadE_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = mData[15]; mData[15] = aHold;
}

void M88::Mini_TriadE_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = mData[25]; mData[25] = aHold;
}

void M88::Mini_TriadE_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = mData[27]; mData[27] = aHold;
}

void M88::Mini_TriadE_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = mData[29]; mData[29] = aHold;
}

void M88::Mini_TriadE_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = mData[31]; mData[31] = aHold;
}

void M88::Mini_TriadE_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = mData[41]; mData[41] = aHold;
}

void M88::Mini_TriadE_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = mData[43]; mData[43] = aHold;
}

void M88::Mini_TriadE_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = mData[45]; mData[45] = aHold;
}

void M88::Mini_TriadE_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = mData[47]; mData[47] = aHold;
}

void M88::Mini_TriadE_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = mData[57]; mData[57] = aHold;
}

void M88::Mini_TriadE_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = mData[59]; mData[59] = aHold;
}

void M88::Mini_TriadE_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = mData[61]; mData[61] = aHold;
}

void M88::Mini_TriadE_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = mData[63]; mData[63] = aHold;
}





void M88::Full_TriadF_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[36]; mData[36] = mData[32]; mData[32] = aHold;
    aHold = mData[1]; mData[1] = mData[37]; mData[37] = mData[33]; mData[33] = aHold;
    aHold = mData[2]; mData[2] = mData[38]; mData[38] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[39]; mData[39] = mData[35]; mData[35] = aHold;
    aHold = mData[8]; mData[8] = mData[44]; mData[44] = mData[40]; mData[40] = aHold;
    aHold = mData[9]; mData[9] = mData[45]; mData[45] = mData[41]; mData[41] = aHold;
    aHold = mData[10]; mData[10] = mData[46]; mData[46] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[47]; mData[47] = mData[43]; mData[43] = aHold;
    aHold = mData[16]; mData[16] = mData[52]; mData[52] = mData[48]; mData[48] = aHold;
    aHold = mData[17]; mData[17] = mData[53]; mData[53] = mData[49]; mData[49] = aHold;
    aHold = mData[18]; mData[18] = mData[54]; mData[54] = mData[50]; mData[50] = aHold;
    aHold = mData[19]; mData[19] = mData[55]; mData[55] = mData[51]; mData[51] = aHold;
    aHold = mData[24]; mData[24] = mData[60]; mData[60] = mData[56]; mData[56] = aHold;
    aHold = mData[25]; mData[25] = mData[61]; mData[61] = mData[57]; mData[57] = aHold;
    aHold = mData[26]; mData[26] = mData[62]; mData[62] = mData[58]; mData[58] = aHold;
    aHold = mData[27]; mData[27] = mData[63]; mData[63] = mData[59]; mData[59] = aHold;
}

void M88::Full_TriadF_EachQuad_2x2() {
    Quad_TriadF_2x2_A();
    Quad_TriadF_2x2_B();
    Quad_TriadF_2x2_C();
    Quad_TriadF_2x2_D();
}

void M88::Full_TriadF_EachMini_2x2() {
    Mini_TriadF_2x2_A();
    Mini_TriadF_2x2_B();
    Mini_TriadF_2x2_C();
    Mini_TriadF_2x2_D();
    Mini_TriadF_2x2_E();
    Mini_TriadF_2x2_F();
    Mini_TriadF_2x2_G();
    Mini_TriadF_2x2_H();
    Mini_TriadF_2x2_I();
    Mini_TriadF_2x2_J();
    Mini_TriadF_2x2_K();
    Mini_TriadF_2x2_L();
    Mini_TriadF_2x2_M();
    Mini_TriadF_2x2_N();
    Mini_TriadF_2x2_O();
    Mini_TriadF_2x2_P();
}

void M88::Quad_TriadF_EachMini_2x2_A() {
    Mini_TriadF_2x2_A();
    Mini_TriadF_2x2_B();
    Mini_TriadF_2x2_E();
    Mini_TriadF_2x2_F();
}

void M88::Quad_TriadF_EachMini_2x2_B() {
    Mini_TriadF_2x2_C();
    Mini_TriadF_2x2_D();
    Mini_TriadF_2x2_G();
    Mini_TriadF_2x2_H();
}

void M88::Quad_TriadF_EachMini_2x2_C() {
    Mini_TriadF_2x2_I();
    Mini_TriadF_2x2_J();
    Mini_TriadF_2x2_M();
    Mini_TriadF_2x2_N();
}

void M88::Quad_TriadF_EachMini_2x2_D() {
    Mini_TriadF_2x2_K();
    Mini_TriadF_2x2_L();
    Mini_TriadF_2x2_O();
    Mini_TriadF_2x2_P();
}

void M88::Quad_TriadF_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[18]; mData[18] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = mData[17]; mData[17] = aHold;
    aHold = mData[8]; mData[8] = mData[26]; mData[26] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[27]; mData[27] = mData[25]; mData[25] = aHold;
}

void M88::Quad_TriadF_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[22]; mData[22] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = mData[21]; mData[21] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[31]; mData[31] = mData[29]; mData[29] = aHold;
}

void M88::Quad_TriadF_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[50]; mData[50] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = mData[49]; mData[49] = aHold;
    aHold = mData[40]; mData[40] = mData[58]; mData[58] = mData[56]; mData[56] = aHold;
    aHold = mData[41]; mData[41] = mData[59]; mData[59] = mData[57]; mData[57] = aHold;
}

void M88::Quad_TriadF_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[54]; mData[54] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[55]; mData[55] = mData[53]; mData[53] = aHold;
    aHold = mData[44]; mData[44] = mData[62]; mData[62] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[63]; mData[63] = mData[61]; mData[61] = aHold;
}

void M88::Mini_TriadF_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = mData[8]; mData[8] = aHold;
}

void M88::Mini_TriadF_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = mData[10]; mData[10] = aHold;
}

void M88::Mini_TriadF_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = mData[12]; mData[12] = aHold;
}

void M88::Mini_TriadF_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = mData[14]; mData[14] = aHold;
}

void M88::Mini_TriadF_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = mData[24]; mData[24] = aHold;
}

void M88::Mini_TriadF_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = mData[26]; mData[26] = aHold;
}

void M88::Mini_TriadF_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = mData[28]; mData[28] = aHold;
}

void M88::Mini_TriadF_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = mData[30]; mData[30] = aHold;
}

void M88::Mini_TriadF_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = mData[40]; mData[40] = aHold;
}

void M88::Mini_TriadF_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = mData[42]; mData[42] = aHold;
}

void M88::Mini_TriadF_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = mData[44]; mData[44] = aHold;
}

void M88::Mini_TriadF_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = mData[46]; mData[46] = aHold;
}

void M88::Mini_TriadF_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = mData[56]; mData[56] = aHold;
}

void M88::Mini_TriadF_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = mData[58]; mData[58] = aHold;
}

void M88::Mini_TriadF_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = mData[60]; mData[60] = aHold;
}

void M88::Mini_TriadF_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = mData[62]; mData[62] = aHold;
}


void M88::Full_TriadG_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[32]; mData[32] = mData[36]; mData[36] = aHold;
    aHold = mData[5]; mData[5] = mData[33]; mData[33] = mData[37]; mData[37] = aHold;
    aHold = mData[6]; mData[6] = mData[34]; mData[34] = mData[38]; mData[38] = aHold;
    aHold = mData[7]; mData[7] = mData[35]; mData[35] = mData[39]; mData[39] = aHold;
    aHold = mData[12]; mData[12] = mData[40]; mData[40] = mData[44]; mData[44] = aHold;
    aHold = mData[13]; mData[13] = mData[41]; mData[41] = mData[45]; mData[45] = aHold;
    aHold = mData[14]; mData[14] = mData[42]; mData[42] = mData[46]; mData[46] = aHold;
    aHold = mData[15]; mData[15] = mData[43]; mData[43] = mData[47]; mData[47] = aHold;
    aHold = mData[20]; mData[20] = mData[48]; mData[48] = mData[52]; mData[52] = aHold;
    aHold = mData[21]; mData[21] = mData[49]; mData[49] = mData[53]; mData[53] = aHold;
    aHold = mData[22]; mData[22] = mData[50]; mData[50] = mData[54]; mData[54] = aHold;
    aHold = mData[23]; mData[23] = mData[51]; mData[51] = mData[55]; mData[55] = aHold;
    aHold = mData[28]; mData[28] = mData[56]; mData[56] = mData[60]; mData[60] = aHold;
    aHold = mData[29]; mData[29] = mData[57]; mData[57] = mData[61]; mData[61] = aHold;
    aHold = mData[30]; mData[30] = mData[58]; mData[58] = mData[62]; mData[62] = aHold;
    aHold = mData[31]; mData[31] = mData[59]; mData[59] = mData[63]; mData[63] = aHold;
}

void M88::Full_TriadG_EachQuad_2x2() {
    Quad_TriadG_2x2_A();
    Quad_TriadG_2x2_B();
    Quad_TriadG_2x2_C();
    Quad_TriadG_2x2_D();
}

void M88::Full_TriadG_EachMini_2x2() {
    Mini_TriadG_2x2_A();
    Mini_TriadG_2x2_B();
    Mini_TriadG_2x2_C();
    Mini_TriadG_2x2_D();
    Mini_TriadG_2x2_E();
    Mini_TriadG_2x2_F();
    Mini_TriadG_2x2_G();
    Mini_TriadG_2x2_H();
    Mini_TriadG_2x2_I();
    Mini_TriadG_2x2_J();
    Mini_TriadG_2x2_K();
    Mini_TriadG_2x2_L();
    Mini_TriadG_2x2_M();
    Mini_TriadG_2x2_N();
    Mini_TriadG_2x2_O();
    Mini_TriadG_2x2_P();
}

void M88::Quad_TriadG_EachMini_2x2_A() {
    Mini_TriadG_2x2_A();
    Mini_TriadG_2x2_B();
    Mini_TriadG_2x2_E();
    Mini_TriadG_2x2_F();
}

void M88::Quad_TriadG_EachMini_2x2_B() {
    Mini_TriadG_2x2_C();
    Mini_TriadG_2x2_D();
    Mini_TriadG_2x2_G();
    Mini_TriadG_2x2_H();
}

void M88::Quad_TriadG_EachMini_2x2_C() {
    Mini_TriadG_2x2_I();
    Mini_TriadG_2x2_J();
    Mini_TriadG_2x2_M();
    Mini_TriadG_2x2_N();
}

void M88::Quad_TriadG_EachMini_2x2_D() {
    Mini_TriadG_2x2_K();
    Mini_TriadG_2x2_L();
    Mini_TriadG_2x2_O();
    Mini_TriadG_2x2_P();
}

void M88::Quad_TriadG_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[10]; mData[10] = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
}

void M88::Quad_TriadG_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[14]; mData[14] = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[15]; mData[15] = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
}

void M88::Quad_TriadG_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[35]; mData[35] = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[42]; mData[42] = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
    aHold = mData[43]; mData[43] = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
}

void M88::Quad_TriadG_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[39]; mData[39] = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[46]; mData[46] = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
    aHold = mData[47]; mData[47] = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}

void M88::Mini_TriadG_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[1]; mData[1] = mData[8]; mData[8] = mData[9]; mData[9] = aHold;
}

void M88::Mini_TriadG_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[3]; mData[3] = mData[10]; mData[10] = mData[11]; mData[11] = aHold;
}

void M88::Mini_TriadG_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[5]; mData[5] = mData[12]; mData[12] = mData[13]; mData[13] = aHold;
}

void M88::Mini_TriadG_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[7]; mData[7] = mData[14]; mData[14] = mData[15]; mData[15] = aHold;
}

void M88::Mini_TriadG_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[17]; mData[17] = mData[24]; mData[24] = mData[25]; mData[25] = aHold;
}

void M88::Mini_TriadG_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[19]; mData[19] = mData[26]; mData[26] = mData[27]; mData[27] = aHold;
}

void M88::Mini_TriadG_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[21]; mData[21] = mData[28]; mData[28] = mData[29]; mData[29] = aHold;
}

void M88::Mini_TriadG_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[23]; mData[23] = mData[30]; mData[30] = mData[31]; mData[31] = aHold;
}

void M88::Mini_TriadG_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[33]; mData[33] = mData[40]; mData[40] = mData[41]; mData[41] = aHold;
}

void M88::Mini_TriadG_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[35]; mData[35] = mData[42]; mData[42] = mData[43]; mData[43] = aHold;
}

void M88::Mini_TriadG_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[37]; mData[37] = mData[44]; mData[44] = mData[45]; mData[45] = aHold;
}

void M88::Mini_TriadG_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[39]; mData[39] = mData[46]; mData[46] = mData[47]; mData[47] = aHold;
}

void M88::Mini_TriadG_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[49]; mData[49] = mData[56]; mData[56] = mData[57]; mData[57] = aHold;
}

void M88::Mini_TriadG_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[51]; mData[51] = mData[58]; mData[58] = mData[59]; mData[59] = aHold;
}

void M88::Mini_TriadG_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[53]; mData[53] = mData[60]; mData[60] = mData[61]; mData[61] = aHold;
}

void M88::Mini_TriadG_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[55]; mData[55] = mData[62]; mData[62] = mData[63]; mData[63] = aHold;
}





void M88::Full_TriadH_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[36]; mData[36] = mData[32]; mData[32] = aHold;
    aHold = mData[5]; mData[5] = mData[37]; mData[37] = mData[33]; mData[33] = aHold;
    aHold = mData[6]; mData[6] = mData[38]; mData[38] = mData[34]; mData[34] = aHold;
    aHold = mData[7]; mData[7] = mData[39]; mData[39] = mData[35]; mData[35] = aHold;
    aHold = mData[12]; mData[12] = mData[44]; mData[44] = mData[40]; mData[40] = aHold;
    aHold = mData[13]; mData[13] = mData[45]; mData[45] = mData[41]; mData[41] = aHold;
    aHold = mData[14]; mData[14] = mData[46]; mData[46] = mData[42]; mData[42] = aHold;
    aHold = mData[15]; mData[15] = mData[47]; mData[47] = mData[43]; mData[43] = aHold;
    aHold = mData[20]; mData[20] = mData[52]; mData[52] = mData[48]; mData[48] = aHold;
    aHold = mData[21]; mData[21] = mData[53]; mData[53] = mData[49]; mData[49] = aHold;
    aHold = mData[22]; mData[22] = mData[54]; mData[54] = mData[50]; mData[50] = aHold;
    aHold = mData[23]; mData[23] = mData[55]; mData[55] = mData[51]; mData[51] = aHold;
    aHold = mData[28]; mData[28] = mData[60]; mData[60] = mData[56]; mData[56] = aHold;
    aHold = mData[29]; mData[29] = mData[61]; mData[61] = mData[57]; mData[57] = aHold;
    aHold = mData[30]; mData[30] = mData[62]; mData[62] = mData[58]; mData[58] = aHold;
    aHold = mData[31]; mData[31] = mData[63]; mData[63] = mData[59]; mData[59] = aHold;
}

void M88::Full_TriadH_EachQuad_2x2() {
    Quad_TriadH_2x2_A();
    Quad_TriadH_2x2_B();
    Quad_TriadH_2x2_C();
    Quad_TriadH_2x2_D();
}

void M88::Full_TriadH_EachMini_2x2() {
    Mini_TriadH_2x2_A();
    Mini_TriadH_2x2_B();
    Mini_TriadH_2x2_C();
    Mini_TriadH_2x2_D();
    Mini_TriadH_2x2_E();
    Mini_TriadH_2x2_F();
    Mini_TriadH_2x2_G();
    Mini_TriadH_2x2_H();
    Mini_TriadH_2x2_I();
    Mini_TriadH_2x2_J();
    Mini_TriadH_2x2_K();
    Mini_TriadH_2x2_L();
    Mini_TriadH_2x2_M();
    Mini_TriadH_2x2_N();
    Mini_TriadH_2x2_O();
    Mini_TriadH_2x2_P();
}

void M88::Quad_TriadH_EachMini_2x2_A() {
    Mini_TriadH_2x2_A();
    Mini_TriadH_2x2_B();
    Mini_TriadH_2x2_E();
    Mini_TriadH_2x2_F();
}

void M88::Quad_TriadH_EachMini_2x2_B() {
    Mini_TriadH_2x2_C();
    Mini_TriadH_2x2_D();
    Mini_TriadH_2x2_G();
    Mini_TriadH_2x2_H();
}

void M88::Quad_TriadH_EachMini_2x2_C() {
    Mini_TriadH_2x2_I();
    Mini_TriadH_2x2_J();
    Mini_TriadH_2x2_M();
    Mini_TriadH_2x2_N();
}

void M88::Quad_TriadH_EachMini_2x2_D() {
    Mini_TriadH_2x2_K();
    Mini_TriadH_2x2_L();
    Mini_TriadH_2x2_O();
    Mini_TriadH_2x2_P();
}

void M88::Quad_TriadH_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = mData[16]; mData[16] = aHold;
    aHold = mData[3]; mData[3] = mData[19]; mData[19] = mData[17]; mData[17] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = mData[24]; mData[24] = aHold;
    aHold = mData[11]; mData[11] = mData[27]; mData[27] = mData[25]; mData[25] = aHold;
}

void M88::Quad_TriadH_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[22]; mData[22] = mData[20]; mData[20] = aHold;
    aHold = mData[7]; mData[7] = mData[23]; mData[23] = mData[21]; mData[21] = aHold;
    aHold = mData[14]; mData[14] = mData[30]; mData[30] = mData[28]; mData[28] = aHold;
    aHold = mData[15]; mData[15] = mData[31]; mData[31] = mData[29]; mData[29] = aHold;
}

void M88::Quad_TriadH_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[50]; mData[50] = mData[48]; mData[48] = aHold;
    aHold = mData[35]; mData[35] = mData[51]; mData[51] = mData[49]; mData[49] = aHold;
    aHold = mData[42]; mData[42] = mData[58]; mData[58] = mData[56]; mData[56] = aHold;
    aHold = mData[43]; mData[43] = mData[59]; mData[59] = mData[57]; mData[57] = aHold;
}

void M88::Quad_TriadH_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[54]; mData[54] = mData[52]; mData[52] = aHold;
    aHold = mData[39]; mData[39] = mData[55]; mData[55] = mData[53]; mData[53] = aHold;
    aHold = mData[46]; mData[46] = mData[62]; mData[62] = mData[60]; mData[60] = aHold;
    aHold = mData[47]; mData[47] = mData[63]; mData[63] = mData[61]; mData[61] = aHold;
}

void M88::Mini_TriadH_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[1]; mData[1] = mData[9]; mData[9] = mData[8]; mData[8] = aHold;
}

void M88::Mini_TriadH_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[3]; mData[3] = mData[11]; mData[11] = mData[10]; mData[10] = aHold;
}

void M88::Mini_TriadH_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[5]; mData[5] = mData[13]; mData[13] = mData[12]; mData[12] = aHold;
}

void M88::Mini_TriadH_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[7]; mData[7] = mData[15]; mData[15] = mData[14]; mData[14] = aHold;
}

void M88::Mini_TriadH_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[17]; mData[17] = mData[25]; mData[25] = mData[24]; mData[24] = aHold;
}

void M88::Mini_TriadH_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[19]; mData[19] = mData[27]; mData[27] = mData[26]; mData[26] = aHold;
}

void M88::Mini_TriadH_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[21]; mData[21] = mData[29]; mData[29] = mData[28]; mData[28] = aHold;
}

void M88::Mini_TriadH_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[23]; mData[23] = mData[31]; mData[31] = mData[30]; mData[30] = aHold;
}

void M88::Mini_TriadH_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[33]; mData[33] = mData[41]; mData[41] = mData[40]; mData[40] = aHold;
}

void M88::Mini_TriadH_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[35]; mData[35] = mData[43]; mData[43] = mData[42]; mData[42] = aHold;
}

void M88::Mini_TriadH_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[37]; mData[37] = mData[45]; mData[45] = mData[44]; mData[44] = aHold;
}

void M88::Mini_TriadH_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[39]; mData[39] = mData[47]; mData[47] = mData[46]; mData[46] = aHold;
}

void M88::Mini_TriadH_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[49]; mData[49] = mData[57]; mData[57] = mData[56]; mData[56] = aHold;
}

void M88::Mini_TriadH_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[51]; mData[51] = mData[59]; mData[59] = mData[58]; mData[58] = aHold;
}

void M88::Mini_TriadH_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[53]; mData[53] = mData[61]; mData[61] = mData[60]; mData[60] = aHold;
}

void M88::Mini_TriadH_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[55]; mData[55] = mData[63]; mData[63] = mData[62]; mData[62] = aHold;
}


void M88::Full_CastleA_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[20]; mData[20] = aHold;
    aHold = mData[1]; mData[1] = mData[21]; mData[21] = aHold;
    aHold = mData[2]; mData[2] = mData[22]; mData[22] = mData[52]; mData[52] = mData[32]; mData[32] = aHold;
    aHold = mData[3]; mData[3] = mData[23]; mData[23] = mData[53]; mData[53] = mData[33]; mData[33] = aHold;
    aHold = mData[4]; mData[4] = mData[38]; mData[38] = mData[50]; mData[50] = mData[16]; mData[16] = aHold;
    aHold = mData[5]; mData[5] = mData[39]; mData[39] = mData[51]; mData[51] = mData[17]; mData[17] = aHold;
    aHold = mData[6]; mData[6] = mData[36]; mData[36] = aHold;
    aHold = mData[7]; mData[7] = mData[37]; mData[37] = aHold;
    aHold = mData[8]; mData[8] = mData[28]; mData[28] = aHold;
    aHold = mData[9]; mData[9] = mData[29]; mData[29] = aHold;
    aHold = mData[10]; mData[10] = mData[30]; mData[30] = mData[60]; mData[60] = mData[40]; mData[40] = aHold;
    aHold = mData[11]; mData[11] = mData[31]; mData[31] = mData[61]; mData[61] = mData[41]; mData[41] = aHold;
    aHold = mData[12]; mData[12] = mData[46]; mData[46] = mData[58]; mData[58] = mData[24]; mData[24] = aHold;
    aHold = mData[13]; mData[13] = mData[47]; mData[47] = mData[59]; mData[59] = mData[25]; mData[25] = aHold;
    aHold = mData[14]; mData[14] = mData[44]; mData[44] = aHold;
    aHold = mData[15]; mData[15] = mData[45]; mData[45] = aHold;
    aHold = mData[18]; mData[18] = mData[48]; mData[48] = aHold;
    aHold = mData[19]; mData[19] = mData[49]; mData[49] = aHold;
    aHold = mData[26]; mData[26] = mData[56]; mData[56] = aHold;
    aHold = mData[27]; mData[27] = mData[57]; mData[57] = aHold;
    aHold = mData[34]; mData[34] = mData[54]; mData[54] = aHold;
    aHold = mData[35]; mData[35] = mData[55]; mData[55] = aHold;
    aHold = mData[42]; mData[42] = mData[62]; mData[62] = aHold;
    aHold = mData[43]; mData[43] = mData[63]; mData[63] = aHold;
}

void M88::Full_CastleA_EachQuad_4x4() {
    Quad_CastleA_4x4_A();
    Quad_CastleA_4x4_B();
    Quad_CastleA_4x4_C();
    Quad_CastleA_4x4_D();
}

void M88::Quad_CastleA_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[10]; mData[10] = aHold;
    aHold = mData[1]; mData[1] = mData[11]; mData[11] = mData[26]; mData[26] = mData[16]; mData[16] = aHold;
    aHold = mData[2]; mData[2] = mData[19]; mData[19] = mData[25]; mData[25] = mData[8]; mData[8] = aHold;
    aHold = mData[3]; mData[3] = mData[18]; mData[18] = aHold;
    aHold = mData[9]; mData[9] = mData[24]; mData[24] = aHold;
    aHold = mData[17]; mData[17] = mData[27]; mData[27] = aHold;
}

void M88::Quad_CastleA_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[14]; mData[14] = aHold;
    aHold = mData[5]; mData[5] = mData[15]; mData[15] = mData[30]; mData[30] = mData[20]; mData[20] = aHold;
    aHold = mData[6]; mData[6] = mData[23]; mData[23] = mData[29]; mData[29] = mData[12]; mData[12] = aHold;
    aHold = mData[7]; mData[7] = mData[22]; mData[22] = aHold;
    aHold = mData[13]; mData[13] = mData[28]; mData[28] = aHold;
    aHold = mData[21]; mData[21] = mData[31]; mData[31] = aHold;
}

void M88::Quad_CastleA_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[42]; mData[42] = aHold;
    aHold = mData[33]; mData[33] = mData[43]; mData[43] = mData[58]; mData[58] = mData[48]; mData[48] = aHold;
    aHold = mData[34]; mData[34] = mData[51]; mData[51] = mData[57]; mData[57] = mData[40]; mData[40] = aHold;
    aHold = mData[35]; mData[35] = mData[50]; mData[50] = aHold;
    aHold = mData[41]; mData[41] = mData[56]; mData[56] = aHold;
    aHold = mData[49]; mData[49] = mData[59]; mData[59] = aHold;
}

void M88::Quad_CastleA_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[46]; mData[46] = aHold;
    aHold = mData[37]; mData[37] = mData[47]; mData[47] = mData[62]; mData[62] = mData[52]; mData[52] = aHold;
    aHold = mData[38]; mData[38] = mData[55]; mData[55] = mData[61]; mData[61] = mData[44]; mData[44] = aHold;
    aHold = mData[39]; mData[39] = mData[54]; mData[54] = aHold;
    aHold = mData[45]; mData[45] = mData[60]; mData[60] = aHold;
    aHold = mData[53]; mData[53] = mData[63]; mData[63] = aHold;
}


void M88::Full_CastleB_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[34]; mData[34] = aHold;
    aHold = mData[1]; mData[1] = mData[35]; mData[35] = aHold;
    aHold = mData[2]; mData[2] = mData[32]; mData[32] = mData[52]; mData[52] = mData[22]; mData[22] = aHold;
    aHold = mData[3]; mData[3] = mData[33]; mData[33] = mData[53]; mData[53] = mData[23]; mData[23] = aHold;
    aHold = mData[4]; mData[4] = mData[16]; mData[16] = mData[50]; mData[50] = mData[38]; mData[38] = aHold;
    aHold = mData[5]; mData[5] = mData[17]; mData[17] = mData[51]; mData[51] = mData[39]; mData[39] = aHold;
    aHold = mData[6]; mData[6] = mData[18]; mData[18] = aHold;
    aHold = mData[7]; mData[7] = mData[19]; mData[19] = aHold;
    aHold = mData[8]; mData[8] = mData[42]; mData[42] = aHold;
    aHold = mData[9]; mData[9] = mData[43]; mData[43] = aHold;
    aHold = mData[10]; mData[10] = mData[40]; mData[40] = mData[60]; mData[60] = mData[30]; mData[30] = aHold;
    aHold = mData[11]; mData[11] = mData[41]; mData[41] = mData[61]; mData[61] = mData[31]; mData[31] = aHold;
    aHold = mData[12]; mData[12] = mData[24]; mData[24] = mData[58]; mData[58] = mData[46]; mData[46] = aHold;
    aHold = mData[13]; mData[13] = mData[25]; mData[25] = mData[59]; mData[59] = mData[47]; mData[47] = aHold;
    aHold = mData[14]; mData[14] = mData[26]; mData[26] = aHold;
    aHold = mData[15]; mData[15] = mData[27]; mData[27] = aHold;
    aHold = mData[20]; mData[20] = mData[54]; mData[54] = aHold;
    aHold = mData[21]; mData[21] = mData[55]; mData[55] = aHold;
    aHold = mData[28]; mData[28] = mData[62]; mData[62] = aHold;
    aHold = mData[29]; mData[29] = mData[63]; mData[63] = aHold;
    aHold = mData[36]; mData[36] = mData[48]; mData[48] = aHold;
    aHold = mData[37]; mData[37] = mData[49]; mData[49] = aHold;
    aHold = mData[44]; mData[44] = mData[56]; mData[56] = aHold;
    aHold = mData[45]; mData[45] = mData[57]; mData[57] = aHold;
}

void M88::Full_CastleB_EachQuad_4x4() {
    Quad_CastleB_4x4_A();
    Quad_CastleB_4x4_B();
    Quad_CastleB_4x4_C();
    Quad_CastleB_4x4_D();
}

void M88::Quad_CastleB_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[17]; mData[17] = aHold;
    aHold = mData[1]; mData[1] = mData[16]; mData[16] = mData[26]; mData[26] = mData[11]; mData[11] = aHold;
    aHold = mData[2]; mData[2] = mData[8]; mData[8] = mData[25]; mData[25] = mData[19]; mData[19] = aHold;
    aHold = mData[3]; mData[3] = mData[9]; mData[9] = aHold;
    aHold = mData[10]; mData[10] = mData[27]; mData[27] = aHold;
    aHold = mData[18]; mData[18] = mData[24]; mData[24] = aHold;
}

void M88::Quad_CastleB_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[21]; mData[21] = aHold;
    aHold = mData[5]; mData[5] = mData[20]; mData[20] = mData[30]; mData[30] = mData[15]; mData[15] = aHold;
    aHold = mData[6]; mData[6] = mData[12]; mData[12] = mData[29]; mData[29] = mData[23]; mData[23] = aHold;
    aHold = mData[7]; mData[7] = mData[13]; mData[13] = aHold;
    aHold = mData[14]; mData[14] = mData[31]; mData[31] = aHold;
    aHold = mData[22]; mData[22] = mData[28]; mData[28] = aHold;
}

void M88::Quad_CastleB_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[49]; mData[49] = aHold;
    aHold = mData[33]; mData[33] = mData[48]; mData[48] = mData[58]; mData[58] = mData[43]; mData[43] = aHold;
    aHold = mData[34]; mData[34] = mData[40]; mData[40] = mData[57]; mData[57] = mData[51]; mData[51] = aHold;
    aHold = mData[35]; mData[35] = mData[41]; mData[41] = aHold;
    aHold = mData[42]; mData[42] = mData[59]; mData[59] = aHold;
    aHold = mData[50]; mData[50] = mData[56]; mData[56] = aHold;
}

void M88::Quad_CastleB_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[53]; mData[53] = aHold;
    aHold = mData[37]; mData[37] = mData[52]; mData[52] = mData[62]; mData[62] = mData[47]; mData[47] = aHold;
    aHold = mData[38]; mData[38] = mData[44]; mData[44] = mData[61]; mData[61] = mData[55]; mData[55] = aHold;
    aHold = mData[39]; mData[39] = mData[45]; mData[45] = aHold;
    aHold = mData[46]; mData[46] = mData[63]; mData[63] = aHold;
    aHold = mData[54]; mData[54] = mData[60]; mData[60] = aHold;
}


void M88::Full_CastleC_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[36]; mData[36] = aHold;
    aHold = mData[1]; mData[1] = mData[37]; mData[37] = aHold;
    aHold = mData[2]; mData[2] = mData[38]; mData[38] = mData[52]; mData[52] = mData[16]; mData[16] = aHold;
    aHold = mData[3]; mData[3] = mData[39]; mData[39] = mData[53]; mData[53] = mData[17]; mData[17] = aHold;
    aHold = mData[4]; mData[4] = mData[22]; mData[22] = mData[50]; mData[50] = mData[32]; mData[32] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = mData[51]; mData[51] = mData[33]; mData[33] = aHold;
    aHold = mData[6]; mData[6] = mData[34]; mData[34] = aHold;
    aHold = mData[7]; mData[7] = mData[35]; mData[35] = aHold;
    aHold = mData[8]; mData[8] = mData[44]; mData[44] = aHold;
    aHold = mData[9]; mData[9] = mData[45]; mData[45] = aHold;
    aHold = mData[10]; mData[10] = mData[46]; mData[46] = mData[60]; mData[60] = mData[24]; mData[24] = aHold;
    aHold = mData[11]; mData[11] = mData[47]; mData[47] = mData[61]; mData[61] = mData[25]; mData[25] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = mData[58]; mData[58] = mData[40]; mData[40] = aHold;
    aHold = mData[13]; mData[13] = mData[31]; mData[31] = mData[59]; mData[59] = mData[41]; mData[41] = aHold;
    aHold = mData[14]; mData[14] = mData[42]; mData[42] = aHold;
    aHold = mData[15]; mData[15] = mData[43]; mData[43] = aHold;
    aHold = mData[18]; mData[18] = mData[54]; mData[54] = aHold;
    aHold = mData[19]; mData[19] = mData[55]; mData[55] = aHold;
    aHold = mData[20]; mData[20] = mData[48]; mData[48] = aHold;
    aHold = mData[21]; mData[21] = mData[49]; mData[49] = aHold;
    aHold = mData[26]; mData[26] = mData[62]; mData[62] = aHold;
    aHold = mData[27]; mData[27] = mData[63]; mData[63] = aHold;
    aHold = mData[28]; mData[28] = mData[56]; mData[56] = aHold;
    aHold = mData[29]; mData[29] = mData[57]; mData[57] = aHold;
}

void M88::Full_CastleC_EachQuad_4x4() {
    Quad_CastleC_4x4_A();
    Quad_CastleC_4x4_B();
    Quad_CastleC_4x4_C();
    Quad_CastleC_4x4_D();
}

void M88::Quad_CastleC_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[18]; mData[18] = aHold;
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = mData[26]; mData[26] = mData[8]; mData[8] = aHold;
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = mData[25]; mData[25] = mData[16]; mData[16] = aHold;
    aHold = mData[3]; mData[3] = mData[17]; mData[17] = aHold;
    aHold = mData[9]; mData[9] = mData[27]; mData[27] = aHold;
    aHold = mData[10]; mData[10] = mData[24]; mData[24] = aHold;
}

void M88::Quad_CastleC_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[22]; mData[22] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = mData[30]; mData[30] = mData[12]; mData[12] = aHold;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = mData[29]; mData[29] = mData[20]; mData[20] = aHold;
    aHold = mData[7]; mData[7] = mData[21]; mData[21] = aHold;
    aHold = mData[13]; mData[13] = mData[31]; mData[31] = aHold;
    aHold = mData[14]; mData[14] = mData[28]; mData[28] = aHold;
}

void M88::Quad_CastleC_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[50]; mData[50] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = mData[58]; mData[58] = mData[40]; mData[40] = aHold;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = mData[57]; mData[57] = mData[48]; mData[48] = aHold;
    aHold = mData[35]; mData[35] = mData[49]; mData[49] = aHold;
    aHold = mData[41]; mData[41] = mData[59]; mData[59] = aHold;
    aHold = mData[42]; mData[42] = mData[56]; mData[56] = aHold;
}

void M88::Quad_CastleC_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[54]; mData[54] = aHold;
    aHold = mData[37]; mData[37] = mData[55]; mData[55] = mData[62]; mData[62] = mData[44]; mData[44] = aHold;
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = mData[61]; mData[61] = mData[52]; mData[52] = aHold;
    aHold = mData[39]; mData[39] = mData[53]; mData[53] = aHold;
    aHold = mData[45]; mData[45] = mData[63]; mData[63] = aHold;
    aHold = mData[46]; mData[46] = mData[60]; mData[60] = aHold;
}




void M88::Full_CastleD_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[18]; mData[18] = aHold;
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = aHold;
    aHold = mData[2]; mData[2] = mData[16]; mData[16] = mData[52]; mData[52] = mData[38]; mData[38] = aHold;
    aHold = mData[3]; mData[3] = mData[17]; mData[17] = mData[53]; mData[53] = mData[39]; mData[39] = aHold;
    aHold = mData[4]; mData[4] = mData[32]; mData[32] = mData[50]; mData[50] = mData[22]; mData[22] = aHold;
    aHold = mData[5]; mData[5] = mData[33]; mData[33] = mData[51]; mData[51] = mData[23]; mData[23] = aHold;
    aHold = mData[6]; mData[6] = mData[20]; mData[20] = aHold;
    aHold = mData[7]; mData[7] = mData[21]; mData[21] = aHold;
    aHold = mData[8]; mData[8] = mData[26]; mData[26] = aHold;
    aHold = mData[9]; mData[9] = mData[27]; mData[27] = aHold;
    aHold = mData[10]; mData[10] = mData[24]; mData[24] = mData[60]; mData[60] = mData[46]; mData[46] = aHold;
    aHold = mData[11]; mData[11] = mData[25]; mData[25] = mData[61]; mData[61] = mData[47]; mData[47] = aHold;
    aHold = mData[12]; mData[12] = mData[40]; mData[40] = mData[58]; mData[58] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[41]; mData[41] = mData[59]; mData[59] = mData[31]; mData[31] = aHold;
    aHold = mData[14]; mData[14] = mData[28]; mData[28] = aHold;
    aHold = mData[15]; mData[15] = mData[29]; mData[29] = aHold;
    aHold = mData[34]; mData[34] = mData[48]; mData[48] = aHold;
    aHold = mData[35]; mData[35] = mData[49]; mData[49] = aHold;
    aHold = mData[36]; mData[36] = mData[54]; mData[54] = aHold;
    aHold = mData[37]; mData[37] = mData[55]; mData[55] = aHold;
    aHold = mData[42]; mData[42] = mData[56]; mData[56] = aHold;
    aHold = mData[43]; mData[43] = mData[57]; mData[57] = aHold;
    aHold = mData[44]; mData[44] = mData[62]; mData[62] = aHold;
    aHold = mData[45]; mData[45] = mData[63]; mData[63] = aHold;
}

void M88::Full_CastleD_EachQuad_4x4() {
    Quad_CastleD_4x4_A();
    Quad_CastleD_4x4_B();
    Quad_CastleD_4x4_C();
    Quad_CastleD_4x4_D();
}

void M88::Quad_CastleD_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = aHold;
    aHold = mData[1]; mData[1] = mData[8]; mData[8] = mData[26]; mData[26] = mData[19]; mData[19] = aHold;
    aHold = mData[2]; mData[2] = mData[16]; mData[16] = mData[25]; mData[25] = mData[11]; mData[11] = aHold;
    aHold = mData[3]; mData[3] = mData[10]; mData[10] = aHold;
    aHold = mData[17]; mData[17] = mData[24]; mData[24] = aHold;
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = aHold;
}

void M88::Quad_CastleD_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = aHold;
    aHold = mData[5]; mData[5] = mData[12]; mData[12] = mData[30]; mData[30] = mData[23]; mData[23] = aHold;
    aHold = mData[6]; mData[6] = mData[20]; mData[20] = mData[29]; mData[29] = mData[15]; mData[15] = aHold;
    aHold = mData[7]; mData[7] = mData[14]; mData[14] = aHold;
    aHold = mData[21]; mData[21] = mData[28]; mData[28] = aHold;
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = aHold;
}

void M88::Quad_CastleD_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = aHold;
    aHold = mData[33]; mData[33] = mData[40]; mData[40] = mData[58]; mData[58] = mData[51]; mData[51] = aHold;
    aHold = mData[34]; mData[34] = mData[48]; mData[48] = mData[57]; mData[57] = mData[43]; mData[43] = aHold;
    aHold = mData[35]; mData[35] = mData[42]; mData[42] = aHold;
    aHold = mData[49]; mData[49] = mData[56]; mData[56] = aHold;
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = aHold;
}

void M88::Quad_CastleD_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = aHold;
    aHold = mData[37]; mData[37] = mData[44]; mData[44] = mData[62]; mData[62] = mData[55]; mData[55] = aHold;
    aHold = mData[38]; mData[38] = mData[52]; mData[52] = mData[61]; mData[61] = mData[47]; mData[47] = aHold;
    aHold = mData[39]; mData[39] = mData[46]; mData[46] = aHold;
    aHold = mData[53]; mData[53] = mData[60]; mData[60] = aHold;
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = aHold;
}

void M88::Full_TowerA_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[38]; mData[38] = aHold;
    aHold = mData[1]; mData[1] = mData[39]; mData[39] = aHold;
    aHold = mData[2]; mData[2] = mData[20]; mData[20] = aHold;
    aHold = mData[3]; mData[3] = mData[21]; mData[21] = aHold;
    aHold = mData[4]; mData[4] = mData[48]; mData[48] = aHold;
    aHold = mData[5]; mData[5] = mData[49]; mData[49] = aHold;
    aHold = mData[6]; mData[6] = mData[50]; mData[50] = aHold;
    aHold = mData[7]; mData[7] = mData[51]; mData[51] = aHold;
    aHold = mData[8]; mData[8] = mData[46]; mData[46] = aHold;
    aHold = mData[9]; mData[9] = mData[47]; mData[47] = aHold;
    aHold = mData[10]; mData[10] = mData[28]; mData[28] = aHold;
    aHold = mData[11]; mData[11] = mData[29]; mData[29] = aHold;
    aHold = mData[12]; mData[12] = mData[56]; mData[56] = aHold;
    aHold = mData[13]; mData[13] = mData[57]; mData[57] = aHold;
    aHold = mData[14]; mData[14] = mData[58]; mData[58] = aHold;
    aHold = mData[15]; mData[15] = mData[59]; mData[59] = aHold;
    aHold = mData[16]; mData[16] = mData[54]; mData[54] = aHold;
    aHold = mData[17]; mData[17] = mData[55]; mData[55] = aHold;
    aHold = mData[18]; mData[18] = mData[32]; mData[32] = aHold;
    aHold = mData[19]; mData[19] = mData[33]; mData[33] = aHold;
    aHold = mData[22]; mData[22] = mData[36]; mData[36] = aHold;
    aHold = mData[23]; mData[23] = mData[37]; mData[37] = aHold;
    aHold = mData[24]; mData[24] = mData[62]; mData[62] = aHold;
    aHold = mData[25]; mData[25] = mData[63]; mData[63] = aHold;
    aHold = mData[26]; mData[26] = mData[40]; mData[40] = aHold;
    aHold = mData[27]; mData[27] = mData[41]; mData[41] = aHold;
    aHold = mData[30]; mData[30] = mData[44]; mData[44] = aHold;
    aHold = mData[31]; mData[31] = mData[45]; mData[45] = aHold;
    aHold = mData[34]; mData[34] = mData[52]; mData[52] = aHold;
    aHold = mData[35]; mData[35] = mData[53]; mData[53] = aHold;
    aHold = mData[42]; mData[42] = mData[60]; mData[60] = aHold;
    aHold = mData[43]; mData[43] = mData[61]; mData[61] = aHold;
}

void M88::Full_TowerA_EachQuad_4x4() {
    Quad_TowerA_4x4_A();
    Quad_TowerA_4x4_B();
    Quad_TowerA_4x4_C();
    Quad_TowerA_4x4_D();
}

void M88::Quad_TowerA_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[19]; mData[19] = aHold;
    aHold = mData[1]; mData[1] = mData[10]; mData[10] = aHold;
    aHold = mData[2]; mData[2] = mData[24]; mData[24] = aHold;
    aHold = mData[3]; mData[3] = mData[25]; mData[25] = aHold;
    aHold = mData[8]; mData[8] = mData[27]; mData[27] = aHold;
    aHold = mData[9]; mData[9] = mData[16]; mData[16] = aHold;
    aHold = mData[11]; mData[11] = mData[18]; mData[18] = aHold;
    aHold = mData[17]; mData[17] = mData[26]; mData[26] = aHold;
}

void M88::Quad_TowerA_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[23]; mData[23] = aHold;
    aHold = mData[5]; mData[5] = mData[14]; mData[14] = aHold;
    aHold = mData[6]; mData[6] = mData[28]; mData[28] = aHold;
    aHold = mData[7]; mData[7] = mData[29]; mData[29] = aHold;
    aHold = mData[12]; mData[12] = mData[31]; mData[31] = aHold;
    aHold = mData[13]; mData[13] = mData[20]; mData[20] = aHold;
    aHold = mData[15]; mData[15] = mData[22]; mData[22] = aHold;
    aHold = mData[21]; mData[21] = mData[30]; mData[30] = aHold;
}

void M88::Quad_TowerA_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[51]; mData[51] = aHold;
    aHold = mData[33]; mData[33] = mData[42]; mData[42] = aHold;
    aHold = mData[34]; mData[34] = mData[56]; mData[56] = aHold;
    aHold = mData[35]; mData[35] = mData[57]; mData[57] = aHold;
    aHold = mData[40]; mData[40] = mData[59]; mData[59] = aHold;
    aHold = mData[41]; mData[41] = mData[48]; mData[48] = aHold;
    aHold = mData[43]; mData[43] = mData[50]; mData[50] = aHold;
    aHold = mData[49]; mData[49] = mData[58]; mData[58] = aHold;
}

void M88::Quad_TowerA_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[55]; mData[55] = aHold;
    aHold = mData[37]; mData[37] = mData[46]; mData[46] = aHold;
    aHold = mData[38]; mData[38] = mData[60]; mData[60] = aHold;
    aHold = mData[39]; mData[39] = mData[61]; mData[61] = aHold;
    aHold = mData[44]; mData[44] = mData[63]; mData[63] = aHold;
    aHold = mData[45]; mData[45] = mData[52]; mData[52] = aHold;
    aHold = mData[47]; mData[47] = mData[54]; mData[54] = aHold;
    aHold = mData[53]; mData[53] = mData[62]; mData[62] = aHold;
}

void M88::Full_TowerB_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = aHold;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = aHold;
    aHold = mData[20]; mData[20] = mData[52]; mData[52] = aHold;
    aHold = mData[21]; mData[21] = mData[53]; mData[53] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = aHold;
    aHold = mData[28]; mData[28] = mData[60]; mData[60] = aHold;
    aHold = mData[29]; mData[29] = mData[61]; mData[61] = aHold;
    aHold = mData[32]; mData[32] = mData[36]; mData[36] = aHold;
    aHold = mData[33]; mData[33] = mData[37]; mData[37] = aHold;
    aHold = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[40]; mData[40] = mData[44]; mData[44] = aHold;
    aHold = mData[41]; mData[41] = mData[45]; mData[45] = aHold;
    aHold = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
    aHold = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
    aHold = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
}

void M88::Full_TowerB_EachQuad_4x4() {
    Quad_TowerB_4x4_A();
    Quad_TowerB_4x4_B();
    Quad_TowerB_4x4_C();
    Quad_TowerB_4x4_D();
}

void M88::Quad_TowerB_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = aHold;
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
    aHold = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[19]; mData[19] = mData[27]; mData[27] = aHold;
    aHold = mData[24]; mData[24] = mData[25]; mData[25] = aHold;
}

void M88::Quad_TowerB_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = aHold;
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = aHold;
    aHold = mData[14]; mData[14] = mData[30]; mData[30] = aHold;
    aHold = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[23]; mData[23] = mData[31]; mData[31] = aHold;
    aHold = mData[28]; mData[28] = mData[29]; mData[29] = aHold;
}

void M88::Quad_TowerB_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = aHold;
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = aHold;
    aHold = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[51]; mData[51] = mData[59]; mData[59] = aHold;
    aHold = mData[56]; mData[56] = mData[57]; mData[57] = aHold;
}

void M88::Quad_TowerB_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = aHold;
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = aHold;
    aHold = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[55]; mData[55] = mData[63]; mData[63] = aHold;
    aHold = mData[60]; mData[60] = mData[61]; mData[61] = aHold;
}


void M88::Full_FortressA_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[52]; mData[52] = aHold;
    aHold = mData[1]; mData[1] = mData[53]; mData[53] = aHold;
    aHold = mData[2]; mData[2] = mData[54]; mData[54] = aHold;
    aHold = mData[3]; mData[3] = mData[55]; mData[55] = aHold;
    aHold = mData[4]; mData[4] = mData[36]; mData[36] = aHold;
    aHold = mData[5]; mData[5] = mData[37]; mData[37] = aHold;
    aHold = mData[6]; mData[6] = mData[32]; mData[32] = aHold;
    aHold = mData[7]; mData[7] = mData[33]; mData[33] = aHold;
    aHold = mData[8]; mData[8] = mData[60]; mData[60] = aHold;
    aHold = mData[9]; mData[9] = mData[61]; mData[61] = aHold;
    aHold = mData[10]; mData[10] = mData[62]; mData[62] = aHold;
    aHold = mData[11]; mData[11] = mData[63]; mData[63] = aHold;
    aHold = mData[12]; mData[12] = mData[44]; mData[44] = aHold;
    aHold = mData[13]; mData[13] = mData[45]; mData[45] = aHold;
    aHold = mData[14]; mData[14] = mData[40]; mData[40] = aHold;
    aHold = mData[15]; mData[15] = mData[41]; mData[41] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = aHold;
    aHold = mData[22]; mData[22] = mData[48]; mData[48] = aHold;
    aHold = mData[23]; mData[23] = mData[49]; mData[49] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = aHold;
    aHold = mData[30]; mData[30] = mData[56]; mData[56] = aHold;
    aHold = mData[31]; mData[31] = mData[57]; mData[57] = aHold;
    aHold = mData[34]; mData[34] = mData[38]; mData[38] = aHold;
    aHold = mData[35]; mData[35] = mData[39]; mData[39] = aHold;
    aHold = mData[42]; mData[42] = mData[46]; mData[46] = aHold;
    aHold = mData[43]; mData[43] = mData[47]; mData[47] = aHold;
}

void M88::Full_FortressA_EachQuad_4x4() {
    Quad_FortressA_4x4_A();
    Quad_FortressA_4x4_B();
    Quad_FortressA_4x4_C();
    Quad_FortressA_4x4_D();
}

void M88::Quad_FortressA_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[26]; mData[26] = aHold;
    aHold = mData[1]; mData[1] = mData[27]; mData[27] = aHold;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[16]; mData[16] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = aHold;
    aHold = mData[11]; mData[11] = mData[24]; mData[24] = aHold;
    aHold = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
}

void M88::Quad_FortressA_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[30]; mData[30] = aHold;
    aHold = mData[5]; mData[5] = mData[31]; mData[31] = aHold;
    aHold = mData[6]; mData[6] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[20]; mData[20] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = aHold;
    aHold = mData[15]; mData[15] = mData[28]; mData[28] = aHold;
    aHold = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
}

void M88::Quad_FortressA_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[58]; mData[58] = aHold;
    aHold = mData[33]; mData[33] = mData[59]; mData[59] = aHold;
    aHold = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[35]; mData[35] = mData[48]; mData[48] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = aHold;
    aHold = mData[43]; mData[43] = mData[56]; mData[56] = aHold;
    aHold = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
}

void M88::Quad_FortressA_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[62]; mData[62] = aHold;
    aHold = mData[37]; mData[37] = mData[63]; mData[63] = aHold;
    aHold = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[39]; mData[39] = mData[52]; mData[52] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = aHold;
    aHold = mData[47]; mData[47] = mData[60]; mData[60] = aHold;
    aHold = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
}


void M88::Full_FortressB_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[54]; mData[54] = aHold;
    aHold = mData[1]; mData[1] = mData[55]; mData[55] = aHold;
    aHold = mData[2]; mData[2] = mData[52]; mData[52] = aHold;
    aHold = mData[3]; mData[3] = mData[53]; mData[53] = aHold;
    aHold = mData[4]; mData[4] = mData[18]; mData[18] = aHold;
    aHold = mData[5]; mData[5] = mData[19]; mData[19] = aHold;
    aHold = mData[6]; mData[6] = mData[48]; mData[48] = aHold;
    aHold = mData[7]; mData[7] = mData[49]; mData[49] = aHold;
    aHold = mData[8]; mData[8] = mData[62]; mData[62] = aHold;
    aHold = mData[9]; mData[9] = mData[63]; mData[63] = aHold;
    aHold = mData[10]; mData[10] = mData[60]; mData[60] = aHold;
    aHold = mData[11]; mData[11] = mData[61]; mData[61] = aHold;
    aHold = mData[12]; mData[12] = mData[26]; mData[26] = aHold;
    aHold = mData[13]; mData[13] = mData[27]; mData[27] = aHold;
    aHold = mData[14]; mData[14] = mData[56]; mData[56] = aHold;
    aHold = mData[15]; mData[15] = mData[57]; mData[57] = aHold;
    aHold = mData[16]; mData[16] = mData[34]; mData[34] = aHold;
    aHold = mData[17]; mData[17] = mData[35]; mData[35] = aHold;
    aHold = mData[20]; mData[20] = mData[38]; mData[38] = aHold;
    aHold = mData[21]; mData[21] = mData[39]; mData[39] = aHold;
    aHold = mData[22]; mData[22] = mData[32]; mData[32] = aHold;
    aHold = mData[23]; mData[23] = mData[33]; mData[33] = aHold;
    aHold = mData[24]; mData[24] = mData[42]; mData[42] = aHold;
    aHold = mData[25]; mData[25] = mData[43]; mData[43] = aHold;
    aHold = mData[28]; mData[28] = mData[46]; mData[46] = aHold;
    aHold = mData[29]; mData[29] = mData[47]; mData[47] = aHold;
    aHold = mData[30]; mData[30] = mData[40]; mData[40] = aHold;
    aHold = mData[31]; mData[31] = mData[41]; mData[41] = aHold;
    aHold = mData[36]; mData[36] = mData[50]; mData[50] = aHold;
    aHold = mData[37]; mData[37] = mData[51]; mData[51] = aHold;
    aHold = mData[44]; mData[44] = mData[58]; mData[58] = aHold;
    aHold = mData[45]; mData[45] = mData[59]; mData[59] = aHold;
}

void M88::Full_FortressB_EachQuad_4x4() {
    Quad_FortressB_4x4_A();
    Quad_FortressB_4x4_B();
    Quad_FortressB_4x4_C();
    Quad_FortressB_4x4_D();
}

void M88::Quad_FortressB_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[27]; mData[27] = aHold;
    aHold = mData[1]; mData[1] = mData[26]; mData[26] = aHold;
    aHold = mData[2]; mData[2] = mData[9]; mData[9] = aHold;
    aHold = mData[3]; mData[3] = mData[24]; mData[24] = aHold;
    aHold = mData[8]; mData[8] = mData[17]; mData[17] = aHold;
    aHold = mData[10]; mData[10] = mData[19]; mData[19] = aHold;
    aHold = mData[11]; mData[11] = mData[16]; mData[16] = aHold;
    aHold = mData[18]; mData[18] = mData[25]; mData[25] = aHold;
}

void M88::Quad_FortressB_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[31]; mData[31] = aHold;
    aHold = mData[5]; mData[5] = mData[30]; mData[30] = aHold;
    aHold = mData[6]; mData[6] = mData[13]; mData[13] = aHold;
    aHold = mData[7]; mData[7] = mData[28]; mData[28] = aHold;
    aHold = mData[12]; mData[12] = mData[21]; mData[21] = aHold;
    aHold = mData[14]; mData[14] = mData[23]; mData[23] = aHold;
    aHold = mData[15]; mData[15] = mData[20]; mData[20] = aHold;
    aHold = mData[22]; mData[22] = mData[29]; mData[29] = aHold;
}

void M88::Quad_FortressB_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[59]; mData[59] = aHold;
    aHold = mData[33]; mData[33] = mData[58]; mData[58] = aHold;
    aHold = mData[34]; mData[34] = mData[41]; mData[41] = aHold;
    aHold = mData[35]; mData[35] = mData[56]; mData[56] = aHold;
    aHold = mData[40]; mData[40] = mData[49]; mData[49] = aHold;
    aHold = mData[42]; mData[42] = mData[51]; mData[51] = aHold;
    aHold = mData[43]; mData[43] = mData[48]; mData[48] = aHold;
    aHold = mData[50]; mData[50] = mData[57]; mData[57] = aHold;
}

void M88::Quad_FortressB_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[63]; mData[63] = aHold;
    aHold = mData[37]; mData[37] = mData[62]; mData[62] = aHold;
    aHold = mData[38]; mData[38] = mData[45]; mData[45] = aHold;
    aHold = mData[39]; mData[39] = mData[60]; mData[60] = aHold;
    aHold = mData[44]; mData[44] = mData[53]; mData[53] = aHold;
    aHold = mData[46]; mData[46] = mData[55]; mData[55] = aHold;
    aHold = mData[47]; mData[47] = mData[52]; mData[52] = aHold;
    aHold = mData[54]; mData[54] = mData[61]; mData[61] = aHold;
}

void M88::Full_PinA_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[48]; mData[48] = mData[54]; mData[54] = mData[6]; mData[6] = aHold;
    aHold = mData[1]; mData[1] = mData[49]; mData[49] = mData[55]; mData[55] = mData[7]; mData[7] = aHold;
    aHold = mData[2]; mData[2] = mData[32]; mData[32] = mData[52]; mData[52] = mData[22]; mData[22] = aHold;
    aHold = mData[3]; mData[3] = mData[33]; mData[33] = mData[53]; mData[53] = mData[23]; mData[23] = aHold;
    aHold = mData[4]; mData[4] = mData[16]; mData[16] = mData[50]; mData[50] = mData[38]; mData[38] = aHold;
    aHold = mData[5]; mData[5] = mData[17]; mData[17] = mData[51]; mData[51] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[56]; mData[56] = mData[62]; mData[62] = mData[14]; mData[14] = aHold;
    aHold = mData[9]; mData[9] = mData[57]; mData[57] = mData[63]; mData[63] = mData[15]; mData[15] = aHold;
    aHold = mData[10]; mData[10] = mData[40]; mData[40] = mData[60]; mData[60] = mData[30]; mData[30] = aHold;
    aHold = mData[11]; mData[11] = mData[41]; mData[41] = mData[61]; mData[61] = mData[31]; mData[31] = aHold;
    aHold = mData[12]; mData[12] = mData[24]; mData[24] = mData[58]; mData[58] = mData[46]; mData[46] = aHold;
    aHold = mData[13]; mData[13] = mData[25]; mData[25] = mData[59]; mData[59] = mData[47]; mData[47] = aHold;
    aHold = mData[18]; mData[18] = mData[20]; mData[20] = mData[36]; mData[36] = mData[34]; mData[34] = aHold;
    aHold = mData[19]; mData[19] = mData[21]; mData[21] = mData[37]; mData[37] = mData[35]; mData[35] = aHold;
    aHold = mData[26]; mData[26] = mData[28]; mData[28] = mData[44]; mData[44] = mData[42]; mData[42] = aHold;
    aHold = mData[27]; mData[27] = mData[29]; mData[29] = mData[45]; mData[45] = mData[43]; mData[43] = aHold;
}

void M88::Full_PinA_EachQuad_4x4() {
    Quad_PinA_4x4_A();
    Quad_PinA_4x4_B();
    Quad_PinA_4x4_C();
    Quad_PinA_4x4_D();
}

void M88::Quad_PinA_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[24]; mData[24] = mData[27]; mData[27] = mData[3]; mData[3] = aHold;
    aHold = mData[1]; mData[1] = mData[16]; mData[16] = mData[26]; mData[26] = mData[11]; mData[11] = aHold;
    aHold = mData[2]; mData[2] = mData[8]; mData[8] = mData[25]; mData[25] = mData[19]; mData[19] = aHold;
    aHold = mData[9]; mData[9] = mData[10]; mData[10] = mData[18]; mData[18] = mData[17]; mData[17] = aHold;
}

void M88::Quad_PinA_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[28]; mData[28] = mData[31]; mData[31] = mData[7]; mData[7] = aHold;
    aHold = mData[5]; mData[5] = mData[20]; mData[20] = mData[30]; mData[30] = mData[15]; mData[15] = aHold;
    aHold = mData[6]; mData[6] = mData[12]; mData[12] = mData[29]; mData[29] = mData[23]; mData[23] = aHold;
    aHold = mData[13]; mData[13] = mData[14]; mData[14] = mData[22]; mData[22] = mData[21]; mData[21] = aHold;
}

void M88::Quad_PinA_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[56]; mData[56] = mData[59]; mData[59] = mData[35]; mData[35] = aHold;
    aHold = mData[33]; mData[33] = mData[48]; mData[48] = mData[58]; mData[58] = mData[43]; mData[43] = aHold;
    aHold = mData[34]; mData[34] = mData[40]; mData[40] = mData[57]; mData[57] = mData[51]; mData[51] = aHold;
    aHold = mData[41]; mData[41] = mData[42]; mData[42] = mData[50]; mData[50] = mData[49]; mData[49] = aHold;
}

void M88::Quad_PinA_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[60]; mData[60] = mData[63]; mData[63] = mData[39]; mData[39] = aHold;
    aHold = mData[37]; mData[37] = mData[52]; mData[52] = mData[62]; mData[62] = mData[47]; mData[47] = aHold;
    aHold = mData[38]; mData[38] = mData[44]; mData[44] = mData[61]; mData[61] = mData[55]; mData[55] = aHold;
    aHold = mData[45]; mData[45] = mData[46]; mData[46] = mData[54]; mData[54] = mData[53]; mData[53] = aHold;
}

void M88::Full_PinA_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[56]; mData[56] = mData[63]; mData[63] = mData[7]; mData[7] = aHold;
    aHold = mData[1]; mData[1] = mData[48]; mData[48] = mData[62]; mData[62] = mData[15]; mData[15] = aHold;
    aHold = mData[2]; mData[2] = mData[40]; mData[40] = mData[61]; mData[61] = mData[23]; mData[23] = aHold;
    aHold = mData[3]; mData[3] = mData[32]; mData[32] = mData[60]; mData[60] = mData[31]; mData[31] = aHold;
    aHold = mData[4]; mData[4] = mData[24]; mData[24] = mData[59]; mData[59] = mData[39]; mData[39] = aHold;
    aHold = mData[5]; mData[5] = mData[16]; mData[16] = mData[58]; mData[58] = mData[47]; mData[47] = aHold;
    aHold = mData[6]; mData[6] = mData[8]; mData[8] = mData[57]; mData[57] = mData[55]; mData[55] = aHold;
    aHold = mData[9]; mData[9] = mData[14]; mData[14] = mData[54]; mData[54] = mData[49]; mData[49] = aHold;
    aHold = mData[10]; mData[10] = mData[22]; mData[22] = mData[53]; mData[53] = mData[41]; mData[41] = aHold;
    aHold = mData[11]; mData[11] = mData[30]; mData[30] = mData[52]; mData[52] = mData[33]; mData[33] = aHold;
    aHold = mData[12]; mData[12] = mData[38]; mData[38] = mData[51]; mData[51] = mData[25]; mData[25] = aHold;
    aHold = mData[13]; mData[13] = mData[46]; mData[46] = mData[50]; mData[50] = mData[17]; mData[17] = aHold;
    aHold = mData[18]; mData[18] = mData[42]; mData[42] = mData[45]; mData[45] = mData[21]; mData[21] = aHold;
    aHold = mData[19]; mData[19] = mData[34]; mData[34] = mData[44]; mData[44] = mData[29]; mData[29] = aHold;
    aHold = mData[20]; mData[20] = mData[26]; mData[26] = mData[43]; mData[43] = mData[37]; mData[37] = aHold;
    aHold = mData[27]; mData[27] = mData[28]; mData[28] = mData[36]; mData[36] = mData[35]; mData[35] = aHold;
}


void M88::Full_PinB_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[6]; mData[6] = mData[54]; mData[54] = mData[48]; mData[48] = aHold;
    aHold = mData[1]; mData[1] = mData[7]; mData[7] = mData[55]; mData[55] = mData[49]; mData[49] = aHold;
    aHold = mData[2]; mData[2] = mData[22]; mData[22] = mData[52]; mData[52] = mData[32]; mData[32] = aHold;
    aHold = mData[3]; mData[3] = mData[23]; mData[23] = mData[53]; mData[53] = mData[33]; mData[33] = aHold;
    aHold = mData[4]; mData[4] = mData[38]; mData[38] = mData[50]; mData[50] = mData[16]; mData[16] = aHold;
    aHold = mData[5]; mData[5] = mData[39]; mData[39] = mData[51]; mData[51] = mData[17]; mData[17] = aHold;
    aHold = mData[8]; mData[8] = mData[14]; mData[14] = mData[62]; mData[62] = mData[56]; mData[56] = aHold;
    aHold = mData[9]; mData[9] = mData[15]; mData[15] = mData[63]; mData[63] = mData[57]; mData[57] = aHold;
    aHold = mData[10]; mData[10] = mData[30]; mData[30] = mData[60]; mData[60] = mData[40]; mData[40] = aHold;
    aHold = mData[11]; mData[11] = mData[31]; mData[31] = mData[61]; mData[61] = mData[41]; mData[41] = aHold;
    aHold = mData[12]; mData[12] = mData[46]; mData[46] = mData[58]; mData[58] = mData[24]; mData[24] = aHold;
    aHold = mData[13]; mData[13] = mData[47]; mData[47] = mData[59]; mData[59] = mData[25]; mData[25] = aHold;
    aHold = mData[18]; mData[18] = mData[34]; mData[34] = mData[36]; mData[36] = mData[20]; mData[20] = aHold;
    aHold = mData[19]; mData[19] = mData[35]; mData[35] = mData[37]; mData[37] = mData[21]; mData[21] = aHold;
    aHold = mData[26]; mData[26] = mData[42]; mData[42] = mData[44]; mData[44] = mData[28]; mData[28] = aHold;
    aHold = mData[27]; mData[27] = mData[43]; mData[43] = mData[45]; mData[45] = mData[29]; mData[29] = aHold;
}

void M88::Full_PinB_EachQuad_4x4() {
    Quad_PinB_4x4_A();
    Quad_PinB_4x4_B();
    Quad_PinB_4x4_C();
    Quad_PinB_4x4_D();
}

void M88::Quad_PinB_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[3]; mData[3] = mData[27]; mData[27] = mData[24]; mData[24] = aHold;
    aHold = mData[1]; mData[1] = mData[11]; mData[11] = mData[26]; mData[26] = mData[16]; mData[16] = aHold;
    aHold = mData[2]; mData[2] = mData[19]; mData[19] = mData[25]; mData[25] = mData[8]; mData[8] = aHold;
    aHold = mData[9]; mData[9] = mData[17]; mData[17] = mData[18]; mData[18] = mData[10]; mData[10] = aHold;
}

void M88::Quad_PinB_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[7]; mData[7] = mData[31]; mData[31] = mData[28]; mData[28] = aHold;
    aHold = mData[5]; mData[5] = mData[15]; mData[15] = mData[30]; mData[30] = mData[20]; mData[20] = aHold;
    aHold = mData[6]; mData[6] = mData[23]; mData[23] = mData[29]; mData[29] = mData[12]; mData[12] = aHold;
    aHold = mData[13]; mData[13] = mData[21]; mData[21] = mData[22]; mData[22] = mData[14]; mData[14] = aHold;
}

void M88::Quad_PinB_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[35]; mData[35] = mData[59]; mData[59] = mData[56]; mData[56] = aHold;
    aHold = mData[33]; mData[33] = mData[43]; mData[43] = mData[58]; mData[58] = mData[48]; mData[48] = aHold;
    aHold = mData[34]; mData[34] = mData[51]; mData[51] = mData[57]; mData[57] = mData[40]; mData[40] = aHold;
    aHold = mData[41]; mData[41] = mData[49]; mData[49] = mData[50]; mData[50] = mData[42]; mData[42] = aHold;
}

void M88::Quad_PinB_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[39]; mData[39] = mData[63]; mData[63] = mData[60]; mData[60] = aHold;
    aHold = mData[37]; mData[37] = mData[47]; mData[47] = mData[62]; mData[62] = mData[52]; mData[52] = aHold;
    aHold = mData[38]; mData[38] = mData[55]; mData[55] = mData[61]; mData[61] = mData[44]; mData[44] = aHold;
    aHold = mData[45]; mData[45] = mData[53]; mData[53] = mData[54]; mData[54] = mData[46]; mData[46] = aHold;
}


void M88::Full_PinB_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[7]; mData[7] = mData[63]; mData[63] = mData[56]; mData[56] = aHold;
    aHold = mData[1]; mData[1] = mData[15]; mData[15] = mData[62]; mData[62] = mData[48]; mData[48] = aHold;
    aHold = mData[2]; mData[2] = mData[23]; mData[23] = mData[61]; mData[61] = mData[40]; mData[40] = aHold;
    aHold = mData[3]; mData[3] = mData[31]; mData[31] = mData[60]; mData[60] = mData[32]; mData[32] = aHold;
    aHold = mData[4]; mData[4] = mData[39]; mData[39] = mData[59]; mData[59] = mData[24]; mData[24] = aHold;
    aHold = mData[5]; mData[5] = mData[47]; mData[47] = mData[58]; mData[58] = mData[16]; mData[16] = aHold;
    aHold = mData[6]; mData[6] = mData[55]; mData[55] = mData[57]; mData[57] = mData[8]; mData[8] = aHold;
    aHold = mData[9]; mData[9] = mData[49]; mData[49] = mData[54]; mData[54] = mData[14]; mData[14] = aHold;
    aHold = mData[10]; mData[10] = mData[41]; mData[41] = mData[53]; mData[53] = mData[22]; mData[22] = aHold;
    aHold = mData[11]; mData[11] = mData[33]; mData[33] = mData[52]; mData[52] = mData[30]; mData[30] = aHold;
    aHold = mData[12]; mData[12] = mData[25]; mData[25] = mData[51]; mData[51] = mData[38]; mData[38] = aHold;
    aHold = mData[13]; mData[13] = mData[17]; mData[17] = mData[50]; mData[50] = mData[46]; mData[46] = aHold;
    aHold = mData[18]; mData[18] = mData[21]; mData[21] = mData[45]; mData[45] = mData[42]; mData[42] = aHold;
    aHold = mData[19]; mData[19] = mData[29]; mData[29] = mData[44]; mData[44] = mData[34]; mData[34] = aHold;
    aHold = mData[20]; mData[20] = mData[37]; mData[37] = mData[43]; mData[43] = mData[26]; mData[26] = aHold;
    aHold = mData[27]; mData[27] = mData[35]; mData[35] = mData[36]; mData[36] = mData[28]; mData[28] = aHold;
}


void M88::Full_SwapA_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = aHold;
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = aHold;
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = aHold;
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = aHold;
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = aHold;
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = aHold;
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = aHold;
}

void M88::Full_SwapA_EachQuad_2x2() {
    Quad_SwapA_2x2_A();
    Quad_SwapA_2x2_B();
    Quad_SwapA_2x2_C();
    Quad_SwapA_2x2_D();
}

void M88::Full_SwapA_EachMini_2x2() {
    Mini_SwapA_2x2_A();
    Mini_SwapA_2x2_B();
    Mini_SwapA_2x2_C();
    Mini_SwapA_2x2_D();
    Mini_SwapA_2x2_E();
    Mini_SwapA_2x2_F();
    Mini_SwapA_2x2_G();
    Mini_SwapA_2x2_H();
    Mini_SwapA_2x2_I();
    Mini_SwapA_2x2_J();
    Mini_SwapA_2x2_K();
    Mini_SwapA_2x2_L();
    Mini_SwapA_2x2_M();
    Mini_SwapA_2x2_N();
    Mini_SwapA_2x2_O();
    Mini_SwapA_2x2_P();
}

void M88::Quad_SwapA_EachMini_2x2_A() {
    Mini_SwapA_2x2_A();
    Mini_SwapA_2x2_B();
    Mini_SwapA_2x2_E();
    Mini_SwapA_2x2_F();
}

void M88::Quad_SwapA_EachMini_2x2_B() {
    Mini_SwapA_2x2_C();
    Mini_SwapA_2x2_D();
    Mini_SwapA_2x2_G();
    Mini_SwapA_2x2_H();
}

void M88::Quad_SwapA_EachMini_2x2_C() {
    Mini_SwapA_2x2_I();
    Mini_SwapA_2x2_J();
    Mini_SwapA_2x2_M();
    Mini_SwapA_2x2_N();
}

void M88::Quad_SwapA_EachMini_2x2_D() {
    Mini_SwapA_2x2_K();
    Mini_SwapA_2x2_L();
    Mini_SwapA_2x2_O();
    Mini_SwapA_2x2_P();
}

void M88::Quad_SwapA_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = aHold;
}

void M88::Quad_SwapA_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = aHold;
}

void M88::Quad_SwapA_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = aHold;
}

void M88::Quad_SwapA_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = aHold;
}

void M88::Mini_SwapA_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = aHold;
}

void M88::Mini_SwapA_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = aHold;
}

void M88::Mini_SwapA_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = aHold;
}

void M88::Mini_SwapA_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = aHold;
}

void M88::Mini_SwapA_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = aHold;
}

void M88::Mini_SwapA_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = aHold;
}

void M88::Mini_SwapA_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = aHold;
}

void M88::Mini_SwapA_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = aHold;
}

void M88::Mini_SwapA_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = aHold;
}

void M88::Mini_SwapA_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = aHold;
}

void M88::Mini_SwapA_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = aHold;
}

void M88::Mini_SwapA_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = aHold;
}

void M88::Mini_SwapA_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = aHold;
}

void M88::Mini_SwapA_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = aHold;
}

void M88::Mini_SwapA_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = aHold;
}

void M88::Mini_SwapA_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = aHold;
}


void M88::Full_SwapB_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = aHold;
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = aHold;
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = aHold;
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = aHold;
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = aHold;
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = aHold;
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = aHold;
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = aHold;
}

void M88::Full_SwapB_EachQuad_2x2() {
    Quad_SwapB_2x2_A();
    Quad_SwapB_2x2_B();
    Quad_SwapB_2x2_C();
    Quad_SwapB_2x2_D();
}

void M88::Full_SwapB_EachMini_2x2() {
    Mini_SwapB_2x2_A();
    Mini_SwapB_2x2_B();
    Mini_SwapB_2x2_C();
    Mini_SwapB_2x2_D();
    Mini_SwapB_2x2_E();
    Mini_SwapB_2x2_F();
    Mini_SwapB_2x2_G();
    Mini_SwapB_2x2_H();
    Mini_SwapB_2x2_I();
    Mini_SwapB_2x2_J();
    Mini_SwapB_2x2_K();
    Mini_SwapB_2x2_L();
    Mini_SwapB_2x2_M();
    Mini_SwapB_2x2_N();
    Mini_SwapB_2x2_O();
    Mini_SwapB_2x2_P();
}

void M88::Quad_SwapB_EachMini_2x2_A() {
    Mini_SwapB_2x2_A();
    Mini_SwapB_2x2_B();
    Mini_SwapB_2x2_E();
    Mini_SwapB_2x2_F();
}

void M88::Quad_SwapB_EachMini_2x2_B() {
    Mini_SwapB_2x2_C();
    Mini_SwapB_2x2_D();
    Mini_SwapB_2x2_G();
    Mini_SwapB_2x2_H();
}

void M88::Quad_SwapB_EachMini_2x2_C() {
    Mini_SwapB_2x2_I();
    Mini_SwapB_2x2_J();
    Mini_SwapB_2x2_M();
    Mini_SwapB_2x2_N();
}

void M88::Quad_SwapB_EachMini_2x2_D() {
    Mini_SwapB_2x2_K();
    Mini_SwapB_2x2_L();
    Mini_SwapB_2x2_O();
    Mini_SwapB_2x2_P();
}

void M88::Quad_SwapB_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = aHold;
}

void M88::Quad_SwapB_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = aHold;
}

void M88::Quad_SwapB_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = aHold;
}

void M88::Quad_SwapB_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = aHold;
}

void M88::Mini_SwapB_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = aHold;
}

void M88::Mini_SwapB_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = aHold;
}

void M88::Mini_SwapB_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = aHold;
}

void M88::Mini_SwapB_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = aHold;
}

void M88::Mini_SwapB_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = aHold;
}

void M88::Mini_SwapB_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = aHold;
}

void M88::Mini_SwapB_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = aHold;
}

void M88::Mini_SwapB_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = aHold;
}

void M88::Mini_SwapB_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = aHold;
}

void M88::Mini_SwapB_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = aHold;
}

void M88::Mini_SwapB_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = aHold;
}

void M88::Mini_SwapB_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = aHold;
}

void M88::Mini_SwapB_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = aHold;
}

void M88::Mini_SwapB_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = aHold;
}

void M88::Mini_SwapB_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = aHold;
}

void M88::Mini_SwapB_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = aHold;
}




void M88::Full_SwapC_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[36]; mData[36] = aHold;
    aHold = mData[5]; mData[5] = mData[37]; mData[37] = aHold;
    aHold = mData[6]; mData[6] = mData[38]; mData[38] = aHold;
    aHold = mData[7]; mData[7] = mData[39]; mData[39] = aHold;
    aHold = mData[12]; mData[12] = mData[44]; mData[44] = aHold;
    aHold = mData[13]; mData[13] = mData[45]; mData[45] = aHold;
    aHold = mData[14]; mData[14] = mData[46]; mData[46] = aHold;
    aHold = mData[15]; mData[15] = mData[47]; mData[47] = aHold;
    aHold = mData[20]; mData[20] = mData[52]; mData[52] = aHold;
    aHold = mData[21]; mData[21] = mData[53]; mData[53] = aHold;
    aHold = mData[22]; mData[22] = mData[54]; mData[54] = aHold;
    aHold = mData[23]; mData[23] = mData[55]; mData[55] = aHold;
    aHold = mData[28]; mData[28] = mData[60]; mData[60] = aHold;
    aHold = mData[29]; mData[29] = mData[61]; mData[61] = aHold;
    aHold = mData[30]; mData[30] = mData[62]; mData[62] = aHold;
    aHold = mData[31]; mData[31] = mData[63]; mData[63] = aHold;
}

void M88::Full_SwapC_EachQuad_2x2() {
    Quad_SwapC_2x2_A();
    Quad_SwapC_2x2_B();
    Quad_SwapC_2x2_C();
    Quad_SwapC_2x2_D();
}

void M88::Full_SwapC_EachMini_2x2() {
    Mini_SwapC_2x2_A();
    Mini_SwapC_2x2_B();
    Mini_SwapC_2x2_C();
    Mini_SwapC_2x2_D();
    Mini_SwapC_2x2_E();
    Mini_SwapC_2x2_F();
    Mini_SwapC_2x2_G();
    Mini_SwapC_2x2_H();
    Mini_SwapC_2x2_I();
    Mini_SwapC_2x2_J();
    Mini_SwapC_2x2_K();
    Mini_SwapC_2x2_L();
    Mini_SwapC_2x2_M();
    Mini_SwapC_2x2_N();
    Mini_SwapC_2x2_O();
    Mini_SwapC_2x2_P();
}

void M88::Quad_SwapC_EachMini_2x2_A() {
    Mini_SwapC_2x2_A();
    Mini_SwapC_2x2_B();
    Mini_SwapC_2x2_E();
    Mini_SwapC_2x2_F();
}

void M88::Quad_SwapC_EachMini_2x2_B() {
    Mini_SwapC_2x2_C();
    Mini_SwapC_2x2_D();
    Mini_SwapC_2x2_G();
    Mini_SwapC_2x2_H();
}

void M88::Quad_SwapC_EachMini_2x2_C() {
    Mini_SwapC_2x2_I();
    Mini_SwapC_2x2_J();
    Mini_SwapC_2x2_M();
    Mini_SwapC_2x2_N();
}

void M88::Quad_SwapC_EachMini_2x2_D() {
    Mini_SwapC_2x2_K();
    Mini_SwapC_2x2_L();
    Mini_SwapC_2x2_O();
    Mini_SwapC_2x2_P();
}

void M88::Quad_SwapC_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[19]; mData[19] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[27]; mData[27] = aHold;
}

void M88::Quad_SwapC_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[23]; mData[23] = aHold;
    aHold = mData[14]; mData[14] = mData[30]; mData[30] = aHold;
    aHold = mData[15]; mData[15] = mData[31]; mData[31] = aHold;
}

void M88::Quad_SwapC_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
}

void M88::Quad_SwapC_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
}

void M88::Mini_SwapC_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[1]; mData[1] = mData[9]; mData[9] = aHold;
}

void M88::Mini_SwapC_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[3]; mData[3] = mData[11]; mData[11] = aHold;
}

void M88::Mini_SwapC_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[5]; mData[5] = mData[13]; mData[13] = aHold;
}

void M88::Mini_SwapC_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[7]; mData[7] = mData[15]; mData[15] = aHold;
}

void M88::Mini_SwapC_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[17]; mData[17] = mData[25]; mData[25] = aHold;
}

void M88::Mini_SwapC_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[19]; mData[19] = mData[27]; mData[27] = aHold;
}

void M88::Mini_SwapC_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[21]; mData[21] = mData[29]; mData[29] = aHold;
}

void M88::Mini_SwapC_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[23]; mData[23] = mData[31]; mData[31] = aHold;
}

void M88::Mini_SwapC_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[33]; mData[33] = mData[41]; mData[41] = aHold;
}

void M88::Mini_SwapC_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[35]; mData[35] = mData[43]; mData[43] = aHold;
}

void M88::Mini_SwapC_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[37]; mData[37] = mData[45]; mData[45] = aHold;
}

void M88::Mini_SwapC_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[39]; mData[39] = mData[47]; mData[47] = aHold;
}

void M88::Mini_SwapC_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[49]; mData[49] = mData[57]; mData[57] = aHold;
}

void M88::Mini_SwapC_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[51]; mData[51] = mData[59]; mData[59] = aHold;
}

void M88::Mini_SwapC_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[53]; mData[53] = mData[61]; mData[61] = aHold;
}

void M88::Mini_SwapC_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[55]; mData[55] = mData[63]; mData[63] = aHold;
}



void M88::Full_SwapD_2x2() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[36]; mData[36] = aHold;
    aHold = mData[33]; mData[33] = mData[37]; mData[37] = aHold;
    aHold = mData[34]; mData[34] = mData[38]; mData[38] = aHold;
    aHold = mData[35]; mData[35] = mData[39]; mData[39] = aHold;
    aHold = mData[40]; mData[40] = mData[44]; mData[44] = aHold;
    aHold = mData[41]; mData[41] = mData[45]; mData[45] = aHold;
    aHold = mData[42]; mData[42] = mData[46]; mData[46] = aHold;
    aHold = mData[43]; mData[43] = mData[47]; mData[47] = aHold;
    aHold = mData[48]; mData[48] = mData[52]; mData[52] = aHold;
    aHold = mData[49]; mData[49] = mData[53]; mData[53] = aHold;
    aHold = mData[50]; mData[50] = mData[54]; mData[54] = aHold;
    aHold = mData[51]; mData[51] = mData[55]; mData[55] = aHold;
    aHold = mData[56]; mData[56] = mData[60]; mData[60] = aHold;
    aHold = mData[57]; mData[57] = mData[61]; mData[61] = aHold;
    aHold = mData[58]; mData[58] = mData[62]; mData[62] = aHold;
    aHold = mData[59]; mData[59] = mData[63]; mData[63] = aHold;
}

void M88::Full_SwapD_EachQuad_2x2() {
    Quad_SwapD_2x2_A();
    Quad_SwapD_2x2_B();
    Quad_SwapD_2x2_C();
    Quad_SwapD_2x2_D();
}

void M88::Full_SwapD_EachMini_2x2() {
    Mini_SwapD_2x2_A();
    Mini_SwapD_2x2_B();
    Mini_SwapD_2x2_C();
    Mini_SwapD_2x2_D();
    Mini_SwapD_2x2_E();
    Mini_SwapD_2x2_F();
    Mini_SwapD_2x2_G();
    Mini_SwapD_2x2_H();
    Mini_SwapD_2x2_I();
    Mini_SwapD_2x2_J();
    Mini_SwapD_2x2_K();
    Mini_SwapD_2x2_L();
    Mini_SwapD_2x2_M();
    Mini_SwapD_2x2_N();
    Mini_SwapD_2x2_O();
    Mini_SwapD_2x2_P();
}

void M88::Quad_SwapD_EachMini_2x2_A() {
    Mini_SwapD_2x2_A();
    Mini_SwapD_2x2_B();
    Mini_SwapD_2x2_E();
    Mini_SwapD_2x2_F();
}

void M88::Quad_SwapD_EachMini_2x2_B() {
    Mini_SwapD_2x2_C();
    Mini_SwapD_2x2_D();
    Mini_SwapD_2x2_G();
    Mini_SwapD_2x2_H();
}

void M88::Quad_SwapD_EachMini_2x2_C() {
    Mini_SwapD_2x2_I();
    Mini_SwapD_2x2_J();
    Mini_SwapD_2x2_M();
    Mini_SwapD_2x2_N();
}

void M88::Quad_SwapD_EachMini_2x2_D() {
    Mini_SwapD_2x2_K();
    Mini_SwapD_2x2_L();
    Mini_SwapD_2x2_O();
    Mini_SwapD_2x2_P();
}

void M88::Quad_SwapD_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
    aHold = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
}

void M88::Quad_SwapD_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
}

void M88::Quad_SwapD_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
    aHold = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
}

void M88::Quad_SwapD_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
    aHold = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}

void M88::Mini_SwapD_2x2_A() {
    std::uint8_t aHold = 0;
    aHold = mData[8]; mData[8] = mData[9]; mData[9] = aHold;
}

void M88::Mini_SwapD_2x2_B() {
    std::uint8_t aHold = 0;
    aHold = mData[10]; mData[10] = mData[11]; mData[11] = aHold;
}

void M88::Mini_SwapD_2x2_C() {
    std::uint8_t aHold = 0;
    aHold = mData[12]; mData[12] = mData[13]; mData[13] = aHold;
}

void M88::Mini_SwapD_2x2_D() {
    std::uint8_t aHold = 0;
    aHold = mData[14]; mData[14] = mData[15]; mData[15] = aHold;
}

void M88::Mini_SwapD_2x2_E() {
    std::uint8_t aHold = 0;
    aHold = mData[24]; mData[24] = mData[25]; mData[25] = aHold;
}

void M88::Mini_SwapD_2x2_F() {
    std::uint8_t aHold = 0;
    aHold = mData[26]; mData[26] = mData[27]; mData[27] = aHold;
}

void M88::Mini_SwapD_2x2_G() {
    std::uint8_t aHold = 0;
    aHold = mData[28]; mData[28] = mData[29]; mData[29] = aHold;
}

void M88::Mini_SwapD_2x2_H() {
    std::uint8_t aHold = 0;
    aHold = mData[30]; mData[30] = mData[31]; mData[31] = aHold;
}

void M88::Mini_SwapD_2x2_I() {
    std::uint8_t aHold = 0;
    aHold = mData[40]; mData[40] = mData[41]; mData[41] = aHold;
}

void M88::Mini_SwapD_2x2_J() {
    std::uint8_t aHold = 0;
    aHold = mData[42]; mData[42] = mData[43]; mData[43] = aHold;
}

void M88::Mini_SwapD_2x2_K() {
    std::uint8_t aHold = 0;
    aHold = mData[44]; mData[44] = mData[45]; mData[45] = aHold;
}

void M88::Mini_SwapD_2x2_L() {
    std::uint8_t aHold = 0;
    aHold = mData[46]; mData[46] = mData[47]; mData[47] = aHold;
}

void M88::Mini_SwapD_2x2_M() {
    std::uint8_t aHold = 0;
    aHold = mData[56]; mData[56] = mData[57]; mData[57] = aHold;
}

void M88::Mini_SwapD_2x2_N() {
    std::uint8_t aHold = 0;
    aHold = mData[58]; mData[58] = mData[59]; mData[59] = aHold;
}

void M88::Mini_SwapD_2x2_O() {
    std::uint8_t aHold = 0;
    aHold = mData[60]; mData[60] = mData[61]; mData[61] = aHold;
}

void M88::Mini_SwapD_2x2_P() {
    std::uint8_t aHold = 0;
    aHold = mData[62]; mData[62] = mData[63]; mData[63] = aHold;
}




void M88::Full_ReachA_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = aHold;
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = aHold;
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = aHold;
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = aHold;
    aHold = mData[34]; mData[34] = mData[38]; mData[38] = aHold;
    aHold = mData[35]; mData[35] = mData[39]; mData[39] = aHold;
    aHold = mData[42]; mData[42] = mData[46]; mData[46] = aHold;
    aHold = mData[43]; mData[43] = mData[47]; mData[47] = aHold;
    aHold = mData[50]; mData[50] = mData[54]; mData[54] = aHold;
    aHold = mData[51]; mData[51] = mData[55]; mData[55] = aHold;
    aHold = mData[58]; mData[58] = mData[62]; mData[62] = aHold;
    aHold = mData[59]; mData[59] = mData[63]; mData[63] = aHold;
}

void M88::Full_ReachA_EachQuad_4x4() {
    Quad_ReachA_4x4_A();
    Quad_ReachA_4x4_B();
    Quad_ReachA_4x4_C();
    Quad_ReachA_4x4_D();
}

void M88::Quad_ReachA_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = aHold;
    aHold = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
}

void M88::Quad_ReachA_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = aHold;
    aHold = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
}

void M88::Quad_ReachA_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = aHold;
    aHold = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
}

void M88::Quad_ReachA_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = aHold;
    aHold = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}

void M88::Full_ReachB_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = aHold;
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = aHold;
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = aHold;
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[36]; mData[36] = aHold;
    aHold = mData[33]; mData[33] = mData[37]; mData[37] = aHold;
    aHold = mData[40]; mData[40] = mData[44]; mData[44] = aHold;
    aHold = mData[41]; mData[41] = mData[45]; mData[45] = aHold;
    aHold = mData[48]; mData[48] = mData[52]; mData[52] = aHold;
    aHold = mData[49]; mData[49] = mData[53]; mData[53] = aHold;
    aHold = mData[56]; mData[56] = mData[60]; mData[60] = aHold;
    aHold = mData[57]; mData[57] = mData[61]; mData[61] = aHold;
}

void M88::Full_ReachB_EachQuad_4x4() {
    Quad_ReachB_4x4_A();
    Quad_ReachB_4x4_B();
    Quad_ReachB_4x4_C();
    Quad_ReachB_4x4_D();
}

void M88::Quad_ReachB_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
}

void M88::Quad_ReachB_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = aHold;
    aHold = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
}

void M88::Quad_ReachB_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
}

void M88::Quad_ReachB_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = aHold;
    aHold = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
}

void M88::Full_ReachC_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = aHold;
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = aHold;
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = aHold;
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = aHold;
    aHold = mData[20]; mData[20] = mData[52]; mData[52] = aHold;
    aHold = mData[21]; mData[21] = mData[53]; mData[53] = aHold;
    aHold = mData[22]; mData[22] = mData[54]; mData[54] = aHold;
    aHold = mData[23]; mData[23] = mData[55]; mData[55] = aHold;
    aHold = mData[28]; mData[28] = mData[60]; mData[60] = aHold;
    aHold = mData[29]; mData[29] = mData[61]; mData[61] = aHold;
    aHold = mData[30]; mData[30] = mData[62]; mData[62] = aHold;
    aHold = mData[31]; mData[31] = mData[63]; mData[63] = aHold;
}

void M88::Full_ReachC_EachQuad_4x4() {
    Quad_ReachC_4x4_A();
    Quad_ReachC_4x4_B();
    Quad_ReachC_4x4_C();
    Quad_ReachC_4x4_D();
}

void M88::Quad_ReachC_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[27]; mData[27] = aHold;
}

void M88::Quad_ReachC_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = aHold;
    aHold = mData[14]; mData[14] = mData[30]; mData[30] = aHold;
    aHold = mData[15]; mData[15] = mData[31]; mData[31] = aHold;
}

void M88::Quad_ReachC_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = aHold;
    aHold = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
}

void M88::Quad_ReachC_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = aHold;
    aHold = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
}

void M88::Full_ReachD_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[36]; mData[36] = aHold;
    aHold = mData[5]; mData[5] = mData[37]; mData[37] = aHold;
    aHold = mData[6]; mData[6] = mData[38]; mData[38] = aHold;
    aHold = mData[7]; mData[7] = mData[39]; mData[39] = aHold;
    aHold = mData[12]; mData[12] = mData[44]; mData[44] = aHold;
    aHold = mData[13]; mData[13] = mData[45]; mData[45] = aHold;
    aHold = mData[14]; mData[14] = mData[46]; mData[46] = aHold;
    aHold = mData[15]; mData[15] = mData[47]; mData[47] = aHold;
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = aHold;
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = aHold;
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = aHold;
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = aHold;
}

void M88::Full_ReachD_EachQuad_4x4() {
    Quad_ReachD_4x4_A();
    Quad_ReachD_4x4_B();
    Quad_ReachD_4x4_C();
    Quad_ReachD_4x4_D();
}

void M88::Quad_ReachD_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[19]; mData[19] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = aHold;
}

void M88::Quad_ReachD_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[6]; mData[6] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[23]; mData[23] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = aHold;
}

void M88::Quad_ReachD_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = aHold;
}

void M88::Quad_ReachD_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = aHold;
}


void M88::Full_ReachA_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = aHold;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = aHold;
    aHold = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
    aHold = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = aHold;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = aHold;
    aHold = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
    aHold = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}


void M88::Full_ReachB_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
    aHold = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = aHold;
    aHold = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
    aHold = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
}

void M88::Full_ReachC_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = aHold;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[27]; mData[27] = aHold;
    aHold = mData[14]; mData[14] = mData[30]; mData[30] = aHold;
    aHold = mData[15]; mData[15] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = aHold;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = aHold;
    aHold = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
    aHold = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
}

void M88::Full_ReachD_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[19]; mData[19] = aHold;
    aHold = mData[6]; mData[6] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[23]; mData[23] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = aHold;
    aHold = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = aHold;
}

void M88::Full_SwapRows_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = aHold;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[19]; mData[19] = aHold;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = aHold;
    aHold = mData[6]; mData[6] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[23]; mData[23] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[27]; mData[27] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = aHold;
    aHold = mData[14]; mData[14] = mData[30]; mData[30] = aHold;
    aHold = mData[15]; mData[15] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = aHold;
    aHold = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = aHold;
    aHold = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = aHold;
    aHold = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = aHold;
    aHold = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
}

void M88::Full_SwapRows_EachQuad_4x4() {
    Quad_SwapRows_4x4_A();
    Quad_SwapRows_4x4_B();
    Quad_SwapRows_4x4_C();
    Quad_SwapRows_4x4_D();
}

void M88::Quad_SwapRows_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = aHold;
    aHold = mData[1]; mData[1] = mData[9]; mData[9] = aHold;
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = aHold;
    aHold = mData[3]; mData[3] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = aHold;
    aHold = mData[17]; mData[17] = mData[25]; mData[25] = aHold;
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = aHold;
    aHold = mData[19]; mData[19] = mData[27]; mData[27] = aHold;
}

void M88::Quad_SwapRows_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = aHold;
    aHold = mData[5]; mData[5] = mData[13]; mData[13] = aHold;
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = aHold;
    aHold = mData[7]; mData[7] = mData[15]; mData[15] = aHold;
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = aHold;
    aHold = mData[21]; mData[21] = mData[29]; mData[29] = aHold;
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = aHold;
    aHold = mData[23]; mData[23] = mData[31]; mData[31] = aHold;
}

void M88::Quad_SwapRows_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = aHold;
    aHold = mData[33]; mData[33] = mData[41]; mData[41] = aHold;
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = aHold;
    aHold = mData[35]; mData[35] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = aHold;
    aHold = mData[49]; mData[49] = mData[57]; mData[57] = aHold;
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = aHold;
    aHold = mData[51]; mData[51] = mData[59]; mData[59] = aHold;
}

void M88::Quad_SwapRows_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = aHold;
    aHold = mData[37]; mData[37] = mData[45]; mData[45] = aHold;
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = aHold;
    aHold = mData[39]; mData[39] = mData[47]; mData[47] = aHold;
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = aHold;
    aHold = mData[53]; mData[53] = mData[61]; mData[61] = aHold;
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = aHold;
    aHold = mData[55]; mData[55] = mData[63]; mData[63] = aHold;
}

void M88::Full_SwapRows_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = aHold;
    aHold = mData[1]; mData[1] = mData[9]; mData[9] = aHold;
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = aHold;
    aHold = mData[3]; mData[3] = mData[11]; mData[11] = aHold;
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = aHold;
    aHold = mData[5]; mData[5] = mData[13]; mData[13] = aHold;
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = aHold;
    aHold = mData[7]; mData[7] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = aHold;
    aHold = mData[17]; mData[17] = mData[25]; mData[25] = aHold;
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = aHold;
    aHold = mData[19]; mData[19] = mData[27]; mData[27] = aHold;
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = aHold;
    aHold = mData[21]; mData[21] = mData[29]; mData[29] = aHold;
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = aHold;
    aHold = mData[23]; mData[23] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = aHold;
    aHold = mData[33]; mData[33] = mData[41]; mData[41] = aHold;
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = aHold;
    aHold = mData[35]; mData[35] = mData[43]; mData[43] = aHold;
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = aHold;
    aHold = mData[37]; mData[37] = mData[45]; mData[45] = aHold;
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = aHold;
    aHold = mData[39]; mData[39] = mData[47]; mData[47] = aHold;
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = aHold;
    aHold = mData[49]; mData[49] = mData[57]; mData[57] = aHold;
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = aHold;
    aHold = mData[51]; mData[51] = mData[59]; mData[59] = aHold;
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = aHold;
    aHold = mData[53]; mData[53] = mData[61]; mData[61] = aHold;
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = aHold;
    aHold = mData[55]; mData[55] = mData[63]; mData[63] = aHold;
}

void M88::Full_SwapColums_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = aHold;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
    aHold = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
    aHold = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = aHold;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = aHold;
    aHold = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
    aHold = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
    aHold = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
    aHold = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}

void M88::Full_SwapColums_EachQuad_4x4() {
    Quad_SwapColums_4x4_A();
    Quad_SwapColums_4x4_B();
    Quad_SwapColums_4x4_C();
    Quad_SwapColums_4x4_D();
}

void M88::Quad_SwapColums_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = aHold;
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[9]; mData[9] = aHold;
    aHold = mData[10]; mData[10] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = aHold;
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = aHold;
    aHold = mData[24]; mData[24] = mData[25]; mData[25] = aHold;
    aHold = mData[26]; mData[26] = mData[27]; mData[27] = aHold;
}

void M88::Quad_SwapColums_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = aHold;
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = aHold;
    aHold = mData[12]; mData[12] = mData[13]; mData[13] = aHold;
    aHold = mData[14]; mData[14] = mData[15]; mData[15] = aHold;
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = aHold;
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = aHold;
    aHold = mData[28]; mData[28] = mData[29]; mData[29] = aHold;
    aHold = mData[30]; mData[30] = mData[31]; mData[31] = aHold;
}

void M88::Quad_SwapColums_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = aHold;
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[41]; mData[41] = aHold;
    aHold = mData[42]; mData[42] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = aHold;
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = aHold;
    aHold = mData[56]; mData[56] = mData[57]; mData[57] = aHold;
    aHold = mData[58]; mData[58] = mData[59]; mData[59] = aHold;
}

void M88::Quad_SwapColums_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = aHold;
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = aHold;
    aHold = mData[44]; mData[44] = mData[45]; mData[45] = aHold;
    aHold = mData[46]; mData[46] = mData[47]; mData[47] = aHold;
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = aHold;
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = aHold;
    aHold = mData[60]; mData[60] = mData[61]; mData[61] = aHold;
    aHold = mData[62]; mData[62] = mData[63]; mData[63] = aHold;
}

void M88::Full_SwapColums_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = aHold;
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = aHold;
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = aHold;
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[9]; mData[9] = aHold;
    aHold = mData[10]; mData[10] = mData[11]; mData[11] = aHold;
    aHold = mData[12]; mData[12] = mData[13]; mData[13] = aHold;
    aHold = mData[14]; mData[14] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = aHold;
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = aHold;
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = aHold;
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[25]; mData[25] = aHold;
    aHold = mData[26]; mData[26] = mData[27]; mData[27] = aHold;
    aHold = mData[28]; mData[28] = mData[29]; mData[29] = aHold;
    aHold = mData[30]; mData[30] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = aHold;
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = aHold;
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = aHold;
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = aHold;
    aHold = mData[40]; mData[40] = mData[41]; mData[41] = aHold;
    aHold = mData[42]; mData[42] = mData[43]; mData[43] = aHold;
    aHold = mData[44]; mData[44] = mData[45]; mData[45] = aHold;
    aHold = mData[46]; mData[46] = mData[47]; mData[47] = aHold;
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = aHold;
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = aHold;
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = aHold;
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = aHold;
    aHold = mData[56]; mData[56] = mData[57]; mData[57] = aHold;
    aHold = mData[58]; mData[58] = mData[59]; mData[59] = aHold;
    aHold = mData[60]; mData[60] = mData[61]; mData[61] = aHold;
    aHold = mData[62]; mData[62] = mData[63]; mData[63] = aHold;
}

void M88::Full_SwapBoth_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[18]; mData[18] = aHold;
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = aHold;
    aHold = mData[2]; mData[2] = mData[16]; mData[16] = aHold;
    aHold = mData[3]; mData[3] = mData[17]; mData[17] = aHold;
    aHold = mData[4]; mData[4] = mData[22]; mData[22] = aHold;
    aHold = mData[5]; mData[5] = mData[23]; mData[23] = aHold;
    aHold = mData[6]; mData[6] = mData[20]; mData[20] = aHold;
    aHold = mData[7]; mData[7] = mData[21]; mData[21] = aHold;
    aHold = mData[8]; mData[8] = mData[26]; mData[26] = aHold;
    aHold = mData[9]; mData[9] = mData[27]; mData[27] = aHold;
    aHold = mData[10]; mData[10] = mData[24]; mData[24] = aHold;
    aHold = mData[11]; mData[11] = mData[25]; mData[25] = aHold;
    aHold = mData[12]; mData[12] = mData[30]; mData[30] = aHold;
    aHold = mData[13]; mData[13] = mData[31]; mData[31] = aHold;
    aHold = mData[14]; mData[14] = mData[28]; mData[28] = aHold;
    aHold = mData[15]; mData[15] = mData[29]; mData[29] = aHold;
    aHold = mData[32]; mData[32] = mData[50]; mData[50] = aHold;
    aHold = mData[33]; mData[33] = mData[51]; mData[51] = aHold;
    aHold = mData[34]; mData[34] = mData[48]; mData[48] = aHold;
    aHold = mData[35]; mData[35] = mData[49]; mData[49] = aHold;
    aHold = mData[36]; mData[36] = mData[54]; mData[54] = aHold;
    aHold = mData[37]; mData[37] = mData[55]; mData[55] = aHold;
    aHold = mData[38]; mData[38] = mData[52]; mData[52] = aHold;
    aHold = mData[39]; mData[39] = mData[53]; mData[53] = aHold;
    aHold = mData[40]; mData[40] = mData[58]; mData[58] = aHold;
    aHold = mData[41]; mData[41] = mData[59]; mData[59] = aHold;
    aHold = mData[42]; mData[42] = mData[56]; mData[56] = aHold;
    aHold = mData[43]; mData[43] = mData[57]; mData[57] = aHold;
    aHold = mData[44]; mData[44] = mData[62]; mData[62] = aHold;
    aHold = mData[45]; mData[45] = mData[63]; mData[63] = aHold;
    aHold = mData[46]; mData[46] = mData[60]; mData[60] = aHold;
    aHold = mData[47]; mData[47] = mData[61]; mData[61] = aHold;
}

void M88::Full_SwapBoth_EachQuad_4x4() {
    Quad_SwapBoth_4x4_A();
    Quad_SwapBoth_4x4_B();
    Quad_SwapBoth_4x4_C();
    Quad_SwapBoth_4x4_D();
}

void M88::Quad_SwapBoth_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = aHold;
    aHold = mData[1]; mData[1] = mData[8]; mData[8] = aHold;
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = aHold;
    aHold = mData[3]; mData[3] = mData[10]; mData[10] = aHold;
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = aHold;
    aHold = mData[17]; mData[17] = mData[24]; mData[24] = aHold;
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = aHold;
    aHold = mData[19]; mData[19] = mData[26]; mData[26] = aHold;
}

void M88::Quad_SwapBoth_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = aHold;
    aHold = mData[5]; mData[5] = mData[12]; mData[12] = aHold;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = aHold;
    aHold = mData[7]; mData[7] = mData[14]; mData[14] = aHold;
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = aHold;
    aHold = mData[21]; mData[21] = mData[28]; mData[28] = aHold;
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = aHold;
    aHold = mData[23]; mData[23] = mData[30]; mData[30] = aHold;
}

void M88::Quad_SwapBoth_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = aHold;
    aHold = mData[33]; mData[33] = mData[40]; mData[40] = aHold;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = aHold;
    aHold = mData[35]; mData[35] = mData[42]; mData[42] = aHold;
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = aHold;
    aHold = mData[49]; mData[49] = mData[56]; mData[56] = aHold;
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = aHold;
    aHold = mData[51]; mData[51] = mData[58]; mData[58] = aHold;
}

void M88::Quad_SwapBoth_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = aHold;
    aHold = mData[37]; mData[37] = mData[44]; mData[44] = aHold;
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = aHold;
    aHold = mData[39]; mData[39] = mData[46]; mData[46] = aHold;
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = aHold;
    aHold = mData[53]; mData[53] = mData[60]; mData[60] = aHold;
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = aHold;
    aHold = mData[55]; mData[55] = mData[62]; mData[62] = aHold;
}

void M88::Full_SwapBoth_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = aHold;
    aHold = mData[1]; mData[1] = mData[8]; mData[8] = aHold;
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = aHold;
    aHold = mData[3]; mData[3] = mData[10]; mData[10] = aHold;
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = aHold;
    aHold = mData[5]; mData[5] = mData[12]; mData[12] = aHold;
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = aHold;
    aHold = mData[7]; mData[7] = mData[14]; mData[14] = aHold;
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = aHold;
    aHold = mData[17]; mData[17] = mData[24]; mData[24] = aHold;
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = aHold;
    aHold = mData[19]; mData[19] = mData[26]; mData[26] = aHold;
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = aHold;
    aHold = mData[21]; mData[21] = mData[28]; mData[28] = aHold;
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = aHold;
    aHold = mData[23]; mData[23] = mData[30]; mData[30] = aHold;
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = aHold;
    aHold = mData[33]; mData[33] = mData[40]; mData[40] = aHold;
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = aHold;
    aHold = mData[35]; mData[35] = mData[42]; mData[42] = aHold;
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = aHold;
    aHold = mData[37]; mData[37] = mData[44]; mData[44] = aHold;
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = aHold;
    aHold = mData[39]; mData[39] = mData[46]; mData[46] = aHold;
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = aHold;
    aHold = mData[49]; mData[49] = mData[56]; mData[56] = aHold;
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = aHold;
    aHold = mData[51]; mData[51] = mData[58]; mData[58] = aHold;
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = aHold;
    aHold = mData[53]; mData[53] = mData[60]; mData[60] = aHold;
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = aHold;
    aHold = mData[55]; mData[55] = mData[62]; mData[62] = aHold;
}


void M88::Full_ShearA_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = aHold;
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = aHold;
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = aHold;
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = aHold;
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = aHold;
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = aHold;
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[22]; mData[22] = mData[20]; mData[20] = mData[18]; mData[18] = aHold;
    aHold = mData[17]; mData[17] = mData[23]; mData[23] = mData[21]; mData[21] = mData[19]; mData[19] = aHold;
    aHold = mData[24]; mData[24] = mData[30]; mData[30] = mData[28]; mData[28] = mData[26]; mData[26] = aHold;
    aHold = mData[25]; mData[25] = mData[31]; mData[31] = mData[29]; mData[29] = mData[27]; mData[27] = aHold;
    aHold = mData[32]; mData[32] = mData[36]; mData[36] = aHold;
    aHold = mData[33]; mData[33] = mData[37]; mData[37] = aHold;
    aHold = mData[34]; mData[34] = mData[38]; mData[38] = aHold;
    aHold = mData[35]; mData[35] = mData[39]; mData[39] = aHold;
    aHold = mData[40]; mData[40] = mData[44]; mData[44] = aHold;
    aHold = mData[41]; mData[41] = mData[45]; mData[45] = aHold;
    aHold = mData[42]; mData[42] = mData[46]; mData[46] = aHold;
    aHold = mData[43]; mData[43] = mData[47]; mData[47] = aHold;
    aHold = mData[48]; mData[48] = mData[54]; mData[54] = mData[52]; mData[52] = mData[50]; mData[50] = aHold;
    aHold = mData[49]; mData[49] = mData[55]; mData[55] = mData[53]; mData[53] = mData[51]; mData[51] = aHold;
    aHold = mData[56]; mData[56] = mData[62]; mData[62] = mData[60]; mData[60] = mData[58]; mData[58] = aHold;
    aHold = mData[57]; mData[57] = mData[63]; mData[63] = mData[61]; mData[61] = mData[59]; mData[59] = aHold;
}

void M88::Full_ShearA_EachQuad_4x4() {
    Quad_ShearA_4x4_A();
    Quad_ShearA_4x4_B();
    Quad_ShearA_4x4_C();
    Quad_ShearA_4x4_D();
}

void M88::Quad_ShearA_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[11]; mData[11] = mData[10]; mData[10] = mData[9]; mData[9] = aHold;
    aHold = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[24]; mData[24] = mData[27]; mData[27] = mData[26]; mData[26] = mData[25]; mData[25] = aHold;
}

void M88::Quad_ShearA_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = aHold;
    aHold = mData[12]; mData[12] = mData[15]; mData[15] = mData[14]; mData[14] = mData[13]; mData[13] = aHold;
    aHold = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[28]; mData[28] = mData[31]; mData[31] = mData[30]; mData[30] = mData[29]; mData[29] = aHold;
}

void M88::Quad_ShearA_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[43]; mData[43] = mData[42]; mData[42] = mData[41]; mData[41] = aHold;
    aHold = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[56]; mData[56] = mData[59]; mData[59] = mData[58]; mData[58] = mData[57]; mData[57] = aHold;
}

void M88::Quad_ShearA_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = aHold;
    aHold = mData[44]; mData[44] = mData[47]; mData[47] = mData[46]; mData[46] = mData[45]; mData[45] = aHold;
    aHold = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[60]; mData[60] = mData[63]; mData[63] = mData[62]; mData[62] = mData[61]; mData[61] = aHold;
}

void M88::Full_ShearB_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[6]; mData[6] = mData[4]; mData[4] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[7]; mData[7] = mData[5]; mData[5] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[14]; mData[14] = mData[12]; mData[12] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[15]; mData[15] = mData[13]; mData[13] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[38]; mData[38] = mData[36]; mData[36] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[39]; mData[39] = mData[37]; mData[37] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[46]; mData[46] = mData[44]; mData[44] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[47]; mData[47] = mData[45]; mData[45] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[52]; mData[52] = aHold;
    aHold = mData[49]; mData[49] = mData[53]; mData[53] = aHold;
    aHold = mData[50]; mData[50] = mData[54]; mData[54] = aHold;
    aHold = mData[51]; mData[51] = mData[55]; mData[55] = aHold;
    aHold = mData[56]; mData[56] = mData[60]; mData[60] = aHold;
    aHold = mData[57]; mData[57] = mData[61]; mData[61] = aHold;
    aHold = mData[58]; mData[58] = mData[62]; mData[62] = aHold;
    aHold = mData[59]; mData[59] = mData[63]; mData[63] = aHold;
}

void M88::Full_ShearB_EachQuad_4x4() {
    Quad_ShearB_4x4_A();
    Quad_ShearB_4x4_B();
    Quad_ShearB_4x4_C();
    Quad_ShearB_4x4_D();
}

void M88::Quad_ShearB_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[3]; mData[3] = mData[2]; mData[2] = mData[1]; mData[1] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[19]; mData[19] = mData[18]; mData[18] = mData[17]; mData[17] = aHold;
    aHold = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
    aHold = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
}

void M88::Quad_ShearB_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[7]; mData[7] = mData[6]; mData[6] = mData[5]; mData[5] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = aHold;
    aHold = mData[20]; mData[20] = mData[23]; mData[23] = mData[22]; mData[22] = mData[21]; mData[21] = aHold;
    aHold = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
}

void M88::Quad_ShearB_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[35]; mData[35] = mData[34]; mData[34] = mData[33]; mData[33] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[51]; mData[51] = mData[50]; mData[50] = mData[49]; mData[49] = aHold;
    aHold = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
    aHold = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
}

void M88::Quad_ShearB_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[39]; mData[39] = mData[38]; mData[38] = mData[37]; mData[37] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = aHold;
    aHold = mData[52]; mData[52] = mData[55]; mData[55] = mData[54]; mData[54] = mData[53]; mData[53] = aHold;
    aHold = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
    aHold = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}

void M88::Full_ShearC_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = aHold;
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = aHold;
    aHold = mData[2]; mData[2] = mData[50]; mData[50] = mData[34]; mData[34] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[51]; mData[51] = mData[35]; mData[35] = mData[19]; mData[19] = aHold;
    aHold = mData[4]; mData[4] = mData[36]; mData[36] = aHold;
    aHold = mData[5]; mData[5] = mData[37]; mData[37] = aHold;
    aHold = mData[6]; mData[6] = mData[54]; mData[54] = mData[38]; mData[38] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[55]; mData[55] = mData[39]; mData[39] = mData[23]; mData[23] = aHold;
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = aHold;
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = aHold;
    aHold = mData[10]; mData[10] = mData[58]; mData[58] = mData[42]; mData[42] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[59]; mData[59] = mData[43]; mData[43] = mData[27]; mData[27] = aHold;
    aHold = mData[12]; mData[12] = mData[44]; mData[44] = aHold;
    aHold = mData[13]; mData[13] = mData[45]; mData[45] = aHold;
    aHold = mData[14]; mData[14] = mData[62]; mData[62] = mData[46]; mData[46] = mData[30]; mData[30] = aHold;
    aHold = mData[15]; mData[15] = mData[63]; mData[63] = mData[47]; mData[47] = mData[31]; mData[31] = aHold;
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = aHold;
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = aHold;
    aHold = mData[20]; mData[20] = mData[52]; mData[52] = aHold;
    aHold = mData[21]; mData[21] = mData[53]; mData[53] = aHold;
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = aHold;
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = aHold;
    aHold = mData[28]; mData[28] = mData[60]; mData[60] = aHold;
    aHold = mData[29]; mData[29] = mData[61]; mData[61] = aHold;
}

void M88::Full_ShearC_EachQuad_4x4() {
    Quad_ShearC_4x4_A();
    Quad_ShearC_4x4_B();
    Quad_ShearC_4x4_C();
    Quad_ShearC_4x4_D();
}

void M88::Quad_ShearC_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[25]; mData[25] = mData[17]; mData[17] = mData[9]; mData[9] = aHold;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[27]; mData[27] = mData[19]; mData[19] = mData[11]; mData[11] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
}

void M88::Quad_ShearC_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[29]; mData[29] = mData[21]; mData[21] = mData[13]; mData[13] = aHold;
    aHold = mData[6]; mData[6] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[31]; mData[31] = mData[23]; mData[23] = mData[15]; mData[15] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = aHold;
    aHold = mData[14]; mData[14] = mData[30]; mData[30] = aHold;
}

void M88::Quad_ShearC_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[57]; mData[57] = mData[49]; mData[49] = mData[41]; mData[41] = aHold;
    aHold = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[35]; mData[35] = mData[59]; mData[59] = mData[51]; mData[51] = mData[43]; mData[43] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = aHold;
    aHold = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
}

void M88::Quad_ShearC_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[61]; mData[61] = mData[53]; mData[53] = mData[45]; mData[45] = aHold;
    aHold = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[39]; mData[39] = mData[63]; mData[63] = mData[55]; mData[55] = mData[47]; mData[47] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = aHold;
    aHold = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
}


void M88::Full_ShearD_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[48]; mData[48] = mData[32]; mData[32] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[49]; mData[49] = mData[33]; mData[33] = mData[17]; mData[17] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = aHold;
    aHold = mData[4]; mData[4] = mData[52]; mData[52] = mData[36]; mData[36] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[53]; mData[53] = mData[37]; mData[37] = mData[21]; mData[21] = aHold;
    aHold = mData[6]; mData[6] = mData[38]; mData[38] = aHold;
    aHold = mData[7]; mData[7] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[56]; mData[56] = mData[40]; mData[40] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[57]; mData[57] = mData[41]; mData[41] = mData[25]; mData[25] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = aHold;
    aHold = mData[12]; mData[12] = mData[60]; mData[60] = mData[44]; mData[44] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[61]; mData[61] = mData[45]; mData[45] = mData[29]; mData[29] = aHold;
    aHold = mData[14]; mData[14] = mData[46]; mData[46] = aHold;
    aHold = mData[15]; mData[15] = mData[47]; mData[47] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = aHold;
    aHold = mData[22]; mData[22] = mData[54]; mData[54] = aHold;
    aHold = mData[23]; mData[23] = mData[55]; mData[55] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = aHold;
    aHold = mData[30]; mData[30] = mData[62]; mData[62] = aHold;
    aHold = mData[31]; mData[31] = mData[63]; mData[63] = aHold;
}

void M88::Full_ShearD_EachQuad_4x4() {
    Quad_ShearD_4x4_A();
    Quad_ShearD_4x4_B();
    Quad_ShearD_4x4_C();
    Quad_ShearD_4x4_D();
}

void M88::Quad_ShearD_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[24]; mData[24] = mData[16]; mData[16] = mData[8]; mData[8] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = aHold;
    aHold = mData[2]; mData[2] = mData[26]; mData[26] = mData[18]; mData[18] = mData[10]; mData[10] = aHold;
    aHold = mData[3]; mData[3] = mData[19]; mData[19] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = aHold;
    aHold = mData[11]; mData[11] = mData[27]; mData[27] = aHold;
}

void M88::Quad_ShearD_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[28]; mData[28] = mData[20]; mData[20] = mData[12]; mData[12] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = aHold;
    aHold = mData[6]; mData[6] = mData[30]; mData[30] = mData[22]; mData[22] = mData[14]; mData[14] = aHold;
    aHold = mData[7]; mData[7] = mData[23]; mData[23] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = aHold;
    aHold = mData[15]; mData[15] = mData[31]; mData[31] = aHold;
}

void M88::Quad_ShearD_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[56]; mData[56] = mData[48]; mData[48] = mData[40]; mData[40] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = aHold;
    aHold = mData[34]; mData[34] = mData[58]; mData[58] = mData[50]; mData[50] = mData[42]; mData[42] = aHold;
    aHold = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = aHold;
    aHold = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
}

void M88::Quad_ShearD_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[60]; mData[60] = mData[52]; mData[52] = mData[44]; mData[44] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = aHold;
    aHold = mData[38]; mData[38] = mData[62]; mData[62] = mData[54]; mData[54] = mData[46]; mData[46] = aHold;
    aHold = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = aHold;
    aHold = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
}


void M88::Full_ShearA_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = aHold;
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = aHold;
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = aHold;
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[14]; mData[14] = mData[12]; mData[12] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[15]; mData[15] = mData[13]; mData[13] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[30]; mData[30] = mData[28]; mData[28] = mData[26]; mData[26] = aHold;
    aHold = mData[25]; mData[25] = mData[31]; mData[31] = mData[29]; mData[29] = mData[27]; mData[27] = aHold;
    aHold = mData[32]; mData[32] = mData[36]; mData[36] = aHold;
    aHold = mData[33]; mData[33] = mData[37]; mData[37] = aHold;
    aHold = mData[34]; mData[34] = mData[38]; mData[38] = aHold;
    aHold = mData[35]; mData[35] = mData[39]; mData[39] = aHold;
    aHold = mData[40]; mData[40] = mData[46]; mData[46] = mData[44]; mData[44] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[47]; mData[47] = mData[45]; mData[45] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[52]; mData[52] = aHold;
    aHold = mData[49]; mData[49] = mData[53]; mData[53] = aHold;
    aHold = mData[50]; mData[50] = mData[54]; mData[54] = aHold;
    aHold = mData[51]; mData[51] = mData[55]; mData[55] = aHold;
    aHold = mData[56]; mData[56] = mData[62]; mData[62] = mData[60]; mData[60] = mData[58]; mData[58] = aHold;
    aHold = mData[57]; mData[57] = mData[63]; mData[63] = mData[61]; mData[61] = mData[59]; mData[59] = aHold;
}


void M88::Full_ShearB_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[6]; mData[6] = mData[4]; mData[4] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[7]; mData[7] = mData[5]; mData[5] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = aHold;
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = aHold;
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = aHold;
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[22]; mData[22] = mData[20]; mData[20] = mData[18]; mData[18] = aHold;
    aHold = mData[17]; mData[17] = mData[23]; mData[23] = mData[21]; mData[21] = mData[19]; mData[19] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[38]; mData[38] = mData[36]; mData[36] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[39]; mData[39] = mData[37]; mData[37] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[44]; mData[44] = aHold;
    aHold = mData[41]; mData[41] = mData[45]; mData[45] = aHold;
    aHold = mData[42]; mData[42] = mData[46]; mData[46] = aHold;
    aHold = mData[43]; mData[43] = mData[47]; mData[47] = aHold;
    aHold = mData[48]; mData[48] = mData[54]; mData[54] = mData[52]; mData[52] = mData[50]; mData[50] = aHold;
    aHold = mData[49]; mData[49] = mData[55]; mData[55] = mData[53]; mData[53] = mData[51]; mData[51] = aHold;
    aHold = mData[56]; mData[56] = mData[60]; mData[60] = aHold;
    aHold = mData[57]; mData[57] = mData[61]; mData[61] = aHold;
    aHold = mData[58]; mData[58] = mData[62]; mData[62] = aHold;
    aHold = mData[59]; mData[59] = mData[63]; mData[63] = aHold;
}

void M88::Full_ShearC_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = aHold;
    aHold = mData[1]; mData[1] = mData[49]; mData[49] = mData[33]; mData[33] = mData[17]; mData[17] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[51]; mData[51] = mData[35]; mData[35] = mData[19]; mData[19] = aHold;
    aHold = mData[4]; mData[4] = mData[36]; mData[36] = aHold;
    aHold = mData[5]; mData[5] = mData[53]; mData[53] = mData[37]; mData[37] = mData[21]; mData[21] = aHold;
    aHold = mData[6]; mData[6] = mData[38]; mData[38] = aHold;
    aHold = mData[7]; mData[7] = mData[55]; mData[55] = mData[39]; mData[39] = mData[23]; mData[23] = aHold;
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = aHold;
    aHold = mData[9]; mData[9] = mData[57]; mData[57] = mData[41]; mData[41] = mData[25]; mData[25] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[59]; mData[59] = mData[43]; mData[43] = mData[27]; mData[27] = aHold;
    aHold = mData[12]; mData[12] = mData[44]; mData[44] = aHold;
    aHold = mData[13]; mData[13] = mData[61]; mData[61] = mData[45]; mData[45] = mData[29]; mData[29] = aHold;
    aHold = mData[14]; mData[14] = mData[46]; mData[46] = aHold;
    aHold = mData[15]; mData[15] = mData[63]; mData[63] = mData[47]; mData[47] = mData[31]; mData[31] = aHold;
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = aHold;
    aHold = mData[20]; mData[20] = mData[52]; mData[52] = aHold;
    aHold = mData[22]; mData[22] = mData[54]; mData[54] = aHold;
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = aHold;
    aHold = mData[28]; mData[28] = mData[60]; mData[60] = aHold;
    aHold = mData[30]; mData[30] = mData[62]; mData[62] = aHold;
}

void M88::Full_ShearD_8x8() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[48]; mData[48] = mData[32]; mData[32] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = aHold;
    aHold = mData[2]; mData[2] = mData[50]; mData[50] = mData[34]; mData[34] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = aHold;
    aHold = mData[4]; mData[4] = mData[52]; mData[52] = mData[36]; mData[36] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[37]; mData[37] = aHold;
    aHold = mData[6]; mData[6] = mData[54]; mData[54] = mData[38]; mData[38] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[56]; mData[56] = mData[40]; mData[40] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = aHold;
    aHold = mData[10]; mData[10] = mData[58]; mData[58] = mData[42]; mData[42] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = aHold;
    aHold = mData[12]; mData[12] = mData[60]; mData[60] = mData[44]; mData[44] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[45]; mData[45] = aHold;
    aHold = mData[14]; mData[14] = mData[62]; mData[62] = mData[46]; mData[46] = mData[30]; mData[30] = aHold;
    aHold = mData[15]; mData[15] = mData[47]; mData[47] = aHold;
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = aHold;
    aHold = mData[21]; mData[21] = mData[53]; mData[53] = aHold;
    aHold = mData[23]; mData[23] = mData[55]; mData[55] = aHold;
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = aHold;
    aHold = mData[29]; mData[29] = mData[61]; mData[61] = aHold;
    aHold = mData[31]; mData[31] = mData[63]; mData[63] = aHold;
}

void M88::Full_RollHor1_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[6]; mData[6] = mData[4]; mData[4] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[7]; mData[7] = mData[5]; mData[5] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[14]; mData[14] = mData[12]; mData[12] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[15]; mData[15] = mData[13]; mData[13] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[22]; mData[22] = mData[20]; mData[20] = mData[18]; mData[18] = aHold;
    aHold = mData[17]; mData[17] = mData[23]; mData[23] = mData[21]; mData[21] = mData[19]; mData[19] = aHold;
    aHold = mData[24]; mData[24] = mData[30]; mData[30] = mData[28]; mData[28] = mData[26]; mData[26] = aHold;
    aHold = mData[25]; mData[25] = mData[31]; mData[31] = mData[29]; mData[29] = mData[27]; mData[27] = aHold;
    aHold = mData[32]; mData[32] = mData[38]; mData[38] = mData[36]; mData[36] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[39]; mData[39] = mData[37]; mData[37] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[46]; mData[46] = mData[44]; mData[44] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[47]; mData[47] = mData[45]; mData[45] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[54]; mData[54] = mData[52]; mData[52] = mData[50]; mData[50] = aHold;
    aHold = mData[49]; mData[49] = mData[55]; mData[55] = mData[53]; mData[53] = mData[51]; mData[51] = aHold;
    aHold = mData[56]; mData[56] = mData[62]; mData[62] = mData[60]; mData[60] = mData[58]; mData[58] = aHold;
    aHold = mData[57]; mData[57] = mData[63]; mData[63] = mData[61]; mData[61] = mData[59]; mData[59] = aHold;
}

void M88::Full_RollHor1_EachQuad_4x4() {
    Quad_RollHor1_4x4_A();
    Quad_RollHor1_4x4_B();
    Quad_RollHor1_4x4_C();
    Quad_RollHor1_4x4_D();
}

void M88::Quad_RollHor1_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[3]; mData[3] = mData[2]; mData[2] = mData[1]; mData[1] = aHold;
    aHold = mData[8]; mData[8] = mData[11]; mData[11] = mData[10]; mData[10] = mData[9]; mData[9] = aHold;
    aHold = mData[16]; mData[16] = mData[19]; mData[19] = mData[18]; mData[18] = mData[17]; mData[17] = aHold;
    aHold = mData[24]; mData[24] = mData[27]; mData[27] = mData[26]; mData[26] = mData[25]; mData[25] = aHold;
}

void M88::Quad_RollHor1_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[7]; mData[7] = mData[6]; mData[6] = mData[5]; mData[5] = aHold;
    aHold = mData[12]; mData[12] = mData[15]; mData[15] = mData[14]; mData[14] = mData[13]; mData[13] = aHold;
    aHold = mData[20]; mData[20] = mData[23]; mData[23] = mData[22]; mData[22] = mData[21]; mData[21] = aHold;
    aHold = mData[28]; mData[28] = mData[31]; mData[31] = mData[30]; mData[30] = mData[29]; mData[29] = aHold;
}

void M88::Quad_RollHor1_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[35]; mData[35] = mData[34]; mData[34] = mData[33]; mData[33] = aHold;
    aHold = mData[40]; mData[40] = mData[43]; mData[43] = mData[42]; mData[42] = mData[41]; mData[41] = aHold;
    aHold = mData[48]; mData[48] = mData[51]; mData[51] = mData[50]; mData[50] = mData[49]; mData[49] = aHold;
    aHold = mData[56]; mData[56] = mData[59]; mData[59] = mData[58]; mData[58] = mData[57]; mData[57] = aHold;
}

void M88::Quad_RollHor1_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[39]; mData[39] = mData[38]; mData[38] = mData[37]; mData[37] = aHold;
    aHold = mData[44]; mData[44] = mData[47]; mData[47] = mData[46]; mData[46] = mData[45]; mData[45] = aHold;
    aHold = mData[52]; mData[52] = mData[55]; mData[55] = mData[54]; mData[54] = mData[53]; mData[53] = aHold;
    aHold = mData[60]; mData[60] = mData[63]; mData[63] = mData[62]; mData[62] = mData[61]; mData[61] = aHold;
}

void M88::Full_RollHor2_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = aHold;
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = aHold;
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = aHold;
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = aHold;
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = aHold;
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = aHold;
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = aHold;
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = aHold;
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = aHold;
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = aHold;
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = aHold;
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = aHold;
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[36]; mData[36] = aHold;
    aHold = mData[33]; mData[33] = mData[37]; mData[37] = aHold;
    aHold = mData[34]; mData[34] = mData[38]; mData[38] = aHold;
    aHold = mData[35]; mData[35] = mData[39]; mData[39] = aHold;
    aHold = mData[40]; mData[40] = mData[44]; mData[44] = aHold;
    aHold = mData[41]; mData[41] = mData[45]; mData[45] = aHold;
    aHold = mData[42]; mData[42] = mData[46]; mData[46] = aHold;
    aHold = mData[43]; mData[43] = mData[47]; mData[47] = aHold;
    aHold = mData[48]; mData[48] = mData[52]; mData[52] = aHold;
    aHold = mData[49]; mData[49] = mData[53]; mData[53] = aHold;
    aHold = mData[50]; mData[50] = mData[54]; mData[54] = aHold;
    aHold = mData[51]; mData[51] = mData[55]; mData[55] = aHold;
    aHold = mData[56]; mData[56] = mData[60]; mData[60] = aHold;
    aHold = mData[57]; mData[57] = mData[61]; mData[61] = aHold;
    aHold = mData[58]; mData[58] = mData[62]; mData[62] = aHold;
    aHold = mData[59]; mData[59] = mData[63]; mData[63] = aHold;
}

void M88::Full_RollHor2_EachQuad_4x4() {
    Quad_RollHor2_4x4_A();
    Quad_RollHor2_4x4_B();
    Quad_RollHor2_4x4_C();
    Quad_RollHor2_4x4_D();
}

void M88::Quad_RollHor2_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = aHold;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
    aHold = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
}

void M88::Quad_RollHor2_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[6]; mData[6] = aHold;
    aHold = mData[5]; mData[5] = mData[7]; mData[7] = aHold;
    aHold = mData[12]; mData[12] = mData[14]; mData[14] = aHold;
    aHold = mData[13]; mData[13] = mData[15]; mData[15] = aHold;
    aHold = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
}

void M88::Quad_RollHor2_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[50]; mData[50] = aHold;
    aHold = mData[49]; mData[49] = mData[51]; mData[51] = aHold;
    aHold = mData[56]; mData[56] = mData[58]; mData[58] = aHold;
    aHold = mData[57]; mData[57] = mData[59]; mData[59] = aHold;
}

void M88::Quad_RollHor2_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = aHold;
    aHold = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
    aHold = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}


void M88::Full_RollHor3_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[2]; mData[2] = mData[4]; mData[4] = mData[6]; mData[6] = aHold;
    aHold = mData[1]; mData[1] = mData[3]; mData[3] = mData[5]; mData[5] = mData[7]; mData[7] = aHold;
    aHold = mData[8]; mData[8] = mData[10]; mData[10] = mData[12]; mData[12] = mData[14]; mData[14] = aHold;
    aHold = mData[9]; mData[9] = mData[11]; mData[11] = mData[13]; mData[13] = mData[15]; mData[15] = aHold;
    aHold = mData[16]; mData[16] = mData[18]; mData[18] = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[17]; mData[17] = mData[19]; mData[19] = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[26]; mData[26] = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[25]; mData[25] = mData[27]; mData[27] = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = mData[36]; mData[36] = mData[38]; mData[38] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = mData[37]; mData[37] = mData[39]; mData[39] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = mData[44]; mData[44] = mData[46]; mData[46] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = mData[45]; mData[45] = mData[47]; mData[47] = aHold;
    aHold = mData[48]; mData[48] = mData[50]; mData[50] = mData[52]; mData[52] = mData[54]; mData[54] = aHold;
    aHold = mData[49]; mData[49] = mData[51]; mData[51] = mData[53]; mData[53] = mData[55]; mData[55] = aHold;
    aHold = mData[56]; mData[56] = mData[58]; mData[58] = mData[60]; mData[60] = mData[62]; mData[62] = aHold;
    aHold = mData[57]; mData[57] = mData[59]; mData[59] = mData[61]; mData[61] = mData[63]; mData[63] = aHold;
}

void M88::Full_RollHor3_EachQuad_4x4() {
    Quad_RollHor3_4x4_A();
    Quad_RollHor3_4x4_B();
    Quad_RollHor3_4x4_C();
    Quad_RollHor3_4x4_D();
}

void M88::Quad_RollHor3_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = mData[2]; mData[2] = mData[3]; mData[3] = aHold;
    aHold = mData[8]; mData[8] = mData[9]; mData[9] = mData[10]; mData[10] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = mData[18]; mData[18] = mData[19]; mData[19] = aHold;
    aHold = mData[24]; mData[24] = mData[25]; mData[25] = mData[26]; mData[26] = mData[27]; mData[27] = aHold;
}

void M88::Quad_RollHor3_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = mData[6]; mData[6] = mData[7]; mData[7] = aHold;
    aHold = mData[12]; mData[12] = mData[13]; mData[13] = mData[14]; mData[14] = mData[15]; mData[15] = aHold;
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = mData[22]; mData[22] = mData[23]; mData[23] = aHold;
    aHold = mData[28]; mData[28] = mData[29]; mData[29] = mData[30]; mData[30] = mData[31]; mData[31] = aHold;
}

void M88::Quad_RollHor3_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = mData[34]; mData[34] = mData[35]; mData[35] = aHold;
    aHold = mData[40]; mData[40] = mData[41]; mData[41] = mData[42]; mData[42] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = mData[50]; mData[50] = mData[51]; mData[51] = aHold;
    aHold = mData[56]; mData[56] = mData[57]; mData[57] = mData[58]; mData[58] = mData[59]; mData[59] = aHold;
}

void M88::Quad_RollHor3_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = mData[38]; mData[38] = mData[39]; mData[39] = aHold;
    aHold = mData[44]; mData[44] = mData[45]; mData[45] = mData[46]; mData[46] = mData[47]; mData[47] = aHold;
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = mData[54]; mData[54] = mData[55]; mData[55] = aHold;
    aHold = mData[60]; mData[60] = mData[61]; mData[61] = mData[62]; mData[62] = mData[63]; mData[63] = aHold;
}


void M88::Full_RollVer1_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[48]; mData[48] = mData[32]; mData[32] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[49]; mData[49] = mData[33]; mData[33] = mData[17]; mData[17] = aHold;
    aHold = mData[2]; mData[2] = mData[50]; mData[50] = mData[34]; mData[34] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[51]; mData[51] = mData[35]; mData[35] = mData[19]; mData[19] = aHold;
    aHold = mData[4]; mData[4] = mData[52]; mData[52] = mData[36]; mData[36] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[53]; mData[53] = mData[37]; mData[37] = mData[21]; mData[21] = aHold;
    aHold = mData[6]; mData[6] = mData[54]; mData[54] = mData[38]; mData[38] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[55]; mData[55] = mData[39]; mData[39] = mData[23]; mData[23] = aHold;
    aHold = mData[8]; mData[8] = mData[56]; mData[56] = mData[40]; mData[40] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[57]; mData[57] = mData[41]; mData[41] = mData[25]; mData[25] = aHold;
    aHold = mData[10]; mData[10] = mData[58]; mData[58] = mData[42]; mData[42] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[59]; mData[59] = mData[43]; mData[43] = mData[27]; mData[27] = aHold;
    aHold = mData[12]; mData[12] = mData[60]; mData[60] = mData[44]; mData[44] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[61]; mData[61] = mData[45]; mData[45] = mData[29]; mData[29] = aHold;
    aHold = mData[14]; mData[14] = mData[62]; mData[62] = mData[46]; mData[46] = mData[30]; mData[30] = aHold;
    aHold = mData[15]; mData[15] = mData[63]; mData[63] = mData[47]; mData[47] = mData[31]; mData[31] = aHold;
}

void M88::Full_RollVer1_EachQuad_4x4() {
    Quad_RollVer1_4x4_A();
    Quad_RollVer1_4x4_B();
    Quad_RollVer1_4x4_C();
    Quad_RollVer1_4x4_D();
}

void M88::Quad_RollVer1_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[24]; mData[24] = mData[16]; mData[16] = mData[8]; mData[8] = aHold;
    aHold = mData[1]; mData[1] = mData[25]; mData[25] = mData[17]; mData[17] = mData[9]; mData[9] = aHold;
    aHold = mData[2]; mData[2] = mData[26]; mData[26] = mData[18]; mData[18] = mData[10]; mData[10] = aHold;
    aHold = mData[3]; mData[3] = mData[27]; mData[27] = mData[19]; mData[19] = mData[11]; mData[11] = aHold;
}

void M88::Quad_RollVer1_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[28]; mData[28] = mData[20]; mData[20] = mData[12]; mData[12] = aHold;
    aHold = mData[5]; mData[5] = mData[29]; mData[29] = mData[21]; mData[21] = mData[13]; mData[13] = aHold;
    aHold = mData[6]; mData[6] = mData[30]; mData[30] = mData[22]; mData[22] = mData[14]; mData[14] = aHold;
    aHold = mData[7]; mData[7] = mData[31]; mData[31] = mData[23]; mData[23] = mData[15]; mData[15] = aHold;
}

void M88::Quad_RollVer1_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[56]; mData[56] = mData[48]; mData[48] = mData[40]; mData[40] = aHold;
    aHold = mData[33]; mData[33] = mData[57]; mData[57] = mData[49]; mData[49] = mData[41]; mData[41] = aHold;
    aHold = mData[34]; mData[34] = mData[58]; mData[58] = mData[50]; mData[50] = mData[42]; mData[42] = aHold;
    aHold = mData[35]; mData[35] = mData[59]; mData[59] = mData[51]; mData[51] = mData[43]; mData[43] = aHold;
}

void M88::Quad_RollVer1_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[60]; mData[60] = mData[52]; mData[52] = mData[44]; mData[44] = aHold;
    aHold = mData[37]; mData[37] = mData[61]; mData[61] = mData[53]; mData[53] = mData[45]; mData[45] = aHold;
    aHold = mData[38]; mData[38] = mData[62]; mData[62] = mData[54]; mData[54] = mData[46]; mData[46] = aHold;
    aHold = mData[39]; mData[39] = mData[63]; mData[63] = mData[55]; mData[55] = mData[47]; mData[47] = aHold;
}

void M88::Full_RollVer2_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = aHold;
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = aHold;
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = aHold;
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = aHold;
    aHold = mData[4]; mData[4] = mData[36]; mData[36] = aHold;
    aHold = mData[5]; mData[5] = mData[37]; mData[37] = aHold;
    aHold = mData[6]; mData[6] = mData[38]; mData[38] = aHold;
    aHold = mData[7]; mData[7] = mData[39]; mData[39] = aHold;
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = aHold;
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = aHold;
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = aHold;
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = aHold;
    aHold = mData[12]; mData[12] = mData[44]; mData[44] = aHold;
    aHold = mData[13]; mData[13] = mData[45]; mData[45] = aHold;
    aHold = mData[14]; mData[14] = mData[46]; mData[46] = aHold;
    aHold = mData[15]; mData[15] = mData[47]; mData[47] = aHold;
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = aHold;
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = aHold;
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = aHold;
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = aHold;
    aHold = mData[20]; mData[20] = mData[52]; mData[52] = aHold;
    aHold = mData[21]; mData[21] = mData[53]; mData[53] = aHold;
    aHold = mData[22]; mData[22] = mData[54]; mData[54] = aHold;
    aHold = mData[23]; mData[23] = mData[55]; mData[55] = aHold;
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = aHold;
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = aHold;
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = aHold;
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = aHold;
    aHold = mData[28]; mData[28] = mData[60]; mData[60] = aHold;
    aHold = mData[29]; mData[29] = mData[61]; mData[61] = aHold;
    aHold = mData[30]; mData[30] = mData[62]; mData[62] = aHold;
    aHold = mData[31]; mData[31] = mData[63]; mData[63] = aHold;
}

void M88::Full_RollVer2_EachQuad_4x4() {
    Quad_RollVer2_4x4_A();
    Quad_RollVer2_4x4_B();
    Quad_RollVer2_4x4_C();
    Quad_RollVer2_4x4_D();
}

void M88::Quad_RollVer2_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = aHold;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[19]; mData[19] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[27]; mData[27] = aHold;
}

void M88::Quad_RollVer2_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = aHold;
    aHold = mData[6]; mData[6] = mData[22]; mData[22] = aHold;
    aHold = mData[7]; mData[7] = mData[23]; mData[23] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = aHold;
    aHold = mData[14]; mData[14] = mData[30]; mData[30] = aHold;
    aHold = mData[15]; mData[15] = mData[31]; mData[31] = aHold;
}

void M88::Quad_RollVer2_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[48]; mData[48] = aHold;
    aHold = mData[33]; mData[33] = mData[49]; mData[49] = aHold;
    aHold = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[40]; mData[40] = mData[56]; mData[56] = aHold;
    aHold = mData[41]; mData[41] = mData[57]; mData[57] = aHold;
    aHold = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
}

void M88::Quad_RollVer2_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = aHold;
    aHold = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = aHold;
    aHold = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
}

void M88::Full_RollVer3_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[16]; mData[16] = mData[32]; mData[32] = mData[48]; mData[48] = aHold;
    aHold = mData[1]; mData[1] = mData[17]; mData[17] = mData[33]; mData[33] = mData[49]; mData[49] = aHold;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[3]; mData[3] = mData[19]; mData[19] = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = mData[36]; mData[36] = mData[52]; mData[52] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = mData[37]; mData[37] = mData[53]; mData[53] = aHold;
    aHold = mData[6]; mData[6] = mData[22]; mData[22] = mData[38]; mData[38] = mData[54]; mData[54] = aHold;
    aHold = mData[7]; mData[7] = mData[23]; mData[23] = mData[39]; mData[39] = mData[55]; mData[55] = aHold;
    aHold = mData[8]; mData[8] = mData[24]; mData[24] = mData[40]; mData[40] = mData[56]; mData[56] = aHold;
    aHold = mData[9]; mData[9] = mData[25]; mData[25] = mData[41]; mData[41] = mData[57]; mData[57] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[11]; mData[11] = mData[27]; mData[27] = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = mData[44]; mData[44] = mData[60]; mData[60] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = mData[45]; mData[45] = mData[61]; mData[61] = aHold;
    aHold = mData[14]; mData[14] = mData[30]; mData[30] = mData[46]; mData[46] = mData[62]; mData[62] = aHold;
    aHold = mData[15]; mData[15] = mData[31]; mData[31] = mData[47]; mData[47] = mData[63]; mData[63] = aHold;
}

void M88::Full_RollVer3_EachQuad_4x4() {
    Quad_RollVer3_4x4_A();
    Quad_RollVer3_4x4_B();
    Quad_RollVer3_4x4_C();
    Quad_RollVer3_4x4_D();
}

void M88::Quad_RollVer3_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = mData[16]; mData[16] = mData[24]; mData[24] = aHold;
    aHold = mData[1]; mData[1] = mData[9]; mData[9] = mData[17]; mData[17] = mData[25]; mData[25] = aHold;
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = mData[18]; mData[18] = mData[26]; mData[26] = aHold;
    aHold = mData[3]; mData[3] = mData[11]; mData[11] = mData[19]; mData[19] = mData[27]; mData[27] = aHold;
}

void M88::Quad_RollVer3_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = mData[20]; mData[20] = mData[28]; mData[28] = aHold;
    aHold = mData[5]; mData[5] = mData[13]; mData[13] = mData[21]; mData[21] = mData[29]; mData[29] = aHold;
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = mData[22]; mData[22] = mData[30]; mData[30] = aHold;
    aHold = mData[7]; mData[7] = mData[15]; mData[15] = mData[23]; mData[23] = mData[31]; mData[31] = aHold;
}

void M88::Quad_RollVer3_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = mData[48]; mData[48] = mData[56]; mData[56] = aHold;
    aHold = mData[33]; mData[33] = mData[41]; mData[41] = mData[49]; mData[49] = mData[57]; mData[57] = aHold;
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = mData[50]; mData[50] = mData[58]; mData[58] = aHold;
    aHold = mData[35]; mData[35] = mData[43]; mData[43] = mData[51]; mData[51] = mData[59]; mData[59] = aHold;
}

void M88::Quad_RollVer3_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = mData[52]; mData[52] = mData[60]; mData[60] = aHold;
    aHold = mData[37]; mData[37] = mData[45]; mData[45] = mData[53]; mData[53] = mData[61]; mData[61] = aHold;
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = mData[54]; mData[54] = mData[62]; mData[62] = aHold;
    aHold = mData[39]; mData[39] = mData[47]; mData[47] = mData[55]; mData[55] = mData[63]; mData[63] = aHold;
}

void M88::Full_FoldA_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[6]; mData[6] = aHold;
    aHold = mData[1]; mData[1] = mData[7]; mData[7] = aHold;
    aHold = mData[2]; mData[2] = mData[18]; mData[18] = aHold;
    aHold = mData[3]; mData[3] = mData[19]; mData[19] = aHold;
    aHold = mData[4]; mData[4] = mData[20]; mData[20] = aHold;
    aHold = mData[5]; mData[5] = mData[21]; mData[21] = aHold;
    aHold = mData[8]; mData[8] = mData[14]; mData[14] = aHold;
    aHold = mData[9]; mData[9] = mData[15]; mData[15] = aHold;
    aHold = mData[10]; mData[10] = mData[26]; mData[26] = aHold;
    aHold = mData[11]; mData[11] = mData[27]; mData[27] = aHold;
    aHold = mData[12]; mData[12] = mData[28]; mData[28] = aHold;
    aHold = mData[13]; mData[13] = mData[29]; mData[29] = aHold;
    aHold = mData[16]; mData[16] = mData[22]; mData[22] = aHold;
    aHold = mData[17]; mData[17] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[30]; mData[30] = aHold;
    aHold = mData[25]; mData[25] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[38]; mData[38] = aHold;
    aHold = mData[33]; mData[33] = mData[39]; mData[39] = aHold;
    aHold = mData[34]; mData[34] = mData[50]; mData[50] = aHold;
    aHold = mData[35]; mData[35] = mData[51]; mData[51] = aHold;
    aHold = mData[36]; mData[36] = mData[52]; mData[52] = aHold;
    aHold = mData[37]; mData[37] = mData[53]; mData[53] = aHold;
    aHold = mData[40]; mData[40] = mData[46]; mData[46] = aHold;
    aHold = mData[41]; mData[41] = mData[47]; mData[47] = aHold;
    aHold = mData[42]; mData[42] = mData[58]; mData[58] = aHold;
    aHold = mData[43]; mData[43] = mData[59]; mData[59] = aHold;
    aHold = mData[44]; mData[44] = mData[60]; mData[60] = aHold;
    aHold = mData[45]; mData[45] = mData[61]; mData[61] = aHold;
    aHold = mData[48]; mData[48] = mData[54]; mData[54] = aHold;
    aHold = mData[49]; mData[49] = mData[55]; mData[55] = aHold;
    aHold = mData[56]; mData[56] = mData[62]; mData[62] = aHold;
    aHold = mData[57]; mData[57] = mData[63]; mData[63] = aHold;
}

void M88::Full_FoldA_EachQuad_4x4() {
    Quad_FoldA_4x4_A();
    Quad_FoldA_4x4_B();
    Quad_FoldA_4x4_C();
    Quad_FoldA_4x4_D();
}

void M88::Quad_FoldA_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[3]; mData[3] = aHold;
    aHold = mData[1]; mData[1] = mData[9]; mData[9] = aHold;
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = aHold;
    aHold = mData[8]; mData[8] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[19]; mData[19] = aHold;
    aHold = mData[17]; mData[17] = mData[25]; mData[25] = aHold;
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = aHold;
    aHold = mData[24]; mData[24] = mData[27]; mData[27] = aHold;
}

void M88::Quad_FoldA_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[7]; mData[7] = aHold;
    aHold = mData[5]; mData[5] = mData[13]; mData[13] = aHold;
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = aHold;
    aHold = mData[12]; mData[12] = mData[15]; mData[15] = aHold;
    aHold = mData[20]; mData[20] = mData[23]; mData[23] = aHold;
    aHold = mData[21]; mData[21] = mData[29]; mData[29] = aHold;
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = aHold;
    aHold = mData[28]; mData[28] = mData[31]; mData[31] = aHold;
}

void M88::Quad_FoldA_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[35]; mData[35] = aHold;
    aHold = mData[33]; mData[33] = mData[41]; mData[41] = aHold;
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = aHold;
    aHold = mData[40]; mData[40] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[51]; mData[51] = aHold;
    aHold = mData[49]; mData[49] = mData[57]; mData[57] = aHold;
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = aHold;
    aHold = mData[56]; mData[56] = mData[59]; mData[59] = aHold;
}

void M88::Quad_FoldA_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[39]; mData[39] = aHold;
    aHold = mData[37]; mData[37] = mData[45]; mData[45] = aHold;
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = aHold;
    aHold = mData[44]; mData[44] = mData[47]; mData[47] = aHold;
    aHold = mData[52]; mData[52] = mData[55]; mData[55] = aHold;
    aHold = mData[53]; mData[53] = mData[61]; mData[61] = aHold;
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = aHold;
    aHold = mData[60]; mData[60] = mData[63]; mData[63] = aHold;
}

void M88::Full_FoldB_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[48]; mData[48] = aHold;
    aHold = mData[1]; mData[1] = mData[49]; mData[49] = aHold;
    aHold = mData[2]; mData[2] = mData[50]; mData[50] = aHold;
    aHold = mData[3]; mData[3] = mData[51]; mData[51] = aHold;
    aHold = mData[4]; mData[4] = mData[52]; mData[52] = aHold;
    aHold = mData[5]; mData[5] = mData[53]; mData[53] = aHold;
    aHold = mData[6]; mData[6] = mData[54]; mData[54] = aHold;
    aHold = mData[7]; mData[7] = mData[55]; mData[55] = aHold;
    aHold = mData[8]; mData[8] = mData[56]; mData[56] = aHold;
    aHold = mData[9]; mData[9] = mData[57]; mData[57] = aHold;
    aHold = mData[10]; mData[10] = mData[58]; mData[58] = aHold;
    aHold = mData[11]; mData[11] = mData[59]; mData[59] = aHold;
    aHold = mData[12]; mData[12] = mData[60]; mData[60] = aHold;
    aHold = mData[13]; mData[13] = mData[61]; mData[61] = aHold;
    aHold = mData[14]; mData[14] = mData[62]; mData[62] = aHold;
    aHold = mData[15]; mData[15] = mData[63]; mData[63] = aHold;
    aHold = mData[16]; mData[16] = mData[18]; mData[18] = aHold;
    aHold = mData[17]; mData[17] = mData[19]; mData[19] = aHold;
    aHold = mData[20]; mData[20] = mData[22]; mData[22] = aHold;
    aHold = mData[21]; mData[21] = mData[23]; mData[23] = aHold;
    aHold = mData[24]; mData[24] = mData[26]; mData[26] = aHold;
    aHold = mData[25]; mData[25] = mData[27]; mData[27] = aHold;
    aHold = mData[28]; mData[28] = mData[30]; mData[30] = aHold;
    aHold = mData[29]; mData[29] = mData[31]; mData[31] = aHold;
    aHold = mData[32]; mData[32] = mData[34]; mData[34] = aHold;
    aHold = mData[33]; mData[33] = mData[35]; mData[35] = aHold;
    aHold = mData[36]; mData[36] = mData[38]; mData[38] = aHold;
    aHold = mData[37]; mData[37] = mData[39]; mData[39] = aHold;
    aHold = mData[40]; mData[40] = mData[42]; mData[42] = aHold;
    aHold = mData[41]; mData[41] = mData[43]; mData[43] = aHold;
    aHold = mData[44]; mData[44] = mData[46]; mData[46] = aHold;
    aHold = mData[45]; mData[45] = mData[47]; mData[47] = aHold;
}

void M88::Full_FoldB_EachQuad_4x4() {
    Quad_FoldB_4x4_A();
    Quad_FoldB_4x4_B();
    Quad_FoldB_4x4_C();
    Quad_FoldB_4x4_D();
}

void M88::Quad_FoldB_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[24]; mData[24] = aHold;
    aHold = mData[1]; mData[1] = mData[25]; mData[25] = aHold;
    aHold = mData[2]; mData[2] = mData[26]; mData[26] = aHold;
    aHold = mData[3]; mData[3] = mData[27]; mData[27] = aHold;
    aHold = mData[8]; mData[8] = mData[9]; mData[9] = aHold;
    aHold = mData[10]; mData[10] = mData[11]; mData[11] = aHold;
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = aHold;
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = aHold;
}

void M88::Quad_FoldB_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[28]; mData[28] = aHold;
    aHold = mData[5]; mData[5] = mData[29]; mData[29] = aHold;
    aHold = mData[6]; mData[6] = mData[30]; mData[30] = aHold;
    aHold = mData[7]; mData[7] = mData[31]; mData[31] = aHold;
    aHold = mData[12]; mData[12] = mData[13]; mData[13] = aHold;
    aHold = mData[14]; mData[14] = mData[15]; mData[15] = aHold;
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = aHold;
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = aHold;
}

void M88::Quad_FoldB_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[56]; mData[56] = aHold;
    aHold = mData[33]; mData[33] = mData[57]; mData[57] = aHold;
    aHold = mData[34]; mData[34] = mData[58]; mData[58] = aHold;
    aHold = mData[35]; mData[35] = mData[59]; mData[59] = aHold;
    aHold = mData[40]; mData[40] = mData[41]; mData[41] = aHold;
    aHold = mData[42]; mData[42] = mData[43]; mData[43] = aHold;
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = aHold;
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = aHold;
}

void M88::Quad_FoldB_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[60]; mData[60] = aHold;
    aHold = mData[37]; mData[37] = mData[61]; mData[61] = aHold;
    aHold = mData[38]; mData[38] = mData[62]; mData[62] = aHold;
    aHold = mData[39]; mData[39] = mData[63]; mData[63] = aHold;
    aHold = mData[44]; mData[44] = mData[45]; mData[45] = aHold;
    aHold = mData[46]; mData[46] = mData[47]; mData[47] = aHold;
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = aHold;
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = aHold;
}

void M88::Full_FoldC_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[6]; mData[6] = aHold;
    aHold = mData[1]; mData[1] = mData[7]; mData[7] = aHold;
    aHold = mData[2]; mData[2] = mData[4]; mData[4] = aHold;
    aHold = mData[3]; mData[3] = mData[5]; mData[5] = aHold;
    aHold = mData[8]; mData[8] = mData[14]; mData[14] = aHold;
    aHold = mData[9]; mData[9] = mData[15]; mData[15] = aHold;
    aHold = mData[10]; mData[10] = mData[12]; mData[12] = aHold;
    aHold = mData[11]; mData[11] = mData[13]; mData[13] = aHold;
    aHold = mData[16]; mData[16] = mData[22]; mData[22] = aHold;
    aHold = mData[17]; mData[17] = mData[23]; mData[23] = aHold;
    aHold = mData[18]; mData[18] = mData[20]; mData[20] = aHold;
    aHold = mData[19]; mData[19] = mData[21]; mData[21] = aHold;
    aHold = mData[24]; mData[24] = mData[30]; mData[30] = aHold;
    aHold = mData[25]; mData[25] = mData[31]; mData[31] = aHold;
    aHold = mData[26]; mData[26] = mData[28]; mData[28] = aHold;
    aHold = mData[27]; mData[27] = mData[29]; mData[29] = aHold;
    aHold = mData[32]; mData[32] = mData[38]; mData[38] = aHold;
    aHold = mData[33]; mData[33] = mData[39]; mData[39] = aHold;
    aHold = mData[34]; mData[34] = mData[36]; mData[36] = aHold;
    aHold = mData[35]; mData[35] = mData[37]; mData[37] = aHold;
    aHold = mData[40]; mData[40] = mData[46]; mData[46] = aHold;
    aHold = mData[41]; mData[41] = mData[47]; mData[47] = aHold;
    aHold = mData[42]; mData[42] = mData[44]; mData[44] = aHold;
    aHold = mData[43]; mData[43] = mData[45]; mData[45] = aHold;
    aHold = mData[48]; mData[48] = mData[54]; mData[54] = aHold;
    aHold = mData[49]; mData[49] = mData[55]; mData[55] = aHold;
    aHold = mData[50]; mData[50] = mData[52]; mData[52] = aHold;
    aHold = mData[51]; mData[51] = mData[53]; mData[53] = aHold;
    aHold = mData[56]; mData[56] = mData[62]; mData[62] = aHold;
    aHold = mData[57]; mData[57] = mData[63]; mData[63] = aHold;
    aHold = mData[58]; mData[58] = mData[60]; mData[60] = aHold;
    aHold = mData[59]; mData[59] = mData[61]; mData[61] = aHold;
}

void M88::Full_FoldC_EachQuad_4x4() {
    Quad_FoldC_4x4_A();
    Quad_FoldC_4x4_B();
    Quad_FoldC_4x4_C();
    Quad_FoldC_4x4_D();
}

void M88::Quad_FoldC_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[3]; mData[3] = aHold;
    aHold = mData[1]; mData[1] = mData[2]; mData[2] = aHold;
    aHold = mData[8]; mData[8] = mData[11]; mData[11] = aHold;
    aHold = mData[9]; mData[9] = mData[10]; mData[10] = aHold;
    aHold = mData[16]; mData[16] = mData[19]; mData[19] = aHold;
    aHold = mData[17]; mData[17] = mData[18]; mData[18] = aHold;
    aHold = mData[24]; mData[24] = mData[27]; mData[27] = aHold;
    aHold = mData[25]; mData[25] = mData[26]; mData[26] = aHold;
}

void M88::Quad_FoldC_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[7]; mData[7] = aHold;
    aHold = mData[5]; mData[5] = mData[6]; mData[6] = aHold;
    aHold = mData[12]; mData[12] = mData[15]; mData[15] = aHold;
    aHold = mData[13]; mData[13] = mData[14]; mData[14] = aHold;
    aHold = mData[20]; mData[20] = mData[23]; mData[23] = aHold;
    aHold = mData[21]; mData[21] = mData[22]; mData[22] = aHold;
    aHold = mData[28]; mData[28] = mData[31]; mData[31] = aHold;
    aHold = mData[29]; mData[29] = mData[30]; mData[30] = aHold;
}

void M88::Quad_FoldC_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[35]; mData[35] = aHold;
    aHold = mData[33]; mData[33] = mData[34]; mData[34] = aHold;
    aHold = mData[40]; mData[40] = mData[43]; mData[43] = aHold;
    aHold = mData[41]; mData[41] = mData[42]; mData[42] = aHold;
    aHold = mData[48]; mData[48] = mData[51]; mData[51] = aHold;
    aHold = mData[49]; mData[49] = mData[50]; mData[50] = aHold;
    aHold = mData[56]; mData[56] = mData[59]; mData[59] = aHold;
    aHold = mData[57]; mData[57] = mData[58]; mData[58] = aHold;
}

void M88::Quad_FoldC_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[39]; mData[39] = aHold;
    aHold = mData[37]; mData[37] = mData[38]; mData[38] = aHold;
    aHold = mData[44]; mData[44] = mData[47]; mData[47] = aHold;
    aHold = mData[45]; mData[45] = mData[46]; mData[46] = aHold;
    aHold = mData[52]; mData[52] = mData[55]; mData[55] = aHold;
    aHold = mData[53]; mData[53] = mData[54]; mData[54] = aHold;
    aHold = mData[60]; mData[60] = mData[63]; mData[63] = aHold;
    aHold = mData[61]; mData[61] = mData[62]; mData[62] = aHold;
}


void M88::Full_FoldD_4x4() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[54]; mData[54] = aHold;
    aHold = mData[1]; mData[1] = mData[55]; mData[55] = aHold;
    aHold = mData[2]; mData[2] = mData[52]; mData[52] = aHold;
    aHold = mData[3]; mData[3] = mData[53]; mData[53] = aHold;
    aHold = mData[4]; mData[4] = mData[50]; mData[50] = aHold;
    aHold = mData[5]; mData[5] = mData[51]; mData[51] = aHold;
    aHold = mData[6]; mData[6] = mData[48]; mData[48] = aHold;
    aHold = mData[7]; mData[7] = mData[49]; mData[49] = aHold;
    aHold = mData[8]; mData[8] = mData[62]; mData[62] = aHold;
    aHold = mData[9]; mData[9] = mData[63]; mData[63] = aHold;
    aHold = mData[10]; mData[10] = mData[60]; mData[60] = aHold;
    aHold = mData[11]; mData[11] = mData[61]; mData[61] = aHold;
    aHold = mData[12]; mData[12] = mData[58]; mData[58] = aHold;
    aHold = mData[13]; mData[13] = mData[59]; mData[59] = aHold;
    aHold = mData[14]; mData[14] = mData[56]; mData[56] = aHold;
    aHold = mData[15]; mData[15] = mData[57]; mData[57] = aHold;
    aHold = mData[16]; mData[16] = mData[22]; mData[22] = aHold;
    aHold = mData[17]; mData[17] = mData[23]; mData[23] = aHold;
    aHold = mData[18]; mData[18] = mData[20]; mData[20] = aHold;
    aHold = mData[19]; mData[19] = mData[21]; mData[21] = aHold;
    aHold = mData[24]; mData[24] = mData[30]; mData[30] = aHold;
    aHold = mData[25]; mData[25] = mData[31]; mData[31] = aHold;
    aHold = mData[26]; mData[26] = mData[28]; mData[28] = aHold;
    aHold = mData[27]; mData[27] = mData[29]; mData[29] = aHold;
    aHold = mData[32]; mData[32] = mData[38]; mData[38] = aHold;
    aHold = mData[33]; mData[33] = mData[39]; mData[39] = aHold;
    aHold = mData[34]; mData[34] = mData[36]; mData[36] = aHold;
    aHold = mData[35]; mData[35] = mData[37]; mData[37] = aHold;
    aHold = mData[40]; mData[40] = mData[46]; mData[46] = aHold;
    aHold = mData[41]; mData[41] = mData[47]; mData[47] = aHold;
    aHold = mData[42]; mData[42] = mData[44]; mData[44] = aHold;
    aHold = mData[43]; mData[43] = mData[45]; mData[45] = aHold;
}

void M88::Full_FoldD_EachQuad_4x4() {
    Quad_FoldD_4x4_A();
    Quad_FoldD_4x4_B();
    Quad_FoldD_4x4_C();
    Quad_FoldD_4x4_D();
}

void M88::Quad_FoldD_4x4_A() {
    std::uint8_t aHold = 0;
    aHold = mData[0]; mData[0] = mData[27]; mData[27] = aHold;
    aHold = mData[1]; mData[1] = mData[26]; mData[26] = aHold;
    aHold = mData[2]; mData[2] = mData[25]; mData[25] = aHold;
    aHold = mData[3]; mData[3] = mData[24]; mData[24] = aHold;
    aHold = mData[8]; mData[8] = mData[11]; mData[11] = aHold;
    aHold = mData[9]; mData[9] = mData[10]; mData[10] = aHold;
    aHold = mData[16]; mData[16] = mData[19]; mData[19] = aHold;
    aHold = mData[17]; mData[17] = mData[18]; mData[18] = aHold;
}

void M88::Quad_FoldD_4x4_B() {
    std::uint8_t aHold = 0;
    aHold = mData[4]; mData[4] = mData[31]; mData[31] = aHold;
    aHold = mData[5]; mData[5] = mData[30]; mData[30] = aHold;
    aHold = mData[6]; mData[6] = mData[29]; mData[29] = aHold;
    aHold = mData[7]; mData[7] = mData[28]; mData[28] = aHold;
    aHold = mData[12]; mData[12] = mData[15]; mData[15] = aHold;
    aHold = mData[13]; mData[13] = mData[14]; mData[14] = aHold;
    aHold = mData[20]; mData[20] = mData[23]; mData[23] = aHold;
    aHold = mData[21]; mData[21] = mData[22]; mData[22] = aHold;
}

void M88::Quad_FoldD_4x4_C() {
    std::uint8_t aHold = 0;
    aHold = mData[32]; mData[32] = mData[59]; mData[59] = aHold;
    aHold = mData[33]; mData[33] = mData[58]; mData[58] = aHold;
    aHold = mData[34]; mData[34] = mData[57]; mData[57] = aHold;
    aHold = mData[35]; mData[35] = mData[56]; mData[56] = aHold;
    aHold = mData[40]; mData[40] = mData[43]; mData[43] = aHold;
    aHold = mData[41]; mData[41] = mData[42]; mData[42] = aHold;
    aHold = mData[48]; mData[48] = mData[51]; mData[51] = aHold;
    aHold = mData[49]; mData[49] = mData[50]; mData[50] = aHold;
}

void M88::Quad_FoldD_4x4_D() {
    std::uint8_t aHold = 0;
    aHold = mData[36]; mData[36] = mData[63]; mData[63] = aHold;
    aHold = mData[37]; mData[37] = mData[62]; mData[62] = aHold;
    aHold = mData[38]; mData[38] = mData[61]; mData[61] = aHold;
    aHold = mData[39]; mData[39] = mData[60]; mData[60] = aHold;
    aHold = mData[44]; mData[44] = mData[47]; mData[47] = aHold;
    aHold = mData[45]; mData[45] = mData[46]; mData[46] = aHold;
    aHold = mData[52]; mData[52] = mData[55]; mData[55] = aHold;
    aHold = mData[53]; mData[53] = mData[54]; mData[54] = aHold;
}


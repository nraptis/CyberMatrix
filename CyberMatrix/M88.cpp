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

Slice M88::GetQuarter(int pWhich) {
    switch (pWhich % 4) {
        case 0: return GetQuarterA();
        case 1: return GetQuarterB();
        case 2: return GetQuarterC();
        default: return GetQuarterD();
    }
}

Slice M88::GetQuarterA() {
    return Get(0, 0, 4);
}

Slice M88::GetQuarterB() {
    return Get(4, 0, 4);
}

Slice M88::GetQuarterC() {
    return Get(0, 4, 4);
}

Slice M88::GetQuarterD() {
    return Get(4, 4, 4);
}

Slice M88::GetSixteenth(int pWhich) {
    switch (pWhich % 16) {
        case 0:  return GetSixteenthA();
        case 1:  return GetSixteenthB();
        case 2:  return GetSixteenthC();
        case 3:  return GetSixteenthD();
        case 4:  return GetSixteenthE();
        case 5:  return GetSixteenthF();
        case 6:  return GetSixteenthG();
        case 7:  return GetSixteenthH();
        case 8:  return GetSixteenthI();
        case 9:  return GetSixteenthJ();
        case 10: return GetSixteenthK();
        case 11: return GetSixteenthL();
        case 12: return GetSixteenthM();
        case 13: return GetSixteenthN();
        case 14: return GetSixteenthO();
        default: return GetSixteenthP();
    }
}

void M88::SlickshotSix(std::uint8_t pByte) {
    typedef void (M88::*Fn)();

    static const Fn kTable[16][16] = {
        {
            &M88::RotASixA,
            &M88::RotASixB,
            &M88::RotASixC,
            &M88::RotASixD,
            &M88::RotASixE,
            &M88::RotASixF,
            &M88::RotASixG,
            &M88::RotASixH,
            &M88::RotASixI,
            &M88::RotASixJ,
            &M88::RotASixK,
            &M88::RotASixL,
            &M88::RotASixM,
            &M88::RotASixN,
            &M88::RotASixO,
            &M88::RotASixP
        },
        {
            &M88::RotBSixA,
            &M88::RotBSixB,
            &M88::RotBSixC,
            &M88::RotBSixD,
            &M88::RotBSixE,
            &M88::RotBSixF,
            &M88::RotBSixG,
            &M88::RotBSixH,
            &M88::RotBSixI,
            &M88::RotBSixJ,
            &M88::RotBSixK,
            &M88::RotBSixL,
            &M88::RotBSixM,
            &M88::RotBSixN,
            &M88::RotBSixO,
            &M88::RotBSixP
        },
        {
            &M88::FlipASixA,
            &M88::FlipASixB,
            &M88::FlipASixC,
            &M88::FlipASixD,
            &M88::FlipASixE,
            &M88::FlipASixF,
            &M88::FlipASixG,
            &M88::FlipASixH,
            &M88::FlipASixI,
            &M88::FlipASixJ,
            &M88::FlipASixK,
            &M88::FlipASixL,
            &M88::FlipASixM,
            &M88::FlipASixN,
            &M88::FlipASixO,
            &M88::FlipASixP
        },
        {
            &M88::FlipBSixA,
            &M88::FlipBSixB,
            &M88::FlipBSixC,
            &M88::FlipBSixD,
            &M88::FlipBSixE,
            &M88::FlipBSixF,
            &M88::FlipBSixG,
            &M88::FlipBSixH,
            &M88::FlipBSixI,
            &M88::FlipBSixJ,
            &M88::FlipBSixK,
            &M88::FlipBSixL,
            &M88::FlipBSixM,
            &M88::FlipBSixN,
            &M88::FlipBSixO,
            &M88::FlipBSixP
        },
        {
            &M88::SnakeASixA,
            &M88::SnakeASixB,
            &M88::SnakeASixC,
            &M88::SnakeASixD,
            &M88::SnakeASixE,
            &M88::SnakeASixF,
            &M88::SnakeASixG,
            &M88::SnakeASixH,
            &M88::SnakeASixI,
            &M88::SnakeASixJ,
            &M88::SnakeASixK,
            &M88::SnakeASixL,
            &M88::SnakeASixM,
            &M88::SnakeASixN,
            &M88::SnakeASixO,
            &M88::SnakeASixP
        },
        {
            &M88::SnakeBSixA,
            &M88::SnakeBSixB,
            &M88::SnakeBSixC,
            &M88::SnakeBSixD,
            &M88::SnakeBSixE,
            &M88::SnakeBSixF,
            &M88::SnakeBSixG,
            &M88::SnakeBSixH,
            &M88::SnakeBSixI,
            &M88::SnakeBSixJ,
            &M88::SnakeBSixK,
            &M88::SnakeBSixL,
            &M88::SnakeBSixM,
            &M88::SnakeBSixN,
            &M88::SnakeBSixO,
            &M88::SnakeBSixP
        },
        {
            &M88::SnakeCSixA,
            &M88::SnakeCSixB,
            &M88::SnakeCSixC,
            &M88::SnakeCSixD,
            &M88::SnakeCSixE,
            &M88::SnakeCSixF,
            &M88::SnakeCSixG,
            &M88::SnakeCSixH,
            &M88::SnakeCSixI,
            &M88::SnakeCSixJ,
            &M88::SnakeCSixK,
            &M88::SnakeCSixL,
            &M88::SnakeCSixM,
            &M88::SnakeCSixN,
            &M88::SnakeCSixO,
            &M88::SnakeCSixP
        },
        {
            &M88::SnakeDSixA,
            &M88::SnakeDSixB,
            &M88::SnakeDSixC,
            &M88::SnakeDSixD,
            &M88::SnakeDSixE,
            &M88::SnakeDSixF,
            &M88::SnakeDSixG,
            &M88::SnakeDSixH,
            &M88::SnakeDSixI,
            &M88::SnakeDSixJ,
            &M88::SnakeDSixK,
            &M88::SnakeDSixL,
            &M88::SnakeDSixM,
            &M88::SnakeDSixN,
            &M88::SnakeDSixO,
            &M88::SnakeDSixP
        },
        {
            &M88::TriadAASixA,
            &M88::TriadAASixB,
            &M88::TriadAASixC,
            &M88::TriadAASixD,
            &M88::TriadAASixE,
            &M88::TriadAASixF,
            &M88::TriadAASixG,
            &M88::TriadAASixH,
            &M88::TriadAASixI,
            &M88::TriadAASixJ,
            &M88::TriadAASixK,
            &M88::TriadAASixL,
            &M88::TriadAASixM,
            &M88::TriadAASixN,
            &M88::TriadAASixO,
            &M88::TriadAASixP
        },
        {
            &M88::TriadABSixA,
            &M88::TriadABSixB,
            &M88::TriadABSixC,
            &M88::TriadABSixD,
            &M88::TriadABSixE,
            &M88::TriadABSixF,
            &M88::TriadABSixG,
            &M88::TriadABSixH,
            &M88::TriadABSixI,
            &M88::TriadABSixJ,
            &M88::TriadABSixK,
            &M88::TriadABSixL,
            &M88::TriadABSixM,
            &M88::TriadABSixN,
            &M88::TriadABSixO,
            &M88::TriadABSixP
        },
        {
            &M88::TriadBASixA,
            &M88::TriadBASixB,
            &M88::TriadBASixC,
            &M88::TriadBASixD,
            &M88::TriadBASixE,
            &M88::TriadBASixF,
            &M88::TriadBASixG,
            &M88::TriadBASixH,
            &M88::TriadBASixI,
            &M88::TriadBASixJ,
            &M88::TriadBASixK,
            &M88::TriadBASixL,
            &M88::TriadBASixM,
            &M88::TriadBASixN,
            &M88::TriadBASixO,
            &M88::TriadBASixP
        },
        {
            &M88::TriadBBSixA,
            &M88::TriadBBSixB,
            &M88::TriadBBSixC,
            &M88::TriadBBSixD,
            &M88::TriadBBSixE,
            &M88::TriadBBSixF,
            &M88::TriadBBSixG,
            &M88::TriadBBSixH,
            &M88::TriadBBSixI,
            &M88::TriadBBSixJ,
            &M88::TriadBBSixK,
            &M88::TriadBBSixL,
            &M88::TriadBBSixM,
            &M88::TriadBBSixN,
            &M88::TriadBBSixO,
            &M88::TriadBBSixP
        },
        {
            &M88::TriadCASixA,
            &M88::TriadCASixB,
            &M88::TriadCASixC,
            &M88::TriadCASixD,
            &M88::TriadCASixE,
            &M88::TriadCASixF,
            &M88::TriadCASixG,
            &M88::TriadCASixH,
            &M88::TriadCASixI,
            &M88::TriadCASixJ,
            &M88::TriadCASixK,
            &M88::TriadCASixL,
            &M88::TriadCASixM,
            &M88::TriadCASixN,
            &M88::TriadCASixO,
            &M88::TriadCASixP
        },
        {
            &M88::TriadCBSixA,
            &M88::TriadCBSixB,
            &M88::TriadCBSixC,
            &M88::TriadCBSixD,
            &M88::TriadCBSixE,
            &M88::TriadCBSixF,
            &M88::TriadCBSixG,
            &M88::TriadCBSixH,
            &M88::TriadCBSixI,
            &M88::TriadCBSixJ,
            &M88::TriadCBSixK,
            &M88::TriadCBSixL,
            &M88::TriadCBSixM,
            &M88::TriadCBSixN,
            &M88::TriadCBSixO,
            &M88::TriadCBSixP
        },
        {
            &M88::TriadDASixA,
            &M88::TriadDASixB,
            &M88::TriadDASixC,
            &M88::TriadDASixD,
            &M88::TriadDASixE,
            &M88::TriadDASixF,
            &M88::TriadDASixG,
            &M88::TriadDASixH,
            &M88::TriadDASixI,
            &M88::TriadDASixJ,
            &M88::TriadDASixK,
            &M88::TriadDASixL,
            &M88::TriadDASixM,
            &M88::TriadDASixN,
            &M88::TriadDASixO,
            &M88::TriadDASixP
        },
        {
            &M88::TriadDBSixA,
            &M88::TriadDBSixB,
            &M88::TriadDBSixC,
            &M88::TriadDBSixD,
            &M88::TriadDBSixE,
            &M88::TriadDBSixF,
            &M88::TriadDBSixG,
            &M88::TriadDBSixH,
            &M88::TriadDBSixI,
            &M88::TriadDBSixJ,
            &M88::TriadDBSixK,
            &M88::TriadDBSixL,
            &M88::TriadDBSixM,
            &M88::TriadDBSixN,
            &M88::TriadDBSixO,
            &M88::TriadDBSixP
        }
    };
    
    const std::uint8_t aSix = pByte & 0x0FU;
    const std::uint8_t aOp = (pByte >> 4U) & 0x0FU;
    (this->*kTable[aOp][aSix])();
    
}

Slice M88::GetSixteenthA() {
    return Get(0, 0, 2);
}

Slice M88::GetSixteenthB() {
    return Get(2, 0, 2);
}

Slice M88::GetSixteenthC() {
    return Get(4, 0, 2);
}

Slice M88::GetSixteenthD() {
    return Get(6, 0, 2);
}

Slice M88::GetSixteenthE() {
    return Get(0, 2, 2);
}

Slice M88::GetSixteenthF() {
    return Get(2, 2, 2);
}

Slice M88::GetSixteenthG() {
    return Get(4, 2, 2);
}

Slice M88::GetSixteenthH() {
    return Get(6, 2, 2);
}

Slice M88::GetSixteenthI() {
    return Get(0, 4, 2);
}

Slice M88::GetSixteenthJ() {
    return Get(2, 4, 2);
}

Slice M88::GetSixteenthK() {
    return Get(4, 4, 2);
}

Slice M88::GetSixteenthL() {
    return Get(6, 4, 2);
}

Slice M88::GetSixteenthM() {
    return Get(0, 6, 2);
}

Slice M88::GetSixteenthN() {
    return Get(2, 6, 2);
}

Slice M88::GetSixteenthO() {
    return Get(4, 6, 2);
}

Slice M88::GetSixteenthP() {
    return Get(6, 6, 2);
}

void M88::RotateRightQuarterA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[24]; mData[24] = mData[27]; mData[27] = mData[3];
    mData[3] = aHold;

    // cycle 1
    aHold = mData[1]; mData[1] = mData[16]; mData[16] = mData[26]; mData[26] = mData[11];
    mData[11] = aHold;

    // cycle 2
    aHold = mData[2]; mData[2] = mData[8]; mData[8] = mData[25]; mData[25] = mData[19];
    mData[19] = aHold;

    // cycle 3
    aHold = mData[9]; mData[9] = mData[17]; mData[17] = mData[18]; mData[18] = mData[10];
    mData[10] = aHold;

}

void M88::CastleAQuarterA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[10]; mData[10] = aHold;

    // cycle 1
    aHold = mData[1]; mData[1] = mData[19]; mData[19] = mData[26]; mData[26] = mData[8];
    mData[8] = aHold;

    // cycle 2
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = mData[25]; mData[25] = mData[16];
    mData[16] = aHold;

    // cycle 3
    aHold = mData[3]; mData[3] = mData[18]; mData[18] = aHold;

    // cycle 4
    aHold = mData[9]; mData[9] = mData[24]; mData[24] = aHold;

    // cycle 5
    aHold = mData[17]; mData[17] = mData[27]; mData[27] = aHold;

}

void M88::CastleBQuarterA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[17]; mData[17] = aHold;

    // cycle 1
    aHold = mData[1]; mData[1] = mData[8]; mData[8] = mData[26]; mData[26] = mData[19];
    mData[19] = aHold;

    // cycle 2
    aHold = mData[2]; mData[2] = mData[16]; mData[16] = mData[25]; mData[25] = mData[11];
    mData[11] = aHold;

    // cycle 3
    aHold = mData[3]; mData[3] = mData[9]; mData[9] = aHold;

    // cycle 4
    aHold = mData[10]; mData[10] = mData[27]; mData[27] = aHold;

    // cycle 5
    aHold = mData[18]; mData[18] = mData[24]; mData[24] = aHold;

}






void M88::RotA() {
    std::uint8_t aHold = 0;
    
    // cycle 0
    aHold = mData[0]; mData[0] = mData[56]; mData[56] = mData[63]; mData[63] = mData[7];
    mData[7] = aHold;
    
    // cycle 1
    aHold = mData[1]; mData[1] = mData[48]; mData[48] = mData[62]; mData[62] = mData[15];
    mData[15] = aHold;
    
    // cycle 2
    aHold = mData[2]; mData[2] = mData[40]; mData[40] = mData[61]; mData[61] = mData[23];
    mData[23] = aHold;
    
    // cycle 3
    aHold = mData[3]; mData[3] = mData[32]; mData[32] = mData[60]; mData[60] = mData[31];
    mData[31] = aHold;
    
    // cycle 4
    aHold = mData[4]; mData[4] = mData[24]; mData[24] = mData[59]; mData[59] = mData[39];
    mData[39] = aHold;
    
    // cycle 5
    aHold = mData[5]; mData[5] = mData[16]; mData[16] = mData[58]; mData[58] = mData[47];
    mData[47] = aHold;
    
    // cycle 6
    aHold = mData[6]; mData[6] = mData[8]; mData[8] = mData[57]; mData[57] = mData[55];
    mData[55] = aHold;
    
    // cycle 7
    aHold = mData[9]; mData[9] = mData[49]; mData[49] = mData[54]; mData[54] = mData[14];
    mData[14] = aHold;
    
    // cycle 8
    aHold = mData[10]; mData[10] = mData[41]; mData[41] = mData[53]; mData[53] = mData[22];
    mData[22] = aHold;
    
    // cycle 9
    aHold = mData[11]; mData[11] = mData[33]; mData[33] = mData[52]; mData[52] = mData[30];
    mData[30] = aHold;
    
    // cycle 10
    aHold = mData[12]; mData[12] = mData[25]; mData[25] = mData[51]; mData[51] = mData[38];
    mData[38] = aHold;
    
    // cycle 11
    aHold = mData[13]; mData[13] = mData[17]; mData[17] = mData[50]; mData[50] = mData[46];
    mData[46] = aHold;
    
    // cycle 12
    aHold = mData[18]; mData[18] = mData[42]; mData[42] = mData[45]; mData[45] = mData[21];
    mData[21] = aHold;
    
    // cycle 13
    aHold = mData[19]; mData[19] = mData[34]; mData[34] = mData[44]; mData[44] = mData[29];
    mData[29] = aHold;
    
    // cycle 14
    aHold = mData[20]; mData[20] = mData[26]; mData[26] = mData[43]; mData[43] = mData[37];
    mData[37] = aHold;
    
    // cycle 15
    aHold = mData[27]; mData[27] = mData[35]; mData[35] = mData[36]; mData[36] = mData[28];
    mData[28] = aHold;
    
}

void M88::RotB() {
    std::uint8_t aHold = 0;
    
    // cycle 0
    aHold = mData[0]; mData[0] = mData[7]; mData[7] = mData[63]; mData[63] = mData[56];
    mData[56] = aHold;
    
    // cycle 1
    aHold = mData[1]; mData[1] = mData[15]; mData[15] = mData[62]; mData[62] = mData[48];
    mData[48] = aHold;
    
    // cycle 2
    aHold = mData[2]; mData[2] = mData[23]; mData[23] = mData[61]; mData[61] = mData[40];
    mData[40] = aHold;
    
    // cycle 3
    aHold = mData[3]; mData[3] = mData[31]; mData[31] = mData[60]; mData[60] = mData[32];
    mData[32] = aHold;
    
    // cycle 4
    aHold = mData[4]; mData[4] = mData[39]; mData[39] = mData[59]; mData[59] = mData[24];
    mData[24] = aHold;
    
    // cycle 5
    aHold = mData[5]; mData[5] = mData[47]; mData[47] = mData[58]; mData[58] = mData[16];
    mData[16] = aHold;
    
    // cycle 6
    aHold = mData[6]; mData[6] = mData[55]; mData[55] = mData[57]; mData[57] = mData[8];
    mData[8] = aHold;
    
    // cycle 7
    aHold = mData[9]; mData[9] = mData[14]; mData[14] = mData[54]; mData[54] = mData[49];
    mData[49] = aHold;
    
    // cycle 8
    aHold = mData[10]; mData[10] = mData[22]; mData[22] = mData[53]; mData[53] = mData[41];
    mData[41] = aHold;
    
    // cycle 9
    aHold = mData[11]; mData[11] = mData[30]; mData[30] = mData[52]; mData[52] = mData[33];
    mData[33] = aHold;
    
    // cycle 10
    aHold = mData[12]; mData[12] = mData[38]; mData[38] = mData[51]; mData[51] = mData[25];
    mData[25] = aHold;
    
    // cycle 11
    aHold = mData[13]; mData[13] = mData[46]; mData[46] = mData[50]; mData[50] = mData[17];
    mData[17] = aHold;
    
    // cycle 12
    aHold = mData[18]; mData[18] = mData[21]; mData[21] = mData[45]; mData[45] = mData[42];
    mData[42] = aHold;
    
    // cycle 13
    aHold = mData[19]; mData[19] = mData[29]; mData[29] = mData[44]; mData[44] = mData[34];
    mData[34] = aHold;
    
    // cycle 14
    aHold = mData[20]; mData[20] = mData[37]; mData[37] = mData[43]; mData[43] = mData[26];
    mData[26] = aHold;
    
    // cycle 15
    aHold = mData[27]; mData[27] = mData[28]; mData[28] = mData[36]; mData[36] = mData[35];
    mData[35] = aHold;
    
}

void M88::RotC() {
    std::uint8_t aHold = 0;
    
    // cycle 0
    aHold = mData[0]; mData[0] = mData[63]; mData[63] = aHold;
    
    // cycle 1
    aHold = mData[1]; mData[1] = mData[62]; mData[62] = aHold;
    
    // cycle 2
    aHold = mData[2]; mData[2] = mData[61]; mData[61] = aHold;
    
    // cycle 3
    aHold = mData[3]; mData[3] = mData[60]; mData[60] = aHold;
    
    // cycle 4
    aHold = mData[4]; mData[4] = mData[59]; mData[59] = aHold;
    
    // cycle 5
    aHold = mData[5]; mData[5] = mData[58]; mData[58] = aHold;
    
    // cycle 6
    aHold = mData[6]; mData[6] = mData[57]; mData[57] = aHold;
    
    // cycle 7
    aHold = mData[7]; mData[7] = mData[56]; mData[56] = aHold;
    
    // cycle 8
    aHold = mData[8]; mData[8] = mData[55]; mData[55] = aHold;
    
    // cycle 9
    aHold = mData[9]; mData[9] = mData[54]; mData[54] = aHold;
    
    // cycle 10
    aHold = mData[10]; mData[10] = mData[53]; mData[53] = aHold;
    
    // cycle 11
    aHold = mData[11]; mData[11] = mData[52]; mData[52] = aHold;
    
    // cycle 12
    aHold = mData[12]; mData[12] = mData[51]; mData[51] = aHold;
    
    // cycle 13
    aHold = mData[13]; mData[13] = mData[50]; mData[50] = aHold;
    
    // cycle 14
    aHold = mData[14]; mData[14] = mData[49]; mData[49] = aHold;
    
    // cycle 15
    aHold = mData[15]; mData[15] = mData[48]; mData[48] = aHold;
    
    // cycle 16
    aHold = mData[16]; mData[16] = mData[47]; mData[47] = aHold;
    
    // cycle 17
    aHold = mData[17]; mData[17] = mData[46]; mData[46] = aHold;
    
    // cycle 18
    aHold = mData[18]; mData[18] = mData[45]; mData[45] = aHold;
    
    // cycle 19
    aHold = mData[19]; mData[19] = mData[44]; mData[44] = aHold;
    
    // cycle 20
    aHold = mData[20]; mData[20] = mData[43]; mData[43] = aHold;
    
    // cycle 21
    aHold = mData[21]; mData[21] = mData[42]; mData[42] = aHold;
    
    // cycle 22
    aHold = mData[22]; mData[22] = mData[41]; mData[41] = aHold;
    
    // cycle 23
    aHold = mData[23]; mData[23] = mData[40]; mData[40] = aHold;
    
    // cycle 24
    aHold = mData[24]; mData[24] = mData[39]; mData[39] = aHold;
    
    // cycle 25
    aHold = mData[25]; mData[25] = mData[38]; mData[38] = aHold;
    
    // cycle 26
    aHold = mData[26]; mData[26] = mData[37]; mData[37] = aHold;
    
    // cycle 27
    aHold = mData[27]; mData[27] = mData[36]; mData[36] = aHold;
    
    // cycle 28
    aHold = mData[28]; mData[28] = mData[35]; mData[35] = aHold;
    
    // cycle 29
    aHold = mData[29]; mData[29] = mData[34]; mData[34] = aHold;
    
    // cycle 30
    aHold = mData[30]; mData[30] = mData[33]; mData[33] = aHold;
    
    // cycle 31
    aHold = mData[31]; mData[31] = mData[32]; mData[32] = aHold;
    
}


void M88::BlockRotA() {
    std::uint8_t aHold = 0;
    
    // cycle 0
    aHold = mData[0]; mData[0] = mData[32]; mData[32] = mData[36]; mData[36] = mData[4];
    mData[4] = aHold;
    
    // cycle 1
    aHold = mData[1]; mData[1] = mData[33]; mData[33] = mData[37]; mData[37] = mData[5];
    mData[5] = aHold;
    
    // cycle 2
    aHold = mData[2]; mData[2] = mData[34]; mData[34] = mData[38]; mData[38] = mData[6];
    mData[6] = aHold;
    
    // cycle 3
    aHold = mData[3]; mData[3] = mData[35]; mData[35] = mData[39]; mData[39] = mData[7];
    mData[7] = aHold;
    
    // cycle 4
    aHold = mData[8]; mData[8] = mData[40]; mData[40] = mData[44]; mData[44] = mData[12];
    mData[12] = aHold;
    
    // cycle 5
    aHold = mData[9]; mData[9] = mData[41]; mData[41] = mData[45]; mData[45] = mData[13];
    mData[13] = aHold;
    
    // cycle 6
    aHold = mData[10]; mData[10] = mData[42]; mData[42] = mData[46]; mData[46] = mData[14];
    mData[14] = aHold;
    
    // cycle 7
    aHold = mData[11]; mData[11] = mData[43]; mData[43] = mData[47]; mData[47] = mData[15];
    mData[15] = aHold;
    
    // cycle 8
    aHold = mData[16]; mData[16] = mData[48]; mData[48] = mData[52]; mData[52] = mData[20];
    mData[20] = aHold;
    
    // cycle 9
    aHold = mData[17]; mData[17] = mData[49]; mData[49] = mData[53]; mData[53] = mData[21];
    mData[21] = aHold;
    
    // cycle 10
    aHold = mData[18]; mData[18] = mData[50]; mData[50] = mData[54]; mData[54] = mData[22];
    mData[22] = aHold;
    
    // cycle 11
    aHold = mData[19]; mData[19] = mData[51]; mData[51] = mData[55]; mData[55] = mData[23];
    mData[23] = aHold;
    
    // cycle 12
    aHold = mData[24]; mData[24] = mData[56]; mData[56] = mData[60]; mData[60] = mData[28];
    mData[28] = aHold;
    
    // cycle 13
    aHold = mData[25]; mData[25] = mData[57]; mData[57] = mData[61]; mData[61] = mData[29];
    mData[29] = aHold;
    
    // cycle 14
    aHold = mData[26]; mData[26] = mData[58]; mData[58] = mData[62]; mData[62] = mData[30];
    mData[30] = aHold;
    
    // cycle 15
    aHold = mData[27]; mData[27] = mData[59]; mData[59] = mData[63]; mData[63] = mData[31];
    mData[31] = aHold;
    
}

void M88::BlockRotB() {
    std::uint8_t aHold = 0;
    
    // cycle 0
    aHold = mData[0]; mData[0] = mData[4]; mData[4] = mData[36]; mData[36] = mData[32];
    mData[32] = aHold;
    
    // cycle 1
    aHold = mData[1]; mData[1] = mData[5]; mData[5] = mData[37]; mData[37] = mData[33];
    mData[33] = aHold;
    
    // cycle 2
    aHold = mData[2]; mData[2] = mData[6]; mData[6] = mData[38]; mData[38] = mData[34];
    mData[34] = aHold;
    
    // cycle 3
    aHold = mData[3]; mData[3] = mData[7]; mData[7] = mData[39]; mData[39] = mData[35];
    mData[35] = aHold;
    
    // cycle 4
    aHold = mData[8]; mData[8] = mData[12]; mData[12] = mData[44]; mData[44] = mData[40];
    mData[40] = aHold;
    
    // cycle 5
    aHold = mData[9]; mData[9] = mData[13]; mData[13] = mData[45]; mData[45] = mData[41];
    mData[41] = aHold;
    
    // cycle 6
    aHold = mData[10]; mData[10] = mData[14]; mData[14] = mData[46]; mData[46] = mData[42];
    mData[42] = aHold;
    
    // cycle 7
    aHold = mData[11]; mData[11] = mData[15]; mData[15] = mData[47]; mData[47] = mData[43];
    mData[43] = aHold;
    
    // cycle 8
    aHold = mData[16]; mData[16] = mData[20]; mData[20] = mData[52]; mData[52] = mData[48];
    mData[48] = aHold;
    
    // cycle 9
    aHold = mData[17]; mData[17] = mData[21]; mData[21] = mData[53]; mData[53] = mData[49];
    mData[49] = aHold;
    
    // cycle 10
    aHold = mData[18]; mData[18] = mData[22]; mData[22] = mData[54]; mData[54] = mData[50];
    mData[50] = aHold;
    
    // cycle 11
    aHold = mData[19]; mData[19] = mData[23]; mData[23] = mData[55]; mData[55] = mData[51];
    mData[51] = aHold;
    
    // cycle 12
    aHold = mData[24]; mData[24] = mData[28]; mData[28] = mData[60]; mData[60] = mData[56];
    mData[56] = aHold;
    
    // cycle 13
    aHold = mData[25]; mData[25] = mData[29]; mData[29] = mData[61]; mData[61] = mData[57];
    mData[57] = aHold;
    
    // cycle 14
    aHold = mData[26]; mData[26] = mData[30]; mData[30] = mData[62]; mData[62] = mData[58];
    mData[58] = aHold;
    
    // cycle 15
    aHold = mData[27]; mData[27] = mData[31]; mData[31] = mData[63]; mData[63] = mData[59];
    mData[59] = aHold;
    
}

void M88::BlockRotC() {
    std::uint8_t aHold = 0;
    
    // cycle 0
    aHold = mData[0]; mData[0] = mData[36]; mData[36] = aHold;
    
    // cycle 1
    aHold = mData[1]; mData[1] = mData[37]; mData[37] = aHold;
    
    // cycle 2
    aHold = mData[2]; mData[2] = mData[38]; mData[38] = aHold;
    
    // cycle 3
    aHold = mData[3]; mData[3] = mData[39]; mData[39] = aHold;
    
    // cycle 4
    aHold = mData[4]; mData[4] = mData[32]; mData[32] = aHold;
    
    // cycle 5
    aHold = mData[5]; mData[5] = mData[33]; mData[33] = aHold;
    
    // cycle 6
    aHold = mData[6]; mData[6] = mData[34]; mData[34] = aHold;
    
    // cycle 7
    aHold = mData[7]; mData[7] = mData[35]; mData[35] = aHold;
    
    // cycle 8
    aHold = mData[8]; mData[8] = mData[44]; mData[44] = aHold;
    
    // cycle 9
    aHold = mData[9]; mData[9] = mData[45]; mData[45] = aHold;
    
    // cycle 10
    aHold = mData[10]; mData[10] = mData[46]; mData[46] = aHold;
    
    // cycle 11
    aHold = mData[11]; mData[11] = mData[47]; mData[47] = aHold;
    
    // cycle 12
    aHold = mData[12]; mData[12] = mData[40]; mData[40] = aHold;
    
    // cycle 13
    aHold = mData[13]; mData[13] = mData[41]; mData[41] = aHold;
    
    // cycle 14
    aHold = mData[14]; mData[14] = mData[42]; mData[42] = aHold;
    
    // cycle 15
    aHold = mData[15]; mData[15] = mData[43]; mData[43] = aHold;
    
    // cycle 16
    aHold = mData[16]; mData[16] = mData[52]; mData[52] = aHold;
    
    // cycle 17
    aHold = mData[17]; mData[17] = mData[53]; mData[53] = aHold;
    
    // cycle 18
    aHold = mData[18]; mData[18] = mData[54]; mData[54] = aHold;
    
    // cycle 19
    aHold = mData[19]; mData[19] = mData[55]; mData[55] = aHold;
    
    // cycle 20
    aHold = mData[20]; mData[20] = mData[48]; mData[48] = aHold;
    
    // cycle 21
    aHold = mData[21]; mData[21] = mData[49]; mData[49] = aHold;
    
    // cycle 22
    aHold = mData[22]; mData[22] = mData[50]; mData[50] = aHold;
    
    // cycle 23
    aHold = mData[23]; mData[23] = mData[51]; mData[51] = aHold;
    
    // cycle 24
    aHold = mData[24]; mData[24] = mData[60]; mData[60] = aHold;
    
    // cycle 25
    aHold = mData[25]; mData[25] = mData[61]; mData[61] = aHold;
    
    // cycle 26
    aHold = mData[26]; mData[26] = mData[62]; mData[62] = aHold;
    
    // cycle 27
    aHold = mData[27]; mData[27] = mData[63]; mData[63] = aHold;
    
    // cycle 28
    aHold = mData[28]; mData[28] = mData[56]; mData[56] = aHold;
    
    // cycle 29
    aHold = mData[29]; mData[29] = mData[57]; mData[57] = aHold;
    
    // cycle 30
    aHold = mData[30]; mData[30] = mData[58]; mData[58] = aHold;
    
    // cycle 31
    aHold = mData[31]; mData[31] = mData[59]; mData[59] = aHold;
    
}

void M88::PylonRotA() {
    std::uint8_t aHold = 0;
    
    // cycle 0
    aHold = mData[0]; mData[0] = mData[48]; mData[48] = mData[54]; mData[54] = mData[6];
    mData[6] = aHold;
    
    // cycle 1
    aHold = mData[1]; mData[1] = mData[49]; mData[49] = mData[55]; mData[55] = mData[7];
    mData[7] = aHold;
    
    // cycle 2
    aHold = mData[2]; mData[2] = mData[32]; mData[32] = mData[52]; mData[52] = mData[22];
    mData[22] = aHold;
    
    // cycle 3
    aHold = mData[3]; mData[3] = mData[33]; mData[33] = mData[53]; mData[53] = mData[23];
    mData[23] = aHold;
    
    // cycle 4
    aHold = mData[4]; mData[4] = mData[16]; mData[16] = mData[50]; mData[50] = mData[38];
    mData[38] = aHold;
    
    // cycle 5
    aHold = mData[5]; mData[5] = mData[17]; mData[17] = mData[51]; mData[51] = mData[39];
    mData[39] = aHold;
    
    // cycle 6
    aHold = mData[8]; mData[8] = mData[56]; mData[56] = mData[62]; mData[62] = mData[14];
    mData[14] = aHold;
    
    // cycle 7
    aHold = mData[9]; mData[9] = mData[57]; mData[57] = mData[63]; mData[63] = mData[15];
    mData[15] = aHold;
    
    // cycle 8
    aHold = mData[10]; mData[10] = mData[40]; mData[40] = mData[60]; mData[60] = mData[30];
    mData[30] = aHold;
    
    // cycle 9
    aHold = mData[11]; mData[11] = mData[41]; mData[41] = mData[61]; mData[61] = mData[31];
    mData[31] = aHold;
    
    // cycle 10
    aHold = mData[12]; mData[12] = mData[24]; mData[24] = mData[58]; mData[58] = mData[46];
    mData[46] = aHold;
    
    // cycle 11
    aHold = mData[13]; mData[13] = mData[25]; mData[25] = mData[59]; mData[59] = mData[47];
    mData[47] = aHold;
    
    // cycle 12
    aHold = mData[18]; mData[18] = mData[34]; mData[34] = mData[36]; mData[36] = mData[20];
    mData[20] = aHold;
    
    // cycle 13
    aHold = mData[19]; mData[19] = mData[35]; mData[35] = mData[37]; mData[37] = mData[21];
    mData[21] = aHold;
    
    // cycle 14
    aHold = mData[26]; mData[26] = mData[42]; mData[42] = mData[44]; mData[44] = mData[28];
    mData[28] = aHold;
    
    // cycle 15
    aHold = mData[27]; mData[27] = mData[43]; mData[43] = mData[45]; mData[45] = mData[29];
    mData[29] = aHold;
    
}

void M88::PylonRotB() {
    std::uint8_t aHold = 0;
    
    // cycle 0
    aHold = mData[0]; mData[0] = mData[6]; mData[6] = mData[54]; mData[54] = mData[48];
    mData[48] = aHold;
    
    // cycle 1
    aHold = mData[1]; mData[1] = mData[7]; mData[7] = mData[55]; mData[55] = mData[49];
    mData[49] = aHold;
    
    // cycle 2
    aHold = mData[2]; mData[2] = mData[22]; mData[22] = mData[52]; mData[52] = mData[32];
    mData[32] = aHold;
    
    // cycle 3
    aHold = mData[3]; mData[3] = mData[23]; mData[23] = mData[53]; mData[53] = mData[33];
    mData[33] = aHold;
    
    // cycle 4
    aHold = mData[4]; mData[4] = mData[38]; mData[38] = mData[50]; mData[50] = mData[16];
    mData[16] = aHold;
    
    // cycle 5
    aHold = mData[5]; mData[5] = mData[39]; mData[39] = mData[51]; mData[51] = mData[17];
    mData[17] = aHold;
    
    // cycle 6
    aHold = mData[8]; mData[8] = mData[14]; mData[14] = mData[62]; mData[62] = mData[56];
    mData[56] = aHold;
    
    // cycle 7
    aHold = mData[9]; mData[9] = mData[15]; mData[15] = mData[63]; mData[63] = mData[57];
    mData[57] = aHold;
    
    // cycle 8
    aHold = mData[10]; mData[10] = mData[30]; mData[30] = mData[60]; mData[60] = mData[40];
    mData[40] = aHold;
    
    // cycle 9
    aHold = mData[11]; mData[11] = mData[31]; mData[31] = mData[61]; mData[61] = mData[41];
    mData[41] = aHold;
    
    // cycle 10
    aHold = mData[12]; mData[12] = mData[46]; mData[46] = mData[58]; mData[58] = mData[24];
    mData[24] = aHold;
    
    // cycle 11
    aHold = mData[13]; mData[13] = mData[47]; mData[47] = mData[59]; mData[59] = mData[25];
    mData[25] = aHold;
    
    // cycle 12
    aHold = mData[18]; mData[18] = mData[20]; mData[20] = mData[36]; mData[36] = mData[34];
    mData[34] = aHold;
    
    // cycle 13
    aHold = mData[19]; mData[19] = mData[21]; mData[21] = mData[37]; mData[37] = mData[35];
    mData[35] = aHold;
    
    // cycle 14
    aHold = mData[26]; mData[26] = mData[28]; mData[28] = mData[44]; mData[44] = mData[42];
    mData[42] = aHold;
    
    // cycle 15
    aHold = mData[27]; mData[27] = mData[29]; mData[29] = mData[45]; mData[45] = mData[43];
    mData[43] = aHold;
    
}

void M88::PylonRotC() {
    std::uint8_t aHold = 0;
    
    // cycle 0
    aHold = mData[0]; mData[0] = mData[54]; mData[54] = aHold;
    
    // cycle 1
    aHold = mData[1]; mData[1] = mData[55]; mData[55] = aHold;
    
    // cycle 2
    aHold = mData[2]; mData[2] = mData[52]; mData[52] = aHold;
    
    // cycle 3
    aHold = mData[3]; mData[3] = mData[53]; mData[53] = aHold;
    
    // cycle 4
    aHold = mData[4]; mData[4] = mData[50]; mData[50] = aHold;
    
    // cycle 5
    aHold = mData[5]; mData[5] = mData[51]; mData[51] = aHold;
    
    // cycle 6
    aHold = mData[6]; mData[6] = mData[48]; mData[48] = aHold;
    
    // cycle 7
    aHold = mData[7]; mData[7] = mData[49]; mData[49] = aHold;
    
    // cycle 8
    aHold = mData[8]; mData[8] = mData[62]; mData[62] = aHold;
    
    // cycle 9
    aHold = mData[9]; mData[9] = mData[63]; mData[63] = aHold;
    
    // cycle 10
    aHold = mData[10]; mData[10] = mData[60]; mData[60] = aHold;
    
    // cycle 11
    aHold = mData[11]; mData[11] = mData[61]; mData[61] = aHold;
    
    // cycle 12
    aHold = mData[12]; mData[12] = mData[58]; mData[58] = aHold;
    
    // cycle 13
    aHold = mData[13]; mData[13] = mData[59]; mData[59] = aHold;
    
    // cycle 14
    aHold = mData[14]; mData[14] = mData[56]; mData[56] = aHold;
    
    // cycle 15
    aHold = mData[15]; mData[15] = mData[57]; mData[57] = aHold;
    
    // cycle 16
    aHold = mData[16]; mData[16] = mData[38]; mData[38] = aHold;
    
    // cycle 17
    aHold = mData[17]; mData[17] = mData[39]; mData[39] = aHold;
    
    // cycle 18
    aHold = mData[18]; mData[18] = mData[36]; mData[36] = aHold;
    
    // cycle 19
    aHold = mData[19]; mData[19] = mData[37]; mData[37] = aHold;
    
    // cycle 20
    aHold = mData[20]; mData[20] = mData[34]; mData[34] = aHold;
    
    // cycle 21
    aHold = mData[21]; mData[21] = mData[35]; mData[35] = aHold;
    
    // cycle 22
    aHold = mData[22]; mData[22] = mData[32]; mData[32] = aHold;
    
    // cycle 23
    aHold = mData[23]; mData[23] = mData[33]; mData[33] = aHold;
    
    // cycle 24
    aHold = mData[24]; mData[24] = mData[46]; mData[46] = aHold;
    
    // cycle 25
    aHold = mData[25]; mData[25] = mData[47]; mData[47] = aHold;
    
    // cycle 26
    aHold = mData[26]; mData[26] = mData[44]; mData[44] = aHold;
    
    // cycle 27
    aHold = mData[27]; mData[27] = mData[45]; mData[45] = aHold;
    
    // cycle 28
    aHold = mData[28]; mData[28] = mData[42]; mData[42] = aHold;
    
    // cycle 29
    aHold = mData[29]; mData[29] = mData[43]; mData[43] = aHold;
    
    // cycle 30
    aHold = mData[30]; mData[30] = mData[40]; mData[40] = aHold;
    
    // cycle 31
    aHold = mData[31]; mData[31] = mData[41]; mData[41] = aHold;
}


void M88::RotASixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = mData[9]; mData[9] = mData[1];
    mData[1] = aHold;

}


    
void M88::RotASixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = mData[11]; mData[11] = mData[3];
    mData[3] = aHold;

}

void M88::RotASixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = mData[13]; mData[13] = mData[5];
    mData[5] = aHold;

}

void M88::RotASixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = mData[15]; mData[15] = mData[7];
    mData[7] = aHold;

}

void M88::RotASixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = mData[25]; mData[25] = mData[17];
    mData[17] = aHold;

}

void M88::RotASixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = mData[27]; mData[27] = mData[19];
    mData[19] = aHold;

}

void M88::RotASixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = mData[29]; mData[29] = mData[21];
    mData[21] = aHold;

}

void M88::RotASixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = mData[31]; mData[31] = mData[23];
    mData[23] = aHold;

}

void M88::RotASixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = mData[41]; mData[41] = mData[33];
    mData[33] = aHold;

}

void M88::RotASixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = mData[43]; mData[43] = mData[35];
    mData[35] = aHold;

}

void M88::RotASixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = mData[45]; mData[45] = mData[37];
    mData[37] = aHold;

}

void M88::RotASixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = mData[47]; mData[47] = mData[39];
    mData[39] = aHold;

}

void M88::RotASixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = mData[57]; mData[57] = mData[49];
    mData[49] = aHold;

}

void M88::RotASixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = mData[59]; mData[59] = mData[51];
    mData[51] = aHold;

}

void M88::RotASixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = mData[61]; mData[61] = mData[53];
    mData[53] = aHold;

}

void M88::RotASixP() {
    std::uint8_t aHold = 0;
    
    // cycle 0
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = mData[63]; mData[63] = mData[55];
    mData[55] = aHold;
    
}



void M88::RotBSixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = mData[9]; mData[9] = mData[8];
    mData[8] = aHold;

}

void M88::RotBSixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = mData[11]; mData[11] = mData[10];
    mData[10] = aHold;

}

void M88::RotBSixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = mData[13]; mData[13] = mData[12];
    mData[12] = aHold;

}

void M88::RotBSixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = mData[15]; mData[15] = mData[14];
    mData[14] = aHold;

}

void M88::RotBSixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = mData[25]; mData[25] = mData[24];
    mData[24] = aHold;

}

void M88::RotBSixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = mData[27]; mData[27] = mData[26];
    mData[26] = aHold;

}

void M88::RotBSixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = mData[29]; mData[29] = mData[28];
    mData[28] = aHold;

}

void M88::RotBSixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = mData[31]; mData[31] = mData[30];
    mData[30] = aHold;

}

void M88::RotBSixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = mData[41]; mData[41] = mData[40];
    mData[40] = aHold;

}

void M88::RotBSixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = mData[43]; mData[43] = mData[42];
    mData[42] = aHold;

}

void M88::RotBSixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = mData[45]; mData[45] = mData[44];
    mData[44] = aHold;

}

void M88::RotBSixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = mData[47]; mData[47] = mData[46];
    mData[46] = aHold;

}

void M88::RotBSixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = mData[57]; mData[57] = mData[56];
    mData[56] = aHold;

}

void M88::RotBSixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = mData[59]; mData[59] = mData[58];
    mData[58] = aHold;

}

void M88::RotBSixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = mData[61]; mData[61] = mData[60];
    mData[60] = aHold;

}

void M88::RotBSixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = mData[63]; mData[63] = mData[62];
    mData[62] = aHold;

}

void M88::FlipASixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = aHold;

    // cycle 1
    aHold = mData[8]; mData[8] = mData[9]; mData[9] = aHold;

}

void M88::FlipASixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = aHold;

    // cycle 1
    aHold = mData[10]; mData[10] = mData[11]; mData[11] = aHold;

}

void M88::FlipASixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = aHold;

    // cycle 1
    aHold = mData[12]; mData[12] = mData[13]; mData[13] = aHold;

}

void M88::FlipASixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = aHold;

    // cycle 1
    aHold = mData[14]; mData[14] = mData[15]; mData[15] = aHold;

}

void M88::FlipASixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = aHold;

    // cycle 1
    aHold = mData[24]; mData[24] = mData[25]; mData[25] = aHold;

}

void M88::FlipASixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = aHold;

    // cycle 1
    aHold = mData[26]; mData[26] = mData[27]; mData[27] = aHold;

}

void M88::FlipASixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = aHold;

    // cycle 1
    aHold = mData[28]; mData[28] = mData[29]; mData[29] = aHold;

}

void M88::FlipASixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = aHold;

    // cycle 1
    aHold = mData[30]; mData[30] = mData[31]; mData[31] = aHold;

}

void M88::FlipASixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = aHold;

    // cycle 1
    aHold = mData[40]; mData[40] = mData[41]; mData[41] = aHold;

}

void M88::FlipASixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = aHold;

    // cycle 1
    aHold = mData[42]; mData[42] = mData[43]; mData[43] = aHold;

}

void M88::FlipASixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = aHold;

    // cycle 1
    aHold = mData[44]; mData[44] = mData[45]; mData[45] = aHold;

}

void M88::FlipASixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = aHold;

    // cycle 1
    aHold = mData[46]; mData[46] = mData[47]; mData[47] = aHold;

}

void M88::FlipASixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = aHold;

    // cycle 1
    aHold = mData[56]; mData[56] = mData[57]; mData[57] = aHold;

}

void M88::FlipASixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = aHold;

    // cycle 1
    aHold = mData[58]; mData[58] = mData[59]; mData[59] = aHold;

}

void M88::FlipASixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = aHold;

    // cycle 1
    aHold = mData[60]; mData[60] = mData[61]; mData[61] = aHold;

}

void M88::FlipASixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = aHold;

    // cycle 1
    aHold = mData[62]; mData[62] = mData[63]; mData[63] = aHold;

}

void M88::FlipBSixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = aHold;

    // cycle 1
    aHold = mData[1]; mData[1] = mData[9]; mData[9] = aHold;

}

void M88::FlipBSixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = aHold;

    // cycle 1
    aHold = mData[3]; mData[3] = mData[11]; mData[11] = aHold;

}

void M88::FlipBSixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = aHold;

    // cycle 1
    aHold = mData[5]; mData[5] = mData[13]; mData[13] = aHold;

}

void M88::FlipBSixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = aHold;

    // cycle 1
    aHold = mData[7]; mData[7] = mData[15]; mData[15] = aHold;

}

void M88::FlipBSixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = aHold;

    // cycle 1
    aHold = mData[17]; mData[17] = mData[25]; mData[25] = aHold;

}

void M88::FlipBSixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = aHold;

    // cycle 1
    aHold = mData[19]; mData[19] = mData[27]; mData[27] = aHold;

}

void M88::FlipBSixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = aHold;

    // cycle 1
    aHold = mData[21]; mData[21] = mData[29]; mData[29] = aHold;

}

void M88::FlipBSixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = aHold;

    // cycle 1
    aHold = mData[23]; mData[23] = mData[31]; mData[31] = aHold;

}

void M88::FlipBSixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = aHold;

    // cycle 1
    aHold = mData[33]; mData[33] = mData[41]; mData[41] = aHold;

}

void M88::FlipBSixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = aHold;

    // cycle 1
    aHold = mData[35]; mData[35] = mData[43]; mData[43] = aHold;

}

void M88::FlipBSixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = aHold;

    // cycle 1
    aHold = mData[37]; mData[37] = mData[45]; mData[45] = aHold;

}

void M88::FlipBSixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = aHold;

    // cycle 1
    aHold = mData[39]; mData[39] = mData[47]; mData[47] = aHold;

}

void M88::FlipBSixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = aHold;

    // cycle 1
    aHold = mData[49]; mData[49] = mData[57]; mData[57] = aHold;

}

void M88::FlipBSixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = aHold;

    // cycle 1
    aHold = mData[51]; mData[51] = mData[59]; mData[59] = aHold;

}

void M88::FlipBSixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = aHold;

    // cycle 1
    aHold = mData[53]; mData[53] = mData[61]; mData[61] = aHold;

}

void M88::FlipBSixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = aHold;

    // cycle 1
    aHold = mData[55]; mData[55] = mData[63]; mData[63] = aHold;

}

void M88::TriadAASixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = mData[8]; mData[8] = aHold;

}

void M88::TriadAASixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = mData[10]; mData[10] = aHold;

}

void M88::TriadAASixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = mData[12]; mData[12] = aHold;

}

void M88::TriadAASixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = mData[14]; mData[14] = aHold;

}

void M88::TriadAASixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = mData[24]; mData[24] = aHold;

}

void M88::TriadAASixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = mData[26]; mData[26] = aHold;

}

void M88::TriadAASixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = mData[28]; mData[28] = aHold;

}

void M88::TriadAASixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = mData[30]; mData[30] = aHold;

}

void M88::TriadAASixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = mData[40]; mData[40] = aHold;

}

void M88::TriadAASixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = mData[42]; mData[42] = aHold;

}

void M88::TriadAASixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = mData[44]; mData[44] = aHold;

}

void M88::TriadAASixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = mData[46]; mData[46] = aHold;

}

void M88::TriadAASixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = mData[56]; mData[56] = aHold;

}

void M88::TriadAASixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = mData[58]; mData[58] = aHold;

}

void M88::TriadAASixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = mData[60]; mData[60] = aHold;

}

void M88::TriadAASixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = mData[62]; mData[62] = aHold;

}

void M88::TriadABSixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = mData[1]; mData[1] = aHold;

}

void M88::TriadABSixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = mData[3]; mData[3] = aHold;

}

void M88::TriadABSixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = mData[5]; mData[5] = aHold;

}

void M88::TriadABSixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = mData[7]; mData[7] = aHold;

}

void M88::TriadABSixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = mData[17]; mData[17] = aHold;

}

void M88::TriadABSixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = mData[19]; mData[19] = aHold;

}

void M88::TriadABSixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = mData[21]; mData[21] = aHold;

}

void M88::TriadABSixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = mData[23]; mData[23] = aHold;

}

void M88::TriadABSixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = mData[33]; mData[33] = aHold;

}

void M88::TriadABSixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = mData[35]; mData[35] = aHold;

}

void M88::TriadABSixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = mData[37]; mData[37] = aHold;

}

void M88::TriadABSixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = mData[39]; mData[39] = aHold;

}

void M88::TriadABSixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = mData[49]; mData[49] = aHold;

}

void M88::TriadABSixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = mData[51]; mData[51] = aHold;

}

void M88::TriadABSixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = mData[53]; mData[53] = aHold;

}

void M88::TriadABSixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = mData[55]; mData[55] = aHold;

}

void M88::TriadBASixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = mData[9]; mData[9] = aHold;

}

void M88::TriadBASixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = mData[11]; mData[11] = aHold;

}

void M88::TriadBASixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = mData[13]; mData[13] = aHold;

}

void M88::TriadBASixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = mData[15]; mData[15] = aHold;

}

void M88::TriadBASixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = mData[25]; mData[25] = aHold;

}

void M88::TriadBASixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = mData[27]; mData[27] = aHold;

}

void M88::TriadBASixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = mData[29]; mData[29] = aHold;

}

void M88::TriadBASixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = mData[31]; mData[31] = aHold;

}

void M88::TriadBASixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = mData[41]; mData[41] = aHold;

}

void M88::TriadBASixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = mData[43]; mData[43] = aHold;

}

void M88::TriadBASixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = mData[45]; mData[45] = aHold;

}

void M88::TriadBASixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = mData[47]; mData[47] = aHold;

}

void M88::TriadBASixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = mData[57]; mData[57] = aHold;

}

void M88::TriadBASixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = mData[59]; mData[59] = aHold;

}

void M88::TriadBASixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = mData[61]; mData[61] = aHold;

}

void M88::TriadBASixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = mData[63]; mData[63] = aHold;

}

void M88::TriadBBSixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = mData[1]; mData[1] = aHold;

}

void M88::TriadBBSixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = mData[3]; mData[3] = aHold;

}

void M88::TriadBBSixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = mData[5]; mData[5] = aHold;

}

void M88::TriadBBSixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = mData[7]; mData[7] = aHold;

}

void M88::TriadBBSixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = mData[17]; mData[17] = aHold;

}

void M88::TriadBBSixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = mData[19]; mData[19] = aHold;

}

void M88::TriadBBSixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = mData[21]; mData[21] = aHold;

}

void M88::TriadBBSixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = mData[23]; mData[23] = aHold;

}

void M88::TriadBBSixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = mData[33]; mData[33] = aHold;

}

void M88::TriadBBSixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = mData[35]; mData[35] = aHold;

}

void M88::TriadBBSixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = mData[37]; mData[37] = aHold;

}

void M88::TriadBBSixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = mData[39]; mData[39] = aHold;

}

void M88::TriadBBSixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = mData[49]; mData[49] = aHold;

}

void M88::TriadBBSixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = mData[51]; mData[51] = aHold;

}

void M88::TriadBBSixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = mData[53]; mData[53] = aHold;

}

void M88::TriadBBSixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = mData[55]; mData[55] = aHold;

}

void M88::TriadCASixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = mData[9]; mData[9] = aHold;

}

void M88::TriadCASixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = mData[11]; mData[11] = aHold;

}

void M88::TriadCASixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = mData[13]; mData[13] = aHold;

}

void M88::TriadCASixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = mData[15]; mData[15] = aHold;

}

void M88::TriadCASixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = mData[25]; mData[25] = aHold;

}

void M88::TriadCASixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = mData[27]; mData[27] = aHold;

}

void M88::TriadCASixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = mData[29]; mData[29] = aHold;

}

void M88::TriadCASixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = mData[31]; mData[31] = aHold;

}

void M88::TriadCASixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = mData[41]; mData[41] = aHold;

}

void M88::TriadCASixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = mData[43]; mData[43] = aHold;

}

void M88::TriadCASixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = mData[45]; mData[45] = aHold;

}

void M88::TriadCASixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = mData[47]; mData[47] = aHold;

}

void M88::TriadCASixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = mData[57]; mData[57] = aHold;

}

void M88::TriadCASixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = mData[59]; mData[59] = aHold;

}

void M88::TriadCASixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = mData[61]; mData[61] = aHold;

}

void M88::TriadCASixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = mData[63]; mData[63] = aHold;

}

void M88::TriadCBSixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = mData[8]; mData[8] = aHold;

}

void M88::TriadCBSixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = mData[10]; mData[10] = aHold;

}

void M88::TriadCBSixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = mData[12]; mData[12] = aHold;

}

void M88::TriadCBSixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = mData[14]; mData[14] = aHold;

}

void M88::TriadCBSixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = mData[24]; mData[24] = aHold;

}

void M88::TriadCBSixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = mData[26]; mData[26] = aHold;

}

void M88::TriadCBSixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = mData[28]; mData[28] = aHold;

}

void M88::TriadCBSixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = mData[30]; mData[30] = aHold;

}

void M88::TriadCBSixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = mData[40]; mData[40] = aHold;

}

void M88::TriadCBSixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = mData[42]; mData[42] = aHold;

}

void M88::TriadCBSixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = mData[44]; mData[44] = aHold;

}

void M88::TriadCBSixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = mData[46]; mData[46] = aHold;

}

void M88::TriadCBSixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = mData[56]; mData[56] = aHold;

}

void M88::TriadCBSixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = mData[58]; mData[58] = aHold;

}

void M88::TriadCBSixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = mData[60]; mData[60] = aHold;

}

void M88::TriadCBSixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = mData[62]; mData[62] = aHold;

}

void M88::TriadDASixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[1]; mData[1] = mData[8]; mData[8] = mData[9]; mData[9] = aHold;

}

void M88::TriadDASixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[3]; mData[3] = mData[10]; mData[10] = mData[11]; mData[11] = aHold;

}

void M88::TriadDASixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[5]; mData[5] = mData[12]; mData[12] = mData[13]; mData[13] = aHold;

}

void M88::TriadDASixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[7]; mData[7] = mData[14]; mData[14] = mData[15]; mData[15] = aHold;

}

void M88::TriadDASixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[17]; mData[17] = mData[24]; mData[24] = mData[25]; mData[25] = aHold;

}

void M88::TriadDASixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[19]; mData[19] = mData[26]; mData[26] = mData[27]; mData[27] = aHold;

}

void M88::TriadDASixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[21]; mData[21] = mData[28]; mData[28] = mData[29]; mData[29] = aHold;

}

void M88::TriadDASixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[23]; mData[23] = mData[30]; mData[30] = mData[31]; mData[31] = aHold;

}

void M88::TriadDASixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[33]; mData[33] = mData[40]; mData[40] = mData[41]; mData[41] = aHold;

}

void M88::TriadDASixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[35]; mData[35] = mData[42]; mData[42] = mData[43]; mData[43] = aHold;

}

void M88::TriadDASixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[37]; mData[37] = mData[44]; mData[44] = mData[45]; mData[45] = aHold;

}

void M88::TriadDASixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[39]; mData[39] = mData[46]; mData[46] = mData[47]; mData[47] = aHold;

}

void M88::TriadDASixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[49]; mData[49] = mData[56]; mData[56] = mData[57]; mData[57] = aHold;

}

void M88::TriadDASixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[51]; mData[51] = mData[58]; mData[58] = mData[59]; mData[59] = aHold;

}

void M88::TriadDASixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[53]; mData[53] = mData[60]; mData[60] = mData[61]; mData[61] = aHold;

}

void M88::TriadDASixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[55]; mData[55] = mData[62]; mData[62] = mData[63]; mData[63] = aHold;

}

void M88::TriadDBSixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[1]; mData[1] = mData[9]; mData[9] = mData[8]; mData[8] = aHold;

}

void M88::TriadDBSixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[3]; mData[3] = mData[11]; mData[11] = mData[10]; mData[10] = aHold;

}

void M88::TriadDBSixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[5]; mData[5] = mData[13]; mData[13] = mData[12]; mData[12] = aHold;

}

void M88::TriadDBSixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[7]; mData[7] = mData[15]; mData[15] = mData[14]; mData[14] = aHold;

}

void M88::TriadDBSixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[17]; mData[17] = mData[25]; mData[25] = mData[24]; mData[24] = aHold;

}

void M88::TriadDBSixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[19]; mData[19] = mData[27]; mData[27] = mData[26]; mData[26] = aHold;

}

void M88::TriadDBSixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[21]; mData[21] = mData[29]; mData[29] = mData[28]; mData[28] = aHold;

}

void M88::TriadDBSixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[23]; mData[23] = mData[31]; mData[31] = mData[30]; mData[30] = aHold;

}

void M88::TriadDBSixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[33]; mData[33] = mData[41]; mData[41] = mData[40]; mData[40] = aHold;

}

void M88::TriadDBSixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[35]; mData[35] = mData[43]; mData[43] = mData[42]; mData[42] = aHold;

}

void M88::TriadDBSixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[37]; mData[37] = mData[45]; mData[45] = mData[44]; mData[44] = aHold;

}

void M88::TriadDBSixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[39]; mData[39] = mData[47]; mData[47] = mData[46]; mData[46] = aHold;

}

void M88::TriadDBSixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[49]; mData[49] = mData[57]; mData[57] = mData[56]; mData[56] = aHold;

}

void M88::TriadDBSixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[51]; mData[51] = mData[59]; mData[59] = mData[58]; mData[58] = aHold;

}

void M88::TriadDBSixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[53]; mData[53] = mData[61]; mData[61] = mData[60]; mData[60] = aHold;

}

void M88::TriadDBSixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[55]; mData[55] = mData[63]; mData[63] = mData[62]; mData[62] = aHold;

}

void M88::SnakeASixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[1]; mData[1] = mData[8]; mData[8] = mData[9];
    mData[9] = aHold;

}

void M88::SnakeASixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[3]; mData[3] = mData[10]; mData[10] = mData[11];
    mData[11] = aHold;

}

void M88::SnakeASixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[5]; mData[5] = mData[12]; mData[12] = mData[13];
    mData[13] = aHold;

}

void M88::SnakeASixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[7]; mData[7] = mData[14]; mData[14] = mData[15];
    mData[15] = aHold;

}

void M88::SnakeASixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[17]; mData[17] = mData[24]; mData[24] = mData[25];
    mData[25] = aHold;

}

void M88::SnakeASixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[19]; mData[19] = mData[26]; mData[26] = mData[27];
    mData[27] = aHold;

}

void M88::SnakeASixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[21]; mData[21] = mData[28]; mData[28] = mData[29];
    mData[29] = aHold;

}

void M88::SnakeASixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[23]; mData[23] = mData[30]; mData[30] = mData[31];
    mData[31] = aHold;

}

void M88::SnakeASixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[33]; mData[33] = mData[40]; mData[40] = mData[41];
    mData[41] = aHold;

}

void M88::SnakeASixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[35]; mData[35] = mData[42]; mData[42] = mData[43];
    mData[43] = aHold;

}

void M88::SnakeASixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[37]; mData[37] = mData[44]; mData[44] = mData[45];
    mData[45] = aHold;

}

void M88::SnakeASixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[39]; mData[39] = mData[46]; mData[46] = mData[47];
    mData[47] = aHold;

}

void M88::SnakeASixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[49]; mData[49] = mData[56]; mData[56] = mData[57];
    mData[57] = aHold;

}

void M88::SnakeASixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[51]; mData[51] = mData[58]; mData[58] = mData[59];
    mData[59] = aHold;

}

void M88::SnakeASixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[53]; mData[53] = mData[60]; mData[60] = mData[61];
    mData[61] = aHold;

}

void M88::SnakeASixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[55]; mData[55] = mData[62]; mData[62] = mData[63];
    mData[63] = aHold;

}

void M88::SnakeBSixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = mData[8]; mData[8] = mData[1];
    mData[1] = aHold;

}

void M88::SnakeBSixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = mData[10]; mData[10] = mData[3];
    mData[3] = aHold;

}

void M88::SnakeBSixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = mData[12]; mData[12] = mData[5];
    mData[5] = aHold;

}

void M88::SnakeBSixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = mData[14]; mData[14] = mData[7];
    mData[7] = aHold;

}

void M88::SnakeBSixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = mData[24]; mData[24] = mData[17];
    mData[17] = aHold;

}

void M88::SnakeBSixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = mData[26]; mData[26] = mData[19];
    mData[19] = aHold;

}

void M88::SnakeBSixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = mData[28]; mData[28] = mData[21];
    mData[21] = aHold;

}

void M88::SnakeBSixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = mData[30]; mData[30] = mData[23];
    mData[23] = aHold;

}

void M88::SnakeBSixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = mData[40]; mData[40] = mData[33];
    mData[33] = aHold;

}

void M88::SnakeBSixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = mData[42]; mData[42] = mData[35];
    mData[35] = aHold;

}

void M88::SnakeBSixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = mData[44]; mData[44] = mData[37];
    mData[37] = aHold;

}

void M88::SnakeBSixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = mData[46]; mData[46] = mData[39];
    mData[39] = aHold;

}

void M88::SnakeBSixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = mData[56]; mData[56] = mData[49];
    mData[49] = aHold;

}

void M88::SnakeBSixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = mData[58]; mData[58] = mData[51];
    mData[51] = aHold;

}

void M88::SnakeBSixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = mData[60]; mData[60] = mData[53];
    mData[53] = aHold;

}

void M88::SnakeBSixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = mData[62]; mData[62] = mData[55];
    mData[55] = aHold;

}

void M88::SnakeCSixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[8]; mData[8] = mData[1]; mData[1] = mData[9];
    mData[9] = aHold;

}

void M88::SnakeCSixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[10]; mData[10] = mData[3]; mData[3] = mData[11];
    mData[11] = aHold;

}

void M88::SnakeCSixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[12]; mData[12] = mData[5]; mData[5] = mData[13];
    mData[13] = aHold;

}

void M88::SnakeCSixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[14]; mData[14] = mData[7]; mData[7] = mData[15];
    mData[15] = aHold;

}

void M88::SnakeCSixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[24]; mData[24] = mData[17]; mData[17] = mData[25];
    mData[25] = aHold;

}

void M88::SnakeCSixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[26]; mData[26] = mData[19]; mData[19] = mData[27];
    mData[27] = aHold;

}

void M88::SnakeCSixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[28]; mData[28] = mData[21]; mData[21] = mData[29];
    mData[29] = aHold;

}

void M88::SnakeCSixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[30]; mData[30] = mData[23]; mData[23] = mData[31];
    mData[31] = aHold;

}

void M88::SnakeCSixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[40]; mData[40] = mData[33]; mData[33] = mData[41];
    mData[41] = aHold;

}

void M88::SnakeCSixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[42]; mData[42] = mData[35]; mData[35] = mData[43];
    mData[43] = aHold;

}

void M88::SnakeCSixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[44]; mData[44] = mData[37]; mData[37] = mData[45];
    mData[45] = aHold;

}

void M88::SnakeCSixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[46]; mData[46] = mData[39]; mData[39] = mData[47];
    mData[47] = aHold;

}

void M88::SnakeCSixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[56]; mData[56] = mData[49]; mData[49] = mData[57];
    mData[57] = aHold;

}

void M88::SnakeCSixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[58]; mData[58] = mData[51]; mData[51] = mData[59];
    mData[59] = aHold;

}

void M88::SnakeCSixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[60]; mData[60] = mData[53]; mData[53] = mData[61];
    mData[61] = aHold;

}

void M88::SnakeCSixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[62]; mData[62] = mData[55]; mData[55] = mData[63];
    mData[63] = aHold;

}

void M88::SnakeDSixA() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[0]; mData[0] = mData[9]; mData[9] = mData[1]; mData[1] = mData[8];
    mData[8] = aHold;

}

void M88::SnakeDSixB() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[2]; mData[2] = mData[11]; mData[11] = mData[3]; mData[3] = mData[10];
    mData[10] = aHold;

}

void M88::SnakeDSixC() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[4]; mData[4] = mData[13]; mData[13] = mData[5]; mData[5] = mData[12];
    mData[12] = aHold;

}

void M88::SnakeDSixD() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[6]; mData[6] = mData[15]; mData[15] = mData[7]; mData[7] = mData[14];
    mData[14] = aHold;

}

void M88::SnakeDSixE() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[16]; mData[16] = mData[25]; mData[25] = mData[17]; mData[17] = mData[24];
    mData[24] = aHold;

}

void M88::SnakeDSixF() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[18]; mData[18] = mData[27]; mData[27] = mData[19]; mData[19] = mData[26];
    mData[26] = aHold;

}

void M88::SnakeDSixG() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[20]; mData[20] = mData[29]; mData[29] = mData[21]; mData[21] = mData[28];
    mData[28] = aHold;

}

void M88::SnakeDSixH() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[22]; mData[22] = mData[31]; mData[31] = mData[23]; mData[23] = mData[30];
    mData[30] = aHold;

}

void M88::SnakeDSixI() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[32]; mData[32] = mData[41]; mData[41] = mData[33]; mData[33] = mData[40];
    mData[40] = aHold;

}

void M88::SnakeDSixJ() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[34]; mData[34] = mData[43]; mData[43] = mData[35]; mData[35] = mData[42];
    mData[42] = aHold;

}

void M88::SnakeDSixK() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[36]; mData[36] = mData[45]; mData[45] = mData[37]; mData[37] = mData[44];
    mData[44] = aHold;

}

void M88::SnakeDSixL() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[38]; mData[38] = mData[47]; mData[47] = mData[39]; mData[39] = mData[46];
    mData[46] = aHold;

}

void M88::SnakeDSixM() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[48]; mData[48] = mData[57]; mData[57] = mData[49]; mData[49] = mData[56];
    mData[56] = aHold;

}

void M88::SnakeDSixN() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[50]; mData[50] = mData[59]; mData[59] = mData[51]; mData[51] = mData[58];
    mData[58] = aHold;

}

void M88::SnakeDSixO() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[52]; mData[52] = mData[61]; mData[61] = mData[53]; mData[53] = mData[60];
    mData[60] = aHold;

}

void M88::SnakeDSixP() {
    std::uint8_t aHold = 0;

    // cycle 0
    aHold = mData[54]; mData[54] = mData[63]; mData[63] = mData[55]; mData[55] = mData[62];
    mData[62] = aHold;

}

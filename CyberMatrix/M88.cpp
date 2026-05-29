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

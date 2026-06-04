//
//  M88Slice.cpp
//  CyberMatrix
//
//  Created by nick on 5/29/26.
//

#include "M88Slice.hpp"
#include "M88.hpp"
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <unordered_map>

Quint::Quint() {
    mXA = 0;
    mYA = 0;
    
    mXB = 0;
    mYB = 0;
    
    mXC = 0;
    mYC = 0;
    
    mXD = 0;
    mYD = 0;
    
    mSize = 0;
}

void Quint::MakeRight(int pX, int pY, int pSize) {
    mXA = pX;
    mYA = pY;
    
    mXB = (pSize - 1 - mYA);
    mYB = mXA;
    
    mXC = (pSize - 1 - mYB);
    mYC = mXB;
    
    mXD = (pSize - 1 - mYC);
    mYD = mXC;
    
    mSize = pSize;
}

void Quint::MakeLeft(int pX, int pY, int pSize) {
    mXA = pX;
    mYA = pY;
    
    mXB = (mYA);
    mYB = (pSize - 1 - mXA);
    
    mXC = (mYB);
    mYC = (pSize - 1 - mXB);
    
    mXD = (mYC);
    mYD = (pSize - 1 - mXC);
    
    mSize = pSize;
}

void Quint::_Rotate() {
    
    int aXA = mXA; int aYA = mYA;
    int aXB = mXB; int aYB = mYB;
    int aXC = mXC; int aYC = mYC;
    int aXD = mXD; int aYD = mYD;
    
    mXA = aXD; mYA = aYD;
    mXB = aXA; mYB = aYA;
    mXC = aXB; mYC = aYB;
    mXD = aXC; mYD = aYC;
}

void Quint::RotA() {
    _Rotate();
}

void Quint::RotB() {
    _Rotate();
    _Rotate();
    _Rotate();
}

void Quint::RotC() {
    _Rotate();
    _Rotate();
}

void Quint::CrossA() {
    int aXA = mXA; int aYA = mYA;
    int aXB = mXB; int aYB = mYB;
    int aXC = mXC; int aYC = mYC;
    int aXD = mXD; int aYD = mYD;
    mXA = aXD; mYA = aYD;
    mXD = aXA; mYD = aYA;
    mXC = aXB; mYC = aYB;
    mXB = aXC; mYB = aYC;
}

void Quint::CrossB() {
    int aXA = mXA; int aYA = mYA;
    int aXB = mXB; int aYB = mYB;
    int aXC = mXC; int aYC = mYC;
    int aXD = mXD; int aYD = mYD;
    mXA = aXB; mYA = aYB;
    mXB = aXA; mYB = aYA;
    mXC = aXD; mYC = aYD;
    mXD = aXC; mYD = aYC;
}

void Quint::CrossC() {
    int aXA = mXA; int aYA = mYA;
    int aXB = mXB; int aYB = mYB;
    int aXC = mXC; int aYC = mYC;
    int aXD = mXD; int aYD = mYD;
    mXA = aXC; mYA = aYC;
    mXC = aXA; mYC = aYA;
    mXB = aXD; mYB = aYD;
    mXD = aXB; mYD = aYB;
}

static void NormalizeCycle(Cycle &pCycle) {
    if (pCycle.mSlots.empty()) {
        return;
    }

    std::size_t aBestIndex = 0U;

    for (std::size_t i = 1U; i < pCycle.mSlots.size(); i++) {
        if (pCycle.mSlots[i] < pCycle.mSlots[aBestIndex]) {
            aBestIndex = i;
        }
    }

    if (aBestIndex == 0U) {
        return;
    }

    std::vector<std::size_t> aRotated;
    aRotated.reserve(pCycle.mSlots.size());

    for (std::size_t i = 0U; i < pCycle.mSlots.size(); i++) {
        const std::size_t aIndex = (aBestIndex + i) % pCycle.mSlots.size();
        aRotated.push_back(pCycle.mSlots[aIndex]);
    }

    pCycle.mSlots = aRotated;
}

static std::size_t CycleMinSlot(const Cycle &pCycle) {
    std::size_t aMin = static_cast<std::size_t>(-1);

    for (std::size_t i = 0U; i < pCycle.mSlots.size(); i++) {
        if (pCycle.mSlots[i] < aMin) {
            aMin = pCycle.mSlots[i];
        }
    }

    return aMin;
}

Slice::Slice(std::size_t pX, std::size_t pY, std::size_t pSize) {
    Make(pX, pY, pSize);
}

Slice::Slice() {
    Make(0, 0, 0);
}

void Slice::Make(std::size_t pX, std::size_t pY, std::size_t pSize) {
    std::memset(mData, 0, sizeof(mData));
    std::memset(mTempData, 0, sizeof(mTempData));
    std::memset(mOriginalData, 0, sizeof(mOriginalData));

    std::memset(mSlot, 0, sizeof(mSlot));
    std::memset(mTempSlot, 0, sizeof(mTempSlot));

    for (std::size_t x = 0; x < pSize; x++) {
        for (std::size_t y = 0; y < pSize; y++) {
            const std::size_t aSlot = M88::Slot(x + pX, y + pY);
            mSlot[x][y] = aSlot;
            mData[x][y] = (y * pSize) + x;
        }
    }

    mX = pX;
    mY = pY;
    mSize = pSize;
}

void Slice::Flood(M88 &pMatrix) {
    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            mData[x][y] = pMatrix.mData[mSlot[x][y]];
        }
    }
}

Quint Slice::GetQuintRight(int pX, int pY) {
    Quint aResult;
    aResult.MakeRight(pX, pY, (int)mSize);
    return aResult;
}

Quint Slice::GetQuintLeft(int pX, int pY) {
    Quint aResult;
    aResult.MakeLeft(pX, pY, (int)mSize);
    return aResult;
}

void Slice::PrepareSlots() {
    std::memcpy(mTempData, mData, sizeof(mTempData));
    std::memcpy(mOriginalData, mData, sizeof(mOriginalData));
    std::memcpy(mTempSlot, mSlot, sizeof(mTempSlot));
}

std::size_t Slice::FindPreparedSlotForValue(std::uint8_t pValue) const {
    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            if (mOriginalData[x][y] == pValue) {
                return mTempSlot[x][y];
            }
        }
    }
    return static_cast<std::size_t>(-1);
}

void Slice::RealizeSlots() {
    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            mSlot[x][y] = FindPreparedSlotForValue(mData[x][y]);
        }
    }
}

void Slice::_ApplyBlockMap8x8(const std::uint8_t pMap[8][8]) {
    const std::size_t aBlockSize = mSize / 8U;

    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t destBlockY = 0U; destBlockY < 8U; destBlockY++) {
        for (std::size_t destBlockX = 0U; destBlockX < 8U; destBlockX++) {
            const std::uint8_t aSourceBlock = pMap[destBlockY][destBlockX];

            const std::size_t sourceBlockX = aSourceBlock & 7U;
            const std::size_t sourceBlockY = aSourceBlock >> 3U;

            for (std::size_t by = 0U; by < aBlockSize; by++) {
                for (std::size_t bx = 0U; bx < aBlockSize; bx++) {
                    const std::size_t destX = destBlockX * aBlockSize + bx;
                    const std::size_t destY = destBlockY * aBlockSize + by;

                    const std::size_t sourceX = sourceBlockX * aBlockSize + bx;
                    const std::size_t sourceY = sourceBlockY * aBlockSize + by;

                    mData[destX][destY] = mTempData[sourceX][sourceY];
                }
            }
        }
    }
}

void Slice::_ApplyBlockMap4x4(const std::uint8_t pMap[4][4]) {
    const std::size_t aBlockSize = mSize / 4U;

    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t destBlockY = 0; destBlockY < 4U; destBlockY++) {
        for (std::size_t destBlockX = 0; destBlockX < 4U; destBlockX++) {
            const std::uint8_t aSourceBlock = pMap[destBlockY][destBlockX];

            const std::size_t sourceBlockX = aSourceBlock & 3U;
            const std::size_t sourceBlockY = aSourceBlock >> 2U;

            for (std::size_t by = 0; by < aBlockSize; by++) {
                for (std::size_t bx = 0; bx < aBlockSize; bx++) {
                    const std::size_t destX = destBlockX * aBlockSize + bx;
                    const std::size_t destY = destBlockY * aBlockSize + by;

                    const std::size_t sourceX = sourceBlockX * aBlockSize + bx;
                    const std::size_t sourceY = sourceBlockY * aBlockSize + by;

                    mData[destX][destY] = mTempData[sourceX][sourceY];
                }
            }
        }
    }
}

void Slice::_ApplyBlockMap2x2(const std::uint8_t pMap[2][2]) {
    const std::size_t aBlockSize = mSize / 2U;

    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t destBlockY = 0; destBlockY < 2U; destBlockY++) {
        for (std::size_t destBlockX = 0; destBlockX < 2U; destBlockX++) {
            const std::uint8_t aSourceBlock = pMap[destBlockY][destBlockX];

            const std::size_t sourceBlockX = aSourceBlock & 1U;
            const std::size_t sourceBlockY = aSourceBlock >> 1U;

            for (std::size_t by = 0; by < aBlockSize; by++) {
                for (std::size_t bx = 0; bx < aBlockSize; bx++) {
                    const std::size_t destX = destBlockX * aBlockSize + bx;
                    const std::size_t destY = destBlockY * aBlockSize + by;

                    const std::size_t sourceX = sourceBlockX * aBlockSize + bx;
                    const std::size_t sourceY = sourceBlockY * aBlockSize + by;

                    mData[destX][destY] = mTempData[sourceX][sourceY];
                }
            }
        }
    }
}

void Slice::_Exchange(Quint &pQuintA, Quint &pQuintB) {
    std::memcpy(mTempData, mData, sizeof(mTempData));
    mData[pQuintA.mXA][pQuintA.mYA] = mTempData[pQuintB.mXA][pQuintB.mYA]; mData[pQuintA.mXB][pQuintA.mYB] = mTempData[pQuintB.mXB][pQuintB.mYB];
    mData[pQuintA.mXC][pQuintA.mYC] = mTempData[pQuintB.mXC][pQuintB.mYC]; mData[pQuintA.mXD][pQuintA.mYD] = mTempData[pQuintB.mXD][pQuintB.mYD];
}

void Slice::_Weave(Quint &pQuintA, Quint &pQuintB) {
    std::memcpy(mTempData, mData, sizeof(mTempData));
    mData[pQuintA.mXA][pQuintA.mYA] = mTempData[pQuintB.mXA][pQuintB.mYA]; mData[pQuintB.mXA][pQuintB.mYA] = mTempData[pQuintA.mXA][pQuintA.mYA];
    mData[pQuintA.mXB][pQuintA.mYB] = mTempData[pQuintB.mXB][pQuintB.mYB]; mData[pQuintB.mXB][pQuintB.mYB] = mTempData[pQuintA.mXB][pQuintA.mYB];
    mData[pQuintA.mXC][pQuintA.mYC] = mTempData[pQuintB.mXC][pQuintB.mYC]; mData[pQuintB.mXC][pQuintB.mYC] = mTempData[pQuintA.mXC][pQuintA.mYC];
    mData[pQuintA.mXD][pQuintA.mYD] = mTempData[pQuintB.mXD][pQuintB.mYD]; mData[pQuintB.mXD][pQuintB.mYD] = mTempData[pQuintA.mXD][pQuintA.mYD];
}

void Slice::_Identity() {
    
}

void Slice::_RotA(Quint &pQuint) {
    Quint aOther = pQuint;
    aOther.RotA();
    _Exchange(pQuint, aOther);
}

void Slice::_RotB(Quint &pQuint) {
    Quint aOther = pQuint;
    aOther.RotB();
    _Exchange(pQuint, aOther);
}

void Slice::_RotC(Quint &pQuint) {
    Quint aOther = pQuint;
    aOther.RotC();
    _Exchange(pQuint, aOther);
}

void Slice::_RotA() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            const std::size_t aNewX = mSize - 1U - y;
            const std::size_t aNewY = x;
            mData[aNewX][aNewY] = mTempData[x][y];
        }
    }
}

void Slice::_RotB() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            const std::size_t aNewX = y;
            const std::size_t aNewY = mSize - 1U - x;
            mData[aNewX][aNewY] = mTempData[x][y];
        }
    }
}

void Slice::_RotC() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            const std::size_t aNewX = mSize - 1U - x;
            const std::size_t aNewY = mSize - 1U - y;
            mData[aNewX][aNewY] = mTempData[x][y];
        }
    }
}

void Slice::_FlipA() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            const std::size_t aNewX = mSize - 1U - x;
            const std::size_t aNewY = y;
            mData[aNewX][aNewY] = mTempData[x][y];
        }
    }
}

void Slice::_FlipB() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            const std::size_t aNewX = x;
            const std::size_t aNewY = mSize - 1U - y;
            mData[aNewX][aNewY] = mTempData[x][y];
        }
    }
}

void Slice::_FlipC() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            const std::size_t aNewX = y;
            const std::size_t aNewY = x;
            mData[aNewX][aNewY] = mTempData[x][y];
        }
    }
}

void Slice::_FlipD() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            const std::size_t aNewX = mSize - 1U - y;
            const std::size_t aNewY = mSize - 1U - x;
            mData[aNewX][aNewY] = mTempData[x][y];
        }
    }
}

void Slice::_ShearA() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    const std::size_t aHalfShift = mSize / 2U;
    const std::size_t aQuarterShift = mSize / 4U;

    for (std::size_t y = 0; y < mSize; y++) {
        const std::size_t aShift = ((y & 1U) == 0U) ? aHalfShift : aQuarterShift;

        for (std::size_t x = 0; x < mSize; x++) {
            const std::size_t aNewX = (x + aShift) % mSize;
            mData[aNewX][y] = mTempData[x][y];
        }
    }
}

void Slice::_ShearB() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    const std::size_t aHalfShift = mSize / 2U;
    const std::size_t aQuarterShift = mSize / 4U;

    for (std::size_t y = 0; y < mSize; y++) {
        const std::size_t aShift = ((y & 1U) == 0U) ? aQuarterShift : aHalfShift;

        for (std::size_t x = 0; x < mSize; x++) {
            const std::size_t aNewX = (x + aShift) % mSize;
            mData[aNewX][y] = mTempData[x][y];
        }
    }
}

void Slice::_ShearC() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    const std::size_t aHalfShift = mSize / 2U;
    const std::size_t aQuarterShift = mSize / 4U;

    for (std::size_t x = 0; x < mSize; x++) {
        const std::size_t aShift = ((x & 1U) == 0U) ? aHalfShift : aQuarterShift;

        for (std::size_t y = 0; y < mSize; y++) {
            const std::size_t aNewY = (y + aShift) % mSize;
            mData[x][aNewY] = mTempData[x][y];
        }
    }
}

void Slice::_ShearD() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    const std::size_t aHalfShift = mSize / 2U;
    const std::size_t aQuarterShift = mSize / 4U;

    for (std::size_t x = 0; x < mSize; x++) {
        const std::size_t aShift = ((x & 1U) == 0U) ? aQuarterShift : aHalfShift;

        for (std::size_t y = 0; y < mSize; y++) {
            const std::size_t aNewY = (y + aShift) % mSize;
            mData[x][aNewY] = mTempData[x][y];
        }
    }
}

std::vector<Cycle> Slice::FindCycles() const {
    std::map<std::size_t, std::size_t> aDestToSource;

    for (std::size_t x = 0; x < mSize; x++) {
        for (std::size_t y = 0; y < mSize; y++) {
            const std::size_t aDestSlot = mTempSlot[x][y];
            const std::size_t aSourceSlot = mSlot[x][y];

            if (aDestSlot != aSourceSlot) {
                aDestToSource[aDestSlot] = aSourceSlot;
            }
        }
    }

    std::set<std::size_t> aVisited;
    std::vector<Cycle> aCycles;

    for (std::map<std::size_t, std::size_t>::const_iterator it = aDestToSource.begin();
         it != aDestToSource.end();
         ++it) {
        const std::size_t aStart = it->first;

        if (aVisited.find(aStart) != aVisited.end()) {
            continue;
        }

        Cycle aCycle;
        std::size_t aCurrent = aStart;

        while (true) {
            if (aVisited.find(aCurrent) != aVisited.end()) {
                break;
            }
            aVisited.insert(aCurrent);
            aCycle.mSlots.push_back(aCurrent);
            std::map<std::size_t, std::size_t>::const_iterator found = aDestToSource.find(aCurrent);
            if (found == aDestToSource.end()) { break; }
            aCurrent = found->second;
            if (aCurrent == aStart) { break; }
        }

        if (aCycle.mSlots.size() > 1U) {
            aCycles.push_back(aCycle);
        }
    }

    for (std::size_t i = 0U; i < aCycles.size(); i++) {
        NormalizeCycle(aCycles[i]);
    }

    std::sort(aCycles.begin(), aCycles.end(), [](const Cycle &lhs, const Cycle &rhs) {
        return CycleMinSlot(lhs) < CycleMinSlot(rhs);
    });

    return aCycles;
}

void Slice::PrintCycles() const {
    const std::vector<Cycle> aCycles = FindCycles();
    std::printf("Cycle count: %zu\n", aCycles.size());
    for (std::size_t i = 0; i < aCycles.size(); i++) {
        std::printf("Cycle %zu: ", i);
        for (std::size_t j = 0; j < aCycles[i].mSlots.size(); j++) {
            std::printf("%zu", aCycles[i].mSlots[j]);
            if (j + 1U < aCycles[i].mSlots.size()) { std::printf(" <- "); }
        }

        if (!aCycles[i].mSlots.empty()) { std::printf(" <- %zu", aCycles[i].mSlots[0]); }
        std::printf("\n");
    }
}

void Slice::PrintCycleCode(const char *pDataName) const {
    const std::vector<Cycle> aCycles = FindCycles();
    std::printf("std::uint8_t aHold = 0;\n");
    for (std::size_t i = 0; i < aCycles.size(); i++) {
        const Cycle &aCycle = aCycles[i];
        if (aCycle.mSlots.size() <= 1U) { continue; }
        std::printf("// cycle %zu\n", i);
        std::size_t aStatementsOnLine = 0U;
        std::printf("aHold = %s[%zu];", pDataName, aCycle.mSlots[0]);
        aStatementsOnLine++;
        for (std::size_t j = 0; j + 1U < aCycle.mSlots.size(); j++) {
            if (aStatementsOnLine >= 4U) {
                std::printf("\n");
                aStatementsOnLine = 0U;
            } else {
                std::printf(" ");
            }
            std::printf("%s[%zu] = %s[%zu];", pDataName, aCycle.mSlots[j], pDataName, aCycle.mSlots[j + 1U]);
            aStatementsOnLine++;
        }
        if (aStatementsOnLine >= 4U) {
            std::printf("\n");
            aStatementsOnLine = 0U;
        } else {
            std::printf(" ");
        }
        std::printf("%s[%zu] = aHold;", pDataName, aCycle.mSlots[aCycle.mSlots.size() - 1U]);
        std::printf("\n");
    }
}

void Slice::PrintBlockMapFunction(const std::string pName) {
    
    
    
    printf("void\t\t\t\t_%s();\n\n", pName.c_str());
    
    
    printf("void Slice::_%s() {\n", pName.c_str());
    
    if (mSize == 4) {
        printf("\tstatic const std::uint8_t kMap[4][4] = {\n");
    } else if (mSize == 2) {
        printf("\tstatic const std::uint8_t kMap[2][2] = {\n");
    }
    
    for (int n=0;n<mSize;n++) {
        printf("\t\t{ ");
        for (int i=0;i<mSize;i++) {
            printf("%2d", mData[i][n]);
            if (i == (mSize - 1)) {
                printf(" }");
            } else {
                printf(", ");
            }
        }
        printf(",\n");
    }
    printf("\t};\n");
    printf("\n");
    
    if (mSize == 4) {
        printf("\t_ApplyBlockMap4x4(kMap);\n");
    } else if (mSize == 2) {
        printf("\t_ApplyBlockMap2x2(kMap);\n");
    }
    printf("}\n");
    
}

void Slice::PrintVerifyExpected(const std::string pClass, const std::string pType, std::string pName) {
    
    std::vector<int> aList;
    for (int n=0;n<mSize;n++) {
        for (int i=0;i<mSize;i++) {
            aList.push_back(mData[i][n]);
        }
    }
    
    std::sort(aList.begin(), aList.end());
    
    std::unordered_map<int, int> aMap;
    for (int i=0; i<aList.size(); i++) {
        aMap[aList[i]] = i;
    }
    
    printf("\tstatic M\t\t\t%s%sExpected();\n\n", pType.c_str(), pName.c_str());
    printf("M %s::%s%sExpected() {\n", pClass.c_str(), pType.c_str(), pName.c_str());
    printf("\treturn {\n");
    
    for (int n=0;n<mSize;n++) {
        printf("\t\t{ ");
        for (int i=0;i<mSize;i++) {
            printf("%2d", aMap[mData[i][n]]);
            if (i == (mSize - 1)) {
                printf(" }");
            } else {
                printf(", ");
            }
        }
        printf(",\n");
    }
    printf("\t};\n");
    printf("}\n\n");
}

void Slice::PrintRecipeFactory2x2(const std::string pName) const {
    const std::string aHPP = BuildRecipeFactory2x2HPP(pName);
    const std::string aCPP = BuildRecipeFactory2x2CPP(pName);

    std::printf("%s\n", aHPP.c_str());
    std::printf("%s", aCPP.c_str());
}

void Slice::PrintRecipeFactory4x4(const std::string pName) const {
    const std::string aHPP = BuildRecipeFactory4x4HPP(pName);
    const std::string aCPP = BuildRecipeFactory4x4CPP(pName);

    std::printf("%s\n", aHPP.c_str());
    std::printf("%s", aCPP.c_str());
}


void Slice::PrintRecipeFactory8x8(const std::string pName) const {
    const std::string aHPP = BuildRecipeFactory8x8HPP(pName);
    const std::string aCPP = BuildRecipeFactory8x8CPP(pName);

    std::printf("%s\n", aHPP.c_str());
    std::printf("%s", aCPP.c_str());
}

std::string Slice::BuildRecipeFactory4x4HPP(const std::string &pName) const {
    std::ostringstream aStream;

    aStream << "    static Recipe4x4                    " << pName << "();\n";

    return aStream.str();
}

std::string Slice::BuildRecipeFactory8x8HPP(const std::string &pName) const {
    std::ostringstream aStream;

    aStream << "    static Recipe8x8                    " << pName << "();\n";

    return aStream.str();
}

std::string Slice::BuildRecipeFactory2x2HPP(const std::string &pName) const {
    std::ostringstream aStream;

    aStream << "    static Recipe2x2                    " << pName << "();\n";

    return aStream.str();
}

std::string Slice::BuildRecipeFactory4x4CPP(const std::string &pName) const {
    std::ostringstream aStream;

    if (mSize != 4U) {
        aStream << "// BuildRecipeFactory4x4CPP requires mSize == 4, got "
                << mSize
                << "\n";
        return aStream.str();
    }

    std::vector<int> aList;

    for (int y = 0; y < static_cast<int>(mSize); y++) {
        for (int x = 0; x < static_cast<int>(mSize); x++) {
            aList.push_back(mData[x][y]);
        }
    }

    std::sort(aList.begin(), aList.end());

    std::unordered_map<int, int> aMap;

    for (int i = 0; i < static_cast<int>(aList.size()); i++) {
        aMap[aList[i]] = i;
    }

    auto Letter = [](int pValue) -> char {
        return static_cast<char>('A' + pValue);
    };

    aStream << "Recipe4x4 RecipeFactory4x4::" << pName << "() {\n";

    aStream << "    //  A  B  C  D      "
            << Letter(aMap.at(mData[0][0])) << "  "
            << Letter(aMap.at(mData[1][0])) << "  "
            << Letter(aMap.at(mData[2][0])) << "  "
            << Letter(aMap.at(mData[3][0])) << "\n";

    aStream << "    //  E  F  G  H  ->  "
            << Letter(aMap.at(mData[0][1])) << "  "
            << Letter(aMap.at(mData[1][1])) << "  "
            << Letter(aMap.at(mData[2][1])) << "  "
            << Letter(aMap.at(mData[3][1])) << "\n";

    aStream << "    //  I  J  K  L      "
            << Letter(aMap.at(mData[0][2])) << "  "
            << Letter(aMap.at(mData[1][2])) << "  "
            << Letter(aMap.at(mData[2][2])) << "  "
            << Letter(aMap.at(mData[3][2])) << "\n";

    aStream << "    //  M  N  O  P      "
            << Letter(aMap.at(mData[0][3])) << "  "
            << Letter(aMap.at(mData[1][3])) << "  "
            << Letter(aMap.at(mData[2][3])) << "  "
            << Letter(aMap.at(mData[3][3])) << "\n";

    aStream << "    return Make(\"" << pName << "\",\n";

    for (int y = 0; y < static_cast<int>(mSize); y++) {
        aStream << "                ";

        for (int x = 0; x < static_cast<int>(mSize); x++) {
            const int aValue = aMap.at(mData[x][y]);

            if (aValue < 10) {
                aStream << ' ';
            }

            aStream << aValue << "U";

            const bool aLast =
                (y == static_cast<int>(mSize) - 1) &&
                (x == static_cast<int>(mSize) - 1);

            if (!aLast) {
                aStream << ", ";
            }
        }

        aStream << "\n";
    }

    aStream << "    );\n";
    aStream << "}\n\n";

    return aStream.str();
}

std::string Slice::BuildCPP(std::vector<std::string> pNameChunks) const {
    std::ostringstream aStream;

    const std::string aName = BuildFunctionName(pNameChunks);
    const std::vector<Cycle> aCycles = FindCycles();

    const std::size_t kMaxStatementsPerLine = 8U;

    aStream << "void M88::" << aName << "() {\n";

    if (aCycles.empty()) {
        aStream << "    // identity transform\n";
        aStream << "}\n\n";
        return aStream.str();
    }

    aStream << "    std::uint8_t aHold = 0;\n";

    for (std::size_t i = 0; i < aCycles.size(); i++) {
        const Cycle &aCycle = aCycles[i];

        if (aCycle.mSlots.size() <= 1U) {
            continue;
        }

        std::size_t aStatementsOnLine = 0U;

        aStream << "    aHold = mData[" << aCycle.mSlots[0] << "];";
        aStatementsOnLine++;

        for (std::size_t j = 0; j + 1U < aCycle.mSlots.size(); j++) {
            if (aStatementsOnLine >= kMaxStatementsPerLine) {
                aStream << "\n    ";
                aStatementsOnLine = 0U;
            } else {
                aStream << " ";
            }

            aStream << "mData[" << aCycle.mSlots[j] << "] = mData["
                    << aCycle.mSlots[j + 1U] << "];";

            aStatementsOnLine++;
        }

        if (aStatementsOnLine >= kMaxStatementsPerLine) {
            aStream << "\n    ";
        } else {
            aStream << " ";
        }

        aStream << "mData[" << aCycle.mSlots[aCycle.mSlots.size() - 1U]
                << "] = aHold;\n";
    }

    aStream << "}\n\n";

    return aStream.str();
}

std::string Slice::BuildRecipeFactory8x8CPP(const std::string &pName) const {
    std::ostringstream aStream;

    if (mSize != 8U) {
        aStream << "// BuildRecipeFactory8x8CPP requires mSize == 8, got "
                << mSize
                << "\n";
        return aStream.str();
    }

    std::vector<int> aList;

    for (int y = 0; y < static_cast<int>(mSize); y++) {
        for (int x = 0; x < static_cast<int>(mSize); x++) {
            aList.push_back(mData[x][y]);
        }
    }

    std::sort(aList.begin(), aList.end());

    std::unordered_map<int, int> aMap;

    for (int i = 0; i < static_cast<int>(aList.size()); i++) {
        aMap[aList[i]] = i;
    }

    auto AppendLabel = [](std::ostringstream &pStream, int pValue) {
        const char aRow = static_cast<char>('A' + (pValue >> 3));
        const char aCol = static_cast<char>('A' + (pValue & 7));

        pStream << aRow << aCol;
    };

    auto AppendInputLabel = [](std::ostringstream &pStream, int pY, int pX) {
        const char aRow = static_cast<char>('A' + pY);
        const char aCol = static_cast<char>('A' + pX);

        pStream << aRow << aCol;
    };

    aStream << "Recipe8x8 RecipeFactory8x8::" << pName << "() {\n";

    for (int y = 0; y < 8; y++) {
        aStream << "    //  ";

        for (int x = 0; x < 8; x++) {
            AppendInputLabel(aStream, y, x);

            if (x < 7) {
                aStream << " ";
            }
        }

        if (y == 1) {
            aStream << "  ->  ";
        } else {
            aStream << "      ";
        }

        for (int x = 0; x < 8; x++) {
            AppendLabel(aStream, aMap.at(mData[x][y]));

            if (x < 7) {
                aStream << " ";
            }
        }

        aStream << "\n";
    }

    aStream << "    return Make(\"" << pName << "\",\n";

    for (int y = 0; y < static_cast<int>(mSize); y++) {
        aStream << "                ";

        for (int x = 0; x < static_cast<int>(mSize); x++) {
            const int aValue = aMap.at(mData[x][y]);

            if (aValue < 10) {
                aStream << ' ';
            }

            aStream << aValue << "U";

            const bool aLast =
                (y == static_cast<int>(mSize) - 1) &&
                (x == static_cast<int>(mSize) - 1);

            if (!aLast) {
                aStream << ", ";
            }
        }

        aStream << "\n";
    }

    aStream << "    );\n";
    aStream << "}\n\n";

    return aStream.str();
}

std::string Slice::BuildRecipeFactory2x2CPP(const std::string &pName) const {
    std::ostringstream aStream;

    if (mSize != 2U) {
        aStream << "// BuildRecipeFactory2x2CPP requires mSize == 2, got "
                << mSize
                << "\n";
        return aStream.str();
    }

    std::vector<int> aList;

    for (int y = 0; y < static_cast<int>(mSize); y++) {
        for (int x = 0; x < static_cast<int>(mSize); x++) {
            aList.push_back(mData[x][y]);
        }
    }

    std::sort(aList.begin(), aList.end());

    std::unordered_map<int, int> aMap;

    for (int i = 0; i < static_cast<int>(aList.size()); i++) {
        aMap[aList[i]] = i;
    }

    auto Letter = [](int pValue) -> char {
        return static_cast<char>('A' + pValue);
    };

    aStream << "Recipe2x2 RecipeFactory2x2::" << pName << "() {\n";

    aStream << "    //  A  B      "
            << Letter(aMap.at(mData[0][0])) << "  "
            << Letter(aMap.at(mData[1][0])) << "\n";

    aStream << "    //  C  D  ->  "
            << Letter(aMap.at(mData[0][1])) << "  "
            << Letter(aMap.at(mData[1][1])) << "\n";

    aStream << "    return Make(\"" << pName << "\",\n";

    for (int y = 0; y < static_cast<int>(mSize); y++) {
        aStream << "                ";

        for (int x = 0; x < static_cast<int>(mSize); x++) {
            const int aValue = aMap.at(mData[x][y]);

            if (aValue < 10) {
                aStream << ' ';
            }

            aStream << aValue << "U";

            const bool aLast =
                (y == static_cast<int>(mSize) - 1) &&
                (x == static_cast<int>(mSize) - 1);

            if (!aLast) {
                aStream << ", ";
            }
        }

        aStream << "\n";
    }

    aStream << "    );\n";
    aStream << "}\n\n";

    return aStream.str();
}

std::string Slice::BuildFunctionName(std::vector<std::string> pNameChunks) {
    std::string aResult;

    for (std::size_t i = 0; i < pNameChunks.size(); i++) {
        aResult += pNameChunks[i];
    }

    return aResult;
}

void Slice::PrintHPP(std::vector<std::string> pNameChunks) const {
    const std::string aName = BuildFunctionName(pNameChunks);

    std::printf("    void                                        %s();\n",
                aName.c_str());
}

void Slice::PrintCPP(std::vector<std::string> pNameChunks) const {
    const std::string aName = BuildFunctionName(pNameChunks);
    const std::vector<Cycle> aCycles = FindCycles();

    const std::size_t kMaxStatementsPerLine = 8U;

    std::printf("void M88::%s() {\n", aName.c_str());

    if (aCycles.empty()) {
        std::printf("    // identity transform\n");
        std::printf("}\n\n");
        return;
    }

    std::printf("    std::uint8_t aHold = 0;\n");

    for (std::size_t i = 0; i < aCycles.size(); i++) {
        const Cycle &aCycle = aCycles[i];

        if (aCycle.mSlots.size() <= 1U) {
            continue;
        }

        std::size_t aStatementsOnLine = 0U;

        std::printf("    aHold = mData[%zu];", aCycle.mSlots[0]);
        aStatementsOnLine++;

        for (std::size_t j = 0; j + 1U < aCycle.mSlots.size(); j++) {
            if (aStatementsOnLine >= kMaxStatementsPerLine) {
                std::printf("\n    ");
                aStatementsOnLine = 0U;
            } else {
                std::printf(" ");
            }

            std::printf("mData[%zu] = mData[%zu];",
                        aCycle.mSlots[j],
                        aCycle.mSlots[j + 1U]);
            aStatementsOnLine++;
        }

        if (aStatementsOnLine >= kMaxStatementsPerLine) {
            std::printf("\n    ");
            aStatementsOnLine = 0U;
        } else {
            std::printf(" ");
        }

        std::printf("mData[%zu] = aHold;\n",
                    aCycle.mSlots[aCycle.mSlots.size() - 1U]);
    }

    std::printf("}\n\n");
}

int Slice::_PositiveModulo(int pValue, int pMod) {
    int aResult = pValue % pMod;

    if (aResult < 0) {
        aResult += pMod;
    }

    return aResult;
}

void Slice::_SpiralRect(std::size_t pX,
                        std::size_t pY,
                        std::size_t pWidth,
                        std::size_t pHeight,
                        int pAmount) {
    std::vector<std::pair<std::size_t, std::size_t>> aPath;

    if (pWidth == 0U || pHeight == 0U) {
        return;
    }

    if (pWidth == 1U && pHeight == 1U) {
        return;
    }

    // Top edge, left to right.
    for (std::size_t x = 0U; x < pWidth; x++) {
        aPath.push_back({ pX + x, pY });
    }

    // Right edge, top + 1 to bottom.
    for (std::size_t y = 1U; y < pHeight; y++) {
        aPath.push_back({ pX + pWidth - 1U, pY + y });
    }

    // Bottom edge, right - 1 to left.
    if (pHeight > 1U) {
        for (std::size_t x = pWidth - 1U; x-- > 0U;) {
            aPath.push_back({ pX + x, pY + pHeight - 1U });
        }
    }

    // Left edge, bottom - 1 to top + 1.
    if (pWidth > 1U) {
        for (std::size_t y = pHeight - 1U; y-- > 1U;) {
            aPath.push_back({ pX, pY + y });
        }
    }

    const int aCount = static_cast<int>(aPath.size());

    if (aCount <= 1) {
        return;
    }

    const int aShift = _PositiveModulo(pAmount, aCount);

    if (aShift == 0) {
        return;
    }

    std::memcpy(mTempData, mData, sizeof(mTempData));

    for (std::size_t i = 0U; i < aPath.size(); i++) {
        const std::size_t aDestIndex = static_cast<std::size_t>(
            _PositiveModulo(static_cast<int>(i) + aShift, aCount)
        );

        const std::size_t aSourceX = aPath[i].first;
        const std::size_t aSourceY = aPath[i].second;

        const std::size_t aDestX = aPath[aDestIndex].first;
        const std::size_t aDestY = aPath[aDestIndex].second;

        mData[aDestX][aDestY] = mTempData[aSourceX][aSourceY];
    }
}

void Slice::_JewelA() {
    const int aShift = static_cast<int>(mSize / 2U);

    // Horizontal bands: top half-style rows in 2-row strips.
    // First band forward, second band backward, alternating.
    for (std::size_t y = 0U; y + 1U < mSize; y += 2U) {
        const int aAmount = ((y / 2U) & 1U) == 0U ? aShift : -aShift;
        _SpiralRect(0U, y, mSize, 2U, aAmount);
    }
}

void Slice::_JewelB() {
    const int aShift = static_cast<int>(mSize / 2U);

    // Same as JewelA, reversed signs.
    for (std::size_t y = 0U; y + 1U < mSize; y += 2U) {
        const int aAmount = ((y / 2U) & 1U) == 0U ? -aShift : aShift;
        _SpiralRect(0U, y, mSize, 2U, aAmount);
    }
}

void Slice::_JewelC() {
    const int aShift = static_cast<int>(mSize / 2U);

    // Vertical bands: 2-column strips.
    // First band forward, second band backward, alternating.
    for (std::size_t x = 0U; x + 1U < mSize; x += 2U) {
        const int aAmount = ((x / 2U) & 1U) == 0U ? aShift : -aShift;
        _SpiralRect(x, 0U, 2U, mSize, aAmount);
    }
}

void Slice::_JewelD() {
    const int aShift = static_cast<int>(mSize / 2U);

    // Same as JewelC, reversed signs.
    for (std::size_t x = 0U; x + 1U < mSize; x += 2U) {
        const int aAmount = ((x / 2U) & 1U) == 0U ? -aShift : aShift;
        _SpiralRect(x, 0U, 2U, mSize, aAmount);
    }
}

void Slice::_ZigZagA() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    // Pattern:
    //
    // a x b x      f x e x
    // c x d x  ->  h x g x
    // x e x f      x a x b
    // x g x h      x c x d

    const std::size_t aHalf = mSize / 2U;

    for (std::size_t y = 0U; y < aHalf; y++) {
        for (std::size_t x = 0U; x < mSize; x += 2U) {
            const std::size_t aDestX = x + 1U;
            const std::size_t aDestY = y + aHalf;

            mData[aDestX][aDestY] = mTempData[x][y];
        }
    }

    for (std::size_t y = aHalf; y < mSize; y++) {
        for (std::size_t x = 1U; x < mSize; x += 2U) {
            const std::size_t aDestX = (x + 1U) % mSize;
            const std::size_t aDestY = y - aHalf;

            mData[aDestX][aDestY] = mTempData[x][y];
        }
    }
}

void Slice::_ZigZagB() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    // Pattern:
    //
    // x a x b      x e x f
    // x c x d  ->  x g x h
    // e x f x      b x a x
    // g x h x      d x c x

    const std::size_t aHalf = mSize / 2U;

    for (std::size_t y = 0U; y < aHalf; y++) {
        for (std::size_t x = 1U; x < mSize; x += 2U) {
            const std::size_t aDestX = x - 1U;
            const std::size_t aDestY = y + aHalf;

            mData[aDestX][aDestY] = mTempData[x][y];
        }
    }

    for (std::size_t y = aHalf; y < mSize; y++) {
        for (std::size_t x = 0U; x < mSize; x += 2U) {
            const std::size_t aDestX = x + 1U;
            const std::size_t aDestY = y - aHalf;

            mData[aDestX][aDestY] = mTempData[x][y];
        }
    }
}

void Slice::_ZigZagC() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    // Pattern:
    //
    // a x b x      e x f x
    // c x d x  ->  g x h x
    // x e x f      x b x a
    // x g x h      x d x c

    const std::size_t aHalf = mSize / 2U;

    for (std::size_t y = 0U; y < aHalf; y++) {
        for (std::size_t x = 0U; x < mSize; x += 2U) {
            const std::size_t aDestX = (x + mSize - 1U) % mSize;
            const std::size_t aDestY = y + aHalf;

            mData[aDestX][aDestY] = mTempData[x][y];
        }
    }

    for (std::size_t y = aHalf; y < mSize; y++) {
        for (std::size_t x = 1U; x < mSize; x += 2U) {
            const std::size_t aDestX = x - 1U;
            const std::size_t aDestY = y - aHalf;

            mData[aDestX][aDestY] = mTempData[x][y];
        }
    }
}

void Slice::_ZigZagD() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    // Pattern:
    //
    // x a x b      x f x e
    // x c x d  ->  x h x g
    // e x f x      a x b x
    // g x h x      c x d x

    const std::size_t aHalf = mSize / 2U;

    for (std::size_t y = 0U; y < aHalf; y++) {
        for (std::size_t x = 1U; x < mSize; x += 2U) {
            const std::size_t aDestX = x - 1U;
            const std::size_t aDestY = y + aHalf;

            mData[aDestX][aDestY] = mTempData[x][y];
        }
    }

    for (std::size_t y = aHalf; y < mSize; y++) {
        for (std::size_t x = 0U; x < mSize; x += 2U) {
            const std::size_t aDestX = (x + mSize - 1U) % mSize;
            const std::size_t aDestY = y - aHalf;

            mData[aDestX][aDestY] = mTempData[x][y];
        }
    }
}


void Slice::_SwapHalvesVer() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    const std::size_t aHalf = mSize / 2U;

    for (std::size_t x = 0U; x < mSize; x++) {
        for (std::size_t y = 0U; y < mSize; y++) {
            const std::size_t aNewY = (y + aHalf) % mSize;

            mData[x][aNewY] = mTempData[x][y];
        }
    }
}

void Slice::_SwapHalvesHor() {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    const std::size_t aHalf = mSize / 2U;

    for (std::size_t x = 0U; x < mSize; x++) {
        for (std::size_t y = 0U; y < mSize; y++) {
            const std::size_t aNewX = (x + aHalf) % mSize;

            mData[aNewX][y] = mTempData[x][y];
        }
    }
}


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

void Slice::_PinA() {
    // Starts right:
    // each ring's top-left corner moves to that ring's top-right corner.
    _Pin(1);
}

void Slice::_PinB() {
    // Starts left:
    // reverse of PinA.
    _Pin(-1);
}

void Slice::_Pin(int pStartDirection) {
    const std::size_t aRingCount = mSize / 2U;

    for (std::size_t aRing = 0U; aRing < aRingCount; aRing++) {
        const std::size_t aMin = aRing;
        const std::size_t aMax = mSize - 1U - aRing;
        const std::size_t aSide = aMax - aMin + 1U;
        const std::size_t aShift = aSide - 1U;

        int aDirection = pStartDirection;

        if ((aRing & 1U) != 0U) {
            aDirection = -aDirection;
        }

        for (std::size_t aStep = 0U; aStep < aShift; aStep++) {
            std::memcpy(mTempData, mData, sizeof(mTempData));

            if (aDirection > 0) {
                // Right / clockwise:
                // top-left moves right along the top edge.
                for (std::size_t x = aMin; x < aMax; x++) {
                    mData[x + 1U][aMin] = mTempData[x][aMin];
                }

                for (std::size_t y = aMin; y < aMax; y++) {
                    mData[aMax][y + 1U] = mTempData[aMax][y];
                }

                for (std::size_t x = aMax; x > aMin; x--) {
                    mData[x - 1U][aMax] = mTempData[x][aMax];
                }

                for (std::size_t y = aMax; y > aMin; y--) {
                    mData[aMin][y - 1U] = mTempData[aMin][y];
                }
            } else {
                // Left / counter-clockwise:
                // top-left moves down along the left edge.
                for (std::size_t x = aMin; x < aMax; x++) {
                    mData[x][aMin] = mTempData[x + 1U][aMin];
                }

                for (std::size_t y = aMin; y < aMax; y++) {
                    mData[aMax][y] = mTempData[aMax][y + 1U];
                }

                for (std::size_t x = aMax; x > aMin; x--) {
                    mData[x][aMax] = mTempData[x - 1U][aMax];
                }

                for (std::size_t y = aMax; y > aMin; y--) {
                    mData[aMin][y] = mTempData[aMin][y - 1U];
                }
            }
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

    if (mSize != 2U) {
        printf("// PrintRecipeFactory2x2 requires mSize == 2, got %zu\n", mSize);
        return;
    }

    std::vector<int> aList;
    for (int n = 0; n < mSize; n++) {
        for (int i = 0; i < mSize; i++) {
            aList.push_back(mData[i][n]);
        }
    }

    std::sort(aList.begin(), aList.end());

    std::unordered_map<int, int> aMap;
    for (int i = 0; i < aList.size(); i++) {
        aMap[aList[i]] = i;
    }

    printf("\tstatic Recipe2x2\t\t%s();\n\n", pName.c_str());

    printf("Recipe2x2 RecipeFactory2x2::%s() {\n", pName.c_str());

    auto Letter = [](int pValue) -> char {
        return static_cast<char>('A' + pValue);
    };

    printf("\t//  A  B      %c  %c\n",
           Letter(aMap[mData[0][0]]),
           Letter(aMap[mData[1][0]]));

    printf("\t//  C  D  ->  %c  %c\n",
           Letter(aMap[mData[0][1]]),
           Letter(aMap[mData[1][1]]));

    printf("\treturn Make(\"%s\",\n", pName.c_str());

    for (int n = 0; n < mSize; n++) {
        printf("\t\t\t\t");

        for (int i = 0; i < mSize; i++) {
            printf("%2dU", aMap[mData[i][n]]);

            const bool aLast = (n == (mSize - 1)) && (i == (mSize - 1));

            if (!aLast) {
                printf(", ");
            }
        }

        printf("\n");
    }

    printf("\t);\n");
    printf("}\n\n");
}

void Slice::PrintRecipeFactory4x4(const std::string pName) const {

    if (mSize != 4U) {
        printf("// PrintRecipeFactory4x4 requires mSize == 4, got %zu\n", mSize);
        return;
    }

    std::vector<int> aList;
    for (int n = 0; n < mSize; n++) {
        for (int i = 0; i < mSize; i++) {
            aList.push_back(mData[i][n]);
        }
    }

    std::sort(aList.begin(), aList.end());

    std::unordered_map<int, int> aMap;
    for (int i = 0; i < aList.size(); i++) {
        aMap[aList[i]] = i;
    }

    printf("\tstatic Recipe4x4\t\t%s();\n\n", pName.c_str());

    printf("Recipe4x4 RecipeFactory4x4::%s() {\n", pName.c_str());

    auto Letter = [](int pValue) -> char {
        return static_cast<char>('A' + pValue);
    };

    printf("\t//  A  B  C  D      %c  %c  %c  %c\n",
           Letter(aMap[mData[0][0]]),
           Letter(aMap[mData[1][0]]),
           Letter(aMap[mData[2][0]]),
           Letter(aMap[mData[3][0]]));

    printf("\t//  E  F  G  H  ->  %c  %c  %c  %c\n",
           Letter(aMap[mData[0][1]]),
           Letter(aMap[mData[1][1]]),
           Letter(aMap[mData[2][1]]),
           Letter(aMap[mData[3][1]]));

    printf("\t//  I  J  K  L      %c  %c  %c  %c\n",
           Letter(aMap[mData[0][2]]),
           Letter(aMap[mData[1][2]]),
           Letter(aMap[mData[2][2]]),
           Letter(aMap[mData[3][2]]));

    printf("\t//  M  N  O  P      %c  %c  %c  %c\n",
           Letter(aMap[mData[0][3]]),
           Letter(aMap[mData[1][3]]),
           Letter(aMap[mData[2][3]]),
           Letter(aMap[mData[3][3]]));

    printf("\treturn Make(\"%s\",\n", pName.c_str());

    for (int n = 0; n < mSize; n++) {
        printf("\t\t\t\t");

        for (int i = 0; i < mSize; i++) {
            printf("%2dU", aMap[mData[i][n]]);

            const bool aLast = (n == (mSize - 1)) && (i == (mSize - 1));

            if (!aLast) {
                printf(", ");
            }
        }

        printf("\n");
    }

    printf("\t);\n");
    printf("}\n\n");
}


void Slice::PrintRecipeFactory8x8(const std::string pName) const {

    
    if (mSize != 8U) {
        printf("// PrintRecipeFactory8x8 requires mSize == 8, got %zu\n", mSize);
        return;
    }
    
    auto PrintLabel = [](int pValue) {
        const char aRow = static_cast<char>('A' + (pValue >> 3));
        const char aCol = static_cast<char>('A' + (pValue & 7));
        std::printf("%c%c", aRow, aCol);
    };

    auto PrintInputLabel = [](int pY, int pX) {
        const char aRow = static_cast<char>('A' + pY);
        const char aCol = static_cast<char>('A' + pX);
        std::printf("%c%c", aRow, aCol);
    };

    std::vector<int> aList;
    for (int n = 0; n < mSize; n++) {
        for (int i = 0; i < mSize; i++) {
            aList.push_back(mData[i][n]);
        }
    }

    std::sort(aList.begin(), aList.end());

    std::unordered_map<int, int> aMap;
    for (int i = 0; i < aList.size(); i++) {
        aMap[aList[i]] = i;
    }

    auto Letter = [](int pValue) -> char {
        if (pValue < 26) {
            return static_cast<char>('A' + pValue);
        }
        return static_cast<char>('a' + (pValue - 26));
    };

    printf("\tstatic Recipe8x8\t\t%s();\n\n", pName.c_str());

    printf("Recipe8x8 RecipeFactory8x8::%s() {\n", pName.c_str());

    for (int y = 0; y < 8; y++) {
        std::printf("\t//  ");

        for (int x = 0; x < 8; x++) {
            PrintInputLabel(y, x);
            if (x < 7) {
                std::printf(" ");
            }
        }

        if (y == 1) {
            std::printf("  ->  ");
        } else {
            std::printf("      ");
        }

        for (int x = 0; x < 8; x++) {
            PrintLabel(aMap[mData[x][y]]);
            if (x < 7) {
                std::printf(" ");
            }
        }

        std::printf("\n");
    }

    printf("\treturn Make(\"%s\",\n", pName.c_str());

    for (int n = 0; n < mSize; n++) {
        printf("\t\t\t\t");

        for (int i = 0; i < mSize; i++) {
            printf("%2dU", aMap[mData[i][n]]);

            const bool aLast = (n == (mSize - 1)) && (i == (mSize - 1));

            if (!aLast) {
                printf(", ");
            }
        }

        printf("\n");
    }

    printf("\t);\n");
    printf("}\n\n");
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

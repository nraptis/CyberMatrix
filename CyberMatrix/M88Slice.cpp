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

bool Slice::Capable(Op pOp) const {
    switch (pOp) {
        case Op::kRotateRight:
            return (mSize > 1U);
    }

    return false;
}

void Slice::Execute(Op pOp) {
    if (!Capable(pOp)) {
        return;
    }

    switch (pOp) {
        case Op::kRotateRight:
            RotateRight();
            return;
    }
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

void Slice::RotateRight() {
    if (mSize <= 1U) {
        return;
    }

    PrepareSlots();

    const std::size_t n = mSize;

    for (std::size_t x = 0; x < n; x++) {
        for (std::size_t y = 0; y < n; y++) {
            const std::size_t aNewX = n - 1U - y;
            const std::size_t aNewY = x;

            mData[aNewX][aNewY] = mTempData[x][y];
        }
    }

    RealizeSlots();
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
            if (found == aDestToSource.end()) {
                break;
            }

            aCurrent = found->second;

            if (aCurrent == aStart) {
                break;
            }
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

            if (j + 1U < aCycles[i].mSlots.size()) {
                std::printf(" <- ");
            }
        }

        if (!aCycles[i].mSlots.empty()) {
            std::printf(" <- %zu", aCycles[i].mSlots[0]);
        }

        std::printf("\n");
    }
}

void Slice::PrintCycleCode(const char *pDataName) const {
    const std::vector<Cycle> aCycles = FindCycles();

    std::printf("std::uint8_t aHold = 0;\n");

    for (std::size_t i = 0; i < aCycles.size(); i++) {
        const Cycle &aCycle = aCycles[i];

        if (aCycle.mSlots.size() <= 1U) {
            continue;
        }

        std::printf("// cycle %zu\n", i);

        std::size_t aStatementsOnLine = 0U;

        std::printf("aHold = %s[%zu];",
                    pDataName,
                    aCycle.mSlots[0]);
        aStatementsOnLine++;

        for (std::size_t j = 0; j + 1U < aCycle.mSlots.size(); j++) {
            if (aStatementsOnLine >= 4U) {
                std::printf("\n");
                aStatementsOnLine = 0U;
            } else {
                std::printf(" ");
            }

            std::printf("%s[%zu] = %s[%zu];",
                        pDataName,
                        aCycle.mSlots[j],
                        pDataName,
                        aCycle.mSlots[j + 1U]);
            aStatementsOnLine++;
        }

        if (aStatementsOnLine >= 4U) {
            std::printf("\n");
            aStatementsOnLine = 0U;
        } else {
            std::printf(" ");
        }

        std::printf("%s[%zu] = aHold;",
                    pDataName,
                    aCycle.mSlots[aCycle.mSlots.size() - 1U]);

        std::printf("\n");
    }
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

    std::printf("void M88::%s() {\n", aName.c_str());

    if (aCycles.empty()) {
        std::printf("    // identity transform\n");
        std::printf("}\n\n");
        return;
    }

    std::printf("    std::uint8_t aHold = 0;\n\n");

    for (std::size_t i = 0; i < aCycles.size(); i++) {
        const Cycle &aCycle = aCycles[i];

        if (aCycle.mSlots.size() <= 1U) {
            continue;
        }

        std::printf("    // cycle %zu\n", i);

        std::size_t aStatementsOnLine = 0U;

        std::printf("    aHold = mData[%zu];",
                    aCycle.mSlots[0]);
        aStatementsOnLine++;

        for (std::size_t j = 0; j + 1U < aCycle.mSlots.size(); j++) {
            if (aStatementsOnLine >= 4U) {
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

        if (aStatementsOnLine >= 4U) {
            std::printf("\n    ");
            aStatementsOnLine = 0U;
        } else {
            std::printf(" ");
        }

        std::printf("mData[%zu] = aHold;\n\n",
                    aCycle.mSlots[aCycle.mSlots.size() - 1U]);
    }

    std::printf("}\n\n");
}

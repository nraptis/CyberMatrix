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
        case Op::kRotA:
        case Op::kRotB:
        case Op::kRotC:
        case Op::kFlipA:
        case Op::kFlipB:
        case Op::kFlipC:
        case Op::kFlipD:
            return (mSize >= 2U);
            
        case Op::kPylonRotA:
        case Op::kPylonRotB:
        case Op::kPylonRotC:
        case Op::kPylonFlipA:
        case Op::kPylonFlipB:
        case Op::kPylonFlipC:
        case Op::kPylonFlipD:
            return (mSize == 8U);

        case Op::kBlockRotA:
        case Op::kBlockRotB:
        case Op::kBlockRotC:
        case Op::kBlockFlipA:
        case Op::kBlockFlipB:
        case Op::kBlockFlipC:
        case Op::kBlockFlipD:
        case Op::kPinA:
        case Op::kPinB:
        case Op::kCastleA:
        case Op::kCastleB:
            return (mSize == 4U) || (mSize == 8U);
            
        case Op::kTriadAA:
        case Op::kTriadAB:
        case Op::kTriadBA:
        case Op::kTriadBB:
        case Op::kTriadCA:
        case Op::kTriadCB:
        case Op::kTriadDA:
        case Op::kTriadDB:
        case Op::kSnakeA:
        case Op::kSnakeB:
        case Op::kSnakeC:
        case Op::kSnakeD:
            return (mSize == 2U);
    }

    return false;
}

void Slice::Execute(Op pOp) {
    std::vector<Op> aOps;
    aOps.push_back(pOp);
    Execute(aOps);
}

void Slice::Execute(std::vector<Op> pOps) {
    for (std::size_t i = 0; i < pOps.size(); i++) {
        if (!Capable(pOps[i])) {
            std::printf("tried an impossible op...\n");
            std::exit(0);
        }
    }

    PrepareSlots();

    for (std::size_t i = 0; i < pOps.size(); i++) {
        switch (pOps[i]) {
            case Op::kRotA:       _RotA();       break;
            case Op::kRotB:       _RotB();       break;
            case Op::kRotC:       _RotC();       break;

            case Op::kFlipA:      _FlipA();      break;
            case Op::kFlipB:      _FlipB();      break;
            case Op::kFlipC:      _FlipC();      break;
            case Op::kFlipD:      _FlipD();      break;

            case Op::kBlockRotA:  _BlockRotA();  break;
            case Op::kBlockRotB:  _BlockRotB();  break;
            case Op::kBlockRotC:  _BlockRotC();  break;

            case Op::kBlockFlipA: _BlockFlipA(); break;
            case Op::kBlockFlipB: _BlockFlipB(); break;
            case Op::kBlockFlipC: _BlockFlipC(); break;
            case Op::kBlockFlipD: _BlockFlipD(); break;
                
            case Op::kPylonRotA:  _PylonRotA();  break;
            case Op::kPylonRotB:  _PylonRotB();  break;
            case Op::kPylonRotC:  _PylonRotC();  break;

            case Op::kPylonFlipA: _PylonFlipA(); break;
            case Op::kPylonFlipB: _PylonFlipB(); break;
            case Op::kPylonFlipC: _PylonFlipC(); break;
            case Op::kPylonFlipD: _PylonFlipD(); break;

            case Op::kPinA:       _PinA();       break;
            case Op::kPinB:       _PinB();       break;

            case Op::kCastleA:    _CastleA();    break;
            case Op::kCastleB:    _CastleB();    break;

            case Op::kTriadAA:    _TriadAA();    break;
            case Op::kTriadAB:    _TriadAB();    break;
            case Op::kTriadBA:    _TriadBA();    break;
            case Op::kTriadBB:    _TriadBB();    break;
            case Op::kTriadCA:    _TriadCA();    break;
            case Op::kTriadCB:    _TriadCB();    break;
            case Op::kTriadDA:    _TriadDA();    break;
            case Op::kTriadDB:    _TriadDB();    break;
                
            case Op::kSnakeA:  _SnakeA();  break;
            case Op::kSnakeB:  _SnakeB();  break;
            case Op::kSnakeC:  _SnakeC();  break;
            case Op::kSnakeD:  _SnakeD();  break;
                
        }
    }

    RealizeSlots();
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

void Slice::_PylonRotA() {
    static const std::uint8_t kMap[4][4] = {
        { 12U,  8U,  4U,  0U },
        { 13U,  9U,  5U,  1U },
        { 14U, 10U,  6U,  2U },
        { 15U, 11U,  7U,  3U }
    };

    _ApplyBlockMap4x4(kMap);
}

void Slice::_PylonRotB() {
    static const std::uint8_t kMap[4][4] = {
        {  3U,  7U, 11U, 15U },
        {  2U,  6U, 10U, 14U },
        {  1U,  5U,  9U, 13U },
        {  0U,  4U,  8U, 12U }
    };

    _ApplyBlockMap4x4(kMap);
}

void Slice::_PylonRotC() {
    static const std::uint8_t kMap[4][4] = {
        { 15U, 14U, 13U, 12U },
        { 11U, 10U,  9U,  8U },
        {  7U,  6U,  5U,  4U },
        {  3U,  2U,  1U,  0U }
    };

    _ApplyBlockMap4x4(kMap);
}

void Slice::_PylonFlipA() {
    static const std::uint8_t kMap[4][4] = {
        {  3U,  2U,  1U,  0U },
        {  7U,  6U,  5U,  4U },
        { 11U, 10U,  9U,  8U },
        { 15U, 14U, 13U, 12U }
    };

    _ApplyBlockMap4x4(kMap);
}

void Slice::_PylonFlipB() {
    static const std::uint8_t kMap[4][4] = {
        { 12U, 13U, 14U, 15U },
        {  8U,  9U, 10U, 11U },
        {  4U,  5U,  6U,  7U },
        {  0U,  1U,  2U,  3U }
    };

    _ApplyBlockMap4x4(kMap);
}

void Slice::_PylonFlipC() {
    static const std::uint8_t kMap[4][4] = {
        {  0U,  4U,  8U, 12U },
        {  1U,  5U,  9U, 13U },
        {  2U,  6U, 10U, 14U },
        {  3U,  7U, 11U, 15U }
    };

    _ApplyBlockMap4x4(kMap);
}

void Slice::_PylonFlipD() {
    static const std::uint8_t kMap[4][4] = {
        { 15U, 11U,  7U,  3U },
        { 14U, 10U,  6U,  2U },
        { 13U,  9U,  5U,  1U },
        { 12U,  8U,  4U,  0U }
    };

    _ApplyBlockMap4x4(kMap);
}

void Slice::_PinA() {
    static const std::uint8_t kMap[4][4] = {
        { 12U,  8U,  4U,  0U },
        { 13U,  6U, 10U,  1U },
        { 14U,  5U,  9U,  2U },
        { 15U, 11U,  7U,  3U }
    };

    _ApplyBlockMap4x4(kMap);
}

void Slice::_PinB() {
    static const std::uint8_t kMap[4][4] = {
        {  3U,  7U, 11U, 15U },
        {  2U,  9U,  5U, 14U },
        {  1U, 10U,  6U, 13U },
        {  0U,  4U,  8U, 12U }
    };

    _ApplyBlockMap4x4(kMap);
}

void Slice::_BlockRotA() {
    static const std::uint8_t kMap[2][2] = {
        { 2U, 0U },
        { 3U, 1U }
    };

    _ApplyBlockMap2x2(kMap);
}

void Slice::_BlockRotB() {
    static const std::uint8_t kMap[2][2] = {
        { 1U, 3U },
        { 0U, 2U }
    };

    _ApplyBlockMap2x2(kMap);
}

void Slice::_BlockRotC() {
    static const std::uint8_t kMap[2][2] = {
        { 3U, 2U },
        { 1U, 0U }
    };

    _ApplyBlockMap2x2(kMap);
}

void Slice::_BlockFlipA() {
    static const std::uint8_t kMap[2][2] = {
        { 1U, 0U },
        { 3U, 2U }
    };

    _ApplyBlockMap2x2(kMap);
}

void Slice::_BlockFlipB() {
    static const std::uint8_t kMap[2][2] = {
        { 2U, 3U },
        { 0U, 1U }
    };

    _ApplyBlockMap2x2(kMap);
}

void Slice::_BlockFlipC() {
    static const std::uint8_t kMap[2][2] = {
        { 0U, 2U },
        { 1U, 3U }
    };

    _ApplyBlockMap2x2(kMap);
}

void Slice::_BlockFlipD() {
    static const std::uint8_t kMap[2][2] = {
        { 3U, 1U },
        { 2U, 0U }
    };

    _ApplyBlockMap2x2(kMap);
}

void Slice::_CastleA() {
    static const std::uint8_t kMap[4][4] = {
        {  6U, 11U,  7U, 10U },
        {  1U, 12U,  0U, 13U },
        {  2U, 15U,  3U, 14U },
        {  5U,  8U,  4U,  9U }
    };

    _ApplyBlockMap4x4(kMap);
}

void Slice::_CastleB() {
    static const std::uint8_t kMap[4][4] = {
        {  9U,  4U,  8U,  5U },
        { 14U,  3U, 15U,  2U },
        { 13U,  0U, 12U,  1U },
        { 10U,  7U, 11U,  6U }
    };

    _ApplyBlockMap4x4(kMap);
}

static std::size_t LocalX(std::size_t pIndex) {
    return pIndex & 1U;
}

static std::size_t LocalY(std::size_t pIndex) {
    return pIndex >> 1U;
}

void Slice::_SwapLocal(std::size_t pA, std::size_t pB) {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    const std::size_t ax = LocalX(pA);
    const std::size_t ay = LocalY(pA);
    const std::size_t bx = LocalX(pB);
    const std::size_t by = LocalY(pB);

    mData[ax][ay] = mTempData[bx][by];
    mData[bx][by] = mTempData[ax][ay];
}

void Slice::_CycleLocal3(std::size_t pA,
                         std::size_t pB,
                         std::size_t pC) {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    const std::size_t ax = LocalX(pA);
    const std::size_t ay = LocalY(pA);
    const std::size_t bx = LocalX(pB);
    const std::size_t by = LocalY(pB);
    const std::size_t cx = LocalX(pC);
    const std::size_t cy = LocalY(pC);

    mData[ax][ay] = mTempData[bx][by];
    mData[bx][by] = mTempData[cx][cy];
    mData[cx][cy] = mTempData[ax][ay];
}

void Slice::_LayoutLocal4(std::size_t pA,
                          std::size_t pB,
                          std::size_t pC,
                          std::size_t pD) {
    std::memcpy(mTempData, mData, sizeof(mTempData));

    const std::size_t ax = LocalX(pA);
    const std::size_t ay = LocalY(pA);
    const std::size_t bx = LocalX(pB);
    const std::size_t by = LocalY(pB);
    const std::size_t cx = LocalX(pC);
    const std::size_t cy = LocalY(pC);
    const std::size_t dx = LocalX(pD);
    const std::size_t dy = LocalY(pD);

    mData[0][0] = mTempData[ax][ay];
    mData[1][0] = mTempData[bx][by];
    mData[0][1] = mTempData[cx][cy];
    mData[1][1] = mTempData[dx][dy];
}

void Slice::_TriadAA() {
    // BCAD
    // A B / C D -> B C / A D
    // D fixed, opposite corner A, clockwise
    _CycleLocal3(0U, 1U, 2U);
}

void Slice::_TriadAB() {
    // CABD
    // A B / C D -> C A / B D
    // D fixed, opposite corner A, counter-clockwise
    _CycleLocal3(0U, 2U, 1U);
}

void Slice::_TriadBA() {
    // BDCA
    // A B / C D -> B D / C A
    // C fixed, opposite corner B, clockwise
    _CycleLocal3(0U, 1U, 3U);
}

void Slice::_TriadBB() {
    // DACB
    // A B / C D -> D A / C B
    // C fixed, opposite corner B, counter-clockwise
    _CycleLocal3(0U, 3U, 1U);
}

void Slice::_TriadCA() {
    // CBDA
    // A B / C D -> C B / D A
    // B fixed, opposite corner C, clockwise
    _CycleLocal3(0U, 2U, 3U);
}

void Slice::_TriadCB() {
    // DBAC
    // A B / C D -> D B / A C
    // B fixed, opposite corner C, counter-clockwise
    _CycleLocal3(0U, 3U, 2U);
}

void Slice::_TriadDA() {
    // ACDB
    // A B / C D -> A C / D B
    // A fixed, opposite corner D, clockwise
    _CycleLocal3(1U, 2U, 3U);
}

void Slice::_TriadDB() {
    // ADBC
    // A B / C D -> A D / B C
    // A fixed, opposite corner D, counter-clockwise
    _CycleLocal3(1U, 3U, 2U);
}

void Slice::_SnakeA() {
    // BCDA
    _LayoutLocal4(1U, 2U, 3U, 0U);
}

void Slice::_SnakeB() {
    // DABC
    _LayoutLocal4(3U, 0U, 1U, 2U);
}

void Slice::_SnakeC() {
    // CDBA
    _LayoutLocal4(2U, 3U, 1U, 0U);
}

void Slice::_SnakeD() {
    // DCAB
    _LayoutLocal4(3U, 2U, 0U, 1U);
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

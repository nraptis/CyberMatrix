//
//  UniqueQuarterGrid.cpp
//  CyberMatrix
//

#include "UniqueQuarterGrid.hpp"

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

UniqueQuarterGrid::UniqueQuarterGrid() {
    Reset();
}

void UniqueQuarterGrid::Reset() {
    std::uint8_t value = 0;

    for (std::size_t y = 0U; y < 4U; ++y) {
        for (std::size_t x = 0U; x < 4U; ++x) {
            mData[x][y] = value++;
        }
    }
}

void UniqueQuarterGrid::LoadFromM88QuadA(const M88 &pM88) {
    std::uint8_t values[16];

    std::size_t index = 0U;

    for (std::size_t y = 0U; y < 4U; ++y) {
        for (std::size_t x = 0U; x < 4U; ++x) {
            values[index++] = pM88.mData[M88::Slot(x, y)];
        }
    }

    std::uint8_t sorted[16];

    for (std::size_t i = 0U; i < 16U; ++i) {
        sorted[i] = values[i];
    }

    std::sort(sorted, sorted + 16U);

    for (std::size_t y = 0U; y < 4U; ++y) {
        for (std::size_t x = 0U; x < 4U; ++x) {
            const std::uint8_t value = pM88.mData[M88::Slot(x, y)];

            std::uint8_t normalized = 0U;

            for (std::uint8_t i = 0U; i < 16U; ++i) {
                if (sorted[i] == value) {
                    normalized = i;
                    break;
                }
            }

            mData[x][y] = normalized;
        }
    }
}

std::string UniqueQuarterGrid::Key() const {
    std::string result;
    result.reserve(4 * 4 * 3);

    for (std::size_t y = 0; y < 4; ++y) {
        for (std::size_t x = 0; x < 4; ++x) {
            result += std::to_string(mData[y][x]);
            result += ",";
        }
    }

    return result;
}

std::size_t UniqueQuarterGrid::HammingDistance(const UniqueQuarterGrid &pOther) const {
    std::size_t result = 0U;

    for (std::size_t y = 0U; y < 4U; ++y) {
        for (std::size_t x = 0U; x < 4U; ++x) {
            if (mData[x][y] != pOther.mData[x][y]) {
                ++result;
            }
        }
    }

    return result;
}


void UniqueQuarterGrid::Print() const {
    for (std::size_t y = 0; y < 4; ++y) {
        for (std::size_t x = 0; x < 4; ++x) {
            std::printf("%3d ", mData[y][x]);
        }

        std::printf("\n");
    }
}

int UniqueQuarterGrid::PositiveModulo(int pValue, int pMod) {
    int result = pValue % pMod;

    if (result < 0) {
        result += pMod;
    }

    return result;
}

void UniqueQuarterGrid::SpiralRect(std::size_t pX,
                                   std::size_t pY,
                                   std::size_t pWidth,
                                   std::size_t pHeight,
                                   int pAmount) {
    std::vector<std::pair<std::size_t, std::size_t>> path;

    if (pWidth == 0 || pHeight == 0) {
        return;
    }

    if (pWidth == 1 && pHeight == 1) {
        return;
    }

    for (std::size_t x = 0; x < pWidth; ++x) {
        path.push_back({ pX + x, pY });
    }

    for (std::size_t y = 1; y < pHeight; ++y) {
        path.push_back({ pX + pWidth - 1, pY + y });
    }

    if (pHeight > 1) {
        for (std::size_t x = pWidth - 1; x-- > 0;) {
            path.push_back({ pX + x, pY + pHeight - 1 });
        }
    }

    if (pWidth > 1) {
        for (std::size_t y = pHeight - 1; y-- > 1;) {
            path.push_back({ pX, pY + y });
        }
    }

    const int count = static_cast<int>(path.size());
    const int shift = PositiveModulo(pAmount, count);

    if (shift == 0) {
        return;
    }

    std::vector<std::uint8_t> oldValues;
    oldValues.resize(path.size());

    for (std::size_t i = 0; i < path.size(); ++i) {
        const std::size_t x = path[i].first;
        const std::size_t y = path[i].second;

        oldValues[i] = mData[y][x];
    }

    for (std::size_t i = 0; i < path.size(); ++i) {
        const std::size_t dstIndex = static_cast<std::size_t>(
            PositiveModulo(static_cast<int>(i) + shift, count)
        );

        const std::size_t dstX = path[dstIndex].first;
        const std::size_t dstY = path[dstIndex].second;

        mData[dstY][dstX] = oldValues[i];
    }
}

void UniqueQuarterGrid::RotateRight() {
    std::uint8_t aTemp[4][4];

    for (std::size_t x = 0; x < 4; ++x) {
        for (std::size_t y = 0; y < 4; ++y) {
            aTemp[x][y] = mData[x][y];
        }
    }

    for (std::size_t x = 0; x < 4; ++x) {
        for (std::size_t y = 0; y < 4; ++y) {
            const std::size_t aNewX = 3U - y;
            const std::size_t aNewY = x;

            mData[aNewX][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::RotateLeft() {
    std::uint8_t aTemp[4][4];

    for (std::size_t x = 0; x < 4; ++x) {
        for (std::size_t y = 0; y < 4; ++y) {
            aTemp[x][y] = mData[x][y];
        }
    }

    for (std::size_t x = 0; x < 4; ++x) {
        for (std::size_t y = 0; y < 4; ++y) {
            const std::size_t aNewX = y;
            const std::size_t aNewY = 3U - x;

            mData[aNewX][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::Rotate180() {
    RotateRight();
    RotateRight();
}

void UniqueQuarterGrid::FlipA() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewX = 3U - x;
            const std::size_t aNewY = y;

            mData[aNewX][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::FlipB() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewX = x;
            const std::size_t aNewY = 3U - y;

            mData[aNewX][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::FlipC() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewX = y;
            const std::size_t aNewY = x;

            mData[aNewX][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::FlipD() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewX = 3U - y;
            const std::size_t aNewY = 3U - x;

            mData[aNewX][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::JewelA() {
    SpiralRect(0U, 0U, 4U, 2U,  2);
    SpiralRect(0U, 2U, 4U, 2U, -2);
}

void UniqueQuarterGrid::JewelB() {
    SpiralRect(0U, 0U, 4U, 2U, -2);
    SpiralRect(0U, 2U, 4U, 2U,  2);
}

void UniqueQuarterGrid::JewelC() {
    SpiralRect(0U, 0U, 2U, 4U,  2);
    SpiralRect(2U, 0U, 2U, 4U, -2);
}

void UniqueQuarterGrid::JewelD() {
    SpiralRect(0U, 0U, 2U, 4U, -2);
    SpiralRect(2U, 0U, 2U, 4U,  2);
}


void UniqueQuarterGrid::ZigZagA() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // Pattern:
    //
    // a x b x      f x e x
    // c x d x  ->  h x g x
    // x e x f      x a x b
    // x g x h      x c x d

    mData[0][0] = aTemp[3][2];
    mData[2][0] = aTemp[1][2];

    mData[0][1] = aTemp[3][3];
    mData[2][1] = aTemp[1][3];

    mData[1][2] = aTemp[0][0];
    mData[3][2] = aTemp[2][0];

    mData[1][3] = aTemp[0][1];
    mData[3][3] = aTemp[2][1];
}

void UniqueQuarterGrid::ZigZagB() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // Pattern:
    //
    // x a x b      x e x f
    // x c x d  ->  x g x h
    // e x f x      b x a x
    // g x h x      d x c x

    mData[1][0] = aTemp[0][2];
    mData[3][0] = aTemp[2][2];

    mData[1][1] = aTemp[0][3];
    mData[3][1] = aTemp[2][3];

    mData[0][2] = aTemp[3][0];
    mData[2][2] = aTemp[1][0];

    mData[0][3] = aTemp[3][1];
    mData[2][3] = aTemp[1][1];
}

void UniqueQuarterGrid::ZigZagC() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // Pattern:
    //
    // a x b x      e x f x
    // c x d x  ->  g x h x
    // x e x f      x b x a
    // x g x h      x d x c

    mData[0][0] = aTemp[1][2];
    mData[2][0] = aTemp[3][2];

    mData[0][1] = aTemp[1][3];
    mData[2][1] = aTemp[3][3];

    mData[1][2] = aTemp[2][0];
    mData[3][2] = aTemp[0][0];

    mData[1][3] = aTemp[2][1];
    mData[3][3] = aTemp[0][1];
}

void UniqueQuarterGrid::ZigZagD() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // Pattern:
    //
    // x a x b      x f x e
    // x c x d  ->  x h x g
    // e x f x      a x b x
    // g x h x      c x d x

    mData[1][0] = aTemp[2][2];
    mData[3][0] = aTemp[0][2];

    mData[1][1] = aTemp[2][3];
    mData[3][1] = aTemp[0][3];

    mData[0][2] = aTemp[1][0];
    mData[2][2] = aTemp[3][0];

    mData[0][3] = aTemp[1][1];
    mData[2][3] = aTemp[3][1];
}

void UniqueQuarterGrid::ShearA() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    const std::size_t aHalfShift = 2U;
    const std::size_t aQuarterShift = 1U;

    for (std::size_t y = 0U; y < 4U; y++) {
        const std::size_t aShift = ((y & 1U) == 0U) ? aHalfShift : aQuarterShift;

        for (std::size_t x = 0U; x < 4U; x++) {
            const std::size_t aNewX = (x + aShift) & 3U;

            mData[aNewX][y] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::ShearB() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    const std::size_t aHalfShift = 2U;
    const std::size_t aQuarterShift = 1U;

    for (std::size_t y = 0U; y < 4U; y++) {
        const std::size_t aShift = ((y & 1U) == 0U) ? aQuarterShift : aHalfShift;

        for (std::size_t x = 0U; x < 4U; x++) {
            const std::size_t aNewX = (x + aShift) & 3U;

            mData[aNewX][y] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::ShearC() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    const std::size_t aHalfShift = 2U;
    const std::size_t aQuarterShift = 1U;

    for (std::size_t x = 0U; x < 4U; x++) {
        const std::size_t aShift = ((x & 1U) == 0U) ? aHalfShift : aQuarterShift;

        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewY = (y + aShift) & 3U;

            mData[x][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::ShearD() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    const std::size_t aHalfShift = 2U;
    const std::size_t aQuarterShift = 1U;

    for (std::size_t x = 0U; x < 4U; x++) {
        const std::size_t aShift = ((x & 1U) == 0U) ? aQuarterShift : aHalfShift;

        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewY = (y + aShift) & 3U;

            mData[x][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::SwapHalvesVer() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewY = (y + 2U) & 3U;

            mData[x][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::SwapHalvesHor() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewX = (x + 2U) & 3U;

            mData[aNewX][y] = aTemp[x][y];
        }
    }
}


void UniqueQuarterGrid::SwapAB() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // A B      B A
    // C D  ->  C D

    for (std::size_t x = 0U; x < 2U; ++x) {
        for (std::size_t y = 0U; y < 2U; ++y) {
            mData[x][y] = aTemp[x + 2U][y];
            mData[x + 2U][y] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::SwapBC() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // A B      A C
    // C D  ->  B D

    for (std::size_t x = 0U; x < 2U; ++x) {
        for (std::size_t y = 0U; y < 2U; ++y) {
            mData[x + 2U][y] = aTemp[x][y + 2U];
            mData[x][y + 2U] = aTemp[x + 2U][y];
        }
    }
}

void UniqueQuarterGrid::SwapAD() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // A B      D B
    // C D  ->  C A

    for (std::size_t x = 0U; x < 2U; ++x) {
        for (std::size_t y = 0U; y < 2U; ++y) {
            mData[x][y] = aTemp[x + 2U][y + 2U];
            mData[x + 2U][y + 2U] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::SwapLongQuartersA() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // Row bands:
    // A B C D  ->  B A D C

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewY = ((y & 1U) == 0U) ? y + 1U : y - 1U;

            mData[x][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::SwapLongQuartersB() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // Row bands:
    // A B C D  ->  C D A B

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewY = (y + 2U) & 3U;

            mData[x][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::SwapLongQuartersC() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // Row bands:
    // A B C D  ->  D C B A

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewY = 3U - y;

            mData[x][aNewY] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::SwapTallQuartersA() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // Column bands:
    // A B C D  ->  B A D C

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewX = ((x & 1U) == 0U) ? x + 1U : x - 1U;

            mData[aNewX][y] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::SwapTallQuartersB() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // Column bands:
    // A B C D  ->  C D A B

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewX = (x + 2U) & 3U;

            mData[aNewX][y] = aTemp[x][y];
        }
    }
}

void UniqueQuarterGrid::SwapTallQuartersC() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // Column bands:
    // A B C D  ->  D C B A

    for (std::size_t x = 0U; x < 4U; x++) {
        for (std::size_t y = 0U; y < 4U; y++) {
            const std::size_t aNewX = 3U - x;

            mData[aNewX][y] = aTemp[x][y];
        }
    }
}



void UniqueQuarterGrid::HexA() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // a b c d      f b c g
    // e f g h  ->  e a d h
    // i j k l      i m p l
    // m n o p      j n o k

    mData[0][0] = aTemp[1][1];
    mData[1][0] = aTemp[1][0];
    mData[2][0] = aTemp[2][0];
    mData[3][0] = aTemp[2][1];

    mData[0][1] = aTemp[0][1];
    mData[1][1] = aTemp[0][0];
    mData[2][1] = aTemp[3][0];
    mData[3][1] = aTemp[3][1];

    mData[0][2] = aTemp[0][2];
    mData[1][2] = aTemp[0][3];
    mData[2][2] = aTemp[3][3];
    mData[3][2] = aTemp[3][2];

    mData[0][3] = aTemp[1][2];
    mData[1][3] = aTemp[1][3];
    mData[2][3] = aTemp[2][3];
    mData[3][3] = aTemp[2][2];
}

void UniqueQuarterGrid::HexB() {
    std::uint8_t aTemp[4][4];

    std::memcpy(aTemp, mData, sizeof(aTemp));

    // a b c d      a e h d
    // e f g h  ->  b f g c
    // i j k l      n j k o
    // m n o p      m i l p

    mData[0][0] = aTemp[0][0];
    mData[1][0] = aTemp[0][1];
    mData[2][0] = aTemp[3][1];
    mData[3][0] = aTemp[3][0];

    mData[0][1] = aTemp[1][0];
    mData[1][1] = aTemp[1][1];
    mData[2][1] = aTemp[2][1];
    mData[3][1] = aTemp[2][0];

    mData[0][2] = aTemp[1][3];
    mData[1][2] = aTemp[1][2];
    mData[2][2] = aTemp[2][2];
    mData[3][2] = aTemp[2][3];

    mData[0][3] = aTemp[0][3];
    mData[1][3] = aTemp[0][2];
    mData[2][3] = aTemp[3][2];
    mData[3][3] = aTemp[3][3];
}

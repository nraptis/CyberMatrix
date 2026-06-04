//
//  UniqueQuarterGrid.hpp
//  CyberMatrix
//

#ifndef UniqueQuarterGrid_hpp
#define UniqueQuarterGrid_hpp

#include <cstdint>
#include <cstddef>
#include <string>

#include "M88.hpp"

class UniqueQuarterGrid {
public:
    static constexpr std::size_t kSize = 4U;

    UniqueQuarterGrid();

    void Reset();

    void LoadFromM88QuadA(const M88 &pM88);

    std::string Key() const;

    std::size_t HammingDistance(const UniqueQuarterGrid &pOther) const;
    

    void Print() const;

    void SpiralRect(std::size_t pX,
                    std::size_t pY,
                    std::size_t pWidth,
                    std::size_t pHeight,
                    int pAmount);
    
    void RotateRight();
    void RotateLeft();
    void Rotate180();

    void FlipA();
    void FlipB();
    void FlipC();
    void FlipD();

    void ShearA();
    void ShearB();
    void ShearC();
    void ShearD();

    void ZigZagA();
    void ZigZagB();
    void ZigZagC();
    void ZigZagD();

    void JewelA();
    void JewelB();
    void JewelC();
    void JewelD();

    void SwapHalvesVer();
    void SwapHalvesHor();

    void SwapAB();
    void SwapBC();
    void SwapAD();

    void SwapLongQuartersA();
    void SwapLongQuartersB();
    void SwapLongQuartersC();

    void SwapTallQuartersA();
    void SwapTallQuartersB();
    void SwapTallQuartersC();

    void HexA();
    void HexB();
    

public:
    std::uint8_t mData[4][4];

private:
    static int PositiveModulo(int pValue, int pMod);
};

#endif /* UniqueQuarterGrid_hpp */

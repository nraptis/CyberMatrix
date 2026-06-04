//
//  M88Slice.hpp
//  CyberMatrix
//
//  Created by nick on 5/29/26.
//

#ifndef M88Slice_hpp
#define M88Slice_hpp

#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>

struct Cycle {
    std::vector<std::size_t> mSlots;
};

struct Quint {
    
    Quint();
    
    void        MakeRight(int pX, int pY, int pSize);
    void        MakeLeft(int pX, int pY, int pSize);
    
    void        RotA();
    void        RotB();
    void        RotC();
    
    void        CrossA();
    void        CrossB();
    void        CrossC();
    
    int mXA; int mYA;
    int mXB; int mYB;
    int mXC; int mYC;
    int mXD; int mYD;
    
    int mSize;
    
    void Print() {
        printf("------ quint ------\n");
        printf("quint, a = [%2d %2d]\n", mXA, mYA);
        printf("quint, b = [%2d %2d]\n", mXB, mYB);
        printf("quint, c = [%2d %2d]\n", mXC, mYC);
        printf("quint, d = [%2d %2d]\n", mXD, mYD);
        printf("------ ----- ------\n");
    }
    
private:
    void        _Rotate();
    
};

class M88;

class Slice {
public:
    Slice(std::size_t pX, std::size_t pY, std::size_t pSize);
    Slice();
    
    void                        Make(std::size_t pX, std::size_t pY, std::size_t pSize);
    void                        Flood(M88 &pMatrix);
    
    void                        PrepareSlots();
    void                        RealizeSlots();
    std::size_t                 FindPreparedSlotForValue(std::uint8_t pValue) const;
    
    std::vector<Cycle>                          FindCycles() const;
    void                                        PrintCycles() const;
    void                                        PrintCycleCode(const char *pDataName) const;
    
    void                                        PrintRecipeFactory2x2(const std::string pName) const;
    void                                        PrintRecipeFactory4x4(const std::string pName) const;
    void                                        PrintRecipeFactory8x8(const std::string pName) const;
    void                                        PrintBlockMapFunction(const std::string pName);
    void                                        PrintVerifyExpected(const std::string pClass, const std::string pType, std::string pName);
    
    std::string                                 BuildRecipeFactory2x2HPP(const std::string &pName) const;
    std::string                                 BuildRecipeFactory4x4HPP(const std::string &pName) const;
    std::string                                 BuildRecipeFactory8x8HPP(const std::string &pName) const;

    std::string                                 BuildRecipeFactory2x2CPP(const std::string &pName) const;
    std::string                                 BuildRecipeFactory4x4CPP(const std::string &pName) const;
    std::string                                 BuildRecipeFactory8x8CPP(const std::string &pName) const;
    
    std::string                                 BuildCPP(std::vector<std::string> pNameChunks) const;
    
    
    void                                        PrintHPP(std::vector<std::string> pNameChunks) const;
    void                                        PrintCPP(std::vector<std::string> pNameChunks) const;
    
    static std::string                          BuildFunctionName(std::vector<std::string> pNameChunks);
    
    Quint                                       GetQuintRight(int pX, int pY);
    Quint                                       GetQuintLeft(int pX, int pY);
    
    std::uint8_t                                mData[8][8];
    std::uint8_t                                mTempData[8][8];
    std::uint8_t                                mOriginalData[8][8];
    
    std::size_t                                 mSlot[8][8];
    std::size_t                                 mTempSlot[8][8];
    
    std::size_t                                 mX;
    std::size_t                                 mY;
    std::size_t                                 mSize;
    
    void                                        _ApplyBlockMap8x8(const std::uint8_t pMap[8][8]);
    void                                        _ApplyBlockMap4x4(const std::uint8_t pMap[4][4]);
    void                                        _ApplyBlockMap2x2(const std::uint8_t pMap[2][2]);
    
    void                                        _Exchange(Quint &pQuintA, Quint &pQuintB);
    void                                        _Weave(Quint &pQuintA, Quint &pQuintB);
    
    void                                        _Identity();
    
    void                                        _RotA(Quint &pQuint);
    void                                        _RotB(Quint &pQuint);
    void                                        _RotC(Quint &pQuint);
    
    void                                        _RotA(); // right
    void                                        _RotB(); // left
    void                                        _RotC(); // 180
    
    void                                        _FlipA(); // horizontal
    void                                        _FlipB(); // diagonal
    void                                        _FlipC(); // main transpose
    void                                        _FlipD(); // anti transpose
    
    void                                        _ShearA();
    void                                        _ShearB();
    void                                        _ShearC();
    void                                        _ShearD();
    
    
    void                                        _JewelA();
    void                                        _JewelB();
    void                                        _JewelC();
    void                                        _JewelD();
    
    void                                        _ZigZagA();
    void                                        _ZigZagB();
    void                                        _ZigZagC();
    void                                        _ZigZagD();
    
    void                                        _SwapHalvesVer();
    void                                        _SwapHalvesHor();
    
    void                                        _SwapAB();
    void                                        _SwapBC();
    void                                        _SwapAD();
    
    void                                        _SwapLongQuartersA();
    void                                        _SwapLongQuartersB();
    void                                        _SwapLongQuartersC();

    void                                        _SwapTallQuartersA();
    void                                        _SwapTallQuartersB();
    void                                        _SwapTallQuartersC();
    
    void                                        _HexA();
    void                                        _HexB();

private:
    static int                                  _PositiveModulo(int pValue, int pMod);

    void                                        _SpiralRect(std::size_t pX,
                                            std::size_t pY,
                                            std::size_t pWidth,
                                            std::size_t pHeight,
                                            int pAmount);
    
};

#endif /* M88Slice_hpp */

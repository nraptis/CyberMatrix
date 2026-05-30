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

enum class Op : std::uint8_t {
    kRotA,    // rotate right
    kRotB,    // rotate left
    kRotC,    // rotate 180

    kFlipA,   // horizontal
    kFlipB,   // vertical
    kFlipC,   // main diagonal transpose
    kFlipD,   // anti diagonal transpose

    kBlockRotA,    // block rotate right
    kBlockRotB,    // block rotate left
    kBlockRotC,    // block rotate 180
    kBlockFlipA,   // block horizontal
    kBlockFlipB,   // block vertical
    kBlockFlipC,   // block main diagonal transpose
    kBlockFlipD,   // block anti diagonal transpose
    
    kPylonRotA,
    kPylonRotB,
    kPylonRotC,

    kPylonFlipA,
    kPylonFlipB,
    kPylonFlipC,
    kPylonFlipD,

    kPinA,
    kPinB,

    kCastleA,
    kCastleB,
    
    kTriadAA, // BCAD
    kTriadAB, // CABD
    kTriadBA, // BDCA
    kTriadBB, // DACB
    kTriadCA, // CBDA
    kTriadCB, // DBAC
    kTriadDA, // ACDB
    kTriadDB, // ADBC

    kSnakeA, // BCDA
    kSnakeB, // DABC
    kSnakeC, // CDBA
    kSnakeD, // DCAB
};

struct Cycle {
    std::vector<std::size_t> mSlots;
};

class M88;

class Slice {
public:
    Slice(std::size_t pX, std::size_t pY, std::size_t pSize);
    Slice();
    
    bool                Capable(Op pOp) const;
    void                Execute(Op pOp);
    void                Execute(std::vector<Op> pOps);
    
    void                Make(std::size_t pX, std::size_t pY, std::size_t pSize);
    void                Flood(M88 &pMatrix);
    
    void                PrepareSlots();
    void                RealizeSlots();
    std::size_t         FindPreparedSlotForValue(std::uint8_t pValue) const;
    
    std::vector<Cycle>  FindCycles() const;
    void                PrintCycles() const;
    void                PrintCycleCode(const char *pDataName) const;
    
    void                PrintHPP(std::vector<std::string> pNameChunks) const;
    void                PrintCPP(std::vector<std::string> pNameChunks) const;
    
    static std::string  BuildFunctionName(std::vector<std::string> pNameChunks);
    
    std::uint8_t        mData[8][8];
    std::uint8_t        mTempData[8][8];
    std::uint8_t        mOriginalData[8][8];
    
    std::size_t         mSlot[8][8];
    std::size_t         mTempSlot[8][8];
    
    std::size_t         mX;
    std::size_t         mY;
    std::size_t         mSize;
    
    void                _ApplyBlockMap4x4(const std::uint8_t pMap[4][4]);
    void                _ApplyBlockMap2x2(const std::uint8_t pMap[2][2]);
    
    
    void                _RotA(); // right
    void                _RotB(); // left
    void                _RotC(); // 180
    
    void                _FlipA(); // horizontal
    void                _FlipB(); // diagonal
    void                _FlipC(); // main transpose
    void                _FlipD(); // anti transpose
    
    void                _BlockRotA(); // anti transpose
    void                _BlockRotB(); // anti transpose
    void                _BlockRotC(); // anti transpose
    
    void                _BlockFlipA(); // anti transpose
    void                _BlockFlipB(); // anti transpose
    void                _BlockFlipC(); // anti transpose
    void                _BlockFlipD(); // anti transpose
    
    void                _PylonRotA();  // sixteenth-grid rotate right
    void                _PylonRotB();  // sixteenth-grid rotate left
    void                _PylonRotC();  // sixteenth-grid rotate 180
    
    void                _PylonFlipA(); // sixteenth-grid horizontal
    void                _PylonFlipB(); // sixteenth-grid vertical
    void                _PylonFlipC(); // sixteenth-grid main diagonal transpose
    void                _PylonFlipD(); // sixteenth-grid anti diagonal transpose
    
    
    // Only apply to, size >= 4
    void                _PinA();
    // a b c d
    // e f g h
    // i j k l
    // m n o p
    
    // m i e a
    // n g k b
    // o f j c
    // p l h d
    void                _PinB();
    
    
    // Only apply to, size == 4, size == 8
    void                _CastleA();
    // a b c d
    // e f g h
    // i j k l
    // m n o p
    
    // g l h k
    // b m a n
    // c p d o
    // f i e j
    
    void                _CastleB();
    // a b c d
    // e f g h
    // i j k l
    // m n o p
    
    // j e i f
    // o d p c
    // n a m b
    // k h l g
    
    
    
    void                _SwapLocal(std::size_t pA, std::size_t pB);
    void                _CycleLocal3(std::size_t pA,
                                     std::size_t pB,
                                     std::size_t pC);
    void                _LayoutLocal4(std::size_t pA,
                                      std::size_t pB,
                                      std::size_t pC,
                                      std::size_t pD);
    
    void                _TriadAA(); // BCAD
    void                _TriadAB(); // CABD
    void                _TriadBA(); // BDCA
    void                _TriadBB(); // DACB
    void                _TriadCA(); // CBDA
    void                _TriadCB(); // DBAC
    void                _TriadDA(); // ACDB
    void                _TriadDB(); // ADBC
    
    
    void                _SnakeA(); // BCDA
    void                _SnakeB(); // DABC
    void                _SnakeC(); // CDBA
    void                _SnakeD(); // DCAB
    
};

#endif /* M88Slice_hpp */

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

enum class Op: std::uint8_t {
    kRotateRight
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

    void                Make(std::size_t pX, std::size_t pY, std::size_t pSize);
    void                Flood(M88 &pMatrix);

    void                RotateRight();

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
};

#endif /* M88Slice_hpp */

//
//  M88.hpp
//  CyberMatrix
//
//  Created by nick on 5/29/26.
//

#ifndef M88_hpp
#define M88_hpp

#include <cstdint>
#include <cstddef>
#include <vector>
#include <string>
#include <cstring>

#include "M88Slice.hpp"

class M88 {
public:
    M88();

    static std::size_t  Slot(std::size_t pX, std::size_t pY);
    static std::size_t  X(std::size_t pSlot);
    static std::size_t  Y(std::size_t pSlot);

    void                Reset();

    void                Paste(Slice pSlice);

    void                RecordStart();
    void                RecordStop();
    bool                HasChange() const;

    void                RecordPrintFunction(std::vector<std::string> pNameChunks);
    void                RecordPrintFunction(const char *pOpName,
                                            const char *pPartName,
                                            int pNumber);

    std::uint8_t        mData[64];
    std::uint8_t        mBefore[64];
    std::uint8_t        mAfter[64];

    Slice               Get(std::size_t pX, std::size_t pY, std::size_t pSize);

    Slice               GetFull();

    Slice               GetQuarter(int pWhich);
    Slice               GetQuarterA();
    Slice               GetQuarterB();
    Slice               GetQuarterC();
    Slice               GetQuarterD();

    Slice               GetSixteenth(int pWhich);
    Slice               GetSixteenthA();
    Slice               GetSixteenthB();
    Slice               GetSixteenthC();
    Slice               GetSixteenthD();
    Slice               GetSixteenthE();
    Slice               GetSixteenthF();
    Slice               GetSixteenthG();
    Slice               GetSixteenthH();
    Slice               GetSixteenthI();
    Slice               GetSixteenthJ();
    Slice               GetSixteenthK();
    Slice               GetSixteenthL();
    Slice               GetSixteenthM();
    Slice               GetSixteenthN();
    Slice               GetSixteenthO();
    Slice               GetSixteenthP();
    
    void                                        RotateRightQuarterA();

    
    
};

#endif /* M88_hpp */

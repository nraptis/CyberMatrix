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

/*
 D fixed, opposite corner A:
 [Y] BCAD = TriadAA   // clockwise
 [Y] CABD = TriadAB   // counter-clockwise

 C fixed, opposite corner B:
 [Y] BDCA = TriadBA   // clockwise
 [Y] DACB = TriadBB   // counter-clockwise

 B fixed, opposite corner C:
 [Y] CBDA = TriadCA   // clockwise
 [Y] DBAC = TriadCB   // counter-clockwise

A fixed, opposite corner D:
 [Y] ACDB = TriadDA   // clockwise
 [Y] ADBC = TriadDB   // counter-clockwise

[Y] BADC = FlipA // 03
[Y] CDAB = FlipB // 04
//// [N] DCBA = RotC
[Y] CADB = RotA // 06
[Y] BDAC = RotB // 07

[Y] BCDA // 01 (D/B)
[Y] DABC // 02 (A)
 
[Y] CDBA // 14
[Y] DCAB // 05 (A)
 
BC
DA
 
DA
BC
 
CD
BA
 
DC
AB
 
*/


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

    std::uint8_t                                mData[64];
    std::uint8_t                                mBefore[64];
    std::uint8_t                                mAfter[64];

    
    // ignores bytes 1 and 2, uses last byte to unroll
    void                                        Slickshot(std::uint8_t *pOperationData,
                                                          std::uint8_t *pSource,
                                                          std::uint8_t *pDestination);
    
    
    Slice                                       Get(std::size_t pX, std::size_t pY, std::size_t pSize);

    Slice                                       GetFull();

    Slice                                       GetQuarter(int pWhich);
    Slice                                       GetQuarterA();
    Slice                                       GetQuarterB();
    Slice                                       GetQuarterC();
    Slice                                       GetQuarterD();

    Slice                                       GetSixteenth(int pWhich);
    Slice                                       GetSixteenthA();
    Slice                                       GetSixteenthB();
    Slice                                       GetSixteenthC();
    Slice                                       GetSixteenthD();
    Slice                                       GetSixteenthE();
    Slice                                       GetSixteenthF();
    Slice                                       GetSixteenthG();
    Slice                                       GetSixteenthH();
    Slice                                       GetSixteenthI();
    Slice                                       GetSixteenthJ();
    Slice                                       GetSixteenthK();
    Slice                                       GetSixteenthL();
    Slice                                       GetSixteenthM();
    Slice                                       GetSixteenthN();
    Slice                                       GetSixteenthO();
    Slice                                       GetSixteenthP();
    
    void                                        RotateRightQuarterA();
    
    void                                        CastleAQuarterA();
    void                                        CastleBQuarterA();
    
    
    
    // Full Ops (256 target, at 3)
    
    void                                        RotA();
    void                                        RotB();
    void                                        RotC();
    void                                        BlockRotA();
    void                                        BlockRotB();
    void                                        BlockRotC();
    void                                        PylonRotA();
    void                                        PylonRotB();
    void                                        PylonRotC();
    
    
    // Quarter Ops (256)
    void                                        SlickshotSix(std::uint8_t pByte);
    
    void                                        RotASixA();
    void                                        RotASixB();
    void                                        RotASixC();
    void                                        RotASixD();
    void                                        RotASixE();
    void                                        RotASixF();
    void                                        RotASixG();
    void                                        RotASixH();
    void                                        RotASixI();
    void                                        RotASixJ();
    void                                        RotASixK();
    void                                        RotASixL();
    void                                        RotASixM();
    void                                        RotASixN();
    void                                        RotASixO();
    void                                        RotASixP();
    
    void                                        RotBSixA();
    void                                        RotBSixB();
    void                                        RotBSixC();
    void                                        RotBSixD();
    void                                        RotBSixE();
    void                                        RotBSixF();
    void                                        RotBSixG();
    void                                        RotBSixH();
    void                                        RotBSixI();
    void                                        RotBSixJ();
    void                                        RotBSixK();
    void                                        RotBSixL();
    void                                        RotBSixM();
    void                                        RotBSixN();
    void                                        RotBSixO();
    void                                        RotBSixP();
    
    void                                        FlipASixA();
    void                                        FlipASixB();
    void                                        FlipASixC();
    void                                        FlipASixD();
    void                                        FlipASixE();
    void                                        FlipASixF();
    void                                        FlipASixG();
    void                                        FlipASixH();
    void                                        FlipASixI();
    void                                        FlipASixJ();
    void                                        FlipASixK();
    void                                        FlipASixL();
    void                                        FlipASixM();
    void                                        FlipASixN();
    void                                        FlipASixO();
    void                                        FlipASixP();

    void                                        FlipBSixA();
    void                                        FlipBSixB();
    void                                        FlipBSixC();
    void                                        FlipBSixD();
    void                                        FlipBSixE();
    void                                        FlipBSixF();
    void                                        FlipBSixG();
    void                                        FlipBSixH();
    void                                        FlipBSixI();
    void                                        FlipBSixJ();
    void                                        FlipBSixK();
    void                                        FlipBSixL();
    void                                        FlipBSixM();
    void                                        FlipBSixN();
    void                                        FlipBSixO();
    void                                        FlipBSixP();
    
    void                                        TriadAASixA();
    void                                        TriadAASixB();
    void                                        TriadAASixC();
    void                                        TriadAASixD();
    void                                        TriadAASixE();
    void                                        TriadAASixF();
    void                                        TriadAASixG();
    void                                        TriadAASixH();
    void                                        TriadAASixI();
    void                                        TriadAASixJ();
    void                                        TriadAASixK();
    void                                        TriadAASixL();
    void                                        TriadAASixM();
    void                                        TriadAASixN();
    void                                        TriadAASixO();
    void                                        TriadAASixP();
    
    void                                        TriadABSixA();
    void                                        TriadABSixB();
    void                                        TriadABSixC();
    void                                        TriadABSixD();
    void                                        TriadABSixE();
    void                                        TriadABSixF();
    void                                        TriadABSixG();
    void                                        TriadABSixH();
    void                                        TriadABSixI();
    void                                        TriadABSixJ();
    void                                        TriadABSixK();
    void                                        TriadABSixL();
    void                                        TriadABSixM();
    void                                        TriadABSixN();
    void                                        TriadABSixO();
    void                                        TriadABSixP();
    
    void                                        TriadBASixA();
    void                                        TriadBASixB();
    void                                        TriadBASixC();
    void                                        TriadBASixD();
    void                                        TriadBASixE();
    void                                        TriadBASixF();
    void                                        TriadBASixG();
    void                                        TriadBASixH();
    void                                        TriadBASixI();
    void                                        TriadBASixJ();
    void                                        TriadBASixK();
    void                                        TriadBASixL();
    void                                        TriadBASixM();
    void                                        TriadBASixN();
    void                                        TriadBASixO();
    void                                        TriadBASixP();
    
    void                                        TriadBBSixA();
    void                                        TriadBBSixB();
    void                                        TriadBBSixC();
    void                                        TriadBBSixD();
    void                                        TriadBBSixE();
    void                                        TriadBBSixF();
    void                                        TriadBBSixG();
    void                                        TriadBBSixH();
    void                                        TriadBBSixI();
    void                                        TriadBBSixJ();
    void                                        TriadBBSixK();
    void                                        TriadBBSixL();
    void                                        TriadBBSixM();
    void                                        TriadBBSixN();
    void                                        TriadBBSixO();
    void                                        TriadBBSixP();
    
    void                                        TriadCASixA();
    void                                        TriadCASixB();
    void                                        TriadCASixC();
    void                                        TriadCASixD();
    void                                        TriadCASixE();
    void                                        TriadCASixF();
    void                                        TriadCASixG();
    void                                        TriadCASixH();
    void                                        TriadCASixI();
    void                                        TriadCASixJ();
    void                                        TriadCASixK();
    void                                        TriadCASixL();
    void                                        TriadCASixM();
    void                                        TriadCASixN();
    void                                        TriadCASixO();
    void                                        TriadCASixP();
    
    void                                        TriadCBSixA();
    void                                        TriadCBSixB();
    void                                        TriadCBSixC();
    void                                        TriadCBSixD();
    void                                        TriadCBSixE();
    void                                        TriadCBSixF();
    void                                        TriadCBSixG();
    void                                        TriadCBSixH();
    void                                        TriadCBSixI();
    void                                        TriadCBSixJ();
    void                                        TriadCBSixK();
    void                                        TriadCBSixL();
    void                                        TriadCBSixM();
    void                                        TriadCBSixN();
    void                                        TriadCBSixO();
    void                                        TriadCBSixP();
    
    void                                        TriadDASixA();
    void                                        TriadDASixB();
    void                                        TriadDASixC();
    void                                        TriadDASixD();
    void                                        TriadDASixE();
    void                                        TriadDASixF();
    void                                        TriadDASixG();
    void                                        TriadDASixH();
    void                                        TriadDASixI();
    void                                        TriadDASixJ();
    void                                        TriadDASixK();
    void                                        TriadDASixL();
    void                                        TriadDASixM();
    void                                        TriadDASixN();
    void                                        TriadDASixO();
    void                                        TriadDASixP();
    
    void                                        TriadDBSixA();
    void                                        TriadDBSixB();
    void                                        TriadDBSixC();
    void                                        TriadDBSixD();
    void                                        TriadDBSixE();
    void                                        TriadDBSixF();
    void                                        TriadDBSixG();
    void                                        TriadDBSixH();
    void                                        TriadDBSixI();
    void                                        TriadDBSixJ();
    void                                        TriadDBSixK();
    void                                        TriadDBSixL();
    void                                        TriadDBSixM();
    void                                        TriadDBSixN();
    void                                        TriadDBSixO();
    void                                        TriadDBSixP();
    
    void                                        SnakeASixA();
    void                                        SnakeASixB();
    void                                        SnakeASixC();
    void                                        SnakeASixD();
    void                                        SnakeASixE();
    void                                        SnakeASixF();
    void                                        SnakeASixG();
    void                                        SnakeASixH();
    void                                        SnakeASixI();
    void                                        SnakeASixJ();
    void                                        SnakeASixK();
    void                                        SnakeASixL();
    void                                        SnakeASixM();
    void                                        SnakeASixN();
    void                                        SnakeASixO();
    void                                        SnakeASixP();
    
    void                                        SnakeBSixA();
    void                                        SnakeBSixB();
    void                                        SnakeBSixC();
    void                                        SnakeBSixD();
    void                                        SnakeBSixE();
    void                                        SnakeBSixF();
    void                                        SnakeBSixG();
    void                                        SnakeBSixH();
    void                                        SnakeBSixI();
    void                                        SnakeBSixJ();
    void                                        SnakeBSixK();
    void                                        SnakeBSixL();
    void                                        SnakeBSixM();
    void                                        SnakeBSixN();
    void                                        SnakeBSixO();
    void                                        SnakeBSixP();

    void                                        SnakeCSixA();
    void                                        SnakeCSixB();
    void                                        SnakeCSixC();
    void                                        SnakeCSixD();
    void                                        SnakeCSixE();
    void                                        SnakeCSixF();
    void                                        SnakeCSixG();
    void                                        SnakeCSixH();
    void                                        SnakeCSixI();
    void                                        SnakeCSixJ();
    void                                        SnakeCSixK();
    void                                        SnakeCSixL();
    void                                        SnakeCSixM();
    void                                        SnakeCSixN();
    void                                        SnakeCSixO();
    void                                        SnakeCSixP();

    void                                        SnakeDSixA();
    void                                        SnakeDSixB();
    void                                        SnakeDSixC();
    void                                        SnakeDSixD();
    void                                        SnakeDSixE();
    void                                        SnakeDSixF();
    void                                        SnakeDSixG();
    void                                        SnakeDSixH();
    void                                        SnakeDSixI();
    void                                        SnakeDSixJ();
    void                                        SnakeDSixK();
    void                                        SnakeDSixL();
    void                                        SnakeDSixM();
    void                                        SnakeDSixN();
    void                                        SnakeDSixO();
    void                                        SnakeDSixP();
    
};

#endif /* M88_hpp */

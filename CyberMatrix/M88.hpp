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
    
    static std::size_t                          Slot(std::size_t pX, std::size_t pY);
    static std::size_t                          X(std::size_t pSlot);
    static std::size_t                          Y(std::size_t pSlot);
    
    void                                        Reset();
    
    void                                        Paste(Slice pSlice);
    
    void                                        RecordStart();
    void                                        RecordStop();
    bool                                        HasChange() const;
    
    void                                        RecordPrintFunction(std::vector<std::string> pNameChunks);
    void                                        RecordPrintFunction(const char *pOpName,
                                                                    const char *pPartName,
                                                                    int pNumber);
    
    std::uint8_t                                mData[64];
    std::uint8_t                                mTemp[64];
    
    
    void                                        SwapRows(std::uint8_t pRowA, std::uint8_t pRowB);
    void                                        SwapCols(std::uint8_t pColA, std::uint8_t pColB);
    
    void                                        SwapRows(std::uint8_t pInstruction);
    void                                        SwapCols(std::uint8_t pInstruction);
    
    std::uint8_t                                mBefore[64];
    std::uint8_t                                mAfter[64];
    
    
    // ignores bytes 1 and 2, uses last byte to unroll
    void                                        Slickshot(std::uint8_t *pOperationData,
                                                          std::uint8_t *pSource,
                                                          std::uint8_t *pDestination);
    
    
    Slice                                       Get(std::size_t pX, std::size_t pY, std::size_t pSize);
    
    Slice                                       GetFull();
    
    Slice                                       GetQuad(int pWhich);
    Slice                                       GetQuadA();
    Slice                                       GetQuadB();
    Slice                                       GetQuadC();
    Slice                                       GetQuadD();
    
    Slice                                       GetMini(int pWhich);
    Slice                                       GetMiniA();
    Slice                                       GetMiniB();
    Slice                                       GetMiniC();
    Slice                                       GetMiniD();
    Slice                                       GetMiniE();
    Slice                                       GetMiniF();
    Slice                                       GetMiniG();
    Slice                                       GetMiniH();
    Slice                                       GetMiniI();
    Slice                                       GetMiniJ();
    Slice                                       GetMiniK();
    Slice                                       GetMiniL();
    Slice                                       GetMiniM();
    Slice                                       GetMiniN();
    Slice                                       GetMiniO();
    Slice                                       GetMiniP();
    
    
    // Quad Ops (256)
    void                                        SlickshotMini(std::uint8_t pByte);
    
    
    
    // Full - 78
    void                                        Full_RotA_8x8();
    void                                        Full_RotA_2x2();
    void                                        Full_RotA_4x4();
    void                                        Full_RotA_EachQuad_2x2();
    void                                        Full_RotA_EachQuad_4x4();
    void                                        Full_RotA_EachMini_2x2();
    void                                        Full_RotB_8x8();
    void                                        Full_RotB_2x2();
    void                                        Full_RotB_EachQuad_2x2();
    void                                        Full_RotB_EachMini_2x2();
    void                                        Full_RotB_4x4();
    void                                        Full_RotB_EachQuad_4x4();
    void                                        Full_RotC_2x2();
    void                                        Full_RotC_EachQuad_2x2();
    void                                        Full_RotC_EachMini_2x2();
    void                                        Full_RotC_4x4();
    void                                        Full_RotC_EachQuad_4x4();
    void                                        Full_RotC_8x8();
    
    void                                        Full_FlipA_2x2();
    void                                        Full_FlipA_EachQuad_2x2();
    void                                        Full_FlipA_EachMini_2x2();
    void                                        Full_FlipA_4x4();
    void                                        Full_FlipA_EachQuad_4x4();
    void                                        Full_FlipA_8x8();
    void                                        Full_FlipB_2x2();
    void                                        Full_FlipB_EachQuad_2x2();
    void                                        Full_FlipB_EachMini_2x2();
    void                                        Full_FlipB_4x4();
    void                                        Full_FlipB_EachQuad_4x4();
    void                                        Full_FlipB_8x8();
    void                                        Full_FlipC_2x2();
    void                                        Full_FlipC_EachQuad_2x2();
    void                                        Full_FlipC_EachMini_2x2();
    void                                        Full_FlipC_4x4();
    void                                        Full_FlipC_EachQuad_4x4();
    void                                        Full_FlipC_8x8();
    void                                        Full_FlipD_2x2();
    void                                        Full_FlipD_EachQuad_2x2();
    void                                        Full_FlipD_EachMini_2x2();
    void                                        Full_FlipD_4x4();
    void                                        Full_FlipD_EachQuad_4x4();
    void                                        Full_FlipD_8x8();
    
    void                                        Full_TriadA_2x2();
    void                                        Full_TriadA_EachQuad_2x2();
    void                                        Full_TriadA_EachMini_2x2();
    void                                        Full_TriadB_2x2();
    void                                        Full_TriadB_EachQuad_2x2();
    void                                        Full_TriadB_EachMini_2x2();
    void                                        Full_TriadC_2x2();
    void                                        Full_TriadC_EachQuad_2x2();
    void                                        Full_TriadC_EachMini_2x2();
    void                                        Full_TriadD_2x2();
    void                                        Full_TriadD_EachQuad_2x2();
    void                                        Full_TriadD_EachMini_2x2();
    void                                        Full_TriadE_2x2();
    void                                        Full_TriadE_EachQuad_2x2();
    void                                        Full_TriadE_EachMini_2x2();
    void                                        Full_TriadF_2x2();
    void                                        Full_TriadF_EachQuad_2x2();
    void                                        Full_TriadF_EachMini_2x2();
    void                                        Full_TriadG_2x2();
    void                                        Full_TriadG_EachQuad_2x2();
    void                                        Full_TriadG_EachMini_2x2();
    void                                        Full_TriadH_2x2();
    void                                        Full_TriadH_EachQuad_2x2();
    void                                        Full_TriadH_EachMini_2x2();
    
    void                                        Full_SnakeA_2x2();
    void                                        Full_SnakeA_EachQuad_2x2();
    void                                        Full_SnakeA_EachMini_2x2();
    void                                        Full_SnakeB_2x2();
    void                                        Full_SnakeB_EachQuad_2x2();
    void                                        Full_SnakeB_EachMini_2x2();
    void                                        Full_SnakeC_2x2();
    void                                        Full_SnakeC_EachQuad_2x2();
    void                                        Full_SnakeC_EachMini_2x2();
    void                                        Full_SnakeD_2x2();
    void                                        Full_SnakeD_EachQuad_2x2();
    void                                        Full_SnakeD_EachMini_2x2();
    
    
    // Quad A - 45
    void                                        Quad_RotA_2x2_A();
    void                                        Quad_RotA_4x4_A();
    void                                        Quad_RotA_EachMini_2x2_A();
    void                                        Quad_RotB_EachMini_2x2_A();
    void                                        Quad_RotB_2x2_A();
    void                                        Quad_RotB_4x4_A();
    void                                        Quad_RotC_EachMini_2x2_A();
    void                                        Quad_RotC_2x2_A();
    void                                        Quad_RotC_4x4_A();
    void                                        Quad_FlipA_EachMini_2x2_A();
    void                                        Quad_FlipA_2x2_A();
    void                                        Quad_FlipA_4x4_A();
    void                                        Quad_FlipB_EachMini_2x2_A();
    void                                        Quad_FlipB_2x2_A();
    void                                        Quad_FlipB_4x4_A();
    void                                        Quad_FlipC_EachMini_2x2_A();
    void                                        Quad_FlipC_2x2_A();
    void                                        Quad_FlipC_4x4_A();
    void                                        Quad_FlipD_EachMini_2x2_A();
    void                                        Quad_FlipD_2x2_A();
    void                                        Quad_FlipD_4x4_A();
    void                                        Quad_TriadA_EachMini_2x2_A();
    void                                        Quad_TriadA_2x2_A();
    void                                        Quad_TriadB_EachMini_2x2_A();
    void                                        Quad_TriadB_2x2_A();
    void                                        Quad_TriadC_EachMini_2x2_A();
    void                                        Quad_TriadC_2x2_A();
    void                                        Quad_TriadD_EachMini_2x2_A();
    void                                        Quad_TriadD_2x2_A();
    void                                        Quad_TriadE_EachMini_2x2_A();
    void                                        Quad_TriadE_2x2_A();
    void                                        Quad_TriadF_EachMini_2x2_A();
    void                                        Quad_TriadF_2x2_A();
    void                                        Quad_TriadG_EachMini_2x2_A();
    void                                        Quad_TriadG_2x2_A();
    void                                        Quad_TriadH_EachMini_2x2_A();
    void                                        Quad_TriadH_2x2_A();
    void                                        Quad_SnakeA_EachMini_2x2_A();
    void                                        Quad_SnakeA_2x2_A();
    void                                        Quad_SnakeB_EachMini_2x2_A();
    void                                        Quad_SnakeB_2x2_A();
    void                                        Quad_SnakeC_EachMini_2x2_A();
    void                                        Quad_SnakeC_2x2_A();
    void                                        Quad_SnakeD_EachMini_2x2_A();
    void                                        Quad_SnakeD_2x2_A();
    
    // Quad B - 45
    void                                        Quad_RotA_2x2_B();
    void                                        Quad_RotA_4x4_B();
    void                                        Quad_RotA_EachMini_2x2_B();
    void                                        Quad_RotB_EachMini_2x2_B();
    void                                        Quad_RotB_2x2_B();
    void                                        Quad_RotB_4x4_B();
    void                                        Quad_RotC_EachMini_2x2_B();
    void                                        Quad_RotC_2x2_B();
    void                                        Quad_RotC_4x4_B();
    void                                        Quad_FlipA_EachMini_2x2_B();
    void                                        Quad_FlipA_2x2_B();
    void                                        Quad_FlipA_4x4_B();
    void                                        Quad_FlipB_EachMini_2x2_B();
    void                                        Quad_FlipB_2x2_B();
    void                                        Quad_FlipB_4x4_B();
    void                                        Quad_FlipC_EachMini_2x2_B();
    void                                        Quad_FlipC_2x2_B();
    void                                        Quad_FlipC_4x4_B();
    void                                        Quad_FlipD_EachMini_2x2_B();
    void                                        Quad_FlipD_2x2_B();
    void                                        Quad_FlipD_4x4_B();
    void                                        Quad_TriadA_EachMini_2x2_B();
    void                                        Quad_TriadA_2x2_B();
    void                                        Quad_TriadB_EachMini_2x2_B();
    void                                        Quad_TriadB_2x2_B();
    void                                        Quad_TriadC_EachMini_2x2_B();
    void                                        Quad_TriadC_2x2_B();
    void                                        Quad_TriadD_EachMini_2x2_B();
    void                                        Quad_TriadD_2x2_B();
    void                                        Quad_TriadE_EachMini_2x2_B();
    void                                        Quad_TriadE_2x2_B();
    void                                        Quad_TriadF_EachMini_2x2_B();
    void                                        Quad_TriadF_2x2_B();
    void                                        Quad_TriadG_EachMini_2x2_B();
    void                                        Quad_TriadG_2x2_B();
    void                                        Quad_TriadH_EachMini_2x2_B();
    void                                        Quad_TriadH_2x2_B();
    void                                        Quad_SnakeA_EachMini_2x2_B();
    void                                        Quad_SnakeA_2x2_B();
    void                                        Quad_SnakeB_EachMini_2x2_B();
    void                                        Quad_SnakeB_2x2_B();
    void                                        Quad_SnakeC_EachMini_2x2_B();
    void                                        Quad_SnakeC_2x2_B();
    void                                        Quad_SnakeD_EachMini_2x2_B();
    void                                        Quad_SnakeD_2x2_B();
    
    // Quad C - 45
    void                                        Quad_RotA_2x2_C();
    void                                        Quad_RotA_4x4_C();
    void                                        Quad_RotA_EachMini_2x2_C();
    void                                        Quad_RotB_EachMini_2x2_C();
    void                                        Quad_RotB_2x2_C();
    void                                        Quad_RotB_4x4_C();
    void                                        Quad_RotC_EachMini_2x2_C();
    void                                        Quad_RotC_2x2_C();
    void                                        Quad_RotC_4x4_C();
    void                                        Quad_FlipA_EachMini_2x2_C();
    void                                        Quad_FlipA_2x2_C();
    void                                        Quad_FlipA_4x4_C();
    void                                        Quad_FlipB_EachMini_2x2_C();
    void                                        Quad_FlipB_2x2_C();
    void                                        Quad_FlipB_4x4_C();
    void                                        Quad_FlipC_EachMini_2x2_C();
    void                                        Quad_FlipC_2x2_C();
    void                                        Quad_FlipC_4x4_C();
    void                                        Quad_FlipD_EachMini_2x2_C();
    void                                        Quad_FlipD_2x2_C();
    void                                        Quad_FlipD_4x4_C();
    void                                        Quad_TriadA_EachMini_2x2_C();
    void                                        Quad_TriadA_2x2_C();
    void                                        Quad_TriadB_EachMini_2x2_C();
    void                                        Quad_TriadB_2x2_C();
    void                                        Quad_TriadC_EachMini_2x2_C();
    void                                        Quad_TriadC_2x2_C();
    void                                        Quad_TriadD_EachMini_2x2_C();
    void                                        Quad_TriadD_2x2_C();
    void                                        Quad_TriadE_EachMini_2x2_C();
    void                                        Quad_TriadE_2x2_C();
    void                                        Quad_TriadF_EachMini_2x2_C();
    void                                        Quad_TriadF_2x2_C();
    void                                        Quad_TriadG_EachMini_2x2_C();
    void                                        Quad_TriadG_2x2_C();
    void                                        Quad_TriadH_EachMini_2x2_C();
    void                                        Quad_TriadH_2x2_C();
    void                                        Quad_SnakeA_EachMini_2x2_C();
    void                                        Quad_SnakeA_2x2_C();
    void                                        Quad_SnakeB_EachMini_2x2_C();
    void                                        Quad_SnakeB_2x2_C();
    void                                        Quad_SnakeC_EachMini_2x2_C();
    void                                        Quad_SnakeC_2x2_C();
    void                                        Quad_SnakeD_EachMini_2x2_C();
    void                                        Quad_SnakeD_2x2_C();
    
    // Quad D - 45
    void                                        Quad_RotA_2x2_D();
    void                                        Quad_RotA_4x4_D();
    void                                        Quad_RotA_EachMini_2x2_D();
    void                                        Quad_RotB_EachMini_2x2_D();
    void                                        Quad_RotB_2x2_D();
    void                                        Quad_RotB_4x4_D();
    void                                        Quad_RotC_EachMini_2x2_D();
    void                                        Quad_RotC_2x2_D();
    void                                        Quad_RotC_4x4_D();
    void                                        Quad_FlipA_EachMini_2x2_D();
    void                                        Quad_FlipA_2x2_D();
    void                                        Quad_FlipA_4x4_D();
    void                                        Quad_FlipB_EachMini_2x2_D();
    void                                        Quad_FlipB_2x2_D();
    void                                        Quad_FlipB_4x4_D();
    void                                        Quad_FlipC_EachMini_2x2_D();
    void                                        Quad_FlipC_2x2_D();
    void                                        Quad_FlipC_4x4_D();
    void                                        Quad_FlipD_EachMini_2x2_D();
    void                                        Quad_FlipD_2x2_D();
    void                                        Quad_FlipD_4x4_D();
    void                                        Quad_TriadA_EachMini_2x2_D();
    void                                        Quad_TriadA_2x2_D();
    void                                        Quad_TriadB_EachMini_2x2_D();
    void                                        Quad_TriadB_2x2_D();
    void                                        Quad_TriadC_EachMini_2x2_D();
    void                                        Quad_TriadC_2x2_D();
    void                                        Quad_TriadD_EachMini_2x2_D();
    void                                        Quad_TriadD_2x2_D();
    void                                        Quad_TriadE_EachMini_2x2_D();
    void                                        Quad_TriadE_2x2_D();
    void                                        Quad_TriadF_EachMini_2x2_D();
    void                                        Quad_TriadF_2x2_D();
    void                                        Quad_TriadG_EachMini_2x2_D();
    void                                        Quad_TriadG_2x2_D();
    void                                        Quad_TriadH_EachMini_2x2_D();
    void                                        Quad_TriadH_2x2_D();
    void                                        Quad_SnakeA_EachMini_2x2_D();
    void                                        Quad_SnakeA_2x2_D();
    void                                        Quad_SnakeB_EachMini_2x2_D();
    void                                        Quad_SnakeB_2x2_D();
    void                                        Quad_SnakeC_EachMini_2x2_D();
    void                                        Quad_SnakeC_2x2_D();
    void                                        Quad_SnakeD_EachMini_2x2_D();
    void                                        Quad_SnakeD_2x2_D();
    
    
    // Mini - 304
    void                                        Mini_RotA_2x2_A();
    void                                        Mini_RotA_2x2_B();
    void                                        Mini_RotA_2x2_C();
    void                                        Mini_RotA_2x2_D();
    void                                        Mini_RotA_2x2_E();
    void                                        Mini_RotA_2x2_F();
    void                                        Mini_RotA_2x2_G();
    void                                        Mini_RotA_2x2_H();
    void                                        Mini_RotA_2x2_I();
    void                                        Mini_RotA_2x2_J();
    void                                        Mini_RotA_2x2_K();
    void                                        Mini_RotA_2x2_L();
    void                                        Mini_RotA_2x2_M();
    void                                        Mini_RotA_2x2_N();
    void                                        Mini_RotA_2x2_O();
    void                                        Mini_RotA_2x2_P();
    void                                        Mini_RotB_2x2_A();
    void                                        Mini_RotB_2x2_B();
    void                                        Mini_RotB_2x2_C();
    void                                        Mini_RotB_2x2_D();
    void                                        Mini_RotB_2x2_E();
    void                                        Mini_RotB_2x2_F();
    void                                        Mini_RotB_2x2_G();
    void                                        Mini_RotB_2x2_H();
    void                                        Mini_RotB_2x2_I();
    void                                        Mini_RotB_2x2_J();
    void                                        Mini_RotB_2x2_K();
    void                                        Mini_RotB_2x2_L();
    void                                        Mini_RotB_2x2_M();
    void                                        Mini_RotB_2x2_N();
    void                                        Mini_RotB_2x2_O();
    void                                        Mini_RotB_2x2_P();
    void                                        Mini_RotC_2x2_A();
    void                                        Mini_RotC_2x2_B();
    void                                        Mini_RotC_2x2_C();
    void                                        Mini_RotC_2x2_D();
    void                                        Mini_RotC_2x2_E();
    void                                        Mini_RotC_2x2_F();
    void                                        Mini_RotC_2x2_G();
    void                                        Mini_RotC_2x2_H();
    void                                        Mini_RotC_2x2_I();
    void                                        Mini_RotC_2x2_J();
    void                                        Mini_RotC_2x2_K();
    void                                        Mini_RotC_2x2_L();
    void                                        Mini_RotC_2x2_M();
    void                                        Mini_RotC_2x2_N();
    void                                        Mini_RotC_2x2_O();
    void                                        Mini_RotC_2x2_P();
    
    void                                        Mini_FlipA_2x2_A();
    void                                        Mini_FlipA_2x2_B();
    void                                        Mini_FlipA_2x2_C();
    void                                        Mini_FlipA_2x2_D();
    void                                        Mini_FlipA_2x2_E();
    void                                        Mini_FlipA_2x2_F();
    void                                        Mini_FlipA_2x2_G();
    void                                        Mini_FlipA_2x2_H();
    void                                        Mini_FlipA_2x2_I();
    void                                        Mini_FlipA_2x2_J();
    void                                        Mini_FlipA_2x2_K();
    void                                        Mini_FlipA_2x2_L();
    void                                        Mini_FlipA_2x2_M();
    void                                        Mini_FlipA_2x2_N();
    void                                        Mini_FlipA_2x2_O();
    void                                        Mini_FlipA_2x2_P();
    void                                        Mini_FlipB_2x2_A();
    void                                        Mini_FlipB_2x2_B();
    void                                        Mini_FlipB_2x2_C();
    void                                        Mini_FlipB_2x2_D();
    void                                        Mini_FlipB_2x2_E();
    void                                        Mini_FlipB_2x2_F();
    void                                        Mini_FlipB_2x2_G();
    void                                        Mini_FlipB_2x2_H();
    void                                        Mini_FlipB_2x2_I();
    void                                        Mini_FlipB_2x2_J();
    void                                        Mini_FlipB_2x2_K();
    void                                        Mini_FlipB_2x2_L();
    void                                        Mini_FlipB_2x2_M();
    void                                        Mini_FlipB_2x2_N();
    void                                        Mini_FlipB_2x2_O();
    void                                        Mini_FlipB_2x2_P();
    void                                        Mini_FlipC_2x2_A();
    void                                        Mini_FlipC_2x2_B();
    void                                        Mini_FlipC_2x2_C();
    void                                        Mini_FlipC_2x2_D();
    void                                        Mini_FlipC_2x2_E();
    void                                        Mini_FlipC_2x2_F();
    void                                        Mini_FlipC_2x2_G();
    void                                        Mini_FlipC_2x2_H();
    void                                        Mini_FlipC_2x2_I();
    void                                        Mini_FlipC_2x2_J();
    void                                        Mini_FlipC_2x2_K();
    void                                        Mini_FlipC_2x2_L();
    void                                        Mini_FlipC_2x2_M();
    void                                        Mini_FlipC_2x2_N();
    void                                        Mini_FlipC_2x2_O();
    void                                        Mini_FlipC_2x2_P();
    void                                        Mini_FlipD_2x2_A();
    void                                        Mini_FlipD_2x2_B();
    void                                        Mini_FlipD_2x2_C();
    void                                        Mini_FlipD_2x2_D();
    void                                        Mini_FlipD_2x2_E();
    void                                        Mini_FlipD_2x2_F();
    void                                        Mini_FlipD_2x2_G();
    void                                        Mini_FlipD_2x2_H();
    void                                        Mini_FlipD_2x2_I();
    void                                        Mini_FlipD_2x2_J();
    void                                        Mini_FlipD_2x2_K();
    void                                        Mini_FlipD_2x2_L();
    void                                        Mini_FlipD_2x2_M();
    void                                        Mini_FlipD_2x2_N();
    void                                        Mini_FlipD_2x2_O();
    void                                        Mini_FlipD_2x2_P();
    
    void                                        Mini_TriadA_2x2_A();
    void                                        Mini_TriadA_2x2_B();
    void                                        Mini_TriadA_2x2_C();
    void                                        Mini_TriadA_2x2_D();
    void                                        Mini_TriadA_2x2_E();
    void                                        Mini_TriadA_2x2_F();
    void                                        Mini_TriadA_2x2_G();
    void                                        Mini_TriadA_2x2_H();
    void                                        Mini_TriadA_2x2_I();
    void                                        Mini_TriadA_2x2_J();
    void                                        Mini_TriadA_2x2_K();
    void                                        Mini_TriadA_2x2_L();
    void                                        Mini_TriadA_2x2_M();
    void                                        Mini_TriadA_2x2_N();
    void                                        Mini_TriadA_2x2_O();
    void                                        Mini_TriadA_2x2_P();
    void                                        Mini_TriadB_2x2_A();
    void                                        Mini_TriadB_2x2_B();
    void                                        Mini_TriadB_2x2_C();
    void                                        Mini_TriadB_2x2_D();
    void                                        Mini_TriadB_2x2_E();
    void                                        Mini_TriadB_2x2_F();
    void                                        Mini_TriadB_2x2_G();
    void                                        Mini_TriadB_2x2_H();
    void                                        Mini_TriadB_2x2_I();
    void                                        Mini_TriadB_2x2_J();
    void                                        Mini_TriadB_2x2_K();
    void                                        Mini_TriadB_2x2_L();
    void                                        Mini_TriadB_2x2_M();
    void                                        Mini_TriadB_2x2_N();
    void                                        Mini_TriadB_2x2_O();
    void                                        Mini_TriadB_2x2_P();
    void                                        Mini_TriadC_2x2_A();
    void                                        Mini_TriadC_2x2_B();
    void                                        Mini_TriadC_2x2_C();
    void                                        Mini_TriadC_2x2_D();
    void                                        Mini_TriadC_2x2_E();
    void                                        Mini_TriadC_2x2_F();
    void                                        Mini_TriadC_2x2_G();
    void                                        Mini_TriadC_2x2_H();
    void                                        Mini_TriadC_2x2_I();
    void                                        Mini_TriadC_2x2_J();
    void                                        Mini_TriadC_2x2_K();
    void                                        Mini_TriadC_2x2_L();
    void                                        Mini_TriadC_2x2_M();
    void                                        Mini_TriadC_2x2_N();
    void                                        Mini_TriadC_2x2_O();
    void                                        Mini_TriadC_2x2_P();
    void                                        Mini_TriadD_2x2_A();
    void                                        Mini_TriadD_2x2_B();
    void                                        Mini_TriadD_2x2_C();
    void                                        Mini_TriadD_2x2_D();
    void                                        Mini_TriadD_2x2_E();
    void                                        Mini_TriadD_2x2_F();
    void                                        Mini_TriadD_2x2_G();
    void                                        Mini_TriadD_2x2_H();
    void                                        Mini_TriadD_2x2_I();
    void                                        Mini_TriadD_2x2_J();
    void                                        Mini_TriadD_2x2_K();
    void                                        Mini_TriadD_2x2_L();
    void                                        Mini_TriadD_2x2_M();
    void                                        Mini_TriadD_2x2_N();
    void                                        Mini_TriadD_2x2_O();
    void                                        Mini_TriadD_2x2_P();
    void                                        Mini_TriadE_2x2_A();
    void                                        Mini_TriadE_2x2_B();
    void                                        Mini_TriadE_2x2_C();
    void                                        Mini_TriadE_2x2_D();
    void                                        Mini_TriadE_2x2_E();
    void                                        Mini_TriadE_2x2_F();
    void                                        Mini_TriadE_2x2_G();
    void                                        Mini_TriadE_2x2_H();
    void                                        Mini_TriadE_2x2_I();
    void                                        Mini_TriadE_2x2_J();
    void                                        Mini_TriadE_2x2_K();
    void                                        Mini_TriadE_2x2_L();
    void                                        Mini_TriadE_2x2_M();
    void                                        Mini_TriadE_2x2_N();
    void                                        Mini_TriadE_2x2_O();
    void                                        Mini_TriadE_2x2_P();
    void                                        Mini_TriadF_2x2_A();
    void                                        Mini_TriadF_2x2_B();
    void                                        Mini_TriadF_2x2_C();
    void                                        Mini_TriadF_2x2_D();
    void                                        Mini_TriadF_2x2_E();
    void                                        Mini_TriadF_2x2_F();
    void                                        Mini_TriadF_2x2_G();
    void                                        Mini_TriadF_2x2_H();
    void                                        Mini_TriadF_2x2_I();
    void                                        Mini_TriadF_2x2_J();
    void                                        Mini_TriadF_2x2_K();
    void                                        Mini_TriadF_2x2_L();
    void                                        Mini_TriadF_2x2_M();
    void                                        Mini_TriadF_2x2_N();
    void                                        Mini_TriadF_2x2_O();
    void                                        Mini_TriadF_2x2_P();
    void                                        Mini_TriadG_2x2_A();
    void                                        Mini_TriadG_2x2_B();
    void                                        Mini_TriadG_2x2_C();
    void                                        Mini_TriadG_2x2_D();
    void                                        Mini_TriadG_2x2_E();
    void                                        Mini_TriadG_2x2_F();
    void                                        Mini_TriadG_2x2_G();
    void                                        Mini_TriadG_2x2_H();
    void                                        Mini_TriadG_2x2_I();
    void                                        Mini_TriadG_2x2_J();
    void                                        Mini_TriadG_2x2_K();
    void                                        Mini_TriadG_2x2_L();
    void                                        Mini_TriadG_2x2_M();
    void                                        Mini_TriadG_2x2_N();
    void                                        Mini_TriadG_2x2_O();
    void                                        Mini_TriadG_2x2_P();
    void                                        Mini_TriadH_2x2_A();
    void                                        Mini_TriadH_2x2_B();
    void                                        Mini_TriadH_2x2_C();
    void                                        Mini_TriadH_2x2_D();
    void                                        Mini_TriadH_2x2_E();
    void                                        Mini_TriadH_2x2_F();
    void                                        Mini_TriadH_2x2_G();
    void                                        Mini_TriadH_2x2_H();
    void                                        Mini_TriadH_2x2_I();
    void                                        Mini_TriadH_2x2_J();
    void                                        Mini_TriadH_2x2_K();
    void                                        Mini_TriadH_2x2_L();
    void                                        Mini_TriadH_2x2_M();
    void                                        Mini_TriadH_2x2_N();
    void                                        Mini_TriadH_2x2_O();
    void                                        Mini_TriadH_2x2_P();
    
    void                                        Mini_SnakeA_2x2_A();
    void                                        Mini_SnakeA_2x2_B();
    void                                        Mini_SnakeA_2x2_C();
    void                                        Mini_SnakeA_2x2_D();
    void                                        Mini_SnakeA_2x2_E();
    void                                        Mini_SnakeA_2x2_F();
    void                                        Mini_SnakeA_2x2_G();
    void                                        Mini_SnakeA_2x2_H();
    void                                        Mini_SnakeA_2x2_I();
    void                                        Mini_SnakeA_2x2_J();
    void                                        Mini_SnakeA_2x2_K();
    void                                        Mini_SnakeA_2x2_L();
    void                                        Mini_SnakeA_2x2_M();
    void                                        Mini_SnakeA_2x2_N();
    void                                        Mini_SnakeA_2x2_O();
    void                                        Mini_SnakeA_2x2_P();
    void                                        Mini_SnakeB_2x2_A();
    void                                        Mini_SnakeB_2x2_B();
    void                                        Mini_SnakeB_2x2_C();
    void                                        Mini_SnakeB_2x2_D();
    void                                        Mini_SnakeB_2x2_E();
    void                                        Mini_SnakeB_2x2_F();
    void                                        Mini_SnakeB_2x2_G();
    void                                        Mini_SnakeB_2x2_H();
    void                                        Mini_SnakeB_2x2_I();
    void                                        Mini_SnakeB_2x2_J();
    void                                        Mini_SnakeB_2x2_K();
    void                                        Mini_SnakeB_2x2_L();
    void                                        Mini_SnakeB_2x2_M();
    void                                        Mini_SnakeB_2x2_N();
    void                                        Mini_SnakeB_2x2_O();
    void                                        Mini_SnakeB_2x2_P();
    void                                        Mini_SnakeC_2x2_A();
    void                                        Mini_SnakeC_2x2_B();
    void                                        Mini_SnakeC_2x2_C();
    void                                        Mini_SnakeC_2x2_D();
    void                                        Mini_SnakeC_2x2_E();
    void                                        Mini_SnakeC_2x2_F();
    void                                        Mini_SnakeC_2x2_G();
    void                                        Mini_SnakeC_2x2_H();
    void                                        Mini_SnakeC_2x2_I();
    void                                        Mini_SnakeC_2x2_J();
    void                                        Mini_SnakeC_2x2_K();
    void                                        Mini_SnakeC_2x2_L();
    void                                        Mini_SnakeC_2x2_M();
    void                                        Mini_SnakeC_2x2_N();
    void                                        Mini_SnakeC_2x2_O();
    void                                        Mini_SnakeC_2x2_P();
    void                                        Mini_SnakeD_2x2_A();
    void                                        Mini_SnakeD_2x2_B();
    void                                        Mini_SnakeD_2x2_C();
    void                                        Mini_SnakeD_2x2_D();
    void                                        Mini_SnakeD_2x2_E();
    void                                        Mini_SnakeD_2x2_F();
    void                                        Mini_SnakeD_2x2_G();
    void                                        Mini_SnakeD_2x2_H();
    void                                        Mini_SnakeD_2x2_I();
    void                                        Mini_SnakeD_2x2_J();
    void                                        Mini_SnakeD_2x2_K();
    void                                        Mini_SnakeD_2x2_L();
    void                                        Mini_SnakeD_2x2_M();
    void                                        Mini_SnakeD_2x2_N();
    void                                        Mini_SnakeD_2x2_O();
    void                                        Mini_SnakeD_2x2_P();
    
    
};

#endif /* M88_hpp */

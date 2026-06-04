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
    
    
    // Full - 165
    void                                        Full_RotA_2x2();
    void                                        Full_RotA_4x4();
    void                                        Full_RotA_8x8();
    void                                        Full_RotA_EachMini_2x2();
    void                                        Full_RotA_EachQuad_2x2();
    void                                        Full_RotA_EachQuad_4x4();
    void                                        Full_RotB_2x2();
    void                                        Full_RotB_4x4();
    void                                        Full_RotB_8x8();
    void                                        Full_RotB_EachMini_2x2();
    void                                        Full_RotB_EachQuad_2x2();
    void                                        Full_RotB_EachQuad_4x4();
    void                                        Full_RotC_2x2();
    void                                        Full_RotC_4x4();
    void                                        Full_RotC_8x8();
    void                                        Full_RotC_EachMini_2x2();
    void                                        Full_RotC_EachQuad_2x2();
    void                                        Full_RotC_EachQuad_4x4();
    
    void                                        Full_FlipA_2x2();
    void                                        Full_FlipA_4x4();
    void                                        Full_FlipA_8x8();
    void                                        Full_FlipA_EachMini_2x2();
    void                                        Full_FlipA_EachQuad_2x2();
    void                                        Full_FlipA_EachQuad_4x4();
    void                                        Full_FlipB_2x2();
    void                                        Full_FlipB_4x4();
    void                                        Full_FlipB_8x8();
    void                                        Full_FlipB_EachMini_2x2();
    void                                        Full_FlipB_EachQuad_2x2();
    void                                        Full_FlipB_EachQuad_4x4();
    void                                        Full_FlipC_2x2();
    void                                        Full_FlipC_4x4();
    void                                        Full_FlipC_8x8();
    void                                        Full_FlipC_EachMini_2x2();
    void                                        Full_FlipC_EachQuad_2x2();
    void                                        Full_FlipC_EachQuad_4x4();
    void                                        Full_FlipD_2x2();
    void                                        Full_FlipD_4x4();
    void                                        Full_FlipD_8x8();
    void                                        Full_FlipD_EachMini_2x2();
    void                                        Full_FlipD_EachQuad_2x2();
    void                                        Full_FlipD_EachQuad_4x4();
    
    void                                        Full_TriadA_2x2();
    void                                        Full_TriadA_EachMini_2x2();
    void                                        Full_TriadA_EachQuad_2x2();
    void                                        Full_TriadB_2x2();
    void                                        Full_TriadB_EachMini_2x2();
    void                                        Full_TriadB_EachQuad_2x2();
    void                                        Full_TriadC_2x2();
    void                                        Full_TriadC_EachMini_2x2();
    void                                        Full_TriadC_EachQuad_2x2();
    void                                        Full_TriadD_2x2();
    void                                        Full_TriadD_EachMini_2x2();
    void                                        Full_TriadD_EachQuad_2x2();
    void                                        Full_TriadE_2x2();
    void                                        Full_TriadE_EachMini_2x2();
    void                                        Full_TriadE_EachQuad_2x2();
    void                                        Full_TriadF_2x2();
    void                                        Full_TriadF_EachMini_2x2();
    void                                        Full_TriadF_EachQuad_2x2();
    void                                        Full_TriadG_2x2();
    void                                        Full_TriadG_EachMini_2x2();
    void                                        Full_TriadG_EachQuad_2x2();
    void                                        Full_TriadH_2x2();
    void                                        Full_TriadH_EachMini_2x2();
    void                                        Full_TriadH_EachQuad_2x2();
    
    void                                        Full_SnakeA_2x2();
    void                                        Full_SnakeA_EachMini_2x2();
    void                                        Full_SnakeA_EachQuad_2x2();
    void                                        Full_SnakeB_2x2();
    void                                        Full_SnakeB_EachMini_2x2();
    void                                        Full_SnakeB_EachQuad_2x2();
    void                                        Full_SnakeC_2x2();
    void                                        Full_SnakeC_EachMini_2x2();
    void                                        Full_SnakeC_EachQuad_2x2();
    void                                        Full_SnakeD_2x2();
    void                                        Full_SnakeD_EachMini_2x2();
    void                                        Full_SnakeD_EachQuad_2x2();
    
    
    void                                        Full_TowerA_4x4();
    void                                        Full_TowerA_EachQuad_4x4();
    void                                        Full_TowerB_4x4();
    void                                        Full_TowerB_EachQuad_4x4();
    
    
    void                                        Full_PinA_8x8();
    void                                        Full_PinB_8x8();
    
    void                                        Full_SwapA_2x2();
    void                                        Full_SwapA_EachMini_2x2();
    void                                        Full_SwapA_EachQuad_2x2();
    void                                        Full_SwapB_2x2();
    void                                        Full_SwapB_EachMini_2x2();
    void                                        Full_SwapB_EachQuad_2x2();
    void                                        Full_SwapC_2x2();
    void                                        Full_SwapC_EachMini_2x2();
    void                                        Full_SwapC_EachQuad_2x2();
    void                                        Full_SwapD_2x2();
    void                                        Full_SwapD_EachMini_2x2();
    void                                        Full_SwapD_EachQuad_2x2();
    
    void                                        Full_ShearA_4x4();
    void                                        Full_ShearA_8x8();
    void                                        Full_ShearA_EachQuad_4x4();
    void                                        Full_ShearB_4x4();
    void                                        Full_ShearB_8x8();
    void                                        Full_ShearB_EachQuad_4x4();
    void                                        Full_ShearC_4x4();
    void                                        Full_ShearC_8x8();
    void                                        Full_ShearC_EachQuad_4x4();
    void                                        Full_ShearD_4x4();
    void                                        Full_ShearD_8x8();
    void                                        Full_ShearD_EachQuad_4x4();
    
    
    // Quad A - 84
    void                                        Quad_RotA_2x2_A();
    void                                        Quad_RotA_4x4_A();
    void                                        Quad_RotA_EachMini_2x2_A();
    void                                        Quad_RotB_2x2_A();
    void                                        Quad_RotB_4x4_A();
    void                                        Quad_RotB_EachMini_2x2_A();
    void                                        Quad_RotC_2x2_A();
    void                                        Quad_RotC_4x4_A();
    void                                        Quad_RotC_EachMini_2x2_A();
    
    void                                        Quad_FlipA_2x2_A();
    void                                        Quad_FlipA_4x4_A();
    void                                        Quad_FlipA_EachMini_2x2_A();
    void                                        Quad_FlipB_2x2_A();
    void                                        Quad_FlipB_4x4_A();
    void                                        Quad_FlipB_EachMini_2x2_A();
    void                                        Quad_FlipC_2x2_A();
    void                                        Quad_FlipC_4x4_A();
    void                                        Quad_FlipC_EachMini_2x2_A();
    void                                        Quad_FlipD_2x2_A();
    void                                        Quad_FlipD_4x4_A();
    void                                        Quad_FlipD_EachMini_2x2_A();
    
    void                                        Quad_TriadA_2x2_A();
    void                                        Quad_TriadA_EachMini_2x2_A();
    void                                        Quad_TriadB_2x2_A();
    void                                        Quad_TriadB_EachMini_2x2_A();
    void                                        Quad_TriadC_2x2_A();
    void                                        Quad_TriadC_EachMini_2x2_A();
    void                                        Quad_TriadD_2x2_A();
    void                                        Quad_TriadD_EachMini_2x2_A();
    void                                        Quad_TriadE_2x2_A();
    void                                        Quad_TriadE_EachMini_2x2_A();
    void                                        Quad_TriadF_2x2_A();
    void                                        Quad_TriadF_EachMini_2x2_A();
    void                                        Quad_TriadG_2x2_A();
    void                                        Quad_TriadG_EachMini_2x2_A();
    void                                        Quad_TriadH_2x2_A();
    void                                        Quad_TriadH_EachMini_2x2_A();
    
    void                                        Quad_SnakeA_2x2_A();
    void                                        Quad_SnakeA_EachMini_2x2_A();
    void                                        Quad_SnakeB_2x2_A();
    void                                        Quad_SnakeB_EachMini_2x2_A();
    void                                        Quad_SnakeC_2x2_A();
    void                                        Quad_SnakeC_EachMini_2x2_A();
    void                                        Quad_SnakeD_2x2_A();
    void                                        Quad_SnakeD_EachMini_2x2_A();
    
    
    void                                        Quad_TowerA_4x4_A();
    void                                        Quad_TowerB_4x4_A();
    
    
    void                                        Quad_SwapA_2x2_A();
    void                                        Quad_SwapA_EachMini_2x2_A();
    void                                        Quad_SwapB_2x2_A();
    void                                        Quad_SwapB_EachMini_2x2_A();
    void                                        Quad_SwapC_2x2_A();
    void                                        Quad_SwapC_EachMini_2x2_A();
    void                                        Quad_SwapD_2x2_A();
    void                                        Quad_SwapD_EachMini_2x2_A();
    
    void                                        Quad_ShearA_4x4_A();
    void                                        Quad_ShearB_4x4_A();
    void                                        Quad_ShearC_4x4_A();
    void                                        Quad_ShearD_4x4_A();
    
    
    // Quad B - 84
    void                                        Quad_RotA_2x2_B();
    void                                        Quad_RotA_4x4_B();
    void                                        Quad_RotA_EachMini_2x2_B();
    void                                        Quad_RotB_2x2_B();
    void                                        Quad_RotB_4x4_B();
    void                                        Quad_RotB_EachMini_2x2_B();
    void                                        Quad_RotC_2x2_B();
    void                                        Quad_RotC_4x4_B();
    void                                        Quad_RotC_EachMini_2x2_B();
    
    void                                        Quad_FlipA_2x2_B();
    void                                        Quad_FlipA_4x4_B();
    void                                        Quad_FlipA_EachMini_2x2_B();
    void                                        Quad_FlipB_2x2_B();
    void                                        Quad_FlipB_4x4_B();
    void                                        Quad_FlipB_EachMini_2x2_B();
    void                                        Quad_FlipC_2x2_B();
    void                                        Quad_FlipC_4x4_B();
    void                                        Quad_FlipC_EachMini_2x2_B();
    void                                        Quad_FlipD_2x2_B();
    void                                        Quad_FlipD_4x4_B();
    void                                        Quad_FlipD_EachMini_2x2_B();
    
    void                                        Quad_TriadA_2x2_B();
    void                                        Quad_TriadA_EachMini_2x2_B();
    void                                        Quad_TriadB_2x2_B();
    void                                        Quad_TriadB_EachMini_2x2_B();
    void                                        Quad_TriadC_2x2_B();
    void                                        Quad_TriadC_EachMini_2x2_B();
    void                                        Quad_TriadD_2x2_B();
    void                                        Quad_TriadD_EachMini_2x2_B();
    void                                        Quad_TriadE_2x2_B();
    void                                        Quad_TriadE_EachMini_2x2_B();
    void                                        Quad_TriadF_2x2_B();
    void                                        Quad_TriadF_EachMini_2x2_B();
    void                                        Quad_TriadG_2x2_B();
    void                                        Quad_TriadG_EachMini_2x2_B();
    void                                        Quad_TriadH_2x2_B();
    void                                        Quad_TriadH_EachMini_2x2_B();
    
    void                                        Quad_SnakeA_2x2_B();
    void                                        Quad_SnakeA_EachMini_2x2_B();
    void                                        Quad_SnakeB_2x2_B();
    void                                        Quad_SnakeB_EachMini_2x2_B();
    void                                        Quad_SnakeC_2x2_B();
    void                                        Quad_SnakeC_EachMini_2x2_B();
    void                                        Quad_SnakeD_2x2_B();
    void                                        Quad_SnakeD_EachMini_2x2_B();
    
    
    void                                        Quad_TowerA_4x4_B();
    void                                        Quad_TowerB_4x4_B();
    
    
    void                                        Quad_SwapA_2x2_B();
    void                                        Quad_SwapA_EachMini_2x2_B();
    void                                        Quad_SwapB_2x2_B();
    void                                        Quad_SwapB_EachMini_2x2_B();
    void                                        Quad_SwapC_2x2_B();
    void                                        Quad_SwapC_EachMini_2x2_B();
    void                                        Quad_SwapD_2x2_B();
    void                                        Quad_SwapD_EachMini_2x2_B();

    void                                        Quad_ShearA_4x4_B();
    void                                        Quad_ShearB_4x4_B();
    void                                        Quad_ShearC_4x4_B();
    void                                        Quad_ShearD_4x4_B();
    
    // Quad C - 84
    void                                        Quad_RotA_2x2_C();
    void                                        Quad_RotA_4x4_C();
    void                                        Quad_RotA_EachMini_2x2_C();
    void                                        Quad_RotB_2x2_C();
    void                                        Quad_RotB_4x4_C();
    void                                        Quad_RotB_EachMini_2x2_C();
    void                                        Quad_RotC_2x2_C();
    void                                        Quad_RotC_4x4_C();
    void                                        Quad_RotC_EachMini_2x2_C();
    
    void                                        Quad_FlipA_2x2_C();
    void                                        Quad_FlipA_4x4_C();
    void                                        Quad_FlipA_EachMini_2x2_C();
    void                                        Quad_FlipB_2x2_C();
    void                                        Quad_FlipB_4x4_C();
    void                                        Quad_FlipB_EachMini_2x2_C();
    void                                        Quad_FlipC_2x2_C();
    void                                        Quad_FlipC_4x4_C();
    void                                        Quad_FlipC_EachMini_2x2_C();
    void                                        Quad_FlipD_2x2_C();
    void                                        Quad_FlipD_4x4_C();
    void                                        Quad_FlipD_EachMini_2x2_C();
    
    void                                        Quad_TriadA_2x2_C();
    void                                        Quad_TriadA_EachMini_2x2_C();
    void                                        Quad_TriadB_2x2_C();
    void                                        Quad_TriadB_EachMini_2x2_C();
    void                                        Quad_TriadC_2x2_C();
    void                                        Quad_TriadC_EachMini_2x2_C();
    void                                        Quad_TriadD_2x2_C();
    void                                        Quad_TriadD_EachMini_2x2_C();
    void                                        Quad_TriadE_2x2_C();
    void                                        Quad_TriadE_EachMini_2x2_C();
    void                                        Quad_TriadF_2x2_C();
    void                                        Quad_TriadF_EachMini_2x2_C();
    void                                        Quad_TriadG_2x2_C();
    void                                        Quad_TriadG_EachMini_2x2_C();
    void                                        Quad_TriadH_2x2_C();
    void                                        Quad_TriadH_EachMini_2x2_C();
    
    void                                        Quad_SnakeA_2x2_C();
    void                                        Quad_SnakeA_EachMini_2x2_C();
    void                                        Quad_SnakeB_2x2_C();
    void                                        Quad_SnakeB_EachMini_2x2_C();
    void                                        Quad_SnakeC_2x2_C();
    void                                        Quad_SnakeC_EachMini_2x2_C();
    void                                        Quad_SnakeD_2x2_C();
    void                                        Quad_SnakeD_EachMini_2x2_C();
    
    
    void                                        Quad_TowerA_4x4_C();
    void                                        Quad_TowerB_4x4_C();
    
    
    void                                        Quad_SwapA_2x2_C();
    void                                        Quad_SwapA_EachMini_2x2_C();
    void                                        Quad_SwapB_2x2_C();
    void                                        Quad_SwapB_EachMini_2x2_C();
    void                                        Quad_SwapC_2x2_C();
    void                                        Quad_SwapC_EachMini_2x2_C();
    void                                        Quad_SwapD_2x2_C();
    void                                        Quad_SwapD_EachMini_2x2_C();

    void                                        Quad_ShearA_4x4_C();
    void                                        Quad_ShearB_4x4_C();
    void                                        Quad_ShearC_4x4_C();
    void                                        Quad_ShearD_4x4_C();
    
    // Quad D - 84
    void                                        Quad_RotA_2x2_D();
    void                                        Quad_RotA_4x4_D();
    void                                        Quad_RotA_EachMini_2x2_D();
    void                                        Quad_RotB_2x2_D();
    void                                        Quad_RotB_4x4_D();
    void                                        Quad_RotB_EachMini_2x2_D();
    void                                        Quad_RotC_2x2_D();
    void                                        Quad_RotC_4x4_D();
    void                                        Quad_RotC_EachMini_2x2_D();
    
    void                                        Quad_FlipA_2x2_D();
    void                                        Quad_FlipA_4x4_D();
    void                                        Quad_FlipA_EachMini_2x2_D();
    void                                        Quad_FlipB_2x2_D();
    void                                        Quad_FlipB_4x4_D();
    void                                        Quad_FlipB_EachMini_2x2_D();
    void                                        Quad_FlipC_2x2_D();
    void                                        Quad_FlipC_4x4_D();
    void                                        Quad_FlipC_EachMini_2x2_D();
    void                                        Quad_FlipD_2x2_D();
    void                                        Quad_FlipD_4x4_D();
    void                                        Quad_FlipD_EachMini_2x2_D();
    
    void                                        Quad_TriadA_2x2_D();
    void                                        Quad_TriadA_EachMini_2x2_D();
    void                                        Quad_TriadB_2x2_D();
    void                                        Quad_TriadB_EachMini_2x2_D();
    void                                        Quad_TriadC_2x2_D();
    void                                        Quad_TriadC_EachMini_2x2_D();
    void                                        Quad_TriadD_2x2_D();
    void                                        Quad_TriadD_EachMini_2x2_D();
    void                                        Quad_TriadE_2x2_D();
    void                                        Quad_TriadE_EachMini_2x2_D();
    void                                        Quad_TriadF_2x2_D();
    void                                        Quad_TriadF_EachMini_2x2_D();
    void                                        Quad_TriadG_2x2_D();
    void                                        Quad_TriadG_EachMini_2x2_D();
    void                                        Quad_TriadH_2x2_D();
    void                                        Quad_TriadH_EachMini_2x2_D();
    
    void                                        Quad_SnakeA_2x2_D();
    void                                        Quad_SnakeA_EachMini_2x2_D();
    void                                        Quad_SnakeB_2x2_D();
    void                                        Quad_SnakeB_EachMini_2x2_D();
    void                                        Quad_SnakeC_2x2_D();
    void                                        Quad_SnakeC_EachMini_2x2_D();
    void                                        Quad_SnakeD_2x2_D();
    void                                        Quad_SnakeD_EachMini_2x2_D();
    
    
    void                                        Quad_TowerA_4x4_D();
    void                                        Quad_TowerB_4x4_D();
    
    
    void                                        Quad_SwapA_2x2_D();
    void                                        Quad_SwapA_EachMini_2x2_D();
    void                                        Quad_SwapB_2x2_D();
    void                                        Quad_SwapB_EachMini_2x2_D();
    void                                        Quad_SwapC_2x2_D();
    void                                        Quad_SwapC_EachMini_2x2_D();
    void                                        Quad_SwapD_2x2_D();
    void                                        Quad_SwapD_EachMini_2x2_D();

    void                                        Quad_ShearA_4x4_D();
    void                                        Quad_ShearB_4x4_D();
    void                                        Quad_ShearC_4x4_D();
    void                                        Quad_ShearD_4x4_D();
    
    void                                        Quad_FoldA_4x4_D();
    void                                        Quad_FoldB_4x4_D();
    void                                        Quad_FoldD_4x4_D();
    
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
    
    
    
    
    void                                        Mini_SwapA_2x2_A();
    void                                        Mini_SwapA_2x2_B();
    void                                        Mini_SwapA_2x2_C();
    void                                        Mini_SwapA_2x2_D();
    void                                        Mini_SwapA_2x2_E();
    void                                        Mini_SwapA_2x2_F();
    void                                        Mini_SwapA_2x2_G();
    void                                        Mini_SwapA_2x2_H();
    void                                        Mini_SwapA_2x2_I();
    void                                        Mini_SwapA_2x2_J();
    void                                        Mini_SwapA_2x2_K();
    void                                        Mini_SwapA_2x2_L();
    void                                        Mini_SwapA_2x2_M();
    void                                        Mini_SwapA_2x2_N();
    void                                        Mini_SwapA_2x2_O();
    void                                        Mini_SwapA_2x2_P();
    
    
    
    void                                        Mini_SwapB_2x2_A();
    void                                        Mini_SwapB_2x2_B();
    void                                        Mini_SwapB_2x2_C();
    void                                        Mini_SwapB_2x2_D();
    void                                        Mini_SwapB_2x2_E();
    void                                        Mini_SwapB_2x2_F();
    void                                        Mini_SwapB_2x2_G();
    void                                        Mini_SwapB_2x2_H();
    void                                        Mini_SwapB_2x2_I();
    void                                        Mini_SwapB_2x2_J();
    void                                        Mini_SwapB_2x2_K();
    void                                        Mini_SwapB_2x2_L();
    void                                        Mini_SwapB_2x2_M();
    void                                        Mini_SwapB_2x2_N();
    void                                        Mini_SwapB_2x2_O();
    void                                        Mini_SwapB_2x2_P();
    
    
    void                                        Mini_SwapC_2x2_A();
    void                                        Mini_SwapC_2x2_B();
    void                                        Mini_SwapC_2x2_C();
    void                                        Mini_SwapC_2x2_D();
    void                                        Mini_SwapC_2x2_E();
    void                                        Mini_SwapC_2x2_F();
    void                                        Mini_SwapC_2x2_G();
    void                                        Mini_SwapC_2x2_H();
    void                                        Mini_SwapC_2x2_I();
    void                                        Mini_SwapC_2x2_J();
    void                                        Mini_SwapC_2x2_K();
    void                                        Mini_SwapC_2x2_L();
    void                                        Mini_SwapC_2x2_M();
    void                                        Mini_SwapC_2x2_N();
    void                                        Mini_SwapC_2x2_O();
    void                                        Mini_SwapC_2x2_P();
    
    
    void                                        Mini_SwapD_2x2_A();
    void                                        Mini_SwapD_2x2_B();
    void                                        Mini_SwapD_2x2_C();
    void                                        Mini_SwapD_2x2_D();
    void                                        Mini_SwapD_2x2_E();
    void                                        Mini_SwapD_2x2_F();
    void                                        Mini_SwapD_2x2_G();
    void                                        Mini_SwapD_2x2_H();
    void                                        Mini_SwapD_2x2_I();
    void                                        Mini_SwapD_2x2_J();
    void                                        Mini_SwapD_2x2_K();
    void                                        Mini_SwapD_2x2_L();
    void                                        Mini_SwapD_2x2_M();
    void                                        Mini_SwapD_2x2_N();
    void                                        Mini_SwapD_2x2_O();
    void                                        Mini_SwapD_2x2_P();
    

    void                                        Full_JewelA_8x8();
    void                                        Full_JewelA_4x4();
    void                                        Full_JewelA_EachQuad_4x4();
    void                                        Quad_JewelA_4x4_A();
    void                                        Quad_JewelA_4x4_B();
    void                                        Quad_JewelA_4x4_C();
    void                                        Quad_JewelA_4x4_D();


    void                                        Full_JewelB_8x8();
    void                                        Full_JewelB_4x4();
    void                                        Full_JewelB_EachQuad_4x4();
    void                                        Quad_JewelB_4x4_A();
    void                                        Quad_JewelB_4x4_B();
    void                                        Quad_JewelB_4x4_C();
    void                                        Quad_JewelB_4x4_D();


    void                                        Full_JewelC_8x8();
    void                                        Full_JewelC_4x4();
    void                                        Full_JewelC_EachQuad_4x4();
    void                                        Quad_JewelC_4x4_A();
    void                                        Quad_JewelC_4x4_B();
    void                                        Quad_JewelC_4x4_C();
    void                                        Quad_JewelC_4x4_D();


    void                                        Full_JewelD_8x8();
    void                                        Full_JewelD_4x4();
    void                                        Full_JewelD_EachQuad_4x4();
    void                                        Quad_JewelD_4x4_A();
    void                                        Quad_JewelD_4x4_B();
    void                                        Quad_JewelD_4x4_C();
    void                                        Quad_JewelD_4x4_D();
    
    void                                        Full_CrystalA_8x8();
    void                                        Full_CrystalA_4x4();
    void                                        Full_CrystalA_EachQuad_4x4();
    void                                        Quad_CrystalA_4x4_A();
    void                                        Quad_CrystalA_4x4_B();
    void                                        Quad_CrystalA_4x4_C();
    void                                        Quad_CrystalA_4x4_D();
    
    
    
    void                                        Full_CrystalC_8x8();
    void                                        Full_CrystalC_4x4();
    void                                        Full_CrystalC_EachQuad_4x4();
    void                                        Quad_CrystalC_4x4_A();
    void                                        Quad_CrystalC_4x4_B();
    void                                        Quad_CrystalC_4x4_C();
    void                                        Quad_CrystalC_4x4_D();
    
    
    
    void                                        Full_CrystalB_8x8();
    void                                        Full_CrystalB_4x4();
    void                                        Full_CrystalB_EachQuad_4x4();
    void                                        Quad_CrystalB_4x4_A();
    void                                        Quad_CrystalB_4x4_B();
    void                                        Quad_CrystalB_4x4_C();
    void                                        Quad_CrystalB_4x4_D();
    
    
    void                                        Full_CrystalD_8x8();
    void                                        Full_CrystalD_4x4();
    void                                        Full_CrystalD_EachQuad_4x4();
    void                                        Quad_CrystalD_4x4_A();
    void                                        Quad_CrystalD_4x4_B();
    void                                        Quad_CrystalD_4x4_C();
    void                                        Quad_CrystalD_4x4_D();
    
    
    
    
    void                                        Full_OpalA_8x8();
    void                                        Full_OpalA_4x4();
    void                                        Full_OpalA_EachQuad_4x4();
    void                                        Quad_OpalA_4x4_A();
    void                                        Quad_OpalA_4x4_B();
    void                                        Quad_OpalA_4x4_C();
    void                                        Quad_OpalA_4x4_D();
    

    
    void                                        Full_OpalC_8x8();
    void                                        Full_OpalC_4x4();
    void                                        Full_OpalC_EachQuad_4x4();
    void                                        Quad_OpalC_4x4_A();
    void                                        Quad_OpalC_4x4_B();
    void                                        Quad_OpalC_4x4_C();
    void                                        Quad_OpalC_4x4_D();
    
    
    void                                        Full_OpalB_8x8();
    void                                        Full_OpalB_4x4();
    void                                        Full_OpalB_EachQuad_4x4();
    void                                        Quad_OpalB_4x4_A();
    void                                        Quad_OpalB_4x4_B();
    void                                        Quad_OpalB_4x4_C();
    void                                        Quad_OpalB_4x4_D();
    
    
    void                                        Full_OpalD_8x8();
    void                                        Full_OpalD_4x4();
    void                                        Full_OpalD_EachQuad_4x4();
    void                                        Quad_OpalD_4x4_A();
    void                                        Quad_OpalD_4x4_B();
    void                                        Quad_OpalD_4x4_C();
    void                                        Quad_OpalD_4x4_D();
    
    
    
    
    
    void                                        Full_PeridotA_8x8();
    void                                        Full_PeridotA_4x4();
    void                                        Full_PeridotA_EachQuad_4x4();
    void                                        Quad_PeridotA_4x4_A();
    void                                        Quad_PeridotA_4x4_B();
    void                                        Quad_PeridotA_4x4_C();
    void                                        Quad_PeridotA_4x4_D();
    
    
    void                                        Full_PeridotB_8x8();
    void                                        Full_PeridotB_4x4();
    void                                        Full_PeridotB_EachQuad_4x4();
    void                                        Quad_PeridotB_4x4_A();
    void                                        Quad_PeridotB_4x4_B();
    void                                        Quad_PeridotB_4x4_C();
    void                                        Quad_PeridotB_4x4_D();
    
    
    void                                        Full_PeridotC_8x8();
    void                                        Full_PeridotC_4x4();
    void                                        Full_PeridotC_EachQuad_4x4();
    void                                        Quad_PeridotC_4x4_A();
    void                                        Quad_PeridotC_4x4_B();
    void                                        Quad_PeridotC_4x4_C();
    void                                        Quad_PeridotC_4x4_D();
    
    
    void                                        Full_PeridotD_8x8();
    void                                        Full_PeridotD_4x4();
    void                                        Full_PeridotD_EachQuad_4x4();
    void                                        Quad_PeridotD_4x4_A();
    void                                        Quad_PeridotD_4x4_B();
    void                                        Quad_PeridotD_4x4_C();
    void                                        Quad_PeridotD_4x4_D();
    
    
    
    
    void                                        Full_SwanA_4x4();
    void                                        Full_SwanA_EachQuad_4x4();
    void                                        Quad_SwanA_4x4_A();
    void                                        Quad_SwanA_4x4_B();
    void                                        Quad_SwanA_4x4_C();
    void                                        Quad_SwanA_4x4_D();
    void                                        Full_SwanB_4x4();
    void                                        Full_SwanB_EachQuad_4x4();
    void                                        Quad_SwanB_4x4_A();
    void                                        Quad_SwanB_4x4_B();
    void                                        Quad_SwanB_4x4_C();
    void                                        Quad_SwanB_4x4_D();
    void                                        Full_SwanC_4x4();
    void                                        Full_SwanC_EachQuad_4x4();
    void                                        Quad_SwanC_4x4_A();
    void                                        Quad_SwanC_4x4_B();
    void                                        Quad_SwanC_4x4_C();
    void                                        Quad_SwanC_4x4_D();
    void                                        Full_SwanD_4x4();
    void                                        Full_SwanD_EachQuad_4x4();
    void                                        Quad_SwanD_4x4_A();
    void                                        Quad_SwanD_4x4_B();
    void                                        Quad_SwanD_4x4_C();
    void                                        Quad_SwanD_4x4_D();
    void                                        Full_GooseA_4x4();
    void                                        Full_GooseA_EachQuad_4x4();
    void                                        Quad_GooseA_4x4_A();
    void                                        Quad_GooseA_4x4_B();
    void                                        Quad_GooseA_4x4_C();
    void                                        Quad_GooseA_4x4_D();
    void                                        Full_GooseB_4x4();
    void                                        Full_GooseB_EachQuad_4x4();
    void                                        Quad_GooseB_4x4_A();
    void                                        Quad_GooseB_4x4_B();
    void                                        Quad_GooseB_4x4_C();
    void                                        Quad_GooseB_4x4_D();
    void                                        Full_GooseC_4x4();
    void                                        Full_GooseC_EachQuad_4x4();
    void                                        Quad_GooseC_4x4_A();
    void                                        Quad_GooseC_4x4_B();
    void                                        Quad_GooseC_4x4_C();
    void                                        Quad_GooseC_4x4_D();
    void                                        Full_GooseD_4x4();
    void                                        Full_GooseD_EachQuad_4x4();
    void                                        Quad_GooseD_4x4_A();
    void                                        Quad_GooseD_4x4_B();
    void                                        Quad_GooseD_4x4_C();
    void                                        Quad_GooseD_4x4_D();

// ============================================================
// 8x8 HPP
// ============================================================

    void                                        Full_SwanA_8x8();
    void                                        Full_SwanB_8x8();
    void                                        Full_SwanC_8x8();
    void                                        Full_SwanD_8x8();
    void                                        Full_GooseA_8x8();
    void                                        Full_GooseB_8x8();
    void                                        Full_GooseC_8x8();
    void                                        Full_GooseD_8x8();
    
    
    
    
    void                                        Full_HeronA_4x4();
    void                                        Full_HeronA_EachQuad_4x4();
    void                                        Quad_HeronA_4x4_A();
    void                                        Quad_HeronA_4x4_B();
    void                                        Quad_HeronA_4x4_C();
    void                                        Quad_HeronA_4x4_D();
    void                                        Full_HeronB_4x4();
    void                                        Full_HeronB_EachQuad_4x4();
    void                                        Quad_HeronB_4x4_A();
    void                                        Quad_HeronB_4x4_B();
    void                                        Quad_HeronB_4x4_C();
    void                                        Quad_HeronB_4x4_D();
    void                                        Full_HeronC_4x4();
    void                                        Full_HeronC_EachQuad_4x4();
    void                                        Quad_HeronC_4x4_A();
    void                                        Quad_HeronC_4x4_B();
    void                                        Quad_HeronC_4x4_C();
    void                                        Quad_HeronC_4x4_D();
    void                                        Full_HeronD_4x4();
    void                                        Full_HeronD_EachQuad_4x4();
    void                                        Quad_HeronD_4x4_A();
    void                                        Quad_HeronD_4x4_B();
    void                                        Quad_HeronD_4x4_C();
    void                                        Quad_HeronD_4x4_D();
    void                                        Full_FalconA_4x4();
    void                                        Full_FalconA_EachQuad_4x4();
    void                                        Quad_FalconA_4x4_A();
    void                                        Quad_FalconA_4x4_B();
    void                                        Quad_FalconA_4x4_C();
    void                                        Quad_FalconA_4x4_D();
    void                                        Full_FalconB_4x4();
    void                                        Full_FalconB_EachQuad_4x4();
    void                                        Quad_FalconB_4x4_A();
    void                                        Quad_FalconB_4x4_B();
    void                                        Quad_FalconB_4x4_C();
    void                                        Quad_FalconB_4x4_D();
    void                                        Full_FalconC_4x4();
    void                                        Full_FalconC_EachQuad_4x4();
    void                                        Quad_FalconC_4x4_A();
    void                                        Quad_FalconC_4x4_B();
    void                                        Quad_FalconC_4x4_C();
    void                                        Quad_FalconC_4x4_D();
    void                                        Full_FalconD_4x4();
    void                                        Full_FalconD_EachQuad_4x4();
    void                                        Quad_FalconD_4x4_A();
    void                                        Quad_FalconD_4x4_B();
    void                                        Quad_FalconD_4x4_C();
    void                                        Quad_FalconD_4x4_D();

// ============================================================
// 8x8 HPP
// ============================================================

    void                                        Full_HeronA_8x8();
    void                                        Full_HeronB_8x8();
    void                                        Full_HeronC_8x8();
    void                                        Full_HeronD_8x8();
    void                                        Full_FalconA_8x8();
    void                                        Full_FalconB_8x8();
    void                                        Full_FalconC_8x8();
    void                                        Full_FalconD_8x8();
    
    
    void                                        Full_IronA_4x4();
    void                                        Full_IronA_EachQuad_4x4();
    void                                        Quad_IronA_4x4_A();
    void                                        Quad_IronA_4x4_B();
    void                                        Quad_IronA_4x4_C();
    void                                        Quad_IronA_4x4_D();
    void                                        Full_IronB_4x4();
    void                                        Full_IronB_EachQuad_4x4();
    void                                        Quad_IronB_4x4_A();
    void                                        Quad_IronB_4x4_B();
    void                                        Quad_IronB_4x4_C();
    void                                        Quad_IronB_4x4_D();
    void                                        Full_IronC_4x4();
    void                                        Full_IronC_EachQuad_4x4();
    void                                        Quad_IronC_4x4_A();
    void                                        Quad_IronC_4x4_B();
    void                                        Quad_IronC_4x4_C();
    void                                        Quad_IronC_4x4_D();
    void                                        Full_IronD_4x4();
    void                                        Full_IronD_EachQuad_4x4();
    void                                        Quad_IronD_4x4_A();
    void                                        Quad_IronD_4x4_B();
    void                                        Quad_IronD_4x4_C();
    void                                        Quad_IronD_4x4_D();
    void                                        Full_SteelA_4x4();
    void                                        Full_SteelA_EachQuad_4x4();
    void                                        Quad_SteelA_4x4_A();
    void                                        Quad_SteelA_4x4_B();
    void                                        Quad_SteelA_4x4_C();
    void                                        Quad_SteelA_4x4_D();
    void                                        Full_SteelB_4x4();
    void                                        Full_SteelB_EachQuad_4x4();
    void                                        Quad_SteelB_4x4_A();
    void                                        Quad_SteelB_4x4_B();
    void                                        Quad_SteelB_4x4_C();
    void                                        Quad_SteelB_4x4_D();
    void                                        Full_SteelC_4x4();
    void                                        Full_SteelC_EachQuad_4x4();
    void                                        Quad_SteelC_4x4_A();
    void                                        Quad_SteelC_4x4_B();
    void                                        Quad_SteelC_4x4_C();
    void                                        Quad_SteelC_4x4_D();
    void                                        Full_SteelD_4x4();
    void                                        Full_SteelD_EachQuad_4x4();
    void                                        Quad_SteelD_4x4_A();
    void                                        Quad_SteelD_4x4_B();
    void                                        Quad_SteelD_4x4_C();
    void                                        Quad_SteelD_4x4_D();
    void                                        Full_SilverA_4x4();
    void                                        Full_SilverA_EachQuad_4x4();
    void                                        Quad_SilverA_4x4_A();
    void                                        Quad_SilverA_4x4_B();
    void                                        Quad_SilverA_4x4_C();
    void                                        Quad_SilverA_4x4_D();
    void                                        Full_SilverB_4x4();
    void                                        Full_SilverB_EachQuad_4x4();
    void                                        Quad_SilverB_4x4_A();
    void                                        Quad_SilverB_4x4_B();
    void                                        Quad_SilverB_4x4_C();
    void                                        Quad_SilverB_4x4_D();
    void                                        Full_SilverC_4x4();
    void                                        Full_SilverC_EachQuad_4x4();
    void                                        Quad_SilverC_4x4_A();
    void                                        Quad_SilverC_4x4_B();
    void                                        Quad_SilverC_4x4_C();
    void                                        Quad_SilverC_4x4_D();
    void                                        Full_SilverD_4x4();
    void                                        Full_SilverD_EachQuad_4x4();
    void                                        Quad_SilverD_4x4_A();
    void                                        Quad_SilverD_4x4_B();
    void                                        Quad_SilverD_4x4_C();
    void                                        Quad_SilverD_4x4_D();
    void                                        Full_GoldA_4x4();
    void                                        Full_GoldA_EachQuad_4x4();
    void                                        Quad_GoldA_4x4_A();
    void                                        Quad_GoldA_4x4_B();
    void                                        Quad_GoldA_4x4_C();
    void                                        Quad_GoldA_4x4_D();
    void                                        Full_GoldB_4x4();
    void                                        Full_GoldB_EachQuad_4x4();
    void                                        Quad_GoldB_4x4_A();
    void                                        Quad_GoldB_4x4_B();
    void                                        Quad_GoldB_4x4_C();
    void                                        Quad_GoldB_4x4_D();
    void                                        Full_GoldC_4x4();
    void                                        Full_GoldC_EachQuad_4x4();
    void                                        Quad_GoldC_4x4_A();
    void                                        Quad_GoldC_4x4_B();
    void                                        Quad_GoldC_4x4_C();
    void                                        Quad_GoldC_4x4_D();
    void                                        Full_GoldD_4x4();
    void                                        Full_GoldD_EachQuad_4x4();
    void                                        Quad_GoldD_4x4_A();
    void                                        Quad_GoldD_4x4_B();
    void                                        Quad_GoldD_4x4_C();
    void                                        Quad_GoldD_4x4_D();
    void                                        Full_BronzeA_4x4();
    void                                        Full_BronzeA_EachQuad_4x4();
    void                                        Quad_BronzeA_4x4_A();
    void                                        Quad_BronzeA_4x4_B();
    void                                        Quad_BronzeA_4x4_C();
    void                                        Quad_BronzeA_4x4_D();
    void                                        Full_BronzeB_4x4();
    void                                        Full_BronzeB_EachQuad_4x4();
    void                                        Quad_BronzeB_4x4_A();
    void                                        Quad_BronzeB_4x4_B();
    void                                        Quad_BronzeB_4x4_C();
    void                                        Quad_BronzeB_4x4_D();
    void                                        Full_BronzeC_4x4();
    void                                        Full_BronzeC_EachQuad_4x4();
    void                                        Quad_BronzeC_4x4_A();
    void                                        Quad_BronzeC_4x4_B();
    void                                        Quad_BronzeC_4x4_C();
    void                                        Quad_BronzeC_4x4_D();
    void                                        Full_BronzeD_4x4();
    void                                        Full_BronzeD_EachQuad_4x4();
    void                                        Quad_BronzeD_4x4_A();
    void                                        Quad_BronzeD_4x4_B();
    void                                        Quad_BronzeD_4x4_C();
    void                                        Quad_BronzeD_4x4_D();
    void                                        Full_BrassA_4x4();
    void                                        Full_BrassA_EachQuad_4x4();
    void                                        Quad_BrassA_4x4_A();
    void                                        Quad_BrassA_4x4_B();
    void                                        Quad_BrassA_4x4_C();
    void                                        Quad_BrassA_4x4_D();
    void                                        Full_BrassB_4x4();
    void                                        Full_BrassB_EachQuad_4x4();
    void                                        Quad_BrassB_4x4_A();
    void                                        Quad_BrassB_4x4_B();
    void                                        Quad_BrassB_4x4_C();
    void                                        Quad_BrassB_4x4_D();
    void                                        Full_BrassC_4x4();
    void                                        Full_BrassC_EachQuad_4x4();
    void                                        Quad_BrassC_4x4_A();
    void                                        Quad_BrassC_4x4_B();
    void                                        Quad_BrassC_4x4_C();
    void                                        Quad_BrassC_4x4_D();
    void                                        Full_BrassD_4x4();
    void                                        Full_BrassD_EachQuad_4x4();
    void                                        Quad_BrassD_4x4_A();
    void                                        Quad_BrassD_4x4_B();
    void                                        Quad_BrassD_4x4_C();
    void                                        Quad_BrassD_4x4_D();
    void                                        Full_NickelA_4x4();
    void                                        Full_NickelA_EachQuad_4x4();
    void                                        Quad_NickelA_4x4_A();
    void                                        Quad_NickelA_4x4_B();
    void                                        Quad_NickelA_4x4_C();
    void                                        Quad_NickelA_4x4_D();
    void                                        Full_NickelB_4x4();
    void                                        Full_NickelB_EachQuad_4x4();
    void                                        Quad_NickelB_4x4_A();
    void                                        Quad_NickelB_4x4_B();
    void                                        Quad_NickelB_4x4_C();
    void                                        Quad_NickelB_4x4_D();
    void                                        Full_NickelC_4x4();
    void                                        Full_NickelC_EachQuad_4x4();
    void                                        Quad_NickelC_4x4_A();
    void                                        Quad_NickelC_4x4_B();
    void                                        Quad_NickelC_4x4_C();
    void                                        Quad_NickelC_4x4_D();
    void                                        Full_NickelD_4x4();
    void                                        Full_NickelD_EachQuad_4x4();
    void                                        Quad_NickelD_4x4_A();
    void                                        Quad_NickelD_4x4_B();
    void                                        Quad_NickelD_4x4_C();
    void                                        Quad_NickelD_4x4_D();
    void                                        Full_CobaltA_4x4();
    void                                        Full_CobaltA_EachQuad_4x4();
    void                                        Quad_CobaltA_4x4_A();
    void                                        Quad_CobaltA_4x4_B();
    void                                        Quad_CobaltA_4x4_C();
    void                                        Quad_CobaltA_4x4_D();
    void                                        Full_CobaltB_4x4();
    void                                        Full_CobaltB_EachQuad_4x4();
    void                                        Quad_CobaltB_4x4_A();
    void                                        Quad_CobaltB_4x4_B();
    void                                        Quad_CobaltB_4x4_C();
    void                                        Quad_CobaltB_4x4_D();
    void                                        Full_CobaltC_4x4();
    void                                        Full_CobaltC_EachQuad_4x4();
    void                                        Quad_CobaltC_4x4_A();
    void                                        Quad_CobaltC_4x4_B();
    void                                        Quad_CobaltC_4x4_C();
    void                                        Quad_CobaltC_4x4_D();
    void                                        Full_CobaltD_4x4();
    void                                        Full_CobaltD_EachQuad_4x4();
    void                                        Quad_CobaltD_4x4_A();
    void                                        Quad_CobaltD_4x4_B();
    void                                        Quad_CobaltD_4x4_C();
    void                                        Quad_CobaltD_4x4_D();
    

    
    
    void                                        Full_PlatinumA_4x4();
    void                                        Full_PlatinumA_EachQuad_4x4();
    void                                        Quad_PlatinumA_4x4_A();
    void                                        Quad_PlatinumA_4x4_B();
    void                                        Quad_PlatinumA_4x4_C();
    void                                        Quad_PlatinumA_4x4_D();
    void                                        Full_PlatinumB_4x4();
    void                                        Full_PlatinumB_EachQuad_4x4();
    void                                        Quad_PlatinumB_4x4_A();
    void                                        Quad_PlatinumB_4x4_B();
    void                                        Quad_PlatinumB_4x4_C();
    void                                        Quad_PlatinumB_4x4_D();
    void                                        Full_PlatinumC_4x4();
    void                                        Full_PlatinumC_EachQuad_4x4();
    void                                        Quad_PlatinumC_4x4_A();
    void                                        Quad_PlatinumC_4x4_B();
    void                                        Quad_PlatinumC_4x4_C();
    void                                        Quad_PlatinumC_4x4_D();
    void                                        Full_PlatinumD_4x4();
    void                                        Full_PlatinumD_EachQuad_4x4();
    void                                        Quad_PlatinumD_4x4_A();
    void                                        Quad_PlatinumD_4x4_B();
    void                                        Quad_PlatinumD_4x4_C();
    void                                        Quad_PlatinumD_4x4_D();


    
    void                                        Full_PalladiumA_4x4();
    void                                        Full_PalladiumA_EachQuad_4x4();
    void                                        Quad_PalladiumA_4x4_A();
    void                                        Quad_PalladiumA_4x4_B();
    void                                        Quad_PalladiumA_4x4_C();
    void                                        Quad_PalladiumA_4x4_D();
    void                                        Full_PalladiumB_4x4();
    void                                        Full_PalladiumB_EachQuad_4x4();
    void                                        Quad_PalladiumB_4x4_A();
    void                                        Quad_PalladiumB_4x4_B();
    void                                        Quad_PalladiumB_4x4_C();
    void                                        Quad_PalladiumB_4x4_D();
    void                                        Full_PalladiumC_4x4();
    void                                        Full_PalladiumC_EachQuad_4x4();
    void                                        Quad_PalladiumC_4x4_A();
    void                                        Quad_PalladiumC_4x4_B();
    void                                        Quad_PalladiumC_4x4_C();
    void                                        Quad_PalladiumC_4x4_D();
    void                                        Full_PalladiumD_4x4();
    void                                        Full_PalladiumD_EachQuad_4x4();
    void                                        Quad_PalladiumD_4x4_A();
    void                                        Quad_PalladiumD_4x4_B();
    void                                        Quad_PalladiumD_4x4_C();
    void                                        Quad_PalladiumD_4x4_D();
    

    
    void                                        Full_ChromiumA_4x4();
    void                                        Full_ChromiumA_EachQuad_4x4();
    void                                        Quad_ChromiumA_4x4_A();
    void                                        Quad_ChromiumA_4x4_B();
    void                                        Quad_ChromiumA_4x4_C();
    void                                        Quad_ChromiumA_4x4_D();
    void                                        Full_ChromiumB_4x4();
    void                                        Full_ChromiumB_EachQuad_4x4();
    void                                        Quad_ChromiumB_4x4_A();
    void                                        Quad_ChromiumB_4x4_B();
    void                                        Quad_ChromiumB_4x4_C();
    void                                        Quad_ChromiumB_4x4_D();
    void                                        Full_ChromiumC_4x4();
    void                                        Full_ChromiumC_EachQuad_4x4();
    void                                        Quad_ChromiumC_4x4_A();
    void                                        Quad_ChromiumC_4x4_B();
    void                                        Quad_ChromiumC_4x4_C();
    void                                        Quad_ChromiumC_4x4_D();
    void                                        Full_ChromiumD_4x4();
    void                                        Full_ChromiumD_EachQuad_4x4();
    void                                        Quad_ChromiumD_4x4_A();
    void                                        Quad_ChromiumD_4x4_B();
    void                                        Quad_ChromiumD_4x4_C();
    void                                        Quad_ChromiumD_4x4_D();
    void                                        Full_ZirconiumA_4x4();
    void                                        Full_ZirconiumA_EachQuad_4x4();
    void                                        Quad_ZirconiumA_4x4_A();
    void                                        Quad_ZirconiumA_4x4_B();
    void                                        Quad_ZirconiumA_4x4_C();
    void                                        Quad_ZirconiumA_4x4_D();
    void                                        Full_ZirconiumB_4x4();
    void                                        Full_ZirconiumB_EachQuad_4x4();
    void                                        Quad_ZirconiumB_4x4_A();
    void                                        Quad_ZirconiumB_4x4_B();
    void                                        Quad_ZirconiumB_4x4_C();
    void                                        Quad_ZirconiumB_4x4_D();
    void                                        Full_ZirconiumC_4x4();
    void                                        Full_ZirconiumC_EachQuad_4x4();
    void                                        Quad_ZirconiumC_4x4_A();
    void                                        Quad_ZirconiumC_4x4_B();
    void                                        Quad_ZirconiumC_4x4_C();
    void                                        Quad_ZirconiumC_4x4_D();
    void                                        Full_ZirconiumD_4x4();
    void                                        Full_ZirconiumD_EachQuad_4x4();
    void                                        Quad_ZirconiumD_4x4_A();
    void                                        Quad_ZirconiumD_4x4_B();
    void                                        Quad_ZirconiumD_4x4_C();
    void                                        Quad_ZirconiumD_4x4_D();
    
    
    void                                        Full_IronA_8x8();
    void                                        Full_IronB_8x8();
    void                                        Full_IronC_8x8();
    void                                        Full_IronD_8x8();
    void                                        Full_SteelA_8x8();
    void                                        Full_SteelB_8x8();
    void                                        Full_SteelC_8x8();
    void                                        Full_SteelD_8x8();
    void                                        Full_SilverA_8x8();
    void                                        Full_SilverB_8x8();
    void                                        Full_SilverC_8x8();
    void                                        Full_SilverD_8x8();
    void                                        Full_GoldA_8x8();
    void                                        Full_GoldB_8x8();
    void                                        Full_GoldC_8x8();
    void                                        Full_GoldD_8x8();
    void                                        Full_BronzeA_8x8();
    void                                        Full_BronzeB_8x8();
    void                                        Full_BronzeC_8x8();
    void                                        Full_BronzeD_8x8();
    void                                        Full_BrassA_8x8();
    void                                        Full_BrassB_8x8();
    void                                        Full_BrassC_8x8();
    void                                        Full_BrassD_8x8();
    void                                        Full_NickelA_8x8();
    void                                        Full_NickelB_8x8();
    void                                        Full_NickelC_8x8();
    void                                        Full_NickelD_8x8();
    void                                        Full_CobaltA_8x8();
    void                                        Full_CobaltB_8x8();
    void                                        Full_CobaltC_8x8();
    void                                        Full_CobaltD_8x8();
    
    void                                        Full_PlatinumA_8x8();
    void                                        Full_PlatinumB_8x8();
    void                                        Full_PlatinumC_8x8();
    void                                        Full_PlatinumD_8x8();
    
    
    void                                        Full_PalladiumA_8x8();
    void                                        Full_PalladiumB_8x8();
    void                                        Full_PalladiumC_8x8();
    void                                        Full_PalladiumD_8x8();
    
    void                                        Full_ChromiumA_8x8();
    void                                        Full_ChromiumB_8x8();
    void                                        Full_ChromiumC_8x8();
    void                                        Full_ChromiumD_8x8();
    void                                        Full_ZirconiumA_8x8();
    void                                        Full_ZirconiumB_8x8();
    void                                        Full_ZirconiumC_8x8();
    void                                        Full_ZirconiumD_8x8();
    
};

#endif /* M88_hpp */

//
//  Test_NoDuplicateTransforms.m
//  UnitTests
//
//  Created by Wu Tang on 6/3/26.
//

#import <XCTest/XCTest.h>

#include <array>
#include <map>
#include <string>
#include <vector>
#include <cstring>

#include "M88.hpp"
#include "VerifyFull.hpp"
#include "Logging.hpp"

@interface Test_NoDuplicateTransforms : XCTestCase
@end

@implementation Test_NoDuplicateTransforms

using TransformFn = void (M88::*)();

struct TransformEntry {
    const char *mName;
    TransformFn mFunction;
};

static std::array<std::uint8_t, 64> CaptureData(const M88 &pMatrix) {
    std::array<std::uint8_t, 64> aResult;
    std::memcpy(aResult.data(), pMatrix.mData, 64);
    return aResult;
}

static std::string MatrixKey(const std::array<std::uint8_t, 64> &pData) {
    std::string aResult;
    aResult.reserve(64 * 3);

    for (std::size_t i = 0; i < pData.size(); i++) {
        aResult += std::to_string(static_cast<int>(pData[i]));
        aResult += ",";
    }

    return aResult;
}

static std::vector<TransformEntry> BuildTransformList() {
    return {
        { "Full_RotA_2x2", &M88::Full_RotA_2x2 },
        { "Full_RotA_4x4", &M88::Full_RotA_4x4 },
        { "Full_RotA_8x8", &M88::Full_RotA_8x8 },
        { "Full_RotA_EachMini_2x2", &M88::Full_RotA_EachMini_2x2 },
        { "Full_RotA_EachQuad_2x2", &M88::Full_RotA_EachQuad_2x2 },
        { "Full_RotA_EachQuad_4x4", &M88::Full_RotA_EachQuad_4x4 },

        { "Full_RotB_2x2", &M88::Full_RotB_2x2 },
        { "Full_RotB_4x4", &M88::Full_RotB_4x4 },
        { "Full_RotB_8x8", &M88::Full_RotB_8x8 },
        { "Full_RotB_EachMini_2x2", &M88::Full_RotB_EachMini_2x2 },
        { "Full_RotB_EachQuad_2x2", &M88::Full_RotB_EachQuad_2x2 },
        { "Full_RotB_EachQuad_4x4", &M88::Full_RotB_EachQuad_4x4 },

        { "Full_RotC_2x2", &M88::Full_RotC_2x2 },
        { "Full_RotC_4x4", &M88::Full_RotC_4x4 },
        { "Full_RotC_8x8", &M88::Full_RotC_8x8 },
        { "Full_RotC_EachMini_2x2", &M88::Full_RotC_EachMini_2x2 },
        { "Full_RotC_EachQuad_2x2", &M88::Full_RotC_EachQuad_2x2 },
        { "Full_RotC_EachQuad_4x4", &M88::Full_RotC_EachQuad_4x4 },

        { "Full_FlipA_2x2", &M88::Full_FlipA_2x2 },
        { "Full_FlipA_4x4", &M88::Full_FlipA_4x4 },
        { "Full_FlipA_8x8", &M88::Full_FlipA_8x8 },
        { "Full_FlipA_EachMini_2x2", &M88::Full_FlipA_EachMini_2x2 },
        { "Full_FlipA_EachQuad_2x2", &M88::Full_FlipA_EachQuad_2x2 },
        { "Full_FlipA_EachQuad_4x4", &M88::Full_FlipA_EachQuad_4x4 },

        { "Full_FlipB_2x2", &M88::Full_FlipB_2x2 },
        { "Full_FlipB_4x4", &M88::Full_FlipB_4x4 },
        { "Full_FlipB_8x8", &M88::Full_FlipB_8x8 },
        { "Full_FlipB_EachMini_2x2", &M88::Full_FlipB_EachMini_2x2 },
        { "Full_FlipB_EachQuad_2x2", &M88::Full_FlipB_EachQuad_2x2 },
        { "Full_FlipB_EachQuad_4x4", &M88::Full_FlipB_EachQuad_4x4 },

        { "Full_FlipC_2x2", &M88::Full_FlipC_2x2 },
        { "Full_FlipC_4x4", &M88::Full_FlipC_4x4 },
        { "Full_FlipC_8x8", &M88::Full_FlipC_8x8 },
        { "Full_FlipC_EachMini_2x2", &M88::Full_FlipC_EachMini_2x2 },
        { "Full_FlipC_EachQuad_2x2", &M88::Full_FlipC_EachQuad_2x2 },
        { "Full_FlipC_EachQuad_4x4", &M88::Full_FlipC_EachQuad_4x4 },

        { "Full_FlipD_2x2", &M88::Full_FlipD_2x2 },
        { "Full_FlipD_4x4", &M88::Full_FlipD_4x4 },
        { "Full_FlipD_8x8", &M88::Full_FlipD_8x8 },
        { "Full_FlipD_EachMini_2x2", &M88::Full_FlipD_EachMini_2x2 },
        { "Full_FlipD_EachQuad_2x2", &M88::Full_FlipD_EachQuad_2x2 },
        { "Full_FlipD_EachQuad_4x4", &M88::Full_FlipD_EachQuad_4x4 },

        { "Full_TriadA_2x2", &M88::Full_TriadA_2x2 },
        { "Full_TriadA_EachMini_2x2", &M88::Full_TriadA_EachMini_2x2 },
        { "Full_TriadA_EachQuad_2x2", &M88::Full_TriadA_EachQuad_2x2 },

        { "Full_TriadB_2x2", &M88::Full_TriadB_2x2 },
        { "Full_TriadB_EachMini_2x2", &M88::Full_TriadB_EachMini_2x2 },
        { "Full_TriadB_EachQuad_2x2", &M88::Full_TriadB_EachQuad_2x2 },

        { "Full_TriadC_2x2", &M88::Full_TriadC_2x2 },
        { "Full_TriadC_EachMini_2x2", &M88::Full_TriadC_EachMini_2x2 },
        { "Full_TriadC_EachQuad_2x2", &M88::Full_TriadC_EachQuad_2x2 },

        { "Full_TriadD_2x2", &M88::Full_TriadD_2x2 },
        { "Full_TriadD_EachMini_2x2", &M88::Full_TriadD_EachMini_2x2 },
        { "Full_TriadD_EachQuad_2x2", &M88::Full_TriadD_EachQuad_2x2 },

        { "Full_TriadE_2x2", &M88::Full_TriadE_2x2 },
        { "Full_TriadE_EachMini_2x2", &M88::Full_TriadE_EachMini_2x2 },
        { "Full_TriadE_EachQuad_2x2", &M88::Full_TriadE_EachQuad_2x2 },

        { "Full_TriadF_2x2", &M88::Full_TriadF_2x2 },
        { "Full_TriadF_EachMini_2x2", &M88::Full_TriadF_EachMini_2x2 },
        { "Full_TriadF_EachQuad_2x2", &M88::Full_TriadF_EachQuad_2x2 },

        { "Full_TriadG_2x2", &M88::Full_TriadG_2x2 },
        { "Full_TriadG_EachMini_2x2", &M88::Full_TriadG_EachMini_2x2 },
        { "Full_TriadG_EachQuad_2x2", &M88::Full_TriadG_EachQuad_2x2 },

        { "Full_TriadH_2x2", &M88::Full_TriadH_2x2 },
        { "Full_TriadH_EachMini_2x2", &M88::Full_TriadH_EachMini_2x2 },
        { "Full_TriadH_EachQuad_2x2", &M88::Full_TriadH_EachQuad_2x2 },

        { "Full_SnakeA_2x2", &M88::Full_SnakeA_2x2 },
        { "Full_SnakeA_EachMini_2x2", &M88::Full_SnakeA_EachMini_2x2 },
        { "Full_SnakeA_EachQuad_2x2", &M88::Full_SnakeA_EachQuad_2x2 },

        { "Full_SnakeB_2x2", &M88::Full_SnakeB_2x2 },
        { "Full_SnakeB_EachMini_2x2", &M88::Full_SnakeB_EachMini_2x2 },
        { "Full_SnakeB_EachQuad_2x2", &M88::Full_SnakeB_EachQuad_2x2 },

        { "Full_SnakeC_2x2", &M88::Full_SnakeC_2x2 },
        { "Full_SnakeC_EachMini_2x2", &M88::Full_SnakeC_EachMini_2x2 },
        { "Full_SnakeC_EachQuad_2x2", &M88::Full_SnakeC_EachQuad_2x2 },

        { "Full_SnakeD_2x2", &M88::Full_SnakeD_2x2 },
        { "Full_SnakeD_EachMini_2x2", &M88::Full_SnakeD_EachMini_2x2 },
        { "Full_SnakeD_EachQuad_2x2", &M88::Full_SnakeD_EachQuad_2x2 },

        { "Full_CastleA_4x4", &M88::Full_CastleA_4x4 },
        { "Full_CastleA_EachQuad_4x4", &M88::Full_CastleA_EachQuad_4x4 },

        { "Full_CastleB_4x4", &M88::Full_CastleB_4x4 },
        { "Full_CastleB_EachQuad_4x4", &M88::Full_CastleB_EachQuad_4x4 },

        { "Full_CastleC_4x4", &M88::Full_CastleC_4x4 },
        { "Full_CastleC_EachQuad_4x4", &M88::Full_CastleC_EachQuad_4x4 },

        { "Full_CastleD_4x4", &M88::Full_CastleD_4x4 },
        { "Full_CastleD_EachQuad_4x4", &M88::Full_CastleD_EachQuad_4x4 },

        { "Full_TowerA_4x4", &M88::Full_TowerA_4x4 },
        { "Full_TowerA_EachQuad_4x4", &M88::Full_TowerA_EachQuad_4x4 },

        { "Full_TowerB_4x4", &M88::Full_TowerB_4x4 },
        { "Full_TowerB_EachQuad_4x4", &M88::Full_TowerB_EachQuad_4x4 },

        { "Full_FortressA_4x4", &M88::Full_FortressA_4x4 },
        { "Full_FortressA_EachQuad_4x4", &M88::Full_FortressA_EachQuad_4x4 },

        { "Full_FortressB_4x4", &M88::Full_FortressB_4x4 },
        { "Full_FortressB_EachQuad_4x4", &M88::Full_FortressB_EachQuad_4x4 },

        { "Full_PinA_4x4", &M88::Full_PinA_4x4 },
        { "Full_PinA_8x8", &M88::Full_PinA_8x8 },
        { "Full_PinA_EachQuad_4x4", &M88::Full_PinA_EachQuad_4x4 },

        { "Full_PinB_4x4", &M88::Full_PinB_4x4 },
        { "Full_PinB_8x8", &M88::Full_PinB_8x8 },
        { "Full_PinB_EachQuad_4x4", &M88::Full_PinB_EachQuad_4x4 },

        { "Full_SwapA_2x2", &M88::Full_SwapA_2x2 },
        { "Full_SwapA_EachMini_2x2", &M88::Full_SwapA_EachMini_2x2 },
        { "Full_SwapA_EachQuad_2x2", &M88::Full_SwapA_EachQuad_2x2 },

        { "Full_SwapB_2x2", &M88::Full_SwapB_2x2 },
        { "Full_SwapB_EachMini_2x2", &M88::Full_SwapB_EachMini_2x2 },
        { "Full_SwapB_EachQuad_2x2", &M88::Full_SwapB_EachQuad_2x2 },

        { "Full_SwapBoth_4x4", &M88::Full_SwapBoth_4x4 },
        { "Full_SwapBoth_8x8", &M88::Full_SwapBoth_8x8 },
        { "Full_SwapBoth_EachQuad_4x4", &M88::Full_SwapBoth_EachQuad_4x4 },

        { "Full_SwapC_2x2", &M88::Full_SwapC_2x2 },
        { "Full_SwapC_EachMini_2x2", &M88::Full_SwapC_EachMini_2x2 },
        { "Full_SwapC_EachQuad_2x2", &M88::Full_SwapC_EachQuad_2x2 },

        { "Full_SwapColums_4x4", &M88::Full_SwapColums_4x4 },
        { "Full_SwapColums_8x8", &M88::Full_SwapColums_8x8 },
        { "Full_SwapColums_EachQuad_4x4", &M88::Full_SwapColums_EachQuad_4x4 },

        { "Full_SwapD_2x2", &M88::Full_SwapD_2x2 },
        { "Full_SwapD_EachMini_2x2", &M88::Full_SwapD_EachMini_2x2 },
        { "Full_SwapD_EachQuad_2x2", &M88::Full_SwapD_EachQuad_2x2 },

        { "Full_SwapRows_4x4", &M88::Full_SwapRows_4x4 },
        { "Full_SwapRows_8x8", &M88::Full_SwapRows_8x8 },
        { "Full_SwapRows_EachQuad_4x4", &M88::Full_SwapRows_EachQuad_4x4 },

        { "Full_ReachA_4x4", &M88::Full_ReachA_4x4 },
        { "Full_ReachA_8x8", &M88::Full_ReachA_8x8 },
        { "Full_ReachA_EachQuad_4x4", &M88::Full_ReachA_EachQuad_4x4 },

        { "Full_ReachB_4x4", &M88::Full_ReachB_4x4 },
        { "Full_ReachB_8x8", &M88::Full_ReachB_8x8 },
        { "Full_ReachB_EachQuad_4x4", &M88::Full_ReachB_EachQuad_4x4 },

        { "Full_ReachC_4x4", &M88::Full_ReachC_4x4 },
        { "Full_ReachC_8x8", &M88::Full_ReachC_8x8 },
        { "Full_ReachC_EachQuad_4x4", &M88::Full_ReachC_EachQuad_4x4 },

        { "Full_ReachD_4x4", &M88::Full_ReachD_4x4 },
        { "Full_ReachD_8x8", &M88::Full_ReachD_8x8 },
        { "Full_ReachD_EachQuad_4x4", &M88::Full_ReachD_EachQuad_4x4 },

        { "Full_ShearA_4x4", &M88::Full_ShearA_4x4 },
        { "Full_ShearA_8x8", &M88::Full_ShearA_8x8 },
        { "Full_ShearA_EachQuad_4x4", &M88::Full_ShearA_EachQuad_4x4 },

        { "Full_ShearB_4x4", &M88::Full_ShearB_4x4 },
        { "Full_ShearB_8x8", &M88::Full_ShearB_8x8 },
        { "Full_ShearB_EachQuad_4x4", &M88::Full_ShearB_EachQuad_4x4 },

        { "Full_ShearC_4x4", &M88::Full_ShearC_4x4 },
        { "Full_ShearC_8x8", &M88::Full_ShearC_8x8 },
        { "Full_ShearC_EachQuad_4x4", &M88::Full_ShearC_EachQuad_4x4 },

        { "Full_ShearD_4x4", &M88::Full_ShearD_4x4 },
        { "Full_ShearD_8x8", &M88::Full_ShearD_8x8 },
        { "Full_ShearD_EachQuad_4x4", &M88::Full_ShearD_EachQuad_4x4 },

        { "Full_RollHor1_4x4", &M88::Full_RollHor1_4x4 },
        { "Full_RollHor1_EachQuad_4x4", &M88::Full_RollHor1_EachQuad_4x4 },

        { "Full_RollHor2_4x4", &M88::Full_RollHor2_4x4 },
        { "Full_RollHor2_EachQuad_4x4", &M88::Full_RollHor2_EachQuad_4x4 },

        { "Full_RollHor3_4x4", &M88::Full_RollHor3_4x4 },
        { "Full_RollHor3_EachQuad_4x4", &M88::Full_RollHor3_EachQuad_4x4 },

        { "Full_RollVer1_4x4", &M88::Full_RollVer1_4x4 },
        { "Full_RollVer1_EachQuad_4x4", &M88::Full_RollVer1_EachQuad_4x4 },

        { "Full_RollVer2_4x4", &M88::Full_RollVer2_4x4 },
        { "Full_RollVer2_EachQuad_4x4", &M88::Full_RollVer2_EachQuad_4x4 },

        { "Full_RollVer3_4x4", &M88::Full_RollVer3_4x4 },
        { "Full_RollVer3_EachQuad_4x4", &M88::Full_RollVer3_EachQuad_4x4 },

        { "Full_FoldA_4x4", &M88::Full_FoldA_4x4 },
        { "Full_FoldA_EachQuad_4x4", &M88::Full_FoldA_EachQuad_4x4 },

        { "Full_FoldB_4x4", &M88::Full_FoldB_4x4 },
        { "Full_FoldB_EachQuad_4x4", &M88::Full_FoldB_EachQuad_4x4 },

        { "Full_FoldC_4x4", &M88::Full_FoldC_4x4 },
        { "Full_FoldC_EachQuad_4x4", &M88::Full_FoldC_EachQuad_4x4 },

        { "Full_FoldD_4x4", &M88::Full_FoldD_4x4 },
        { "Full_FoldD_EachQuad_4x4", &M88::Full_FoldD_EachQuad_4x4 },

        { "Quad_RotA_2x2_A", &M88::Quad_RotA_2x2_A },
        { "Quad_RotA_2x2_B", &M88::Quad_RotA_2x2_B },
        { "Quad_RotA_2x2_C", &M88::Quad_RotA_2x2_C },
        { "Quad_RotA_2x2_D", &M88::Quad_RotA_2x2_D },
        { "Quad_RotA_4x4_A", &M88::Quad_RotA_4x4_A },
        { "Quad_RotA_4x4_B", &M88::Quad_RotA_4x4_B },
        { "Quad_RotA_4x4_C", &M88::Quad_RotA_4x4_C },
        { "Quad_RotA_4x4_D", &M88::Quad_RotA_4x4_D },
        { "Quad_RotA_EachMini_2x2_A", &M88::Quad_RotA_EachMini_2x2_A },
        { "Quad_RotA_EachMini_2x2_B", &M88::Quad_RotA_EachMini_2x2_B },
        { "Quad_RotA_EachMini_2x2_C", &M88::Quad_RotA_EachMini_2x2_C },
        { "Quad_RotA_EachMini_2x2_D", &M88::Quad_RotA_EachMini_2x2_D },

        { "Quad_RotB_2x2_A", &M88::Quad_RotB_2x2_A },
        { "Quad_RotB_2x2_B", &M88::Quad_RotB_2x2_B },
        { "Quad_RotB_2x2_C", &M88::Quad_RotB_2x2_C },
        { "Quad_RotB_2x2_D", &M88::Quad_RotB_2x2_D },
        { "Quad_RotB_4x4_A", &M88::Quad_RotB_4x4_A },
        { "Quad_RotB_4x4_B", &M88::Quad_RotB_4x4_B },
        { "Quad_RotB_4x4_C", &M88::Quad_RotB_4x4_C },
        { "Quad_RotB_4x4_D", &M88::Quad_RotB_4x4_D },
        { "Quad_RotB_EachMini_2x2_A", &M88::Quad_RotB_EachMini_2x2_A },
        { "Quad_RotB_EachMini_2x2_B", &M88::Quad_RotB_EachMini_2x2_B },
        { "Quad_RotB_EachMini_2x2_C", &M88::Quad_RotB_EachMini_2x2_C },
        { "Quad_RotB_EachMini_2x2_D", &M88::Quad_RotB_EachMini_2x2_D },

        { "Quad_RotC_2x2_A", &M88::Quad_RotC_2x2_A },
        { "Quad_RotC_2x2_B", &M88::Quad_RotC_2x2_B },
        { "Quad_RotC_2x2_C", &M88::Quad_RotC_2x2_C },
        { "Quad_RotC_2x2_D", &M88::Quad_RotC_2x2_D },
        { "Quad_RotC_4x4_A", &M88::Quad_RotC_4x4_A },
        { "Quad_RotC_4x4_B", &M88::Quad_RotC_4x4_B },
        { "Quad_RotC_4x4_C", &M88::Quad_RotC_4x4_C },
        { "Quad_RotC_4x4_D", &M88::Quad_RotC_4x4_D },
        { "Quad_RotC_EachMini_2x2_A", &M88::Quad_RotC_EachMini_2x2_A },
        { "Quad_RotC_EachMini_2x2_B", &M88::Quad_RotC_EachMini_2x2_B },
        { "Quad_RotC_EachMini_2x2_C", &M88::Quad_RotC_EachMini_2x2_C },
        { "Quad_RotC_EachMini_2x2_D", &M88::Quad_RotC_EachMini_2x2_D },

        { "Quad_FlipA_2x2_A", &M88::Quad_FlipA_2x2_A },
        { "Quad_FlipA_2x2_B", &M88::Quad_FlipA_2x2_B },
        { "Quad_FlipA_2x2_C", &M88::Quad_FlipA_2x2_C },
        { "Quad_FlipA_2x2_D", &M88::Quad_FlipA_2x2_D },
        { "Quad_FlipA_4x4_A", &M88::Quad_FlipA_4x4_A },
        { "Quad_FlipA_4x4_B", &M88::Quad_FlipA_4x4_B },
        { "Quad_FlipA_4x4_C", &M88::Quad_FlipA_4x4_C },
        { "Quad_FlipA_4x4_D", &M88::Quad_FlipA_4x4_D },
        { "Quad_FlipA_EachMini_2x2_A", &M88::Quad_FlipA_EachMini_2x2_A },
        { "Quad_FlipA_EachMini_2x2_B", &M88::Quad_FlipA_EachMini_2x2_B },
        { "Quad_FlipA_EachMini_2x2_C", &M88::Quad_FlipA_EachMini_2x2_C },
        { "Quad_FlipA_EachMini_2x2_D", &M88::Quad_FlipA_EachMini_2x2_D },

        { "Quad_FlipB_2x2_A", &M88::Quad_FlipB_2x2_A },
        { "Quad_FlipB_2x2_B", &M88::Quad_FlipB_2x2_B },
        { "Quad_FlipB_2x2_C", &M88::Quad_FlipB_2x2_C },
        { "Quad_FlipB_2x2_D", &M88::Quad_FlipB_2x2_D },
        { "Quad_FlipB_4x4_A", &M88::Quad_FlipB_4x4_A },
        { "Quad_FlipB_4x4_B", &M88::Quad_FlipB_4x4_B },
        { "Quad_FlipB_4x4_C", &M88::Quad_FlipB_4x4_C },
        { "Quad_FlipB_4x4_D", &M88::Quad_FlipB_4x4_D },
        { "Quad_FlipB_EachMini_2x2_A", &M88::Quad_FlipB_EachMini_2x2_A },
        { "Quad_FlipB_EachMini_2x2_B", &M88::Quad_FlipB_EachMini_2x2_B },
        { "Quad_FlipB_EachMini_2x2_C", &M88::Quad_FlipB_EachMini_2x2_C },
        { "Quad_FlipB_EachMini_2x2_D", &M88::Quad_FlipB_EachMini_2x2_D },

        { "Quad_FlipC_2x2_A", &M88::Quad_FlipC_2x2_A },
        { "Quad_FlipC_2x2_B", &M88::Quad_FlipC_2x2_B },
        { "Quad_FlipC_2x2_C", &M88::Quad_FlipC_2x2_C },
        { "Quad_FlipC_2x2_D", &M88::Quad_FlipC_2x2_D },
        { "Quad_FlipC_4x4_A", &M88::Quad_FlipC_4x4_A },
        { "Quad_FlipC_4x4_B", &M88::Quad_FlipC_4x4_B },
        { "Quad_FlipC_4x4_C", &M88::Quad_FlipC_4x4_C },
        { "Quad_FlipC_4x4_D", &M88::Quad_FlipC_4x4_D },
        { "Quad_FlipC_EachMini_2x2_A", &M88::Quad_FlipC_EachMini_2x2_A },
        { "Quad_FlipC_EachMini_2x2_B", &M88::Quad_FlipC_EachMini_2x2_B },
        { "Quad_FlipC_EachMini_2x2_C", &M88::Quad_FlipC_EachMini_2x2_C },
        { "Quad_FlipC_EachMini_2x2_D", &M88::Quad_FlipC_EachMini_2x2_D },

        { "Quad_FlipD_2x2_A", &M88::Quad_FlipD_2x2_A },
        { "Quad_FlipD_2x2_B", &M88::Quad_FlipD_2x2_B },
        { "Quad_FlipD_2x2_C", &M88::Quad_FlipD_2x2_C },
        { "Quad_FlipD_2x2_D", &M88::Quad_FlipD_2x2_D },
        { "Quad_FlipD_4x4_A", &M88::Quad_FlipD_4x4_A },
        { "Quad_FlipD_4x4_B", &M88::Quad_FlipD_4x4_B },
        { "Quad_FlipD_4x4_C", &M88::Quad_FlipD_4x4_C },
        { "Quad_FlipD_4x4_D", &M88::Quad_FlipD_4x4_D },
        { "Quad_FlipD_EachMini_2x2_A", &M88::Quad_FlipD_EachMini_2x2_A },
        { "Quad_FlipD_EachMini_2x2_B", &M88::Quad_FlipD_EachMini_2x2_B },
        { "Quad_FlipD_EachMini_2x2_C", &M88::Quad_FlipD_EachMini_2x2_C },
        { "Quad_FlipD_EachMini_2x2_D", &M88::Quad_FlipD_EachMini_2x2_D },

        { "Quad_TriadA_2x2_A", &M88::Quad_TriadA_2x2_A },
        { "Quad_TriadA_2x2_B", &M88::Quad_TriadA_2x2_B },
        { "Quad_TriadA_2x2_C", &M88::Quad_TriadA_2x2_C },
        { "Quad_TriadA_2x2_D", &M88::Quad_TriadA_2x2_D },
        { "Quad_TriadA_EachMini_2x2_A", &M88::Quad_TriadA_EachMini_2x2_A },
        { "Quad_TriadA_EachMini_2x2_B", &M88::Quad_TriadA_EachMini_2x2_B },
        { "Quad_TriadA_EachMini_2x2_C", &M88::Quad_TriadA_EachMini_2x2_C },
        { "Quad_TriadA_EachMini_2x2_D", &M88::Quad_TriadA_EachMini_2x2_D },

        { "Quad_TriadB_2x2_A", &M88::Quad_TriadB_2x2_A },
        { "Quad_TriadB_2x2_B", &M88::Quad_TriadB_2x2_B },
        { "Quad_TriadB_2x2_C", &M88::Quad_TriadB_2x2_C },
        { "Quad_TriadB_2x2_D", &M88::Quad_TriadB_2x2_D },
        { "Quad_TriadB_EachMini_2x2_A", &M88::Quad_TriadB_EachMini_2x2_A },
        { "Quad_TriadB_EachMini_2x2_B", &M88::Quad_TriadB_EachMini_2x2_B },
        { "Quad_TriadB_EachMini_2x2_C", &M88::Quad_TriadB_EachMini_2x2_C },
        { "Quad_TriadB_EachMini_2x2_D", &M88::Quad_TriadB_EachMini_2x2_D },

        { "Quad_TriadC_2x2_A", &M88::Quad_TriadC_2x2_A },
        { "Quad_TriadC_2x2_B", &M88::Quad_TriadC_2x2_B },
        { "Quad_TriadC_2x2_C", &M88::Quad_TriadC_2x2_C },
        { "Quad_TriadC_2x2_D", &M88::Quad_TriadC_2x2_D },
        { "Quad_TriadC_EachMini_2x2_A", &M88::Quad_TriadC_EachMini_2x2_A },
        { "Quad_TriadC_EachMini_2x2_B", &M88::Quad_TriadC_EachMini_2x2_B },
        { "Quad_TriadC_EachMini_2x2_C", &M88::Quad_TriadC_EachMini_2x2_C },
        { "Quad_TriadC_EachMini_2x2_D", &M88::Quad_TriadC_EachMini_2x2_D },

        { "Quad_TriadD_2x2_A", &M88::Quad_TriadD_2x2_A },
        { "Quad_TriadD_2x2_B", &M88::Quad_TriadD_2x2_B },
        { "Quad_TriadD_2x2_C", &M88::Quad_TriadD_2x2_C },
        { "Quad_TriadD_2x2_D", &M88::Quad_TriadD_2x2_D },
        { "Quad_TriadD_EachMini_2x2_A", &M88::Quad_TriadD_EachMini_2x2_A },
        { "Quad_TriadD_EachMini_2x2_B", &M88::Quad_TriadD_EachMini_2x2_B },
        { "Quad_TriadD_EachMini_2x2_C", &M88::Quad_TriadD_EachMini_2x2_C },
        { "Quad_TriadD_EachMini_2x2_D", &M88::Quad_TriadD_EachMini_2x2_D },

        { "Quad_TriadE_2x2_A", &M88::Quad_TriadE_2x2_A },
        { "Quad_TriadE_2x2_B", &M88::Quad_TriadE_2x2_B },
        { "Quad_TriadE_2x2_C", &M88::Quad_TriadE_2x2_C },
        { "Quad_TriadE_2x2_D", &M88::Quad_TriadE_2x2_D },
        { "Quad_TriadE_EachMini_2x2_A", &M88::Quad_TriadE_EachMini_2x2_A },
        { "Quad_TriadE_EachMini_2x2_B", &M88::Quad_TriadE_EachMini_2x2_B },
        { "Quad_TriadE_EachMini_2x2_C", &M88::Quad_TriadE_EachMini_2x2_C },
        { "Quad_TriadE_EachMini_2x2_D", &M88::Quad_TriadE_EachMini_2x2_D },

        { "Quad_TriadF_2x2_A", &M88::Quad_TriadF_2x2_A },
        { "Quad_TriadF_2x2_B", &M88::Quad_TriadF_2x2_B },
        { "Quad_TriadF_2x2_C", &M88::Quad_TriadF_2x2_C },
        { "Quad_TriadF_2x2_D", &M88::Quad_TriadF_2x2_D },
        { "Quad_TriadF_EachMini_2x2_A", &M88::Quad_TriadF_EachMini_2x2_A },
        { "Quad_TriadF_EachMini_2x2_B", &M88::Quad_TriadF_EachMini_2x2_B },
        { "Quad_TriadF_EachMini_2x2_C", &M88::Quad_TriadF_EachMini_2x2_C },
        { "Quad_TriadF_EachMini_2x2_D", &M88::Quad_TriadF_EachMini_2x2_D },

        { "Quad_TriadG_2x2_A", &M88::Quad_TriadG_2x2_A },
        { "Quad_TriadG_2x2_B", &M88::Quad_TriadG_2x2_B },
        { "Quad_TriadG_2x2_C", &M88::Quad_TriadG_2x2_C },
        { "Quad_TriadG_2x2_D", &M88::Quad_TriadG_2x2_D },
        { "Quad_TriadG_EachMini_2x2_A", &M88::Quad_TriadG_EachMini_2x2_A },
        { "Quad_TriadG_EachMini_2x2_B", &M88::Quad_TriadG_EachMini_2x2_B },
        { "Quad_TriadG_EachMini_2x2_C", &M88::Quad_TriadG_EachMini_2x2_C },
        { "Quad_TriadG_EachMini_2x2_D", &M88::Quad_TriadG_EachMini_2x2_D },

        { "Quad_TriadH_2x2_A", &M88::Quad_TriadH_2x2_A },
        { "Quad_TriadH_2x2_B", &M88::Quad_TriadH_2x2_B },
        { "Quad_TriadH_2x2_C", &M88::Quad_TriadH_2x2_C },
        { "Quad_TriadH_2x2_D", &M88::Quad_TriadH_2x2_D },
        { "Quad_TriadH_EachMini_2x2_A", &M88::Quad_TriadH_EachMini_2x2_A },
        { "Quad_TriadH_EachMini_2x2_B", &M88::Quad_TriadH_EachMini_2x2_B },
        { "Quad_TriadH_EachMini_2x2_C", &M88::Quad_TriadH_EachMini_2x2_C },
        { "Quad_TriadH_EachMini_2x2_D", &M88::Quad_TriadH_EachMini_2x2_D },

        { "Quad_SnakeA_2x2_A", &M88::Quad_SnakeA_2x2_A },
        { "Quad_SnakeA_2x2_B", &M88::Quad_SnakeA_2x2_B },
        { "Quad_SnakeA_2x2_C", &M88::Quad_SnakeA_2x2_C },
        { "Quad_SnakeA_2x2_D", &M88::Quad_SnakeA_2x2_D },
        { "Quad_SnakeA_EachMini_2x2_A", &M88::Quad_SnakeA_EachMini_2x2_A },
        { "Quad_SnakeA_EachMini_2x2_B", &M88::Quad_SnakeA_EachMini_2x2_B },
        { "Quad_SnakeA_EachMini_2x2_C", &M88::Quad_SnakeA_EachMini_2x2_C },
        { "Quad_SnakeA_EachMini_2x2_D", &M88::Quad_SnakeA_EachMini_2x2_D },

        { "Quad_SnakeB_2x2_A", &M88::Quad_SnakeB_2x2_A },
        { "Quad_SnakeB_2x2_B", &M88::Quad_SnakeB_2x2_B },
        { "Quad_SnakeB_2x2_C", &M88::Quad_SnakeB_2x2_C },
        { "Quad_SnakeB_2x2_D", &M88::Quad_SnakeB_2x2_D },
        { "Quad_SnakeB_EachMini_2x2_A", &M88::Quad_SnakeB_EachMini_2x2_A },
        { "Quad_SnakeB_EachMini_2x2_B", &M88::Quad_SnakeB_EachMini_2x2_B },
        { "Quad_SnakeB_EachMini_2x2_C", &M88::Quad_SnakeB_EachMini_2x2_C },
        { "Quad_SnakeB_EachMini_2x2_D", &M88::Quad_SnakeB_EachMini_2x2_D },

        { "Quad_SnakeC_2x2_A", &M88::Quad_SnakeC_2x2_A },
        { "Quad_SnakeC_2x2_B", &M88::Quad_SnakeC_2x2_B },
        { "Quad_SnakeC_2x2_C", &M88::Quad_SnakeC_2x2_C },
        { "Quad_SnakeC_2x2_D", &M88::Quad_SnakeC_2x2_D },
        { "Quad_SnakeC_EachMini_2x2_A", &M88::Quad_SnakeC_EachMini_2x2_A },
        { "Quad_SnakeC_EachMini_2x2_B", &M88::Quad_SnakeC_EachMini_2x2_B },
        { "Quad_SnakeC_EachMini_2x2_C", &M88::Quad_SnakeC_EachMini_2x2_C },
        { "Quad_SnakeC_EachMini_2x2_D", &M88::Quad_SnakeC_EachMini_2x2_D },

        { "Quad_SnakeD_2x2_A", &M88::Quad_SnakeD_2x2_A },
        { "Quad_SnakeD_2x2_B", &M88::Quad_SnakeD_2x2_B },
        { "Quad_SnakeD_2x2_C", &M88::Quad_SnakeD_2x2_C },
        { "Quad_SnakeD_2x2_D", &M88::Quad_SnakeD_2x2_D },
        { "Quad_SnakeD_EachMini_2x2_A", &M88::Quad_SnakeD_EachMini_2x2_A },
        { "Quad_SnakeD_EachMini_2x2_B", &M88::Quad_SnakeD_EachMini_2x2_B },
        { "Quad_SnakeD_EachMini_2x2_C", &M88::Quad_SnakeD_EachMini_2x2_C },
        { "Quad_SnakeD_EachMini_2x2_D", &M88::Quad_SnakeD_EachMini_2x2_D },

        { "Quad_CastleA_4x4_A", &M88::Quad_CastleA_4x4_A },
        { "Quad_CastleA_4x4_B", &M88::Quad_CastleA_4x4_B },
        { "Quad_CastleA_4x4_C", &M88::Quad_CastleA_4x4_C },
        { "Quad_CastleA_4x4_D", &M88::Quad_CastleA_4x4_D },

        { "Quad_CastleB_4x4_A", &M88::Quad_CastleB_4x4_A },
        { "Quad_CastleB_4x4_B", &M88::Quad_CastleB_4x4_B },
        { "Quad_CastleB_4x4_C", &M88::Quad_CastleB_4x4_C },
        { "Quad_CastleB_4x4_D", &M88::Quad_CastleB_4x4_D },

        { "Quad_CastleC_4x4_A", &M88::Quad_CastleC_4x4_A },
        { "Quad_CastleC_4x4_B", &M88::Quad_CastleC_4x4_B },
        { "Quad_CastleC_4x4_C", &M88::Quad_CastleC_4x4_C },
        { "Quad_CastleC_4x4_D", &M88::Quad_CastleC_4x4_D },

        { "Quad_CastleD_4x4_A", &M88::Quad_CastleD_4x4_A },
        { "Quad_CastleD_4x4_B", &M88::Quad_CastleD_4x4_B },
        { "Quad_CastleD_4x4_C", &M88::Quad_CastleD_4x4_C },
        { "Quad_CastleD_4x4_D", &M88::Quad_CastleD_4x4_D },

        { "Quad_TowerA_4x4_A", &M88::Quad_TowerA_4x4_A },
        { "Quad_TowerA_4x4_B", &M88::Quad_TowerA_4x4_B },
        { "Quad_TowerA_4x4_C", &M88::Quad_TowerA_4x4_C },
        { "Quad_TowerA_4x4_D", &M88::Quad_TowerA_4x4_D },

        { "Quad_TowerB_4x4_A", &M88::Quad_TowerB_4x4_A },
        { "Quad_TowerB_4x4_B", &M88::Quad_TowerB_4x4_B },
        { "Quad_TowerB_4x4_C", &M88::Quad_TowerB_4x4_C },
        { "Quad_TowerB_4x4_D", &M88::Quad_TowerB_4x4_D },

        { "Quad_FortressA_4x4_A", &M88::Quad_FortressA_4x4_A },
        { "Quad_FortressA_4x4_B", &M88::Quad_FortressA_4x4_B },
        { "Quad_FortressA_4x4_C", &M88::Quad_FortressA_4x4_C },
        { "Quad_FortressA_4x4_D", &M88::Quad_FortressA_4x4_D },

        { "Quad_FortressB_4x4_A", &M88::Quad_FortressB_4x4_A },
        { "Quad_FortressB_4x4_B", &M88::Quad_FortressB_4x4_B },
        { "Quad_FortressB_4x4_C", &M88::Quad_FortressB_4x4_C },
        { "Quad_FortressB_4x4_D", &M88::Quad_FortressB_4x4_D },

        { "Quad_PinA_4x4_A", &M88::Quad_PinA_4x4_A },
        { "Quad_PinA_4x4_B", &M88::Quad_PinA_4x4_B },
        { "Quad_PinA_4x4_C", &M88::Quad_PinA_4x4_C },
        { "Quad_PinA_4x4_D", &M88::Quad_PinA_4x4_D },

        { "Quad_PinB_4x4_A", &M88::Quad_PinB_4x4_A },
        { "Quad_PinB_4x4_B", &M88::Quad_PinB_4x4_B },
        { "Quad_PinB_4x4_C", &M88::Quad_PinB_4x4_C },
        { "Quad_PinB_4x4_D", &M88::Quad_PinB_4x4_D },

        { "Quad_SwapA_2x2_A", &M88::Quad_SwapA_2x2_A },
        { "Quad_SwapA_2x2_B", &M88::Quad_SwapA_2x2_B },
        { "Quad_SwapA_2x2_C", &M88::Quad_SwapA_2x2_C },
        { "Quad_SwapA_2x2_D", &M88::Quad_SwapA_2x2_D },
        { "Quad_SwapA_EachMini_2x2_A", &M88::Quad_SwapA_EachMini_2x2_A },
        { "Quad_SwapA_EachMini_2x2_B", &M88::Quad_SwapA_EachMini_2x2_B },
        { "Quad_SwapA_EachMini_2x2_C", &M88::Quad_SwapA_EachMini_2x2_C },
        { "Quad_SwapA_EachMini_2x2_D", &M88::Quad_SwapA_EachMini_2x2_D },

        { "Quad_SwapB_2x2_A", &M88::Quad_SwapB_2x2_A },
        { "Quad_SwapB_2x2_B", &M88::Quad_SwapB_2x2_B },
        { "Quad_SwapB_2x2_C", &M88::Quad_SwapB_2x2_C },
        { "Quad_SwapB_2x2_D", &M88::Quad_SwapB_2x2_D },
        { "Quad_SwapB_EachMini_2x2_A", &M88::Quad_SwapB_EachMini_2x2_A },
        { "Quad_SwapB_EachMini_2x2_B", &M88::Quad_SwapB_EachMini_2x2_B },
        { "Quad_SwapB_EachMini_2x2_C", &M88::Quad_SwapB_EachMini_2x2_C },
        { "Quad_SwapB_EachMini_2x2_D", &M88::Quad_SwapB_EachMini_2x2_D },

        { "Quad_SwapBoth_4x4_A", &M88::Quad_SwapBoth_4x4_A },
        { "Quad_SwapBoth_4x4_B", &M88::Quad_SwapBoth_4x4_B },
        { "Quad_SwapBoth_4x4_C", &M88::Quad_SwapBoth_4x4_C },
        { "Quad_SwapBoth_4x4_D", &M88::Quad_SwapBoth_4x4_D },

        { "Quad_SwapC_2x2_A", &M88::Quad_SwapC_2x2_A },
        { "Quad_SwapC_2x2_B", &M88::Quad_SwapC_2x2_B },
        { "Quad_SwapC_2x2_C", &M88::Quad_SwapC_2x2_C },
        { "Quad_SwapC_2x2_D", &M88::Quad_SwapC_2x2_D },
        { "Quad_SwapC_EachMini_2x2_A", &M88::Quad_SwapC_EachMini_2x2_A },
        { "Quad_SwapC_EachMini_2x2_B", &M88::Quad_SwapC_EachMini_2x2_B },
        { "Quad_SwapC_EachMini_2x2_C", &M88::Quad_SwapC_EachMini_2x2_C },
        { "Quad_SwapC_EachMini_2x2_D", &M88::Quad_SwapC_EachMini_2x2_D },

        { "Quad_SwapColums_4x4_A", &M88::Quad_SwapColums_4x4_A },
        { "Quad_SwapColums_4x4_B", &M88::Quad_SwapColums_4x4_B },
        { "Quad_SwapColums_4x4_C", &M88::Quad_SwapColums_4x4_C },
        { "Quad_SwapColums_4x4_D", &M88::Quad_SwapColums_4x4_D },

        { "Quad_SwapD_2x2_A", &M88::Quad_SwapD_2x2_A },
        { "Quad_SwapD_2x2_B", &M88::Quad_SwapD_2x2_B },
        { "Quad_SwapD_2x2_C", &M88::Quad_SwapD_2x2_C },
        { "Quad_SwapD_2x2_D", &M88::Quad_SwapD_2x2_D },
        { "Quad_SwapD_EachMini_2x2_A", &M88::Quad_SwapD_EachMini_2x2_A },
        { "Quad_SwapD_EachMini_2x2_B", &M88::Quad_SwapD_EachMini_2x2_B },
        { "Quad_SwapD_EachMini_2x2_C", &M88::Quad_SwapD_EachMini_2x2_C },
        { "Quad_SwapD_EachMini_2x2_D", &M88::Quad_SwapD_EachMini_2x2_D },

        { "Quad_SwapRows_4x4_A", &M88::Quad_SwapRows_4x4_A },
        { "Quad_SwapRows_4x4_B", &M88::Quad_SwapRows_4x4_B },
        { "Quad_SwapRows_4x4_C", &M88::Quad_SwapRows_4x4_C },
        { "Quad_SwapRows_4x4_D", &M88::Quad_SwapRows_4x4_D },

        { "Quad_ReachA_4x4_A", &M88::Quad_ReachA_4x4_A },
        { "Quad_ReachA_4x4_B", &M88::Quad_ReachA_4x4_B },
        { "Quad_ReachA_4x4_C", &M88::Quad_ReachA_4x4_C },
        { "Quad_ReachA_4x4_D", &M88::Quad_ReachA_4x4_D },

        { "Quad_ReachB_4x4_A", &M88::Quad_ReachB_4x4_A },
        { "Quad_ReachB_4x4_B", &M88::Quad_ReachB_4x4_B },
        { "Quad_ReachB_4x4_C", &M88::Quad_ReachB_4x4_C },
        { "Quad_ReachB_4x4_D", &M88::Quad_ReachB_4x4_D },

        { "Quad_ReachC_4x4_A", &M88::Quad_ReachC_4x4_A },
        { "Quad_ReachC_4x4_B", &M88::Quad_ReachC_4x4_B },
        { "Quad_ReachC_4x4_C", &M88::Quad_ReachC_4x4_C },
        { "Quad_ReachC_4x4_D", &M88::Quad_ReachC_4x4_D },

        { "Quad_ReachD_4x4_A", &M88::Quad_ReachD_4x4_A },
        { "Quad_ReachD_4x4_B", &M88::Quad_ReachD_4x4_B },
        { "Quad_ReachD_4x4_C", &M88::Quad_ReachD_4x4_C },
        { "Quad_ReachD_4x4_D", &M88::Quad_ReachD_4x4_D },

        { "Quad_ShearA_4x4_A", &M88::Quad_ShearA_4x4_A },
        { "Quad_ShearA_4x4_B", &M88::Quad_ShearA_4x4_B },
        { "Quad_ShearA_4x4_C", &M88::Quad_ShearA_4x4_C },
        { "Quad_ShearA_4x4_D", &M88::Quad_ShearA_4x4_D },

        { "Quad_ShearB_4x4_A", &M88::Quad_ShearB_4x4_A },
        { "Quad_ShearB_4x4_B", &M88::Quad_ShearB_4x4_B },
        { "Quad_ShearB_4x4_C", &M88::Quad_ShearB_4x4_C },
        { "Quad_ShearB_4x4_D", &M88::Quad_ShearB_4x4_D },

        { "Quad_ShearC_4x4_A", &M88::Quad_ShearC_4x4_A },
        { "Quad_ShearC_4x4_B", &M88::Quad_ShearC_4x4_B },
        { "Quad_ShearC_4x4_C", &M88::Quad_ShearC_4x4_C },
        { "Quad_ShearC_4x4_D", &M88::Quad_ShearC_4x4_D },

        { "Quad_ShearD_4x4_A", &M88::Quad_ShearD_4x4_A },
        { "Quad_ShearD_4x4_B", &M88::Quad_ShearD_4x4_B },
        { "Quad_ShearD_4x4_C", &M88::Quad_ShearD_4x4_C },
        { "Quad_ShearD_4x4_D", &M88::Quad_ShearD_4x4_D },

        { "Quad_RollHor1_4x4_A", &M88::Quad_RollHor1_4x4_A },
        { "Quad_RollHor1_4x4_B", &M88::Quad_RollHor1_4x4_B },
        { "Quad_RollHor1_4x4_C", &M88::Quad_RollHor1_4x4_C },
        { "Quad_RollHor1_4x4_D", &M88::Quad_RollHor1_4x4_D },

        { "Quad_RollHor2_4x4_A", &M88::Quad_RollHor2_4x4_A },
        { "Quad_RollHor2_4x4_B", &M88::Quad_RollHor2_4x4_B },
        { "Quad_RollHor2_4x4_C", &M88::Quad_RollHor2_4x4_C },
        { "Quad_RollHor2_4x4_D", &M88::Quad_RollHor2_4x4_D },

        { "Quad_RollHor3_4x4_A", &M88::Quad_RollHor3_4x4_A },
        { "Quad_RollHor3_4x4_B", &M88::Quad_RollHor3_4x4_B },
        { "Quad_RollHor3_4x4_C", &M88::Quad_RollHor3_4x4_C },
        { "Quad_RollHor3_4x4_D", &M88::Quad_RollHor3_4x4_D },

        { "Quad_RollVer1_4x4_A", &M88::Quad_RollVer1_4x4_A },
        { "Quad_RollVer1_4x4_B", &M88::Quad_RollVer1_4x4_B },
        { "Quad_RollVer1_4x4_C", &M88::Quad_RollVer1_4x4_C },
        { "Quad_RollVer1_4x4_D", &M88::Quad_RollVer1_4x4_D },

        { "Quad_RollVer2_4x4_A", &M88::Quad_RollVer2_4x4_A },
        { "Quad_RollVer2_4x4_B", &M88::Quad_RollVer2_4x4_B },
        { "Quad_RollVer2_4x4_C", &M88::Quad_RollVer2_4x4_C },
        { "Quad_RollVer2_4x4_D", &M88::Quad_RollVer2_4x4_D },

        { "Quad_RollVer3_4x4_A", &M88::Quad_RollVer3_4x4_A },
        { "Quad_RollVer3_4x4_B", &M88::Quad_RollVer3_4x4_B },
        { "Quad_RollVer3_4x4_C", &M88::Quad_RollVer3_4x4_C },
        { "Quad_RollVer3_4x4_D", &M88::Quad_RollVer3_4x4_D },

        { "Quad_FoldA_4x4_A", &M88::Quad_FoldA_4x4_A },
        { "Quad_FoldA_4x4_B", &M88::Quad_FoldA_4x4_B },
        { "Quad_FoldA_4x4_C", &M88::Quad_FoldA_4x4_C },
        { "Quad_FoldA_4x4_D", &M88::Quad_FoldA_4x4_D },

        { "Quad_FoldB_4x4_A", &M88::Quad_FoldB_4x4_A },
        { "Quad_FoldB_4x4_B", &M88::Quad_FoldB_4x4_B },
        { "Quad_FoldB_4x4_C", &M88::Quad_FoldB_4x4_C },
        { "Quad_FoldB_4x4_D", &M88::Quad_FoldB_4x4_D },

        { "Quad_FoldC_4x4_A", &M88::Quad_FoldC_4x4_A },
        { "Quad_FoldC_4x4_B", &M88::Quad_FoldC_4x4_B },
        { "Quad_FoldC_4x4_C", &M88::Quad_FoldC_4x4_C },
        { "Quad_FoldC_4x4_D", &M88::Quad_FoldC_4x4_D },

        { "Quad_FoldD_4x4_A", &M88::Quad_FoldD_4x4_A },
        { "Quad_FoldD_4x4_B", &M88::Quad_FoldD_4x4_B },
        { "Quad_FoldD_4x4_C", &M88::Quad_FoldD_4x4_C },
        { "Quad_FoldD_4x4_D", &M88::Quad_FoldD_4x4_D },
    };
}

- (void)testNoDuplicateTransformOutputs {
    const std::vector<TransformEntry> aTransforms = BuildTransformList();

    std::map<std::string, std::string> aSeen;
    std::vector<std::string> aDuplicates;

    for (const TransformEntry &aEntry : aTransforms) {
        M88 aMatrix = VerifyFull::SpawnTestMatrixFull();

        (aMatrix.*aEntry.mFunction)();

        const std::array<std::uint8_t, 64> aData = CaptureData(aMatrix);
        const std::string aKey = MatrixKey(aData);

        auto aIt = aSeen.find(aKey);
        if (aIt != aSeen.end()) {
            const std::string aMessage =
                std::string(aEntry.mName) +
                " duplicates " +
                aIt->second;

            aDuplicates.push_back(aMessage);

            Logging::Log("Duplicate transform output", aMatrix);
            NSLog(@"Duplicate transform output: %s", aMessage.c_str());
        } else {
            aSeen[aKey] = aEntry.mName;
        }
    }

    if (!aDuplicates.empty()) {
        NSMutableString *aFailure = [NSMutableString string];

        [aFailure appendFormat:@"Found %lu duplicate transform output(s):\n",
                               static_cast<unsigned long>(aDuplicates.size())];

        for (const std::string &aDuplicate : aDuplicates) {
            [aFailure appendFormat:@"%s\n", aDuplicate.c_str()];
        }

        XCTFail(@"%@", aFailure);
    }
}

@end

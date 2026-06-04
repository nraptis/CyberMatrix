//
//  UniqueQuarterTool.cpp
//  CyberMatrix
//

#include "UniqueQuarterTool.hpp"

#include <algorithm>
#include <cstdio>

static constexpr std::size_t kCandidateDistanceWarningThreshold = 12U;

static const std::vector<UniqueQuarterExistingOp> kExistingQuarterAOps = {
    
    { "Identity",             &M88::Reset },
    
    { "Quad_RotA_2x2_A",             &M88::Quad_RotA_2x2_A },
    { "Quad_RotA_EachMini_2x2_A",    &M88::Quad_RotA_EachMini_2x2_A },
    { "Quad_RotB_2x2_A",             &M88::Quad_RotB_2x2_A },
    { "Quad_RotB_EachMini_2x2_A",    &M88::Quad_RotB_EachMini_2x2_A },
    { "Quad_RotC_2x2_A",             &M88::Quad_RotC_2x2_A },
    { "Quad_RotC_EachMini_2x2_A",    &M88::Quad_RotC_EachMini_2x2_A },

    { "Quad_FlipA_2x2_A",            &M88::Quad_FlipA_2x2_A },
    { "Quad_FlipA_EachMini_2x2_A",   &M88::Quad_FlipA_EachMini_2x2_A },
    { "Quad_FlipB_2x2_A",            &M88::Quad_FlipB_2x2_A },
    { "Quad_FlipB_EachMini_2x2_A",   &M88::Quad_FlipB_EachMini_2x2_A },
    { "Quad_FlipC_2x2_A",            &M88::Quad_FlipC_2x2_A },
    { "Quad_FlipC_EachMini_2x2_A",   &M88::Quad_FlipC_EachMini_2x2_A },
    { "Quad_FlipD_2x2_A",            &M88::Quad_FlipD_2x2_A },
    { "Quad_FlipD_EachMini_2x2_A",   &M88::Quad_FlipD_EachMini_2x2_A },

    { "Quad_TriadA_2x2_A",           &M88::Quad_TriadA_2x2_A },
    { "Quad_TriadA_EachMini_2x2_A",  &M88::Quad_TriadA_EachMini_2x2_A },
    { "Quad_TriadB_2x2_A",           &M88::Quad_TriadB_2x2_A },
    { "Quad_TriadB_EachMini_2x2_A",  &M88::Quad_TriadB_EachMini_2x2_A },
    { "Quad_TriadC_2x2_A",           &M88::Quad_TriadC_2x2_A },
    { "Quad_TriadC_EachMini_2x2_A",  &M88::Quad_TriadC_EachMini_2x2_A },
    { "Quad_TriadD_2x2_A",           &M88::Quad_TriadD_2x2_A },
    { "Quad_TriadD_EachMini_2x2_A",  &M88::Quad_TriadD_EachMini_2x2_A },
    { "Quad_TriadE_2x2_A",           &M88::Quad_TriadE_2x2_A },
    { "Quad_TriadE_EachMini_2x2_A",  &M88::Quad_TriadE_EachMini_2x2_A },
    { "Quad_TriadF_2x2_A",           &M88::Quad_TriadF_2x2_A },
    { "Quad_TriadF_EachMini_2x2_A",  &M88::Quad_TriadF_EachMini_2x2_A },
    { "Quad_TriadG_2x2_A",           &M88::Quad_TriadG_2x2_A },
    { "Quad_TriadG_EachMini_2x2_A",  &M88::Quad_TriadG_EachMini_2x2_A },
    { "Quad_TriadH_2x2_A",           &M88::Quad_TriadH_2x2_A },
    { "Quad_TriadH_EachMini_2x2_A",  &M88::Quad_TriadH_EachMini_2x2_A },

    { "Quad_SnakeA_2x2_A",           &M88::Quad_SnakeA_2x2_A },
    { "Quad_SnakeA_EachMini_2x2_A",  &M88::Quad_SnakeA_EachMini_2x2_A },
    { "Quad_SnakeB_2x2_A",           &M88::Quad_SnakeB_2x2_A },
    { "Quad_SnakeB_EachMini_2x2_A",  &M88::Quad_SnakeB_EachMini_2x2_A },
    { "Quad_SnakeC_2x2_A",           &M88::Quad_SnakeC_2x2_A },
    { "Quad_SnakeC_EachMini_2x2_A",  &M88::Quad_SnakeC_EachMini_2x2_A },
    { "Quad_SnakeD_2x2_A",           &M88::Quad_SnakeD_2x2_A },
    { "Quad_SnakeD_EachMini_2x2_A",  &M88::Quad_SnakeD_EachMini_2x2_A },

    { "Quad_SwapA_2x2_A",            &M88::Quad_SwapA_2x2_A },
    { "Quad_SwapA_EachMini_2x2_A",   &M88::Quad_SwapA_EachMini_2x2_A },
    { "Quad_SwapB_2x2_A",            &M88::Quad_SwapB_2x2_A },
    { "Quad_SwapB_EachMini_2x2_A",   &M88::Quad_SwapB_EachMini_2x2_A },
    { "Quad_SwapC_2x2_A",            &M88::Quad_SwapC_2x2_A },
    { "Quad_SwapC_EachMini_2x2_A",   &M88::Quad_SwapC_EachMini_2x2_A },
    { "Quad_SwapD_2x2_A",            &M88::Quad_SwapD_2x2_A },
    { "Quad_SwapD_EachMini_2x2_A",   &M88::Quad_SwapD_EachMini_2x2_A },
    
    
    { "Quad_RotA_4x4_A",      &M88::Quad_RotA_4x4_A },
    { "Quad_RotB_4x4_A",      &M88::Quad_RotB_4x4_A },
    { "Quad_RotC_4x4_A",      &M88::Quad_RotC_4x4_A },

    { "Quad_FlipA_4x4_A",     &M88::Quad_FlipA_4x4_A },
    { "Quad_FlipB_4x4_A",     &M88::Quad_FlipB_4x4_A },
    { "Quad_FlipC_4x4_A",     &M88::Quad_FlipC_4x4_A },
    { "Quad_FlipD_4x4_A",     &M88::Quad_FlipD_4x4_A },

    { "Quad_TowerA_4x4_A",    &M88::Quad_TowerA_4x4_A },
    { "Quad_TowerB_4x4_A",    &M88::Quad_TowerB_4x4_A },

    { "Quad_ShearA_4x4_A",    &M88::Quad_ShearA_4x4_A },
    { "Quad_ShearB_4x4_A",    &M88::Quad_ShearB_4x4_A },
    { "Quad_ShearC_4x4_A",    &M88::Quad_ShearC_4x4_A },
    { "Quad_ShearD_4x4_A",    &M88::Quad_ShearD_4x4_A },
    
    { "Quad_JewelA_4x4_A",    &M88::Quad_JewelA_4x4_A },
    { "Quad_JewelB_4x4_A",    &M88::Quad_JewelB_4x4_A },
    { "Quad_JewelC_4x4_A",    &M88::Quad_JewelC_4x4_A },
    { "Quad_JewelD_4x4_A",    &M88::Quad_JewelD_4x4_A },
     
    { "Quad_CrystalA_4x4_A",  &M88::Quad_CrystalA_4x4_A },
    { "Quad_CrystalC_4x4_A",  &M88::Quad_CrystalC_4x4_A },
    { "Quad_CrystalB_4x4_A",  &M88::Quad_CrystalB_4x4_A },
    { "Quad_CrystalD_4x4_A",  &M88::Quad_CrystalD_4x4_A },
    
    { "Quad_OpalA_4x4_A",     &M88::Quad_OpalA_4x4_A },
    { "Quad_OpalC_4x4_A",     &M88::Quad_OpalC_4x4_A },
    { "Quad_OpalB_4x4_A",     &M88::Quad_OpalB_4x4_A },
    { "Quad_OpalD_4x4_A",     &M88::Quad_OpalD_4x4_A },
    
    { "Quad_PeridotA_4x4_A",  &M88::Quad_PeridotA_4x4_A },
    { "Quad_PeridotB_4x4_A",  &M88::Quad_PeridotB_4x4_A },
    { "Quad_PeridotC_4x4_A",  &M88::Quad_PeridotC_4x4_A },
    { "Quad_PeridotD_4x4_A",  &M88::Quad_PeridotD_4x4_A },
    
    { "Quad_SwanA_4x4_A",     &M88::Quad_SwanA_4x4_A },
    { "Quad_SwanB_4x4_A",     &M88::Quad_SwanB_4x4_A },
    { "Quad_SwanC_4x4_A",     &M88::Quad_SwanC_4x4_A },
    { "Quad_SwanD_4x4_A",     &M88::Quad_SwanD_4x4_A },

    { "Quad_GooseA_4x4_A",    &M88::Quad_GooseA_4x4_A },
    { "Quad_GooseB_4x4_A",    &M88::Quad_GooseB_4x4_A },
    { "Quad_GooseC_4x4_A",    &M88::Quad_GooseC_4x4_A },
    { "Quad_GooseD_4x4_A",    &M88::Quad_GooseD_4x4_A },
    
    { "Quad_SwanA_4x4_A",     &M88::Quad_SwanA_4x4_A },
    { "Quad_SwanB_4x4_A",     &M88::Quad_SwanB_4x4_A },
    { "Quad_SwanC_4x4_A",     &M88::Quad_SwanC_4x4_A },
    { "Quad_SwanD_4x4_A",     &M88::Quad_SwanD_4x4_A },

    { "Quad_GooseA_4x4_A",    &M88::Quad_GooseA_4x4_A },
    { "Quad_GooseB_4x4_A",    &M88::Quad_GooseB_4x4_A },
    { "Quad_GooseC_4x4_A",    &M88::Quad_GooseC_4x4_A },
    { "Quad_GooseD_4x4_A",    &M88::Quad_GooseD_4x4_A },
    
    
};

static const std::vector<UniqueQuarterCandidateOp> kCandidateQuarterOps = {
    { "Candidate_00", &UniqueQuarterTool::Candidate_00 },
    { "Candidate_01", &UniqueQuarterTool::Candidate_01 },
    { "Candidate_02", &UniqueQuarterTool::Candidate_02 },
    { "Candidate_03", &UniqueQuarterTool::Candidate_03 },

    { "Candidate_04", &UniqueQuarterTool::Candidate_04 },
    { "Candidate_05", &UniqueQuarterTool::Candidate_05 },
    { "Candidate_06", &UniqueQuarterTool::Candidate_06 },
    { "Candidate_07", &UniqueQuarterTool::Candidate_07 },
};

void UniqueQuarterTool::ApplyCandidateIndexed(UniqueQuarterGrid &pGrid,
                                              int pIndex) {
    const int aRotationIndex = pIndex & 3;
    const bool aUseSwapHalvesVer = (pIndex & 4) != 0;
    const bool aUseFlipB = (pIndex & 8) != 0;
    const int aBaseIndex = (pIndex >> 4) & 3;

    switch (aBaseIndex) {
        case 0:
            pGrid.ZigZagA();
            pGrid.ZigZagB();
            break;

        case 1:
            pGrid.ZigZagA();
            pGrid.ZigZagD();
            break;

        case 2:
            pGrid.ZigZagC();
            pGrid.ZigZagD();
            break;

        case 3:
            pGrid.ZigZagC();
            pGrid.ZigZagB();
            break;

        default:
            break;
    }

    if (aUseFlipB) {
        pGrid.FlipB();
    }

    if (aUseSwapHalvesVer) {
        pGrid.FlipC();
    }

    switch (aRotationIndex) {
        case 0:
            break;

        case 1:
            pGrid.RotateRight();
            break;

        case 2:
            pGrid.Rotate180();
            break;

        case 3:
            pGrid.RotateLeft();
            break;

        default:
            break;
    }
}



void UniqueQuarterTool::Candidate_00(UniqueQuarterGrid &pGrid) {
    pGrid.ZigZagA();
    pGrid.ZigZagD();
    pGrid.SwapHalvesVer();
}

void UniqueQuarterTool::Candidate_01(UniqueQuarterGrid &pGrid) {
    pGrid.ZigZagA();
    pGrid.ZigZagD();
    pGrid.SwapHalvesVer();
    pGrid.RotateRight();
}

void UniqueQuarterTool::Candidate_02(UniqueQuarterGrid &pGrid) {
    pGrid.ZigZagA();
    pGrid.ZigZagD();
    pGrid.SwapHalvesVer();
    pGrid.Rotate180();
}

void UniqueQuarterTool::Candidate_03(UniqueQuarterGrid &pGrid) {
    pGrid.ZigZagA();
    pGrid.ZigZagD();
    pGrid.SwapHalvesVer();
    pGrid.RotateLeft();
}

void UniqueQuarterTool::Candidate_04(UniqueQuarterGrid &pGrid) {
    pGrid.ZigZagC();
    pGrid.ZigZagB();
    pGrid.SwapHalvesVer();
}

void UniqueQuarterTool::Candidate_05(UniqueQuarterGrid &pGrid) {
    pGrid.ZigZagC();
    pGrid.ZigZagB();
    pGrid.SwapHalvesVer();
    pGrid.RotateRight();
}

void UniqueQuarterTool::Candidate_06(UniqueQuarterGrid &pGrid) {
    pGrid.ZigZagC();
    pGrid.ZigZagB();
    pGrid.SwapHalvesVer();
    pGrid.Rotate180();
}

void UniqueQuarterTool::Candidate_07(UniqueQuarterGrid &pGrid) {
    pGrid.ZigZagC();
    pGrid.ZigZagB();
    pGrid.SwapHalvesVer();
    pGrid.RotateLeft();
}

void UniqueQuarterTool::Candidate_08(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 8); }
void UniqueQuarterTool::Candidate_09(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 9); }
void UniqueQuarterTool::Candidate_10(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 10); }
void UniqueQuarterTool::Candidate_11(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 11); }
void UniqueQuarterTool::Candidate_12(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 12); }
void UniqueQuarterTool::Candidate_13(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 13); }
void UniqueQuarterTool::Candidate_14(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 14); }
void UniqueQuarterTool::Candidate_15(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 15); }

void UniqueQuarterTool::Candidate_16(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 16); }
void UniqueQuarterTool::Candidate_17(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 17); }
void UniqueQuarterTool::Candidate_18(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 18); }
void UniqueQuarterTool::Candidate_19(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 19); }
void UniqueQuarterTool::Candidate_20(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 20); }
void UniqueQuarterTool::Candidate_21(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 21); }
void UniqueQuarterTool::Candidate_22(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 22); }
void UniqueQuarterTool::Candidate_23(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 23); }
void UniqueQuarterTool::Candidate_24(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 24); }
void UniqueQuarterTool::Candidate_25(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 25); }
void UniqueQuarterTool::Candidate_26(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 26); }
void UniqueQuarterTool::Candidate_27(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 27); }
void UniqueQuarterTool::Candidate_28(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 28); }
void UniqueQuarterTool::Candidate_29(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 29); }
void UniqueQuarterTool::Candidate_30(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 30); }
void UniqueQuarterTool::Candidate_31(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 31); }

void UniqueQuarterTool::Candidate_32(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 32); }
void UniqueQuarterTool::Candidate_33(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 33); }
void UniqueQuarterTool::Candidate_34(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 34); }
void UniqueQuarterTool::Candidate_35(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 35); }
void UniqueQuarterTool::Candidate_36(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 36); }
void UniqueQuarterTool::Candidate_37(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 37); }
void UniqueQuarterTool::Candidate_38(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 38); }
void UniqueQuarterTool::Candidate_39(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 39); }
void UniqueQuarterTool::Candidate_40(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 40); }
void UniqueQuarterTool::Candidate_41(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 41); }
void UniqueQuarterTool::Candidate_42(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 42); }
void UniqueQuarterTool::Candidate_43(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 43); }
void UniqueQuarterTool::Candidate_44(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 44); }
void UniqueQuarterTool::Candidate_45(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 45); }
void UniqueQuarterTool::Candidate_46(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 46); }
void UniqueQuarterTool::Candidate_47(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 47); }

void UniqueQuarterTool::Candidate_48(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 48); }
void UniqueQuarterTool::Candidate_49(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 49); }
void UniqueQuarterTool::Candidate_50(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 50); }
void UniqueQuarterTool::Candidate_51(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 51); }
void UniqueQuarterTool::Candidate_52(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 52); }
void UniqueQuarterTool::Candidate_53(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 53); }
void UniqueQuarterTool::Candidate_54(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 54); }
void UniqueQuarterTool::Candidate_55(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 55); }
void UniqueQuarterTool::Candidate_56(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 56); }
void UniqueQuarterTool::Candidate_57(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 57); }
void UniqueQuarterTool::Candidate_58(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 58); }
void UniqueQuarterTool::Candidate_59(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 59); }
void UniqueQuarterTool::Candidate_60(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 60); }
void UniqueQuarterTool::Candidate_61(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 61); }
void UniqueQuarterTool::Candidate_62(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 62); }
void UniqueQuarterTool::Candidate_63(UniqueQuarterGrid &pGrid) { ApplyCandidateIndexed(pGrid, 63); }



std::vector<UniqueQuarterCompareResult>
UniqueQuarterTool::CompareCandidateOpsToQuarterOps() {
    std::vector<UniqueQuarterCompareResult> results;

    std::vector<UniqueQuarterGrid> existingGrids;
    existingGrids.reserve(kExistingQuarterAOps.size());

    for (const UniqueQuarterExistingOp &entry : kExistingQuarterAOps) {
        M88 matrix;
        matrix.Reset();

        (matrix.*entry.mFunction)();

        UniqueQuarterGrid grid;
        grid.LoadFromM88QuadA(matrix);

        existingGrids.push_back(grid);
    }

    for (const UniqueQuarterCandidateOp &candidateEntry : kCandidateQuarterOps) {
        UniqueQuarterGrid candidate;
        candidate.Reset();

        candidateEntry.mFunction(candidate);

        for (std::size_t existingIndex = 0;
             existingIndex < kExistingQuarterAOps.size();
             ++existingIndex) {
            const UniqueQuarterGrid &existing = existingGrids[existingIndex];

            const std::size_t distance = candidate.HammingDistance(existing);

            UniqueQuarterCompareResult result;
            result.mCandidateName = candidateEntry.mName;
            result.mExistingName = kExistingQuarterAOps[existingIndex].mName;
            result.mHammingDistance = distance;
            result.mExactDuplicate = distance == 0;

            results.push_back(result);
        }
    }

    std::sort(results.begin(),
              results.end(),
              [](const UniqueQuarterCompareResult &a,
                 const UniqueQuarterCompareResult &b) {
                  if (a.mCandidateName != b.mCandidateName) {
                      return a.mCandidateName < b.mCandidateName;
                  }

                  if (a.mHammingDistance != b.mHammingDistance) {
                      return a.mHammingDistance < b.mHammingDistance;
                  }

                  return a.mExistingName < b.mExistingName;
              });

    return results;
}

void UniqueQuarterTool::PrintCompareCandidateOpsToQuarterOps() {
    const std::vector<UniqueQuarterCompareResult> results =
    CompareCandidateOpsToQuarterOps();

    std::string currentCandidate;

    for (const UniqueQuarterCompareResult &result : results) {
        if (result.mCandidateName != currentCandidate) {
            currentCandidate = result.mCandidateName;

            std::printf("\n%s\n", currentCandidate.c_str());
        }

        std::printf("  distance %2zu  vs  %s%s\n",
                    result.mHammingDistance,
                    result.mExistingName.c_str(),
                    result.mExactDuplicate ? "  DUPLICATE" : "");
    }
}

std::vector<UniqueQuarterExistingCompareResult>
UniqueQuarterTool::CompareExistingOpsToEachOther() {
    std::vector<UniqueQuarterExistingCompareResult> results;

    std::vector<UniqueQuarterGrid> existingGrids;
    existingGrids.reserve(kExistingQuarterAOps.size());

    for (const UniqueQuarterExistingOp &entry : kExistingQuarterAOps) {
        M88 matrix;
        matrix.Reset();

        (matrix.*entry.mFunction)();

        UniqueQuarterGrid grid;
        grid.LoadFromM88QuadA(matrix);

        existingGrids.push_back(grid);
    }

    for (std::size_t indexA = 0; indexA < kExistingQuarterAOps.size(); ++indexA) {
        for (std::size_t indexB = indexA + 1; indexB < kExistingQuarterAOps.size(); ++indexB) {
            const UniqueQuarterGrid &gridA = existingGrids[indexA];
            const UniqueQuarterGrid &gridB = existingGrids[indexB];

            const std::size_t distance = gridA.HammingDistance(gridB);

            UniqueQuarterExistingCompareResult result;
            result.mNameA = kExistingQuarterAOps[indexA].mName;
            result.mNameB = kExistingQuarterAOps[indexB].mName;
            result.mHammingDistance = distance;
            result.mExactDuplicate = distance == 0;

            results.push_back(result);
        }
    }

    std::sort(results.begin(),
              results.end(),
              [](const UniqueQuarterExistingCompareResult &a,
                 const UniqueQuarterExistingCompareResult &b) {
                  if (a.mHammingDistance != b.mHammingDistance) {
                      return a.mHammingDistance < b.mHammingDistance;
                  }

                  if (a.mNameA != b.mNameA) {
                      return a.mNameA < b.mNameA;
                  }

                  return a.mNameB < b.mNameB;
              });

    return results;
}


void UniqueQuarterTool::PrintCompareExistingOpsToEachOther() {
    const std::vector<UniqueQuarterExistingCompareResult> results =
    CompareExistingOpsToEachOther();

    std::printf("\nExisting quarter ops vs existing quarter ops\n");

    for (const UniqueQuarterExistingCompareResult &result : results) {
        std::printf("  distance %2zu  %s  vs  %s%s\n",
                    result.mHammingDistance,
                    result.mNameA.c_str(),
                    result.mNameB.c_str(),
                    result.mExactDuplicate ? "  DUPLICATE" : "");
    }
}

std::vector<UniqueQuarterCandidateCompareResult>
UniqueQuarterTool::CompareCandidateOpsToEachOther() {
    std::vector<UniqueQuarterCandidateCompareResult> results;

    std::vector<UniqueQuarterGrid> candidateGrids;
    candidateGrids.reserve(kCandidateQuarterOps.size());

    for (const UniqueQuarterCandidateOp &entry : kCandidateQuarterOps) {
        UniqueQuarterGrid grid;
        grid.Reset();

        entry.mFunction(grid);

        candidateGrids.push_back(grid);
    }

    for (std::size_t indexA = 0U; indexA < kCandidateQuarterOps.size(); ++indexA) {
        for (std::size_t indexB = indexA + 1U; indexB < kCandidateQuarterOps.size(); ++indexB) {
            const UniqueQuarterGrid &gridA = candidateGrids[indexA];
            const UniqueQuarterGrid &gridB = candidateGrids[indexB];

            const std::size_t distance = gridA.HammingDistance(gridB);

            UniqueQuarterCandidateCompareResult result;
            result.mNameA = kCandidateQuarterOps[indexA].mName;
            result.mNameB = kCandidateQuarterOps[indexB].mName;
            result.mHammingDistance = distance;
            result.mExactDuplicate = distance == 0U;

            results.push_back(result);
        }
    }

    std::sort(results.begin(),
              results.end(),
              [](const UniqueQuarterCandidateCompareResult &a,
                 const UniqueQuarterCandidateCompareResult &b) {
                  if (a.mHammingDistance != b.mHammingDistance) {
                      return a.mHammingDistance < b.mHammingDistance;
                  }

                  if (a.mNameA != b.mNameA) {
                      return a.mNameA < b.mNameA;
                  }

                  return a.mNameB < b.mNameB;
              });

    return results;
}


void UniqueQuarterTool::PrintCompareCandidateOpsToEachOther() {
    std::vector<UniqueQuarterGrid> candidateGrids;
    candidateGrids.reserve(kCandidateQuarterOps.size());

    for (const UniqueQuarterCandidateOp &entry : kCandidateQuarterOps) {
        UniqueQuarterGrid grid;
        grid.Reset();

        entry.mFunction(grid);

        candidateGrids.push_back(grid);
    }

    std::printf("\nCandidate quarter ops vs candidate quarter ops\n");

    for (std::size_t indexA = 0U; indexA < kCandidateQuarterOps.size(); ++indexA) {
        for (std::size_t indexB = indexA + 1U; indexB < kCandidateQuarterOps.size(); ++indexB) {
            const UniqueQuarterGrid &gridA = candidateGrids[indexA];
            const UniqueQuarterGrid &gridB = candidateGrids[indexB];

            const std::size_t distance = gridA.HammingDistance(gridB);

            std::printf("  distance %2zu  %s  vs  %s%s\n",
                        distance,
                        kCandidateQuarterOps[indexA].mName,
                        kCandidateQuarterOps[indexB].mName,
                        distance == 0U ? "  DUPLICATE" : "");
        }
    }
}

void UniqueQuarterTool::PrintCompareCandidates() {
    const std::vector<UniqueQuarterCompareResult> candidateVsExisting =
        CompareCandidateOpsToQuarterOps();

    const std::vector<UniqueQuarterCandidateCompareResult> candidateVsCandidate =
        CompareCandidateOpsToEachOther();

    std::printf("\n");
    std::printf("// ============================================================\n");
    std::printf("// Candidate compare: distance >= %zu\n", kCandidateDistanceWarningThreshold);
    std::printf("// ============================================================\n");

    std::printf("\nCandidate quarter ops vs existing quarter ops\n");

    for (const UniqueQuarterCompareResult &result : candidateVsExisting) {
        if (result.mHammingDistance < kCandidateDistanceWarningThreshold) {
            continue;
        }

        std::printf("  distance %2zu  %s  vs  %s%s\n",
                    result.mHammingDistance,
                    result.mCandidateName.c_str(),
                    result.mExistingName.c_str(),
                    result.mExactDuplicate ? "  DUPLICATE" : "");
    }

    std::printf("\nCandidate quarter ops vs candidate quarter ops\n");

    for (const UniqueQuarterCandidateCompareResult &result : candidateVsCandidate) {
        if (result.mHammingDistance < kCandidateDistanceWarningThreshold) {
            continue;
        }

        std::printf("  distance %2zu  %s  vs  %s%s\n",
                    result.mHammingDistance,
                    result.mNameA.c_str(),
                    result.mNameB.c_str(),
                    result.mExactDuplicate ? "  DUPLICATE" : "");
    }

    std::printf("\n");
    std::printf("// ============================================================\n");
    std::printf("// Candidate compare warnings: distance < %zu\n", kCandidateDistanceWarningThreshold);
    std::printf("// ============================================================\n");

    std::printf("\nCandidate quarter ops vs existing quarter ops\n");

    bool foundLowCandidateVsExisting = false;

    for (const UniqueQuarterCompareResult &result : candidateVsExisting) {
        if (result.mHammingDistance >= kCandidateDistanceWarningThreshold) {
            continue;
        }

        foundLowCandidateVsExisting = true;

        std::printf("  distance %2zu  %s  vs  %s%s\n",
                    result.mHammingDistance,
                    result.mCandidateName.c_str(),
                    result.mExistingName.c_str(),
                    result.mExactDuplicate ? "  DUPLICATE" : "");
    }

    if (!foundLowCandidateVsExisting) {
        std::printf("  none\n");
    }

    std::printf("\nCandidate quarter ops vs candidate quarter ops\n");

    bool foundLowCandidateVsCandidate = false;

    for (const UniqueQuarterCandidateCompareResult &result : candidateVsCandidate) {
        if (result.mHammingDistance >= kCandidateDistanceWarningThreshold) {
            continue;
        }

        foundLowCandidateVsCandidate = true;

        std::printf("  distance %2zu  %s  vs  %s%s\n",
                    result.mHammingDistance,
                    result.mNameA.c_str(),
                    result.mNameB.c_str(),
                    result.mExactDuplicate ? "  DUPLICATE" : "");
    }

    if (!foundLowCandidateVsCandidate) {
        std::printf("  none\n");
    }
}


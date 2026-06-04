//
//  UniqueQuarterTool.hpp
//  CyberMatrix
//

#ifndef UniqueQuarterTool_hpp
#define UniqueQuarterTool_hpp

#include <cstddef>
#include <string>
#include <vector>

#include "M88.hpp"
#include "UniqueQuarterGrid.hpp"

struct UniqueQuarterExistingCompareResult {
    std::string mNameA;
    std::string mNameB;
    std::size_t mHammingDistance;
    bool mExactDuplicate;
};

struct UniqueQuarterCompareResult {
    std::string mCandidateName;
    std::string mExistingName;
    std::size_t mHammingDistance;
    bool mExactDuplicate;
};

struct UniqueQuarterCandidateCompareResult {
    std::string mNameA;
    std::string mNameB;
    std::size_t mHammingDistance = 0U;
    bool mExactDuplicate = false;
};

struct UniqueQuarterExistingOp {
    const char *mName;
    void (M88::*mFunction)();
};

struct UniqueQuarterCandidateOp {
    const char *mName;
    void (*mFunction)(UniqueQuarterGrid &);
};

class UniqueQuarterTool {
public:
    static std::vector<UniqueQuarterCompareResult> CompareCandidateOpsToQuarterOps();
    
    static void PrintCompareCandidateOpsToQuarterOps();
    
    static std::vector<UniqueQuarterExistingCompareResult> CompareExistingOpsToEachOther();

    static void PrintCompareExistingOpsToEachOther();
    
    static void PrintCompareCandidateOpsToEachOther();
    
    static std::vector<UniqueQuarterCandidateCompareResult>
    CompareCandidateOpsToEachOther();

    static void PrintCompareCandidates();

    static void ApplyCandidateIndexed(UniqueQuarterGrid &pGrid, int pIndex);

    static void Candidate_00(UniqueQuarterGrid &pGrid);
    static void Candidate_01(UniqueQuarterGrid &pGrid);
    static void Candidate_02(UniqueQuarterGrid &pGrid);
    static void Candidate_03(UniqueQuarterGrid &pGrid);
    static void Candidate_04(UniqueQuarterGrid &pGrid);
    static void Candidate_05(UniqueQuarterGrid &pGrid);
    static void Candidate_06(UniqueQuarterGrid &pGrid);
    static void Candidate_07(UniqueQuarterGrid &pGrid);
    static void Candidate_08(UniqueQuarterGrid &pGrid);
    static void Candidate_09(UniqueQuarterGrid &pGrid);
    static void Candidate_10(UniqueQuarterGrid &pGrid);
    static void Candidate_11(UniqueQuarterGrid &pGrid);
    static void Candidate_12(UniqueQuarterGrid &pGrid);
    static void Candidate_13(UniqueQuarterGrid &pGrid);
    static void Candidate_14(UniqueQuarterGrid &pGrid);
    static void Candidate_15(UniqueQuarterGrid &pGrid);
    static void Candidate_16(UniqueQuarterGrid &pGrid);
    static void Candidate_17(UniqueQuarterGrid &pGrid);
    static void Candidate_18(UniqueQuarterGrid &pGrid);
    static void Candidate_19(UniqueQuarterGrid &pGrid);
    static void Candidate_20(UniqueQuarterGrid &pGrid);
    static void Candidate_21(UniqueQuarterGrid &pGrid);
    static void Candidate_22(UniqueQuarterGrid &pGrid);
    static void Candidate_23(UniqueQuarterGrid &pGrid);
    static void Candidate_24(UniqueQuarterGrid &pGrid);
    static void Candidate_25(UniqueQuarterGrid &pGrid);
    static void Candidate_26(UniqueQuarterGrid &pGrid);
    static void Candidate_27(UniqueQuarterGrid &pGrid);
    static void Candidate_28(UniqueQuarterGrid &pGrid);
    static void Candidate_29(UniqueQuarterGrid &pGrid);
    static void Candidate_30(UniqueQuarterGrid &pGrid);
    static void Candidate_31(UniqueQuarterGrid &pGrid);
    static void Candidate_32(UniqueQuarterGrid &pGrid);
    static void Candidate_33(UniqueQuarterGrid &pGrid);
    static void Candidate_34(UniqueQuarterGrid &pGrid);
    static void Candidate_35(UniqueQuarterGrid &pGrid);
    static void Candidate_36(UniqueQuarterGrid &pGrid);
    static void Candidate_37(UniqueQuarterGrid &pGrid);
    static void Candidate_38(UniqueQuarterGrid &pGrid);
    static void Candidate_39(UniqueQuarterGrid &pGrid);
    static void Candidate_40(UniqueQuarterGrid &pGrid);
    static void Candidate_41(UniqueQuarterGrid &pGrid);
    static void Candidate_42(UniqueQuarterGrid &pGrid);
    static void Candidate_43(UniqueQuarterGrid &pGrid);
    static void Candidate_44(UniqueQuarterGrid &pGrid);
    static void Candidate_45(UniqueQuarterGrid &pGrid);
    static void Candidate_46(UniqueQuarterGrid &pGrid);
    static void Candidate_47(UniqueQuarterGrid &pGrid);
    static void Candidate_48(UniqueQuarterGrid &pGrid);
    static void Candidate_49(UniqueQuarterGrid &pGrid);
    static void Candidate_50(UniqueQuarterGrid &pGrid);
    static void Candidate_51(UniqueQuarterGrid &pGrid);
    static void Candidate_52(UniqueQuarterGrid &pGrid);
    static void Candidate_53(UniqueQuarterGrid &pGrid);
    static void Candidate_54(UniqueQuarterGrid &pGrid);
    static void Candidate_55(UniqueQuarterGrid &pGrid);
    static void Candidate_56(UniqueQuarterGrid &pGrid);
    static void Candidate_57(UniqueQuarterGrid &pGrid);
    static void Candidate_58(UniqueQuarterGrid &pGrid);
    static void Candidate_59(UniqueQuarterGrid &pGrid);
    static void Candidate_60(UniqueQuarterGrid &pGrid);
    static void Candidate_61(UniqueQuarterGrid &pGrid);
    static void Candidate_62(UniqueQuarterGrid &pGrid);
    static void Candidate_63(UniqueQuarterGrid &pGrid);
    
    
};

#endif /* UniqueQuarterTool_hpp */

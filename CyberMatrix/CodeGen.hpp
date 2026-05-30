//
//  CodeGen.hpp
//  CyberMatrix
//
//  Created by nick on 5/29/26.
//

#ifndef CodeGen_h
#define CodeGen_h

enum class CodeGenBaseOp : std::uint8_t {
    kRotateRight,
    kRotateLeft,
    kFlipHorizontal,
    kFlipVertical,
    kTransposeMainDiagonal,
    kTransposeAntiDiagonal,
    kPinwheelRight,
    kPinwheelLeft
};

enum class CodeGenDomain : std::uint8_t {
    kFullMatrix,
    kQuarter,
    kSixteenth,
    kSixteenthsAsBlocks
};

enum class CodeGenScope : std::uint8_t {
    kOne,
    kEach
};

enum class CodeGenParent : std::uint8_t {
    kMatrix,
    kQuarterA,
    kQuarterB,
    kQuarterC,
    kQuarterD
};

struct CodeGenOpSpec {
    std::uint8_t        mByte;
    CodeGenBaseOp      mBaseOp;
    CodeGenDomain      mDomain;
    CodeGenScope       mScope;
    CodeGenParent      mParent;

    const char         *mFunctionName;
    const char         *mEnumName;
    const char         *mTestName;
};


#endif /* CodeGen_h */

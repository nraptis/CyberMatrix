//
//  AppDelegate.m
//  CyberMatrix
//
//  Created by nick on 5/29/26.
//

#import "AppDelegate.h"


#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <vector>
#include "M88.hpp"

struct Pick4 {
    std::uint8_t t[4];
};

static void PrintGridComment(const Pick4& p, std::size_t index) {
    char grid[4][4];

    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            grid[r][c] = '.';
        }
    }

    grid[p.t[0] >> 2][p.t[0] & 3U] = 'A';
    grid[p.t[1] >> 2][p.t[1] & 3U] = 'B';
    grid[p.t[2] >> 2][p.t[2] & 3U] = 'C';
    grid[p.t[3] >> 2][p.t[3] & 3U] = 'D';

    std::printf("        // %4zu: { %2u, %2u, %2u, %2u }\n",
                index,
                static_cast<unsigned>(p.t[0]),
                static_cast<unsigned>(p.t[1]),
                static_cast<unsigned>(p.t[2]),
                static_cast<unsigned>(p.t[3]));

    for (int r = 0; r < 4; ++r) {
        std::printf("        // ");
        for (int c = 0; c < 4; ++c) {
            std::printf("%c ", grid[r][c]);
        }
        std::printf("\n");
    }
}

void TryRotateRightQuarterA() {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aQuarterA = aMatrix.GetQuarterA();

    if (aQuarterA.Capable(Op::kCastleB)) {
        aQuarterA.Execute(Op::kCastleB);

        aMatrix.RecordStart();
        aMatrix.Paste(aQuarterA);
        aMatrix.RecordStop();
        
        aQuarterA.PrintCycles();
        
        std::vector<std::string> aNameChunks;
        aNameChunks.push_back("CastleB");
        aNameChunks.push_back("Quarter");
        aNameChunks.push_back("A");
        
        
        aQuarterA.PrintHPP(aNameChunks);
        aQuarterA.PrintCPP(aNameChunks);
        
        if (aMatrix.HasChange()) {
            aMatrix.RecordPrintFunction("RotateRight", "Quarter", 0);
        } else {
            std::printf("kRotateRight identity for 4 x 4\n");
        }
    } else {
        std::printf("kRotateRight not possible for 4 x 4\n");
    }
}

void TryOpSixHPP(const char *pOpName,
              Op pOp,
              std::size_t pSixteenthIndex) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aSix = aMatrix.GetSixteenth((int)pSixteenthIndex);

    if (aSix.Capable(pOp)) {
        aSix.Execute(pOp);

        aMatrix.RecordStart();
        aMatrix.Paste(aSix);
        aMatrix.RecordStop();
        
        std::vector<std::string> aNameChunks;
        aNameChunks.push_back(pOpName);
        aNameChunks.push_back("Six");
        aNameChunks.push_back(std::string(1, static_cast<char>('A' + pSixteenthIndex)));

        aSix.PrintHPP(aNameChunks);

        if (aMatrix.HasChange()) {
            aMatrix.RecordPrintFunction(pOpName, "Six", (int)pSixteenthIndex);
        }
    } else {
        std::printf("%s not possible for sixteenth %c\n",
                    pOpName,
                    static_cast<char>('A' + pSixteenthIndex));
    }
}

void TryOpSixCPP(const char *pOpName,
              Op pOp,
              std::size_t pSixteenthIndex) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aSix = aMatrix.GetSixteenth((int)pSixteenthIndex);

    if (aSix.Capable(pOp)) {
        aSix.Execute(pOp);

        aMatrix.RecordStart();
        aMatrix.Paste(aSix);
        aMatrix.RecordStop();
        
        std::vector<std::string> aNameChunks;
        aNameChunks.push_back(pOpName);
        aNameChunks.push_back("Six");
        aNameChunks.push_back(std::string(1, static_cast<char>('A' + pSixteenthIndex)));

        aSix.PrintCPP(aNameChunks);

        if (aMatrix.HasChange()) {
            aMatrix.RecordPrintFunction(pOpName, "Six", (int)pSixteenthIndex);
        }
        
    } else {
        std::printf("%s not possible for sixteenth %c\n",
                    pOpName,
                    static_cast<char>('A' + pSixteenthIndex));
    }
}

void MakeEachSixHPP(const char *pOpName, Op pOp) {
    for (std::size_t i = 0; i < 16U; i++) {
        TryOpSixHPP(pOpName, pOp, i);
    }
}

void MakeEachSixCPP(const char *pOpName, Op pOp) {
    for (std::size_t i = 0; i < 16U; i++) {
        TryOpSixCPP(pOpName, pOp, i);
    }
}

void MakeEachSix(const char *pOpName, Op pOp) {
    for (std::size_t i = 0; i < 16U; i++) {
        TryOpSixHPP(pOpName, pOp, i);
    }
    for (std::size_t i = 0; i < 16U; i++) {
        TryOpSixCPP(pOpName, pOp, i);
    }
    
}

void TryOpFullHPP(const char *pOpName, Op pOp) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aFull = aMatrix.GetFull();

    if (aFull.Capable(pOp)) {
        aFull.Execute(pOp);

        aMatrix.RecordStart();
        aMatrix.Paste(aFull);
        aMatrix.RecordStop();

        std::vector<std::string> aNameChunks;
        aNameChunks.push_back(pOpName);

        aFull.PrintHPP(aNameChunks);

        if (aMatrix.HasChange()) {
            aMatrix.RecordPrintFunction(pOpName, "", 0);
        }
    } else {
        std::printf("%s not possible for full matrix\n", pOpName);
    }
}

void TryOpFullCPP(const char *pOpName, Op pOp) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aFull = aMatrix.GetFull();

    if (aFull.Capable(pOp)) {
        aFull.Execute(pOp);

        aMatrix.RecordStart();
        aMatrix.Paste(aFull);
        aMatrix.RecordStop();

        std::vector<std::string> aNameChunks;
        aNameChunks.push_back(pOpName);

        aFull.PrintCPP(aNameChunks);

        if (aMatrix.HasChange()) {
            aMatrix.RecordPrintFunction(pOpName, "", 0);
        }
    } else {
        std::printf("%s not possible for full matrix\n", pOpName);
    }
}

void MakeFullHPP(const char *pOpName, Op pOp) {
    TryOpFullHPP(pOpName, pOp);
}

void MakeFullCPP(const char *pOpName, Op pOp) {
    TryOpFullCPP(pOpName, pOp);
}

void MakeFull(const char *pOpName, Op pOp) {
    TryOpFullHPP(pOpName, pOp);
    TryOpFullCPP(pOpName, pOp);
}


static Slice GetQuarterByIndex(M88 &pMatrix, std::size_t pQuarterIndex) {
    switch (pQuarterIndex) {
        case 0: return pMatrix.GetQuarterA();
        case 1: return pMatrix.GetQuarterB();
        case 2: return pMatrix.GetQuarterC();
        case 3: return pMatrix.GetQuarterD();
        default: return pMatrix.GetQuarterA();
    }
}

void TryOpQuarHPP(const char *pOpName,
                  Op pOp,
                  std::size_t pQuarterIndex) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aQuarter = GetQuarterByIndex(aMatrix, pQuarterIndex);

    if (aQuarter.Capable(pOp)) {
        aQuarter.Execute(pOp);

        aMatrix.RecordStart();
        aMatrix.Paste(aQuarter);
        aMatrix.RecordStop();

        std::vector<std::string> aNameChunks;
        aNameChunks.push_back(pOpName);
        aNameChunks.push_back("Quarter");
        aNameChunks.push_back(std::string(1, static_cast<char>('A' + pQuarterIndex)));

        aQuarter.PrintHPP(aNameChunks);

        if (aMatrix.HasChange()) {
            aMatrix.RecordPrintFunction(pOpName, "Quarter", static_cast<int>(pQuarterIndex));
        }
    } else {
        std::printf("%s not possible for quarter %c\n",
                    pOpName,
                    static_cast<char>('A' + pQuarterIndex));
    }
}

void TryOpQuarCPP(const char *pOpName,
                  Op pOp,
                  std::size_t pQuarterIndex) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aQuarter = GetQuarterByIndex(aMatrix, pQuarterIndex);

    if (aQuarter.Capable(pOp)) {
        aQuarter.Execute(pOp);

        aMatrix.RecordStart();
        aMatrix.Paste(aQuarter);
        aMatrix.RecordStop();

        std::vector<std::string> aNameChunks;
        aNameChunks.push_back(pOpName);
        aNameChunks.push_back("Quarter");
        aNameChunks.push_back(std::string(1, static_cast<char>('A' + pQuarterIndex)));

        aQuarter.PrintCPP(aNameChunks);

        if (aMatrix.HasChange()) {
            aMatrix.RecordPrintFunction(pOpName, "Quarter", static_cast<int>(pQuarterIndex));
        }
    } else {
        std::printf("%s not possible for quarter %c\n",
                    pOpName,
                    static_cast<char>('A' + pQuarterIndex));
    }
}

void MakeQuarHPP(const char *pOpName, Op pOp, std::size_t pQuarterIndex) {
    TryOpQuarHPP(pOpName, pOp, pQuarterIndex);
}

void MakeQuarCPP(const char *pOpName, Op pOp, std::size_t pQuarterIndex) {
    TryOpQuarCPP(pOpName, pOp, pQuarterIndex);
}

void MakeQuar(const char *pOpName, Op pOp, std::size_t pQuarterIndex) {
    TryOpQuarHPP(pOpName, pOp, pQuarterIndex);
    TryOpQuarCPP(pOpName, pOp, pQuarterIndex);
}

void MakeEachQuarHPP(const char *pOpName, Op pOp) {
    for (std::size_t i = 0; i < 4U; i++) {
        TryOpQuarHPP(pOpName, pOp, i);
    }
}

void MakeEachQuarCPP(const char *pOpName, Op pOp) {
    for (std::size_t i = 0; i < 4U; i++) {
        TryOpQuarCPP(pOpName, pOp, i);
    }
}

void MakeEachQuar(const char *pOpName, Op pOp) {
    for (std::size_t i = 0; i < 4U; i++) {
        TryOpQuarHPP(pOpName, pOp, i);
    }

    for (std::size_t i = 0; i < 4U; i++) {
        TryOpQuarCPP(pOpName, pOp, i);
    }
}


@interface AppDelegate ()

@property (strong) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
    //MakeEachSixCPP("SnakeA", Op::kSnakeA);
    //MakeEachSixCPP("SnakeB", Op::kSnakeB);
    //MakeEachSixCPP("SnakeC", Op::kSnakeC);
    //MakeEachSixCPP("SnakeD", Op::kSnakeD);
    
    
    MakeFull("RotA", Op::kRotA);
    MakeFull("RotB", Op::kRotB);
    MakeFull("RotC", Op::kRotC);

    MakeFull("BlockRotA", Op::kBlockRotA);
    MakeFull("BlockRotB", Op::kBlockRotB);
    MakeFull("BlockRotC", Op::kBlockRotC);

    MakeFull("PylonRotA", Op::kPylonRotA);
    MakeFull("PylonRotB", Op::kPylonRotB);
    MakeFull("PylonRotC", Op::kPylonRotC);
    
    // TryRotateRightQuarterA();
    
    /*
    M88 aMatrix;
    aMatrix.Reset();

    Slice aQuarterA = aMatrix.GetQuarterA();

    if (aQuarterA.Capable(Op::kRotateRight)) {
        aQuarterA.Execute(Op::kRotateRight);
        
        aMatrix.RecordStart();
        aMatrix.Paste(aQuarterA);
        aMatrix.RecordStop();
        
        if (aMatrix.HasChange()) {
            
            aMatrix.RecordPrintFunction("RotateRight", "Quarter", 0);
        } else {
            printf("kRotateRight identity for 4 x 4");
        }
        
        
    } else {
        printf("kRotateRight not possible for 4 x 4");
    }
    
    */
    
    
    return;
    
    
    std::vector<Pick4> picks;
    picks.reserve(1820);
    
    // Unique unordered 4-tile sets from 16 tiles.
    // a < b < c < d guarantees uniqueness.
    for (int a = 0; a < 16; ++a) {
        for (int b = a + 1; b < 16; ++b) {
            for (int c = b + 1; c < 16; ++c) {
                for (int d = c + 1; d < 16; ++d) {
                    Pick4 p;
                    p.t[0] = static_cast<std::uint8_t>(a);
                    p.t[1] = static_cast<std::uint8_t>(b);
                    p.t[2] = static_cast<std::uint8_t>(c);
                    p.t[3] = static_cast<std::uint8_t>(d);
                    picks.push_back(p);
                }
            }
        }
    }
    
    std::printf("// Generated by GenerateTwistMatrixQuarterSelects.cpp\n");
    std::printf("// Unique 4-tile picks inside a 4x4 quarter.\n");
    std::printf("// Count: %zu\n\n", picks.size());
    
    std::printf("#ifndef TwistMatrixQuarterSelects_hpp\n");
    std::printf("#define TwistMatrixQuarterSelects_hpp\n\n");
    std::printf("#include <cstdint>\n\n");
    
    std::printf("class TwistMatrixQuarterSelects {\n");
    std::printf("public:\n");
    std::printf("    static constexpr std::uint32_t kPick4Count = %zuU;\n\n", picks.size());
    
    std::printf("    static const std::uint8_t *Pick4(std::uint8_t pByteA, std::uint8_t pByteB) {\n");
    std::printf("        const std::uint32_t aWord = static_cast<std::uint32_t>(pByteA) |\n");
    std::printf("                                  (static_cast<std::uint32_t>(pByteB) << 8U);\n");
    std::printf("        const std::uint32_t aIndex = aWord %% kPick4Count;\n");
    std::printf("        return kPick4[aIndex];\n");
    std::printf("    }\n\n");
    
    std::printf("private:\n");
    std::printf("    static constexpr std::uint8_t kPick4[%zu][4] = {\n", picks.size());
    
    for (std::size_t i = 0; i < picks.size(); ++i) {
        if (i < 32) {
            PrintGridComment(picks[i], i);
        }
        
        std::printf("        { %2uU, %2uU, %2uU, %2uU }",
                    static_cast<unsigned>(picks[i].t[0]),
                    static_cast<unsigned>(picks[i].t[1]),
                    static_cast<unsigned>(picks[i].t[2]),
                    static_cast<unsigned>(picks[i].t[3]));
        
        if (i + 1U != picks.size()) {
            std::printf(",");
        }
        
        std::printf("\n");
    }
    
    std::printf("    };\n");
    std::printf("};\n\n");
    std::printf("#endif /* TwistMatrixQuarterSelects_hpp */\n");
    
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}


@end

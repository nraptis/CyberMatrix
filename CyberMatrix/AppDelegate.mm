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

#include "RecipeExporter2x2.hpp"
#include "RecipeExporter4x4.hpp"
#include "RecipeExporter8x8.hpp"

#include "RecipeFactory2x2.hpp"
#include "RecipeFactory4x4.hpp"
#include "RecipeFactory8x8.hpp"

#include "TestExporter2x2.hpp"
#include "TestExporter4x4.hpp"
#include "TestExporter8x8.hpp"


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

@interface AppDelegate ()

@property (strong) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
    
    //RecipeExporter2x2::Export(RecipeFactory2x2::SwapD());
    //TestExporter2x2::Export(RecipeFactory2x2::SwapD());
    
    //RecipeExporter4x4::Export(RecipeFactory4x4::FoldD());
    TestExporter4x4::Export(RecipeFactory4x4::FoldD());
    
    //RecipeExporter8x8::Export(RecipeFactory8x8::ShearD());
    //TestExporter8x8::Export(RecipeFactory8x8::ShearD());
    
    
    
    /*
    const std::string aName = "ShearD";
    void (Slice::*aFunction)() = &Slice::_ShearD;

    M88 aMatrix;

    aMatrix.Reset();
    Slice aSliceA = aMatrix.GetQuadA();
    aSliceA.PrepareSlots();
    (aSliceA.*aFunction)();
    aSliceA.RealizeSlots();
    aMatrix.RecordStart();
    aMatrix.Paste(aSliceA);
    aMatrix.RecordStop();
    aSliceA.PrintRecipeFactory4x4(aName);

    aMatrix.Reset();
    Slice aSliceB = aMatrix.GetFull();
    aSliceB.PrepareSlots();
    (aSliceB.*aFunction)();
    aSliceB.RealizeSlots();
    aMatrix.RecordStart();
    aMatrix.Paste(aSliceB);
    aMatrix.RecordStop();
    aSliceB.PrintRecipeFactory8x8(aName);
    */
    
    
    
    
    
    
    /*
    M88 aMatrix;
    aMatrix.Reset();
    Slice aSlice = aMatrix.GetMiniA();
    //Slice aSlice = aMatrix.GetQuadA();
    //Slice aSlice = aMatrix.GetFull();
    
    
    aSlice.PrepareSlots();
    
    aSlice._FlipD();
    
    aSlice.RealizeSlots();
    aMatrix.RecordStart();
    aMatrix.Paste(aSlice);
    aMatrix.RecordStop();
    aSlice.PrintRecipeFactory2x2("FlipD");
    //aSlice.PrintRecipeFactory4x4("FlipD");
    //aSlice.PrintRecipeFactory8x8("FlipD");
    */
    
    
    
    
    //RecipeExporter2x2::Export(RecipeFactory2x2::RotA());
    //TestExporter2x2::Export(RecipeFactory2x2::RotA());
    
    //RecipeExporter4x4::Export(RecipeFactory4x4::RotA());
    //TestExporter4x4::Export(RecipeFactory4x4::RotA());
    
    //RecipeExporter8x8::Export(RecipeFactory8x8::RotA());
    //TestExporter8x8::Export(RecipeFactory8x8::RotA());
    
    
    /*
    M88 aMatrix;
    aMatrix.Reset();

    Slice aSlice = aMatrix.GetFull();
    
    aSlice.PrepareSlots();

    aSlice._PinB();
    
    aSlice.RealizeSlots();


    aMatrix.RecordStart();
    aMatrix.Paste(aSlice);
    aMatrix.RecordStop();

    aSlice.PrintRecipeFactory4x4("PinB");
    */
    
    
    //
    //
    
    
    //RecipeExporter4x4::Export(RecipeFactory4x4::RotA());
    
    //RecipeExporter4x4::Export(RecipeFactory4x4::CastleA());
    
    
    //MakeEachMiniCPP("SnakeA", Op::kSnakeA);
    //MakeEachMiniCPP("SnakeB", Op::kSnakeB);
    //MakeEachMiniCPP("SnakeC", Op::kSnakeC);
    //MakeEachMiniCPP("SnakeD", Op::kSnakeD);
    
    //MakeEachMini("FlipD", Op::kFlipD);
    
    //MakeEachMiniCPP("RotD", Op::kRotC);
    
    //Slice aSlice = Slice(0, 0, 2);
    //aSlice.PrintBlockMapFunction("Glob");
    //aSlice.PrintVerifyExpected("VerifyQuad", "QuadPinAExpected");
    
    /*
    
    M88 aMatrix;
    aMatrix.Reset();

    Slice aSlice = aMatrix.GetQuadA();
    Quint aQuintCorners = aSlice.GetQuintRight(0, 0);
    Quint aQuintCentersRight = aSlice.GetQuintRight(2, 1);

    aSlice.PrepareSlots();

    aSlice._Weave(aQuintCorners, aQuintCentersRight);


    Quint aQuintEdgeA = aSlice.GetQuintRight(1, 0);
    Quint aQuintEdgeB = aSlice.GetQuintRight(2, 0);

    aQuintEdgeA.Print();

    aSlice._RotB(aQuintEdgeA);
    aSlice._RotB(aQuintEdgeB);

    //aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
    aSlice.RealizeSlots();


    aMatrix.RecordStart();
    aMatrix.Paste(aSlice);
    aMatrix.RecordStop();

    aSlice.PrintRecipeFactory4x4("CastleA");

    printf("all done...\n");
    printf("all done...\n");
    
    */
    
    /*
     std::vector<std::string> aNameChunks;
    aNameChunks.push_back(pOpName);

    aFull.PrintHPP(aNameChunks);

    if (aMatrix.HasChange()) {
        aMatrix.RecordPrintFunction(pOpName, "", 0);
    }
    */
    
    /*
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
    */
    
    
    //MakeFull("FlipA", Op::kFlipA);
    //MakeFull("FlipB", Op::kFlipB);
    //MakeFull("FlipC", Op::kFlipC);
    //MakeFull("FlipD", Op::kFlipD);
    
    
    /*
    MakeFull("RotA", Op::kRotA);
    MakeFull("RotB", Op::kRotB);
    MakeFull("RotC", Op::kRotC);

    MakeFull("BlockRotA", Op::kBlockRotA);
    MakeFull("BlockRotB", Op::kBlockRotB);
    MakeFull("BlockRotC", Op::kBlockRotC);

    MakeFull("PylonRotA", Op::kPylonRotA);
    MakeFull("PylonRotB", Op::kPylonRotB);
    MakeFull("PylonRotC", Op::kPylonRotC);
    */
    
    // TryRotateRightQuadA();
    
    /*
    M88 aMatrix;
    aMatrix.Reset();

    Slice aQuadA = aMatrix.GetQuadA();

    if (aQuadA.Capable(Op::kRotateRight)) {
        aQuadA.Execute(Op::kRotateRight);
        
        aMatrix.RecordStart();
        aMatrix.Paste(aQuadA);
        aMatrix.RecordStop();
        
        if (aMatrix.HasChange()) {
            
            aMatrix.RecordPrintFunction("RotateRight", "Quad", 0);
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
    
    std::printf("// Generated by GenerateTwistMatrixQuadSelects.cpp\n");
    std::printf("// Unique 4-tile picks inside a 4x4 Quad.\n");
    std::printf("// Count: %zu\n\n", picks.size());
    
    std::printf("#ifndef TwistMatrixQuadSelects_hpp\n");
    std::printf("#define TwistMatrixQuadSelects_hpp\n\n");
    std::printf("#include <cstdint>\n\n");
    
    std::printf("class TwistMatrixQuadSelects {\n");
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
    std::printf("#endif /* TwistMatrixQuadSelects_hpp */\n");
    
    
    
    
    /*
    {
        M88 aMatrix;
        aMatrix.Reset();
        Slice aSlice = aMatrix.GetQuadA();
        Quint aQuintCorners = aSlice.GetQuintRight(0, 0);
        Quint aQuintCentersRight = aSlice.GetQuintRight(2, 1);
        aSlice.PrepareSlots();
        aSlice._Weave(aQuintCorners, aQuintCentersRight);
        Quint aQuintEdgeA = aSlice.GetQuintRight(1, 0);
        Quint aQuintEdgeB = aSlice.GetQuintRight(2, 0);
        aQuintEdgeA.Print();
        aSlice._RotB(aQuintEdgeA);
        aSlice._RotB(aQuintEdgeB);
        
        //aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
        aSlice.RealizeSlots();
        aMatrix.RecordStart();
        aMatrix.Paste(aSlice);
        aMatrix.RecordStop();
        
        aSlice.PrintRecipeFactory4x4("CastleA");
        
    }
    {
        M88 aMatrix;
        aMatrix.Reset();
        Slice aSlice = aMatrix.GetQuadA();
        Quint aQuintCorners = aSlice.GetQuintRight(0, 0);
        Quint aQuintCentersRight = aSlice.GetQuintRight(1, 2);
        aSlice.PrepareSlots();
        aSlice._Weave(aQuintCorners, aQuintCentersRight);
        Quint aQuintEdgeA = aSlice.GetQuintRight(1, 0);
        Quint aQuintEdgeB = aSlice.GetQuintRight(2, 0);
        aQuintEdgeA.Print();
        aSlice._RotA(aQuintEdgeA);
        aSlice._RotA(aQuintEdgeB);
        
        //aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
        aSlice.RealizeSlots();
        aMatrix.RecordStart();
        aMatrix.Paste(aSlice);
        aMatrix.RecordStop();
        
        aSlice.PrintRecipeFactory4x4("CastleB");
        
    }
    
    {
        M88 aMatrix;
        aMatrix.Reset();
        Slice aSlice = aMatrix.GetQuadA();
        Quint aQuintCorners = aSlice.GetQuintRight(0, 0);
        Quint aQuintCentersRight = aSlice.GetQuintRight(2, 2);
        aSlice.PrepareSlots();
        aSlice._Weave(aQuintCorners, aQuintCentersRight);
        Quint aQuintEdgeA = aSlice.GetQuintRight(1, 0);
        Quint aQuintEdgeB = aSlice.GetQuintRight(2, 0);
        aQuintEdgeA.Print();
        aSlice._RotB(aQuintEdgeA);
        aSlice._RotB(aQuintEdgeB);
        
        aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
        
        aSlice.RealizeSlots();
        aMatrix.RecordStart();
        aMatrix.Paste(aSlice);
        aMatrix.RecordStop();
        
        aSlice.PrintRecipeFactory4x4("CastleC");
        
    }
    
    {
        M88 aMatrix;
        aMatrix.Reset();
        Slice aSlice = aMatrix.GetQuadA();
        Quint aQuintCorners = aSlice.GetQuintRight(0, 0);
        Quint aQuintCentersRight = aSlice.GetQuintRight(1, 1);
        aSlice.PrepareSlots();
        aSlice._Weave(aQuintCorners, aQuintCentersRight);
        Quint aQuintEdgeA = aSlice.GetQuintRight(1, 0);
        Quint aQuintEdgeB = aSlice.GetQuintRight(2, 0);
        aQuintEdgeA.Print();
        aSlice._RotA(aQuintEdgeA);
        aSlice._RotA(aQuintEdgeB);
        
        aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
        aSlice.RealizeSlots();
        aMatrix.RecordStart();
        aMatrix.Paste(aSlice);
        aMatrix.RecordStop();
        
        aSlice.PrintRecipeFactory4x4("CastleD");
        
    }
    
    {
        M88 aMatrix;
        aMatrix.Reset();
        Slice aSlice = aMatrix.GetQuadA();
        Quint aQuintCorners = aSlice.GetQuintRight(1, 0);
        Quint aQuintCentersRight = aSlice.GetQuintRight(2, 1);
        aSlice.PrepareSlots();
        aSlice._Weave(aQuintCorners, aQuintCentersRight);
        Quint aQuintEdgeA = aSlice.GetQuintRight(0, 0);
        Quint aQuintEdgeB = aSlice.GetQuintRight(2, 0);
        aQuintEdgeA.Print();
        
        aSlice._RotA(aQuintEdgeA);
        aSlice._RotB(aQuintEdgeB);
        
        aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
        aSlice.RealizeSlots();
        aMatrix.RecordStart();
        aMatrix.Paste(aSlice);
        aMatrix.RecordStop();
        
        aSlice.PrintRecipeFactory4x4("TowerA");
        
    }
    
    {
        M88 aMatrix;
        aMatrix.Reset();
        Slice aSlice = aMatrix.GetQuadA();
        Quint aQuintCorners = aSlice.GetQuintRight(1, 0);
        Quint aQuintCentersRight = aSlice.GetQuintRight(1, 2);
        aSlice.PrepareSlots();
        aSlice._Weave(aQuintCorners, aQuintCentersRight);
        Quint aQuintEdgeA = aSlice.GetQuintRight(0, 0);
        Quint aQuintEdgeB = aSlice.GetQuintRight(2, 0);
        aQuintEdgeA.Print();
        
        aSlice._RotB(aQuintEdgeA);
        aSlice._RotA(aQuintEdgeB);
        
        aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
        aSlice.RealizeSlots();
        aMatrix.RecordStart();
        aMatrix.Paste(aSlice);
        aMatrix.RecordStop();
        
        aSlice.PrintRecipeFactory4x4("TowerB");
        
    }
    
    
    {
        M88 aMatrix;
        aMatrix.Reset();
        Slice aSlice = aMatrix.GetQuadA();
        Quint aQuintCorners = aSlice.GetQuintRight(1, 0);
        Quint aQuintCentersRight = aSlice.GetQuintRight(2, 2);
        aSlice.PrepareSlots();
        aSlice._Weave(aQuintCorners, aQuintCentersRight);
        Quint aQuintEdgeA = aSlice.GetQuintRight(0, 0);
        Quint aQuintEdgeB = aSlice.GetQuintRight(2, 0);
        aQuintEdgeA.Print();
        
        aSlice._RotA(aQuintEdgeA);
        aSlice._RotB(aQuintEdgeB);
        
        //aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
        aSlice.RealizeSlots();
        aMatrix.RecordStart();
        aMatrix.Paste(aSlice);
        aMatrix.RecordStop();
        
        aSlice.PrintRecipeFactory4x4("TowerC");
        
    }
    
    {
        M88 aMatrix;
        aMatrix.Reset();
        Slice aSlice = aMatrix.GetQuadA();
        Quint aQuintCorners = aSlice.GetQuintRight(1, 0);
        Quint aQuintCentersRight = aSlice.GetQuintRight(1, 1);
        aSlice.PrepareSlots();
        aSlice._Weave(aQuintCorners, aQuintCentersRight);
        Quint aQuintEdgeA = aSlice.GetQuintRight(0, 0);
        Quint aQuintEdgeB = aSlice.GetQuintRight(2, 0);
        aQuintEdgeA.Print();
        
        aSlice._RotB(aQuintEdgeA);
        aSlice._RotA(aQuintEdgeB);
        
        //aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
        aSlice.RealizeSlots();
        aMatrix.RecordStart();
        aMatrix.Paste(aSlice);
        aMatrix.RecordStop();
        
        aSlice.PrintRecipeFactory4x4("TowerD");
        
    }
    
    
    {
        M88 aMatrix;
        aMatrix.Reset();
        Slice aSlice = aMatrix.GetQuadA();
        Quint aQuintCorners = aSlice.GetQuintRight(2, 0);
        Quint aQuintCentersRight = aSlice.GetQuintRight(2, 2);
        aSlice.PrepareSlots();
        aSlice._Weave(aQuintCorners, aQuintCentersRight);
        
        
        Quint aQuintEdgeA = aSlice.GetQuintRight(0, 0);
        Quint aQuintEdgeB = aSlice.GetQuintRight(1, 0);
        aQuintEdgeA.Print();
        
        aSlice._RotC(aQuintEdgeA);
        aSlice._RotC(aQuintEdgeB);
        
        aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
        aSlice.RealizeSlots();
        aMatrix.RecordStart();
        aMatrix.Paste(aSlice);
        aMatrix.RecordStop();
        
        aSlice.PrintRecipeFactory4x4("FortressA");
        
    }
    
    {
        M88 aMatrix;
        aMatrix.Reset();
        Slice aSlice = aMatrix.GetQuadA();
        Quint aQuintCorners = aSlice.GetQuintRight(2, 0);
        Quint aQuintCentersRight = aSlice.GetQuintRight(1, 1);
        aSlice.PrepareSlots();
        aSlice._Weave(aQuintCorners, aQuintCentersRight);
        
        
        Quint aQuintEdgeA = aSlice.GetQuintRight(0, 0);
        Quint aQuintEdgeB = aSlice.GetQuintRight(1, 0);
        aQuintEdgeA.Print();
        
        aSlice._RotC(aQuintEdgeA);
        aSlice._RotC(aQuintEdgeB);
        
        //aSlice._Weave(aQuintEdgeA, aQuintEdgeB);
        
        aSlice.RealizeSlots();
        aMatrix.RecordStart();
        aMatrix.Paste(aSlice);
        aMatrix.RecordStop();
        
        aSlice.PrintRecipeFactory4x4("FortressB");
        
    }
     
    */
    
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}


@end

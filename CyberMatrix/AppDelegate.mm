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

#include "TestFileExporter4x4And8x8.hpp"


#include "UniqueQuarterTool.hpp"
#include "PrintRecipeTool.hpp"

#include "RecipeExporterQuadAndFull.hpp"

struct SliceRecipePrintEntry {
    std::string mName;
    void (Slice::*mFunctionA)();
    void (Slice::*mFunctionB)();
};


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

const std::vector<PrintRecipeToolEntry> aEntries = {

    { "WizardA", { &Slice::_SwapAD, &Slice::_HexA, &Slice::_SwapTallQuartersA, &Slice::_ShearA, &Slice::_RotA, &Slice::_FlipB, &Slice::_RotC, &Slice::_HexB, &Slice::_FlipA } },
    { "WizardB", { &Slice::_SwapAD, &Slice::_HexA, &Slice::_SwapTallQuartersA, &Slice::_ShearB, &Slice::_RotA, &Slice::_FlipB, &Slice::_RotC, &Slice::_HexB, &Slice::_FlipA } },
    { "WizardC", { &Slice::_SwapAD, &Slice::_HexA, &Slice::_SwapTallQuartersA, &Slice::_ShearC, &Slice::_RotA, &Slice::_FlipB, &Slice::_HexB, &Slice::_FlipA } },
    { "WizardD", { &Slice::_SwapAD, &Slice::_HexA, &Slice::_SwapTallQuartersA, &Slice::_ShearD, &Slice::_RotA, &Slice::_FlipB, &Slice::_HexB, &Slice::_FlipA } },

};

@interface AppDelegate ()

@property (strong) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
    //
    //
    
    //TestFileExporter4x4And8x8::Export("tests/_Falcon", RecipeFactory4x4::FalconD(), RecipeFactory8x8::FalconD());
    
    
    /*
    RecipeExporterQuadAndFull::Export({
        { RecipeFactory4x4::WizardA(), RecipeFactory8x8::WizardA() },
        { RecipeFactory4x4::WizardB(), RecipeFactory8x8::WizardB() },
        { RecipeFactory4x4::WizardC(), RecipeFactory8x8::WizardC() },
        { RecipeFactory4x4::WizardD(), RecipeFactory8x8::WizardD() },
    });
    */
    
    //UniqueQuarterTool::PrintCompareCandidates();
    
    //UniqueQuarterTool::PrintCompareExistingOpsToEachOther();
    
    //return;
    
    //return;
    
    //UniqueQuarterTool::PrintCompareCandidates();
    
    //return;
    
    //PrintRecipeTool::PrintRecipeFactories(aEntries);
    
    //return;
    
    /*
    RecipeExporterQuadAndFull::Export({
        { RecipeFactory4x4::GlendaleA(),  RecipeFactory8x8::GlendaleA() },
        { RecipeFactory4x4::GlendaleB(),  RecipeFactory8x8::GlendaleB() },
        { RecipeFactory4x4::GlendaleC(),  RecipeFactory8x8::GlendaleC() },
        { RecipeFactory4x4::GlendaleD(),  RecipeFactory8x8::GlendaleD() },

        { RecipeFactory4x4::BurbankA(),   RecipeFactory8x8::BurbankA() },
        { RecipeFactory4x4::BurbankB(),   RecipeFactory8x8::BurbankB() },
        { RecipeFactory4x4::BurbankC(),   RecipeFactory8x8::BurbankC() },
        { RecipeFactory4x4::BurbankD(),   RecipeFactory8x8::BurbankD() },

        { RecipeFactory4x4::InglewoodA(), RecipeFactory8x8::InglewoodA() },
        { RecipeFactory4x4::InglewoodB(), RecipeFactory8x8::InglewoodB() },
        { RecipeFactory4x4::InglewoodC(), RecipeFactory8x8::InglewoodC() },
        { RecipeFactory4x4::InglewoodD(), RecipeFactory8x8::InglewoodD() },

        { RecipeFactory4x4::PasadenaA(),  RecipeFactory8x8::PasadenaA() },
        { RecipeFactory4x4::PasadenaB(),  RecipeFactory8x8::PasadenaB() },
        { RecipeFactory4x4::PasadenaC(),  RecipeFactory8x8::PasadenaC() },
        { RecipeFactory4x4::PasadenaD(),  RecipeFactory8x8::PasadenaD() },

        { RecipeFactory4x4::TorranceA(),  RecipeFactory8x8::TorranceA() },
        { RecipeFactory4x4::TorranceB(),  RecipeFactory8x8::TorranceB() },
        { RecipeFactory4x4::TorranceC(),  RecipeFactory8x8::TorranceC() },
        { RecipeFactory4x4::TorranceD(),  RecipeFactory8x8::TorranceD() },

        { RecipeFactory4x4::HawthorneA(), RecipeFactory8x8::HawthorneA() },
        { RecipeFactory4x4::HawthorneB(), RecipeFactory8x8::HawthorneB() },
        { RecipeFactory4x4::HawthorneC(), RecipeFactory8x8::HawthorneC() },
        { RecipeFactory4x4::HawthorneD(), RecipeFactory8x8::HawthorneD() }
    });
    
    return;
    
    */
    
    
    
    /*
    RecipeExporterQuadAndFull::Export({
        { RecipeFactory4x4::HeronA(),  RecipeFactory8x8::HeronA() },
        { RecipeFactory4x4::HeronB(),  RecipeFactory8x8::HeronB() },
        { RecipeFactory4x4::HeronC(),  RecipeFactory8x8::HeronC() },
        { RecipeFactory4x4::HeronD(),  RecipeFactory8x8::HeronD() },

        { RecipeFactory4x4::FalconA(), RecipeFactory8x8::FalconA() },
        { RecipeFactory4x4::FalconB(), RecipeFactory8x8::FalconB() },
        { RecipeFactory4x4::FalconC(), RecipeFactory8x8::FalconC() },
        { RecipeFactory4x4::FalconD(), RecipeFactory8x8::FalconD() }
    });
    */
    
    //
    //
    //
    
    
    //
    
    
    //TestFileExporter4x4And8x8::Export(RecipeFactory4x4::GooseD(), RecipeFactory8x8::GooseD());
    //return;
    
    
    //RecipeExporter4x4::Export(RecipeFactory4x4::SwanA());
    //RecipeExporter8x8::Export(RecipeFactory8x8::SwanA());
    
    //UniqueQuarterTool::PrintCompareExistingOpsToEachOther();
    
    /*
    RecipeExporterQuadAndFull::Export({
        { RecipeFactory4x4::SwanA(),  RecipeFactory8x8::SwanA() },
        { RecipeFactory4x4::SwanB(),  RecipeFactory8x8::SwanB() },
        { RecipeFactory4x4::SwanC(),  RecipeFactory8x8::SwanC() },
        { RecipeFactory4x4::SwanD(),  RecipeFactory8x8::SwanD() },

        { RecipeFactory4x4::GooseA(), RecipeFactory8x8::GooseA() },
        { RecipeFactory4x4::GooseB(), RecipeFactory8x8::GooseB() },
        { RecipeFactory4x4::GooseC(), RecipeFactory8x8::GooseC() },
        { RecipeFactory4x4::GooseD(), RecipeFactory8x8::GooseD() }
    });
    */
    
    
    
    //RecipeExporter4x4::Export(RecipeFactory4x4::PeridotD());
    //TestExporter4x4::Export(RecipeFactory4x4::CrystalA());
    
    
    //DebugCandidateAIdentity();
    //printf("?");
    
    //RecipeExporter8x8::Export(RecipeFactory8x8::PeridotD());
    //TestExporter8x8::Export(RecipeFactory8x8::JewelA());
    
    
    //PrintRecipeTool::PrintRecipeFactories(aEntries);
    
    
    //UniqueQuarterTool::PrintCompareCandidates();
    
    
    //return;
    


    
    //RecipeExporter2x2::Export(RecipeFactory2x2::SwapD());
    //TestExporter2x2::Export(RecipeFactory2x2::SwapD());
    
    //RecipeExporter4x4::Export(RecipeFactory4x4::FoldD());
    //TestExporter4x4::Export(RecipeFactory4x4::PeridotA());
    
    //RecipeExporter8x8::Export(RecipeFactory8x8::ShearD());
    //TestExporter8x8::Export(RecipeFactory8x8::PeridotB());
    
    /*
    TestFileExporter4x4And8x8::Export(RecipeFactory4x4::JewelD(),
                                      RecipeFactory8x8::JewelD());
    */
    
    //TestUniqueMatrix();
    
    
    /*
    const std::string aName = "NameA";
    void (Slice::*aFunctionA)() = &Slice::_Identity;
    void (Slice::*aFunctionB)() = &Slice::_RotA;

    M88 aMatrix;

    aMatrix.Reset();
    Slice aSliceA = aMatrix.GetQuadA();
    aSliceA.PrepareSlots();
    (aSliceA.*aFunctionA)();
    (aSliceA.*aFunctionB)();
    aSliceA.RealizeSlots();
    aMatrix.RecordStart();
    aMatrix.Paste(aSliceA);
    aMatrix.RecordStop();
    aSliceA.PrintRecipeFactory4x4(aName);

    aMatrix.Reset();
    Slice aSliceB = aMatrix.GetFull();
    aSliceB.PrepareSlots();
    (aSliceB.*aFunctionA)();
    (aSliceB.*aFunctionB)();
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

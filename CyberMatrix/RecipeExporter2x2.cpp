//
//  RecipeExporter2x2.cpp
//  CyberMatrix
//

#include "RecipeExporter2x2.hpp"

#include <cstdio>
#include <string>
#include <vector>

#include "M88.hpp"
#include "M88Slice.hpp"

char RecipeExporter2x2::Letter(int pIndex) {
    return static_cast<char>('A' + pIndex);
}

void RecipeExporter2x2::PrintHPPFunction(const char *pFunctionName) {
    std::printf("    void                                        %s();\n",
                pFunctionName);
}

void RecipeExporter2x2::Export(const Recipe2x2 &pRecipe) {
    std::printf("// ============================================================\n");
    std::printf("// %s 2x2 family\n", pRecipe.mName);
    std::printf("// ============================================================\n\n");

    std::printf("// ---------- HPP ----------\n");
    ExportHPP(pRecipe);

    std::printf("\n// ---------- CPP ----------\n");
    ExportCPP(pRecipe);
}

void RecipeExporter2x2::ExportHPP(const Recipe2x2 &pRecipe) {
    ExportFullHPP(pRecipe);
    ExportRepeatedHPP(pRecipe);
    ExportQuadHPP(pRecipe);
    ExportMiniHPP(pRecipe);
}

void RecipeExporter2x2::ExportCPP(const Recipe2x2 &pRecipe) {
    ExportFullCPP(pRecipe);
    ExportRepeatedCPP(pRecipe);
    ExportQuadCPP(pRecipe);
    ExportMiniCPP(pRecipe);
}

void RecipeExporter2x2::ExportFullHPP(const Recipe2x2 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_2x2";
    PrintHPPFunction(aName.c_str());
}

void RecipeExporter2x2::ExportRepeatedHPP(const Recipe2x2 &pRecipe) {
    {
        std::string aName = "Full_";
        aName += pRecipe.mName;
        aName += "_EachQuad_2x2";
        PrintHPPFunction(aName.c_str());
    }

    {
        std::string aName = "Full_";
        aName += pRecipe.mName;
        aName += "_EachMini_2x2";
        PrintHPPFunction(aName.c_str());
    }

    for (int i = 0; i < 4; i++) {
        std::string aName = "Quad_";
        aName += pRecipe.mName;
        aName += "_EachMini_2x2_";
        aName += Letter(i);
        PrintHPPFunction(aName.c_str());
    }
}

void RecipeExporter2x2::ExportQuadHPP(const Recipe2x2 &pRecipe) {
    for (int i = 0; i < 4; i++) {
        std::string aName = "Quad_";
        aName += pRecipe.mName;
        aName += "_2x2_";
        aName += Letter(i);
        PrintHPPFunction(aName.c_str());
    }
}

void RecipeExporter2x2::ExportMiniHPP(const Recipe2x2 &pRecipe) {
    for (int i = 0; i < 16; i++) {
        std::string aName = "Mini_";
        aName += pRecipe.mName;
        aName += "_2x2_";
        aName += Letter(i);
        PrintHPPFunction(aName.c_str());
    }
}

void RecipeExporter2x2::ExportOneCPP(const Recipe2x2 &pRecipe,
                                      const char *pFunctionName,
                                      int pRegionKind,
                                      int pRegionIndex) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aSlice;

    if (pRegionKind == 0) {
        aSlice = aMatrix.GetFull();
    } else if (pRegionKind == 1) {
        aSlice = aMatrix.GetQuad(pRegionIndex);
    } else {
        aSlice = aMatrix.GetMini(pRegionIndex);
    }

    aSlice.PrepareSlots();
    aSlice._ApplyBlockMap2x2(pRecipe.mMap);
    aSlice.RealizeSlots();

    aMatrix.RecordStart();
    aMatrix.Paste(aSlice);
    aMatrix.RecordStop();

    std::vector<std::string> aNameChunks;
    aNameChunks.push_back(pFunctionName);

    aSlice.PrintCPP(aNameChunks);
}

void RecipeExporter2x2::ExportFullCPP(const Recipe2x2 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_2x2";

    ExportOneCPP(pRecipe, aName.c_str(), 0, 0);
}

void RecipeExporter2x2::ExportQuadCPP(const Recipe2x2 &pRecipe) {
    for (int i = 0; i < 4; i++) {
        std::string aName = "Quad_";
        aName += pRecipe.mName;
        aName += "_2x2_";
        aName += Letter(i);

        ExportOneCPP(pRecipe, aName.c_str(), 1, i);
    }
}

void RecipeExporter2x2::ExportMiniCPP(const Recipe2x2 &pRecipe) {
    for (int i = 0; i < 16; i++) {
        std::string aName = "Mini_";
        aName += pRecipe.mName;
        aName += "_2x2_";
        aName += Letter(i);

        ExportOneCPP(pRecipe, aName.c_str(), 2, i);
    }
}


void RecipeExporter2x2::ExportRepeatedCPP(const Recipe2x2 &pRecipe) {
    {
        std::string aName = "Full_";
        aName += pRecipe.mName;
        aName += "_EachQuad_2x2";

        std::printf("void M88::%s() {\n", aName.c_str());
        for (int i = 0; i < 4; i++) {
            std::printf("    Quad_%s_2x2_%c();\n",
                        pRecipe.mName,
                        Letter(i));
        }
        std::printf("}\n\n");
    }

    {
        std::string aName = "Full_";
        aName += pRecipe.mName;
        aName += "_EachMini_2x2";

        std::printf("void M88::%s() {\n", aName.c_str());
        for (int i = 0; i < 16; i++) {
            std::printf("    Mini_%s_2x2_%c();\n",
                        pRecipe.mName,
                        Letter(i));
        }
        std::printf("}\n\n");
    }

    static const int kQuadMini[4][4] = {
        {  0,  1,  4,  5 },   // Quad A: A B E F
        {  2,  3,  6,  7 },   // Quad B: C D G H
        {  8,  9, 12, 13 },   // Quad C: I J M N
        { 10, 11, 14, 15 }    // Quad D: K L O P
    };

    for (int q = 0; q < 4; q++) {
        std::string aName = "Quad_";
        aName += pRecipe.mName;
        aName += "_EachMini_2x2_";
        aName += Letter(q);

        std::printf("void M88::%s() {\n", aName.c_str());

        for (int i = 0; i < 4; i++) {
            std::printf("    Mini_%s_2x2_%c();\n",
                        pRecipe.mName,
                        Letter(kQuadMini[q][i]));
        }

        std::printf("}\n\n");
    }
}



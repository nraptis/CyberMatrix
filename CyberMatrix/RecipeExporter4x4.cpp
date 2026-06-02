//
//  RecipeExporter4x4.cpp
//  CyberMatrix
//

#include "RecipeExporter4x4.hpp"

#include <cstdio>
#include <string>
#include <vector>

#include "M88.hpp"
#include "M88Slice.hpp"

char RecipeExporter4x4::Letter(int pIndex) {
    return static_cast<char>('A' + pIndex);
}

void RecipeExporter4x4::PrintHPPFunction(const char *pFunctionName) {
    std::printf("    void                                        %s();\n",
                pFunctionName);
}

void RecipeExporter4x4::Export(const Recipe4x4 &pRecipe) {
    std::printf("// ============================================================\n");
    std::printf("// %s 4x4 family\n", pRecipe.mName);
    std::printf("// ============================================================\n\n");

    std::printf("// ---------- HPP ----------\n");
    ExportHPP(pRecipe);

    std::printf("\n// ---------- CPP ----------\n");
    ExportCPP(pRecipe);
}

void RecipeExporter4x4::ExportHPP(const Recipe4x4 &pRecipe) {
    ExportFullHPP(pRecipe);
    ExportRepeatedHPP(pRecipe);
    ExportQuadHPP(pRecipe);
}

void RecipeExporter4x4::ExportCPP(const Recipe4x4 &pRecipe) {
    ExportFullCPP(pRecipe);
    ExportRepeatedCPP(pRecipe);
    ExportQuadCPP(pRecipe);
}

void RecipeExporter4x4::ExportFullHPP(const Recipe4x4 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_4x4";

    PrintHPPFunction(aName.c_str());
}

void RecipeExporter4x4::ExportRepeatedHPP(const Recipe4x4 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_EachQuad_4x4";

    PrintHPPFunction(aName.c_str());
}

void RecipeExporter4x4::ExportQuadHPP(const Recipe4x4 &pRecipe) {
    for (int i = 0; i < 4; i++) {
        std::string aName = "Quad_";
        aName += pRecipe.mName;
        aName += "_4x4_";
        aName += Letter(i);

        PrintHPPFunction(aName.c_str());
    }
}

void RecipeExporter4x4::ExportOneCPP(const Recipe4x4 &pRecipe,
                                      const char *pFunctionName,
                                      int pRegionKind,
                                      int pRegionIndex) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aSlice;

    if (pRegionKind == 0) {
        aSlice = aMatrix.GetFull();
    } else {
        aSlice = aMatrix.GetQuad(pRegionIndex);
    }

    aSlice.PrepareSlots();
    aSlice._ApplyBlockMap4x4(pRecipe.mMap);
    aSlice.RealizeSlots();

    aMatrix.RecordStart();
    aMatrix.Paste(aSlice);
    aMatrix.RecordStop();

    std::vector<std::string> aNameChunks;
    aNameChunks.push_back(pFunctionName);

    aSlice.PrintCPP(aNameChunks);
}

void RecipeExporter4x4::ExportFullCPP(const Recipe4x4 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_4x4";

    ExportOneCPP(pRecipe, aName.c_str(), 0, 0);
}

void RecipeExporter4x4::ExportQuadCPP(const Recipe4x4 &pRecipe) {
    for (int i = 0; i < 4; i++) {
        std::string aName = "Quad_";
        aName += pRecipe.mName;
        aName += "_4x4_";
        aName += Letter(i);

        ExportOneCPP(pRecipe, aName.c_str(), 1, i);
    }
}

void RecipeExporter4x4::ExportRepeatedCPP(const Recipe4x4 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_EachQuad_4x4";

    std::printf("void M88::%s() {\n", aName.c_str());

    for (int i = 0; i < 4; i++) {
        std::printf("    Quad_%s_4x4_%c();\n",
                    pRecipe.mName,
                    Letter(i));
    }

    std::printf("}\n\n");
}


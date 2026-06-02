//
//  RecipeExporter8x8.cpp
//  CyberMatrix
//

#include "RecipeExporter8x8.hpp"

#include <cstdio>
#include <string>
#include <vector>

#include "M88.hpp"
#include "M88Slice.hpp"

void RecipeExporter8x8::PrintHPPFunction(const char *pFunctionName) {
    std::printf("    void                                        %s();\n",
                pFunctionName);
}

void RecipeExporter8x8::Export(const Recipe8x8 &pRecipe) {
    std::printf("// ============================================================\n");
    std::printf("// %s 8x8 family\n", pRecipe.mName);
    std::printf("// ============================================================\n\n");

    std::printf("// ---------- HPP ----------\n");
    ExportHPP(pRecipe);

    std::printf("\n// ---------- CPP ----------\n");
    ExportCPP(pRecipe);
}

void RecipeExporter8x8::ExportHPP(const Recipe8x8 &pRecipe) {
    ExportFullHPP(pRecipe);
}

void RecipeExporter8x8::ExportCPP(const Recipe8x8 &pRecipe) {
    ExportFullCPP(pRecipe);
}

void RecipeExporter8x8::ExportFullHPP(const Recipe8x8 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_8x8";

    PrintHPPFunction(aName.c_str());
}

void RecipeExporter8x8::ExportFullCPP(const Recipe8x8 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_8x8";

    ExportOneCPP(pRecipe, aName.c_str());
}

void RecipeExporter8x8::ExportOneCPP(const Recipe8x8 &pRecipe,
                                      const char *pFunctionName) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aSlice = aMatrix.GetFull();

    aSlice.PrepareSlots();
    aSlice._ApplyBlockMap8x8(pRecipe.mMap);
    aSlice.RealizeSlots();

    aMatrix.RecordStart();
    aMatrix.Paste(aSlice);
    aMatrix.RecordStop();

    std::vector<std::string> aNameChunks;
    aNameChunks.push_back(pFunctionName);

    aSlice.PrintCPP(aNameChunks);
}

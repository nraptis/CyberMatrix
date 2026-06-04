//
//  RecipeExporter8x8.cpp
//  CyberMatrix
//

#include "RecipeExporter8x8.hpp"

#include <cstdio>
#include <string>
#include <vector>
#include <sstream>

#include "M88.hpp"
#include "M88Slice.hpp"

void RecipeExporter8x8::PrintHPPFunction(const char *pFunctionName) {
    std::printf("%s", BuildHPPFunction(pFunctionName).c_str());
}

void RecipeExporter8x8::Export(const Recipe8x8 &pRecipe) {
    std::printf("// ============================================================\n");
    std::printf("// %s 8x8 family\n", pRecipe.mName);
    std::printf("// ============================================================\n\n");

    std::printf("// ---------- HPP ----------\n");
    std::printf("%s", BuildHPP(pRecipe).c_str());

    std::printf("\n// ---------- CPP ----------\n");
    std::printf("%s", BuildCPP(pRecipe).c_str());
}

void RecipeExporter8x8::ExportHPP(const Recipe8x8 &pRecipe) {
    std::printf("%s", BuildHPP(pRecipe).c_str());
}

void RecipeExporter8x8::ExportCPP(const Recipe8x8 &pRecipe) {
    std::printf("%s", BuildCPP(pRecipe).c_str());
}

void RecipeExporter8x8::ExportFullHPP(const Recipe8x8 &pRecipe) {
    std::printf("%s", BuildFullHPP(pRecipe).c_str());
}

void RecipeExporter8x8::ExportFullCPP(const Recipe8x8 &pRecipe) {
    std::printf("%s", BuildFullCPP(pRecipe).c_str());
}

void RecipeExporter8x8::ExportOneCPP(const Recipe8x8 &pRecipe,
                                      const char *pFunctionName) {
    std::printf("%s", BuildOneCPP(pRecipe, pFunctionName).c_str());
}

std::string RecipeExporter8x8::BuildHPPFunction(const char *pFunctionName) {
    std::ostringstream aStream;

    aStream << "    void                                        "
            << pFunctionName
            << "();\n";

    return aStream.str();
}

std::string RecipeExporter8x8::BuildHPP(const Recipe8x8 &pRecipe) {
    return BuildFullHPP(pRecipe);
}

std::string RecipeExporter8x8::BuildCPP(const Recipe8x8 &pRecipe) {
    return BuildFullCPP(pRecipe);
}

std::string RecipeExporter8x8::BuildFullHPP(const Recipe8x8 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_8x8";

    return BuildHPPFunction(aName.c_str());
}

std::string RecipeExporter8x8::BuildFullCPP(const Recipe8x8 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_8x8";

    return BuildOneCPP(pRecipe, aName.c_str());
}

std::string RecipeExporter8x8::BuildOneCPP(const Recipe8x8 &pRecipe,
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

    return aSlice.BuildCPP(aNameChunks);
}

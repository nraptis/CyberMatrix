//
//  RecipeExporter4x4.cpp
//  CyberMatrix
//

#include "RecipeExporter4x4.hpp"

#include <cstdio>
#include <string>
#include <vector>
#include <sstream>

#include "M88.hpp"
#include "M88Slice.hpp"

char RecipeExporter4x4::Letter(int pIndex) {
    return static_cast<char>('A' + pIndex);
}

void RecipeExporter4x4::PrintHPPFunction(const char *pFunctionName) {
    const std::string aText = BuildHPPFunction(pFunctionName);
    std::printf("%s", aText.c_str());
}

void RecipeExporter4x4::Export(const Recipe4x4 &pRecipe) {
    std::printf("// ============================================================\n");
    std::printf("// %s 4x4 family\n", pRecipe.mName);
    std::printf("// ============================================================\n\n");

    std::printf("// ---------- HPP ----------\n");
    std::printf("%s", BuildHPP(pRecipe).c_str());

    std::printf("\n// ---------- CPP ----------\n");
    std::printf("%s", BuildCPP(pRecipe).c_str());
}

void RecipeExporter4x4::ExportHPP(const Recipe4x4 &pRecipe) {
    std::printf("%s", BuildHPP(pRecipe).c_str());
}

void RecipeExporter4x4::ExportCPP(const Recipe4x4 &pRecipe) {
    std::printf("%s", BuildCPP(pRecipe).c_str());
}

void RecipeExporter4x4::ExportFullHPP(const Recipe4x4 &pRecipe) {
    std::printf("%s", BuildFullHPP(pRecipe).c_str());
}

void RecipeExporter4x4::ExportRepeatedHPP(const Recipe4x4 &pRecipe) {
    std::printf("%s", BuildRepeatedHPP(pRecipe).c_str());
}


void RecipeExporter4x4::ExportQuadHPP(const Recipe4x4 &pRecipe) {
    std::printf("%s", BuildQuadHPP(pRecipe).c_str());
}

void RecipeExporter4x4::ExportFullCPP(const Recipe4x4 &pRecipe) {
    std::printf("%s", BuildFullCPP(pRecipe).c_str());
}

void RecipeExporter4x4::ExportQuadCPP(const Recipe4x4 &pRecipe) {
    std::printf("%s", BuildQuadCPP(pRecipe).c_str());
}

void RecipeExporter4x4::ExportRepeatedCPP(const Recipe4x4 &pRecipe) {
    std::printf("%s", BuildRepeatedCPP(pRecipe).c_str());
}

void RecipeExporter4x4::ExportOneCPP(const Recipe4x4 &pRecipe,
                                      const char *pFunctionName,
                                      int pRegionKind,
                                      int pRegionIndex) {
    std::printf("%s",
                BuildOneCPP(pRecipe,
                            pFunctionName,
                            pRegionKind,
                            pRegionIndex).c_str());
}

std::string RecipeExporter4x4::BuildHPPFunction(const char *pFunctionName) {
    std::ostringstream aStream;

    aStream << "    void                                        "
            << pFunctionName
            << "();\n";

    return aStream.str();
}

std::string RecipeExporter4x4::BuildHPP(const Recipe4x4 &pRecipe) {
    std::ostringstream aStream;

    aStream << BuildFullHPP(pRecipe);
    aStream << BuildRepeatedHPP(pRecipe);
    aStream << BuildQuadHPP(pRecipe);

    return aStream.str();
}

std::string RecipeExporter4x4::BuildCPP(const Recipe4x4 &pRecipe) {
    std::ostringstream aStream;

    aStream << BuildFullCPP(pRecipe);
    aStream << BuildRepeatedCPP(pRecipe);
    aStream << BuildQuadCPP(pRecipe);

    return aStream.str();
}

std::string RecipeExporter4x4::BuildFullHPP(const Recipe4x4 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_4x4";

    return BuildHPPFunction(aName.c_str());
}

std::string RecipeExporter4x4::BuildRepeatedHPP(const Recipe4x4 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_EachQuad_4x4";

    return BuildHPPFunction(aName.c_str());
}

std::string RecipeExporter4x4::BuildQuadHPP(const Recipe4x4 &pRecipe) {
    std::ostringstream aStream;

    for (int i = 0; i < 4; i++) {
        std::string aName = "Quad_";
        aName += pRecipe.mName;
        aName += "_4x4_";
        aName += Letter(i);

        aStream << BuildHPPFunction(aName.c_str());
    }

    return aStream.str();
}

std::string RecipeExporter4x4::BuildOneCPP(const Recipe4x4 &pRecipe,
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

    return aSlice.BuildCPP(aNameChunks);
}

std::string RecipeExporter4x4::BuildFullCPP(const Recipe4x4 &pRecipe) {
    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_4x4";

    return BuildOneCPP(pRecipe, aName.c_str(), 0, 0);
}

std::string RecipeExporter4x4::BuildQuadCPP(const Recipe4x4 &pRecipe) {
    std::ostringstream aStream;

    for (int i = 0; i < 4; i++) {
        std::string aName = "Quad_";
        aName += pRecipe.mName;
        aName += "_4x4_";
        aName += Letter(i);

        aStream << BuildOneCPP(pRecipe, aName.c_str(), 1, i);
    }

    return aStream.str();
}

std::string RecipeExporter4x4::BuildRepeatedCPP(const Recipe4x4 &pRecipe) {
    std::ostringstream aStream;

    std::string aName = "Full_";
    aName += pRecipe.mName;
    aName += "_EachQuad_4x4";

    aStream << "void M88::" << aName << "() {\n";

    for (int i = 0; i < 4; i++) {
        aStream << "    Quad_"
                << pRecipe.mName
                << "_4x4_"
                << Letter(i)
                << "();\n";
    }

    aStream << "}\n\n";

    return aStream.str();
}

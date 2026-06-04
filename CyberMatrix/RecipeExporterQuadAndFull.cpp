//
//  RecipeExporterQuadAndFull.cpp
//  CyberMatrix
//

#include "RecipeExporterQuadAndFull.hpp"

#include "RecipeExporter4x4.hpp"
#include "RecipeExporter8x8.hpp"

#include <cstdio>
#include <sstream>

std::string RecipeExporterQuadAndFull::Build4x4HPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries) {
    std::ostringstream aStream;

    for (const RecipeExporterQuadAndFullEntry &aEntry : pEntries) {
        aStream << RecipeExporter4x4::BuildHPP(aEntry.mRecipe4x4);
    }

    return aStream.str();
}

std::string RecipeExporterQuadAndFull::Build8x8HPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries) {
    std::ostringstream aStream;

    for (const RecipeExporterQuadAndFullEntry &aEntry : pEntries) {
        aStream << RecipeExporter8x8::BuildHPP(aEntry.mRecipe8x8);
    }

    return aStream.str();
}

std::string RecipeExporterQuadAndFull::Build4x4CPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries) {
    std::ostringstream aStream;

    for (const RecipeExporterQuadAndFullEntry &aEntry : pEntries) {
        aStream << RecipeExporter4x4::BuildCPP(aEntry.mRecipe4x4);
    }

    return aStream.str();
}

std::string RecipeExporterQuadAndFull::Build8x8CPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries) {
    std::ostringstream aStream;

    for (const RecipeExporterQuadAndFullEntry &aEntry : pEntries) {
        aStream << RecipeExporter8x8::BuildCPP(aEntry.mRecipe8x8);
    }

    return aStream.str();
}

std::string RecipeExporterQuadAndFull::BuildHPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries) {
    std::ostringstream aStream;

    aStream << "// ============================================================\n";
    aStream << "// 4x4 HPP\n";
    aStream << "// ============================================================\n\n";
    aStream << Build4x4HPP(pEntries);

    aStream << "\n";
    aStream << "// ============================================================\n";
    aStream << "// 8x8 HPP\n";
    aStream << "// ============================================================\n\n";
    aStream << Build8x8HPP(pEntries);

    return aStream.str();
}

std::string RecipeExporterQuadAndFull::BuildCPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries) {
    std::ostringstream aStream;

    aStream << "// ============================================================\n";
    aStream << "// 4x4 CPP\n";
    aStream << "// ============================================================\n\n";
    aStream << Build4x4CPP(pEntries);

    aStream << "\n";
    aStream << "// ============================================================\n";
    aStream << "// 8x8 CPP\n";
    aStream << "// ============================================================\n\n";
    aStream << Build8x8CPP(pEntries);

    return aStream.str();
}

std::string RecipeExporterQuadAndFull::Build(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries) {
    std::ostringstream aStream;

    aStream << BuildHPP(pEntries);
    aStream << "\n";
    aStream << BuildCPP(pEntries);

    return aStream.str();
}

void RecipeExporterQuadAndFull::Export(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries) {
    const std::string aText = Build(pEntries);
    std::printf("%s", aText.c_str());
}

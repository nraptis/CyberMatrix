//
//  RecipeExporterQuad.cpp
//  CyberMatrix
//

#include "RecipeExporterQuad.hpp"

#include "RecipeExporter4x4.hpp"

#include <cstdio>
#include <sstream>
#include <string>

std::string RecipeExporterQuad::BuildHPP(const std::vector<Recipe4x4> &pRecipes) {
    std::ostringstream aStream;

    for (const Recipe4x4 &aRecipe : pRecipes) {
        aStream << RecipeExporter4x4::BuildHPP(aRecipe);
    }

    return aStream.str();
}

std::string RecipeExporterQuad::BuildCPP(const std::vector<Recipe4x4> &pRecipes) {
    std::ostringstream aStream;

    for (const Recipe4x4 &aRecipe : pRecipes) {
        aStream << RecipeExporter4x4::BuildCPP(aRecipe);
    }

    return aStream.str();
}

std::string RecipeExporterQuad::Build(const std::vector<Recipe4x4> &pRecipes) {
    std::ostringstream aStream;

    aStream << "// ============================================================\n";
    aStream << "// 4x4 HPP\n";
    aStream << "// ============================================================\n\n";
    aStream << BuildHPP(pRecipes);

    aStream << "\n";
    aStream << "// ============================================================\n";
    aStream << "// 4x4 CPP\n";
    aStream << "// ============================================================\n\n";
    aStream << BuildCPP(pRecipes);

    return aStream.str();
}

void RecipeExporterQuad::Export(const std::vector<Recipe4x4> &pRecipes) {
    const std::string aText = Build(pRecipes);
    std::printf("%s", aText.c_str());
}

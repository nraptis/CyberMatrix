//
//  RecipeExporterQuad.hpp
//  CyberMatrix
//

#ifndef RecipeExporterQuad_hpp
#define RecipeExporterQuad_hpp

#include "RecipeFactory4x4.hpp"

#include <string>
#include <vector>

class RecipeExporterQuad {
public:

    static std::string BuildHPP(const std::vector<Recipe4x4> &pRecipes);
    static std::string BuildCPP(const std::vector<Recipe4x4> &pRecipes);
    static std::string Build(const std::vector<Recipe4x4> &pRecipes);

    static void Export(const std::vector<Recipe4x4> &pRecipes);
};

#endif /* RecipeExporterQuad_hpp */

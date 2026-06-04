//
//  RecipeExporterQuadAndFull.hpp
//  CyberMatrix
//

#ifndef RecipeExporterQuadAndFull_hpp
#define RecipeExporterQuadAndFull_hpp

#include "RecipeFactory4x4.hpp"
#include "RecipeFactory8x8.hpp"

#include <string>
#include <vector>

struct RecipeExporterQuadAndFullEntry {
    Recipe4x4 mRecipe4x4;
    Recipe8x8 mRecipe8x8;
};

class RecipeExporterQuadAndFull {
public:

    static std::string Build4x4HPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries);
    static std::string Build8x8HPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries);

    static std::string Build4x4CPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries);
    static std::string Build8x8CPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries);

    static std::string BuildHPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries);
    static std::string BuildCPP(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries);
    static std::string Build(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries);

    static void Export(const std::vector<RecipeExporterQuadAndFullEntry> &pEntries);
};

#endif /* RecipeExporterQuadAndFull_hpp */

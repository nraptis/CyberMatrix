//
//  RecipeExporter4x4.hpp
//  CyberMatrix
//

#ifndef RecipeExporter4x4_hpp
#define RecipeExporter4x4_hpp

#include "RecipeFactory4x4.hpp"
#include <string>
#include <vector>

class RecipeExporter4x4 {
public:
    static void Export(const Recipe4x4 &pRecipe);

    static void ExportHPP(const Recipe4x4 &pRecipe);
    static void ExportCPP(const Recipe4x4 &pRecipe);

    static void ExportFullHPP(const Recipe4x4 &pRecipe);
    static void ExportQuadHPP(const Recipe4x4 &pRecipe);
    static void ExportRepeatedHPP(const Recipe4x4 &pRecipe);

    static void ExportFullCPP(const Recipe4x4 &pRecipe);
    static void ExportQuadCPP(const Recipe4x4 &pRecipe);
    static void ExportRepeatedCPP(const Recipe4x4 &pRecipe);

    static void ExportOneCPP(const Recipe4x4 &pRecipe,
                             const char *pFunctionName,
                             int pRegionKind,
                             int pRegionIndex);

    static void PrintHPPFunction(const char *pFunctionName);

    static char Letter(int pIndex);
    
    
    static std::string BuildHPP(const Recipe4x4 &pRecipe);
    static std::string BuildCPP(const Recipe4x4 &pRecipe);
    static std::string BuildFullHPP(const Recipe4x4 &pRecipe);
    static std::string BuildRepeatedHPP(const Recipe4x4 &pRecipe);
    static std::string BuildQuadHPP(const Recipe4x4 &pRecipe);
    static std::string BuildFullCPP(const Recipe4x4 &pRecipe);
    static std::string BuildRepeatedCPP(const Recipe4x4 &pRecipe);
    static std::string BuildQuadCPP(const Recipe4x4 &pRecipe);

    static std::string BuildOneCPP(const Recipe4x4 &pRecipe,
                                   const char *pFunctionName,
                                   int pRegionKind,
                                   int pRegionIndex);

    static std::string BuildHPPFunction(const char *pFunctionName);
    
};

#endif /* RecipeExporter4x4_hpp */

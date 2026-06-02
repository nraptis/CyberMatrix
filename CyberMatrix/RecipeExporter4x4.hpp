//
//  RecipeExporter4x4.hpp
//  CyberMatrix
//

#ifndef RecipeExporter4x4_hpp
#define RecipeExporter4x4_hpp

#include "RecipeFactory4x4.hpp"

class RecipeExporter4x4 {
public:
    static void Export(const Recipe4x4 &pRecipe);

    static void ExportHPP(const Recipe4x4 &pRecipe);
    static void ExportCPP(const Recipe4x4 &pRecipe);

private:
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
};

#endif /* RecipeExporter4x4_hpp */

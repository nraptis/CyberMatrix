//
//  RecipeExporter2x2.hpp
//  CyberMatrix
//

#ifndef RecipeExporter2x2_hpp
#define RecipeExporter2x2_hpp

#include "RecipeFactory2x2.hpp"

class RecipeExporter2x2 {
public:
    static void Export(const Recipe2x2 &pRecipe);

    static void ExportHPP(const Recipe2x2 &pRecipe);
    static void ExportCPP(const Recipe2x2 &pRecipe);

private:
    static void ExportFullHPP(const Recipe2x2 &pRecipe);
    static void ExportQuadHPP(const Recipe2x2 &pRecipe);
    static void ExportMiniHPP(const Recipe2x2 &pRecipe);
    static void ExportRepeatedHPP(const Recipe2x2 &pRecipe);

    static void ExportFullCPP(const Recipe2x2 &pRecipe);
    static void ExportQuadCPP(const Recipe2x2 &pRecipe);
    static void ExportMiniCPP(const Recipe2x2 &pRecipe);
    static void ExportRepeatedCPP(const Recipe2x2 &pRecipe);
    

    static void ExportOneCPP(const Recipe2x2 &pRecipe,
                             const char *pFunctionName,
                             int pRegionKind,
                             int pRegionIndex);

    static void PrintHPPFunction(const char *pFunctionName);

    static char Letter(int pIndex);
};

#endif /* RecipeExporter2x2_hpp */

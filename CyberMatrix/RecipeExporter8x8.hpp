//
//  RecipeExporter8x8.hpp
//  CyberMatrix
//

#ifndef RecipeExporter8x8_hpp
#define RecipeExporter8x8_hpp

#include "RecipeFactory8x8.hpp"

class RecipeExporter8x8 {
public:
    static void Export(const Recipe8x8 &pRecipe);

    static void ExportHPP(const Recipe8x8 &pRecipe);
    static void ExportCPP(const Recipe8x8 &pRecipe);

private:
    static void ExportFullHPP(const Recipe8x8 &pRecipe);
    static void ExportFullCPP(const Recipe8x8 &pRecipe);

    static void ExportOneCPP(const Recipe8x8 &pRecipe,
                             const char *pFunctionName);

    static void PrintHPPFunction(const char *pFunctionName);
};

#endif /* RecipeExporter8x8_hpp */

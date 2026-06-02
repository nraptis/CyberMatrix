//
//  TestExporter2x2.hpp
//  CyberMatrix
//

#ifndef TestExporter2x2_hpp
#define TestExporter2x2_hpp

#include "RecipeFactory2x2.hpp"

class TestExporter2x2 {
public:
    static void Export(const Recipe2x2 &pRecipe);

    static void ExportMiniTests(const Recipe2x2 &pRecipe);
    static void ExportQuadTests(const Recipe2x2 &pRecipe);
    static void ExportFullTests(const Recipe2x2 &pRecipe);
    static void ExportRepeatedTests(const Recipe2x2 &pRecipe);

private:
    static char Letter(int pIndex);

    static void PrintExpected2x2(const Recipe2x2 &pRecipe,
                                 int pIndent);

    static void PrintExpected4x4From2x2(const Recipe2x2 &pRecipe,
                                        int pIndent);

    static void PrintExpected4x4EachMini(const Recipe2x2 &pRecipe,
                                         int pIndent);

    static void PrintExpected8x8From2x2Full(const Recipe2x2 &pRecipe,
                                            int pIndent);

    static void PrintExpected8x8EachQuad2x2(const Recipe2x2 &pRecipe,
                                            int pIndent);

    static void PrintExpected8x8EachMini2x2(const Recipe2x2 &pRecipe,
                                            int pIndent);

    static void PrintMiniTest(const Recipe2x2 &pRecipe,
                              int pMiniIndex);

    static void PrintQuadTest(const Recipe2x2 &pRecipe,
                              int pQuadIndex);

    static void PrintQuadEachMiniTest(const Recipe2x2 &pRecipe,
                                      int pQuadIndex);

    static void PrintFullTest(const Recipe2x2 &pRecipe);

    static void PrintFullEachQuadTest(const Recipe2x2 &pRecipe);
    static void PrintFullEachMiniTest(const Recipe2x2 &pRecipe);
};

#endif /* TestExporter2x2_hpp */

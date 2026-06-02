//
//  TestExporter4x4.hpp
//  CyberMatrix
//

#ifndef TestExporter4x4_hpp
#define TestExporter4x4_hpp

#include "RecipeFactory4x4.hpp"

class TestExporter4x4 {
public:
    static void Export(const Recipe4x4 &pRecipe);

    static void ExportQuadTests(const Recipe4x4 &pRecipe);
    static void ExportFullTests(const Recipe4x4 &pRecipe);
    static void ExportRepeatedTests(const Recipe4x4 &pRecipe);

private:
    static char Letter(int pIndex);

    static void PrintExpected4x4(const Recipe4x4 &pRecipe,
                                 int pIndent);

    static void PrintExpected8x8From4x4Full(const Recipe4x4 &pRecipe,
                                            int pIndent);

    static void PrintExpected8x8EachQuad(const Recipe4x4 &pRecipe,
                                         int pIndent);

    static void PrintQuadTest(const Recipe4x4 &pRecipe,
                              int pQuadIndex);

    static void PrintFullTest(const Recipe4x4 &pRecipe);

    static void PrintFullEachQuadTest(const Recipe4x4 &pRecipe);
};

#endif /* TestExporter4x4_hpp */

//
//  TestExporter8x8.hpp
//  CyberMatrix
//

#ifndef TestExporter8x8_hpp
#define TestExporter8x8_hpp

#include "RecipeFactory8x8.hpp"

class TestExporter8x8 {
public:
    static void Export(const Recipe8x8 &pRecipe);

private:
    static void PrintExpected8x8(const Recipe8x8 &pRecipe,
                                 int pIndent);

    static void PrintFullTest(const Recipe8x8 &pRecipe);
};

#endif /* TestExporter8x8_hpp */

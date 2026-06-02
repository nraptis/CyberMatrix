//
//  RecipeScaler.hpp
//  CyberMatrix
//
//  Created by Wu Tang on 6/1/26.
//

#ifndef RecipeScaler_hpp
#define RecipeScaler_hpp

#include <stdio.h>
#include "RecipeFactory2x2.hpp"
#include "RecipeFactory4x4.hpp"
#include "RecipeFactory8x8.hpp"

class RecipeScaler {
public:
    static Recipe4x4 Scale2x2To4x4(const Recipe2x2 &pRecipe);
    static Recipe8x8 Scale4x4To8x8(const Recipe4x4 &pRecipe);
    static Recipe8x8 Scale2x2To8x8(const Recipe2x2 &pRecipe);
};

#endif /* RecipeScaler_hpp */

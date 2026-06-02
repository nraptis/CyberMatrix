//
//  RecipeFactory2x2.cpp
//  CyberMatrix
//
//  Created by Wu Tang on 6/1/26.
//

#include "RecipeFactory2x2.hpp"

Recipe2x2 RecipeFactory2x2::Make(const char *pName,
                                  std::uint8_t pA,
                                  std::uint8_t pB,
                                  std::uint8_t pC,
                                  std::uint8_t pD) {
    Recipe2x2 aResult = {
        pName,
        {
            { pA, pB },
            { pC, pD }
        }
    };

    return aResult;
}

Recipe2x2 RecipeFactory2x2::RotA() {
    //  A  B      C  A
    //  C  D  ->  D  B
    return Make("RotA",
                2U,  0U,
                3U,  1U
                );
}

Recipe2x2 RecipeFactory2x2::RotB() {
    //  A  B      B  D
    //  C  D  ->  A  C
    return Make("RotB",
                1U,  3U,
                0U,  2U
                );
}

Recipe2x2 RecipeFactory2x2::RotC() {
    //  A  B      D  C
    //  C  D  ->  B  A
    return Make("RotC",
                3U,  2U,
                1U,  0U
                );
}

Recipe2x2 RecipeFactory2x2::FlipA() {
    //  A  B      B  A
    //  C  D  ->  D  C
    return Make("FlipA",
                1U,  0U,
                3U,  2U
                );
}

Recipe2x2 RecipeFactory2x2::FlipB() {
    //  A  B      C  D
    //  C  D  ->  A  B
    return Make("FlipB",
                2U,  3U,
                0U,  1U
                );
}

Recipe2x2 RecipeFactory2x2::FlipC() {
    //  A  B      A  C
    //  C  D  ->  B  D
    return Make("FlipC",
                0U,  2U,
                1U,  3U
                );
}

Recipe2x2 RecipeFactory2x2::FlipD() {
    //  A  B      D  B
    //  C  D  ->  C  A
    return Make("FlipD",
                3U,  1U,
                2U,  0U
                );
}

Recipe2x2 RecipeFactory2x2::SwapA() {
    // B A / C D
    // SwapAB
    return Make("SwapA",
                1U, 0U,
                2U, 3U);
}

Recipe2x2 RecipeFactory2x2::SwapB() {
    // C B / A D
    // SwapAC
    return Make("SwapB",
                2U, 1U,
                0U, 3U);
}

Recipe2x2 RecipeFactory2x2::SwapC() {
    // A D / C B
    // SwapBD
    return Make("SwapC",
                0U, 3U,
                2U, 1U);
}

Recipe2x2 RecipeFactory2x2::SwapD() {
    // A B / D C
    // SwapCD
    return Make("SwapD",
                0U, 1U,
                3U, 2U);
}

Recipe2x2 RecipeFactory2x2::TriadA() {
    // BCAD
    return Make("TriadA",
                1U, 2U,
                0U, 3U);
}

Recipe2x2 RecipeFactory2x2::TriadB() {
    // CABD
    return Make("TriadB",
                2U, 0U,
                1U, 3U);
}

Recipe2x2 RecipeFactory2x2::TriadC() {
    // BDCA
    return Make("TriadC",
                1U, 3U,
                2U, 0U);
}

Recipe2x2 RecipeFactory2x2::TriadD() {
    // DACB
    return Make("TriadD",
                3U, 0U,
                2U, 1U);
}

Recipe2x2 RecipeFactory2x2::TriadE() {
    // CBDA
    return Make("TriadE",
                2U, 1U,
                3U, 0U);
}

Recipe2x2 RecipeFactory2x2::TriadF() {
    // DBAC
    return Make("TriadF",
                3U, 1U,
                0U, 2U);
}

Recipe2x2 RecipeFactory2x2::TriadG() {
    // ACDB
    return Make("TriadG",
                0U, 2U,
                3U, 1U);
}

Recipe2x2 RecipeFactory2x2::TriadH() {
    // ADBC
    return Make("TriadH",
                0U, 3U,
                1U, 2U);
}

Recipe2x2 RecipeFactory2x2::SnakeA() {
    // BCDA
    return Make("SnakeA",
                1U, 2U,
                3U, 0U);
}

Recipe2x2 RecipeFactory2x2::SnakeB() {
    // DABC
    return Make("SnakeB",
                3U, 0U,
                1U, 2U);
}

Recipe2x2 RecipeFactory2x2::SnakeC() {
    // CDBA
    return Make("SnakeC",
                2U, 3U,
                1U, 0U);
}

Recipe2x2 RecipeFactory2x2::SnakeD() {
    // DCAB
    return Make("SnakeD",
                3U, 2U,
                0U, 1U);
}

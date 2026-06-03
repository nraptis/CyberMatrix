//
//  RecipeFactory4x4.cpp
//  CyberMatrix
//

#include "RecipeFactory4x4.hpp"

Recipe4x4 RecipeFactory4x4::Make(const char *pName,
                                  std::uint8_t p00,
                                  std::uint8_t p01,
                                  std::uint8_t p02,
                                  std::uint8_t p03,
                                  std::uint8_t p10,
                                  std::uint8_t p11,
                                  std::uint8_t p12,
                                  std::uint8_t p13,
                                  std::uint8_t p20,
                                  std::uint8_t p21,
                                  std::uint8_t p22,
                                  std::uint8_t p23,
                                  std::uint8_t p30,
                                  std::uint8_t p31,
                                  std::uint8_t p32,
                                  std::uint8_t p33) {
    Recipe4x4 aResult = {
        pName,
        {
            { p00, p01, p02, p03 },
            { p10, p11, p12, p13 },
            { p20, p21, p22, p23 },
            { p30, p31, p32, p33 }
        }
    };

    return aResult;
}

Recipe4x4 RecipeFactory4x4::Identity() {
    return Make("Identity",
                 0U,  1U,  2U,  3U,
                 4U,  5U,  6U,  7U,
                 8U,  9U, 10U, 11U,
                12U, 13U, 14U, 15U);
}

Recipe4x4 RecipeFactory4x4::RotA() {
    //  A  B  C  D      M  I  E  A
    //  E  F  G  H  ->  N  J  F  B
    //  I  J  K  L      O  K  G  C
    //  M  N  O  P      P  L  H  D
    return Make("RotA",
                12U,  8U,  4U,  0U,
                13U,  9U,  5U,  1U,
                14U, 10U,  6U,  2U,
                15U, 11U,  7U,  3U
                );
}

Recipe4x4 RecipeFactory4x4::RotB() {
    //  A  B  C  D      D  H  L  P
    //  E  F  G  H  ->  C  G  K  O
    //  I  J  K  L      B  F  J  N
    //  M  N  O  P      A  E  I  M
    return Make("RotB",
                3U,  7U, 11U, 15U,
                2U,  6U, 10U, 14U,
                1U,  5U,  9U, 13U,
                0U,  4U,  8U, 12U
                );
}

Recipe4x4 RecipeFactory4x4::RotC() {
    //  A  B  C  D      P  O  N  M
    //  E  F  G  H  ->  L  K  J  I
    //  I  J  K  L      H  G  F  E
    //  M  N  O  P      D  C  B  A
    return Make("RotC",
                15U, 14U, 13U, 12U,
                11U, 10U,  9U,  8U,
                7U,  6U,  5U,  4U,
                3U,  2U,  1U,  0U
                );
}

Recipe4x4 RecipeFactory4x4::FlipA() {
    //  A  B  C  D      D  C  B  A
    //  E  F  G  H  ->  H  G  F  E
    //  I  J  K  L      L  K  J  I
    //  M  N  O  P      P  O  N  M
    return Make("FlipA",
                3U,  2U,  1U,  0U,
                7U,  6U,  5U,  4U,
                11U, 10U,  9U,  8U,
                15U, 14U, 13U, 12U
                );
}

Recipe4x4 RecipeFactory4x4::FlipB() {
    //  A  B  C  D      M  N  O  P
    //  E  F  G  H  ->  I  J  K  L
    //  I  J  K  L      E  F  G  H
    //  M  N  O  P      A  B  C  D
    return Make("FlipB",
                12U, 13U, 14U, 15U,
                8U,  9U, 10U, 11U,
                4U,  5U,  6U,  7U,
                0U,  1U,  2U,  3U
                );
}

Recipe4x4 RecipeFactory4x4::FlipC() {
    //  A  B  C  D      A  E  I  M
    //  E  F  G  H  ->  B  F  J  N
    //  I  J  K  L      C  G  K  O
    //  M  N  O  P      D  H  L  P
    return Make("FlipC",
                0U,  4U,  8U, 12U,
                1U,  5U,  9U, 13U,
                2U,  6U, 10U, 14U,
                3U,  7U, 11U, 15U
                );
}

Recipe4x4 RecipeFactory4x4::FlipD() {
    //  A  B  C  D      P  L  H  D
    //  E  F  G  H  ->  O  K  G  C
    //  I  J  K  L      N  J  F  B
    //  M  N  O  P      M  I  E  A
    return Make("FlipD",
                15U, 11U,  7U,  3U,
                14U, 10U,  6U,  2U,
                13U,  9U,  5U,  1U,
                12U,  8U,  4U,  0U
                );
}

Recipe4x4 RecipeFactory4x4::PinA() {
    //  A  B  C  D      M  I  E  A
    //  E  F  G  H  ->  N  G  K  B
    //  I  J  K  L      O  F  J  C
    //  M  N  O  P      P  L  H  D
    return Make("PinA",
                12U,  8U,  4U,  0U,
                13U,  6U, 10U,  1U,
                14U,  5U,  9U,  2U,
                15U, 11U,  7U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::PinB() {
    //  A  B  C  D      D  H  L  P
    //  E  F  G  H  ->  C  J  F  O
    //  I  J  K  L      B  K  G  N
    //  M  N  O  P      A  E  I  M
    return Make("PinB",
                 3U,  7U, 11U, 15U,
                 2U,  9U,  5U, 14U,
                 1U, 10U,  6U, 13U,
                 0U,  4U,  8U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::ReachA() {
    //  A  B  C  D      C  B  A  D
    //  E  F  G  H  ->  G  F  E  H
    //  I  J  K  L      I  L  K  J
    //  M  N  O  P      M  P  O  N
    return Make("ReachA",
                 2U,  1U,  0U,  3U,
                 6U,  5U,  4U,  7U,
                 8U, 11U, 10U,  9U,
                12U, 15U, 14U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::ReachB() {
    //  A  B  C  D      A  D  C  B
    //  E  F  G  H  ->  E  H  G  F
    //  I  J  K  L      K  J  I  L
    //  M  N  O  P      O  N  M  P
    return Make("ReachB",
                 0U,  3U,  2U,  1U,
                 4U,  7U,  6U,  5U,
                10U,  9U,  8U, 11U,
                14U, 13U, 12U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::ReachC() {
    //  A  B  C  D      I  J  C  D
    //  E  F  G  H  ->  E  F  O  P
    //  I  J  K  L      A  B  K  L
    //  M  N  O  P      M  N  G  H
    return Make("ReachC",
                 8U,  9U,  2U,  3U,
                 4U,  5U, 14U, 15U,
                 0U,  1U, 10U, 11U,
                12U, 13U,  6U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::ReachD() {
    //  A  B  C  D      A  B  K  L
    //  E  F  G  H  ->  M  N  G  H
    //  I  J  K  L      I  J  C  D
    //  M  N  O  P      E  F  O  P
    return Make("ReachD",
                 0U,  1U, 10U, 11U,
                12U, 13U,  6U,  7U,
                 8U,  9U,  2U,  3U,
                 4U,  5U, 14U, 15U
    );
}


Recipe4x4 RecipeFactory4x4::RollHor1() {
    //  A  B  C  D      D  A  B  C
    //  E  F  G  H  ->  H  E  F  G
    //  I  J  K  L      L  I  J  K
    //  M  N  O  P      P  M  N  O
    return Make("RollHor1",
                 3U,  0U,  1U,  2U,
                 7U,  4U,  5U,  6U,
                11U,  8U,  9U, 10U,
                15U, 12U, 13U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::RollHor2() {
    //  A  B  C  D      C  D  A  B
    //  E  F  G  H  ->  G  H  E  F
    //  I  J  K  L      K  L  I  J
    //  M  N  O  P      O  P  M  N
    return Make("RollHor2",
                 2U,  3U,  0U,  1U,
                 6U,  7U,  4U,  5U,
                10U, 11U,  8U,  9U,
                14U, 15U, 12U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::RollHor3() {
    //  A  B  C  D      B  C  D  A
    //  E  F  G  H  ->  F  G  H  E
    //  I  J  K  L      J  K  L  I
    //  M  N  O  P      N  O  P  M
    return Make("RollHor3",
                 1U,  2U,  3U,  0U,
                 5U,  6U,  7U,  4U,
                 9U, 10U, 11U,  8U,
                13U, 14U, 15U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::RollVer1() {
    //  A  B  C  D      M  N  O  P
    //  E  F  G  H  ->  A  B  C  D
    //  I  J  K  L      E  F  G  H
    //  M  N  O  P      I  J  K  L
    return Make("RollVer1",
                12U, 13U, 14U, 15U,
                 0U,  1U,  2U,  3U,
                 4U,  5U,  6U,  7U,
                 8U,  9U, 10U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::RollVer2() {
    //  A  B  C  D      I  J  K  L
    //  E  F  G  H  ->  M  N  O  P
    //  I  J  K  L      A  B  C  D
    //  M  N  O  P      E  F  G  H
    return Make("RollVer2",
                 8U,  9U, 10U, 11U,
                12U, 13U, 14U, 15U,
                 0U,  1U,  2U,  3U,
                 4U,  5U,  6U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::RollVer3() {
    //  A  B  C  D      E  F  G  H
    //  E  F  G  H  ->  I  J  K  L
    //  I  J  K  L      M  N  O  P
    //  M  N  O  P      A  B  C  D
    return Make("RollVer3",
                 4U,  5U,  6U,  7U,
                 8U,  9U, 10U, 11U,
                12U, 13U, 14U, 15U,
                 0U,  1U,  2U,  3U
    );
}




Recipe4x4 RecipeFactory4x4::ShearA() {
//  A  B  C  D      C  D  A  B
//  E  F  G  H  ->  H  E  F  G
//  I  J  K  L      K  L  I  J
//  M  N  O  P      P  M  N  O
return Make("ShearA",
             2U,  3U,  0U,  1U,
             7U,  4U,  5U,  6U,
            10U, 11U,  8U,  9U,
            15U, 12U, 13U, 14U
);
}



Recipe4x4 RecipeFactory4x4::ShearB() {
//  A  B  C  D      D  A  B  C
//  E  F  G  H  ->  G  H  E  F
//  I  J  K  L      L  I  J  K
//  M  N  O  P      O  P  M  N
return Make("ShearB",
             3U,  0U,  1U,  2U,
             6U,  7U,  4U,  5U,
            11U,  8U,  9U, 10U,
            14U, 15U, 12U, 13U
);
}



Recipe4x4 RecipeFactory4x4::ShearC() {
//  A  B  C  D      I  N  K  P
//  E  F  G  H  ->  M  B  O  D
//  I  J  K  L      A  F  C  H
//  M  N  O  P      E  J  G  L
return Make("ShearC",
             8U, 13U, 10U, 15U,
            12U,  1U, 14U,  3U,
             0U,  5U,  2U,  7U,
             4U,  9U,  6U, 11U
);
}



Recipe4x4 RecipeFactory4x4::ShearD() {
//  A  B  C  D      M  J  O  L
//  E  F  G  H  ->  A  N  C  P
//  I  J  K  L      E  B  G  D
//  M  N  O  P      I  F  K  H
return Make("ShearD",
            12U,  9U, 14U, 11U,
             0U, 13U,  2U, 15U,
             4U,  1U,  6U,  3U,
             8U,  5U, 10U,  7U
);
}

Recipe4x4 RecipeFactory4x4::SwapRows() {
    //  A  B  C  D      E  F  G  H
    //  E  F  G  H  ->  A  B  C  D
    //  I  J  K  L      M  N  O  P
    //  M  N  O  P      I  J  K  L
    return Make("SwapRows",
                 4U,  5U,  6U,  7U,
                 0U,  1U,  2U,  3U,
                12U, 13U, 14U, 15U,
                 8U,  9U, 10U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::SwapColums() {
    //  A  B  C  D      B  A  D  C
    //  E  F  G  H  ->  F  E  H  G
    //  I  J  K  L      J  I  L  K
    //  M  N  O  P      N  M  P  O
    return Make("SwapColums",
                1U,  0U,  3U,  2U,
                5U,  4U,  7U,  6U,
                9U,  8U, 11U, 10U,
                13U, 12U, 15U, 14U
                );
}



Recipe4x4 RecipeFactory4x4::SwapBoth() {
//  A  B  C  D      F  E  H  G
//  E  F  G  H  ->  B  A  D  C
//  I  J  K  L      N  M  P  O
//  M  N  O  P      J  I  L  K
return Make("SwapBoth",
             5U,  4U,  7U,  6U,
             1U,  0U,  3U,  2U,
            13U, 12U, 15U, 14U,
             9U,  8U, 11U, 10U
);
}

Recipe4x4 RecipeFactory4x4::FoldA() {
    //  A  B  C  D      D  F  G  A
    //  E  F  G  H  ->  H  B  C  E
    //  I  J  K  L      L  N  O  I
    //  M  N  O  P      P  J  K  M
    return Make("FoldA",
                 3U,  5U,  6U,  0U,
                 7U,  1U,  2U,  4U,
                11U, 13U, 14U,  8U,
                15U,  9U, 10U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::FoldB() {
    //  A  B  C  D      M  N  O  P
    //  E  F  G  H  ->  F  E  H  G
    //  I  J  K  L      J  I  L  K
    //  M  N  O  P      A  B  C  D
    return Make("FoldB",
                12U, 13U, 14U, 15U,
                 5U,  4U,  7U,  6U,
                 9U,  8U, 11U, 10U,
                 0U,  1U,  2U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::FoldC() {
    //  A  B  C  D      D  C  B  A
    //  E  F  G  H  ->  H  G  F  E
    //  I  J  K  L      L  K  J  I
    //  M  N  O  P      P  O  N  M
    return Make("FoldC",
                 3U,  2U,  1U,  0U,
                 7U,  6U,  5U,  4U,
                11U, 10U,  9U,  8U,
                15U, 14U, 13U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::FoldD() {
    //  A  B  C  D      P  O  N  M
    //  E  F  G  H  ->  H  G  F  E
    //  I  J  K  L      L  K  J  I
    //  M  N  O  P      D  C  B  A
    return Make("FoldD",
                15U, 14U, 13U, 12U,
                 7U,  6U,  5U,  4U,
                11U, 10U,  9U,  8U,
                 3U,  2U,  1U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::CastleA() {
    //  A  B  C  D      G  H  L  K
    //  E  F  G  H  ->  C  M  A  O
    //  I  J  K  L      B  P  D  N
    //  M  N  O  P      F  E  I  J
    return Make("CastleA",
                 6U,  7U, 11U, 10U,
                 2U, 12U,  0U, 14U,
                 1U, 15U,  3U, 13U,
                 5U,  4U,  8U,  9U
    );
}


Recipe4x4 RecipeFactory4x4::CastleB() {
    //  A  B  C  D      J  I  E  F
    //  E  F  G  H  ->  N  D  P  B
    //  I  J  K  L      O  A  M  C
    //  M  N  O  P      K  L  H  G
    return Make("CastleB",
                 9U,  8U,  4U,  5U,
                13U,  3U, 15U,  1U,
                14U,  0U, 12U,  2U,
                10U, 11U,  7U,  6U
    );
}


Recipe4x4 RecipeFactory4x4::CastleC() {
    //  A  B  C  D      K  L  H  J
    //  E  F  G  H  ->  B  P  M  N
    //  I  J  K  L      C  D  A  O
    //  M  N  O  P      G  I  E  F
    return Make("CastleC",
                10U, 11U,  7U,  9U,
                 1U, 15U, 12U, 13U,
                 2U,  3U,  0U, 14U,
                 6U,  8U,  4U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::CastleD() {
    //  A  B  C  D      F  E  I  G
    //  E  F  G  H  ->  O  A  D  C
    //  I  J  K  L      N  M  P  B
    //  M  N  O  P      J  H  L  K
    return Make("CastleD",
                 5U,  4U,  8U,  6U,
                14U,  0U,  3U,  2U,
                13U, 12U, 15U,  1U,
                 9U,  7U, 11U, 10U
    );
}


Recipe4x4 RecipeFactory4x4::TowerA() {
    //  A  B  C  D      L  G  M  N
    //  E  F  G  H  ->  P  I  B  K
    //  I  J  K  L      F  O  H  A
    //  M  N  O  P      C  D  J  E
    return Make("TowerA",
                11U,  6U, 12U, 13U,
                15U,  8U,  1U, 10U,
                 5U, 14U,  7U,  0U,
                 2U,  3U,  9U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::TowerB() {
    //  A  B  C  D      E  J  D  C
    //  E  F  G  H  ->  A  H  O  F
    //  I  J  K  L      K  B  I  P
    //  M  N  O  P      N  M  G  L
    return Make("TowerB",
                 4U,  9U,  3U,  2U,
                 0U,  7U, 14U,  5U,
                10U,  1U,  8U, 15U,
                13U, 12U,  6U, 11U
    );
}


Recipe4x4 RecipeFactory4x4::FortressA() {
    //  A  B  C  D      O  P  K  I
    //  E  F  G  H  ->  G  N  E  M
    //  I  J  K  L      D  L  C  J
    //  M  N  O  P      H  F  A  B
    return Make("FortressA",
                14U, 15U, 10U,  8U,
                 6U, 13U,  4U, 12U,
                 3U, 11U,  2U,  9U,
                 7U,  5U,  0U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::FortressB() {
    //  A  B  C  D      P  O  F  M
    //  E  F  G  H  ->  J  C  L  I
    //  I  J  K  L      H  E  N  G
    //  M  N  O  P      D  K  B  A
    return Make("FortressB",
                15U, 14U,  5U, 12U,
                 9U,  2U, 11U,  8U,
                 7U,  4U, 13U,  6U,
                 3U, 10U,  1U,  0U
    );
}

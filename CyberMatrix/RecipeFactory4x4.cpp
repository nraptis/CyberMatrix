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




Recipe4x4 RecipeFactory4x4::JewelA() {
//  A  B  C  D      F  E  A  B
//  E  F  G  H  ->  G  H  D  C
//  I  J  K  L      K  L  P  O
//  M  N  O  P      J  I  M  N
return Make("JewelA",
             5U,  4U,  0U,  1U,
             6U,  7U,  3U,  2U,
            10U, 11U, 15U, 14U,
             9U,  8U, 12U, 13U
);
}




Recipe4x4 RecipeFactory4x4::JewelB() {
//  A  B  C  D      C  D  H  G
//  E  F  G  H  ->  B  A  E  F
//  I  J  K  L      N  M  I  J
//  M  N  O  P      O  P  L  K
return Make("JewelB",
             2U,  3U,  7U,  6U,
             1U,  0U,  4U,  5U,
            13U, 12U,  8U,  9U,
            14U, 15U, 11U, 10U
);
}



Recipe4x4 RecipeFactory4x4::JewelC() {
//  A  B  C  D      I  E  H  L
//  E  F  G  H  ->  M  A  D  P
//  I  J  K  L      N  B  C  O
//  M  N  O  P      J  F  G  K
return Make("JewelC",
             8U,  4U,  7U, 11U,
            12U,  0U,  3U, 15U,
            13U,  1U,  2U, 14U,
             9U,  5U,  6U, 10U
);
}



Recipe4x4 RecipeFactory4x4::JewelD() {
//  A  B  C  D      F  J  K  G
//  E  F  G  H  ->  B  N  O  C
//  I  J  K  L      A  M  P  D
//  M  N  O  P      E  I  L  H
return Make("JewelD",
             5U,  9U, 10U,  6U,
             1U, 13U, 14U,  2U,
             0U, 12U, 15U,  3U,
             4U,  8U, 11U,  7U
);
}




Recipe4x4 RecipeFactory4x4::CrystalA() {
//  A  B  C  D      J  K  G  F
//  E  F  G  H  ->  I  L  H  E
//  I  J  K  L      M  P  D  A
//  M  N  O  P      N  O  C  B
return Make("CrystalA",
             9U, 10U,  6U,  5U,
             8U, 11U,  7U,  4U,
            12U, 15U,  3U,  0U,
            13U, 14U,  2U,  1U
);
}



Recipe4x4 RecipeFactory4x4::CrystalC() {
//  A  B  C  D      O  N  B  C
//  E  F  G  H  ->  P  M  A  D
//  I  J  K  L      L  I  E  H
//  M  N  O  P      K  J  F  G
return Make("CrystalC",
            14U, 13U,  1U,  2U,
            15U, 12U,  0U,  3U,
            11U,  8U,  4U,  7U,
            10U,  9U,  5U,  6U
);
}




Recipe4x4 RecipeFactory4x4::CrystalB() {
//  A  B  C  D      J  N  M  I
//  E  F  G  H  ->  F  B  A  E
//  I  J  K  L      G  C  D  H
//  M  N  O  P      K  O  P  L
return Make("CrystalB",
             9U, 13U, 12U,  8U,
             5U,  1U,  0U,  4U,
             6U,  2U,  3U,  7U,
            10U, 14U, 15U, 11U
);
}



Recipe4x4 RecipeFactory4x4::CrystalD() {
//  A  B  C  D      E  A  B  F
//  E  F  G  H  ->  I  M  N  J
//  I  J  K  L      L  P  O  K
//  M  N  O  P      H  D  C  G
return Make("CrystalD",
             4U,  0U,  1U,  5U,
             8U, 12U, 13U,  9U,
            11U, 15U, 14U, 10U,
             7U,  3U,  2U,  6U
);
}




Recipe4x4 RecipeFactory4x4::OpalA() {
    //  A  B  C  D      B  C  O  N
    //  E  F  G  H  ->  A  D  P  M
    //  I  J  K  L      E  H  L  I
    //  M  N  O  P      F  G  K  J
    return Make("OpalA",
                 1U,  2U, 14U, 13U,
                 0U,  3U, 15U, 12U,
                 4U,  7U, 11U,  8U,
                 5U,  6U, 10U,  9U
    );
}



Recipe4x4 RecipeFactory4x4::OpalC() {
//  A  B  C  D      G  F  J  K
//  E  F  G  H  ->  H  E  I  L
//  I  J  K  L      D  A  M  P
//  M  N  O  P      C  B  N  O
return Make("OpalC",
             6U,  5U,  9U, 10U,
             7U,  4U,  8U, 11U,
             3U,  0U, 12U, 15U,
             2U,  1U, 13U, 14U
);
}



Recipe4x4 RecipeFactory4x4::OpalB() {
//  A  B  C  D      L  P  O  K
//  E  F  G  H  ->  H  D  C  G
//  I  J  K  L      E  A  B  F
//  M  N  O  P      I  M  N  J
return Make("OpalB",
            11U, 15U, 14U, 10U,
             7U,  3U,  2U,  6U,
             4U,  0U,  1U,  5U,
             8U, 12U, 13U,  9U
);
}




Recipe4x4 RecipeFactory4x4::OpalD() {
//  A  B  C  D      G  C  D  H
//  E  F  G  H  ->  K  O  P  L
//  I  J  K  L      J  N  M  I
//  M  N  O  P      F  B  A  E
return Make("OpalD",
             6U,  2U,  3U,  7U,
            10U, 14U, 15U, 11U,
             9U, 13U, 12U,  8U,
             5U,  1U,  0U,  4U
);
}




Recipe4x4 RecipeFactory4x4::PeridotA() {
//  A  B  C  D      N  M  I  J
//  E  F  G  H  ->  O  P  L  K
//  I  J  K  L      C  D  H  G
//  M  N  O  P      B  A  E  F
return Make("PeridotA",
            13U, 12U,  8U,  9U,
            14U, 15U, 11U, 10U,
             2U,  3U,  7U,  6U,
             1U,  0U,  4U,  5U
);
}



Recipe4x4 RecipeFactory4x4::PeridotB() {
//  A  B  C  D      K  L  P  O
//  E  F  G  H  ->  J  I  M  N
//  I  J  K  L      F  E  A  B
//  M  N  O  P      G  H  D  C
return Make("PeridotB",
            10U, 11U, 15U, 14U,
             9U,  8U, 12U, 13U,
             5U,  4U,  0U,  1U,
             6U,  7U,  3U,  2U
);
}





Recipe4x4 RecipeFactory4x4::PeridotC() {
//  A  B  C  D      K  G  F  J
//  E  F  G  H  ->  O  C  B  N
//  I  J  K  L      P  D  A  M
//  M  N  O  P      L  H  E  I
return Make("PeridotC",
            10U,  6U,  5U,  9U,
            14U,  2U,  1U, 13U,
            15U,  3U,  0U, 12U,
            11U,  7U,  4U,  8U
);
}



Recipe4x4 RecipeFactory4x4::PeridotD() {
//  A  B  C  D      H  L  I  E
//  E  F  G  H  ->  D  P  M  A
//  I  J  K  L      C  O  N  B
//  M  N  O  P      G  K  J  F
return Make("PeridotD",
             7U, 11U,  8U,  4U,
             3U, 15U, 12U,  0U,
             2U, 14U, 13U,  1U,
             6U, 10U,  9U,  5U
);
}

Recipe4x4 RecipeFactory4x4::SwanA() {
    //  A  B  C  D      L  I  J  K
    //  E  F  G  H  ->  P  M  N  O
    //  I  J  K  L      B  A  D  C
    //  M  N  O  P      F  E  H  G
    return Make("SwanA",
                11U,  8U,  9U, 10U,
                15U, 12U, 13U, 14U,
                 1U,  0U,  3U,  2U,
                 5U,  4U,  7U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::SwanB() {
    //  A  B  C  D      F  B  P  L
    //  E  F  G  H  ->  E  A  M  I
    //  I  J  K  L      H  D  N  J
    //  M  N  O  P      G  C  O  K
    return Make("SwanB",
                 5U,  1U, 15U, 11U,
                 4U,  0U, 12U,  8U,
                 7U,  3U, 13U,  9U,
                 6U,  2U, 14U, 10U
    );
}

Recipe4x4 RecipeFactory4x4::SwanC() {
    //  A  B  C  D      G  H  E  F
    //  E  F  G  H  ->  C  D  A  B
    //  I  J  K  L      O  N  M  P
    //  M  N  O  P      K  J  I  L
    return Make("SwanC",
                 6U,  7U,  4U,  5U,
                 2U,  3U,  0U,  1U,
                14U, 13U, 12U, 15U,
                10U,  9U,  8U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::SwanD() {
    //  A  B  C  D      K  O  C  G
    //  E  F  G  H  ->  J  N  D  H
    //  I  J  K  L      I  M  A  E
    //  M  N  O  P      L  P  B  F
    return Make("SwanD",
                10U, 14U,  2U,  6U,
                 9U, 13U,  3U,  7U,
                 8U, 12U,  0U,  4U,
                11U, 15U,  1U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::GooseA() {
    //  A  B  C  D      J  K  L  I
    //  E  F  G  H  ->  N  O  P  M
    //  I  J  K  L      B  C  D  A
    //  M  N  O  P      F  G  H  E
    return Make("GooseA",
                 9U, 10U, 11U,  8U,
                13U, 14U, 15U, 12U,
                 1U,  2U,  3U,  0U,
                 5U,  6U,  7U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::GooseB() {
    //  A  B  C  D      F  B  N  J
    //  E  F  G  H  ->  G  C  O  K
    //  I  J  K  L      H  D  P  L
    //  M  N  O  P      E  A  M  I
    return Make("GooseB",
                 5U,  1U, 13U,  9U,
                 6U,  2U, 14U, 10U,
                 7U,  3U, 15U, 11U,
                 4U,  0U, 12U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::GooseC() {
    //  A  B  C  D      E  H  G  F
    //  E  F  G  H  ->  A  D  C  B
    //  I  J  K  L      M  P  O  N
    //  M  N  O  P      I  L  K  J
    return Make("GooseC",
                 4U,  7U,  6U,  5U,
                 0U,  3U,  2U,  1U,
                12U, 15U, 14U, 13U,
                 8U, 11U, 10U,  9U
    );
}

Recipe4x4 RecipeFactory4x4::GooseD() {
    //  A  B  C  D      I  M  A  E
    //  E  F  G  H  ->  L  P  D  H
    //  I  J  K  L      K  O  C  G
    //  M  N  O  P      J  N  B  F
    return Make("GooseD",
                 8U, 12U,  0U,  4U,
                11U, 15U,  3U,  7U,
                10U, 14U,  2U,  6U,
                 9U, 13U,  1U,  5U
    );
}


Recipe4x4 RecipeFactory4x4::HeronA() {
    //  A  B  C  D      B  A  D  C
    //  E  F  G  H  ->  F  E  H  G
    //  I  J  K  L      L  K  J  I
    //  M  N  O  P      P  O  N  M
    return Make("HeronA",
                 1U,  0U,  3U,  2U,
                 5U,  4U,  7U,  6U,
                11U, 10U,  9U,  8U,
                15U, 14U, 13U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::HeronB() {
    //  A  B  C  D      P  L  F  B
    //  E  F  G  H  ->  O  K  E  A
    //  I  J  K  L      N  J  H  D
    //  M  N  O  P      M  I  G  C
    return Make("HeronB",
                15U, 11U,  5U,  1U,
                14U, 10U,  4U,  0U,
                13U,  9U,  7U,  3U,
                12U,  8U,  6U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::HeronC() {
    //  A  B  C  D      M  N  O  P
    //  E  F  G  H  ->  I  J  K  L
    //  I  J  K  L      G  H  E  F
    //  M  N  O  P      C  D  A  B
    return Make("HeronC",
                12U, 13U, 14U, 15U,
                 8U,  9U, 10U, 11U,
                 6U,  7U,  4U,  5U,
                 2U,  3U,  0U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::HeronD() {
    //  A  B  C  D      C  G  I  M
    //  E  F  G  H  ->  D  H  J  N
    //  I  J  K  L      A  E  K  O
    //  M  N  O  P      B  F  L  P
    return Make("HeronD",
                 2U,  6U,  8U, 12U,
                 3U,  7U,  9U, 13U,
                 0U,  4U, 10U, 14U,
                 1U,  5U, 11U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::FalconA() {
    //  A  B  C  D      B  C  D  A
    //  E  F  G  H  ->  F  G  H  E
    //  I  J  K  L      J  I  L  K
    //  M  N  O  P      N  M  P  O
    return Make("FalconA",
                 1U,  2U,  3U,  0U,
                 5U,  6U,  7U,  4U,
                 9U,  8U, 11U, 10U,
                13U, 12U, 15U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::FalconB() {
    //  A  B  C  D      N  J  F  B
    //  E  F  G  H  ->  M  I  G  C
    //  I  J  K  L      P  L  H  D
    //  M  N  O  P      O  K  E  A
    return Make("FalconB",
                13U,  9U,  5U,  1U,
                12U,  8U,  6U,  2U,
                15U, 11U,  7U,  3U,
                14U, 10U,  4U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::FalconC() {
    //  A  B  C  D      O  P  M  N
    //  E  F  G  H  ->  K  L  I  J
    //  I  J  K  L      E  H  G  F
    //  M  N  O  P      A  D  C  B
    return Make("FalconC",
                14U, 15U, 12U, 13U,
                10U, 11U,  8U,  9U,
                 4U,  7U,  6U,  5U,
                 0U,  3U,  2U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::FalconD() {
    //  A  B  C  D      A  E  K  O
    //  E  F  G  H  ->  D  H  L  P
    //  I  J  K  L      C  G  I  M
    //  M  N  O  P      B  F  J  N
    return Make("FalconD",
                 0U,  4U, 10U, 14U,
                 3U,  7U, 11U, 15U,
                 2U,  6U,  8U, 12U,
                 1U,  5U,  9U, 13U
    );
}



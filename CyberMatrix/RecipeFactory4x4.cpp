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


Recipe4x4 RecipeFactory4x4::IronA() {
    //  A  B  C  D      K  A  I  C
    //  E  F  G  H  ->  P  F  N  H
    //  I  J  K  L      J  B  L  D
    //  M  N  O  P      O  G  M  E
    return Make("IronA",
                10U,  0U,  8U,  2U,
                15U,  5U, 13U,  7U,
                 9U,  1U, 11U,  3U,
                14U,  6U, 12U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::IronB() {
    //  A  B  C  D      O  J  P  K
    //  E  F  G  H  ->  G  B  F  A
    //  I  J  K  L      M  L  N  I
    //  M  N  O  P      E  D  H  C
    return Make("IronB",
                14U,  9U, 15U, 10U,
                 6U,  1U,  5U,  0U,
                12U, 11U, 13U,  8U,
                 4U,  3U,  7U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::IronC() {
    //  A  B  C  D      E  M  G  O
    //  E  F  G  H  ->  D  L  B  J
    //  I  J  K  L      H  N  F  P
    //  M  N  O  P      C  I  A  K
    return Make("IronC",
                 4U, 12U,  6U, 14U,
                 3U, 11U,  1U,  9U,
                 7U, 13U,  5U, 15U,
                 2U,  8U,  0U, 10U
    );
}

Recipe4x4 RecipeFactory4x4::IronD() {
    //  A  B  C  D      C  H  D  E
    //  E  F  G  H  ->  I  N  L  M
    //  I  J  K  L      A  F  B  G
    //  M  N  O  P      K  P  J  O
    return Make("IronD",
                 2U,  7U,  3U,  4U,
                 8U, 13U, 11U, 12U,
                 0U,  5U,  1U,  6U,
                10U, 15U,  9U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::SteelA() {
    //  A  B  C  D      L  B  J  D
    //  E  F  G  H  ->  O  E  M  G
    //  I  J  K  L      K  C  I  A
    //  M  N  O  P      N  F  P  H
    return Make("SteelA",
                11U,  1U,  9U,  3U,
                14U,  4U, 12U,  6U,
                10U,  2U,  8U,  0U,
                13U,  5U, 15U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::SteelB() {
    //  A  B  C  D      N  K  O  L
    //  E  F  G  H  ->  F  C  E  B
    //  I  J  K  L      P  I  M  J
    //  M  N  O  P      H  A  G  D
    return Make("SteelB",
                13U, 10U, 14U, 11U,
                 5U,  2U,  4U,  1U,
                15U,  8U, 12U,  9U,
                 7U,  0U,  6U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::SteelC() {
    //  A  B  C  D      H  P  F  N
    //  E  F  G  H  ->  A  I  C  K
    //  I  J  K  L      G  M  E  O
    //  M  N  O  P      D  J  B  L
    return Make("SteelC",
                 7U, 15U,  5U, 13U,
                 0U,  8U,  2U, 10U,
                 6U, 12U,  4U, 14U,
                 3U,  9U,  1U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::SteelD() {
    //  A  B  C  D      D  G  A  H
    //  E  F  G  H  ->  J  M  I  P
    //  I  J  K  L      B  E  C  F
    //  M  N  O  P      L  O  K  N
    return Make("SteelD",
                 3U,  6U,  0U,  7U,
                 9U, 12U,  8U, 15U,
                 1U,  4U,  2U,  5U,
                11U, 14U, 10U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::SilverA() {
    //  A  B  C  D      A  K  C  I
    //  E  F  G  H  ->  E  O  G  M
    //  I  J  K  L      H  P  F  N
    //  M  N  O  P      L  D  J  B
    return Make("SilverA",
                 0U, 10U,  2U,  8U,
                 4U, 14U,  6U, 12U,
                 7U, 15U,  5U, 13U,
                11U,  3U,  9U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::SilverB() {
    //  A  B  C  D      L  H  E  A
    //  E  F  G  H  ->  D  P  O  K
    //  I  J  K  L      J  F  G  C
    //  M  N  O  P      B  N  M  I
    return Make("SilverB",
                11U,  7U,  4U,  0U,
                 3U, 15U, 14U, 10U,
                 9U,  5U,  6U,  2U,
                 1U, 13U, 12U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::SilverC() {
    //  A  B  C  D      B  J  D  L
    //  E  F  G  H  ->  N  F  P  H
    //  I  J  K  L      M  G  O  E
    //  M  N  O  P      I  C  K  A
    return Make("SilverC",
                 1U,  9U,  3U, 11U,
                13U,  5U, 15U,  7U,
                12U,  6U, 14U,  4U,
                 8U,  2U, 10U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::SilverD() {
    //  A  B  C  D      I  M  N  B
    //  E  F  G  H  ->  C  G  F  J
    //  I  J  K  L      K  O  P  D
    //  M  N  O  P      A  E  H  L
    return Make("SilverD",
                 8U, 12U, 13U,  1U,
                 2U,  6U,  5U,  9U,
                10U, 14U, 15U,  3U,
                 0U,  4U,  7U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::GoldA() {
    //  A  B  C  D      E  O  G  M
    //  E  F  G  H  ->  I  C  K  A
    //  I  J  K  L      D  L  B  J
    //  M  N  O  P      H  P  F  N
    return Make("GoldA",
                 4U, 14U,  6U, 12U,
                 8U,  2U, 10U,  0U,
                 3U, 11U,  1U,  9U,
                 7U, 15U,  5U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::GoldB() {
    //  A  B  C  D      H  D  I  E
    //  E  F  G  H  ->  P  L  C  O
    //  I  J  K  L      F  B  K  G
    //  M  N  O  P      N  J  A  M
    return Make("GoldB",
                 7U,  3U,  8U,  4U,
                15U, 11U,  2U, 14U,
                 5U,  1U, 10U,  6U,
                13U,  9U,  0U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::GoldC() {
    //  A  B  C  D      N  F  P  H
    //  E  F  G  H  ->  J  B  L  D
    //  I  J  K  L      A  K  C  I
    //  M  N  O  P      M  G  O  E
    return Make("GoldC",
                13U,  5U, 15U,  7U,
                 9U,  1U, 11U,  3U,
                 0U, 10U,  2U,  8U,
                12U,  6U, 14U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::GoldD() {
    //  A  B  C  D      M  A  J  N
    //  E  F  G  H  ->  G  K  B  F
    //  I  J  K  L      O  C  L  P
    //  M  N  O  P      E  I  D  H
    return Make("GoldD",
                12U,  0U,  9U, 13U,
                 6U, 10U,  1U,  5U,
                14U,  2U, 11U, 15U,
                 4U,  8U,  3U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::BronzeA() {
    //  A  B  C  D      G  M  E  O
    //  E  F  G  H  ->  B  L  D  J
    //  I  J  K  L      H  P  F  N
    //  M  N  O  P      C  K  A  I
    return Make("BronzeA",
                 6U, 12U,  4U, 14U,
                 1U, 11U,  3U,  9U,
                 7U, 15U,  5U, 13U,
                 2U, 10U,  0U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::BronzeB() {
    //  A  B  C  D      C  H  B  G
    //  E  F  G  H  ->  K  P  L  M
    //  I  J  K  L      A  F  D  E
    //  M  N  O  P      I  N  J  O
    return Make("BronzeB",
                 2U,  7U,  1U,  6U,
                10U, 15U, 11U, 12U,
                 0U,  5U,  3U,  4U,
                 8U, 13U,  9U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::BronzeC() {
    //  A  B  C  D      I  A  K  C
    //  E  F  G  H  ->  N  F  P  H
    //  I  J  K  L      J  D  L  B
    //  M  N  O  P      O  E  M  G
    return Make("BronzeC",
                 8U,  0U, 10U,  2U,
                13U,  5U, 15U,  7U,
                 9U,  3U, 11U,  1U,
                14U,  4U, 12U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::BronzeD() {
    //  A  B  C  D      O  J  N  I
    //  E  F  G  H  ->  E  D  F  A
    //  I  J  K  L      M  L  P  K
    //  M  N  O  P      G  B  H  C
    return Make("BronzeD",
                14U,  9U, 13U,  8U,
                 4U,  3U,  5U,  0U,
                12U, 11U, 15U, 10U,
                 6U,  1U,  7U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::BrassA() {
    //  A  B  C  D      F  P  H  N
    //  E  F  G  H  ->  C  I  A  K
    //  I  J  K  L      G  O  E  M
    //  M  N  O  P      D  L  B  J
    return Make("BrassA",
                 5U, 15U,  7U, 13U,
                 2U,  8U,  0U, 10U,
                 6U, 14U,  4U, 12U,
                 3U, 11U,  1U,  9U
    );
}

Recipe4x4 RecipeFactory4x4::BrassB() {
    //  A  B  C  D      D  G  C  F
    //  E  F  G  H  ->  L  O  I  P
    //  I  J  K  L      B  E  A  H
    //  M  N  O  P      J  M  K  N
    return Make("BrassB",
                 3U,  6U,  2U,  5U,
                11U, 14U,  8U, 15U,
                 1U,  4U,  0U,  7U,
                 9U, 12U, 10U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::BrassC() {
    //  A  B  C  D      J  B  L  D
    //  E  F  G  H  ->  M  E  O  G
    //  I  J  K  L      K  A  I  C
    //  M  N  O  P      N  H  P  F
    return Make("BrassC",
                 9U,  1U, 11U,  3U,
                12U,  4U, 14U,  6U,
                10U,  0U,  8U,  2U,
                13U,  7U, 15U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::BrassD() {
    //  A  B  C  D      N  K  M  J
    //  E  F  G  H  ->  H  A  E  B
    //  I  J  K  L      P  I  O  L
    //  M  N  O  P      F  C  G  D
    return Make("BrassD",
                13U, 10U, 12U,  9U,
                 7U,  0U,  4U,  1U,
                15U,  8U, 14U, 11U,
                 5U,  2U,  6U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::NickelA() {
    //  A  B  C  D      D  J  B  L
    //  E  F  G  H  ->  P  F  N  H
    //  I  J  K  L      M  E  O  G
    //  M  N  O  P      I  A  K  C
    return Make("NickelA",
                 3U,  9U,  1U, 11U,
                15U,  5U, 13U,  7U,
                12U,  4U, 14U,  6U,
                 8U,  0U, 10U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::NickelB() {
    //  A  B  C  D      I  M  P  D
    //  E  F  G  H  ->  A  E  F  J
    //  I  J  K  L      K  O  N  B
    //  M  N  O  P      C  G  H  L
    return Make("NickelB",
                 8U, 12U, 15U,  3U,
                 0U,  4U,  5U,  9U,
                10U, 14U, 13U,  1U,
                 2U,  6U,  7U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::NickelC() {
    //  A  B  C  D      C  K  A  I
    //  E  F  G  H  ->  G  O  E  M
    //  I  J  K  L      H  N  F  P
    //  M  N  O  P      L  B  J  D
    return Make("NickelC",
                 2U, 10U,  0U,  8U,
                 6U, 14U,  4U, 12U,
                 7U, 13U,  5U, 15U,
                11U,  1U,  9U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::NickelD() {
    //  A  B  C  D      L  H  G  C
    //  E  F  G  H  ->  B  N  O  K
    //  I  J  K  L      J  F  E  A
    //  M  N  O  P      D  P  M  I
    return Make("NickelD",
                11U,  7U,  6U,  2U,
                 1U, 13U, 14U, 10U,
                 9U,  5U,  4U,  0U,
                 3U, 15U, 12U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::CobaltA() {
    //  A  B  C  D      P  F  N  H
    //  E  F  G  H  ->  L  B  J  D
    //  I  J  K  L      A  I  C  K
    //  M  N  O  P      M  E  O  G
    return Make("CobaltA",
                15U,  5U, 13U,  7U,
                11U,  1U,  9U,  3U,
                 0U,  8U,  2U, 10U,
                12U,  4U, 14U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::CobaltB() {
    //  A  B  C  D      M  A  L  P
    //  E  F  G  H  ->  E  I  B  F
    //  I  J  K  L      O  C  J  N
    //  M  N  O  P      G  K  D  H
    return Make("CobaltB",
                12U,  0U, 11U, 15U,
                 4U,  8U,  1U,  5U,
                14U,  2U,  9U, 13U,
                 6U, 10U,  3U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::CobaltC() {
    //  A  B  C  D      G  O  E  M
    //  E  F  G  H  ->  K  C  I  A
    //  I  J  K  L      D  J  B  L
    //  M  N  O  P      H  N  F  P
    return Make("CobaltC",
                 6U, 14U,  4U, 12U,
                10U,  2U,  8U,  0U,
                 3U,  9U,  1U, 11U,
                 7U, 13U,  5U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::CobaltD() {
    //  A  B  C  D      H  D  K  G
    //  E  F  G  H  ->  N  J  C  O
    //  I  J  K  L      F  B  I  E
    //  M  N  O  P      P  L  A  M
    return Make("CobaltD",
                 7U,  3U, 10U,  6U,
                13U,  9U,  2U, 14U,
                 5U,  1U,  8U,  4U,
                15U, 11U,  0U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::TitaniumA() {
    //  A  B  C  D      B  J  D  L
    //  E  F  G  H  ->  G  O  E  M
    //  I  J  K  L      A  I  C  K
    //  M  N  O  P      F  N  H  P
    return Make("TitaniumA",
                 1U,  9U,  3U, 11U,
                 6U, 14U,  4U, 12U,
                 0U,  8U,  2U, 10U,
                 5U, 13U,  7U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::TitaniumB() {
    //  A  B  C  D      F  A  G  B
    //  E  F  G  H  ->  N  I  O  J
    //  I  J  K  L      H  C  E  D
    //  M  N  O  P      P  K  M  L
    return Make("TitaniumB",
                 5U,  0U,  6U,  1U,
                13U,  8U, 14U,  9U,
                 7U,  2U,  4U,  3U,
                15U, 10U, 12U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::TitaniumC() {
    //  A  B  C  D      P  H  N  F
    //  E  F  G  H  ->  K  C  I  A
    //  I  J  K  L      M  E  O  G
    //  M  N  O  P      L  D  J  B
    return Make("TitaniumC",
                15U,  7U, 13U,  5U,
                10U,  2U,  8U,  0U,
                12U,  4U, 14U,  6U,
                11U,  3U,  9U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::TitaniumD() {
    //  A  B  C  D      L  M  K  P
    //  E  F  G  H  ->  D  E  C  H
    //  I  J  K  L      J  O  I  N
    //  M  N  O  P      B  G  A  F
    return Make("TitaniumD",
                11U, 12U, 10U, 15U,
                 3U,  4U,  2U,  7U,
                 9U, 14U,  8U, 13U,
                 1U,  6U,  0U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::PlatinumA() {
    //  A  B  C  D      C  K  A  I
    //  E  F  G  H  ->  F  N  H  P
    //  I  J  K  L      B  J  D  L
    //  M  N  O  P      E  M  G  O
    return Make("PlatinumA",
                 2U, 10U,  0U,  8U,
                 5U, 13U,  7U, 15U,
                 1U,  9U,  3U, 11U,
                 4U, 12U,  6U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::PlatinumB() {
    //  A  B  C  D      E  B  F  C
    //  E  F  G  H  ->  M  J  N  K
    //  I  J  K  L      G  D  H  A
    //  M  N  O  P      O  L  P  I
    return Make("PlatinumB",
                 4U,  1U,  5U,  2U,
                12U,  9U, 13U, 10U,
                 6U,  3U,  7U,  0U,
                14U, 11U, 15U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::PlatinumC() {
    //  A  B  C  D      O  G  M  E
    //  E  F  G  H  ->  L  D  J  B
    //  I  J  K  L      P  H  N  F
    //  M  N  O  P      I  A  K  C
    return Make("PlatinumC",
                14U,  6U, 12U,  4U,
                11U,  3U,  9U,  1U,
                15U,  7U, 13U,  5U,
                 8U,  0U, 10U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::PlatinumD() {
    //  A  B  C  D      I  P  L  O
    //  E  F  G  H  ->  A  H  D  G
    //  I  J  K  L      K  N  J  M
    //  M  N  O  P      C  F  B  E
    return Make("PlatinumD",
                 8U, 15U, 11U, 14U,
                 0U,  7U,  3U,  6U,
                10U, 13U,  9U, 12U,
                 2U,  5U,  1U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::TungstenA() {
    //  A  B  C  D      P  H  N  F
    //  E  F  G  H  ->  D  L  B  J
    //  I  J  K  L      K  C  I  A
    //  M  N  O  P      O  G  M  E
    return Make("TungstenA",
                15U,  7U, 13U,  5U,
                 3U, 11U,  1U,  9U,
                10U,  2U,  8U,  0U,
                14U,  6U, 12U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::TungstenB() {
    //  A  B  C  D      O  K  D  P
    //  E  F  G  H  ->  G  C  L  H
    //  I  J  K  L      M  I  B  N
    //  M  N  O  P      E  A  J  F
    return Make("TungstenB",
                14U, 10U,  3U, 15U,
                 6U,  2U, 11U,  7U,
                12U,  8U,  1U, 13U,
                 4U,  0U,  9U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::TungstenC() {
    //  A  B  C  D      E  M  G  O
    //  E  F  G  H  ->  A  I  C  K
    //  I  J  K  L      J  B  L  D
    //  M  N  O  P      F  N  H  P
    return Make("TungstenC",
                 4U, 12U,  6U, 14U,
                 0U,  8U,  2U, 10U,
                 9U,  1U, 11U,  3U,
                 5U, 13U,  7U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::TungstenD() {
    //  A  B  C  D      F  J  A  E
    //  E  F  G  H  ->  N  B  I  M
    //  I  J  K  L      H  L  C  G
    //  M  N  O  P      P  D  K  O
    return Make("TungstenD",
                 5U,  9U,  0U,  4U,
                13U,  1U,  8U, 12U,
                 7U, 11U,  2U,  6U,
                15U,  3U, 10U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::MercuryA() {
    //  A  B  C  D      L  D  J  B
    //  E  F  G  H  ->  P  H  N  F
    //  I  J  K  L      O  G  M  E
    //  M  N  O  P      C  K  A  I
    return Make("MercuryA",
                11U,  3U,  9U,  1U,
                15U,  7U, 13U,  5U,
                14U,  6U, 12U,  4U,
                 2U, 10U,  0U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::MercuryB() {
    //  A  B  C  D      C  O  P  L
    //  E  F  G  H  ->  K  G  H  D
    //  I  J  K  L      A  M  N  J
    //  M  N  O  P      I  E  F  B
    return Make("MercuryB",
                 2U, 14U, 15U, 11U,
                10U,  6U,  7U,  3U,
                 0U, 12U, 13U,  9U,
                 8U,  4U,  5U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::MercuryC() {
    //  A  B  C  D      I  A  K  C
    //  E  F  G  H  ->  E  M  G  O
    //  I  J  K  L      F  N  H  P
    //  M  N  O  P      B  J  D  L
    return Make("MercuryC",
                 8U,  0U, 10U,  2U,
                 4U, 12U,  6U, 14U,
                 5U, 13U,  7U, 15U,
                 1U,  9U,  3U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::MercuryD() {
    //  A  B  C  D      B  F  E  I
    //  E  F  G  H  ->  J  N  M  A
    //  I  J  K  L      D  H  G  K
    //  M  N  O  P      L  P  O  C
    return Make("MercuryD",
                 1U,  5U,  4U,  8U,
                 9U, 13U, 12U,  0U,
                 3U,  7U,  6U, 10U,
                11U, 15U, 14U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::PalladiumA() {
    //  A  B  C  D      P  H  N  F
    //  E  F  G  H  ->  K  C  I  A
    //  I  J  K  L      M  E  O  G
    //  M  N  O  P      L  D  J  B
    return Make("PalladiumA",
                15U,  7U, 13U,  5U,
                10U,  2U,  8U,  0U,
                12U,  4U, 14U,  6U,
                11U,  3U,  9U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::PalladiumB() {
    //  A  B  C  D      L  M  K  P
    //  E  F  G  H  ->  D  E  C  H
    //  I  J  K  L      J  O  I  N
    //  M  N  O  P      B  G  A  F
    return Make("PalladiumB",
                11U, 12U, 10U, 15U,
                 3U,  4U,  2U,  7U,
                 9U, 14U,  8U, 13U,
                 1U,  6U,  0U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::PalladiumC() {
    //  A  B  C  D      B  J  D  L
    //  E  F  G  H  ->  G  O  E  M
    //  I  J  K  L      A  I  C  K
    //  M  N  O  P      F  N  H  P
    return Make("PalladiumC",
                 1U,  9U,  3U, 11U,
                 6U, 14U,  4U, 12U,
                 0U,  8U,  2U, 10U,
                 5U, 13U,  7U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::PalladiumD() {
    //  A  B  C  D      F  A  G  B
    //  E  F  G  H  ->  N  I  O  J
    //  I  J  K  L      H  C  E  D
    //  M  N  O  P      P  K  M  L
    return Make("PalladiumD",
                 5U,  0U,  6U,  1U,
                13U,  8U, 14U,  9U,
                 7U,  2U,  4U,  3U,
                15U, 10U, 12U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::RhodiumA() {
    //  A  B  C  D      O  G  M  E
    //  E  F  G  H  ->  L  D  J  B
    //  I  J  K  L      P  H  N  F
    //  M  N  O  P      I  A  K  C
    return Make("RhodiumA",
                14U,  6U, 12U,  4U,
                11U,  3U,  9U,  1U,
                15U,  7U, 13U,  5U,
                 8U,  0U, 10U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::RhodiumB() {
    //  A  B  C  D      I  P  L  O
    //  E  F  G  H  ->  A  H  D  G
    //  I  J  K  L      K  N  J  M
    //  M  N  O  P      C  F  B  E
    return Make("RhodiumB",
                 8U, 15U, 11U, 14U,
                 0U,  7U,  3U,  6U,
                10U, 13U,  9U, 12U,
                 2U,  5U,  1U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::RhodiumC() {
    //  A  B  C  D      C  K  A  I
    //  E  F  G  H  ->  F  N  H  P
    //  I  J  K  L      B  J  D  L
    //  M  N  O  P      E  M  G  O
    return Make("RhodiumC",
                 2U, 10U,  0U,  8U,
                 5U, 13U,  7U, 15U,
                 1U,  9U,  3U, 11U,
                 4U, 12U,  6U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::RhodiumD() {
    //  A  B  C  D      E  B  F  C
    //  E  F  G  H  ->  M  J  N  K
    //  I  J  K  L      G  D  H  A
    //  M  N  O  P      O  L  P  I
    return Make("RhodiumD",
                 4U,  1U,  5U,  2U,
                12U,  9U, 13U, 10U,
                 6U,  3U,  7U,  0U,
                14U, 11U, 15U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::ChromiumA() {
    //  A  B  C  D      E  M  G  O
    //  E  F  G  H  ->  A  I  C  K
    //  I  J  K  L      J  B  L  D
    //  M  N  O  P      F  N  H  P
    return Make("ChromiumA",
                 4U, 12U,  6U, 14U,
                 0U,  8U,  2U, 10U,
                 9U,  1U, 11U,  3U,
                 5U, 13U,  7U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::ChromiumB() {
    //  A  B  C  D      F  J  A  E
    //  E  F  G  H  ->  N  B  I  M
    //  I  J  K  L      H  L  C  G
    //  M  N  O  P      P  D  K  O
    return Make("ChromiumB",
                 5U,  9U,  0U,  4U,
                13U,  1U,  8U, 12U,
                 7U, 11U,  2U,  6U,
                15U,  3U, 10U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::ChromiumC() {
    //  A  B  C  D      P  H  N  F
    //  E  F  G  H  ->  D  L  B  J
    //  I  J  K  L      K  C  I  A
    //  M  N  O  P      O  G  M  E
    return Make("ChromiumC",
                15U,  7U, 13U,  5U,
                 3U, 11U,  1U,  9U,
                10U,  2U,  8U,  0U,
                14U,  6U, 12U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::ChromiumD() {
    //  A  B  C  D      O  K  D  P
    //  E  F  G  H  ->  G  C  L  H
    //  I  J  K  L      M  I  B  N
    //  M  N  O  P      E  A  J  F
    return Make("ChromiumD",
                14U, 10U,  3U, 15U,
                 6U,  2U, 11U,  7U,
                12U,  8U,  1U, 13U,
                 4U,  0U,  9U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::ZirconiumA() {
    //  A  B  C  D      I  A  K  C
    //  E  F  G  H  ->  E  M  G  O
    //  I  J  K  L      F  N  H  P
    //  M  N  O  P      B  J  D  L
    return Make("ZirconiumA",
                 8U,  0U, 10U,  2U,
                 4U, 12U,  6U, 14U,
                 5U, 13U,  7U, 15U,
                 1U,  9U,  3U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::ZirconiumB() {
    //  A  B  C  D      B  F  E  I
    //  E  F  G  H  ->  J  N  M  A
    //  I  J  K  L      D  H  G  K
    //  M  N  O  P      L  P  O  C
    return Make("ZirconiumB",
                 1U,  5U,  4U,  8U,
                 9U, 13U, 12U,  0U,
                 3U,  7U,  6U, 10U,
                11U, 15U, 14U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::ZirconiumC() {
    //  A  B  C  D      L  D  J  B
    //  E  F  G  H  ->  P  H  N  F
    //  I  J  K  L      O  G  M  E
    //  M  N  O  P      C  K  A  I
    return Make("ZirconiumC",
                11U,  3U,  9U,  1U,
                15U,  7U, 13U,  5U,
                14U,  6U, 12U,  4U,
                 2U, 10U,  0U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::ZirconiumD() {
    //  A  B  C  D      C  O  P  L
    //  E  F  G  H  ->  K  G  H  D
    //  I  J  K  L      A  M  N  J
    //  M  N  O  P      I  E  F  B
    return Make("ZirconiumD",
                 2U, 14U, 15U, 11U,
                10U,  6U,  7U,  3U,
                 0U, 12U, 13U,  9U,
                 8U,  4U,  5U,  1U
    );
}


Recipe4x4 RecipeFactory4x4::HydrogenA() {
    //  A  B  C  D      I  J  F  E
    //  E  F  G  H  ->  M  N  B  A
    //  I  J  K  L      P  O  C  D
    //  M  N  O  P      L  K  G  H
    return Make("HydrogenA",
                 8U,  9U,  5U,  4U,
                12U, 13U,  1U,  0U,
                15U, 14U,  2U,  3U,
                11U, 10U,  6U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::HydrogenB() {
    //  A  B  C  D      L  K  G  H
    //  E  F  G  H  ->  P  O  C  D
    //  I  J  K  L      M  N  B  A
    //  M  N  O  P      I  J  F  E
    return Make("HydrogenB",
                11U, 10U,  6U,  7U,
                15U, 14U,  2U,  3U,
                12U, 13U,  1U,  0U,
                 8U,  9U,  5U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::HydrogenC() {
    //  A  B  C  D      P  O  C  D
    //  E  F  G  H  ->  L  K  G  H
    //  I  J  K  L      I  J  F  E
    //  M  N  O  P      M  N  B  A
    return Make("HydrogenC",
                15U, 14U,  2U,  3U,
                11U, 10U,  6U,  7U,
                 8U,  9U,  5U,  4U,
                12U, 13U,  1U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::HydrogenD() {
    //  A  B  C  D      N  M  A  B
    //  E  F  G  H  ->  J  I  E  F
    //  I  J  K  L      K  L  H  G
    //  M  N  O  P      O  P  D  C
    return Make("HydrogenD",
                13U, 12U,  0U,  1U,
                 9U,  8U,  4U,  5U,
                10U, 11U,  7U,  6U,
                14U, 15U,  3U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::HeliumA() {
    //  A  B  C  D      O  P  D  C
    //  E  F  G  H  ->  K  L  H  G
    //  I  J  K  L      J  I  E  F
    //  M  N  O  P      N  M  A  B
    return Make("HeliumA",
                14U, 15U,  3U,  2U,
                10U, 11U,  7U,  6U,
                 9U,  8U,  4U,  5U,
                13U, 12U,  0U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::HeliumB() {
    //  A  B  C  D      K  L  H  G
    //  E  F  G  H  ->  O  P  D  C
    //  I  J  K  L      N  M  A  B
    //  M  N  O  P      J  I  E  F
    return Make("HeliumB",
                10U, 11U,  7U,  6U,
                14U, 15U,  3U,  2U,
                13U, 12U,  0U,  1U,
                 9U,  8U,  4U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::HeliumC() {
    //  A  B  C  D      H  G  K  L
    //  E  F  G  H  ->  D  C  O  P
    //  I  J  K  L      A  B  N  M
    //  M  N  O  P      E  F  J  I
    return Make("HeliumC",
                 7U,  6U, 10U, 11U,
                 3U,  2U, 14U, 15U,
                 0U,  1U, 13U, 12U,
                 4U,  5U,  9U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::HeliumD() {
    //  A  B  C  D      E  F  J  I
    //  E  F  G  H  ->  A  B  N  M
    //  I  J  K  L      D  C  O  P
    //  M  N  O  P      H  G  K  L
    return Make("HeliumD",
                 4U,  5U,  9U,  8U,
                 0U,  1U, 13U, 12U,
                 3U,  2U, 14U, 15U,
                 7U,  6U, 10U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::NeonA() {
    //  A  B  C  D      A  B  N  M
    //  E  F  G  H  ->  E  F  J  I
    //  I  J  K  L      H  G  K  L
    //  M  N  O  P      D  C  O  P
    return Make("NeonA",
                 0U,  1U, 13U, 12U,
                 4U,  5U,  9U,  8U,
                 7U,  6U, 10U, 11U,
                 3U,  2U, 14U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::NeonB() {
    //  A  B  C  D      C  D  P  O
    //  E  F  G  H  ->  G  H  L  K
    //  I  J  K  L      F  E  I  J
    //  M  N  O  P      B  A  M  N
    return Make("NeonB",
                 2U,  3U, 15U, 14U,
                 6U,  7U, 11U, 10U,
                 5U,  4U,  8U,  9U,
                 1U,  0U, 12U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::NeonC() {
    //  A  B  C  D      B  A  M  N
    //  E  F  G  H  ->  F  E  I  J
    //  I  J  K  L      G  H  L  K
    //  M  N  O  P      C  D  P  O
    return Make("NeonC",
                 1U,  0U, 12U, 13U,
                 5U,  4U,  8U,  9U,
                 6U,  7U, 11U, 10U,
                 2U,  3U, 15U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::NeonD() {
    //  A  B  C  D      F  E  I  J
    //  E  F  G  H  ->  B  A  M  N
    //  I  J  K  L      C  D  P  O
    //  M  N  O  P      G  H  L  K
    return Make("NeonD",
                 5U,  4U,  8U,  9U,
                 1U,  0U, 12U, 13U,
                 2U,  3U, 15U, 14U,
                 6U,  7U, 11U, 10U
    );
}

Recipe4x4 RecipeFactory4x4::ArgonA() {
    //  A  B  C  D      E  A  D  H
    //  E  F  G  H  ->  F  B  C  G
    //  I  J  K  L      J  N  O  K
    //  M  N  O  P      I  M  P  L
    return Make("ArgonA",
                 4U,  0U,  3U,  7U,
                 5U,  1U,  2U,  6U,
                 9U, 13U, 14U, 10U,
                 8U, 12U, 15U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::ArgonB() {
    //  A  B  C  D      A  K  N  H
    //  E  F  G  H  ->  E  O  J  D
    //  I  J  K  L      M  L  B  G
    //  M  N  O  P      I  P  F  C
    return Make("ArgonB",
                 0U, 10U, 13U,  7U,
                 4U, 14U,  9U,  3U,
                12U, 11U,  1U,  6U,
                 8U, 15U,  5U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::ArgonC() {
    //  A  B  C  D      E  O  J  D
    //  E  F  G  H  ->  A  K  N  H
    //  I  J  K  L      I  P  F  C
    //  M  N  O  P      M  L  B  G
    return Make("ArgonC",
                 4U, 14U,  9U,  3U,
                 0U, 10U, 13U,  7U,
                 8U, 15U,  5U,  2U,
                12U, 11U,  1U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::ArgonD() {
    //  A  B  C  D      G  M  L  B
    //  E  F  G  H  ->  C  I  P  F
    //  I  J  K  L      K  N  H  A
    //  M  N  O  P      O  J  D  E
    return Make("ArgonD",
                 6U, 12U, 11U,  1U,
                 2U,  8U, 15U,  5U,
                10U, 13U,  7U,  0U,
                14U,  9U,  3U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::KryptonA() {
    //  A  B  C  D      F  P  I  C
    //  E  F  G  H  ->  B  L  M  G
    //  I  J  K  L      J  O  E  D
    //  M  N  O  P      N  K  A  H
    return Make("KryptonA",
                 5U, 15U,  8U,  2U,
                 1U, 11U, 12U,  6U,
                 9U, 14U,  4U,  3U,
                13U, 10U,  0U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::KryptonB() {
    //  A  B  C  D      B  L  M  G
    //  E  F  G  H  ->  F  P  I  C
    //  I  J  K  L      N  K  A  H
    //  M  N  O  P      J  O  E  D
    return Make("KryptonB",
                 1U, 11U, 12U,  6U,
                 5U, 15U,  8U,  2U,
                13U, 10U,  0U,  7U,
                 9U, 14U,  4U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::KryptonC() {
    //  A  B  C  D      M  G  B  L
    //  E  F  G  H  ->  I  C  F  P
    //  I  J  K  L      A  H  N  K
    //  M  N  O  P      E  D  J  O
    return Make("KryptonC",
                12U,  6U,  1U, 11U,
                 8U,  2U,  5U, 15U,
                 0U,  7U, 13U, 10U,
                 4U,  3U,  9U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::KryptonD() {
    //  A  B  C  D      P  F  C  I
    //  E  F  G  H  ->  L  B  G  M
    //  I  J  K  L      D  E  O  J
    //  M  N  O  P      H  A  K  N
    return Make("KryptonD",
                15U,  5U,  2U,  8U,
                11U,  1U,  6U, 12U,
                 3U,  4U, 14U,  9U,
                 7U,  0U, 10U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::XenonA() {
    //  A  B  C  D      L  B  G  M
    //  E  F  G  H  ->  P  F  C  I
    //  I  J  K  L      H  A  K  N
    //  M  N  O  P      D  E  O  J
    return Make("XenonA",
                11U,  1U,  6U, 12U,
                15U,  5U,  2U,  8U,
                 7U,  0U, 10U, 13U,
                 3U,  4U, 14U,  9U
    );
}

Recipe4x4 RecipeFactory4x4::XenonB() {
    //  A  B  C  D      J  D  E  O
    //  E  F  G  H  ->  N  H  A  K
    //  I  J  K  L      F  C  I  P
    //  M  N  O  P      B  G  M  L
    return Make("XenonB",
                 9U,  3U,  4U, 14U,
                13U,  7U,  0U, 10U,
                 5U,  2U,  8U, 15U,
                 1U,  6U, 12U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::XenonC() {
    //  A  B  C  D      K  A  H  N
    //  E  F  G  H  ->  O  E  D  J
    //  I  J  K  L      G  B  L  M
    //  M  N  O  P      C  F  P  I
    return Make("XenonC",
                10U,  0U,  7U, 13U,
                14U,  4U,  3U,  9U,
                 6U,  1U, 11U, 12U,
                 2U,  5U, 15U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::XenonD() {
    //  A  B  C  D      O  E  D  J
    //  E  F  G  H  ->  K  A  H  N
    //  I  J  K  L      C  F  P  I
    //  M  N  O  P      G  B  L  M
    return Make("XenonD",
                14U,  4U,  3U,  9U,
                10U,  0U,  7U, 13U,
                 2U,  5U, 15U,  8U,
                 6U,  1U, 11U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::RadonA() {
    //  A  B  C  D      I  P  F  C
    //  E  F  G  H  ->  M  L  B  G
    //  I  J  K  L      J  O  E  D
    //  M  N  O  P      N  K  A  H
    return Make("RadonA",
                 8U, 15U,  5U,  2U,
                12U, 11U,  1U,  6U,
                 9U, 14U,  4U,  3U,
                13U, 10U,  0U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::RadonB() {
    //  A  B  C  D      L  M  G  B
    //  E  F  G  H  ->  P  I  C  F
    //  I  J  K  L      K  N  H  A
    //  M  N  O  P      O  J  D  E
    return Make("RadonB",
                11U, 12U,  6U,  1U,
                15U,  8U,  2U,  5U,
                10U, 13U,  7U,  0U,
                14U,  9U,  3U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::RadonC() {
    //  A  B  C  D      P  I  C  F
    //  E  F  G  H  ->  L  M  G  B
    //  I  J  K  L      O  J  D  E
    //  M  N  O  P      K  N  H  A
    return Make("RadonC",
                15U,  8U,  2U,  5U,
                11U, 12U,  6U,  1U,
                14U,  9U,  3U,  4U,
                10U, 13U,  7U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::RadonD() {
    //  A  B  C  D      N  K  A  H
    //  E  F  G  H  ->  J  O  E  D
    //  I  J  K  L      M  L  B  G
    //  M  N  O  P      I  P  F  C
    return Make("RadonD",
                13U, 10U,  0U,  7U,
                 9U, 14U,  4U,  3U,
                12U, 11U,  1U,  6U,
                 8U, 15U,  5U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::FluorineA() {
    //  A  B  C  D      O  J  D  E
    //  E  F  G  H  ->  K  N  H  A
    //  I  J  K  L      P  I  C  F
    //  M  N  O  P      L  M  G  B
    return Make("FluorineA",
                14U,  9U,  3U,  4U,
                10U, 13U,  7U,  0U,
                15U,  8U,  2U,  5U,
                11U, 12U,  6U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::FluorineB() {
    //  A  B  C  D      K  N  H  A
    //  E  F  G  H  ->  O  J  D  E
    //  I  J  K  L      L  M  G  B
    //  M  N  O  P      P  I  C  F
    return Make("FluorineB",
                10U, 13U,  7U,  0U,
                14U,  9U,  3U,  4U,
                11U, 12U,  6U,  1U,
                15U,  8U,  2U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::FluorineC() {
    //  A  B  C  D      H  A  K  N
    //  E  F  G  H  ->  D  E  O  J
    //  I  J  K  L      G  B  L  M
    //  M  N  O  P      C  F  P  I
    return Make("FluorineC",
                 7U,  0U, 10U, 13U,
                 3U,  4U, 14U,  9U,
                 6U,  1U, 11U, 12U,
                 2U,  5U, 15U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::FluorineD() {
    //  A  B  C  D      E  D  J  O
    //  E  F  G  H  ->  A  H  N  K
    //  I  J  K  L      F  C  I  P
    //  M  N  O  P      B  G  M  L
    return Make("FluorineD",
                 4U,  3U,  9U, 14U,
                 0U,  7U, 13U, 10U,
                 5U,  2U,  8U, 15U,
                 1U,  6U, 12U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::ChlorineA() {
    //  A  B  C  D      A  H  N  K
    //  E  F  G  H  ->  E  D  J  O
    //  I  J  K  L      B  G  M  L
    //  M  N  O  P      F  C  I  P
    return Make("ChlorineA",
                 0U,  7U, 13U, 10U,
                 4U,  3U,  9U, 14U,
                 1U,  6U, 12U, 11U,
                 5U,  2U,  8U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::ChlorineB() {
    //  A  B  C  D      C  F  P  I
    //  E  F  G  H  ->  G  B  L  M
    //  I  J  K  L      D  E  O  J
    //  M  N  O  P      H  A  K  N
    return Make("ChlorineB",
                 2U,  5U, 15U,  8U,
                 6U,  1U, 11U, 12U,
                 3U,  4U, 14U,  9U,
                 7U,  0U, 10U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::ChlorineC() {
    //  A  B  C  D      B  G  M  L
    //  E  F  G  H  ->  F  C  I  P
    //  I  J  K  L      A  H  N  K
    //  M  N  O  P      E  D  J  O
    return Make("ChlorineC",
                 1U,  6U, 12U, 11U,
                 5U,  2U,  8U, 15U,
                 0U,  7U, 13U, 10U,
                 4U,  3U,  9U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::ChlorineD() {
    //  A  B  C  D      F  C  I  P
    //  E  F  G  H  ->  B  G  M  L
    //  I  J  K  L      E  D  J  O
    //  M  N  O  P      A  H  N  K
    return Make("ChlorineD",
                 5U,  2U,  8U, 15U,
                 1U,  6U, 12U, 11U,
                 4U,  3U,  9U, 14U,
                 0U,  7U, 13U, 10U
    );
}


Recipe4x4 RecipeFactory4x4::MapleA() {
    //  A  B  C  D      N  M  I  J
    //  E  F  G  H  ->  B  A  E  F
    //  I  J  K  L      C  D  H  G
    //  M  N  O  P      O  P  L  K
    return Make("MapleA",
                13U, 12U,  8U,  9U,
                 1U,  0U,  4U,  5U,
                 2U,  3U,  7U,  6U,
                14U, 15U, 11U, 10U
    );
}

Recipe4x4 RecipeFactory4x4::MapleB() {
    //  A  B  C  D      F  E  A  B
    //  E  F  G  H  ->  J  I  M  N
    //  I  J  K  L      K  L  P  O
    //  M  N  O  P      G  H  D  C
    return Make("MapleB",
                 5U,  4U,  0U,  1U,
                 9U,  8U, 12U, 13U,
                10U, 11U, 15U, 14U,
                 6U,  7U,  3U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::MapleC() {
    //  A  B  C  D      P  M  A  D
    //  E  F  G  H  ->  L  I  E  H
    //  I  J  K  L      K  J  F  G
    //  M  N  O  P      O  N  B  C
    return Make("MapleC",
                15U, 12U,  0U,  3U,
                11U,  8U,  4U,  7U,
                10U,  9U,  5U,  6U,
                14U, 13U,  1U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::MapleD() {
    //  A  B  C  D      N  O  C  B
    //  E  F  G  H  ->  J  K  G  F
    //  I  J  K  L      I  L  H  E
    //  M  N  O  P      M  P  D  A
    return Make("MapleD",
                13U, 14U,  2U,  1U,
                 9U, 10U,  6U,  5U,
                 8U, 11U,  7U,  4U,
                12U, 15U,  3U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::WillowA() {
    //  A  B  C  D      L  K  O  P
    //  E  F  G  H  ->  H  G  C  D
    //  I  J  K  L      E  F  B  A
    //  M  N  O  P      I  J  N  M
    return Make("WillowA",
                11U, 10U, 14U, 15U,
                 7U,  6U,  2U,  3U,
                 4U,  5U,  1U,  0U,
                 8U,  9U, 13U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::WillowB() {
    //  A  B  C  D      D  C  G  H
    //  E  F  G  H  ->  P  O  K  L
    //  I  J  K  L      M  N  J  I
    //  M  N  O  P      A  B  F  E
    return Make("WillowB",
                 3U,  2U,  6U,  7U,
                15U, 14U, 10U, 11U,
                12U, 13U,  9U,  8U,
                 0U,  1U,  5U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::WillowC() {
    //  A  B  C  D      J  K  G  F
    //  E  F  G  H  ->  N  O  C  B
    //  I  J  K  L      M  P  D  A
    //  M  N  O  P      I  L  H  E
    return Make("WillowC",
                 9U, 10U,  6U,  5U,
                13U, 14U,  2U,  1U,
                12U, 15U,  3U,  0U,
                 8U, 11U,  7U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::WillowD() {
    //  A  B  C  D      L  I  E  H
    //  E  F  G  H  ->  P  M  A  D
    //  I  J  K  L      O  N  B  C
    //  M  N  O  P      K  J  F  G
    return Make("WillowD",
                11U,  8U,  4U,  7U,
                15U, 12U,  0U,  3U,
                14U, 13U,  1U,  2U,
                10U,  9U,  5U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::BirchA() {
    //  A  B  C  D      M  N  J  I
    //  E  F  G  H  ->  A  B  F  E
    //  I  J  K  L      D  C  G  H
    //  M  N  O  P      P  O  K  L
    return Make("BirchA",
                12U, 13U,  9U,  8U,
                 0U,  1U,  5U,  4U,
                 3U,  2U,  6U,  7U,
                15U, 14U, 10U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::BirchB() {
    //  A  B  C  D      E  F  B  A
    //  E  F  G  H  ->  I  J  N  M
    //  I  J  K  L      L  K  O  P
    //  M  N  O  P      H  G  C  D
    return Make("BirchB",
                 4U,  5U,  1U,  0U,
                 8U,  9U, 13U, 12U,
                11U, 10U, 14U, 15U,
                 7U,  6U,  2U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::BirchC() {
    //  A  B  C  D      O  N  B  C
    //  E  F  G  H  ->  K  J  F  G
    //  I  J  K  L      L  I  E  H
    //  M  N  O  P      P  M  A  D
    return Make("BirchC",
                14U, 13U,  1U,  2U,
                10U,  9U,  5U,  6U,
                11U,  8U,  4U,  7U,
                15U, 12U,  0U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::BirchD() {
    //  A  B  C  D      M  P  D  A
    //  E  F  G  H  ->  I  L  H  E
    //  I  J  K  L      J  K  G  F
    //  M  N  O  P      N  O  C  B
    return Make("BirchD",
                12U, 15U,  3U,  0U,
                 8U, 11U,  7U,  4U,
                 9U, 10U,  6U,  5U,
                13U, 14U,  2U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::CedarA() {
    //  A  B  C  D      K  L  P  O
    //  E  F  G  H  ->  G  H  D  C
    //  I  J  K  L      F  E  A  B
    //  M  N  O  P      J  I  M  N
    return Make("CedarA",
                10U, 11U, 15U, 14U,
                 6U,  7U,  3U,  2U,
                 5U,  4U,  0U,  1U,
                 9U,  8U, 12U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::CedarB() {
    //  A  B  C  D      C  D  H  G
    //  E  F  G  H  ->  O  P  L  K
    //  I  J  K  L      N  M  I  J
    //  M  N  O  P      B  A  E  F
    return Make("CedarB",
                 2U,  3U,  7U,  6U,
                14U, 15U, 11U, 10U,
                13U, 12U,  8U,  9U,
                 1U,  0U,  4U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::CedarC() {
    //  A  B  C  D      M  P  D  A
    //  E  F  G  H  ->  I  L  H  E
    //  I  J  K  L      J  K  G  F
    //  M  N  O  P      N  O  C  B
    return Make("CedarC",
                12U, 15U,  3U,  0U,
                 8U, 11U,  7U,  4U,
                 9U, 10U,  6U,  5U,
                13U, 14U,  2U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::CedarD() {
    //  A  B  C  D      O  N  B  C
    //  E  F  G  H  ->  K  J  F  G
    //  I  J  K  L      L  I  E  H
    //  M  N  O  P      P  M  A  D
    return Make("CedarD",
                14U, 13U,  1U,  2U,
                10U,  9U,  5U,  6U,
                11U,  8U,  4U,  7U,
                15U, 12U,  0U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::HickoryA() {
    //  A  B  C  D      M  L  K  P
    //  E  F  G  H  ->  N  I  J  O
    //  I  J  K  L      A  F  G  B
    //  M  N  O  P      D  E  H  C
    return Make("HickoryA",
                12U, 11U, 10U, 15U,
                13U,  8U,  9U, 14U,
                 0U,  5U,  6U,  1U,
                 3U,  4U,  7U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::HickoryB() {
    //  A  B  C  D      O  J  I  N
    //  E  F  G  H  ->  P  K  L  M
    //  I  J  K  L      C  H  E  D
    //  M  N  O  P      B  G  F  A
    return Make("HickoryB",
                14U,  9U,  8U, 13U,
                15U, 10U, 11U, 12U,
                 2U,  7U,  4U,  3U,
                 1U,  6U,  5U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::HickoryC() {
    //  A  B  C  D      E  L  I  F
    //  E  F  G  H  ->  H  K  J  G
    //  I  J  K  L      C  P  O  B
    //  M  N  O  P      D  M  N  A
    return Make("HickoryC",
                 4U, 11U,  8U,  5U,
                 7U, 10U,  9U,  6U,
                 2U, 15U, 14U,  1U,
                 3U, 12U, 13U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::HickoryD() {
    //  A  B  C  D      M  D  A  N
    //  E  F  G  H  ->  P  C  B  O
    //  I  J  K  L      K  H  G  J
    //  M  N  O  P      L  E  F  I
    return Make("HickoryD",
                12U,  3U,  0U, 13U,
                15U,  2U,  1U, 14U,
                10U,  7U,  6U,  9U,
                11U,  4U,  5U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::JuniperA() {
    //  A  B  C  D      B  F  I  E
    //  E  F  G  H  ->  G  K  H  D
    //  I  J  K  L      C  O  L  P
    //  M  N  O  P      N  J  M  A
    return Make("JuniperA",
                 1U,  5U,  8U,  4U,
                 6U, 10U,  7U,  3U,
                 2U, 14U, 11U, 15U,
                13U,  9U, 12U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::JuniperB() {
    //  A  B  C  D      D  H  K  G
    //  E  F  G  H  ->  E  I  F  B
    //  I  J  K  L      A  M  J  N
    //  M  N  O  P      P  L  O  C
    return Make("JuniperB",
                 3U,  7U, 10U,  6U,
                 4U,  8U,  5U,  1U,
                 0U, 12U,  9U, 13U,
                15U, 11U, 14U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::JuniperC() {
    //  A  B  C  D      J  F  K  O
    //  E  F  G  H  ->  M  I  H  L
    //  I  J  K  L      A  E  D  P
    //  M  N  O  P      N  B  G  C
    return Make("JuniperC",
                 9U,  5U, 10U, 14U,
                12U,  8U,  7U, 11U,
                 0U,  4U,  3U, 15U,
                13U,  1U,  6U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::JuniperD() {
    //  A  B  C  D      B  N  C  G
    //  E  F  G  H  ->  E  A  P  D
    //  I  J  K  L      I  M  L  H
    //  M  N  O  P      F  J  O  K
    return Make("JuniperD",
                 1U, 13U,  2U,  6U,
                 4U,  0U, 15U,  3U,
                 8U, 12U, 11U,  7U,
                 5U,  9U, 14U, 10U
    );
}

Recipe4x4 RecipeFactory4x4::YorkA() {
    //  A  B  C  D      D  J  O  E
    //  E  F  G  H  ->  H  N  K  A
    //  I  J  K  L      P  I  C  F
    //  M  N  O  P      L  M  G  B
    return Make("YorkA",
                 3U,  9U, 14U,  4U,
                 7U, 13U, 10U,  0U,
                15U,  8U,  2U,  5U,
                11U, 12U,  6U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::YorkB() {
    //  A  B  C  D      I  P  F  C
    //  E  F  G  H  ->  M  L  B  G
    //  I  J  K  L      E  O  J  D
    //  M  N  O  P      A  K  N  H
    return Make("YorkB",
                 8U, 15U,  5U,  2U,
                12U, 11U,  1U,  6U,
                 4U, 14U,  9U,  3U,
                 0U, 10U, 13U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::YorkC() {
    //  A  B  C  D      O  J  D  E
    //  E  F  G  H  ->  K  N  H  A
    //  I  J  K  L      P  F  C  I
    //  M  N  O  P      L  B  G  M
    return Make("YorkC",
                14U,  9U,  3U,  4U,
                10U, 13U,  7U,  0U,
                15U,  5U,  2U,  8U,
                11U,  1U,  6U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::YorkD() {
    //  A  B  C  D      I  C  F  P
    //  E  F  G  H  ->  M  G  B  L
    //  I  J  K  L      J  O  E  D
    //  M  N  O  P      N  K  A  H
    return Make("YorkD",
                 8U,  2U,  5U, 15U,
                12U,  6U,  1U, 11U,
                 9U, 14U,  4U,  3U,
                13U, 10U,  0U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::EssexA() {
    //  A  B  C  D      H  A  K  N
    //  E  F  G  H  ->  D  E  O  J
    //  I  J  K  L      G  M  L  B
    //  M  N  O  P      C  I  P  F
    return Make("EssexA",
                 7U,  0U, 10U, 13U,
                 3U,  4U, 14U,  9U,
                 6U, 12U, 11U,  1U,
                 2U,  8U, 15U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::EssexB() {
    //  A  B  C  D      O  J  D  E
    //  E  F  G  H  ->  K  N  H  A
    //  I  J  K  L      C  I  P  F
    //  M  N  O  P      G  M  L  B
    return Make("EssexB",
                14U,  9U,  3U,  4U,
                10U, 13U,  7U,  0U,
                 2U,  8U, 15U,  5U,
                 6U, 12U, 11U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::EssexC() {
    //  A  B  C  D      I  P  F  C
    //  E  F  G  H  ->  M  L  B  G
    //  I  J  K  L      J  D  E  O
    //  M  N  O  P      N  H  A  K
    return Make("EssexC",
                 8U, 15U,  5U,  2U,
                12U, 11U,  1U,  6U,
                 9U,  3U,  4U, 14U,
                13U,  7U,  0U, 10U
    );
}

Recipe4x4 RecipeFactory4x4::EssexD() {
    //  A  B  C  D      O  E  D  J
    //  E  F  G  H  ->  K  A  H  N
    //  I  J  K  L      P  I  C  F
    //  M  N  O  P      L  M  G  B
    return Make("EssexD",
                14U,  4U,  3U,  9U,
                10U,  0U,  7U, 13U,
                15U,  8U,  2U,  5U,
                11U, 12U,  6U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::WessexA() {
    //  A  B  C  D      C  I  P  F
    //  E  F  G  H  ->  G  M  L  B
    //  I  J  K  L      O  J  D  E
    //  M  N  O  P      K  N  H  A
    return Make("WessexA",
                 2U,  8U, 15U,  5U,
                 6U, 12U, 11U,  1U,
                14U,  9U,  3U,  4U,
                10U, 13U,  7U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::WessexB() {
    //  A  B  C  D      J  O  E  D
    //  E  F  G  H  ->  N  K  A  H
    //  I  J  K  L      F  P  I  C
    //  M  N  O  P      B  L  M  G
    return Make("WessexB",
                 9U, 14U,  4U,  3U,
                13U, 10U,  0U,  7U,
                 5U, 15U,  8U,  2U,
                 1U, 11U, 12U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::WessexC() {
    //  A  B  C  D      P  I  C  F
    //  E  F  G  H  ->  L  M  G  B
    //  I  J  K  L      O  E  D  J
    //  M  N  O  P      K  A  H  N
    return Make("WessexC",
                15U,  8U,  2U,  5U,
                11U, 12U,  6U,  1U,
                14U,  4U,  3U,  9U,
                10U,  0U,  7U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::WessexD() {
    //  A  B  C  D      J  D  E  O
    //  E  F  G  H  ->  N  H  A  K
    //  I  J  K  L      I  P  F  C
    //  M  N  O  P      M  L  B  G
    return Make("WessexD",
                 9U,  3U,  4U, 14U,
                13U,  7U,  0U, 10U,
                 8U, 15U,  5U,  2U,
                12U, 11U,  1U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::MerciaA() {
    //  A  B  C  D      C  F  P  I
    //  E  F  G  H  ->  G  B  L  M
    //  I  J  K  L      D  J  O  E
    //  M  N  O  P      H  N  K  A
    return Make("MerciaA",
                 2U,  5U, 15U,  8U,
                 6U,  1U, 11U, 12U,
                 3U,  9U, 14U,  4U,
                 7U, 13U, 10U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::MerciaB() {
    //  A  B  C  D      L  M  G  B
    //  E  F  G  H  ->  P  I  C  F
    //  I  J  K  L      H  N  K  A
    //  M  N  O  P      D  J  O  E
    return Make("MerciaB",
                11U, 12U,  6U,  1U,
                15U,  8U,  2U,  5U,
                 7U, 13U, 10U,  0U,
                 3U,  9U, 14U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::MerciaC() {
    //  A  B  C  D      N  K  A  H
    //  E  F  G  H  ->  J  O  E  D
    //  I  J  K  L      M  G  B  L
    //  M  N  O  P      I  C  F  P
    return Make("MerciaC",
                13U, 10U,  0U,  7U,
                 9U, 14U,  4U,  3U,
                12U,  6U,  1U, 11U,
                 8U,  2U,  5U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::MerciaD() {
    //  A  B  C  D      L  B  G  M
    //  E  F  G  H  ->  P  F  C  I
    //  I  J  K  L      K  N  H  A
    //  M  N  O  P      O  J  D  E
    return Make("MerciaD",
                11U,  1U,  6U, 12U,
                15U,  5U,  2U,  8U,
                10U, 13U,  7U,  0U,
                14U,  9U,  3U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::SussexA() {
    //  A  B  C  D      C  I  M  G
    //  E  F  G  H  ->  F  P  J  D
    //  I  J  K  L      N  L  B  H
    //  M  N  O  P      K  O  E  A
    return Make("SussexA",
                 2U,  8U, 12U,  6U,
                 5U, 15U,  9U,  3U,
                13U, 11U,  1U,  7U,
                10U, 14U,  4U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::SussexB() {
    //  A  B  C  D      L  N  H  B
    //  E  F  G  H  ->  O  K  A  E
    //  I  J  K  L      G  M  I  C
    //  M  N  O  P      D  J  P  F
    return Make("SussexB",
                11U, 13U,  7U,  1U,
                14U, 10U,  0U,  4U,
                 6U, 12U,  8U,  2U,
                 3U,  9U, 15U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::SussexC() {
    //  A  B  C  D      M  I  C  G
    //  E  F  G  H  ->  J  P  F  D
    //  I  J  K  L      N  H  B  L
    //  M  N  O  P      K  A  E  O
    return Make("SussexC",
                12U,  8U,  2U,  6U,
                 9U, 15U,  5U,  3U,
                13U,  7U,  1U, 11U,
                10U,  0U,  4U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::SussexD() {
    //  A  B  C  D      L  B  H  N
    //  E  F  G  H  ->  O  E  A  K
    //  I  J  K  L      I  M  G  C
    //  M  N  O  P      P  J  D  F
    return Make("SussexD",
                11U,  1U,  7U, 13U,
                14U,  4U,  0U, 10U,
                 8U, 12U,  6U,  2U,
                15U,  9U,  3U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::UmbriaA() {
    //  A  B  C  D      A  K  B  L
    //  E  F  G  H  ->  E  O  N  H
    //  I  J  K  L      M  P  F  G
    //  M  N  O  P      I  D  J  C
    return Make("UmbriaA",
                 0U, 10U,  1U, 11U,
                 4U, 14U, 13U,  7U,
                12U, 15U,  5U,  6U,
                 8U,  3U,  9U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::UmbriaB() {
    //  A  B  C  D      P  M  G  F
    //  E  F  G  H  ->  D  I  C  J
    //  I  J  K  L      L  B  K  A
    //  M  N  O  P      H  N  O  E
    return Make("UmbriaB",
                15U, 12U,  6U,  5U,
                 3U,  8U,  2U,  9U,
                11U,  1U, 10U,  0U,
                 7U, 13U, 14U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::UmbriaC() {
    //  A  B  C  D      B  K  A  L
    //  E  F  G  H  ->  N  O  E  H
    //  I  J  K  L      M  G  F  P
    //  M  N  O  P      I  C  J  D
    return Make("UmbriaC",
                 1U, 10U,  0U, 11U,
                13U, 14U,  4U,  7U,
                12U,  6U,  5U, 15U,
                 8U,  2U,  9U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::UmbriaD() {
    //  A  B  C  D      P  F  G  M
    //  E  F  G  H  ->  D  J  C  I
    //  I  J  K  L      K  B  L  A
    //  M  N  O  P      O  N  H  E
    return Make("UmbriaD",
                15U,  5U,  6U, 12U,
                 3U,  9U,  2U,  8U,
                10U,  1U, 11U,  0U,
                14U, 13U,  7U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::TokyoA() {
    //  A  B  C  D      E  B  D  G
    //  E  F  G  H  ->  N  F  K  C
    //  I  J  K  L      J  M  O  L
    //  M  N  O  P      A  I  H  P
    return Make("TokyoA",
                 4U,  1U,  3U,  6U,
                13U,  5U, 10U,  2U,
                 9U, 12U, 14U, 11U,
                 0U,  8U,  7U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::TokyoB() {
    //  A  B  C  D      A  F  H  C
    //  E  F  G  H  ->  E  M  D  L
    //  I  J  K  L      N  I  K  P
    //  M  N  O  P      J  B  O  G
    return Make("TokyoB",
                 0U,  5U,  7U,  2U,
                 4U, 12U,  3U, 11U,
                13U,  8U, 10U, 15U,
                 9U,  1U, 14U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::TokyoC() {
    //  A  B  C  D      K  L  N  M
    //  E  F  G  H  ->  I  O  P  J
    //  I  J  K  L      H  G  A  B
    //  M  N  O  P      F  D  C  E
    return Make("TokyoC",
                10U, 11U, 13U, 12U,
                 8U, 14U, 15U,  9U,
                 7U,  6U,  0U,  1U,
                 5U,  3U,  2U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::TokyoD() {
    //  A  B  C  D      M  K  L  N
    //  E  F  G  H  ->  O  P  J  I
    //  I  J  K  L      B  H  G  A
    //  M  N  O  P      D  C  E  F
    return Make("TokyoD",
                12U, 10U, 11U, 13U,
                14U, 15U,  9U,  8U,
                 1U,  7U,  6U,  0U,
                 3U,  2U,  4U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::KyotoA() {
    //  A  B  C  D      N  I  K  P
    //  E  F  G  H  ->  J  B  O  G
    //  I  J  K  L      A  F  H  C
    //  M  N  O  P      E  M  D  L
    return Make("KyotoA",
                13U,  8U, 10U, 15U,
                 9U,  1U, 14U,  6U,
                 0U,  5U,  7U,  2U,
                 4U, 12U,  3U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::KyotoB() {
    //  A  B  C  D      J  M  O  L
    //  E  F  G  H  ->  A  I  H  P
    //  I  J  K  L      E  B  D  G
    //  M  N  O  P      N  F  K  C
    return Make("KyotoB",
                 9U, 12U, 14U, 11U,
                 0U,  8U,  7U, 15U,
                 4U,  1U,  3U,  6U,
                13U,  5U, 10U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::KyotoC() {
    //  A  B  C  D      K  L  N  M
    //  E  F  G  H  ->  P  J  I  O
    //  I  J  K  L      H  G  A  B
    //  M  N  O  P      C  E  F  D
    return Make("KyotoC",
                10U, 11U, 13U, 12U,
                15U,  9U,  8U, 14U,
                 7U,  6U,  0U,  1U,
                 2U,  4U,  5U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::KyotoD() {
    //  A  B  C  D      L  N  M  K
    //  E  F  G  H  ->  O  P  J  I
    //  I  J  K  L      G  A  B  H
    //  M  N  O  P      D  C  E  F
    return Make("KyotoD",
                11U, 13U, 12U, 10U,
                14U, 15U,  9U,  8U,
                 6U,  0U,  1U,  7U,
                 3U,  2U,  4U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::OsakaA() {
    //  A  B  C  D      K  H  O  L
    //  E  F  G  H  ->  G  P  C  D
    //  I  J  K  L      E  B  A  N
    //  M  N  O  P      I  J  M  F
    return Make("OsakaA",
                10U,  7U, 14U, 11U,
                 6U, 15U,  2U,  3U,
                 4U,  1U,  0U, 13U,
                 8U,  9U, 12U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::OsakaB() {
    //  A  B  C  D      H  O  L  K
    //  E  F  G  H  ->  D  G  P  C
    //  I  J  K  L      B  A  N  E
    //  M  N  O  P      F  I  J  M
    return Make("OsakaB",
                 7U, 14U, 11U, 10U,
                 3U,  6U, 15U,  2U,
                 1U,  0U, 13U,  4U,
                 5U,  8U,  9U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::OsakaC() {
    //  A  B  C  D      A  M  E  I
    //  E  F  G  H  ->  J  L  F  H
    //  I  J  K  L      O  C  K  G
    //  M  N  O  P      P  N  D  B
    return Make("OsakaC",
                 0U, 12U,  4U,  8U,
                 9U, 11U,  5U,  7U,
                14U,  2U, 10U,  6U,
                15U, 13U,  3U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::OsakaD() {
    //  A  B  C  D      J  N  F  B
    //  E  F  G  H  ->  O  M  K  I
    //  I  J  K  L      P  L  D  H
    //  M  N  O  P      A  C  E  G
    return Make("OsakaD",
                 9U, 13U,  5U,  1U,
                14U, 12U, 10U,  8U,
                15U, 11U,  3U,  7U,
                 0U,  2U,  4U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::NaraA() {
    //  A  B  C  D      L  K  M  N
    //  E  F  G  H  ->  O  I  J  P
    //  I  J  K  L      G  H  B  A
    //  M  N  O  P      D  F  E  C
    return Make("NaraA",
                11U, 10U, 12U, 13U,
                14U,  8U,  9U, 15U,
                 6U,  7U,  1U,  0U,
                 3U,  5U,  4U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::NaraB() {
    //  A  B  C  D      K  M  N  L
    //  E  F  G  H  ->  P  O  I  J
    //  I  J  K  L      H  B  A  G
    //  M  N  O  P      C  D  F  E
    return Make("NaraB",
                10U, 12U, 13U, 11U,
                15U, 14U,  8U,  9U,
                 7U,  1U,  0U,  6U,
                 2U,  3U,  5U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::NaraC() {
    //  A  B  C  D      B  E  G  D
    //  E  F  G  H  ->  F  N  C  K
    //  I  J  K  L      M  J  L  O
    //  M  N  O  P      I  A  P  H
    return Make("NaraC",
                 1U,  4U,  6U,  3U,
                 5U, 13U,  2U, 10U,
                12U,  9U, 11U, 14U,
                 8U,  0U, 15U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::NaraD() {
    //  A  B  C  D      F  A  C  H
    //  E  F  G  H  ->  M  E  L  D
    //  I  J  K  L      I  N  P  K
    //  M  N  O  P      B  J  G  O
    return Make("NaraD",
                 5U,  0U,  2U,  7U,
                12U,  4U, 11U,  3U,
                 8U, 13U, 15U, 10U,
                 1U,  9U,  6U, 14U
    );
}

Recipe4x4 RecipeFactory4x4::KobeA() {
    //  A  B  C  D      J  B  O  G
    //  E  F  G  H  ->  N  I  K  P
    //  I  J  K  L      E  M  D  L
    //  M  N  O  P      A  F  H  C
    return Make("KobeA",
                 9U,  1U, 14U,  6U,
                13U,  8U, 10U, 15U,
                 4U, 12U,  3U, 11U,
                 0U,  5U,  7U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::KobeB() {
    //  A  B  C  D      A  I  H  P
    //  E  F  G  H  ->  J  M  O  L
    //  I  J  K  L      N  F  K  C
    //  M  N  O  P      E  B  D  G
    return Make("KobeB",
                 0U,  8U,  7U, 15U,
                 9U, 12U, 14U, 11U,
                13U,  5U, 10U,  2U,
                 4U,  1U,  3U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::KobeC() {
    //  A  B  C  D      C  E  F  D
    //  E  F  G  H  ->  H  G  A  B
    //  I  J  K  L      P  J  I  O
    //  M  N  O  P      K  L  N  M
    return Make("KobeC",
                 2U,  4U,  5U,  3U,
                 7U,  6U,  0U,  1U,
                15U,  9U,  8U, 14U,
                10U, 11U, 13U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::KobeD() {
    //  A  B  C  D      D  C  E  F
    //  E  F  G  H  ->  G  A  B  H
    //  I  J  K  L      O  P  J  I
    //  M  N  O  P      L  N  M  K
    return Make("KobeD",
                 3U,  2U,  4U,  5U,
                 6U,  0U,  1U,  7U,
                14U, 15U,  9U,  8U,
                11U, 13U, 12U, 10U
    );
}

Recipe4x4 RecipeFactory4x4::SapporoA() {
    //  A  B  C  D      P  H  I  A
    //  E  F  G  H  ->  G  D  B  E
    //  I  J  K  L      C  K  F  N
    //  M  N  O  P      L  O  M  J
    return Make("SapporoA",
                15U,  7U,  8U,  0U,
                 6U,  3U,  1U,  4U,
                 2U, 10U,  5U, 13U,
                11U, 14U, 12U,  9U
    );
}

Recipe4x4 RecipeFactory4x4::SapporoB() {
    //  A  B  C  D      G  O  B  J
    //  E  F  G  H  ->  C  H  F  A
    //  I  J  K  L      L  D  M  E
    //  M  N  O  P      P  K  I  N
    return Make("SapporoB",
                 6U, 14U,  1U,  9U,
                 2U,  7U,  5U,  0U,
                11U,  3U, 12U,  4U,
                15U, 10U,  8U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::SapporoC() {
    //  A  B  C  D      K  M  N  L
    //  E  F  G  H  ->  I  J  P  O
    //  I  J  K  L      H  B  A  G
    //  M  N  O  P      F  E  C  D
    return Make("SapporoC",
                10U, 12U, 13U, 11U,
                 8U,  9U, 15U, 14U,
                 7U,  1U,  0U,  6U,
                 5U,  4U,  2U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::SapporoD() {
    //  A  B  C  D      M  N  L  K
    //  E  F  G  H  ->  O  I  J  P
    //  I  J  K  L      B  A  G  H
    //  M  N  O  P      D  F  E  C
    return Make("SapporoD",
                12U, 13U, 11U, 10U,
                14U,  8U,  9U, 15U,
                 1U,  0U,  6U,  7U,
                 3U,  5U,  4U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::NagoyaA() {
    //  A  B  C  D      G  C  P  J
    //  E  F  G  H  ->  H  K  O  B
    //  I  J  K  L      F  D  M  I
    //  M  N  O  P      E  L  N  A
    return Make("NagoyaA",
                 6U,  2U, 15U,  9U,
                 7U, 10U, 14U,  1U,
                 5U,  3U, 12U,  8U,
                 4U, 11U, 13U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::NagoyaB() {
    //  A  B  C  D      C  P  J  G
    //  E  F  G  H  ->  B  H  K  O
    //  I  J  K  L      D  M  I  F
    //  M  N  O  P      A  E  L  N
    return Make("NagoyaB",
                 2U, 15U,  9U,  6U,
                 1U,  7U, 10U, 14U,
                 3U, 12U,  8U,  5U,
                 0U,  4U, 11U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::NagoyaC() {
    //  A  B  C  D      M  N  F  E
    //  E  F  G  H  ->  L  J  A  C
    //  I  J  K  L      P  O  G  H
    //  M  N  O  P      K  I  B  D
    return Make("NagoyaC",
                12U, 13U,  5U,  4U,
                11U,  9U,  0U,  2U,
                15U, 14U,  6U,  7U,
                10U,  8U,  1U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::NagoyaD() {
    //  A  B  C  D      L  I  A  D
    //  E  F  G  H  ->  P  N  G  E
    //  I  J  K  L      K  J  B  C
    //  M  N  O  P      M  O  F  H
    return Make("NagoyaD",
                11U,  8U,  0U,  3U,
                15U, 13U,  6U,  4U,
                10U,  9U,  1U,  2U,
                12U, 14U,  5U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::FukuokaA() {
    //  A  B  C  D      G  H  B  A
    //  E  F  G  H  ->  D  F  E  C
    //  I  J  K  L      L  K  M  N
    //  M  N  O  P      O  I  J  P
    return Make("FukuokaA",
                 6U,  7U,  1U,  0U,
                 3U,  5U,  4U,  2U,
                11U, 10U, 12U, 13U,
                14U,  8U,  9U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::FukuokaB() {
    //  A  B  C  D      H  B  A  G
    //  E  F  G  H  ->  C  D  F  E
    //  I  J  K  L      K  M  N  L
    //  M  N  O  P      P  O  I  J
    return Make("FukuokaB",
                 7U,  1U,  0U,  6U,
                 2U,  3U,  5U,  4U,
                10U, 12U, 13U, 11U,
                15U, 14U,  8U,  9U
    );
}

Recipe4x4 RecipeFactory4x4::FukuokaC() {
    //  A  B  C  D      M  J  L  O
    //  E  F  G  H  ->  I  A  P  H
    //  I  J  K  L      B  E  G  D
    //  M  N  O  P      F  N  C  K
    return Make("FukuokaC",
                12U,  9U, 11U, 14U,
                 8U,  0U, 15U,  7U,
                 1U,  4U,  6U,  3U,
                 5U, 13U,  2U, 10U
    );
}

Recipe4x4 RecipeFactory4x4::FukuokaD() {
    //  A  B  C  D      I  N  P  K
    //  E  F  G  H  ->  B  J  G  O
    //  I  J  K  L      F  A  C  H
    //  M  N  O  P      M  E  L  D
    return Make("FukuokaD",
                 8U, 13U, 15U, 10U,
                 1U,  9U,  6U, 14U,
                 5U,  0U,  2U,  7U,
                12U,  4U, 11U,  3U
    );
}


Recipe4x4 RecipeFactory4x4::GlendaleA() {
    //  A  B  C  D      G  D  B  E
    //  E  F  G  H  ->  C  K  F  N
    //  I  J  K  L      L  O  M  J
    //  M  N  O  P      P  H  I  A
    return Make("GlendaleA",
                 6U,  3U,  1U,  4U,
                 2U, 10U,  5U, 13U,
                11U, 14U, 12U,  9U,
                15U,  7U,  8U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::GlendaleB() {
    //  A  B  C  D      C  H  F  A
    //  E  F  G  H  ->  L  D  M  E
    //  I  J  K  L      P  K  I  N
    //  M  N  O  P      G  O  B  J
    return Make("GlendaleB",
                 2U,  7U,  5U,  0U,
                11U,  3U, 12U,  4U,
                15U, 10U,  8U, 13U,
                 6U, 14U,  1U,  9U
    );
}

Recipe4x4 RecipeFactory4x4::GlendaleC() {
    //  A  B  C  D      F  D  C  E
    //  E  F  G  H  ->  H  G  A  B
    //  I  J  K  L      I  O  P  J
    //  M  N  O  P      K  L  N  M
    return Make("GlendaleC",
                 5U,  3U,  2U,  4U,
                 7U,  6U,  0U,  1U,
                 8U, 14U, 15U,  9U,
                10U, 11U, 13U, 12U
    );
}

Recipe4x4 RecipeFactory4x4::GlendaleD() {
    //  A  B  C  D      D  C  E  F
    //  E  F  G  H  ->  B  H  G  A
    //  I  J  K  L      O  P  J  I
    //  M  N  O  P      M  K  L  N
    return Make("GlendaleD",
                 3U,  2U,  4U,  5U,
                 1U,  7U,  6U,  0U,
                14U, 15U,  9U,  8U,
                12U, 10U, 11U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::BurbankA() {
    //  A  B  C  D      E  M  D  L
    //  E  F  G  H  ->  A  F  H  C
    //  I  J  K  L      J  B  O  G
    //  M  N  O  P      N  I  K  P
    return Make("BurbankA",
                 4U, 12U,  3U, 11U,
                 0U,  5U,  7U,  2U,
                 9U,  1U, 14U,  6U,
                13U,  8U, 10U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::BurbankB() {
    //  A  B  C  D      N  F  K  C
    //  E  F  G  H  ->  E  B  D  G
    //  I  J  K  L      A  I  H  P
    //  M  N  O  P      J  M  O  L
    return Make("BurbankB",
                13U,  5U, 10U,  2U,
                 4U,  1U,  3U,  6U,
                 0U,  8U,  7U, 15U,
                 9U, 12U, 14U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::BurbankC() {
    //  A  B  C  D      K  P  H  C
    //  E  F  G  H  ->  L  J  G  E
    //  I  J  K  L      N  I  A  F
    //  M  N  O  P      M  O  B  D
    return Make("BurbankC",
                10U, 15U,  7U,  2U,
                11U,  9U,  6U,  4U,
                13U,  8U,  0U,  5U,
                12U, 14U,  1U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::BurbankD() {
    //  A  B  C  D      L  O  G  D
    //  E  F  G  H  ->  N  P  A  C
    //  I  J  K  L      M  J  B  E
    //  M  N  O  P      K  I  H  F
    return Make("BurbankD",
                11U, 14U,  6U,  3U,
                13U, 15U,  0U,  2U,
                12U,  9U,  1U,  4U,
                10U,  8U,  7U,  5U
    );
}

Recipe4x4 RecipeFactory4x4::InglewoodA() {
    //  A  B  C  D      I  J  M  F
    //  E  F  G  H  ->  E  B  A  N
    //  I  J  K  L      G  P  C  D
    //  M  N  O  P      K  H  O  L
    return Make("InglewoodA",
                 8U,  9U, 12U,  5U,
                 4U,  1U,  0U, 13U,
                 6U, 15U,  2U,  3U,
                10U,  7U, 14U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::InglewoodB() {
    //  A  B  C  D      F  I  J  M
    //  E  F  G  H  ->  B  A  N  E
    //  I  J  K  L      D  G  P  C
    //  M  N  O  P      H  O  L  K
    return Make("InglewoodB",
                 5U,  8U,  9U, 12U,
                 1U,  0U, 13U,  4U,
                 3U,  6U, 15U,  2U,
                 7U, 14U, 11U, 10U
    );
}

Recipe4x4 RecipeFactory4x4::InglewoodC() {
    //  A  B  C  D      P  N  D  B
    //  E  F  G  H  ->  O  C  K  G
    //  I  J  K  L      J  L  F  H
    //  M  N  O  P      A  M  E  I
    return Make("InglewoodC",
                15U, 13U,  3U,  1U,
                14U,  2U, 10U,  6U,
                 9U, 11U,  5U,  7U,
                 0U, 12U,  4U,  8U
    );
}

Recipe4x4 RecipeFactory4x4::InglewoodD() {
    //  A  B  C  D      A  C  E  G
    //  E  F  G  H  ->  P  L  D  H
    //  I  J  K  L      O  M  K  I
    //  M  N  O  P      J  N  F  B
    return Make("InglewoodD",
                 0U,  2U,  4U,  6U,
                15U, 11U,  3U,  7U,
                14U, 12U, 10U,  8U,
                 9U, 13U,  5U,  1U
    );
}

Recipe4x4 RecipeFactory4x4::PasadenaA() {
    //  A  B  C  D      D  F  E  C
    //  E  F  G  H  ->  G  H  B  A
    //  I  J  K  L      O  I  J  P
    //  M  N  O  P      L  K  M  N
    return Make("PasadenaA",
                 3U,  5U,  4U,  2U,
                 6U,  7U,  1U,  0U,
                14U,  8U,  9U, 15U,
                11U, 10U, 12U, 13U
    );
}

Recipe4x4 RecipeFactory4x4::PasadenaB() {
    //  A  B  C  D      C  D  F  E
    //  E  F  G  H  ->  H  B  A  G
    //  I  J  K  L      P  O  I  J
    //  M  N  O  P      K  M  N  L
    return Make("PasadenaB",
                 2U,  3U,  5U,  4U,
                 7U,  1U,  0U,  6U,
                15U, 14U,  8U,  9U,
                10U, 12U, 13U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::PasadenaC() {
    //  A  B  C  D      I  A  P  H
    //  E  F  G  H  ->  M  J  L  O
    //  I  J  K  L      F  N  C  K
    //  M  N  O  P      B  E  G  D
    return Make("PasadenaC",
                 8U,  0U, 15U,  7U,
                12U,  9U, 11U, 14U,
                 5U, 13U,  2U, 10U,
                 1U,  4U,  6U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::PasadenaD() {
    //  A  B  C  D      B  J  G  O
    //  E  F  G  H  ->  I  N  P  K
    //  I  J  K  L      M  E  L  D
    //  M  N  O  P      F  A  C  H
    return Make("PasadenaD",
                 1U,  9U,  6U, 14U,
                 8U, 13U, 15U, 10U,
                12U,  4U, 11U,  3U,
                 5U,  0U,  2U,  7U
    );
}

Recipe4x4 RecipeFactory4x4::TorranceA() {
    //  A  B  C  D      G  O  B  J
    //  E  F  G  H  ->  P  K  I  N
    //  I  J  K  L      L  D  M  E
    //  M  N  O  P      C  H  F  A
    return Make("TorranceA",
                 6U, 14U,  1U,  9U,
                15U, 10U,  8U, 13U,
                11U,  3U, 12U,  4U,
                 2U,  7U,  5U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::TorranceB() {
    //  A  B  C  D      P  H  I  A
    //  E  F  G  H  ->  L  O  M  J
    //  I  J  K  L      C  K  F  N
    //  M  N  O  P      G  D  B  E
    return Make("TorranceB",
                15U,  7U,  8U,  0U,
                11U, 14U, 12U,  9U,
                 2U, 10U,  5U, 13U,
                 6U,  3U,  1U,  4U
    );
}

Recipe4x4 RecipeFactory4x4::TorranceC() {
    //  A  B  C  D      M  O  B  D
    //  E  F  G  H  ->  N  I  A  F
    //  I  J  K  L      L  J  G  E
    //  M  N  O  P      K  P  H  C
    return Make("TorranceC",
                12U, 14U,  1U,  3U,
                13U,  8U,  0U,  5U,
                11U,  9U,  6U,  4U,
                10U, 15U,  7U,  2U
    );
}

Recipe4x4 RecipeFactory4x4::TorranceD() {
    //  A  B  C  D      K  I  H  F
    //  E  F  G  H  ->  M  J  B  E
    //  I  J  K  L      N  P  A  C
    //  M  N  O  P      L  O  G  D
    return Make("TorranceD",
                10U,  8U,  7U,  5U,
                12U,  9U,  1U,  4U,
                13U, 15U,  0U,  2U,
                11U, 14U,  6U,  3U
    );
}

Recipe4x4 RecipeFactory4x4::HawthorneA() {
    //  A  B  C  D      L  O  M  J
    //  E  F  G  H  ->  C  K  F  N
    //  I  J  K  L      G  D  B  E
    //  M  N  O  P      P  H  I  A
    return Make("HawthorneA",
                11U, 14U, 12U,  9U,
                 2U, 10U,  5U, 13U,
                 6U,  3U,  1U,  4U,
                15U,  7U,  8U,  0U
    );
}

Recipe4x4 RecipeFactory4x4::HawthorneB() {
    //  A  B  C  D      P  K  I  N
    //  E  F  G  H  ->  L  D  M  E
    //  I  J  K  L      C  H  F  A
    //  M  N  O  P      G  O  B  J
    return Make("HawthorneB",
                15U, 10U,  8U, 13U,
                11U,  3U, 12U,  4U,
                 2U,  7U,  5U,  0U,
                 6U, 14U,  1U,  9U
    );
}

Recipe4x4 RecipeFactory4x4::HawthorneC() {
    //  A  B  C  D      F  E  C  D
    //  E  F  G  H  ->  H  B  A  G
    //  I  J  K  L      I  J  P  O
    //  M  N  O  P      K  M  N  L
    return Make("HawthorneC",
                 5U,  4U,  2U,  3U,
                 7U,  1U,  0U,  6U,
                 8U,  9U, 15U, 14U,
                10U, 12U, 13U, 11U
    );
}

Recipe4x4 RecipeFactory4x4::HawthorneD() {
    //  A  B  C  D      D  F  E  C
    //  E  F  G  H  ->  B  A  G  H
    //  I  J  K  L      O  I  J  P
    //  M  N  O  P      M  N  L  K
    return Make("HawthorneD",
                 3U,  5U,  4U,  2U,
                 1U,  0U,  6U,  7U,
                14U,  8U,  9U, 15U,
                12U, 13U, 11U, 10U
    );
}


Recipe4x4 RecipeFactory4x4::WizardA() {
    //  A  B  C  D      E  N  C  G
    //  E  F  G  H  ->  B  F  K  D
    //  I  J  K  L      I  M  O  H
    //  M  N  O  P      A  J  L  P
    return Make("WizardA",
                 4U, 13U,  2U,  6U,
                 1U,  5U, 10U,  3U,
                 8U, 12U, 14U,  7U,
                 0U,  9U, 11U, 15U
    );
}

Recipe4x4 RecipeFactory4x4::WizardB() {
    //  A  B  C  D      A  E  L  C
    //  E  F  G  H  ->  F  M  D  H
    //  I  J  K  L      B  I  K  O
    //  M  N  O  P      J  N  P  G
    return Make("WizardB",
                 0U,  4U, 11U,  2U,
                 5U, 12U,  3U,  7U,
                 1U,  8U, 10U, 14U,
                 9U, 13U, 15U,  6U
    );
}

Recipe4x4 RecipeFactory4x4::WizardC() {
    //  A  B  C  D      E  B  H  F
    //  E  F  G  H  ->  C  A  G  D
    //  I  J  K  L      N  P  O  L
    //  M  N  O  P      M  J  I  K
    return Make("WizardC",
                 4U,  1U,  7U,  5U,
                 2U,  0U,  6U,  3U,
                13U, 15U, 14U, 11U,
                12U,  9U,  8U, 10U
    );
}

Recipe4x4 RecipeFactory4x4::WizardD() {
    //  A  B  C  D      F  A  B  D
    //  E  F  G  H  ->  E  G  H  C
    //  I  J  K  L      L  J  P  K
    //  M  N  O  P      N  I  O  M
    return Make("WizardD",
                 5U,  0U,  1U,  3U,
                 4U,  6U,  7U,  2U,
                11U,  9U, 15U, 10U,
                13U,  8U, 14U, 12U
    );
}



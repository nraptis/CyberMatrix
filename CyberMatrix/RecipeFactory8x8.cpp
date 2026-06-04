//
//  RecipeFactory8x8.cpp
//  CyberMatrix
//

#include "RecipeFactory8x8.hpp"

#include <cstddef>

Recipe8x8 RecipeFactory8x8::MakeIdentityNamed(const char *pName) {
    Recipe8x8 aResult = { pName, {} };

    std::uint8_t aValue = 0U;

    for (std::size_t y = 0U; y < 8U; y++) {
        for (std::size_t x = 0U; x < 8U; x++) {
            aResult.mMap[y][x] = aValue;
            aValue++;
        }
    }

    return aResult;
}

Recipe8x8 RecipeFactory8x8::Identity() {
    return MakeIdentityNamed("Identity");
}

Recipe8x8 RecipeFactory8x8::RotA() {
    //  AA AB AC AD AE AF AG AH      HA GA FA EA DA CA BA AA
    //  BA BB BC BD BE BF BG BH  ->  HB GB FB EB DB CB BB AB
    //  CA CB CC CD CE CF CG CH      HC GC FC EC DC CC BC AC
    //  DA DB DC DD DE DF DG DH      HD GD FD ED DD CD BD AD
    //  EA EB EC ED EE EF EG EH      HE GE FE EE DE CE BE AE
    //  FA FB FC FD FE FF FG FH      HF GF FF EF DF CF BF AF
    //  GA GB GC GD GE GF GG GH      HG GG FG EG DG CG BG AG
    //  HA HB HC HD HE HF HG HH      HH GH FH EH DH CH BH AH
    return Make("RotA",
                56U, 48U, 40U, 32U, 24U, 16U,  8U,  0U,
                57U, 49U, 41U, 33U, 25U, 17U,  9U,  1U,
                58U, 50U, 42U, 34U, 26U, 18U, 10U,  2U,
                59U, 51U, 43U, 35U, 27U, 19U, 11U,  3U,
                60U, 52U, 44U, 36U, 28U, 20U, 12U,  4U,
                61U, 53U, 45U, 37U, 29U, 21U, 13U,  5U,
                62U, 54U, 46U, 38U, 30U, 22U, 14U,  6U,
                63U, 55U, 47U, 39U, 31U, 23U, 15U,  7U
                );
}

Recipe8x8 RecipeFactory8x8::RotB() {
    //  AA AB AC AD AE AF AG AH      AH BH CH DH EH FH GH HH
    //  BA BB BC BD BE BF BG BH  ->  AG BG CG DG EG FG GG HG
    //  CA CB CC CD CE CF CG CH      AF BF CF DF EF FF GF HF
    //  DA DB DC DD DE DF DG DH      AE BE CE DE EE FE GE HE
    //  EA EB EC ED EE EF EG EH      AD BD CD DD ED FD GD HD
    //  FA FB FC FD FE FF FG FH      AC BC CC DC EC FC GC HC
    //  GA GB GC GD GE GF GG GH      AB BB CB DB EB FB GB HB
    //  HA HB HC HD HE HF HG HH      AA BA CA DA EA FA GA HA
    return Make("RotB",
                7U, 15U, 23U, 31U, 39U, 47U, 55U, 63U,
                6U, 14U, 22U, 30U, 38U, 46U, 54U, 62U,
                5U, 13U, 21U, 29U, 37U, 45U, 53U, 61U,
                4U, 12U, 20U, 28U, 36U, 44U, 52U, 60U,
                3U, 11U, 19U, 27U, 35U, 43U, 51U, 59U,
                2U, 10U, 18U, 26U, 34U, 42U, 50U, 58U,
                1U,  9U, 17U, 25U, 33U, 41U, 49U, 57U,
                0U,  8U, 16U, 24U, 32U, 40U, 48U, 56U
                );
}

Recipe8x8 RecipeFactory8x8::RotC() {
    //  AA AB AC AD AE AF AG AH      HH HG HF HE HD HC HB HA
    //  BA BB BC BD BE BF BG BH  ->  GH GG GF GE GD GC GB GA
    //  CA CB CC CD CE CF CG CH      FH FG FF FE FD FC FB FA
    //  DA DB DC DD DE DF DG DH      EH EG EF EE ED EC EB EA
    //  EA EB EC ED EE EF EG EH      DH DG DF DE DD DC DB DA
    //  FA FB FC FD FE FF FG FH      CH CG CF CE CD CC CB CA
    //  GA GB GC GD GE GF GG GH      BH BG BF BE BD BC BB BA
    //  HA HB HC HD HE HF HG HH      AH AG AF AE AD AC AB AA
    return Make("RotC",
                63U, 62U, 61U, 60U, 59U, 58U, 57U, 56U,
                55U, 54U, 53U, 52U, 51U, 50U, 49U, 48U,
                47U, 46U, 45U, 44U, 43U, 42U, 41U, 40U,
                39U, 38U, 37U, 36U, 35U, 34U, 33U, 32U,
                31U, 30U, 29U, 28U, 27U, 26U, 25U, 24U,
                23U, 22U, 21U, 20U, 19U, 18U, 17U, 16U,
                15U, 14U, 13U, 12U, 11U, 10U,  9U,  8U,
                7U,  6U,  5U,  4U,  3U,  2U,  1U,  0U
                );
}

Recipe8x8 RecipeFactory8x8::FlipA() {
    //  AA AB AC AD AE AF AG AH      AH AG AF AE AD AC AB AA
    //  BA BB BC BD BE BF BG BH  ->  BH BG BF BE BD BC BB BA
    //  CA CB CC CD CE CF CG CH      CH CG CF CE CD CC CB CA
    //  DA DB DC DD DE DF DG DH      DH DG DF DE DD DC DB DA
    //  EA EB EC ED EE EF EG EH      EH EG EF EE ED EC EB EA
    //  FA FB FC FD FE FF FG FH      FH FG FF FE FD FC FB FA
    //  GA GB GC GD GE GF GG GH      GH GG GF GE GD GC GB GA
    //  HA HB HC HD HE HF HG HH      HH HG HF HE HD HC HB HA
    return Make("FlipA",
                7U,  6U,  5U,  4U,  3U,  2U,  1U,  0U,
                15U, 14U, 13U, 12U, 11U, 10U,  9U,  8U,
                23U, 22U, 21U, 20U, 19U, 18U, 17U, 16U,
                31U, 30U, 29U, 28U, 27U, 26U, 25U, 24U,
                39U, 38U, 37U, 36U, 35U, 34U, 33U, 32U,
                47U, 46U, 45U, 44U, 43U, 42U, 41U, 40U,
                55U, 54U, 53U, 52U, 51U, 50U, 49U, 48U,
                63U, 62U, 61U, 60U, 59U, 58U, 57U, 56U
                );
}

Recipe8x8 RecipeFactory8x8::FlipB() {
    //  AA AB AC AD AE AF AG AH      HA HB HC HD HE HF HG HH
    //  BA BB BC BD BE BF BG BH  ->  GA GB GC GD GE GF GG GH
    //  CA CB CC CD CE CF CG CH      FA FB FC FD FE FF FG FH
    //  DA DB DC DD DE DF DG DH      EA EB EC ED EE EF EG EH
    //  EA EB EC ED EE EF EG EH      DA DB DC DD DE DF DG DH
    //  FA FB FC FD FE FF FG FH      CA CB CC CD CE CF CG CH
    //  GA GB GC GD GE GF GG GH      BA BB BC BD BE BF BG BH
    //  HA HB HC HD HE HF HG HH      AA AB AC AD AE AF AG AH
    return Make("FlipB",
                56U, 57U, 58U, 59U, 60U, 61U, 62U, 63U,
                48U, 49U, 50U, 51U, 52U, 53U, 54U, 55U,
                40U, 41U, 42U, 43U, 44U, 45U, 46U, 47U,
                32U, 33U, 34U, 35U, 36U, 37U, 38U, 39U,
                24U, 25U, 26U, 27U, 28U, 29U, 30U, 31U,
                16U, 17U, 18U, 19U, 20U, 21U, 22U, 23U,
                8U,  9U, 10U, 11U, 12U, 13U, 14U, 15U,
                0U,  1U,  2U,  3U,  4U,  5U,  6U,  7U
                );
}

Recipe8x8 RecipeFactory8x8::FlipC() {
    //  AA AB AC AD AE AF AG AH      AA BA CA DA EA FA GA HA
    //  BA BB BC BD BE BF BG BH  ->  AB BB CB DB EB FB GB HB
    //  CA CB CC CD CE CF CG CH      AC BC CC DC EC FC GC HC
    //  DA DB DC DD DE DF DG DH      AD BD CD DD ED FD GD HD
    //  EA EB EC ED EE EF EG EH      AE BE CE DE EE FE GE HE
    //  FA FB FC FD FE FF FG FH      AF BF CF DF EF FF GF HF
    //  GA GB GC GD GE GF GG GH      AG BG CG DG EG FG GG HG
    //  HA HB HC HD HE HF HG HH      AH BH CH DH EH FH GH HH
    return Make("FlipC",
                0U,  8U, 16U, 24U, 32U, 40U, 48U, 56U,
                1U,  9U, 17U, 25U, 33U, 41U, 49U, 57U,
                2U, 10U, 18U, 26U, 34U, 42U, 50U, 58U,
                3U, 11U, 19U, 27U, 35U, 43U, 51U, 59U,
                4U, 12U, 20U, 28U, 36U, 44U, 52U, 60U,
                5U, 13U, 21U, 29U, 37U, 45U, 53U, 61U,
                6U, 14U, 22U, 30U, 38U, 46U, 54U, 62U,
                7U, 15U, 23U, 31U, 39U, 47U, 55U, 63U
                );
}

Recipe8x8 RecipeFactory8x8::FlipD() {
    //  AA AB AC AD AE AF AG AH      HH GH FH EH DH CH BH AH
    //  BA BB BC BD BE BF BG BH  ->  HG GG FG EG DG CG BG AG
    //  CA CB CC CD CE CF CG CH      HF GF FF EF DF CF BF AF
    //  DA DB DC DD DE DF DG DH      HE GE FE EE DE CE BE AE
    //  EA EB EC ED EE EF EG EH      HD GD FD ED DD CD BD AD
    //  FA FB FC FD FE FF FG FH      HC GC FC EC DC CC BC AC
    //  GA GB GC GD GE GF GG GH      HB GB FB EB DB CB BB AB
    //  HA HB HC HD HE HF HG HH      HA GA FA EA DA CA BA AA
    return Make("FlipD",
                63U, 55U, 47U, 39U, 31U, 23U, 15U,  7U,
                62U, 54U, 46U, 38U, 30U, 22U, 14U,  6U,
                61U, 53U, 45U, 37U, 29U, 21U, 13U,  5U,
                60U, 52U, 44U, 36U, 28U, 20U, 12U,  4U,
                59U, 51U, 43U, 35U, 27U, 19U, 11U,  3U,
                58U, 50U, 42U, 34U, 26U, 18U, 10U,  2U,
                57U, 49U, 41U, 33U, 25U, 17U,  9U,  1U,
                56U, 48U, 40U, 32U, 24U, 16U,  8U,  0U
                );
}

Recipe8x8 RecipeFactory8x8::PinA() {
    //  AA AB AC AD AE AF AG AH      HA GA FA EA DA CA BA AA
    //  BA BB BC BD BE BF BG BH  ->  HB BG CG DG EG FG GG AB
    //  CA CB CC CD CE CF CG CH      HC BF FC EC DC CC GF AC
    //  DA DB DC DD DE DF DG DH      HD BE FD DE EE CD GE AD
    //  EA EB EC ED EE EF EG EH      HE BD FE DD ED CE GD AE
    //  FA FB FC FD FE FF FG FH      HF BC FF EF DF CF GC AF
    //  GA GB GC GD GE GF GG GH      HG BB CB DB EB FB GB AG
    //  HA HB HC HD HE HF HG HH      HH GH FH EH DH CH BH AH
    return Make("PinA",
                56U, 48U, 40U, 32U, 24U, 16U,  8U,  0U,
                57U, 14U, 22U, 30U, 38U, 46U, 54U,  1U,
                58U, 13U, 42U, 34U, 26U, 18U, 53U,  2U,
                59U, 12U, 43U, 28U, 36U, 19U, 52U,  3U,
                60U, 11U, 44U, 27U, 35U, 20U, 51U,  4U,
                61U, 10U, 45U, 37U, 29U, 21U, 50U,  5U,
                62U,  9U, 17U, 25U, 33U, 41U, 49U,  6U,
                63U, 55U, 47U, 39U, 31U, 23U, 15U,  7U
    );
}

Recipe8x8 RecipeFactory8x8::ShearA() {
//  AA AB AC AD AE AF AG AH      AE AF AG AH AA AB AC AD
//  BA BB BC BD BE BF BG BH  ->  BG BH BA BB BC BD BE BF
//  CA CB CC CD CE CF CG CH      CE CF CG CH CA CB CC CD
//  DA DB DC DD DE DF DG DH      DG DH DA DB DC DD DE DF
//  EA EB EC ED EE EF EG EH      EE EF EG EH EA EB EC ED
//  FA FB FC FD FE FF FG FH      FG FH FA FB FC FD FE FF
//  GA GB GC GD GE GF GG GH      GE GF GG GH GA GB GC GD
//  HA HB HC HD HE HF HG HH      HG HH HA HB HC HD HE HF
return Make("ShearA",
             4U,  5U,  6U,  7U,  0U,  1U,  2U,  3U,
            14U, 15U,  8U,  9U, 10U, 11U, 12U, 13U,
            20U, 21U, 22U, 23U, 16U, 17U, 18U, 19U,
            30U, 31U, 24U, 25U, 26U, 27U, 28U, 29U,
            36U, 37U, 38U, 39U, 32U, 33U, 34U, 35U,
            46U, 47U, 40U, 41U, 42U, 43U, 44U, 45U,
            52U, 53U, 54U, 55U, 48U, 49U, 50U, 51U,
            62U, 63U, 56U, 57U, 58U, 59U, 60U, 61U
);
}

Recipe8x8 RecipeFactory8x8::ShearB() {
//  AA AB AC AD AE AF AG AH      AG AH AA AB AC AD AE AF
//  BA BB BC BD BE BF BG BH  ->  BE BF BG BH BA BB BC BD
//  CA CB CC CD CE CF CG CH      CG CH CA CB CC CD CE CF
//  DA DB DC DD DE DF DG DH      DE DF DG DH DA DB DC DD
//  EA EB EC ED EE EF EG EH      EG EH EA EB EC ED EE EF
//  FA FB FC FD FE FF FG FH      FE FF FG FH FA FB FC FD
//  GA GB GC GD GE GF GG GH      GG GH GA GB GC GD GE GF
//  HA HB HC HD HE HF HG HH      HE HF HG HH HA HB HC HD
return Make("ShearB",
             6U,  7U,  0U,  1U,  2U,  3U,  4U,  5U,
            12U, 13U, 14U, 15U,  8U,  9U, 10U, 11U,
            22U, 23U, 16U, 17U, 18U, 19U, 20U, 21U,
            28U, 29U, 30U, 31U, 24U, 25U, 26U, 27U,
            38U, 39U, 32U, 33U, 34U, 35U, 36U, 37U,
            44U, 45U, 46U, 47U, 40U, 41U, 42U, 43U,
            54U, 55U, 48U, 49U, 50U, 51U, 52U, 53U,
            60U, 61U, 62U, 63U, 56U, 57U, 58U, 59U
);
}





Recipe8x8 RecipeFactory8x8::ShearC() {
//  AA AB AC AD AE AF AG AH      EA GB EC GD EE GF EG GH
//  BA BB BC BD BE BF BG BH  ->  FA HB FC HD FE HF FG HH
//  CA CB CC CD CE CF CG CH      GA AB GC AD GE AF GG AH
//  DA DB DC DD DE DF DG DH      HA BB HC BD HE BF HG BH
//  EA EB EC ED EE EF EG EH      AA CB AC CD AE CF AG CH
//  FA FB FC FD FE FF FG FH      BA DB BC DD BE DF BG DH
//  GA GB GC GD GE GF GG GH      CA EB CC ED CE EF CG EH
//  HA HB HC HD HE HF HG HH      DA FB DC FD DE FF DG FH
return Make("ShearC",
            32U, 49U, 34U, 51U, 36U, 53U, 38U, 55U,
            40U, 57U, 42U, 59U, 44U, 61U, 46U, 63U,
            48U,  1U, 50U,  3U, 52U,  5U, 54U,  7U,
            56U,  9U, 58U, 11U, 60U, 13U, 62U, 15U,
             0U, 17U,  2U, 19U,  4U, 21U,  6U, 23U,
             8U, 25U, 10U, 27U, 12U, 29U, 14U, 31U,
            16U, 33U, 18U, 35U, 20U, 37U, 22U, 39U,
            24U, 41U, 26U, 43U, 28U, 45U, 30U, 47U
);
}

Recipe8x8 RecipeFactory8x8::ShearD() {
//  AA AB AC AD AE AF AG AH      GA EB GC ED GE EF GG EH
//  BA BB BC BD BE BF BG BH  ->  HA FB HC FD HE FF HG FH
//  CA CB CC CD CE CF CG CH      AA GB AC GD AE GF AG GH
//  DA DB DC DD DE DF DG DH      BA HB BC HD BE HF BG HH
//  EA EB EC ED EE EF EG EH      CA AB CC AD CE AF CG AH
//  FA FB FC FD FE FF FG FH      DA BB DC BD DE BF DG BH
//  GA GB GC GD GE GF GG GH      EA CB EC CD EE CF EG CH
//  HA HB HC HD HE HF HG HH      FA DB FC DD FE DF FG DH
return Make("ShearD",
            48U, 33U, 50U, 35U, 52U, 37U, 54U, 39U,
            56U, 41U, 58U, 43U, 60U, 45U, 62U, 47U,
             0U, 49U,  2U, 51U,  4U, 53U,  6U, 55U,
             8U, 57U, 10U, 59U, 12U, 61U, 14U, 63U,
            16U,  1U, 18U,  3U, 20U,  5U, 22U,  7U,
            24U,  9U, 26U, 11U, 28U, 13U, 30U, 15U,
            32U, 17U, 34U, 19U, 36U, 21U, 38U, 23U,
            40U, 25U, 42U, 27U, 44U, 29U, 46U, 31U
);
}


Recipe8x8 RecipeFactory8x8::PinB() {
    //  AA AB AC AD AE AF AG AH      AH BH CH DH EH FH GH HH
    //  BA BB BC BD BE BF BG BH  ->  AG GB FB EB DB CB BB HG
    //  CA CB CC CD CE CF CG CH      AF GC CF DF EF FF BC HF
    //  DA DB DC DD DE DF DG DH      AE GD CE ED DD FE BD HE
    //  EA EB EC ED EE EF EG EH      AD GE CD EE DE FD BE HD
    //  FA FB FC FD FE FF FG FH      AC GF CC DC EC FC BF HC
    //  GA GB GC GD GE GF GG GH      AB GG FG EG DG CG BG HB
    //  HA HB HC HD HE HF HG HH      AA BA CA DA EA FA GA HA
    return Make("PinB",
                 7U, 15U, 23U, 31U, 39U, 47U, 55U, 63U,
                 6U, 49U, 41U, 33U, 25U, 17U,  9U, 62U,
                 5U, 50U, 21U, 29U, 37U, 45U, 10U, 61U,
                 4U, 51U, 20U, 35U, 27U, 44U, 11U, 60U,
                 3U, 52U, 19U, 36U, 28U, 43U, 12U, 59U,
                 2U, 53U, 18U, 26U, 34U, 42U, 13U, 58U,
                 1U, 54U, 46U, 38U, 30U, 22U, 14U, 57U,
                 0U,  8U, 16U, 24U, 32U, 40U, 48U, 56U
    );
}





Recipe8x8 RecipeFactory8x8::JewelA() {
//  AA AB AC AD AE AF AG AH      BD BC BB BA AA AB AC AD
//  BA BB BC BD BE BF BG BH  ->  BE BF BG BH AH AG AF AE
//  CA CB CC CD CE CF CG CH      CE CF CG CH DH DG DF DE
//  DA DB DC DD DE DF DG DH      CD CC CB CA DA DB DC DD
//  EA EB EC ED EE EF EG EH      FD FC FB FA EA EB EC ED
//  FA FB FC FD FE FF FG FH      FE FF FG FH EH EG EF EE
//  GA GB GC GD GE GF GG GH      GE GF GG GH HH HG HF HE
//  HA HB HC HD HE HF HG HH      GD GC GB GA HA HB HC HD
return Make("JewelA",
            11U, 10U,  9U,  8U,  0U,  1U,  2U,  3U,
            12U, 13U, 14U, 15U,  7U,  6U,  5U,  4U,
            20U, 21U, 22U, 23U, 31U, 30U, 29U, 28U,
            19U, 18U, 17U, 16U, 24U, 25U, 26U, 27U,
            43U, 42U, 41U, 40U, 32U, 33U, 34U, 35U,
            44U, 45U, 46U, 47U, 39U, 38U, 37U, 36U,
            52U, 53U, 54U, 55U, 63U, 62U, 61U, 60U,
            51U, 50U, 49U, 48U, 56U, 57U, 58U, 59U
);
}



Recipe8x8 RecipeFactory8x8::JewelB() {
//  AA AB AC AD AE AF AG AH      AE AF AG AH BH BG BF BE
//  BA BB BC BD BE BF BG BH  ->  AD AC AB AA BA BB BC BD
//  CA CB CC CD CE CF CG CH      DD DC DB DA CA CB CC CD
//  DA DB DC DD DE DF DG DH      DE DF DG DH CH CG CF CE
//  EA EB EC ED EE EF EG EH      EE EF EG EH FH FG FF FE
//  FA FB FC FD FE FF FG FH      ED EC EB EA FA FB FC FD
//  GA GB GC GD GE GF GG GH      HD HC HB HA GA GB GC GD
//  HA HB HC HD HE HF HG HH      HE HF HG HH GH GG GF GE
return Make("JewelB",
             4U,  5U,  6U,  7U, 15U, 14U, 13U, 12U,
             3U,  2U,  1U,  0U,  8U,  9U, 10U, 11U,
            27U, 26U, 25U, 24U, 16U, 17U, 18U, 19U,
            28U, 29U, 30U, 31U, 23U, 22U, 21U, 20U,
            36U, 37U, 38U, 39U, 47U, 46U, 45U, 44U,
            35U, 34U, 33U, 32U, 40U, 41U, 42U, 43U,
            59U, 58U, 57U, 56U, 48U, 49U, 50U, 51U,
            60U, 61U, 62U, 63U, 55U, 54U, 53U, 52U
);
}





Recipe8x8 RecipeFactory8x8::JewelC() {
//  AA AB AC AD AE AF AG AH      EA DA DD ED EE DE DH EH
//  BA BB BC BD BE BF BG BH  ->  FA CA CD FD FE CE CH FH
//  CA CB CC CD CE CF CG CH      GA BA BD GD GE BE BH GH
//  DA DB DC DD DE DF DG DH      HA AA AD HD HE AE AH HH
//  EA EB EC ED EE EF EG EH      HB AB AC HC HF AF AG HG
//  FA FB FC FD FE FF FG FH      GB BB BC GC GF BF BG GG
//  GA GB GC GD GE GF GG GH      FB CB CC FC FF CF CG FG
//  HA HB HC HD HE HF HG HH      EB DB DC EC EF DF DG EG
return Make("JewelC",
            32U, 24U, 27U, 35U, 36U, 28U, 31U, 39U,
            40U, 16U, 19U, 43U, 44U, 20U, 23U, 47U,
            48U,  8U, 11U, 51U, 52U, 12U, 15U, 55U,
            56U,  0U,  3U, 59U, 60U,  4U,  7U, 63U,
            57U,  1U,  2U, 58U, 61U,  5U,  6U, 62U,
            49U,  9U, 10U, 50U, 53U, 13U, 14U, 54U,
            41U, 17U, 18U, 42U, 45U, 21U, 22U, 46U,
            33U, 25U, 26U, 34U, 37U, 29U, 30U, 38U
);
}

Recipe8x8 RecipeFactory8x8::Make(const char *pName,
                                  std::uint8_t p00, std::uint8_t p01, std::uint8_t p02, std::uint8_t p03,
                                  std::uint8_t p04, std::uint8_t p05, std::uint8_t p06, std::uint8_t p07,
                                  std::uint8_t p10, std::uint8_t p11, std::uint8_t p12, std::uint8_t p13,
                                  std::uint8_t p14, std::uint8_t p15, std::uint8_t p16, std::uint8_t p17,
                                  std::uint8_t p20, std::uint8_t p21, std::uint8_t p22, std::uint8_t p23,
                                  std::uint8_t p24, std::uint8_t p25, std::uint8_t p26, std::uint8_t p27,
                                  std::uint8_t p30, std::uint8_t p31, std::uint8_t p32, std::uint8_t p33,
                                  std::uint8_t p34, std::uint8_t p35, std::uint8_t p36, std::uint8_t p37,
                                  std::uint8_t p40, std::uint8_t p41, std::uint8_t p42, std::uint8_t p43,
                                  std::uint8_t p44, std::uint8_t p45, std::uint8_t p46, std::uint8_t p47,
                                  std::uint8_t p50, std::uint8_t p51, std::uint8_t p52, std::uint8_t p53,
                                  std::uint8_t p54, std::uint8_t p55, std::uint8_t p56, std::uint8_t p57,
                                  std::uint8_t p60, std::uint8_t p61, std::uint8_t p62, std::uint8_t p63,
                                  std::uint8_t p64, std::uint8_t p65, std::uint8_t p66, std::uint8_t p67,
                                  std::uint8_t p70, std::uint8_t p71, std::uint8_t p72, std::uint8_t p73,
                                  std::uint8_t p74, std::uint8_t p75, std::uint8_t p76, std::uint8_t p77) {
    Recipe8x8 aResult = {
        pName,
        {
            { p00, p01, p02, p03, p04, p05, p06, p07 },
            { p10, p11, p12, p13, p14, p15, p16, p17 },
            { p20, p21, p22, p23, p24, p25, p26, p27 },
            { p30, p31, p32, p33, p34, p35, p36, p37 },
            { p40, p41, p42, p43, p44, p45, p46, p47 },
            { p50, p51, p52, p53, p54, p55, p56, p57 },
            { p60, p61, p62, p63, p64, p65, p66, p67 },
            { p70, p71, p72, p73, p74, p75, p76, p77 }
        }
    };

    return aResult;
}

Recipe8x8 RecipeFactory8x8::JewelD() {
//  AA AB AC AD AE AF AG AH      DB EB EC DC DF EF EG DG
//  BA BB BC BD BE BF BG BH  ->  CB FB FC CC CF FF FG CG
//  CA CB CC CD CE CF CG CH      BB GB GC BC BF GF GG BG
//  DA DB DC DD DE DF DG DH      AB HB HC AC AF HF HG AG
//  EA EB EC ED EE EF EG EH      AA HA HD AD AE HE HH AH
//  FA FB FC FD FE FF FG FH      BA GA GD BD BE GE GH BH
//  GA GB GC GD GE GF GG GH      CA FA FD CD CE FE FH CH
//  HA HB HC HD HE HF HG HH      DA EA ED DD DE EE EH DH
return Make("JewelD",
            25U, 33U, 34U, 26U, 29U, 37U, 38U, 30U,
            17U, 41U, 42U, 18U, 21U, 45U, 46U, 22U,
             9U, 49U, 50U, 10U, 13U, 53U, 54U, 14U,
             1U, 57U, 58U,  2U,  5U, 61U, 62U,  6U,
             0U, 56U, 59U,  3U,  4U, 60U, 63U,  7U,
             8U, 48U, 51U, 11U, 12U, 52U, 55U, 15U,
            16U, 40U, 43U, 19U, 20U, 44U, 47U, 23U,
            24U, 32U, 35U, 27U, 28U, 36U, 39U, 31U
);
}



Recipe8x8 RecipeFactory8x8::CrystalA() {
//  AA AB AC AD AE AF AG AH      GD GE FE FD CD CE BE BD
//  BA BB BC BD BE BF BG BH  ->  GC GF FF FC CC CF BF BC
//  CA CB CC CD CE CF CG CH      GB GG FG FB CB CG BG BB
//  DA DB DC DD DE DF DG DH      GA GH FH FA CA CH BH BA
//  EA EB EC ED EE EF EG EH      HA HH EH EA DA DH AH AA
//  FA FB FC FD FE FF FG FH      HB HG EG EB DB DG AG AB
//  GA GB GC GD GE GF GG GH      HC HF EF EC DC DF AF AC
//  HA HB HC HD HE HF HG HH      HD HE EE ED DD DE AE AD
return Make("CrystalA",
            51U, 52U, 44U, 43U, 19U, 20U, 12U, 11U,
            50U, 53U, 45U, 42U, 18U, 21U, 13U, 10U,
            49U, 54U, 46U, 41U, 17U, 22U, 14U,  9U,
            48U, 55U, 47U, 40U, 16U, 23U, 15U,  8U,
            56U, 63U, 39U, 32U, 24U, 31U,  7U,  0U,
            57U, 62U, 38U, 33U, 25U, 30U,  6U,  1U,
            58U, 61U, 37U, 34U, 26U, 29U,  5U,  2U,
            59U, 60U, 36U, 35U, 27U, 28U,  4U,  3U
);
}


Recipe8x8 RecipeFactory8x8::CrystalC() {
//  AA AB AC AD AE AF AG AH      HE HD ED EE DE DD AD AE
//  BA BB BC BD BE BF BG BH  ->  HF HC EC EF DF DC AC AF
//  CA CB CC CD CE CF CG CH      HG HB EB EG DG DB AB AG
//  DA DB DC DD DE DF DG DH      HH HA EA EH DH DA AA AH
//  EA EB EC ED EE EF EG EH      GH GA FA FH CH CA BA BH
//  FA FB FC FD FE FF FG FH      GG GB FB FG CG CB BB BG
//  GA GB GC GD GE GF GG GH      GF GC FC FF CF CC BC BF
//  HA HB HC HD HE HF HG HH      GE GD FD FE CE CD BD BE
return Make("CrystalC",
            60U, 59U, 35U, 36U, 28U, 27U,  3U,  4U,
            61U, 58U, 34U, 37U, 29U, 26U,  2U,  5U,
            62U, 57U, 33U, 38U, 30U, 25U,  1U,  6U,
            63U, 56U, 32U, 39U, 31U, 24U,  0U,  7U,
            55U, 48U, 40U, 47U, 23U, 16U,  8U, 15U,
            54U, 49U, 41U, 46U, 22U, 17U,  9U, 14U,
            53U, 50U, 42U, 45U, 21U, 18U, 10U, 13U,
            52U, 51U, 43U, 44U, 20U, 19U, 11U, 12U
);
}






Recipe8x8 RecipeFactory8x8::CrystalB() {
//  AA AB AC AD AE AF AG AH      EB FB GB HB HA GA FA EA
//  BA BB BC BD BE BF BG BH  ->  DB CB BB AB AA BA CA DA
//  CA CB CC CD CE CF CG CH      DC CC BC AC AD BD CD DD
//  DA DB DC DD DE DF DG DH      EC FC GC HC HD GD FD ED
//  EA EB EC ED EE EF EG EH      EF FF GF HF HE GE FE EE
//  FA FB FC FD FE FF FG FH      DF CF BF AF AE BE CE DE
//  GA GB GC GD GE GF GG GH      DG CG BG AG AH BH CH DH
//  HA HB HC HD HE HF HG HH      EG FG GG HG HH GH FH EH
return Make("CrystalB",
            33U, 41U, 49U, 57U, 56U, 48U, 40U, 32U,
            25U, 17U,  9U,  1U,  0U,  8U, 16U, 24U,
            26U, 18U, 10U,  2U,  3U, 11U, 19U, 27U,
            34U, 42U, 50U, 58U, 59U, 51U, 43U, 35U,
            37U, 45U, 53U, 61U, 60U, 52U, 44U, 36U,
            29U, 21U, 13U,  5U,  4U, 12U, 20U, 28U,
            30U, 22U, 14U,  6U,  7U, 15U, 23U, 31U,
            38U, 46U, 54U, 62U, 63U, 55U, 47U, 39U
);
}






Recipe8x8 RecipeFactory8x8::CrystalD() {
//  AA AB AC AD AE AF AG AH      DA CA BA AA AB BB CB DB
//  BA BB BC BD BE BF BG BH  ->  EA FA GA HA HB GB FB EB
//  CA CB CC CD CE CF CG CH      ED FD GD HD HC GC FC EC
//  DA DB DC DD DE DF DG DH      DD CD BD AD AC BC CC DC
//  EA EB EC ED EE EF EG EH      DE CE BE AE AF BF CF DF
//  FA FB FC FD FE FF FG FH      EE FE GE HE HF GF FF EF
//  GA GB GC GD GE GF GG GH      EH FH GH HH HG GG FG EG
//  HA HB HC HD HE HF HG HH      DH CH BH AH AG BG CG DG
return Make("CrystalD",
            24U, 16U,  8U,  0U,  1U,  9U, 17U, 25U,
            32U, 40U, 48U, 56U, 57U, 49U, 41U, 33U,
            35U, 43U, 51U, 59U, 58U, 50U, 42U, 34U,
            27U, 19U, 11U,  3U,  2U, 10U, 18U, 26U,
            28U, 20U, 12U,  4U,  5U, 13U, 21U, 29U,
            36U, 44U, 52U, 60U, 61U, 53U, 45U, 37U,
            39U, 47U, 55U, 63U, 62U, 54U, 46U, 38U,
            31U, 23U, 15U,  7U,  6U, 14U, 22U, 30U
);
}






Recipe8x8 RecipeFactory8x8::OpalA() {
    //  AA AB AC AD AE AF AG AH      AD AE DE DD ED EE HE HD
    //  BA BB BC BD BE BF BG BH  ->  AC AF DF DC EC EF HF HC
    //  CA CB CC CD CE CF CG CH      AB AG DG DB EB EG HG HB
    //  DA DB DC DD DE DF DG DH      AA AH DH DA EA EH HH HA
    //  EA EB EC ED EE EF EG EH      BA BH CH CA FA FH GH GA
    //  FA FB FC FD FE FF FG FH      BB BG CG CB FB FG GG GB
    //  GA GB GC GD GE GF GG GH      BC BF CF CC FC FF GF GC
    //  HA HB HC HD HE HF HG HH      BD BE CE CD FD FE GE GD
    return Make("OpalA",
                 3U,  4U, 28U, 27U, 35U, 36U, 60U, 59U,
                 2U,  5U, 29U, 26U, 34U, 37U, 61U, 58U,
                 1U,  6U, 30U, 25U, 33U, 38U, 62U, 57U,
                 0U,  7U, 31U, 24U, 32U, 39U, 63U, 56U,
                 8U, 15U, 23U, 16U, 40U, 47U, 55U, 48U,
                 9U, 14U, 22U, 17U, 41U, 46U, 54U, 49U,
                10U, 13U, 21U, 18U, 42U, 45U, 53U, 50U,
                11U, 12U, 20U, 19U, 43U, 44U, 52U, 51U
    );
}





Recipe8x8 RecipeFactory8x8::OpalC() {
//  AA AB AC AD AE AF AG AH      BE BD CD CE FE FD GD GE
//  BA BB BC BD BE BF BG BH  ->  BF BC CC CF FF FC GC GF
//  CA CB CC CD CE CF CG CH      BG BB CB CG FG FB GB GG
//  DA DB DC DD DE DF DG DH      BH BA CA CH FH FA GA GH
//  EA EB EC ED EE EF EG EH      AH AA DA DH EH EA HA HH
//  FA FB FC FD FE FF FG FH      AG AB DB DG EG EB HB HG
//  GA GB GC GD GE GF GG GH      AF AC DC DF EF EC HC HF
//  HA HB HC HD HE HF HG HH      AE AD DD DE EE ED HD HE
return Make("OpalC",
            12U, 11U, 19U, 20U, 44U, 43U, 51U, 52U,
            13U, 10U, 18U, 21U, 45U, 42U, 50U, 53U,
            14U,  9U, 17U, 22U, 46U, 41U, 49U, 54U,
            15U,  8U, 16U, 23U, 47U, 40U, 48U, 55U,
             7U,  0U, 24U, 31U, 39U, 32U, 56U, 63U,
             6U,  1U, 25U, 30U, 38U, 33U, 57U, 62U,
             5U,  2U, 26U, 29U, 37U, 34U, 58U, 61U,
             4U,  3U, 27U, 28U, 36U, 35U, 59U, 60U
);
}





Recipe8x8 RecipeFactory8x8::OpalB() {
//  AA AB AC AD AE AF AG AH      EH FH GH HH HG GG FG EG
//  BA BB BC BD BE BF BG BH  ->  DH CH BH AH AG BG CG DG
//  CA CB CC CD CE CF CG CH      DE CE BE AE AF BF CF DF
//  DA DB DC DD DE DF DG DH      EE FE GE HE HF GF FF EF
//  EA EB EC ED EE EF EG EH      ED FD GD HD HC GC FC EC
//  FA FB FC FD FE FF FG FH      DD CD BD AD AC BC CC DC
//  GA GB GC GD GE GF GG GH      DA CA BA AA AB BB CB DB
//  HA HB HC HD HE HF HG HH      EA FA GA HA HB GB FB EB
return Make("OpalB",
            39U, 47U, 55U, 63U, 62U, 54U, 46U, 38U,
            31U, 23U, 15U,  7U,  6U, 14U, 22U, 30U,
            28U, 20U, 12U,  4U,  5U, 13U, 21U, 29U,
            36U, 44U, 52U, 60U, 61U, 53U, 45U, 37U,
            35U, 43U, 51U, 59U, 58U, 50U, 42U, 34U,
            27U, 19U, 11U,  3U,  2U, 10U, 18U, 26U,
            24U, 16U,  8U,  0U,  1U,  9U, 17U, 25U,
            32U, 40U, 48U, 56U, 57U, 49U, 41U, 33U
);
}






Recipe8x8 RecipeFactory8x8::OpalD() {
//  AA AB AC AD AE AF AG AH      DG CG BG AG AH BH CH DH
//  BA BB BC BD BE BF BG BH  ->  EG FG GG HG HH GH FH EH
//  CA CB CC CD CE CF CG CH      EF FF GF HF HE GE FE EE
//  DA DB DC DD DE DF DG DH      DF CF BF AF AE BE CE DE
//  EA EB EC ED EE EF EG EH      DC CC BC AC AD BD CD DD
//  FA FB FC FD FE FF FG FH      EC FC GC HC HD GD FD ED
//  GA GB GC GD GE GF GG GH      EB FB GB HB HA GA FA EA
//  HA HB HC HD HE HF HG HH      DB CB BB AB AA BA CA DA
return Make("OpalD",
            30U, 22U, 14U,  6U,  7U, 15U, 23U, 31U,
            38U, 46U, 54U, 62U, 63U, 55U, 47U, 39U,
            37U, 45U, 53U, 61U, 60U, 52U, 44U, 36U,
            29U, 21U, 13U,  5U,  4U, 12U, 20U, 28U,
            26U, 18U, 10U,  2U,  3U, 11U, 19U, 27U,
            34U, 42U, 50U, 58U, 59U, 51U, 43U, 35U,
            33U, 41U, 49U, 57U, 56U, 48U, 40U, 32U,
            25U, 17U,  9U,  1U,  0U,  8U, 16U, 24U
);
}







Recipe8x8 RecipeFactory8x8::PeridotA() {
//  AA AB AC AD AE AF AG AH      HD HC HB HA GA GB GC GD
//  BA BB BC BD BE BF BG BH  ->  HE HF HG HH GH GG GF GE
//  CA CB CC CD CE CF CG CH      EE EF EG EH FH FG FF FE
//  DA DB DC DD DE DF DG DH      ED EC EB EA FA FB FC FD
//  EA EB EC ED EE EF EG EH      DD DC DB DA CA CB CC CD
//  FA FB FC FD FE FF FG FH      DE DF DG DH CH CG CF CE
//  GA GB GC GD GE GF GG GH      AE AF AG AH BH BG BF BE
//  HA HB HC HD HE HF HG HH      AD AC AB AA BA BB BC BD
return Make("PeridotA",
            59U, 58U, 57U, 56U, 48U, 49U, 50U, 51U,
            60U, 61U, 62U, 63U, 55U, 54U, 53U, 52U,
            36U, 37U, 38U, 39U, 47U, 46U, 45U, 44U,
            35U, 34U, 33U, 32U, 40U, 41U, 42U, 43U,
            27U, 26U, 25U, 24U, 16U, 17U, 18U, 19U,
            28U, 29U, 30U, 31U, 23U, 22U, 21U, 20U,
             4U,  5U,  6U,  7U, 15U, 14U, 13U, 12U,
             3U,  2U,  1U,  0U,  8U,  9U, 10U, 11U
);
}


Recipe8x8 RecipeFactory8x8::PeridotB() {
//  AA AB AC AD AE AF AG AH      GE GF GG GH HH HG HF HE
//  BA BB BC BD BE BF BG BH  ->  GD GC GB GA HA HB HC HD
//  CA CB CC CD CE CF CG CH      FD FC FB FA EA EB EC ED
//  DA DB DC DD DE DF DG DH      FE FF FG FH EH EG EF EE
//  EA EB EC ED EE EF EG EH      CE CF CG CH DH DG DF DE
//  FA FB FC FD FE FF FG FH      CD CC CB CA DA DB DC DD
//  GA GB GC GD GE GF GG GH      BD BC BB BA AA AB AC AD
//  HA HB HC HD HE HF HG HH      BE BF BG BH AH AG AF AE
return Make("PeridotB",
            52U, 53U, 54U, 55U, 63U, 62U, 61U, 60U,
            51U, 50U, 49U, 48U, 56U, 57U, 58U, 59U,
            43U, 42U, 41U, 40U, 32U, 33U, 34U, 35U,
            44U, 45U, 46U, 47U, 39U, 38U, 37U, 36U,
            20U, 21U, 22U, 23U, 31U, 30U, 29U, 28U,
            19U, 18U, 17U, 16U, 24U, 25U, 26U, 27U,
            11U, 10U,  9U,  8U,  0U,  1U,  2U,  3U,
            12U, 13U, 14U, 15U,  7U,  6U,  5U,  4U
);
}





Recipe8x8 RecipeFactory8x8::PeridotC() {
//  AA AB AC AD AE AF AG AH      EG DG DF EF EC DC DB EB
//  BA BB BC BD BE BF BG BH  ->  FG CG CF FF FC CC CB FB
//  CA CB CC CD CE CF CG CH      GG BG BF GF GC BC BB GB
//  DA DB DC DD DE DF DG DH      HG AG AF HF HC AC AB HB
//  EA EB EC ED EE EF EG EH      HH AH AE HE HD AD AA HA
//  FA FB FC FD FE FF FG FH      GH BH BE GE GD BD BA GA
//  GA GB GC GD GE GF GG GH      FH CH CE FE FD CD CA FA
//  HA HB HC HD HE HF HG HH      EH DH DE EE ED DD DA EA
return Make("PeridotC",
            38U, 30U, 29U, 37U, 34U, 26U, 25U, 33U,
            46U, 22U, 21U, 45U, 42U, 18U, 17U, 41U,
            54U, 14U, 13U, 53U, 50U, 10U,  9U, 49U,
            62U,  6U,  5U, 61U, 58U,  2U,  1U, 57U,
            63U,  7U,  4U, 60U, 59U,  3U,  0U, 56U,
            55U, 15U, 12U, 52U, 51U, 11U,  8U, 48U,
            47U, 23U, 20U, 44U, 43U, 19U, 16U, 40U,
            39U, 31U, 28U, 36U, 35U, 27U, 24U, 32U
);
}








Recipe8x8 RecipeFactory8x8::PeridotD() {
//  AA AB AC AD AE AF AG AH      DH EH EE DE DD ED EA DA
//  BA BB BC BD BE BF BG BH  ->  CH FH FE CE CD FD FA CA
//  CA CB CC CD CE CF CG CH      BH GH GE BE BD GD GA BA
//  DA DB DC DD DE DF DG DH      AH HH HE AE AD HD HA AA
//  EA EB EC ED EE EF EG EH      AG HG HF AF AC HC HB AB
//  FA FB FC FD FE FF FG FH      BG GG GF BF BC GC GB BB
//  GA GB GC GD GE GF GG GH      CG FG FF CF CC FC FB CB
//  HA HB HC HD HE HF HG HH      DG EG EF DF DC EC EB DB
return Make("PeridotD",
            31U, 39U, 36U, 28U, 27U, 35U, 32U, 24U,
            23U, 47U, 44U, 20U, 19U, 43U, 40U, 16U,
            15U, 55U, 52U, 12U, 11U, 51U, 48U,  8U,
             7U, 63U, 60U,  4U,  3U, 59U, 56U,  0U,
             6U, 62U, 61U,  5U,  2U, 58U, 57U,  1U,
            14U, 54U, 53U, 13U, 10U, 50U, 49U,  9U,
            22U, 46U, 45U, 21U, 18U, 42U, 41U, 17U,
            30U, 38U, 37U, 29U, 26U, 34U, 33U, 25U
);
}


Recipe8x8 RecipeFactory8x8::SwanA() {
    //  AA AB AC AD AE AF AG AH      EH EA EB EC ED EE EF EG
    //  BA BB BC BD BE BF BG BH  ->  FH FA FB FC FD FE FF FG
    //  CA CB CC CD CE CF CG CH      GH GA GB GC GD GE GF GG
    //  DA DB DC DD DE DF DG DH      HH HA HB HC HD HE HF HG
    //  EA EB EC ED EE EF EG EH      AB AA AD AC AF AE AH AG
    //  FA FB FC FD FE FF FG FH      BB BA BD BC BF BE BH BG
    //  GA GB GC GD GE GF GG GH      CB CA CD CC CF CE CH CG
    //  HA HB HC HD HE HF HG HH      DB DA DD DC DF DE DH DG
    return Make("SwanA",
                39U, 32U, 33U, 34U, 35U, 36U, 37U, 38U,
                47U, 40U, 41U, 42U, 43U, 44U, 45U, 46U,
                55U, 48U, 49U, 50U, 51U, 52U, 53U, 54U,
                63U, 56U, 57U, 58U, 59U, 60U, 61U, 62U,
                 1U,  0U,  3U,  2U,  5U,  4U,  7U,  6U,
                 9U,  8U, 11U, 10U, 13U, 12U, 15U, 14U,
                17U, 16U, 19U, 18U, 21U, 20U, 23U, 22U,
                25U, 24U, 27U, 26U, 29U, 28U, 31U, 30U
    );
}

Recipe8x8 RecipeFactory8x8::SwanB() {
    //  AA AB AC AD AE AF AG AH      DB CB BB AB HH GH FH EH
    //  BA BB BC BD BE BF BG BH  ->  DA CA BA AA HA GA FA EA
    //  CA CB CC CD CE CF CG CH      DD CD BD AD HB GB FB EB
    //  DA DB DC DD DE DF DG DH      DC CC BC AC HC GC FC EC
    //  EA EB EC ED EE EF EG EH      DF CF BF AF HD GD FD ED
    //  FA FB FC FD FE FF FG FH      DE CE BE AE HE GE FE EE
    //  GA GB GC GD GE GF GG GH      DH CH BH AH HF GF FF EF
    //  HA HB HC HD HE HF HG HH      DG CG BG AG HG GG FG EG
    return Make("SwanB",
                25U, 17U,  9U,  1U, 63U, 55U, 47U, 39U,
                24U, 16U,  8U,  0U, 56U, 48U, 40U, 32U,
                27U, 19U, 11U,  3U, 57U, 49U, 41U, 33U,
                26U, 18U, 10U,  2U, 58U, 50U, 42U, 34U,
                29U, 21U, 13U,  5U, 59U, 51U, 43U, 35U,
                28U, 20U, 12U,  4U, 60U, 52U, 44U, 36U,
                31U, 23U, 15U,  7U, 61U, 53U, 45U, 37U,
                30U, 22U, 14U,  6U, 62U, 54U, 46U, 38U
    );
}

Recipe8x8 RecipeFactory8x8::SwanC() {
    //  AA AB AC AD AE AF AG AH      DG DH DE DF DC DD DA DB
    //  BA BB BC BD BE BF BG BH  ->  CG CH CE CF CC CD CA CB
    //  CA CB CC CD CE CF CG CH      BG BH BE BF BC BD BA BB
    //  DA DB DC DD DE DF DG DH      AG AH AE AF AC AD AA AB
    //  EA EB EC ED EE EF EG EH      HG HF HE HD HC HB HA HH
    //  FA FB FC FD FE FF FG FH      GG GF GE GD GC GB GA GH
    //  GA GB GC GD GE GF GG GH      FG FF FE FD FC FB FA FH
    //  HA HB HC HD HE HF HG HH      EG EF EE ED EC EB EA EH
    return Make("SwanC",
                30U, 31U, 28U, 29U, 26U, 27U, 24U, 25U,
                22U, 23U, 20U, 21U, 18U, 19U, 16U, 17U,
                14U, 15U, 12U, 13U, 10U, 11U,  8U,  9U,
                 6U,  7U,  4U,  5U,  2U,  3U,  0U,  1U,
                62U, 61U, 60U, 59U, 58U, 57U, 56U, 63U,
                54U, 53U, 52U, 51U, 50U, 49U, 48U, 55U,
                46U, 45U, 44U, 43U, 42U, 41U, 40U, 47U,
                38U, 37U, 36U, 35U, 34U, 33U, 32U, 39U
    );
}

Recipe8x8 RecipeFactory8x8::SwanD() {
    //  AA AB AC AD AE AF AG AH      EG FG GG HG AG BG CG DG
    //  BA BB BC BD BE BF BG BH  ->  EF FF GF HF AH BH CH DH
    //  CA CB CC CD CE CF CG CH      EE FE GE HE AE BE CE DE
    //  DA DB DC DD DE DF DG DH      ED FD GD HD AF BF CF DF
    //  EA EB EC ED EE EF EG EH      EC FC GC HC AC BC CC DC
    //  FA FB FC FD FE FF FG FH      EB FB GB HB AD BD CD DD
    //  GA GB GC GD GE GF GG GH      EA FA GA HA AA BA CA DA
    //  HA HB HC HD HE HF HG HH      EH FH GH HH AB BB CB DB
    return Make("SwanD",
                38U, 46U, 54U, 62U,  6U, 14U, 22U, 30U,
                37U, 45U, 53U, 61U,  7U, 15U, 23U, 31U,
                36U, 44U, 52U, 60U,  4U, 12U, 20U, 28U,
                35U, 43U, 51U, 59U,  5U, 13U, 21U, 29U,
                34U, 42U, 50U, 58U,  2U, 10U, 18U, 26U,
                33U, 41U, 49U, 57U,  3U, 11U, 19U, 27U,
                32U, 40U, 48U, 56U,  0U,  8U, 16U, 24U,
                39U, 47U, 55U, 63U,  1U,  9U, 17U, 25U
    );
}

Recipe8x8 RecipeFactory8x8::GooseA() {
    //  AA AB AC AD AE AF AG AH      EB EC ED EE EF EG EH EA
    //  BA BB BC BD BE BF BG BH  ->  FB FC FD FE FF FG FH FA
    //  CA CB CC CD CE CF CG CH      GB GC GD GE GF GG GH GA
    //  DA DB DC DD DE DF DG DH      HB HC HD HE HF HG HH HA
    //  EA EB EC ED EE EF EG EH      AB AC AD AE AF AG AH AA
    //  FA FB FC FD FE FF FG FH      BB BC BD BE BF BG BH BA
    //  GA GB GC GD GE GF GG GH      CB CC CD CE CF CG CH CA
    //  HA HB HC HD HE HF HG HH      DB DC DD DE DF DG DH DA
    return Make("GooseA",
                33U, 34U, 35U, 36U, 37U, 38U, 39U, 32U,
                41U, 42U, 43U, 44U, 45U, 46U, 47U, 40U,
                49U, 50U, 51U, 52U, 53U, 54U, 55U, 48U,
                57U, 58U, 59U, 60U, 61U, 62U, 63U, 56U,
                 1U,  2U,  3U,  4U,  5U,  6U,  7U,  0U,
                 9U, 10U, 11U, 12U, 13U, 14U, 15U,  8U,
                17U, 18U, 19U, 20U, 21U, 22U, 23U, 16U,
                25U, 26U, 27U, 28U, 29U, 30U, 31U, 24U
    );
}

Recipe8x8 RecipeFactory8x8::GooseB() {
    //  AA AB AC AD AE AF AG AH      DB CB BB AB HB GB FB EB
    //  BA BB BC BD BE BF BG BH  ->  DC CC BC AC HC GC FC EC
    //  CA CB CC CD CE CF CG CH      DD CD BD AD HD GD FD ED
    //  DA DB DC DD DE DF DG DH      DE CE BE AE HE GE FE EE
    //  EA EB EC ED EE EF EG EH      DF CF BF AF HF GF FF EF
    //  FA FB FC FD FE FF FG FH      DG CG BG AG HG GG FG EG
    //  GA GB GC GD GE GF GG GH      DH CH BH AH HH GH FH EH
    //  HA HB HC HD HE HF HG HH      DA CA BA AA HA GA FA EA
    return Make("GooseB",
                25U, 17U,  9U,  1U, 57U, 49U, 41U, 33U,
                26U, 18U, 10U,  2U, 58U, 50U, 42U, 34U,
                27U, 19U, 11U,  3U, 59U, 51U, 43U, 35U,
                28U, 20U, 12U,  4U, 60U, 52U, 44U, 36U,
                29U, 21U, 13U,  5U, 61U, 53U, 45U, 37U,
                30U, 22U, 14U,  6U, 62U, 54U, 46U, 38U,
                31U, 23U, 15U,  7U, 63U, 55U, 47U, 39U,
                24U, 16U,  8U,  0U, 56U, 48U, 40U, 32U
    );
}

Recipe8x8 RecipeFactory8x8::GooseC() {
    //  AA AB AC AD AE AF AG AH      DA DH DG DF DE DD DC DB
    //  BA BB BC BD BE BF BG BH  ->  CA CH CG CF CE CD CC CB
    //  CA CB CC CD CE CF CG CH      BA BH BG BF BE BD BC BB
    //  DA DB DC DD DE DF DG DH      AA AH AG AF AE AD AC AB
    //  EA EB EC ED EE EF EG EH      HA HH HG HF HE HD HC HB
    //  FA FB FC FD FE FF FG FH      GA GH GG GF GE GD GC GB
    //  GA GB GC GD GE GF GG GH      FA FH FG FF FE FD FC FB
    //  HA HB HC HD HE HF HG HH      EA EH EG EF EE ED EC EB
    return Make("GooseC",
                24U, 31U, 30U, 29U, 28U, 27U, 26U, 25U,
                16U, 23U, 22U, 21U, 20U, 19U, 18U, 17U,
                 8U, 15U, 14U, 13U, 12U, 11U, 10U,  9U,
                 0U,  7U,  6U,  5U,  4U,  3U,  2U,  1U,
                56U, 63U, 62U, 61U, 60U, 59U, 58U, 57U,
                48U, 55U, 54U, 53U, 52U, 51U, 50U, 49U,
                40U, 47U, 46U, 45U, 44U, 43U, 42U, 41U,
                32U, 39U, 38U, 37U, 36U, 35U, 34U, 33U
    );
}

Recipe8x8 RecipeFactory8x8::GooseD() {
    //  AA AB AC AD AE AF AG AH      EA FA GA HA AA BA CA DA
    //  BA BB BC BD BE BF BG BH  ->  EH FH GH HH AH BH CH DH
    //  CA CB CC CD CE CF CG CH      EG FG GG HG AG BG CG DG
    //  DA DB DC DD DE DF DG DH      EF FF GF HF AF BF CF DF
    //  EA EB EC ED EE EF EG EH      EE FE GE HE AE BE CE DE
    //  FA FB FC FD FE FF FG FH      ED FD GD HD AD BD CD DD
    //  GA GB GC GD GE GF GG GH      EC FC GC HC AC BC CC DC
    //  HA HB HC HD HE HF HG HH      EB FB GB HB AB BB CB DB
    return Make("GooseD",
                32U, 40U, 48U, 56U,  0U,  8U, 16U, 24U,
                39U, 47U, 55U, 63U,  7U, 15U, 23U, 31U,
                38U, 46U, 54U, 62U,  6U, 14U, 22U, 30U,
                37U, 45U, 53U, 61U,  5U, 13U, 21U, 29U,
                36U, 44U, 52U, 60U,  4U, 12U, 20U, 28U,
                35U, 43U, 51U, 59U,  3U, 11U, 19U, 27U,
                34U, 42U, 50U, 58U,  2U, 10U, 18U, 26U,
                33U, 41U, 49U, 57U,  1U,  9U, 17U, 25U
    );
}

Recipe8x8 RecipeFactory8x8::HeronA() {
    //  AA AB AC AD AE AF AG AH      AB AA AD AC AF AE AH AG
    //  BA BB BC BD BE BF BG BH  ->  BB BA BD BC BF BE BH BG
    //  CA CB CC CD CE CF CG CH      CB CA CD CC CF CE CH CG
    //  DA DB DC DD DE DF DG DH      DB DA DD DC DF DE DH DG
    //  EA EB EC ED EE EF EG EH      EH EC EB EE ED EG EF EA
    //  FA FB FC FD FE FF FG FH      FH FC FB FE FD FG FF FA
    //  GA GB GC GD GE GF GG GH      GH GC GB GE GD GG GF GA
    //  HA HB HC HD HE HF HG HH      HH HC HB HE HD HG HF HA
    return Make("HeronA",
                 1U,  0U,  3U,  2U,  5U,  4U,  7U,  6U,
                 9U,  8U, 11U, 10U, 13U, 12U, 15U, 14U,
                17U, 16U, 19U, 18U, 21U, 20U, 23U, 22U,
                25U, 24U, 27U, 26U, 29U, 28U, 31U, 30U,
                39U, 34U, 33U, 36U, 35U, 38U, 37U, 32U,
                47U, 42U, 41U, 44U, 43U, 46U, 45U, 40U,
                55U, 50U, 49U, 52U, 51U, 54U, 53U, 48U,
                63U, 58U, 57U, 60U, 59U, 62U, 61U, 56U
    );
}

Recipe8x8 RecipeFactory8x8::HeronB() {
    //  AA AB AC AD AE AF AG AH      HH GH FH EH DB CB BB AB
    //  BA BB BC BD BE BF BG BH  ->  HC GC FC EC DA CA BA AA
    //  CA CB CC CD CE CF CG CH      HB GB FB EB DD CD BD AD
    //  DA DB DC DD DE DF DG DH      HE GE FE EE DC CC BC AC
    //  EA EB EC ED EE EF EG EH      HD GD FD ED DF CF BF AF
    //  FA FB FC FD FE FF FG FH      HG GG FG EG DE CE BE AE
    //  GA GB GC GD GE GF GG GH      HF GF FF EF DH CH BH AH
    //  HA HB HC HD HE HF HG HH      HA GA FA EA DG CG BG AG
    return Make("HeronB",
                63U, 55U, 47U, 39U, 25U, 17U,  9U,  1U,
                58U, 50U, 42U, 34U, 24U, 16U,  8U,  0U,
                57U, 49U, 41U, 33U, 27U, 19U, 11U,  3U,
                60U, 52U, 44U, 36U, 26U, 18U, 10U,  2U,
                59U, 51U, 43U, 35U, 29U, 21U, 13U,  5U,
                62U, 54U, 46U, 38U, 28U, 20U, 12U,  4U,
                61U, 53U, 45U, 37U, 31U, 23U, 15U,  7U,
                56U, 48U, 40U, 32U, 30U, 22U, 14U,  6U
    );
}

Recipe8x8 RecipeFactory8x8::HeronC() {
    //  AA AB AC AD AE AF AG AH      HA HF HG HD HE HB HC HH
    //  BA BB BC BD BE BF BG BH  ->  GA GF GG GD GE GB GC GH
    //  CA CB CC CD CE CF CG CH      FA FF FG FD FE FB FC FH
    //  DA DB DC DD DE DF DG DH      EA EF EG ED EE EB EC EH
    //  EA EB EC ED EE EF EG EH      DG DH DE DF DC DD DA DB
    //  FA FB FC FD FE FF FG FH      CG CH CE CF CC CD CA CB
    //  GA GB GC GD GE GF GG GH      BG BH BE BF BC BD BA BB
    //  HA HB HC HD HE HF HG HH      AG AH AE AF AC AD AA AB
    return Make("HeronC",
                56U, 61U, 62U, 59U, 60U, 57U, 58U, 63U,
                48U, 53U, 54U, 51U, 52U, 49U, 50U, 55U,
                40U, 45U, 46U, 43U, 44U, 41U, 42U, 47U,
                32U, 37U, 38U, 35U, 36U, 33U, 34U, 39U,
                30U, 31U, 28U, 29U, 26U, 27U, 24U, 25U,
                22U, 23U, 20U, 21U, 18U, 19U, 16U, 17U,
                14U, 15U, 12U, 13U, 10U, 11U,  8U,  9U,
                 6U,  7U,  4U,  5U,  2U,  3U,  0U,  1U
    );
}

Recipe8x8 RecipeFactory8x8::HeronD() {
    //  AA AB AC AD AE AF AG AH      AG BG CG DG EA FA GA HA
    //  BA BB BC BD BE BF BG BH  ->  AH BH CH DH EF FF GF HF
    //  CA CB CC CD CE CF CG CH      AE BE CE DE EG FG GG HG
    //  DA DB DC DD DE DF DG DH      AF BF CF DF ED FD GD HD
    //  EA EB EC ED EE EF EG EH      AC BC CC DC EE FE GE HE
    //  FA FB FC FD FE FF FG FH      AD BD CD DD EB FB GB HB
    //  GA GB GC GD GE GF GG GH      AA BA CA DA EC FC GC HC
    //  HA HB HC HD HE HF HG HH      AB BB CB DB EH FH GH HH
    return Make("HeronD",
                 6U, 14U, 22U, 30U, 32U, 40U, 48U, 56U,
                 7U, 15U, 23U, 31U, 37U, 45U, 53U, 61U,
                 4U, 12U, 20U, 28U, 38U, 46U, 54U, 62U,
                 5U, 13U, 21U, 29U, 35U, 43U, 51U, 59U,
                 2U, 10U, 18U, 26U, 36U, 44U, 52U, 60U,
                 3U, 11U, 19U, 27U, 33U, 41U, 49U, 57U,
                 0U,  8U, 16U, 24U, 34U, 42U, 50U, 58U,
                 1U,  9U, 17U, 25U, 39U, 47U, 55U, 63U
    );
}

Recipe8x8 RecipeFactory8x8::FalconA() {
    //  AA AB AC AD AE AF AG AH      AB AC AD AE AF AG AH AA
    //  BA BB BC BD BE BF BG BH  ->  BB BC BD BE BF BG BH BA
    //  CA CB CC CD CE CF CG CH      CB CC CD CE CF CG CH CA
    //  DA DB DC DD DE DF DG DH      DB DC DD DE DF DG DH DA
    //  EA EB EC ED EE EF EG EH      EB EA ED EC EF EE EH EG
    //  FA FB FC FD FE FF FG FH      FB FA FD FC FF FE FH FG
    //  GA GB GC GD GE GF GG GH      GB GA GD GC GF GE GH GG
    //  HA HB HC HD HE HF HG HH      HB HA HD HC HF HE HH HG
    return Make("FalconA",
                 1U,  2U,  3U,  4U,  5U,  6U,  7U,  0U,
                 9U, 10U, 11U, 12U, 13U, 14U, 15U,  8U,
                17U, 18U, 19U, 20U, 21U, 22U, 23U, 16U,
                25U, 26U, 27U, 28U, 29U, 30U, 31U, 24U,
                33U, 32U, 35U, 34U, 37U, 36U, 39U, 38U,
                41U, 40U, 43U, 42U, 45U, 44U, 47U, 46U,
                49U, 48U, 51U, 50U, 53U, 52U, 55U, 54U,
                57U, 56U, 59U, 58U, 61U, 60U, 63U, 62U
    );
}

Recipe8x8 RecipeFactory8x8::FalconB() {
    //  AA AB AC AD AE AF AG AH      HB GB FB EB DB CB BB AB
    //  BA BB BC BD BE BF BG BH  ->  HA GA FA EA DC CC BC AC
    //  CA CB CC CD CE CF CG CH      HD GD FD ED DD CD BD AD
    //  DA DB DC DD DE DF DG DH      HC GC FC EC DE CE BE AE
    //  EA EB EC ED EE EF EG EH      HF GF FF EF DF CF BF AF
    //  FA FB FC FD FE FF FG FH      HE GE FE EE DG CG BG AG
    //  GA GB GC GD GE GF GG GH      HH GH FH EH DH CH BH AH
    //  HA HB HC HD HE HF HG HH      HG GG FG EG DA CA BA AA
    return Make("FalconB",
                57U, 49U, 41U, 33U, 25U, 17U,  9U,  1U,
                56U, 48U, 40U, 32U, 26U, 18U, 10U,  2U,
                59U, 51U, 43U, 35U, 27U, 19U, 11U,  3U,
                58U, 50U, 42U, 34U, 28U, 20U, 12U,  4U,
                61U, 53U, 45U, 37U, 29U, 21U, 13U,  5U,
                60U, 52U, 44U, 36U, 30U, 22U, 14U,  6U,
                63U, 55U, 47U, 39U, 31U, 23U, 15U,  7U,
                62U, 54U, 46U, 38U, 24U, 16U,  8U,  0U
    );
}

Recipe8x8 RecipeFactory8x8::FalconC() {
    //  AA AB AC AD AE AF AG AH      HG HH HE HF HC HD HA HB
    //  BA BB BC BD BE BF BG BH  ->  GG GH GE GF GC GD GA GB
    //  CA CB CC CD CE CF CG CH      FG FH FE FF FC FD FA FB
    //  DA DB DC DD DE DF DG DH      EG EH EE EF EC ED EA EB
    //  EA EB EC ED EE EF EG EH      DA DH DG DF DE DD DC DB
    //  FA FB FC FD FE FF FG FH      CA CH CG CF CE CD CC CB
    //  GA GB GC GD GE GF GG GH      BA BH BG BF BE BD BC BB
    //  HA HB HC HD HE HF HG HH      AA AH AG AF AE AD AC AB
    return Make("FalconC",
                62U, 63U, 60U, 61U, 58U, 59U, 56U, 57U,
                54U, 55U, 52U, 53U, 50U, 51U, 48U, 49U,
                46U, 47U, 44U, 45U, 42U, 43U, 40U, 41U,
                38U, 39U, 36U, 37U, 34U, 35U, 32U, 33U,
                24U, 31U, 30U, 29U, 28U, 27U, 26U, 25U,
                16U, 23U, 22U, 21U, 20U, 19U, 18U, 17U,
                 8U, 15U, 14U, 13U, 12U, 11U, 10U,  9U,
                 0U,  7U,  6U,  5U,  4U,  3U,  2U,  1U
    );
}

Recipe8x8 RecipeFactory8x8::FalconD() {
    //  AA AB AC AD AE AF AG AH      AA BA CA DA EG FG GG HG
    //  BA BB BC BD BE BF BG BH  ->  AH BH CH DH EH FH GH HH
    //  CA CB CC CD CE CF CG CH      AG BG CG DG EE FE GE HE
    //  DA DB DC DD DE DF DG DH      AF BF CF DF EF FF GF HF
    //  EA EB EC ED EE EF EG EH      AE BE CE DE EC FC GC HC
    //  FA FB FC FD FE FF FG FH      AD BD CD DD ED FD GD HD
    //  GA GB GC GD GE GF GG GH      AC BC CC DC EA FA GA HA
    //  HA HB HC HD HE HF HG HH      AB BB CB DB EB FB GB HB
    return Make("FalconD",
                 0U,  8U, 16U, 24U, 38U, 46U, 54U, 62U,
                 7U, 15U, 23U, 31U, 39U, 47U, 55U, 63U,
                 6U, 14U, 22U, 30U, 36U, 44U, 52U, 60U,
                 5U, 13U, 21U, 29U, 37U, 45U, 53U, 61U,
                 4U, 12U, 20U, 28U, 34U, 42U, 50U, 58U,
                 3U, 11U, 19U, 27U, 35U, 43U, 51U, 59U,
                 2U, 10U, 18U, 26U, 32U, 40U, 48U, 56U,
                 1U,  9U, 17U, 25U, 33U, 41U, 49U, 57U
    );
}


Recipe8x8 RecipeFactory8x8::IronA() {
    //  AA AB AC AD AE AF AG AH      EE AC EC AA EA AG EG AE
    //  BA BB BC BD BE BF BG BH  ->  FG BE FE BC FC BA FA BG
    //  CA CB CC CD CE CF CG CH      GE CC GC CA GA CG GG CE
    //  DA DB DC DD DE DF DG DH      HG DE HE DC HC DA HA DG
    //  EA EB EC ED EE EF EG EH      ED AD EB AB EH AH EF AF
    //  FA FB FC FD FE FF FG FH      FF BF FD BD FB BB FH BH
    //  GA GB GC GD GE GF GG GH      GD CD GB CB GH CH GF CF
    //  HA HB HC HD HE HF HG HH      HF DF HD DD HB DB HH DH
    return Make("IronA",
                36U,  2U, 34U,  0U, 32U,  6U, 38U,  4U,
                46U, 12U, 44U, 10U, 42U,  8U, 40U, 14U,
                52U, 18U, 50U, 16U, 48U, 22U, 54U, 20U,
                62U, 28U, 60U, 26U, 58U, 24U, 56U, 30U,
                35U,  3U, 33U,  1U, 39U,  7U, 37U,  5U,
                45U, 13U, 43U, 11U, 41U,  9U, 47U, 15U,
                51U, 19U, 49U, 17U, 55U, 23U, 53U, 21U,
                61U, 29U, 59U, 27U, 57U, 25U, 63U, 31U
    );
}

Recipe8x8 RecipeFactory8x8::IronB() {
    //  AA AB AC AD AE AF AG AH      HF GD FF ED HG GE FG EE
    //  BA BB BC BD BE BF BG BH  ->  DF CD BF AD DE CC BE AC
    //  CA CB CC CD CE CF CG CH      HD GB FD EB HE GC FE EC
    //  DA DB DC DD DE DF DG DH      DD CB BD AB DC CA BC AA
    //  EA EB EC ED EE EF EG EH      HB GH FB EH HC GA FC EA
    //  FA FB FC FD FE FF FG FH      DB CH BB AH DA CG BA AG
    //  GA GB GC GD GE GF GG GH      HH GF FH EF HA GG FA EG
    //  HA HB HC HD HE HF HG HH      DH CF BH AF DG CE BG AE
    return Make("IronB",
                61U, 51U, 45U, 35U, 62U, 52U, 46U, 36U,
                29U, 19U, 13U,  3U, 28U, 18U, 12U,  2U,
                59U, 49U, 43U, 33U, 60U, 50U, 44U, 34U,
                27U, 17U, 11U,  1U, 26U, 16U, 10U,  0U,
                57U, 55U, 41U, 39U, 58U, 48U, 42U, 32U,
                25U, 23U,  9U,  7U, 24U, 22U,  8U,  6U,
                63U, 53U, 47U, 37U, 56U, 54U, 40U, 38U,
                31U, 21U, 15U,  5U, 30U, 20U, 14U,  4U
    );
}

Recipe8x8 RecipeFactory8x8::IronC() {
    //  AA AB AC AD AE AF AG AH      DH HH DB HB DD HD DF HF
    //  BA BB BC BD BE BF BG BH  ->  CF GF CH GH CB GB CD GD
    //  CA CB CC CD CE CF CG CH      BH FH BB FB BD FD BF FF
    //  DA DB DC DD DE DF DG DH      AF EF AH EH AB EB AD ED
    //  EA EB EC ED EE EF EG EH      DG HA DA HC DC HE DE HG
    //  FA FB FC FD FE FF FG FH      CE GG CG GA CA GC CC GE
    //  GA GB GC GD GE GF GG GH      BG FA BA FC BC FE BE FG
    //  HA HB HC HD HE HF HG HH      AE EG AG EA AA EC AC EE
    return Make("IronC",
                31U, 63U, 25U, 57U, 27U, 59U, 29U, 61U,
                21U, 53U, 23U, 55U, 17U, 49U, 19U, 51U,
                15U, 47U,  9U, 41U, 11U, 43U, 13U, 45U,
                 5U, 37U,  7U, 39U,  1U, 33U,  3U, 35U,
                30U, 56U, 24U, 58U, 26U, 60U, 28U, 62U,
                20U, 54U, 22U, 48U, 16U, 50U, 18U, 52U,
                14U, 40U,  8U, 42U, 10U, 44U, 12U, 46U,
                 4U, 38U,  6U, 32U,  0U, 34U,  2U, 36U
    );
}

Recipe8x8 RecipeFactory8x8::IronD() {
    //  AA AB AC AD AE AF AG AH      AE BG CE DG AF BH CF DH
    //  BA BB BC BD BE BF BG BH  ->  EG FA GG HA EF FH GF HH
    //  CA CB CC CD CE CF CG CH      AG BA CG DA AH BB CH DB
    //  DA DB DC DD DE DF DG DH      EA FC GA HC EH FB GH HB
    //  EA EB EC ED EE EF EG EH      AA BC CA DC AB BD CB DD
    //  FA FB FC FD FE FF FG FH      EC FE GC HE EB FD GB HD
    //  GA GB GC GD GE GF GG GH      AC BE CC DE AD BF CD DF
    //  HA HB HC HD HE HF HG HH      EE FG GE HG ED FF GD HF
    return Make("IronD",
                 4U, 14U, 20U, 30U,  5U, 15U, 21U, 31U,
                38U, 40U, 54U, 56U, 37U, 47U, 53U, 63U,
                 6U,  8U, 22U, 24U,  7U,  9U, 23U, 25U,
                32U, 42U, 48U, 58U, 39U, 41U, 55U, 57U,
                 0U, 10U, 16U, 26U,  1U, 11U, 17U, 27U,
                34U, 44U, 50U, 60U, 33U, 43U, 49U, 59U,
                 2U, 12U, 18U, 28U,  3U, 13U, 19U, 29U,
                36U, 46U, 52U, 62U, 35U, 45U, 51U, 61U
    );
}

Recipe8x8 RecipeFactory8x8::SteelA() {
    //  AA AB AC AD AE AF AG AH      EG AE EE AC EC AA EA AG
    //  BA BB BC BD BE BF BG BH  ->  FE BC FC BA FA BG FG BE
    //  CA CB CC CD CE CF CG CH      GG CE GE CC GC CA GA CG
    //  DA DB DC DD DE DF DG DH      HE DC HC DA HA DG HG DE
    //  EA EB EC ED EE EF EG EH      EF AF ED AD EB AB EH AH
    //  FA FB FC FD FE FF FG FH      FD BD FB BB FH BH FF BF
    //  GA GB GC GD GE GF GG GH      GF CF GD CD GB CB GH CH
    //  HA HB HC HD HE HF HG HH      HD DD HB DB HH DH HF DF
    return Make("SteelA",
                38U,  4U, 36U,  2U, 34U,  0U, 32U,  6U,
                44U, 10U, 42U,  8U, 40U, 14U, 46U, 12U,
                54U, 20U, 52U, 18U, 50U, 16U, 48U, 22U,
                60U, 26U, 58U, 24U, 56U, 30U, 62U, 28U,
                37U,  5U, 35U,  3U, 33U,  1U, 39U,  7U,
                43U, 11U, 41U,  9U, 47U, 15U, 45U, 13U,
                53U, 21U, 51U, 19U, 49U, 17U, 55U, 23U,
                59U, 27U, 57U, 25U, 63U, 31U, 61U, 29U
    );
}

Recipe8x8 RecipeFactory8x8::SteelB() {
    //  AA AB AC AD AE AF AG AH      HD GF FD EF HE GG FE EG
    //  BA BB BC BD BE BF BG BH  ->  DD CF BD AF DC CE BC AE
    //  CA CB CC CD CE CF CG CH      HB GD FB ED HC GE FC EE
    //  DA DB DC DD DE DF DG DH      DB CD BB AD DA CC BA AC
    //  EA EB EC ED EE EF EG EH      HH GB FH EB HA GC FA EC
    //  FA FB FC FD FE FF FG FH      DH CB BH AB DG CA BG AA
    //  GA GB GC GD GE GF GG GH      HF GH FF EH HG GA FG EA
    //  HA HB HC HD HE HF HG HH      DF CH BF AH DE CG BE AG
    return Make("SteelB",
                59U, 53U, 43U, 37U, 60U, 54U, 44U, 38U,
                27U, 21U, 11U,  5U, 26U, 20U, 10U,  4U,
                57U, 51U, 41U, 35U, 58U, 52U, 42U, 36U,
                25U, 19U,  9U,  3U, 24U, 18U,  8U,  2U,
                63U, 49U, 47U, 33U, 56U, 50U, 40U, 34U,
                31U, 17U, 15U,  1U, 30U, 16U, 14U,  0U,
                61U, 55U, 45U, 39U, 62U, 48U, 46U, 32U,
                29U, 23U, 13U,  7U, 28U, 22U, 12U,  6U
    );
}

Recipe8x8 RecipeFactory8x8::SteelC() {
    //  AA AB AC AD AE AF AG AH      DF HF DH HH DB HB DD HD
    //  BA BB BC BD BE BF BG BH  ->  CH GH CB GB CD GD CF GF
    //  CA CB CC CD CE CF CG CH      BF FF BH FH BB FB BD FD
    //  DA DB DC DD DE DF DG DH      AH EH AB EB AD ED AF EF
    //  EA EB EC ED EE EF EG EH      DE HG DG HA DA HC DC HE
    //  FA FB FC FD FE FF FG FH      CG GA CA GC CC GE CE GG
    //  GA GB GC GD GE GF GG GH      BE FG BG FA BA FC BC FE
    //  HA HB HC HD HE HF HG HH      AG EA AA EC AC EE AE EG
    return Make("SteelC",
                29U, 61U, 31U, 63U, 25U, 57U, 27U, 59U,
                23U, 55U, 17U, 49U, 19U, 51U, 21U, 53U,
                13U, 45U, 15U, 47U,  9U, 41U, 11U, 43U,
                 7U, 39U,  1U, 33U,  3U, 35U,  5U, 37U,
                28U, 62U, 30U, 56U, 24U, 58U, 26U, 60U,
                22U, 48U, 16U, 50U, 18U, 52U, 20U, 54U,
                12U, 46U, 14U, 40U,  8U, 42U, 10U, 44U,
                 6U, 32U,  0U, 34U,  2U, 36U,  4U, 38U
    );
}

Recipe8x8 RecipeFactory8x8::SteelD() {
    //  AA AB AC AD AE AF AG AH      AG BE CG DE AH BF CH DF
    //  BA BB BC BD BE BF BG BH  ->  EA FG GA HG EH FF GH HF
    //  CA CB CC CD CE CF CG CH      AA BG CA DG AB BH CB DH
    //  DA DB DC DD DE DF DG DH      EC FA GC HA EB FH GB HH
    //  EA EB EC ED EE EF EG EH      AC BA CC DA AD BB CD DB
    //  FA FB FC FD FE FF FG FH      EE FC GE HC ED FB GD HB
    //  GA GB GC GD GE GF GG GH      AE BC CE DC AF BD CF DD
    //  HA HB HC HD HE HF HG HH      EG FE GG HE EF FD GF HD
    return Make("SteelD",
                 6U, 12U, 22U, 28U,  7U, 13U, 23U, 29U,
                32U, 46U, 48U, 62U, 39U, 45U, 55U, 61U,
                 0U, 14U, 16U, 30U,  1U, 15U, 17U, 31U,
                34U, 40U, 50U, 56U, 33U, 47U, 49U, 63U,
                 2U,  8U, 18U, 24U,  3U,  9U, 19U, 25U,
                36U, 42U, 52U, 58U, 35U, 41U, 51U, 57U,
                 4U, 10U, 20U, 26U,  5U, 11U, 21U, 27U,
                38U, 44U, 54U, 60U, 37U, 43U, 53U, 59U
    );
}

Recipe8x8 RecipeFactory8x8::SilverA() {
    //  AA AB AC AD AE AF AG AH      AA EG AG EE AE EC AC EA
    //  BA BB BC BD BE BF BG BH  ->  BA FG BG FE BE FC BC FA
    //  CA CB CC CD CE CF CG CH      CA GG CG GE CE GC CC GA
    //  DA DB DC DD DE DF DG DH      DA HG DG HE DE HC DC HA
    //  EA EB EC ED EE EF EG EH      CH GH CF GF CD GD CB GB
    //  FA FB FC FD FE FF FG FH      DH HH DF HF DD HD DB HB
    //  GA GB GC GD GE GF GG GH      EH AH EF AF ED AD EB AB
    //  HA HB HC HD HE HF HG HH      FH BH FF BF FD BD FB BB
    return Make("SilverA",
                 0U, 38U,  6U, 36U,  4U, 34U,  2U, 32U,
                 8U, 46U, 14U, 44U, 12U, 42U, 10U, 40U,
                16U, 54U, 22U, 52U, 20U, 50U, 18U, 48U,
                24U, 62U, 30U, 60U, 28U, 58U, 26U, 56U,
                23U, 55U, 21U, 53U, 19U, 51U, 17U, 49U,
                31U, 63U, 29U, 61U, 27U, 59U, 25U, 57U,
                39U,  7U, 37U,  5U, 35U,  3U, 33U,  1U,
                47U, 15U, 45U, 13U, 43U, 11U, 41U,  9U
    );
}

Recipe8x8 RecipeFactory8x8::SilverB() {
    //  AA AB AC AD AE AF AG AH      FH EH DH CH DA CA BA AA
    //  BA BB BC BD BE BF BG BH  ->  BH AH HH GH HG GG FG EG
    //  CA CB CC CD CE CF CG CH      FF EF DF CF DG CG BG AG
    //  DA DB DC DD DE DF DG DH      BF AF HF GF HE GE FE EE
    //  EA EB EC ED EE EF EG EH      FD ED DD CD DE CE BE AE
    //  FA FB FC FD FE FF FG FH      BD AD HD GD HC GC FC EC
    //  GA GB GC GD GE GF GG GH      FB EB DB CB DC CC BC AC
    //  HA HB HC HD HE HF HG HH      BB AB HB GB HA GA FA EA
    return Make("SilverB",
                47U, 39U, 31U, 23U, 24U, 16U,  8U,  0U,
                15U,  7U, 63U, 55U, 62U, 54U, 46U, 38U,
                45U, 37U, 29U, 21U, 30U, 22U, 14U,  6U,
                13U,  5U, 61U, 53U, 60U, 52U, 44U, 36U,
                43U, 35U, 27U, 19U, 28U, 20U, 12U,  4U,
                11U,  3U, 59U, 51U, 58U, 50U, 42U, 34U,
                41U, 33U, 25U, 17U, 26U, 18U, 10U,  2U,
                 9U,  1U, 57U, 49U, 56U, 48U, 40U, 32U
    );
}

Recipe8x8 RecipeFactory8x8::SilverC() {
    //  AA AB AC AD AE AF AG AH      BB FB BD FD BF FF BH FH
    //  BA BB BC BD BE BF BG BH  ->  AB EB AD ED AF EF AH EH
    //  CA CB CC CD CE CF CG CH      HB DB HD DD HF DF HH DH
    //  DA DB DC DD DE DF DG DH      GB CB GD CD GF CF GH CH
    //  EA EB EC ED EE EF EG EH      HA DC HC DE HE DG HG DA
    //  FA FB FC FD FE FF FG FH      GA CC GC CE GE CG GG CA
    //  GA GB GC GD GE GF GG GH      FA BC FC BE FE BG FG BA
    //  HA HB HC HD HE HF HG HH      EA AC EC AE EE AG EG AA
    return Make("SilverC",
                 9U, 41U, 11U, 43U, 13U, 45U, 15U, 47U,
                 1U, 33U,  3U, 35U,  5U, 37U,  7U, 39U,
                57U, 25U, 59U, 27U, 61U, 29U, 63U, 31U,
                49U, 17U, 51U, 19U, 53U, 21U, 55U, 23U,
                56U, 26U, 58U, 28U, 60U, 30U, 62U, 24U,
                48U, 18U, 50U, 20U, 52U, 22U, 54U, 16U,
                40U, 10U, 42U, 12U, 44U, 14U, 46U,  8U,
                32U,  2U, 34U,  4U, 36U,  6U, 38U,  0U
    );
}

Recipe8x8 RecipeFactory8x8::SilverD() {
    //  AA AB AC AD AE AF AG AH      EA FA GA HA GB HB AB BB
    //  BA BB BC BD BE BF BG BH  ->  AC BC CC DC CB DB EB FB
    //  CA CB CC CD CE CF CG CH      EC FC GC HC GD HD AD BD
    //  DA DB DC DD DE DF DG DH      AE BE CE DE CD DD ED FD
    //  EA EB EC ED EE EF EG EH      EE FE GE HE GF HF AF BF
    //  FA FB FC FD FE FF FG FH      AG BG CG DG CF DF EF FF
    //  GA GB GC GD GE GF GG GH      EG FG GG HG GH HH AH BH
    //  HA HB HC HD HE HF HG HH      AA BA CA DA CH DH EH FH
    return Make("SilverD",
                32U, 40U, 48U, 56U, 49U, 57U,  1U,  9U,
                 2U, 10U, 18U, 26U, 17U, 25U, 33U, 41U,
                34U, 42U, 50U, 58U, 51U, 59U,  3U, 11U,
                 4U, 12U, 20U, 28U, 19U, 27U, 35U, 43U,
                36U, 44U, 52U, 60U, 53U, 61U,  5U, 13U,
                 6U, 14U, 22U, 30U, 21U, 29U, 37U, 45U,
                38U, 46U, 54U, 62U, 55U, 63U,  7U, 15U,
                 0U,  8U, 16U, 24U, 23U, 31U, 39U, 47U
    );
}

Recipe8x8 RecipeFactory8x8::GoldA() {
    //  AA AB AC AD AE AF AG AH      CA GG CG GE CE GC CC GA
    //  BA BB BC BD BE BF BG BH  ->  DA HG DG HE DE HC DC HA
    //  CA CB CC CD CE CF CG CH      EA AG EG AE EE AC EC AA
    //  DA DB DC DD DE DF DG DH      FA BG FG BE FE BC FC BA
    //  EA EB EC ED EE EF EG EH      AH EH AF EF AD ED AB EB
    //  FA FB FC FD FE FF FG FH      BH FH BF FF BD FD BB FB
    //  GA GB GC GD GE GF GG GH      CH GH CF GF CD GD CB GB
    //  HA HB HC HD HE HF HG HH      DH HH DF HF DD HD DB HB
    return Make("GoldA",
                16U, 54U, 22U, 52U, 20U, 50U, 18U, 48U,
                24U, 62U, 30U, 60U, 28U, 58U, 26U, 56U,
                32U,  6U, 38U,  4U, 36U,  2U, 34U,  0U,
                40U, 14U, 46U, 12U, 44U, 10U, 42U,  8U,
                 7U, 39U,  5U, 37U,  3U, 35U,  1U, 33U,
                15U, 47U, 13U, 45U, 11U, 43U,  9U, 41U,
                23U, 55U, 21U, 53U, 19U, 51U, 17U, 49U,
                31U, 63U, 29U, 61U, 27U, 59U, 25U, 57U
    );
}

Recipe8x8 RecipeFactory8x8::GoldB() {
    //  AA AB AC AD AE AF AG AH      DH CH BH AH FA EA DA CA
    //  BA BB BC BD BE BF BG BH  ->  HH GH FH EH BG AG HG GG
    //  CA CB CC CD CE CF CG CH      DF CF BF AF FG EG DG CG
    //  DA DB DC DD DE DF DG DH      HF GF FF EF BE AE HE GE
    //  EA EB EC ED EE EF EG EH      DD CD BD AD FE EE DE CE
    //  FA FB FC FD FE FF FG FH      HD GD FD ED BC AC HC GC
    //  GA GB GC GD GE GF GG GH      DB CB BB AB FC EC DC CC
    //  HA HB HC HD HE HF HG HH      HB GB FB EB BA AA HA GA
    return Make("GoldB",
                31U, 23U, 15U,  7U, 40U, 32U, 24U, 16U,
                63U, 55U, 47U, 39U, 14U,  6U, 62U, 54U,
                29U, 21U, 13U,  5U, 46U, 38U, 30U, 22U,
                61U, 53U, 45U, 37U, 12U,  4U, 60U, 52U,
                27U, 19U, 11U,  3U, 44U, 36U, 28U, 20U,
                59U, 51U, 43U, 35U, 10U,  2U, 58U, 50U,
                25U, 17U,  9U,  1U, 42U, 34U, 26U, 18U,
                57U, 49U, 41U, 33U,  8U,  0U, 56U, 48U
    );
}

Recipe8x8 RecipeFactory8x8::GoldC() {
    //  AA AB AC AD AE AF AG AH      HB DB HD DD HF DF HH DH
    //  BA BB BC BD BE BF BG BH  ->  GB CB GD CD GF CF GH CH
    //  CA CB CC CD CE CF CG CH      FB BB FD BD FF BF FH BH
    //  DA DB DC DD DE DF DG DH      EB AB ED AD EF AF EH AH
    //  EA EB EC ED EE EF EG EH      BA FC BC FE BE FG BG FA
    //  FA FB FC FD FE FF FG FH      AA EC AC EE AE EG AG EA
    //  GA GB GC GD GE GF GG GH      HA DC HC DE HE DG HG DA
    //  HA HB HC HD HE HF HG HH      GA CC GC CE GE CG GG CA
    return Make("GoldC",
                57U, 25U, 59U, 27U, 61U, 29U, 63U, 31U,
                49U, 17U, 51U, 19U, 53U, 21U, 55U, 23U,
                41U,  9U, 43U, 11U, 45U, 13U, 47U, 15U,
                33U,  1U, 35U,  3U, 37U,  5U, 39U,  7U,
                 8U, 42U, 10U, 44U, 12U, 46U, 14U, 40U,
                 0U, 34U,  2U, 36U,  4U, 38U,  6U, 32U,
                56U, 26U, 58U, 28U, 60U, 30U, 62U, 24U,
                48U, 18U, 50U, 20U, 52U, 22U, 54U, 16U
    );
}

Recipe8x8 RecipeFactory8x8::GoldD() {
    //  AA AB AC AD AE AF AG AH      GA HA AA BA EB FB GB HB
    //  BA BB BC BD BE BF BG BH  ->  CC DC EC FC AB BB CB DB
    //  CA CB CC CD CE CF CG CH      GC HC AC BC ED FD GD HD
    //  DA DB DC DD DE DF DG DH      CE DE EE FE AD BD CD DD
    //  EA EB EC ED EE EF EG EH      GE HE AE BE EF FF GF HF
    //  FA FB FC FD FE FF FG FH      CG DG EG FG AF BF CF DF
    //  GA GB GC GD GE GF GG GH      GG HG AG BG EH FH GH HH
    //  HA HB HC HD HE HF HG HH      CA DA EA FA AH BH CH DH
    return Make("GoldD",
                48U, 56U,  0U,  8U, 33U, 41U, 49U, 57U,
                18U, 26U, 34U, 42U,  1U,  9U, 17U, 25U,
                50U, 58U,  2U, 10U, 35U, 43U, 51U, 59U,
                20U, 28U, 36U, 44U,  3U, 11U, 19U, 27U,
                52U, 60U,  4U, 12U, 37U, 45U, 53U, 61U,
                22U, 30U, 38U, 46U,  5U, 13U, 21U, 29U,
                54U, 62U,  6U, 14U, 39U, 47U, 55U, 63U,
                16U, 24U, 32U, 40U,  7U, 15U, 23U, 31U
    );
}

Recipe8x8 RecipeFactory8x8::BronzeA() {
    //  AA AB AC AD AE AF AG AH      DF HH DH HB DB HD DD HF
    //  BA BB BC BD BE BF BG BH  ->  CD GF CF GH CH GB CB GD
    //  CA CB CC CD CE CF CG CH      BF FH BH FB BB FD BD FF
    //  DA DB DC DD DE DF DG DH      AD EF AF EH AH EB AB ED
    //  EA EB EC ED EE EF EG EH      DG HG DA HA DC HC DE HE
    //  FA FB FC FD FE FF FG FH      CE GE CG GG CA GA CC GC
    //  GA GB GC GD GE GF GG GH      BG FG BA FA BC FC BE FE
    //  HA HB HC HD HE HF HG HH      AE EE AG EG AA EA AC EC
    return Make("BronzeA",
                29U, 63U, 31U, 57U, 25U, 59U, 27U, 61U,
                19U, 53U, 21U, 55U, 23U, 49U, 17U, 51U,
                13U, 47U, 15U, 41U,  9U, 43U, 11U, 45U,
                 3U, 37U,  5U, 39U,  7U, 33U,  1U, 35U,
                30U, 62U, 24U, 56U, 26U, 58U, 28U, 60U,
                20U, 52U, 22U, 54U, 16U, 48U, 18U, 50U,
                14U, 46U,  8U, 40U, 10U, 42U, 12U, 44U,
                 4U, 36U,  6U, 38U,  0U, 32U,  2U, 34U
    );
}

Recipe8x8 RecipeFactory8x8::BronzeB() {
    //  AA AB AC AD AE AF AG AH      AE BG CE DG AD BF CD DF
    //  BA BB BC BD BE BF BG BH  ->  EE FG GE HG EF FH GF HH
    //  CA CB CC CD CE CF CG CH      AG BA CG DA AF BH CF DH
    //  DA DB DC DD DE DF DG DH      EG FA GG HA EH FB GH HB
    //  EA EB EC ED EE EF EG EH      AA BC CA DC AH BB CH DB
    //  FA FB FC FD FE FF FG FH      EA FC GA HC EB FD GB HD
    //  GA GB GC GD GE GF GG GH      AC BE CC DE AB BD CB DD
    //  HA HB HC HD HE HF HG HH      EC FE GC HE ED FF GD HF
    return Make("BronzeB",
                 4U, 14U, 20U, 30U,  3U, 13U, 19U, 29U,
                36U, 46U, 52U, 62U, 37U, 47U, 53U, 63U,
                 6U,  8U, 22U, 24U,  5U, 15U, 21U, 31U,
                38U, 40U, 54U, 56U, 39U, 41U, 55U, 57U,
                 0U, 10U, 16U, 26U,  7U,  9U, 23U, 25U,
                32U, 42U, 48U, 58U, 33U, 43U, 49U, 59U,
                 2U, 12U, 18U, 28U,  1U, 11U, 17U, 27U,
                34U, 44U, 50U, 60U, 35U, 45U, 51U, 61U
    );
}

Recipe8x8 RecipeFactory8x8::BronzeC() {
    //  AA AB AC AD AE AF AG AH      EC AC EA AA EG AG EE AE
    //  BA BB BC BD BE BF BG BH  ->  FE BE FC BC FA BA FG BG
    //  CA CB CC CD CE CF CG CH      GC CC GA CA GG CG GE CE
    //  DA DB DC DD DE DF DG DH      HE DE HC DC HA DA HG DG
    //  EA EB EC ED EE EF EG EH      ED AB EB AH EH AF EF AD
    //  FA FB FC FD FE FF FG FH      FF BD FD BB FB BH FH BF
    //  GA GB GC GD GE GF GG GH      GD CB GB CH GH CF GF CD
    //  HA HB HC HD HE HF HG HH      HF DD HD DB HB DH HH DF
    return Make("BronzeC",
                34U,  2U, 32U,  0U, 38U,  6U, 36U,  4U,
                44U, 12U, 42U, 10U, 40U,  8U, 46U, 14U,
                50U, 18U, 48U, 16U, 54U, 22U, 52U, 20U,
                60U, 28U, 58U, 26U, 56U, 24U, 62U, 30U,
                35U,  1U, 33U,  7U, 39U,  5U, 37U,  3U,
                45U, 11U, 43U,  9U, 41U, 15U, 47U, 13U,
                51U, 17U, 49U, 23U, 55U, 21U, 53U, 19U,
                61U, 27U, 59U, 25U, 57U, 31U, 63U, 29U
    );
}

Recipe8x8 RecipeFactory8x8::BronzeD() {
    //  AA AB AC AD AE AF AG AH      HF GD FF ED HE GC FE EC
    //  BA BB BC BD BE BF BG BH  ->  DD CB BD AB DE CC BE AC
    //  CA CB CC CD CE CF CG CH      HD GB FD EB HC GA FC EA
    //  DA DB DC DD DE DF DG DH      DB CH BB AH DC CA BC AA
    //  EA EB EC ED EE EF EG EH      HB GH FB EH HA GG FA EG
    //  FA FB FC FD FE FF FG FH      DH CF BH AF DA CG BA AG
    //  GA GB GC GD GE GF GG GH      HH GF FH EF HG GE FG EE
    //  HA HB HC HD HE HF HG HH      DF CD BF AD DG CE BG AE
    return Make("BronzeD",
                61U, 51U, 45U, 35U, 60U, 50U, 44U, 34U,
                27U, 17U, 11U,  1U, 28U, 18U, 12U,  2U,
                59U, 49U, 43U, 33U, 58U, 48U, 42U, 32U,
                25U, 23U,  9U,  7U, 26U, 16U, 10U,  0U,
                57U, 55U, 41U, 39U, 56U, 54U, 40U, 38U,
                31U, 21U, 15U,  5U, 24U, 22U,  8U,  6U,
                63U, 53U, 47U, 37U, 62U, 52U, 46U, 36U,
                29U, 19U, 13U,  3U, 30U, 20U, 14U,  4U
    );
}

Recipe8x8 RecipeFactory8x8::BrassA() {
    //  AA AB AC AD AE AF AG AH      DD HF DF HH DH HB DB HD
    //  BA BB BC BD BE BF BG BH  ->  CF GH CH GB CB GD CD GF
    //  CA CB CC CD CE CF CG CH      BD FF BF FH BH FB BB FD
    //  DA DB DC DD DE DF DG DH      AF EH AH EB AB ED AD EF
    //  EA EB EC ED EE EF EG EH      DE HE DG HG DA HA DC HC
    //  FA FB FC FD FE FF FG FH      CG GG CA GA CC GC CE GE
    //  GA GB GC GD GE GF GG GH      BE FE BG FG BA FA BC FC
    //  HA HB HC HD HE HF HG HH      AG EG AA EA AC EC AE EE
    return Make("BrassA",
                27U, 61U, 29U, 63U, 31U, 57U, 25U, 59U,
                21U, 55U, 23U, 49U, 17U, 51U, 19U, 53U,
                11U, 45U, 13U, 47U, 15U, 41U,  9U, 43U,
                 5U, 39U,  7U, 33U,  1U, 35U,  3U, 37U,
                28U, 60U, 30U, 62U, 24U, 56U, 26U, 58U,
                22U, 54U, 16U, 48U, 18U, 50U, 20U, 52U,
                12U, 44U, 14U, 46U,  8U, 40U, 10U, 42U,
                 6U, 38U,  0U, 32U,  2U, 34U,  4U, 36U
    );
}

Recipe8x8 RecipeFactory8x8::BrassB() {
    //  AA AB AC AD AE AF AG AH      AG BE CG DE AF BD CF DD
    //  BA BB BC BD BE BF BG BH  ->  EG FE GG HE EH FF GH HF
    //  CA CB CC CD CE CF CG CH      AA BG CA DG AH BF CH DF
    //  DA DB DC DD DE DF DG DH      EA FG GA HG EB FH GB HH
    //  EA EB EC ED EE EF EG EH      AC BA CC DA AB BH CB DH
    //  FA FB FC FD FE FF FG FH      EC FA GC HA ED FB GD HB
    //  GA GB GC GD GE GF GG GH      AE BC CE DC AD BB CD DB
    //  HA HB HC HD HE HF HG HH      EE FC GE HC EF FD GF HD
    return Make("BrassB",
                 6U, 12U, 22U, 28U,  5U, 11U, 21U, 27U,
                38U, 44U, 54U, 60U, 39U, 45U, 55U, 61U,
                 0U, 14U, 16U, 30U,  7U, 13U, 23U, 29U,
                32U, 46U, 48U, 62U, 33U, 47U, 49U, 63U,
                 2U,  8U, 18U, 24U,  1U, 15U, 17U, 31U,
                34U, 40U, 50U, 56U, 35U, 41U, 51U, 57U,
                 4U, 10U, 20U, 26U,  3U,  9U, 19U, 25U,
                36U, 42U, 52U, 58U, 37U, 43U, 53U, 59U
    );
}

Recipe8x8 RecipeFactory8x8::BrassC() {
    //  AA AB AC AD AE AF AG AH      EE AE EC AC EA AA EG AG
    //  BA BB BC BD BE BF BG BH  ->  FC BC FA BA FG BG FE BE
    //  CA CB CC CD CE CF CG CH      GE CE GC CC GA CA GG CG
    //  DA DB DC DD DE DF DG DH      HC DC HA DA HG DG HE DE
    //  EA EB EC ED EE EF EG EH      EF AD ED AB EB AH EH AF
    //  FA FB FC FD FE FF FG FH      FD BB FB BH FH BF FF BD
    //  GA GB GC GD GE GF GG GH      GF CD GD CB GB CH GH CF
    //  HA HB HC HD HE HF HG HH      HD DB HB DH HH DF HF DD
    return Make("BrassC",
                36U,  4U, 34U,  2U, 32U,  0U, 38U,  6U,
                42U, 10U, 40U,  8U, 46U, 14U, 44U, 12U,
                52U, 20U, 50U, 18U, 48U, 16U, 54U, 22U,
                58U, 26U, 56U, 24U, 62U, 30U, 60U, 28U,
                37U,  3U, 35U,  1U, 33U,  7U, 39U,  5U,
                43U,  9U, 41U, 15U, 47U, 13U, 45U, 11U,
                53U, 19U, 51U, 17U, 49U, 23U, 55U, 21U,
                59U, 25U, 57U, 31U, 63U, 29U, 61U, 27U
    );
}

Recipe8x8 RecipeFactory8x8::BrassD() {
    //  AA AB AC AD AE AF AG AH      HD GF FD EF HC GE FC EE
    //  BA BB BC BD BE BF BG BH  ->  DB CD BB AD DC CE BC AE
    //  CA CB CC CD CE CF CG CH      HB GD FB ED HA GC FA EC
    //  DA DB DC DD DE DF DG DH      DH CB BH AB DA CC BA AC
    //  EA EB EC ED EE EF EG EH      HH GB FH EB HG GA FG EA
    //  FA FB FC FD FE FF FG FH      DF CH BF AH DG CA BG AA
    //  GA GB GC GD GE GF GG GH      HF GH FF EH HE GG FE EG
    //  HA HB HC HD HE HF HG HH      DD CF BD AF DE CG BE AG
    return Make("BrassD",
                59U, 53U, 43U, 37U, 58U, 52U, 42U, 36U,
                25U, 19U,  9U,  3U, 26U, 20U, 10U,  4U,
                57U, 51U, 41U, 35U, 56U, 50U, 40U, 34U,
                31U, 17U, 15U,  1U, 24U, 18U,  8U,  2U,
                63U, 49U, 47U, 33U, 62U, 48U, 46U, 32U,
                29U, 23U, 13U,  7U, 30U, 16U, 14U,  0U,
                61U, 55U, 45U, 39U, 60U, 54U, 44U, 38U,
                27U, 21U, 11U,  5U, 28U, 22U, 12U,  6U
    );
}

Recipe8x8 RecipeFactory8x8::NickelA() {
    //  AA AB AC AD AE AF AG AH      BH FB BB FD BD FF BF FH
    //  BA BB BC BD BE BF BG BH  ->  AH EB AB ED AD EF AF EH
    //  CA CB CC CD CE CF CG CH      HH DB HB DD HD DF HF DH
    //  DA DB DC DD DE DF DG DH      GH CB GB CD GD CF GF CH
    //  EA EB EC ED EE EF EG EH      HA DA HC DC HE DE HG DG
    //  FA FB FC FD FE FF FG FH      GA CA GC CC GE CE GG CG
    //  GA GB GC GD GE GF GG GH      FA BA FC BC FE BE FG BG
    //  HA HB HC HD HE HF HG HH      EA AA EC AC EE AE EG AG
    return Make("NickelA",
                15U, 41U,  9U, 43U, 11U, 45U, 13U, 47U,
                 7U, 33U,  1U, 35U,  3U, 37U,  5U, 39U,
                63U, 25U, 57U, 27U, 59U, 29U, 61U, 31U,
                55U, 17U, 49U, 19U, 51U, 21U, 53U, 23U,
                56U, 24U, 58U, 26U, 60U, 28U, 62U, 30U,
                48U, 16U, 50U, 18U, 52U, 20U, 54U, 22U,
                40U,  8U, 42U, 10U, 44U, 12U, 46U, 14U,
                32U,  0U, 34U,  2U, 36U,  4U, 38U,  6U
    );
}

Recipe8x8 RecipeFactory8x8::NickelB() {
    //  AA AB AC AD AE AF AG AH      EA FA GA HA GH HH AH BH
    //  BA BB BC BD BE BF BG BH  ->  AA BA CA DA CB DB EB FB
    //  CA CB CC CD CE CF CG CH      EC FC GC HC GB HB AB BB
    //  DA DB DC DD DE DF DG DH      AC BC CC DC CD DD ED FD
    //  EA EB EC ED EE EF EG EH      EE FE GE HE GD HD AD BD
    //  FA FB FC FD FE FF FG FH      AE BE CE DE CF DF EF FF
    //  GA GB GC GD GE GF GG GH      EG FG GG HG GF HF AF BF
    //  HA HB HC HD HE HF HG HH      AG BG CG DG CH DH EH FH
    return Make("NickelB",
                32U, 40U, 48U, 56U, 55U, 63U,  7U, 15U,
                 0U,  8U, 16U, 24U, 17U, 25U, 33U, 41U,
                34U, 42U, 50U, 58U, 49U, 57U,  1U,  9U,
                 2U, 10U, 18U, 26U, 19U, 27U, 35U, 43U,
                36U, 44U, 52U, 60U, 51U, 59U,  3U, 11U,
                 4U, 12U, 20U, 28U, 21U, 29U, 37U, 45U,
                38U, 46U, 54U, 62U, 53U, 61U,  5U, 13U,
                 6U, 14U, 22U, 30U, 23U, 31U, 39U, 47U
    );
}

Recipe8x8 RecipeFactory8x8::NickelC() {
    //  AA AB AC AD AE AF AG AH      AG EG AE EE AC EC AA EA
    //  BA BB BC BD BE BF BG BH  ->  BG FG BE FE BC FC BA FA
    //  CA CB CC CD CE CF CG CH      CG GG CE GE CC GC CA GA
    //  DA DB DC DD DE DF DG DH      DG HG DE HE DC HC DA HA
    //  EA EB EC ED EE EF EG EH      CH GF CF GD CD GB CB GH
    //  FA FB FC FD FE FF FG FH      DH HF DF HD DD HB DB HH
    //  GA GB GC GD GE GF GG GH      EH AF EF AD ED AB EB AH
    //  HA HB HC HD HE HF HG HH      FH BF FF BD FD BB FB BH
    return Make("NickelC",
                 6U, 38U,  4U, 36U,  2U, 34U,  0U, 32U,
                14U, 46U, 12U, 44U, 10U, 42U,  8U, 40U,
                22U, 54U, 20U, 52U, 18U, 50U, 16U, 48U,
                30U, 62U, 28U, 60U, 26U, 58U, 24U, 56U,
                23U, 53U, 21U, 51U, 19U, 49U, 17U, 55U,
                31U, 61U, 29U, 59U, 27U, 57U, 25U, 63U,
                39U,  5U, 37U,  3U, 35U,  1U, 33U,  7U,
                47U, 13U, 45U, 11U, 43U,  9U, 41U, 15U
    );
}

Recipe8x8 RecipeFactory8x8::NickelD() {
    //  AA AB AC AD AE AF AG AH      FH EH DH CH DG CG BG AG
    //  BA BB BC BD BE BF BG BH  ->  BF AF HF GF HG GG FG EG
    //  CA CB CC CD CE CF CG CH      FF EF DF CF DE CE BE AE
    //  DA DB DC DD DE DF DG DH      BD AD HD GD HE GE FE EE
    //  EA EB EC ED EE EF EG EH      FD ED DD CD DC CC BC AC
    //  FA FB FC FD FE FF FG FH      BB AB HB GB HC GC FC EC
    //  GA GB GC GD GE GF GG GH      FB EB DB CB DA CA BA AA
    //  HA HB HC HD HE HF HG HH      BH AH HH GH HA GA FA EA
    return Make("NickelD",
                47U, 39U, 31U, 23U, 30U, 22U, 14U,  6U,
                13U,  5U, 61U, 53U, 62U, 54U, 46U, 38U,
                45U, 37U, 29U, 21U, 28U, 20U, 12U,  4U,
                11U,  3U, 59U, 51U, 60U, 52U, 44U, 36U,
                43U, 35U, 27U, 19U, 26U, 18U, 10U,  2U,
                 9U,  1U, 57U, 49U, 58U, 50U, 42U, 34U,
                41U, 33U, 25U, 17U, 24U, 16U,  8U,  0U,
                15U,  7U, 63U, 55U, 56U, 48U, 40U, 32U
    );
}

Recipe8x8 RecipeFactory8x8::CobaltA() {
    //  AA AB AC AD AE AF AG AH      HH DB HB DD HD DF HF DH
    //  BA BB BC BD BE BF BG BH  ->  GH CB GB CD GD CF GF CH
    //  CA CB CC CD CE CF CG CH      FH BB FB BD FD BF FF BH
    //  DA DB DC DD DE DF DG DH      EH AB EB AD ED AF EF AH
    //  EA EB EC ED EE EF EG EH      BA FA BC FC BE FE BG FG
    //  FA FB FC FD FE FF FG FH      AA EA AC EC AE EE AG EG
    //  GA GB GC GD GE GF GG GH      HA DA HC DC HE DE HG DG
    //  HA HB HC HD HE HF HG HH      GA CA GC CC GE CE GG CG
    return Make("CobaltA",
                63U, 25U, 57U, 27U, 59U, 29U, 61U, 31U,
                55U, 17U, 49U, 19U, 51U, 21U, 53U, 23U,
                47U,  9U, 41U, 11U, 43U, 13U, 45U, 15U,
                39U,  1U, 33U,  3U, 35U,  5U, 37U,  7U,
                 8U, 40U, 10U, 42U, 12U, 44U, 14U, 46U,
                 0U, 32U,  2U, 34U,  4U, 36U,  6U, 38U,
                56U, 24U, 58U, 26U, 60U, 28U, 62U, 30U,
                48U, 16U, 50U, 18U, 52U, 20U, 54U, 22U
    );
}

Recipe8x8 RecipeFactory8x8::CobaltB() {
    //  AA AB AC AD AE AF AG AH      GA HA AA BA EH FH GH HH
    //  BA BB BC BD BE BF BG BH  ->  CA DA EA FA AB BB CB DB
    //  CA CB CC CD CE CF CG CH      GC HC AC BC EB FB GB HB
    //  DA DB DC DD DE DF DG DH      CC DC EC FC AD BD CD DD
    //  EA EB EC ED EE EF EG EH      GE HE AE BE ED FD GD HD
    //  FA FB FC FD FE FF FG FH      CE DE EE FE AF BF CF DF
    //  GA GB GC GD GE GF GG GH      GG HG AG BG EF FF GF HF
    //  HA HB HC HD HE HF HG HH      CG DG EG FG AH BH CH DH
    return Make("CobaltB",
                48U, 56U,  0U,  8U, 39U, 47U, 55U, 63U,
                16U, 24U, 32U, 40U,  1U,  9U, 17U, 25U,
                50U, 58U,  2U, 10U, 33U, 41U, 49U, 57U,
                18U, 26U, 34U, 42U,  3U, 11U, 19U, 27U,
                52U, 60U,  4U, 12U, 35U, 43U, 51U, 59U,
                20U, 28U, 36U, 44U,  5U, 13U, 21U, 29U,
                54U, 62U,  6U, 14U, 37U, 45U, 53U, 61U,
                22U, 30U, 38U, 46U,  7U, 15U, 23U, 31U
    );
}

Recipe8x8 RecipeFactory8x8::CobaltC() {
    //  AA AB AC AD AE AF AG AH      CG GG CE GE CC GC CA GA
    //  BA BB BC BD BE BF BG BH  ->  DG HG DE HE DC HC DA HA
    //  CA CB CC CD CE CF CG CH      EG AG EE AE EC AC EA AA
    //  DA DB DC DD DE DF DG DH      FG BG FE BE FC BC FA BA
    //  EA EB EC ED EE EF EG EH      AH EF AF ED AD EB AB EH
    //  FA FB FC FD FE FF FG FH      BH FF BF FD BD FB BB FH
    //  GA GB GC GD GE GF GG GH      CH GF CF GD CD GB CB GH
    //  HA HB HC HD HE HF HG HH      DH HF DF HD DD HB DB HH
    return Make("CobaltC",
                22U, 54U, 20U, 52U, 18U, 50U, 16U, 48U,
                30U, 62U, 28U, 60U, 26U, 58U, 24U, 56U,
                38U,  6U, 36U,  4U, 34U,  2U, 32U,  0U,
                46U, 14U, 44U, 12U, 42U, 10U, 40U,  8U,
                 7U, 37U,  5U, 35U,  3U, 33U,  1U, 39U,
                15U, 45U, 13U, 43U, 11U, 41U,  9U, 47U,
                23U, 53U, 21U, 51U, 19U, 49U, 17U, 55U,
                31U, 61U, 29U, 59U, 27U, 57U, 25U, 63U
    );
}

Recipe8x8 RecipeFactory8x8::CobaltD() {
    //  AA AB AC AD AE AF AG AH      DH CH BH AH FG EG DG CG
    //  BA BB BC BD BE BF BG BH  ->  HF GF FF EF BG AG HG GG
    //  CA CB CC CD CE CF CG CH      DF CF BF AF FE EE DE CE
    //  DA DB DC DD DE DF DG DH      HD GD FD ED BE AE HE GE
    //  EA EB EC ED EE EF EG EH      DD CD BD AD FC EC DC CC
    //  FA FB FC FD FE FF FG FH      HB GB FB EB BC AC HC GC
    //  GA GB GC GD GE GF GG GH      DB CB BB AB FA EA DA CA
    //  HA HB HC HD HE HF HG HH      HH GH FH EH BA AA HA GA
    return Make("CobaltD",
                31U, 23U, 15U,  7U, 46U, 38U, 30U, 22U,
                61U, 53U, 45U, 37U, 14U,  6U, 62U, 54U,
                29U, 21U, 13U,  5U, 44U, 36U, 28U, 20U,
                59U, 51U, 43U, 35U, 12U,  4U, 60U, 52U,
                27U, 19U, 11U,  3U, 42U, 34U, 26U, 18U,
                57U, 49U, 41U, 33U, 10U,  2U, 58U, 50U,
                25U, 17U,  9U,  1U, 40U, 32U, 24U, 16U,
                63U, 55U, 47U, 39U,  8U,  0U, 56U, 48U
    );
}

Recipe8x8 RecipeFactory8x8::TitaniumA() {
    //  AA AB AC AD AE AF AG AH      AD ED AB EB AH EH AF EF
    //  BA BB BC BD BE BF BG BH  ->  BF FF BD FD BB FB BH FH
    //  CA CB CC CD CE CF CG CH      CD GD CB GB CH GH CF GF
    //  DA DB DC DD DE DF DG DH      DF HF DD HD DB HB DH HH
    //  EA EB EC ED EE EF EG EH      AC EC AA EA AG EG AE EE
    //  FA FB FC FD FE FF FG FH      BE FE BC FC BA FA BG FG
    //  GA GB GC GD GE GF GG GH      CC GC CA GA CG GG CE GE
    //  HA HB HC HD HE HF HG HH      DE HE DC HC DA HA DG HG
    return Make("TitaniumA",
                 3U, 35U,  1U, 33U,  7U, 39U,  5U, 37U,
                13U, 45U, 11U, 43U,  9U, 41U, 15U, 47U,
                19U, 51U, 17U, 49U, 23U, 55U, 21U, 53U,
                29U, 61U, 27U, 59U, 25U, 57U, 31U, 63U,
                 2U, 34U,  0U, 32U,  6U, 38U,  4U, 36U,
                12U, 44U, 10U, 42U,  8U, 40U, 14U, 46U,
                18U, 50U, 16U, 48U, 22U, 54U, 20U, 52U,
                28U, 60U, 26U, 58U, 24U, 56U, 30U, 62U
    );
}

Recipe8x8 RecipeFactory8x8::TitaniumB() {
    //  AA AB AC AD AE AF AG AH      DE CC BE AC DF CD BF AD
    //  BA BB BC BD BE BF BG BH  ->  HE GC FE EC HF GD FF ED
    //  CA CB CC CD CE CF CG CH      DC CA BC AA DD CB BD AB
    //  DA DB DC DD DE DF DG DH      HC GA FC EA HD GB FD EB
    //  EA EB EC ED EE EF EG EH      DA CG BA AG DB CH BB AH
    //  FA FB FC FD FE FF FG FH      HA GG FA EG HB GH FB EH
    //  GA GB GC GD GE GF GG GH      DG CE BG AE DH CF BH AF
    //  HA HB HC HD HE HF HG HH      HG GE FG EE HH GF FH EF
    return Make("TitaniumB",
                28U, 18U, 12U,  2U, 29U, 19U, 13U,  3U,
                60U, 50U, 44U, 34U, 61U, 51U, 45U, 35U,
                26U, 16U, 10U,  0U, 27U, 17U, 11U,  1U,
                58U, 48U, 42U, 32U, 59U, 49U, 43U, 33U,
                24U, 22U,  8U,  6U, 25U, 23U,  9U,  7U,
                56U, 54U, 40U, 38U, 57U, 55U, 41U, 39U,
                30U, 20U, 14U,  4U, 31U, 21U, 15U,  5U,
                62U, 52U, 46U, 36U, 63U, 53U, 47U, 37U
    );
}

Recipe8x8 RecipeFactory8x8::TitaniumC() {
    //  AA AB AC AD AE AF AG AH      HG DG HA DA HC DC HE DE
    //  BA BB BC BD BE BF BG BH  ->  GE CE GG CG GA CA GC CC
    //  CA CB CC CD CE CF CG CH      FG BG FA BA FC BC FE BE
    //  DA DB DC DD DE DF DG DH      EE AE EG AG EA AA EC AC
    //  EA EB EC ED EE EF EG EH      HH DH HB DB HD DD HF DF
    //  FA FB FC FD FE FF FG FH      GF CF GH CH GB CB GD CD
    //  GA GB GC GD GE GF GG GH      FH BH FB BB FD BD FF BF
    //  HA HB HC HD HE HF HG HH      EF AF EH AH EB AB ED AD
    return Make("TitaniumC",
                62U, 30U, 56U, 24U, 58U, 26U, 60U, 28U,
                52U, 20U, 54U, 22U, 48U, 16U, 50U, 18U,
                46U, 14U, 40U,  8U, 42U, 10U, 44U, 12U,
                36U,  4U, 38U,  6U, 32U,  0U, 34U,  2U,
                63U, 31U, 57U, 25U, 59U, 27U, 61U, 29U,
                53U, 21U, 55U, 23U, 49U, 17U, 51U, 19U,
                47U, 15U, 41U,  9U, 43U, 11U, 45U, 13U,
                37U,  5U, 39U,  7U, 33U,  1U, 35U,  3U
    );
}

Recipe8x8 RecipeFactory8x8::TitaniumD() {
    //  AA AB AC AD AE AF AG AH      EF FH GF HH EE FG GE HG
    //  BA BB BC BD BE BF BG BH  ->  AF BH CF DH AE BG CE DG
    //  CA CB CC CD CE CF CG CH      EH FB GH HB EG FA GG HA
    //  DA DB DC DD DE DF DG DH      AH BB CH DB AG BA CG DA
    //  EA EB EC ED EE EF EG EH      EB FD GB HD EA FC GA HC
    //  FA FB FC FD FE FF FG FH      AB BD CB DD AA BC CA DC
    //  GA GB GC GD GE GF GG GH      ED FF GD HF EC FE GC HE
    //  HA HB HC HD HE HF HG HH      AD BF CD DF AC BE CC DE
    return Make("TitaniumD",
                37U, 47U, 53U, 63U, 36U, 46U, 52U, 62U,
                 5U, 15U, 21U, 31U,  4U, 14U, 20U, 30U,
                39U, 41U, 55U, 57U, 38U, 40U, 54U, 56U,
                 7U,  9U, 23U, 25U,  6U,  8U, 22U, 24U,
                33U, 43U, 49U, 59U, 32U, 42U, 48U, 58U,
                 1U, 11U, 17U, 27U,  0U, 10U, 16U, 26U,
                35U, 45U, 51U, 61U, 34U, 44U, 50U, 60U,
                 3U, 13U, 19U, 29U,  2U, 12U, 18U, 28U
    );
}

Recipe8x8 RecipeFactory8x8::PlatinumA() {
    //  AA AB AC AD AE AF AG AH      AF EF AD ED AB EB AH EH
    //  BA BB BC BD BE BF BG BH  ->  BD FD BB FB BH FH BF FF
    //  CA CB CC CD CE CF CG CH      CF GF CD GD CB GB CH GH
    //  DA DB DC DD DE DF DG DH      DD HD DB HB DH HH DF HF
    //  EA EB EC ED EE EF EG EH      AE EE AC EC AA EA AG EG
    //  FA FB FC FD FE FF FG FH      BC FC BA FA BG FG BE FE
    //  GA GB GC GD GE GF GG GH      CE GE CC GC CA GA CG GG
    //  HA HB HC HD HE HF HG HH      DC HC DA HA DG HG DE HE
    return Make("PlatinumA",
                 5U, 37U,  3U, 35U,  1U, 33U,  7U, 39U,
                11U, 43U,  9U, 41U, 15U, 47U, 13U, 45U,
                21U, 53U, 19U, 51U, 17U, 49U, 23U, 55U,
                27U, 59U, 25U, 57U, 31U, 63U, 29U, 61U,
                 4U, 36U,  2U, 34U,  0U, 32U,  6U, 38U,
                10U, 42U,  8U, 40U, 14U, 46U, 12U, 44U,
                20U, 52U, 18U, 50U, 16U, 48U, 22U, 54U,
                26U, 58U, 24U, 56U, 30U, 62U, 28U, 60U
    );
}

Recipe8x8 RecipeFactory8x8::PlatinumB() {
    //  AA AB AC AD AE AF AG AH      DC CE BC AE DD CF BD AF
    //  BA BB BC BD BE BF BG BH  ->  HC GE FC EE HD GF FD EF
    //  CA CB CC CD CE CF CG CH      DA CC BA AC DB CD BB AD
    //  DA DB DC DD DE DF DG DH      HA GC FA EC HB GD FB ED
    //  EA EB EC ED EE EF EG EH      DG CA BG AA DH CB BH AB
    //  FA FB FC FD FE FF FG FH      HG GA FG EA HH GB FH EB
    //  GA GB GC GD GE GF GG GH      DE CG BE AG DF CH BF AH
    //  HA HB HC HD HE HF HG HH      HE GG FE EG HF GH FF EH
    return Make("PlatinumB",
                26U, 20U, 10U,  4U, 27U, 21U, 11U,  5U,
                58U, 52U, 42U, 36U, 59U, 53U, 43U, 37U,
                24U, 18U,  8U,  2U, 25U, 19U,  9U,  3U,
                56U, 50U, 40U, 34U, 57U, 51U, 41U, 35U,
                30U, 16U, 14U,  0U, 31U, 17U, 15U,  1U,
                62U, 48U, 46U, 32U, 63U, 49U, 47U, 33U,
                28U, 22U, 12U,  6U, 29U, 23U, 13U,  7U,
                60U, 54U, 44U, 38U, 61U, 55U, 45U, 39U
    );
}

Recipe8x8 RecipeFactory8x8::PlatinumC() {
    //  AA AB AC AD AE AF AG AH      HE DE HG DG HA DA HC DC
    //  BA BB BC BD BE BF BG BH  ->  GG CG GA CA GC CC GE CE
    //  CA CB CC CD CE CF CG CH      FE BE FG BG FA BA FC BC
    //  DA DB DC DD DE DF DG DH      EG AG EA AA EC AC EE AE
    //  EA EB EC ED EE EF EG EH      HF DF HH DH HB DB HD DD
    //  FA FB FC FD FE FF FG FH      GH CH GB CB GD CD GF CF
    //  GA GB GC GD GE GF GG GH      FF BF FH BH FB BB FD BD
    //  HA HB HC HD HE HF HG HH      EH AH EB AB ED AD EF AF
    return Make("PlatinumC",
                60U, 28U, 62U, 30U, 56U, 24U, 58U, 26U,
                54U, 22U, 48U, 16U, 50U, 18U, 52U, 20U,
                44U, 12U, 46U, 14U, 40U,  8U, 42U, 10U,
                38U,  6U, 32U,  0U, 34U,  2U, 36U,  4U,
                61U, 29U, 63U, 31U, 57U, 25U, 59U, 27U,
                55U, 23U, 49U, 17U, 51U, 19U, 53U, 21U,
                45U, 13U, 47U, 15U, 41U,  9U, 43U, 11U,
                39U,  7U, 33U,  1U, 35U,  3U, 37U,  5U
    );
}

Recipe8x8 RecipeFactory8x8::PlatinumD() {
    //  AA AB AC AD AE AF AG AH      EH FF GH HF EG FE GG HE
    //  BA BB BC BD BE BF BG BH  ->  AH BF CH DF AG BE CG DE
    //  CA CB CC CD CE CF CG CH      EB FH GB HH EA FG GA HG
    //  DA DB DC DD DE DF DG DH      AB BH CB DH AA BG CA DG
    //  EA EB EC ED EE EF EG EH      ED FB GD HB EC FA GC HA
    //  FA FB FC FD FE FF FG FH      AD BB CD DB AC BA CC DA
    //  GA GB GC GD GE GF GG GH      EF FD GF HD EE FC GE HC
    //  HA HB HC HD HE HF HG HH      AF BD CF DD AE BC CE DC
    return Make("PlatinumD",
                39U, 45U, 55U, 61U, 38U, 44U, 54U, 60U,
                 7U, 13U, 23U, 29U,  6U, 12U, 22U, 28U,
                33U, 47U, 49U, 63U, 32U, 46U, 48U, 62U,
                 1U, 15U, 17U, 31U,  0U, 14U, 16U, 30U,
                35U, 41U, 51U, 57U, 34U, 40U, 50U, 56U,
                 3U,  9U, 19U, 25U,  2U,  8U, 18U, 24U,
                37U, 43U, 53U, 59U, 36U, 42U, 52U, 58U,
                 5U, 11U, 21U, 27U,  4U, 10U, 20U, 26U
    );
}

Recipe8x8 RecipeFactory8x8::TungstenA() {
    //  AA AB AC AD AE AF AG AH      GH CH GF CF GD CD GB CB
    //  BA BB BC BD BE BF BG BH  ->  HH DH HF DF HD DD HB DB
    //  CA CB CC CD CE CF CG CH      AH EH AF EF AD ED AB EB
    //  DA DB DC DD DE DF DG DH      BH FH BF FF BD FD BB FB
    //  EA EB EC ED EE EF EG EH      EG AG EE AE EC AC EA AA
    //  FA FB FC FD FE FF FG FH      FG BG FE BE FC BC FA BA
    //  GA GB GC GD GE GF GG GH      GG CG GE CE GC CC GA CA
    //  HA HB HC HD HE HF HG HH      HG DG HE DE HC DC HA DA
    return Make("TungstenA",
                55U, 23U, 53U, 21U, 51U, 19U, 49U, 17U,
                63U, 31U, 61U, 29U, 59U, 27U, 57U, 25U,
                 7U, 39U,  5U, 37U,  3U, 35U,  1U, 33U,
                15U, 47U, 13U, 45U, 11U, 43U,  9U, 41U,
                38U,  6U, 36U,  4U, 34U,  2U, 32U,  0U,
                46U, 14U, 44U, 12U, 42U, 10U, 40U,  8U,
                54U, 22U, 52U, 20U, 50U, 18U, 48U, 16U,
                62U, 30U, 60U, 28U, 58U, 26U, 56U, 24U
    );
}

Recipe8x8 RecipeFactory8x8::TungstenB() {
    //  AA AB AC AD AE AF AG AH      HG GG FG EG BH AH HH GH
    //  BA BB BC BD BE BF BG BH  ->  DG CG BG AG FH EH DH CH
    //  CA CB CC CD CE CF CG CH      HE GE FE EE BF AF HF GF
    //  DA DB DC DD DE DF DG DH      DE CE BE AE FF EF DF CF
    //  EA EB EC ED EE EF EG EH      HC GC FC EC BD AD HD GD
    //  FA FB FC FD FE FF FG FH      DC CC BC AC FD ED DD CD
    //  GA GB GC GD GE GF GG GH      HA GA FA EA BB AB HB GB
    //  HA HB HC HD HE HF HG HH      DA CA BA AA FB EB DB CB
    return Make("TungstenB",
                62U, 54U, 46U, 38U, 15U,  7U, 63U, 55U,
                30U, 22U, 14U,  6U, 47U, 39U, 31U, 23U,
                60U, 52U, 44U, 36U, 13U,  5U, 61U, 53U,
                28U, 20U, 12U,  4U, 45U, 37U, 29U, 21U,
                58U, 50U, 42U, 34U, 11U,  3U, 59U, 51U,
                26U, 18U, 10U,  2U, 43U, 35U, 27U, 19U,
                56U, 48U, 40U, 32U,  9U,  1U, 57U, 49U,
                24U, 16U,  8U,  0U, 41U, 33U, 25U, 17U
    );
}

Recipe8x8 RecipeFactory8x8::TungstenC() {
    //  AA AB AC AD AE AF AG AH      DA HA DC HC DE HE DG HG
    //  BA BB BC BD BE BF BG BH  ->  CA GA CC GC CE GE CG GG
    //  CA CB CC CD CE CF CG CH      BA FA BC FC BE FE BG FG
    //  DA DB DC DD DE DF DG DH      AA EA AC EC AE EE AG EG
    //  EA EB EC ED EE EF EG EH      FB BB FD BD FF BF FH BH
    //  FA FB FC FD FE FF FG FH      EB AB ED AD EF AF EH AH
    //  GA GB GC GD GE GF GG GH      DB HB DD HD DF HF DH HH
    //  HA HB HC HD HE HF HG HH      CB GB CD GD CF GF CH GH
    return Make("TungstenC",
                24U, 56U, 26U, 58U, 28U, 60U, 30U, 62U,
                16U, 48U, 18U, 50U, 20U, 52U, 22U, 54U,
                 8U, 40U, 10U, 42U, 12U, 44U, 14U, 46U,
                 0U, 32U,  2U, 34U,  4U, 36U,  6U, 38U,
                41U,  9U, 43U, 11U, 45U, 13U, 47U, 15U,
                33U,  1U, 35U,  3U, 37U,  5U, 39U,  7U,
                25U, 57U, 27U, 59U, 29U, 61U, 31U, 63U,
                17U, 49U, 19U, 51U, 21U, 53U, 23U, 55U
    );
}

Recipe8x8 RecipeFactory8x8::TungstenD() {
    //  AA AB AC AD AE AF AG AH      CB DB EB FB AA BA CA DA
    //  BA BB BC BD BE BF BG BH  ->  GB HB AB BB EA FA GA HA
    //  CA CB CC CD CE CF CG CH      CD DD ED FD AC BC CC DC
    //  DA DB DC DD DE DF DG DH      GD HD AD BD EC FC GC HC
    //  EA EB EC ED EE EF EG EH      CF DF EF FF AE BE CE DE
    //  FA FB FC FD FE FF FG FH      GF HF AF BF EE FE GE HE
    //  GA GB GC GD GE GF GG GH      CH DH EH FH AG BG CG DG
    //  HA HB HC HD HE HF HG HH      GH HH AH BH EG FG GG HG
    return Make("TungstenD",
                17U, 25U, 33U, 41U,  0U,  8U, 16U, 24U,
                49U, 57U,  1U,  9U, 32U, 40U, 48U, 56U,
                19U, 27U, 35U, 43U,  2U, 10U, 18U, 26U,
                51U, 59U,  3U, 11U, 34U, 42U, 50U, 58U,
                21U, 29U, 37U, 45U,  4U, 12U, 20U, 28U,
                53U, 61U,  5U, 13U, 36U, 44U, 52U, 60U,
                23U, 31U, 39U, 47U,  6U, 14U, 22U, 30U,
                55U, 63U,  7U, 15U, 38U, 46U, 54U, 62U
    );
}

Recipe8x8 RecipeFactory8x8::MercuryA() {
    //  AA AB AC AD AE AF AG AH      EH AH EF AF ED AD EB AB
    //  BA BB BC BD BE BF BG BH  ->  FH BH FF BF FD BD FB BB
    //  CA CB CC CD CE CF CG CH      GH CH GF CF GD CD GB CB
    //  DA DB DC DD DE DF DG DH      HH DH HF DF HD DD HB DB
    //  EA EB EC ED EE EF EG EH      GG CG GE CE GC CC GA CA
    //  FA FB FC FD FE FF FG FH      HG DG HE DE HC DC HA DA
    //  GA GB GC GD GE GF GG GH      AG EG AE EE AC EC AA EA
    //  HA HB HC HD HE HF HG HH      BG FG BE FE BC FC BA FA
    return Make("MercuryA",
                39U,  7U, 37U,  5U, 35U,  3U, 33U,  1U,
                47U, 15U, 45U, 13U, 43U, 11U, 41U,  9U,
                55U, 23U, 53U, 21U, 51U, 19U, 49U, 17U,
                63U, 31U, 61U, 29U, 59U, 27U, 57U, 25U,
                54U, 22U, 52U, 20U, 50U, 18U, 48U, 16U,
                62U, 30U, 60U, 28U, 58U, 26U, 56U, 24U,
                 6U, 38U,  4U, 36U,  2U, 34U,  0U, 32U,
                14U, 46U, 12U, 44U, 10U, 42U,  8U, 40U
    );
}

Recipe8x8 RecipeFactory8x8::MercuryB() {
    //  AA AB AC AD AE AF AG AH      BG AG HG GG HH GH FH EH
    //  BA BB BC BD BE BF BG BH  ->  FG EG DG CG DH CH BH AH
    //  CA CB CC CD CE CF CG CH      BE AE HE GE HF GF FF EF
    //  DA DB DC DD DE DF DG DH      FE EE DE CE DF CF BF AF
    //  EA EB EC ED EE EF EG EH      BC AC HC GC HD GD FD ED
    //  FA FB FC FD FE FF FG FH      FC EC DC CC DD CD BD AD
    //  GA GB GC GD GE GF GG GH      BA AA HA GA HB GB FB EB
    //  HA HB HC HD HE HF HG HH      FA EA DA CA DB CB BB AB
    return Make("MercuryB",
                14U,  6U, 62U, 54U, 63U, 55U, 47U, 39U,
                46U, 38U, 30U, 22U, 31U, 23U, 15U,  7U,
                12U,  4U, 60U, 52U, 61U, 53U, 45U, 37U,
                44U, 36U, 28U, 20U, 29U, 21U, 13U,  5U,
                10U,  2U, 58U, 50U, 59U, 51U, 43U, 35U,
                42U, 34U, 26U, 18U, 27U, 19U, 11U,  3U,
                 8U,  0U, 56U, 48U, 57U, 49U, 41U, 33U,
                40U, 32U, 24U, 16U, 25U, 17U,  9U,  1U
    );
}

Recipe8x8 RecipeFactory8x8::MercuryC() {
    //  AA AB AC AD AE AF AG AH      FA BA FC BC FE BE FG BG
    //  BA BB BC BD BE BF BG BH  ->  EA AA EC AC EE AE EG AG
    //  CA CB CC CD CE CF CG CH      DA HA DC HC DE HE DG HG
    //  DA DB DC DD DE DF DG DH      CA GA CC GC CE GE CG GG
    //  EA EB EC ED EE EF EG EH      DB HB DD HD DF HF DH HH
    //  FA FB FC FD FE FF FG FH      CB GB CD GD CF GF CH GH
    //  GA GB GC GD GE GF GG GH      BB FB BD FD BF FF BH FH
    //  HA HB HC HD HE HF HG HH      AB EB AD ED AF EF AH EH
    return Make("MercuryC",
                40U,  8U, 42U, 10U, 44U, 12U, 46U, 14U,
                32U,  0U, 34U,  2U, 36U,  4U, 38U,  6U,
                24U, 56U, 26U, 58U, 28U, 60U, 30U, 62U,
                16U, 48U, 18U, 50U, 20U, 52U, 22U, 54U,
                25U, 57U, 27U, 59U, 29U, 61U, 31U, 63U,
                17U, 49U, 19U, 51U, 21U, 53U, 23U, 55U,
                 9U, 41U, 11U, 43U, 13U, 45U, 15U, 47U,
                 1U, 33U,  3U, 35U,  5U, 37U,  7U, 39U
    );
}

Recipe8x8 RecipeFactory8x8::MercuryD() {
    //  AA AB AC AD AE AF AG AH      AB BB CB DB CA DA EA FA
    //  BA BB BC BD BE BF BG BH  ->  EB FB GB HB GA HA AA BA
    //  CA CB CC CD CE CF CG CH      AD BD CD DD CC DC EC FC
    //  DA DB DC DD DE DF DG DH      ED FD GD HD GC HC AC BC
    //  EA EB EC ED EE EF EG EH      AF BF CF DF CE DE EE FE
    //  FA FB FC FD FE FF FG FH      EF FF GF HF GE HE AE BE
    //  GA GB GC GD GE GF GG GH      AH BH CH DH CG DG EG FG
    //  HA HB HC HD HE HF HG HH      EH FH GH HH GG HG AG BG
    return Make("MercuryD",
                 1U,  9U, 17U, 25U, 16U, 24U, 32U, 40U,
                33U, 41U, 49U, 57U, 48U, 56U,  0U,  8U,
                 3U, 11U, 19U, 27U, 18U, 26U, 34U, 42U,
                35U, 43U, 51U, 59U, 50U, 58U,  2U, 10U,
                 5U, 13U, 21U, 29U, 20U, 28U, 36U, 44U,
                37U, 45U, 53U, 61U, 52U, 60U,  4U, 12U,
                 7U, 15U, 23U, 31U, 22U, 30U, 38U, 46U,
                39U, 47U, 55U, 63U, 54U, 62U,  6U, 14U
    );
}

Recipe8x8 RecipeFactory8x8::PalladiumA() {
    //  AA AB AC AD AE AF AG AH      HG DG HA DA HC DC HE DE
    //  BA BB BC BD BE BF BG BH  ->  GE CE GG CG GA CA GC CC
    //  CA CB CC CD CE CF CG CH      FG BG FA BA FC BC FE BE
    //  DA DB DC DD DE DF DG DH      EE AE EG AG EA AA EC AC
    //  EA EB EC ED EE EF EG EH      HH DH HB DB HD DD HF DF
    //  FA FB FC FD FE FF FG FH      GF CF GH CH GB CB GD CD
    //  GA GB GC GD GE GF GG GH      FH BH FB BB FD BD FF BF
    //  HA HB HC HD HE HF HG HH      EF AF EH AH EB AB ED AD
    return Make("PalladiumA",
                62U, 30U, 56U, 24U, 58U, 26U, 60U, 28U,
                52U, 20U, 54U, 22U, 48U, 16U, 50U, 18U,
                46U, 14U, 40U,  8U, 42U, 10U, 44U, 12U,
                36U,  4U, 38U,  6U, 32U,  0U, 34U,  2U,
                63U, 31U, 57U, 25U, 59U, 27U, 61U, 29U,
                53U, 21U, 55U, 23U, 49U, 17U, 51U, 19U,
                47U, 15U, 41U,  9U, 43U, 11U, 45U, 13U,
                37U,  5U, 39U,  7U, 33U,  1U, 35U,  3U
    );
}

Recipe8x8 RecipeFactory8x8::PalladiumB() {
    //  AA AB AC AD AE AF AG AH      EF FH GF HH EE FG GE HG
    //  BA BB BC BD BE BF BG BH  ->  AF BH CF DH AE BG CE DG
    //  CA CB CC CD CE CF CG CH      EH FB GH HB EG FA GG HA
    //  DA DB DC DD DE DF DG DH      AH BB CH DB AG BA CG DA
    //  EA EB EC ED EE EF EG EH      EB FD GB HD EA FC GA HC
    //  FA FB FC FD FE FF FG FH      AB BD CB DD AA BC CA DC
    //  GA GB GC GD GE GF GG GH      ED FF GD HF EC FE GC HE
    //  HA HB HC HD HE HF HG HH      AD BF CD DF AC BE CC DE
    return Make("PalladiumB",
                37U, 47U, 53U, 63U, 36U, 46U, 52U, 62U,
                 5U, 15U, 21U, 31U,  4U, 14U, 20U, 30U,
                39U, 41U, 55U, 57U, 38U, 40U, 54U, 56U,
                 7U,  9U, 23U, 25U,  6U,  8U, 22U, 24U,
                33U, 43U, 49U, 59U, 32U, 42U, 48U, 58U,
                 1U, 11U, 17U, 27U,  0U, 10U, 16U, 26U,
                35U, 45U, 51U, 61U, 34U, 44U, 50U, 60U,
                 3U, 13U, 19U, 29U,  2U, 12U, 18U, 28U
    );
}

Recipe8x8 RecipeFactory8x8::PalladiumC() {
    //  AA AB AC AD AE AF AG AH      AD ED AB EB AH EH AF EF
    //  BA BB BC BD BE BF BG BH  ->  BF FF BD FD BB FB BH FH
    //  CA CB CC CD CE CF CG CH      CD GD CB GB CH GH CF GF
    //  DA DB DC DD DE DF DG DH      DF HF DD HD DB HB DH HH
    //  EA EB EC ED EE EF EG EH      AC EC AA EA AG EG AE EE
    //  FA FB FC FD FE FF FG FH      BE FE BC FC BA FA BG FG
    //  GA GB GC GD GE GF GG GH      CC GC CA GA CG GG CE GE
    //  HA HB HC HD HE HF HG HH      DE HE DC HC DA HA DG HG
    return Make("PalladiumC",
                 3U, 35U,  1U, 33U,  7U, 39U,  5U, 37U,
                13U, 45U, 11U, 43U,  9U, 41U, 15U, 47U,
                19U, 51U, 17U, 49U, 23U, 55U, 21U, 53U,
                29U, 61U, 27U, 59U, 25U, 57U, 31U, 63U,
                 2U, 34U,  0U, 32U,  6U, 38U,  4U, 36U,
                12U, 44U, 10U, 42U,  8U, 40U, 14U, 46U,
                18U, 50U, 16U, 48U, 22U, 54U, 20U, 52U,
                28U, 60U, 26U, 58U, 24U, 56U, 30U, 62U
    );
}

Recipe8x8 RecipeFactory8x8::PalladiumD() {
    //  AA AB AC AD AE AF AG AH      DE CC BE AC DF CD BF AD
    //  BA BB BC BD BE BF BG BH  ->  HE GC FE EC HF GD FF ED
    //  CA CB CC CD CE CF CG CH      DC CA BC AA DD CB BD AB
    //  DA DB DC DD DE DF DG DH      HC GA FC EA HD GB FD EB
    //  EA EB EC ED EE EF EG EH      DA CG BA AG DB CH BB AH
    //  FA FB FC FD FE FF FG FH      HA GG FA EG HB GH FB EH
    //  GA GB GC GD GE GF GG GH      DG CE BG AE DH CF BH AF
    //  HA HB HC HD HE HF HG HH      HG GE FG EE HH GF FH EF
    return Make("PalladiumD",
                28U, 18U, 12U,  2U, 29U, 19U, 13U,  3U,
                60U, 50U, 44U, 34U, 61U, 51U, 45U, 35U,
                26U, 16U, 10U,  0U, 27U, 17U, 11U,  1U,
                58U, 48U, 42U, 32U, 59U, 49U, 43U, 33U,
                24U, 22U,  8U,  6U, 25U, 23U,  9U,  7U,
                56U, 54U, 40U, 38U, 57U, 55U, 41U, 39U,
                30U, 20U, 14U,  4U, 31U, 21U, 15U,  5U,
                62U, 52U, 46U, 36U, 63U, 53U, 47U, 37U
    );
}

Recipe8x8 RecipeFactory8x8::RhodiumA() {
    //  AA AB AC AD AE AF AG AH      HE DE HG DG HA DA HC DC
    //  BA BB BC BD BE BF BG BH  ->  GG CG GA CA GC CC GE CE
    //  CA CB CC CD CE CF CG CH      FE BE FG BG FA BA FC BC
    //  DA DB DC DD DE DF DG DH      EG AG EA AA EC AC EE AE
    //  EA EB EC ED EE EF EG EH      HF DF HH DH HB DB HD DD
    //  FA FB FC FD FE FF FG FH      GH CH GB CB GD CD GF CF
    //  GA GB GC GD GE GF GG GH      FF BF FH BH FB BB FD BD
    //  HA HB HC HD HE HF HG HH      EH AH EB AB ED AD EF AF
    return Make("RhodiumA",
                60U, 28U, 62U, 30U, 56U, 24U, 58U, 26U,
                54U, 22U, 48U, 16U, 50U, 18U, 52U, 20U,
                44U, 12U, 46U, 14U, 40U,  8U, 42U, 10U,
                38U,  6U, 32U,  0U, 34U,  2U, 36U,  4U,
                61U, 29U, 63U, 31U, 57U, 25U, 59U, 27U,
                55U, 23U, 49U, 17U, 51U, 19U, 53U, 21U,
                45U, 13U, 47U, 15U, 41U,  9U, 43U, 11U,
                39U,  7U, 33U,  1U, 35U,  3U, 37U,  5U
    );
}

Recipe8x8 RecipeFactory8x8::RhodiumB() {
    //  AA AB AC AD AE AF AG AH      EH FF GH HF EG FE GG HE
    //  BA BB BC BD BE BF BG BH  ->  AH BF CH DF AG BE CG DE
    //  CA CB CC CD CE CF CG CH      EB FH GB HH EA FG GA HG
    //  DA DB DC DD DE DF DG DH      AB BH CB DH AA BG CA DG
    //  EA EB EC ED EE EF EG EH      ED FB GD HB EC FA GC HA
    //  FA FB FC FD FE FF FG FH      AD BB CD DB AC BA CC DA
    //  GA GB GC GD GE GF GG GH      EF FD GF HD EE FC GE HC
    //  HA HB HC HD HE HF HG HH      AF BD CF DD AE BC CE DC
    return Make("RhodiumB",
                39U, 45U, 55U, 61U, 38U, 44U, 54U, 60U,
                 7U, 13U, 23U, 29U,  6U, 12U, 22U, 28U,
                33U, 47U, 49U, 63U, 32U, 46U, 48U, 62U,
                 1U, 15U, 17U, 31U,  0U, 14U, 16U, 30U,
                35U, 41U, 51U, 57U, 34U, 40U, 50U, 56U,
                 3U,  9U, 19U, 25U,  2U,  8U, 18U, 24U,
                37U, 43U, 53U, 59U, 36U, 42U, 52U, 58U,
                 5U, 11U, 21U, 27U,  4U, 10U, 20U, 26U
    );
}

Recipe8x8 RecipeFactory8x8::RhodiumC() {
    //  AA AB AC AD AE AF AG AH      AF EF AD ED AB EB AH EH
    //  BA BB BC BD BE BF BG BH  ->  BD FD BB FB BH FH BF FF
    //  CA CB CC CD CE CF CG CH      CF GF CD GD CB GB CH GH
    //  DA DB DC DD DE DF DG DH      DD HD DB HB DH HH DF HF
    //  EA EB EC ED EE EF EG EH      AE EE AC EC AA EA AG EG
    //  FA FB FC FD FE FF FG FH      BC FC BA FA BG FG BE FE
    //  GA GB GC GD GE GF GG GH      CE GE CC GC CA GA CG GG
    //  HA HB HC HD HE HF HG HH      DC HC DA HA DG HG DE HE
    return Make("RhodiumC",
                 5U, 37U,  3U, 35U,  1U, 33U,  7U, 39U,
                11U, 43U,  9U, 41U, 15U, 47U, 13U, 45U,
                21U, 53U, 19U, 51U, 17U, 49U, 23U, 55U,
                27U, 59U, 25U, 57U, 31U, 63U, 29U, 61U,
                 4U, 36U,  2U, 34U,  0U, 32U,  6U, 38U,
                10U, 42U,  8U, 40U, 14U, 46U, 12U, 44U,
                20U, 52U, 18U, 50U, 16U, 48U, 22U, 54U,
                26U, 58U, 24U, 56U, 30U, 62U, 28U, 60U
    );
}

Recipe8x8 RecipeFactory8x8::RhodiumD() {
    //  AA AB AC AD AE AF AG AH      DC CE BC AE DD CF BD AF
    //  BA BB BC BD BE BF BG BH  ->  HC GE FC EE HD GF FD EF
    //  CA CB CC CD CE CF CG CH      DA CC BA AC DB CD BB AD
    //  DA DB DC DD DE DF DG DH      HA GC FA EC HB GD FB ED
    //  EA EB EC ED EE EF EG EH      DG CA BG AA DH CB BH AB
    //  FA FB FC FD FE FF FG FH      HG GA FG EA HH GB FH EB
    //  GA GB GC GD GE GF GG GH      DE CG BE AG DF CH BF AH
    //  HA HB HC HD HE HF HG HH      HE GG FE EG HF GH FF EH
    return Make("RhodiumD",
                26U, 20U, 10U,  4U, 27U, 21U, 11U,  5U,
                58U, 52U, 42U, 36U, 59U, 53U, 43U, 37U,
                24U, 18U,  8U,  2U, 25U, 19U,  9U,  3U,
                56U, 50U, 40U, 34U, 57U, 51U, 41U, 35U,
                30U, 16U, 14U,  0U, 31U, 17U, 15U,  1U,
                62U, 48U, 46U, 32U, 63U, 49U, 47U, 33U,
                28U, 22U, 12U,  6U, 29U, 23U, 13U,  7U,
                60U, 54U, 44U, 38U, 61U, 55U, 45U, 39U
    );
}

Recipe8x8 RecipeFactory8x8::ChromiumA() {
    //  AA AB AC AD AE AF AG AH      DA HA DC HC DE HE DG HG
    //  BA BB BC BD BE BF BG BH  ->  CA GA CC GC CE GE CG GG
    //  CA CB CC CD CE CF CG CH      BA FA BC FC BE FE BG FG
    //  DA DB DC DD DE DF DG DH      AA EA AC EC AE EE AG EG
    //  EA EB EC ED EE EF EG EH      FB BB FD BD FF BF FH BH
    //  FA FB FC FD FE FF FG FH      EB AB ED AD EF AF EH AH
    //  GA GB GC GD GE GF GG GH      DB HB DD HD DF HF DH HH
    //  HA HB HC HD HE HF HG HH      CB GB CD GD CF GF CH GH
    return Make("ChromiumA",
                24U, 56U, 26U, 58U, 28U, 60U, 30U, 62U,
                16U, 48U, 18U, 50U, 20U, 52U, 22U, 54U,
                 8U, 40U, 10U, 42U, 12U, 44U, 14U, 46U,
                 0U, 32U,  2U, 34U,  4U, 36U,  6U, 38U,
                41U,  9U, 43U, 11U, 45U, 13U, 47U, 15U,
                33U,  1U, 35U,  3U, 37U,  5U, 39U,  7U,
                25U, 57U, 27U, 59U, 29U, 61U, 31U, 63U,
                17U, 49U, 19U, 51U, 21U, 53U, 23U, 55U
    );
}

Recipe8x8 RecipeFactory8x8::ChromiumB() {
    //  AA AB AC AD AE AF AG AH      CB DB EB FB AA BA CA DA
    //  BA BB BC BD BE BF BG BH  ->  GB HB AB BB EA FA GA HA
    //  CA CB CC CD CE CF CG CH      CD DD ED FD AC BC CC DC
    //  DA DB DC DD DE DF DG DH      GD HD AD BD EC FC GC HC
    //  EA EB EC ED EE EF EG EH      CF DF EF FF AE BE CE DE
    //  FA FB FC FD FE FF FG FH      GF HF AF BF EE FE GE HE
    //  GA GB GC GD GE GF GG GH      CH DH EH FH AG BG CG DG
    //  HA HB HC HD HE HF HG HH      GH HH AH BH EG FG GG HG
    return Make("ChromiumB",
                17U, 25U, 33U, 41U,  0U,  8U, 16U, 24U,
                49U, 57U,  1U,  9U, 32U, 40U, 48U, 56U,
                19U, 27U, 35U, 43U,  2U, 10U, 18U, 26U,
                51U, 59U,  3U, 11U, 34U, 42U, 50U, 58U,
                21U, 29U, 37U, 45U,  4U, 12U, 20U, 28U,
                53U, 61U,  5U, 13U, 36U, 44U, 52U, 60U,
                23U, 31U, 39U, 47U,  6U, 14U, 22U, 30U,
                55U, 63U,  7U, 15U, 38U, 46U, 54U, 62U
    );
}

Recipe8x8 RecipeFactory8x8::ChromiumC() {
    //  AA AB AC AD AE AF AG AH      GH CH GF CF GD CD GB CB
    //  BA BB BC BD BE BF BG BH  ->  HH DH HF DF HD DD HB DB
    //  CA CB CC CD CE CF CG CH      AH EH AF EF AD ED AB EB
    //  DA DB DC DD DE DF DG DH      BH FH BF FF BD FD BB FB
    //  EA EB EC ED EE EF EG EH      EG AG EE AE EC AC EA AA
    //  FA FB FC FD FE FF FG FH      FG BG FE BE FC BC FA BA
    //  GA GB GC GD GE GF GG GH      GG CG GE CE GC CC GA CA
    //  HA HB HC HD HE HF HG HH      HG DG HE DE HC DC HA DA
    return Make("ChromiumC",
                55U, 23U, 53U, 21U, 51U, 19U, 49U, 17U,
                63U, 31U, 61U, 29U, 59U, 27U, 57U, 25U,
                 7U, 39U,  5U, 37U,  3U, 35U,  1U, 33U,
                15U, 47U, 13U, 45U, 11U, 43U,  9U, 41U,
                38U,  6U, 36U,  4U, 34U,  2U, 32U,  0U,
                46U, 14U, 44U, 12U, 42U, 10U, 40U,  8U,
                54U, 22U, 52U, 20U, 50U, 18U, 48U, 16U,
                62U, 30U, 60U, 28U, 58U, 26U, 56U, 24U
    );
}

Recipe8x8 RecipeFactory8x8::ChromiumD() {
    //  AA AB AC AD AE AF AG AH      HG GG FG EG BH AH HH GH
    //  BA BB BC BD BE BF BG BH  ->  DG CG BG AG FH EH DH CH
    //  CA CB CC CD CE CF CG CH      HE GE FE EE BF AF HF GF
    //  DA DB DC DD DE DF DG DH      DE CE BE AE FF EF DF CF
    //  EA EB EC ED EE EF EG EH      HC GC FC EC BD AD HD GD
    //  FA FB FC FD FE FF FG FH      DC CC BC AC FD ED DD CD
    //  GA GB GC GD GE GF GG GH      HA GA FA EA BB AB HB GB
    //  HA HB HC HD HE HF HG HH      DA CA BA AA FB EB DB CB
    return Make("ChromiumD",
                62U, 54U, 46U, 38U, 15U,  7U, 63U, 55U,
                30U, 22U, 14U,  6U, 47U, 39U, 31U, 23U,
                60U, 52U, 44U, 36U, 13U,  5U, 61U, 53U,
                28U, 20U, 12U,  4U, 45U, 37U, 29U, 21U,
                58U, 50U, 42U, 34U, 11U,  3U, 59U, 51U,
                26U, 18U, 10U,  2U, 43U, 35U, 27U, 19U,
                56U, 48U, 40U, 32U,  9U,  1U, 57U, 49U,
                24U, 16U,  8U,  0U, 41U, 33U, 25U, 17U
    );
}

Recipe8x8 RecipeFactory8x8::ZirconiumA() {
    //  AA AB AC AD AE AF AG AH      FA BA FC BC FE BE FG BG
    //  BA BB BC BD BE BF BG BH  ->  EA AA EC AC EE AE EG AG
    //  CA CB CC CD CE CF CG CH      DA HA DC HC DE HE DG HG
    //  DA DB DC DD DE DF DG DH      CA GA CC GC CE GE CG GG
    //  EA EB EC ED EE EF EG EH      DB HB DD HD DF HF DH HH
    //  FA FB FC FD FE FF FG FH      CB GB CD GD CF GF CH GH
    //  GA GB GC GD GE GF GG GH      BB FB BD FD BF FF BH FH
    //  HA HB HC HD HE HF HG HH      AB EB AD ED AF EF AH EH
    return Make("ZirconiumA",
                40U,  8U, 42U, 10U, 44U, 12U, 46U, 14U,
                32U,  0U, 34U,  2U, 36U,  4U, 38U,  6U,
                24U, 56U, 26U, 58U, 28U, 60U, 30U, 62U,
                16U, 48U, 18U, 50U, 20U, 52U, 22U, 54U,
                25U, 57U, 27U, 59U, 29U, 61U, 31U, 63U,
                17U, 49U, 19U, 51U, 21U, 53U, 23U, 55U,
                 9U, 41U, 11U, 43U, 13U, 45U, 15U, 47U,
                 1U, 33U,  3U, 35U,  5U, 37U,  7U, 39U
    );
}

Recipe8x8 RecipeFactory8x8::ZirconiumB() {
    //  AA AB AC AD AE AF AG AH      AB BB CB DB CA DA EA FA
    //  BA BB BC BD BE BF BG BH  ->  EB FB GB HB GA HA AA BA
    //  CA CB CC CD CE CF CG CH      AD BD CD DD CC DC EC FC
    //  DA DB DC DD DE DF DG DH      ED FD GD HD GC HC AC BC
    //  EA EB EC ED EE EF EG EH      AF BF CF DF CE DE EE FE
    //  FA FB FC FD FE FF FG FH      EF FF GF HF GE HE AE BE
    //  GA GB GC GD GE GF GG GH      AH BH CH DH CG DG EG FG
    //  HA HB HC HD HE HF HG HH      EH FH GH HH GG HG AG BG
    return Make("ZirconiumB",
                 1U,  9U, 17U, 25U, 16U, 24U, 32U, 40U,
                33U, 41U, 49U, 57U, 48U, 56U,  0U,  8U,
                 3U, 11U, 19U, 27U, 18U, 26U, 34U, 42U,
                35U, 43U, 51U, 59U, 50U, 58U,  2U, 10U,
                 5U, 13U, 21U, 29U, 20U, 28U, 36U, 44U,
                37U, 45U, 53U, 61U, 52U, 60U,  4U, 12U,
                 7U, 15U, 23U, 31U, 22U, 30U, 38U, 46U,
                39U, 47U, 55U, 63U, 54U, 62U,  6U, 14U
    );
}

Recipe8x8 RecipeFactory8x8::ZirconiumC() {
    //  AA AB AC AD AE AF AG AH      EH AH EF AF ED AD EB AB
    //  BA BB BC BD BE BF BG BH  ->  FH BH FF BF FD BD FB BB
    //  CA CB CC CD CE CF CG CH      GH CH GF CF GD CD GB CB
    //  DA DB DC DD DE DF DG DH      HH DH HF DF HD DD HB DB
    //  EA EB EC ED EE EF EG EH      GG CG GE CE GC CC GA CA
    //  FA FB FC FD FE FF FG FH      HG DG HE DE HC DC HA DA
    //  GA GB GC GD GE GF GG GH      AG EG AE EE AC EC AA EA
    //  HA HB HC HD HE HF HG HH      BG FG BE FE BC FC BA FA
    return Make("ZirconiumC",
                39U,  7U, 37U,  5U, 35U,  3U, 33U,  1U,
                47U, 15U, 45U, 13U, 43U, 11U, 41U,  9U,
                55U, 23U, 53U, 21U, 51U, 19U, 49U, 17U,
                63U, 31U, 61U, 29U, 59U, 27U, 57U, 25U,
                54U, 22U, 52U, 20U, 50U, 18U, 48U, 16U,
                62U, 30U, 60U, 28U, 58U, 26U, 56U, 24U,
                 6U, 38U,  4U, 36U,  2U, 34U,  0U, 32U,
                14U, 46U, 12U, 44U, 10U, 42U,  8U, 40U
    );
}

Recipe8x8 RecipeFactory8x8::ZirconiumD() {
    //  AA AB AC AD AE AF AG AH      BG AG HG GG HH GH FH EH
    //  BA BB BC BD BE BF BG BH  ->  FG EG DG CG DH CH BH AH
    //  CA CB CC CD CE CF CG CH      BE AE HE GE HF GF FF EF
    //  DA DB DC DD DE DF DG DH      FE EE DE CE DF CF BF AF
    //  EA EB EC ED EE EF EG EH      BC AC HC GC HD GD FD ED
    //  FA FB FC FD FE FF FG FH      FC EC DC CC DD CD BD AD
    //  GA GB GC GD GE GF GG GH      BA AA HA GA HB GB FB EB
    //  HA HB HC HD HE HF HG HH      FA EA DA CA DB CB BB AB
    return Make("ZirconiumD",
                14U,  6U, 62U, 54U, 63U, 55U, 47U, 39U,
                46U, 38U, 30U, 22U, 31U, 23U, 15U,  7U,
                12U,  4U, 60U, 52U, 61U, 53U, 45U, 37U,
                44U, 36U, 28U, 20U, 29U, 21U, 13U,  5U,
                10U,  2U, 58U, 50U, 59U, 51U, 43U, 35U,
                42U, 34U, 26U, 18U, 27U, 19U, 11U,  3U,
                 8U,  0U, 56U, 48U, 57U, 49U, 41U, 33U,
                40U, 32U, 24U, 16U, 25U, 17U,  9U,  1U
    );
}



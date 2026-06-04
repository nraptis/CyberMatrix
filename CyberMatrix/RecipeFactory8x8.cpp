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

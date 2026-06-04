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


Recipe8x8 RecipeFactory8x8::HydrogenA() {
    //  AA AB AC AD AE AF AG AH      FA EA FC EC DC CC DA CA
    //  BA BB BC BD BE BF BG BH  ->  FB EB FD ED DD CD DB CB
    //  CA CB CC CD CE CF CG CH      HA GA HC GC BC AC BA AA
    //  DA DB DC DD DE DF DG DH      HB GB HD GD BD AD BB AB
    //  EA EB EC ED EE EF EG EH      HG GG HE GE BE AE BG AG
    //  FA FB FC FD FE FF FG FH      HH GH HF GF BF AF BH AH
    //  GA GB GC GD GE GF GG GH      FG EG FE EE DE CE DG CG
    //  HA HB HC HD HE HF HG HH      FH EH FF EF DF CF DH CH
    return Make("HydrogenA",
                40U, 32U, 42U, 34U, 26U, 18U, 24U, 16U,
                41U, 33U, 43U, 35U, 27U, 19U, 25U, 17U,
                56U, 48U, 58U, 50U, 10U,  2U,  8U,  0U,
                57U, 49U, 59U, 51U, 11U,  3U,  9U,  1U,
                62U, 54U, 60U, 52U, 12U,  4U, 14U,  6U,
                63U, 55U, 61U, 53U, 13U,  5U, 15U,  7U,
                46U, 38U, 44U, 36U, 28U, 20U, 30U, 22U,
                47U, 39U, 45U, 37U, 29U, 21U, 31U, 23U
    );
}

Recipe8x8 RecipeFactory8x8::HydrogenB() {
    //  AA AB AC AD AE AF AG AH      FG EG FE EE DE CE DG CG
    //  BA BB BC BD BE BF BG BH  ->  FH EH FF EF DF CF DH CH
    //  CA CB CC CD CE CF CG CH      HG GG HE GE BE AE BG AG
    //  DA DB DC DD DE DF DG DH      HH GH HF GF BF AF BH AH
    //  EA EB EC ED EE EF EG EH      HA GA HC GC BC AC BA AA
    //  FA FB FC FD FE FF FG FH      HB GB HD GD BD AD BB AB
    //  GA GB GC GD GE GF GG GH      FA EA FC EC DC CC DA CA
    //  HA HB HC HD HE HF HG HH      FB EB FD ED DD CD DB CB
    return Make("HydrogenB",
                46U, 38U, 44U, 36U, 28U, 20U, 30U, 22U,
                47U, 39U, 45U, 37U, 29U, 21U, 31U, 23U,
                62U, 54U, 60U, 52U, 12U,  4U, 14U,  6U,
                63U, 55U, 61U, 53U, 13U,  5U, 15U,  7U,
                56U, 48U, 58U, 50U, 10U,  2U,  8U,  0U,
                57U, 49U, 59U, 51U, 11U,  3U,  9U,  1U,
                40U, 32U, 42U, 34U, 26U, 18U, 24U, 16U,
                41U, 33U, 43U, 35U, 27U, 19U, 25U, 17U
    );
}

Recipe8x8 RecipeFactory8x8::HydrogenC() {
    //  AA AB AC AD AE AF AG AH      HG GG HE GE BE AE BG AG
    //  BA BB BC BD BE BF BG BH  ->  HH GH HF GF BF AF BH AH
    //  CA CB CC CD CE CF CG CH      FG EG FE EE DE CE DG CG
    //  DA DB DC DD DE DF DG DH      FH EH FF EF DF CF DH CH
    //  EA EB EC ED EE EF EG EH      FA EA FC EC DC CC DA CA
    //  FA FB FC FD FE FF FG FH      FB EB FD ED DD CD DB CB
    //  GA GB GC GD GE GF GG GH      HA GA HC GC BC AC BA AA
    //  HA HB HC HD HE HF HG HH      HB GB HD GD BD AD BB AB
    return Make("HydrogenC",
                62U, 54U, 60U, 52U, 12U,  4U, 14U,  6U,
                63U, 55U, 61U, 53U, 13U,  5U, 15U,  7U,
                46U, 38U, 44U, 36U, 28U, 20U, 30U, 22U,
                47U, 39U, 45U, 37U, 29U, 21U, 31U, 23U,
                40U, 32U, 42U, 34U, 26U, 18U, 24U, 16U,
                41U, 33U, 43U, 35U, 27U, 19U, 25U, 17U,
                56U, 48U, 58U, 50U, 10U,  2U,  8U,  0U,
                57U, 49U, 59U, 51U, 11U,  3U,  9U,  1U
    );
}

Recipe8x8 RecipeFactory8x8::HydrogenD() {
    //  AA AB AC AD AE AF AG AH      HC GC HA GA BA AA BC AC
    //  BA BB BC BD BE BF BG BH  ->  HD GD HB GB BB AB BD AD
    //  CA CB CC CD CE CF CG CH      FC EC FA EA DA CA DC CC
    //  DA DB DC DD DE DF DG DH      FD ED FB EB DB CB DD CD
    //  EA EB EC ED EE EF EG EH      FE EE FG EG DG CG DE CE
    //  FA FB FC FD FE FF FG FH      FF EF FH EH DH CH DF CF
    //  GA GB GC GD GE GF GG GH      HE GE HG GG BG AG BE AE
    //  HA HB HC HD HE HF HG HH      HF GF HH GH BH AH BF AF
    return Make("HydrogenD",
                58U, 50U, 56U, 48U,  8U,  0U, 10U,  2U,
                59U, 51U, 57U, 49U,  9U,  1U, 11U,  3U,
                42U, 34U, 40U, 32U, 24U, 16U, 26U, 18U,
                43U, 35U, 41U, 33U, 25U, 17U, 27U, 19U,
                44U, 36U, 46U, 38U, 30U, 22U, 28U, 20U,
                45U, 37U, 47U, 39U, 31U, 23U, 29U, 21U,
                60U, 52U, 62U, 54U, 14U,  6U, 12U,  4U,
                61U, 53U, 63U, 55U, 15U,  7U, 13U,  5U
    );
}

Recipe8x8 RecipeFactory8x8::HeliumA() {
    //  AA AB AC AD AE AF AG AH      HE GE HG GG BG AG BE AE
    //  BA BB BC BD BE BF BG BH  ->  HF GF HH GH BH AH BF AF
    //  CA CB CC CD CE CF CG CH      FE EE FG EG DG CG DE CE
    //  DA DB DC DD DE DF DG DH      FF EF FH EH DH CH DF CF
    //  EA EB EC ED EE EF EG EH      FC EC FA EA DA CA DC CC
    //  FA FB FC FD FE FF FG FH      FD ED FB EB DB CB DD CD
    //  GA GB GC GD GE GF GG GH      HC GC HA GA BA AA BC AC
    //  HA HB HC HD HE HF HG HH      HD GD HB GB BB AB BD AD
    return Make("HeliumA",
                60U, 52U, 62U, 54U, 14U,  6U, 12U,  4U,
                61U, 53U, 63U, 55U, 15U,  7U, 13U,  5U,
                44U, 36U, 46U, 38U, 30U, 22U, 28U, 20U,
                45U, 37U, 47U, 39U, 31U, 23U, 29U, 21U,
                42U, 34U, 40U, 32U, 24U, 16U, 26U, 18U,
                43U, 35U, 41U, 33U, 25U, 17U, 27U, 19U,
                58U, 50U, 56U, 48U,  8U,  0U, 10U,  2U,
                59U, 51U, 57U, 49U,  9U,  1U, 11U,  3U
    );
}

Recipe8x8 RecipeFactory8x8::HeliumB() {
    //  AA AB AC AD AE AF AG AH      FE EE FG EG DG CG DE CE
    //  BA BB BC BD BE BF BG BH  ->  FF EF FH EH DH CH DF CF
    //  CA CB CC CD CE CF CG CH      HE GE HG GG BG AG BE AE
    //  DA DB DC DD DE DF DG DH      HF GF HH GH BH AH BF AF
    //  EA EB EC ED EE EF EG EH      HC GC HA GA BA AA BC AC
    //  FA FB FC FD FE FF FG FH      HD GD HB GB BB AB BD AD
    //  GA GB GC GD GE GF GG GH      FC EC FA EA DA CA DC CC
    //  HA HB HC HD HE HF HG HH      FD ED FB EB DB CB DD CD
    return Make("HeliumB",
                44U, 36U, 46U, 38U, 30U, 22U, 28U, 20U,
                45U, 37U, 47U, 39U, 31U, 23U, 29U, 21U,
                60U, 52U, 62U, 54U, 14U,  6U, 12U,  4U,
                61U, 53U, 63U, 55U, 15U,  7U, 13U,  5U,
                58U, 50U, 56U, 48U,  8U,  0U, 10U,  2U,
                59U, 51U, 57U, 49U,  9U,  1U, 11U,  3U,
                42U, 34U, 40U, 32U, 24U, 16U, 26U, 18U,
                43U, 35U, 41U, 33U, 25U, 17U, 27U, 19U
    );
}

Recipe8x8 RecipeFactory8x8::HeliumC() {
    //  AA AB AC AD AE AF AG AH      CH DH CF DF EF FF EH FH
    //  BA BB BC BD BE BF BG BH  ->  CG DG CE DE EE FE EG FG
    //  CA CB CC CD CE CF CG CH      AH BH AF BF GF HF GH HH
    //  DA DB DC DD DE DF DG DH      AG BG AE BE GE HE GG HG
    //  EA EB EC ED EE EF EG EH      AB BB AD BD GD HD GB HB
    //  FA FB FC FD FE FF FG FH      AA BA AC BC GC HC GA HA
    //  GA GB GC GD GE GF GG GH      CB DB CD DD ED FD EB FB
    //  HA HB HC HD HE HF HG HH      CA DA CC DC EC FC EA FA
    return Make("HeliumC",
                23U, 31U, 21U, 29U, 37U, 45U, 39U, 47U,
                22U, 30U, 20U, 28U, 36U, 44U, 38U, 46U,
                 7U, 15U,  5U, 13U, 53U, 61U, 55U, 63U,
                 6U, 14U,  4U, 12U, 52U, 60U, 54U, 62U,
                 1U,  9U,  3U, 11U, 51U, 59U, 49U, 57U,
                 0U,  8U,  2U, 10U, 50U, 58U, 48U, 56U,
                17U, 25U, 19U, 27U, 35U, 43U, 33U, 41U,
                16U, 24U, 18U, 26U, 34U, 42U, 32U, 40U
    );
}

Recipe8x8 RecipeFactory8x8::HeliumD() {
    //  AA AB AC AD AE AF AG AH      CB DB CD DD ED FD EB FB
    //  BA BB BC BD BE BF BG BH  ->  CA DA CC DC EC FC EA FA
    //  CA CB CC CD CE CF CG CH      AB BB AD BD GD HD GB HB
    //  DA DB DC DD DE DF DG DH      AA BA AC BC GC HC GA HA
    //  EA EB EC ED EE EF EG EH      AH BH AF BF GF HF GH HH
    //  FA FB FC FD FE FF FG FH      AG BG AE BE GE HE GG HG
    //  GA GB GC GD GE GF GG GH      CH DH CF DF EF FF EH FH
    //  HA HB HC HD HE HF HG HH      CG DG CE DE EE FE EG FG
    return Make("HeliumD",
                17U, 25U, 19U, 27U, 35U, 43U, 33U, 41U,
                16U, 24U, 18U, 26U, 34U, 42U, 32U, 40U,
                 1U,  9U,  3U, 11U, 51U, 59U, 49U, 57U,
                 0U,  8U,  2U, 10U, 50U, 58U, 48U, 56U,
                 7U, 15U,  5U, 13U, 53U, 61U, 55U, 63U,
                 6U, 14U,  4U, 12U, 52U, 60U, 54U, 62U,
                23U, 31U, 21U, 29U, 37U, 45U, 39U, 47U,
                22U, 30U, 20U, 28U, 36U, 44U, 38U, 46U
    );
}

Recipe8x8 RecipeFactory8x8::NeonA() {
    //  AA AB AC AD AE AF AG AH      AB BB AD BD GD HD GB HB
    //  BA BB BC BD BE BF BG BH  ->  AA BA AC BC GC HC GA HA
    //  CA CB CC CD CE CF CG CH      CB DB CD DD ED FD EB FB
    //  DA DB DC DD DE DF DG DH      CA DA CC DC EC FC EA FA
    //  EA EB EC ED EE EF EG EH      CH DH CF DF EF FF EH FH
    //  FA FB FC FD FE FF FG FH      CG DG CE DE EE FE EG FG
    //  GA GB GC GD GE GF GG GH      AH BH AF BF GF HF GH HH
    //  HA HB HC HD HE HF HG HH      AG BG AE BE GE HE GG HG
    return Make("NeonA",
                 1U,  9U,  3U, 11U, 51U, 59U, 49U, 57U,
                 0U,  8U,  2U, 10U, 50U, 58U, 48U, 56U,
                17U, 25U, 19U, 27U, 35U, 43U, 33U, 41U,
                16U, 24U, 18U, 26U, 34U, 42U, 32U, 40U,
                23U, 31U, 21U, 29U, 37U, 45U, 39U, 47U,
                22U, 30U, 20U, 28U, 36U, 44U, 38U, 46U,
                 7U, 15U,  5U, 13U, 53U, 61U, 55U, 63U,
                 6U, 14U,  4U, 12U, 52U, 60U, 54U, 62U
    );
}

Recipe8x8 RecipeFactory8x8::NeonB() {
    //  AA AB AC AD AE AF AG AH      AF BF AH BH GH HH GF HF
    //  BA BB BC BD BE BF BG BH  ->  AE BE AG BG GG HG GE HE
    //  CA CB CC CD CE CF CG CH      CF DF CH DH EH FH EF FF
    //  DA DB DC DD DE DF DG DH      CE DE CG DG EG FG EE FE
    //  EA EB EC ED EE EF EG EH      CD DD CB DB EB FB ED FD
    //  FA FB FC FD FE FF FG FH      CC DC CA DA EA FA EC FC
    //  GA GB GC GD GE GF GG GH      AD BD AB BB GB HB GD HD
    //  HA HB HC HD HE HF HG HH      AC BC AA BA GA HA GC HC
    return Make("NeonB",
                 5U, 13U,  7U, 15U, 55U, 63U, 53U, 61U,
                 4U, 12U,  6U, 14U, 54U, 62U, 52U, 60U,
                21U, 29U, 23U, 31U, 39U, 47U, 37U, 45U,
                20U, 28U, 22U, 30U, 38U, 46U, 36U, 44U,
                19U, 27U, 17U, 25U, 33U, 41U, 35U, 43U,
                18U, 26U, 16U, 24U, 32U, 40U, 34U, 42U,
                 3U, 11U,  1U,  9U, 49U, 57U, 51U, 59U,
                 2U, 10U,  0U,  8U, 48U, 56U, 50U, 58U
    );
}

Recipe8x8 RecipeFactory8x8::NeonC() {
    //  AA AB AC AD AE AF AG AH      AD BD AB BB GB HB GD HD
    //  BA BB BC BD BE BF BG BH  ->  AC BC AA BA GA HA GC HC
    //  CA CB CC CD CE CF CG CH      CD DD CB DB EB FB ED FD
    //  DA DB DC DD DE DF DG DH      CC DC CA DA EA FA EC FC
    //  EA EB EC ED EE EF EG EH      CF DF CH DH EH FH EF FF
    //  FA FB FC FD FE FF FG FH      CE DE CG DG EG FG EE FE
    //  GA GB GC GD GE GF GG GH      AF BF AH BH GH HH GF HF
    //  HA HB HC HD HE HF HG HH      AE BE AG BG GG HG GE HE
    return Make("NeonC",
                 3U, 11U,  1U,  9U, 49U, 57U, 51U, 59U,
                 2U, 10U,  0U,  8U, 48U, 56U, 50U, 58U,
                19U, 27U, 17U, 25U, 33U, 41U, 35U, 43U,
                18U, 26U, 16U, 24U, 32U, 40U, 34U, 42U,
                21U, 29U, 23U, 31U, 39U, 47U, 37U, 45U,
                20U, 28U, 22U, 30U, 38U, 46U, 36U, 44U,
                 5U, 13U,  7U, 15U, 55U, 63U, 53U, 61U,
                 4U, 12U,  6U, 14U, 54U, 62U, 52U, 60U
    );
}

Recipe8x8 RecipeFactory8x8::NeonD() {
    //  AA AB AC AD AE AF AG AH      CD DD CB DB EB FB ED FD
    //  BA BB BC BD BE BF BG BH  ->  CC DC CA DA EA FA EC FC
    //  CA CB CC CD CE CF CG CH      AD BD AB BB GB HB GD HD
    //  DA DB DC DD DE DF DG DH      AC BC AA BA GA HA GC HC
    //  EA EB EC ED EE EF EG EH      AF BF AH BH GH HH GF HF
    //  FA FB FC FD FE FF FG FH      AE BE AG BG GG HG GE HE
    //  GA GB GC GD GE GF GG GH      CF DF CH DH EH FH EF FF
    //  HA HB HC HD HE HF HG HH      CE DE CG DG EG FG EE FE
    return Make("NeonD",
                19U, 27U, 17U, 25U, 33U, 41U, 35U, 43U,
                18U, 26U, 16U, 24U, 32U, 40U, 34U, 42U,
                 3U, 11U,  1U,  9U, 49U, 57U, 51U, 59U,
                 2U, 10U,  0U,  8U, 48U, 56U, 50U, 58U,
                 5U, 13U,  7U, 15U, 55U, 63U, 53U, 61U,
                 4U, 12U,  6U, 14U, 54U, 62U, 52U, 60U,
                21U, 29U, 23U, 31U, 39U, 47U, 37U, 45U,
                20U, 28U, 22U, 30U, 38U, 46U, 36U, 44U
    );
}

Recipe8x8 RecipeFactory8x8::ArgonA() {
    //  AA AB AC AD AE AF AG AH      CA CB AA AB AG AH CG CH
    //  BA BB BC BD BE BF BG BH  ->  DA DB BA BB BG BH DG DH
    //  CA CB CC CD CE CF CG CH      CC CD AC AD AE AF CE CF
    //  DA DB DC DD DE DF DG DH      DC DD BC BD BE BF DE DF
    //  EA EB EC ED EE EF EG EH      EC ED GC GD GE GF EE EF
    //  FA FB FC FD FE FF FG FH      FC FD HC HD HE HF FE FF
    //  GA GB GC GD GE GF GG GH      EA EB GA GB GG GH EG EH
    //  HA HB HC HD HE HF HG HH      FA FB HA HB HG HH FG FH
    return Make("ArgonA",
                16U, 17U,  0U,  1U,  6U,  7U, 22U, 23U,
                24U, 25U,  8U,  9U, 14U, 15U, 30U, 31U,
                18U, 19U,  2U,  3U,  4U,  5U, 20U, 21U,
                26U, 27U, 10U, 11U, 12U, 13U, 28U, 29U,
                34U, 35U, 50U, 51U, 52U, 53U, 36U, 37U,
                42U, 43U, 58U, 59U, 60U, 61U, 44U, 45U,
                32U, 33U, 48U, 49U, 54U, 55U, 38U, 39U,
                40U, 41U, 56U, 57U, 62U, 63U, 46U, 47U
    );
}

Recipe8x8 RecipeFactory8x8::ArgonB() {
    //  AA AB AC AD AE AF AG AH      AA EG GA EE GC CE AC CG
    //  BA BB BC BD BE BF BG BH  ->  AB EH GB EF GD CF AD CH
    //  CA CB CC CD CE CF CG CH      CA GG EA GE EC AE CC AG
    //  DA DB DC DD DE DF DG DH      CB GH EB GF ED AF CD AH
    //  EA EB EC ED EE EF EG EH      HA FG HC FE BC DE BA DG
    //  FA FB FC FD FE FF FG FH      HB FH HD FF BD DF BB DH
    //  GA GB GC GD GE GF GG GH      FA HG FC HE DC BE DA BG
    //  HA HB HC HD HE HF HG HH      FB HH FD HF DD BF DB BH
    return Make("ArgonB",
                 0U, 38U, 48U, 36U, 50U, 20U,  2U, 22U,
                 1U, 39U, 49U, 37U, 51U, 21U,  3U, 23U,
                16U, 54U, 32U, 52U, 34U,  4U, 18U,  6U,
                17U, 55U, 33U, 53U, 35U,  5U, 19U,  7U,
                56U, 46U, 58U, 44U, 10U, 28U,  8U, 30U,
                57U, 47U, 59U, 45U, 11U, 29U,  9U, 31U,
                40U, 62U, 42U, 60U, 26U, 12U, 24U, 14U,
                41U, 63U, 43U, 61U, 27U, 13U, 25U, 15U
    );
}

Recipe8x8 RecipeFactory8x8::ArgonC() {
    //  AA AB AC AD AE AF AG AH      CA GG EA GE EC AE CC AG
    //  BA BB BC BD BE BF BG BH  ->  CB GH EB GF ED AF CD AH
    //  CA CB CC CD CE CF CG CH      AA EG GA EE GC CE AC CG
    //  DA DB DC DD DE DF DG DH      AB EH GB EF GD CF AD CH
    //  EA EB EC ED EE EF EG EH      FA HG FC HE DC BE DA BG
    //  FA FB FC FD FE FF FG FH      FB HH FD HF DD BF DB BH
    //  GA GB GC GD GE GF GG GH      HA FG HC FE BC DE BA DG
    //  HA HB HC HD HE HF HG HH      HB FH HD FF BD DF BB DH
    return Make("ArgonC",
                16U, 54U, 32U, 52U, 34U,  4U, 18U,  6U,
                17U, 55U, 33U, 53U, 35U,  5U, 19U,  7U,
                 0U, 38U, 48U, 36U, 50U, 20U,  2U, 22U,
                 1U, 39U, 49U, 37U, 51U, 21U,  3U, 23U,
                40U, 62U, 42U, 60U, 26U, 12U, 24U, 14U,
                41U, 63U, 43U, 61U, 27U, 13U, 25U, 15U,
                56U, 46U, 58U, 44U, 10U, 28U,  8U, 30U,
                57U, 47U, 59U, 45U, 11U, 29U,  9U, 31U
    );
}

Recipe8x8 RecipeFactory8x8::ArgonD() {
    //  AA AB AC AD AE AF AG AH      CE GC EE GA EG AA CG AC
    //  BA BB BC BD BE BF BG BH  ->  CF GD EF GB EH AB CH AD
    //  CA CB CC CD CE CF CG CH      AE EC GE EA GG CA AG CC
    //  DA DB DC DD DE DF DG DH      AF ED GF EB GH CB AH CD
    //  EA EB EC ED EE EF EG EH      FE HC FG HA DG BA DE BC
    //  FA FB FC FD FE FF FG FH      FF HD FH HB DH BB DF BD
    //  GA GB GC GD GE GF GG GH      HE FC HG FA BG DA BE DC
    //  HA HB HC HD HE HF HG HH      HF FD HH FB BH DB BF DD
    return Make("ArgonD",
                20U, 50U, 36U, 48U, 38U,  0U, 22U,  2U,
                21U, 51U, 37U, 49U, 39U,  1U, 23U,  3U,
                 4U, 34U, 52U, 32U, 54U, 16U,  6U, 18U,
                 5U, 35U, 53U, 33U, 55U, 17U,  7U, 19U,
                44U, 58U, 46U, 56U, 30U,  8U, 28U, 10U,
                45U, 59U, 47U, 57U, 31U,  9U, 29U, 11U,
                60U, 42U, 62U, 40U, 14U, 24U, 12U, 26U,
                61U, 43U, 63U, 41U, 15U, 25U, 13U, 27U
    );
}

Recipe8x8 RecipeFactory8x8::KryptonA() {
    //  AA AB AC AD AE AF AG AH      CC GE EC GG EA AG CA AE
    //  BA BB BC BD BE BF BG BH  ->  CD GF ED GH EB AH CB AF
    //  CA CB CC CD CE CF CG CH      AC EE GC EG GA CG AA CE
    //  DA DB DC DD DE DF DG DH      AD EF GD EH GB CH AB CF
    //  EA EB EC ED EE EF EG EH      FC HE FA HG DA BG DC BE
    //  FA FB FC FD FE FF FG FH      FD HF FB HH DB BH DD BF
    //  GA GB GC GD GE GF GG GH      HC FE HA FG BA DG BC DE
    //  HA HB HC HD HE HF HG HH      HD FF HB FH BB DH BD DF
    return Make("KryptonA",
                18U, 52U, 34U, 54U, 32U,  6U, 16U,  4U,
                19U, 53U, 35U, 55U, 33U,  7U, 17U,  5U,
                 2U, 36U, 50U, 38U, 48U, 22U,  0U, 20U,
                 3U, 37U, 51U, 39U, 49U, 23U,  1U, 21U,
                42U, 60U, 40U, 62U, 24U, 14U, 26U, 12U,
                43U, 61U, 41U, 63U, 25U, 15U, 27U, 13U,
                58U, 44U, 56U, 46U,  8U, 30U, 10U, 28U,
                59U, 45U, 57U, 47U,  9U, 31U, 11U, 29U
    );
}

Recipe8x8 RecipeFactory8x8::KryptonB() {
    //  AA AB AC AD AE AF AG AH      AC EE GC EG GA CG AA CE
    //  BA BB BC BD BE BF BG BH  ->  AD EF GD EH GB CH AB CF
    //  CA CB CC CD CE CF CG CH      CC GE EC GG EA AG CA AE
    //  DA DB DC DD DE DF DG DH      CD GF ED GH EB AH CB AF
    //  EA EB EC ED EE EF EG EH      HC FE HA FG BA DG BC DE
    //  FA FB FC FD FE FF FG FH      HD FF HB FH BB DH BD DF
    //  GA GB GC GD GE GF GG GH      FC HE FA HG DA BG DC BE
    //  HA HB HC HD HE HF HG HH      FD HF FB HH DB BH DD BF
    return Make("KryptonB",
                 2U, 36U, 50U, 38U, 48U, 22U,  0U, 20U,
                 3U, 37U, 51U, 39U, 49U, 23U,  1U, 21U,
                18U, 52U, 34U, 54U, 32U,  6U, 16U,  4U,
                19U, 53U, 35U, 55U, 33U,  7U, 17U,  5U,
                58U, 44U, 56U, 46U,  8U, 30U, 10U, 28U,
                59U, 45U, 57U, 47U,  9U, 31U, 11U, 29U,
                42U, 60U, 40U, 62U, 24U, 14U, 26U, 12U,
                43U, 61U, 41U, 63U, 25U, 15U, 27U, 13U
    );
}

Recipe8x8 RecipeFactory8x8::KryptonC() {
    //  AA AB AC AD AE AF AG AH      HB DH BB DF BD FF HD FH
    //  BA BB BC BD BE BF BG BH  ->  HA DG BA DE BC FE HC FG
    //  CA CB CC CD CE CF CG CH      FB BH DB BF DD HF FD HH
    //  DA DB DC DD DE DF DG DH      FA BG DA BE DC HE FC HG
    //  EA EB EC ED EE EF EG EH      AB CH AD CF GD EF GB EH
    //  FA FB FC FD FE FF FG FH      AA CG AC CE GC EE GA EG
    //  GA GB GC GD GE GF GG GH      CB AH CD AF ED GF EB GH
    //  HA HB HC HD HE HF HG HH      CA AG CC AE EC GE EA GG
    return Make("KryptonC",
                57U, 31U,  9U, 29U, 11U, 45U, 59U, 47U,
                56U, 30U,  8U, 28U, 10U, 44U, 58U, 46U,
                41U, 15U, 25U, 13U, 27U, 61U, 43U, 63U,
                40U, 14U, 24U, 12U, 26U, 60U, 42U, 62U,
                 1U, 23U,  3U, 21U, 51U, 37U, 49U, 39U,
                 0U, 22U,  2U, 20U, 50U, 36U, 48U, 38U,
                17U,  7U, 19U,  5U, 35U, 53U, 33U, 55U,
                16U,  6U, 18U,  4U, 34U, 52U, 32U, 54U
    );
}

Recipe8x8 RecipeFactory8x8::KryptonD() {
    //  AA AB AC AD AE AF AG AH      HH DB BH DD BF FD HF FB
    //  BA BB BC BD BE BF BG BH  ->  HG DA BG DC BE FC HE FA
    //  CA CB CC CD CE CF CG CH      FH BB DH BD DF HD FF HB
    //  DA DB DC DD DE DF DG DH      FG BA DG BC DE HC FE HA
    //  EA EB EC ED EE EF EG EH      AH CB AF CD GF ED GH EB
    //  FA FB FC FD FE FF FG FH      AG CA AE CC GE EC GG EA
    //  GA GB GC GD GE GF GG GH      CH AB CF AD EF GD EH GB
    //  HA HB HC HD HE HF HG HH      CG AA CE AC EE GC EG GA
    return Make("KryptonD",
                63U, 25U, 15U, 27U, 13U, 43U, 61U, 41U,
                62U, 24U, 14U, 26U, 12U, 42U, 60U, 40U,
                47U,  9U, 31U, 11U, 29U, 59U, 45U, 57U,
                46U,  8U, 30U, 10U, 28U, 58U, 44U, 56U,
                 7U, 17U,  5U, 19U, 53U, 35U, 55U, 33U,
                 6U, 16U,  4U, 18U, 52U, 34U, 54U, 32U,
                23U,  1U, 21U,  3U, 37U, 51U, 39U, 49U,
                22U,  0U, 20U,  2U, 36U, 50U, 38U, 48U
    );
}

Recipe8x8 RecipeFactory8x8::XenonA() {
    //  AA AB AC AD AE AF AG AH      FH BB DH BD DF HD FF HB
    //  BA BB BC BD BE BF BG BH  ->  FG BA DG BC DE HC FE HA
    //  CA CB CC CD CE CF CG CH      HH DB BH DD BF FD HF FB
    //  DA DB DC DD DE DF DG DH      HG DA BG DC BE FC HE FA
    //  EA EB EC ED EE EF EG EH      CH AB CF AD EF GD EH GB
    //  FA FB FC FD FE FF FG FH      CG AA CE AC EE GC EG GA
    //  GA GB GC GD GE GF GG GH      AH CB AF CD GF ED GH EB
    //  HA HB HC HD HE HF HG HH      AG CA AE CC GE EC GG EA
    return Make("XenonA",
                47U,  9U, 31U, 11U, 29U, 59U, 45U, 57U,
                46U,  8U, 30U, 10U, 28U, 58U, 44U, 56U,
                63U, 25U, 15U, 27U, 13U, 43U, 61U, 41U,
                62U, 24U, 14U, 26U, 12U, 42U, 60U, 40U,
                23U,  1U, 21U,  3U, 37U, 51U, 39U, 49U,
                22U,  0U, 20U,  2U, 36U, 50U, 38U, 48U,
                 7U, 17U,  5U, 19U, 53U, 35U, 55U, 33U,
                 6U, 16U,  4U, 18U, 52U, 34U, 54U, 32U
    );
}

Recipe8x8 RecipeFactory8x8::XenonB() {
    //  AA AB AC AD AE AF AG AH      FD BF DD BH DB HH FB HF
    //  BA BB BC BD BE BF BG BH  ->  FC BE DC BG DA HG FA HE
    //  CA CB CC CD CE CF CG CH      HD DF BD DH BB FH HB FF
    //  DA DB DC DD DE DF DG DH      HC DE BC DG BA FG HA FE
    //  EA EB EC ED EE EF EG EH      CD AF CB AH EB GH ED GF
    //  FA FB FC FD FE FF FG FH      CC AE CA AG EA GG EC GE
    //  GA GB GC GD GE GF GG GH      AD CF AB CH GB EH GD EF
    //  HA HB HC HD HE HF HG HH      AC CE AA CG GA EG GC EE
    return Make("XenonB",
                43U, 13U, 27U, 15U, 25U, 63U, 41U, 61U,
                42U, 12U, 26U, 14U, 24U, 62U, 40U, 60U,
                59U, 29U, 11U, 31U,  9U, 47U, 57U, 45U,
                58U, 28U, 10U, 30U,  8U, 46U, 56U, 44U,
                19U,  5U, 17U,  7U, 33U, 55U, 35U, 53U,
                18U,  4U, 16U,  6U, 32U, 54U, 34U, 52U,
                 3U, 21U,  1U, 23U, 49U, 39U, 51U, 37U,
                 2U, 20U,  0U, 22U, 48U, 38U, 50U, 36U
    );
}

Recipe8x8 RecipeFactory8x8::XenonC() {
    //  AA AB AC AD AE AF AG AH      FF BD DF BB DH HB FH HD
    //  BA BB BC BD BE BF BG BH  ->  FE BC DE BA DG HA FG HC
    //  CA CB CC CD CE CF CG CH      HF DD BF DB BH FB HH FD
    //  DA DB DC DD DE DF DG DH      HE DC BE DA BG FA HG FC
    //  EA EB EC ED EE EF EG EH      CF AD CH AB EH GB EF GD
    //  FA FB FC FD FE FF FG FH      CE AC CG AA EG GA EE GC
    //  GA GB GC GD GE GF GG GH      AF CD AH CB GH EB GF ED
    //  HA HB HC HD HE HF HG HH      AE CC AG CA GG EA GE EC
    return Make("XenonC",
                45U, 11U, 29U,  9U, 31U, 57U, 47U, 59U,
                44U, 10U, 28U,  8U, 30U, 56U, 46U, 58U,
                61U, 27U, 13U, 25U, 15U, 41U, 63U, 43U,
                60U, 26U, 12U, 24U, 14U, 40U, 62U, 42U,
                21U,  3U, 23U,  1U, 39U, 49U, 37U, 51U,
                20U,  2U, 22U,  0U, 38U, 48U, 36U, 50U,
                 5U, 19U,  7U, 17U, 55U, 33U, 53U, 35U,
                 4U, 18U,  6U, 16U, 54U, 32U, 52U, 34U
    );
}

Recipe8x8 RecipeFactory8x8::XenonD() {
    //  AA AB AC AD AE AF AG AH      HF DD BF DB BH FB HH FD
    //  BA BB BC BD BE BF BG BH  ->  HE DC BE DA BG FA HG FC
    //  CA CB CC CD CE CF CG CH      FF BD DF BB DH HB FH HD
    //  DA DB DC DD DE DF DG DH      FE BC DE BA DG HA FG HC
    //  EA EB EC ED EE EF EG EH      AF CD AH CB GH EB GF ED
    //  FA FB FC FD FE FF FG FH      AE CC AG CA GG EA GE EC
    //  GA GB GC GD GE GF GG GH      CF AD CH AB EH GB EF GD
    //  HA HB HC HD HE HF HG HH      CE AC CG AA EG GA EE GC
    return Make("XenonD",
                61U, 27U, 13U, 25U, 15U, 41U, 63U, 43U,
                60U, 26U, 12U, 24U, 14U, 40U, 62U, 42U,
                45U, 11U, 29U,  9U, 31U, 57U, 47U, 59U,
                44U, 10U, 28U,  8U, 30U, 56U, 46U, 58U,
                 5U, 19U,  7U, 17U, 55U, 33U, 53U, 35U,
                 4U, 18U,  6U, 16U, 54U, 32U, 52U, 34U,
                21U,  3U, 23U,  1U, 39U, 49U, 37U, 51U,
                20U,  2U, 22U,  0U, 38U, 48U, 36U, 50U
    );
}

Recipe8x8 RecipeFactory8x8::RadonA() {
    //  AA AB AC AD AE AF AG AH      FA HG FC HE DC BE DA BG
    //  BA BB BC BD BE BF BG BH  ->  FB HH FD HF DD BF DB BH
    //  CA CB CC CD CE CF CG CH      HA FG HC FE BC DE BA DG
    //  DA DB DC DD DE DF DG DH      HB FH HD FF BD DF BB DH
    //  EA EB EC ED EE EF EG EH      EA GG EC GE CC AE CA AG
    //  FA FB FC FD FE FF FG FH      EB GH ED GF CD AF CB AH
    //  GA GB GC GD GE GF GG GH      GA EG GC EE AC CE AA CG
    //  HA HB HC HD HE HF HG HH      GB EH GD EF AD CF AB CH
    return Make("RadonA",
                40U, 62U, 42U, 60U, 26U, 12U, 24U, 14U,
                41U, 63U, 43U, 61U, 27U, 13U, 25U, 15U,
                56U, 46U, 58U, 44U, 10U, 28U,  8U, 30U,
                57U, 47U, 59U, 45U, 11U, 29U,  9U, 31U,
                32U, 54U, 34U, 52U, 18U,  4U, 16U,  6U,
                33U, 55U, 35U, 53U, 19U,  5U, 17U,  7U,
                48U, 38U, 50U, 36U,  2U, 20U,  0U, 22U,
                49U, 39U, 51U, 37U,  3U, 21U,  1U, 23U
    );
}

Recipe8x8 RecipeFactory8x8::RadonB() {
    //  AA AB AC AD AE AF AG AH      FG HA FE HC DE BC DG BA
    //  BA BB BC BD BE BF BG BH  ->  FH HB FF HD DF BD DH BB
    //  CA CB CC CD CE CF CG CH      HG FA HE FC BE DC BG DA
    //  DA DB DC DD DE DF DG DH      HH FB HF FD BF DD BH DB
    //  EA EB EC ED EE EF EG EH      EG GA EE GC CE AC CG AA
    //  FA FB FC FD FE FF FG FH      EH GB EF GD CF AD CH AB
    //  GA GB GC GD GE GF GG GH      GG EA GE EC AE CC AG CA
    //  HA HB HC HD HE HF HG HH      GH EB GF ED AF CD AH CB
    return Make("RadonB",
                46U, 56U, 44U, 58U, 28U, 10U, 30U,  8U,
                47U, 57U, 45U, 59U, 29U, 11U, 31U,  9U,
                62U, 40U, 60U, 42U, 12U, 26U, 14U, 24U,
                63U, 41U, 61U, 43U, 13U, 27U, 15U, 25U,
                38U, 48U, 36U, 50U, 20U,  2U, 22U,  0U,
                39U, 49U, 37U, 51U, 21U,  3U, 23U,  1U,
                54U, 32U, 52U, 34U,  4U, 18U,  6U, 16U,
                55U, 33U, 53U, 35U,  5U, 19U,  7U, 17U
    );
}

Recipe8x8 RecipeFactory8x8::RadonC() {
    //  AA AB AC AD AE AF AG AH      HG FA HE FC BE DC BG DA
    //  BA BB BC BD BE BF BG BH  ->  HH FB HF FD BF DD BH DB
    //  CA CB CC CD CE CF CG CH      FG HA FE HC DE BC DG BA
    //  DA DB DC DD DE DF DG DH      FH HB FF HD DF BD DH BB
    //  EA EB EC ED EE EF EG EH      GG EA GE EC AE CC AG CA
    //  FA FB FC FD FE FF FG FH      GH EB GF ED AF CD AH CB
    //  GA GB GC GD GE GF GG GH      EG GA EE GC CE AC CG AA
    //  HA HB HC HD HE HF HG HH      EH GB EF GD CF AD CH AB
    return Make("RadonC",
                62U, 40U, 60U, 42U, 12U, 26U, 14U, 24U,
                63U, 41U, 61U, 43U, 13U, 27U, 15U, 25U,
                46U, 56U, 44U, 58U, 28U, 10U, 30U,  8U,
                47U, 57U, 45U, 59U, 29U, 11U, 31U,  9U,
                54U, 32U, 52U, 34U,  4U, 18U,  6U, 16U,
                55U, 33U, 53U, 35U,  5U, 19U,  7U, 17U,
                38U, 48U, 36U, 50U, 20U,  2U, 22U,  0U,
                39U, 49U, 37U, 51U, 21U,  3U, 23U,  1U
    );
}

Recipe8x8 RecipeFactory8x8::RadonD() {
    //  AA AB AC AD AE AF AG AH      HC FE HA FG BA DG BC DE
    //  BA BB BC BD BE BF BG BH  ->  HD FF HB FH BB DH BD DF
    //  CA CB CC CD CE CF CG CH      FC HE FA HG DA BG DC BE
    //  DA DB DC DD DE DF DG DH      FD HF FB HH DB BH DD BF
    //  EA EB EC ED EE EF EG EH      GC EE GA EG AA CG AC CE
    //  FA FB FC FD FE FF FG FH      GD EF GB EH AB CH AD CF
    //  GA GB GC GD GE GF GG GH      EC GE EA GG CA AG CC AE
    //  HA HB HC HD HE HF HG HH      ED GF EB GH CB AH CD AF
    return Make("RadonD",
                58U, 44U, 56U, 46U,  8U, 30U, 10U, 28U,
                59U, 45U, 57U, 47U,  9U, 31U, 11U, 29U,
                42U, 60U, 40U, 62U, 24U, 14U, 26U, 12U,
                43U, 61U, 41U, 63U, 25U, 15U, 27U, 13U,
                50U, 36U, 48U, 38U,  0U, 22U,  2U, 20U,
                51U, 37U, 49U, 39U,  1U, 23U,  3U, 21U,
                34U, 52U, 32U, 54U, 16U,  6U, 18U,  4U,
                35U, 53U, 33U, 55U, 17U,  7U, 19U,  5U
    );
}

Recipe8x8 RecipeFactory8x8::FluorineA() {
    //  AA AB AC AD AE AF AG AH      HE FC HG FA BG DA BE DC
    //  BA BB BC BD BE BF BG BH  ->  HF FD HH FB BH DB BF DD
    //  CA CB CC CD CE CF CG CH      FE HC FG HA DG BA DE BC
    //  DA DB DC DD DE DF DG DH      FF HD FH HB DH BB DF BD
    //  EA EB EC ED EE EF EG EH      GE EC GG EA AG CA AE CC
    //  FA FB FC FD FE FF FG FH      GF ED GH EB AH CB AF CD
    //  GA GB GC GD GE GF GG GH      EE GC EG GA CG AA CE AC
    //  HA HB HC HD HE HF HG HH      EF GD EH GB CH AB CF AD
    return Make("FluorineA",
                60U, 42U, 62U, 40U, 14U, 24U, 12U, 26U,
                61U, 43U, 63U, 41U, 15U, 25U, 13U, 27U,
                44U, 58U, 46U, 56U, 30U,  8U, 28U, 10U,
                45U, 59U, 47U, 57U, 31U,  9U, 29U, 11U,
                52U, 34U, 54U, 32U,  6U, 16U,  4U, 18U,
                53U, 35U, 55U, 33U,  7U, 17U,  5U, 19U,
                36U, 50U, 38U, 48U, 22U,  0U, 20U,  2U,
                37U, 51U, 39U, 49U, 23U,  1U, 21U,  3U
    );
}

Recipe8x8 RecipeFactory8x8::FluorineB() {
    //  AA AB AC AD AE AF AG AH      FE HC FG HA DG BA DE BC
    //  BA BB BC BD BE BF BG BH  ->  FF HD FH HB DH BB DF BD
    //  CA CB CC CD CE CF CG CH      HE FC HG FA BG DA BE DC
    //  DA DB DC DD DE DF DG DH      HF FD HH FB BH DB BF DD
    //  EA EB EC ED EE EF EG EH      EE GC EG GA CG AA CE AC
    //  FA FB FC FD FE FF FG FH      EF GD EH GB CH AB CF AD
    //  GA GB GC GD GE GF GG GH      GE EC GG EA AG CA AE CC
    //  HA HB HC HD HE HF HG HH      GF ED GH EB AH CB AF CD
    return Make("FluorineB",
                44U, 58U, 46U, 56U, 30U,  8U, 28U, 10U,
                45U, 59U, 47U, 57U, 31U,  9U, 29U, 11U,
                60U, 42U, 62U, 40U, 14U, 24U, 12U, 26U,
                61U, 43U, 63U, 41U, 15U, 25U, 13U, 27U,
                36U, 50U, 38U, 48U, 22U,  0U, 20U,  2U,
                37U, 51U, 39U, 49U, 23U,  1U, 21U,  3U,
                52U, 34U, 54U, 32U,  6U, 16U,  4U, 18U,
                53U, 35U, 55U, 33U,  7U, 17U,  5U, 19U
    );
}

Recipe8x8 RecipeFactory8x8::FluorineC() {
    //  AA AB AC AD AE AF AG AH      CH AB CF AD EF GD EH GB
    //  BA BB BC BD BE BF BG BH  ->  CG AA CE AC EE GC EG GA
    //  CA CB CC CD CE CF CG CH      AH CB AF CD GF ED GH EB
    //  DA DB DC DD DE DF DG DH      AG CA AE CC GE EC GG EA
    //  EA EB EC ED EE EF EG EH      DH BB DF BD FF HD FH HB
    //  FA FB FC FD FE FF FG FH      DG BA DE BC FE HC FG HA
    //  GA GB GC GD GE GF GG GH      BH DB BF DD HF FD HH FB
    //  HA HB HC HD HE HF HG HH      BG DA BE DC HE FC HG FA
    return Make("FluorineC",
                23U,  1U, 21U,  3U, 37U, 51U, 39U, 49U,
                22U,  0U, 20U,  2U, 36U, 50U, 38U, 48U,
                 7U, 17U,  5U, 19U, 53U, 35U, 55U, 33U,
                 6U, 16U,  4U, 18U, 52U, 34U, 54U, 32U,
                31U,  9U, 29U, 11U, 45U, 59U, 47U, 57U,
                30U,  8U, 28U, 10U, 44U, 58U, 46U, 56U,
                15U, 25U, 13U, 27U, 61U, 43U, 63U, 41U,
                14U, 24U, 12U, 26U, 60U, 42U, 62U, 40U
    );
}

Recipe8x8 RecipeFactory8x8::FluorineD() {
    //  AA AB AC AD AE AF AG AH      CB AH CD AF ED GF EB GH
    //  BA BB BC BD BE BF BG BH  ->  CA AG CC AE EC GE EA GG
    //  CA CB CC CD CE CF CG CH      AB CH AD CF GD EF GB EH
    //  DA DB DC DD DE DF DG DH      AA CG AC CE GC EE GA EG
    //  EA EB EC ED EE EF EG EH      DB BH DD BF FD HF FB HH
    //  FA FB FC FD FE FF FG FH      DA BG DC BE FC HE FA HG
    //  GA GB GC GD GE GF GG GH      BB DH BD DF HD FF HB FH
    //  HA HB HC HD HE HF HG HH      BA DG BC DE HC FE HA FG
    return Make("FluorineD",
                17U,  7U, 19U,  5U, 35U, 53U, 33U, 55U,
                16U,  6U, 18U,  4U, 34U, 52U, 32U, 54U,
                 1U, 23U,  3U, 21U, 51U, 37U, 49U, 39U,
                 0U, 22U,  2U, 20U, 50U, 36U, 48U, 38U,
                25U, 15U, 27U, 13U, 43U, 61U, 41U, 63U,
                24U, 14U, 26U, 12U, 42U, 60U, 40U, 62U,
                 9U, 31U, 11U, 29U, 59U, 45U, 57U, 47U,
                 8U, 30U, 10U, 28U, 58U, 44U, 56U, 46U
    );
}

Recipe8x8 RecipeFactory8x8::ChlorineA() {
    //  AA AB AC AD AE AF AG AH      AB CH AD CF GD EF GB EH
    //  BA BB BC BD BE BF BG BH  ->  AA CG AC CE GC EE GA EG
    //  CA CB CC CD CE CF CG CH      CB AH CD AF ED GF EB GH
    //  DA DB DC DD DE DF DG DH      CA AG CC AE EC GE EA GG
    //  EA EB EC ED EE EF EG EH      BB DH BD DF HD FF HB FH
    //  FA FB FC FD FE FF FG FH      BA DG BC DE HC FE HA FG
    //  GA GB GC GD GE GF GG GH      DB BH DD BF FD HF FB HH
    //  HA HB HC HD HE HF HG HH      DA BG DC BE FC HE FA HG
    return Make("ChlorineA",
                 1U, 23U,  3U, 21U, 51U, 37U, 49U, 39U,
                 0U, 22U,  2U, 20U, 50U, 36U, 48U, 38U,
                17U,  7U, 19U,  5U, 35U, 53U, 33U, 55U,
                16U,  6U, 18U,  4U, 34U, 52U, 32U, 54U,
                 9U, 31U, 11U, 29U, 59U, 45U, 57U, 47U,
                 8U, 30U, 10U, 28U, 58U, 44U, 56U, 46U,
                25U, 15U, 27U, 13U, 43U, 61U, 41U, 63U,
                24U, 14U, 26U, 12U, 42U, 60U, 40U, 62U
    );
}

Recipe8x8 RecipeFactory8x8::ChlorineB() {
    //  AA AB AC AD AE AF AG AH      AF CD AH CB GH EB GF ED
    //  BA BB BC BD BE BF BG BH  ->  AE CC AG CA GG EA GE EC
    //  CA CB CC CD CE CF CG CH      CF AD CH AB EH GB EF GD
    //  DA DB DC DD DE DF DG DH      CE AC CG AA EG GA EE GC
    //  EA EB EC ED EE EF EG EH      BF DD BH DB HH FB HF FD
    //  FA FB FC FD FE FF FG FH      BE DC BG DA HG FA HE FC
    //  GA GB GC GD GE GF GG GH      DF BD DH BB FH HB FF HD
    //  HA HB HC HD HE HF HG HH      DE BC DG BA FG HA FE HC
    return Make("ChlorineB",
                 5U, 19U,  7U, 17U, 55U, 33U, 53U, 35U,
                 4U, 18U,  6U, 16U, 54U, 32U, 52U, 34U,
                21U,  3U, 23U,  1U, 39U, 49U, 37U, 51U,
                20U,  2U, 22U,  0U, 38U, 48U, 36U, 50U,
                13U, 27U, 15U, 25U, 63U, 41U, 61U, 43U,
                12U, 26U, 14U, 24U, 62U, 40U, 60U, 42U,
                29U, 11U, 31U,  9U, 47U, 57U, 45U, 59U,
                28U, 10U, 30U,  8U, 46U, 56U, 44U, 58U
    );
}

Recipe8x8 RecipeFactory8x8::ChlorineC() {
    //  AA AB AC AD AE AF AG AH      AD CF AB CH GB EH GD EF
    //  BA BB BC BD BE BF BG BH  ->  AC CE AA CG GA EG GC EE
    //  CA CB CC CD CE CF CG CH      CD AF CB AH EB GH ED GF
    //  DA DB DC DD DE DF DG DH      CC AE CA AG EA GG EC GE
    //  EA EB EC ED EE EF EG EH      BD DF BB DH HB FH HD FF
    //  FA FB FC FD FE FF FG FH      BC DE BA DG HA FG HC FE
    //  GA GB GC GD GE GF GG GH      DD BF DB BH FB HH FD HF
    //  HA HB HC HD HE HF HG HH      DC BE DA BG FA HG FC HE
    return Make("ChlorineC",
                 3U, 21U,  1U, 23U, 49U, 39U, 51U, 37U,
                 2U, 20U,  0U, 22U, 48U, 38U, 50U, 36U,
                19U,  5U, 17U,  7U, 33U, 55U, 35U, 53U,
                18U,  4U, 16U,  6U, 32U, 54U, 34U, 52U,
                11U, 29U,  9U, 31U, 57U, 47U, 59U, 45U,
                10U, 28U,  8U, 30U, 56U, 46U, 58U, 44U,
                27U, 13U, 25U, 15U, 41U, 63U, 43U, 61U,
                26U, 12U, 24U, 14U, 40U, 62U, 42U, 60U
    );
}

Recipe8x8 RecipeFactory8x8::ChlorineD() {
    //  AA AB AC AD AE AF AG AH      CD AF CB AH EB GH ED GF
    //  BA BB BC BD BE BF BG BH  ->  CC AE CA AG EA GG EC GE
    //  CA CB CC CD CE CF CG CH      AD CF AB CH GB EH GD EF
    //  DA DB DC DD DE DF DG DH      AC CE AA CG GA EG GC EE
    //  EA EB EC ED EE EF EG EH      DD BF DB BH FB HH FD HF
    //  FA FB FC FD FE FF FG FH      DC BE DA BG FA HG FC HE
    //  GA GB GC GD GE GF GG GH      BD DF BB DH HB FH HD FF
    //  HA HB HC HD HE HF HG HH      BC DE BA DG HA FG HC FE
    return Make("ChlorineD",
                19U,  5U, 17U,  7U, 33U, 55U, 35U, 53U,
                18U,  4U, 16U,  6U, 32U, 54U, 34U, 52U,
                 3U, 21U,  1U, 23U, 49U, 39U, 51U, 37U,
                 2U, 20U,  0U, 22U, 48U, 38U, 50U, 36U,
                27U, 13U, 25U, 15U, 41U, 63U, 43U, 61U,
                26U, 12U, 24U, 14U, 40U, 62U, 42U, 60U,
                11U, 29U,  9U, 31U, 57U, 47U, 59U, 45U,
                10U, 28U,  8U, 30U, 56U, 46U, 58U, 44U
    );
}


Recipe8x8 RecipeFactory8x8::MapleA() {
    //  AA AB AC AD AE AF AG AH      ED FD EB FB FA EA FC EC
    //  BA BB BC BD BE BF BG BH  ->  DD CD DB CB CA DA CC DC
    //  CA CB CC CD CE CF CG CH      BC AC BA AA AB BB AD BD
    //  DA DB DC DD DE DF DG DH      GC HC GA HA HB GB HD GD
    //  EA EB EC ED EE EF EG EH      GF HF GH HH HG GG HE GE
    //  FA FB FC FD FE FF FG FH      BF AF BH AH AG BG AE BE
    //  GA GB GC GD GE GF GG GH      DE CE DG CG CH DH CF DF
    //  HA HB HC HD HE HF HG HH      EE FE EG FG FH EH FF EF
    return Make("MapleA",
                35U, 43U, 33U, 41U, 40U, 32U, 42U, 34U,
                27U, 19U, 25U, 17U, 16U, 24U, 18U, 26U,
                10U,  2U,  8U,  0U,  1U,  9U,  3U, 11U,
                50U, 58U, 48U, 56U, 57U, 49U, 59U, 51U,
                53U, 61U, 55U, 63U, 62U, 54U, 60U, 52U,
                13U,  5U, 15U,  7U,  6U, 14U,  4U, 12U,
                28U, 20U, 30U, 22U, 23U, 31U, 21U, 29U,
                36U, 44U, 38U, 46U, 47U, 39U, 45U, 37U
    );
}

Recipe8x8 RecipeFactory8x8::MapleB() {
    //  AA AB AC AD AE AF AG AH      DC CC DA CA CB DB CD DD
    //  BA BB BC BD BE BF BG BH  ->  EC FC EA FA FB EB FD ED
    //  CA CB CC CD CE CF CG CH      GD HD GB HB HA GA HC GC
    //  DA DB DC DD DE DF DG DH      BD AD BB AB AA BA AC BC
    //  EA EB EC ED EE EF EG EH      BE AE BG AG AH BH AF BF
    //  FA FB FC FD FE FF FG FH      GE HE GG HG HH GH HF GF
    //  GA GB GC GD GE GF GG GH      EF FF EH FH FG EG FE EE
    //  HA HB HC HD HE HF HG HH      DF CF DH CH CG DG CE DE
    return Make("MapleB",
                26U, 18U, 24U, 16U, 17U, 25U, 19U, 27U,
                34U, 42U, 32U, 40U, 41U, 33U, 43U, 35U,
                51U, 59U, 49U, 57U, 56U, 48U, 58U, 50U,
                11U,  3U,  9U,  1U,  0U,  8U,  2U, 10U,
                12U,  4U, 14U,  6U,  7U, 15U,  5U, 13U,
                52U, 60U, 54U, 62U, 63U, 55U, 61U, 53U,
                37U, 45U, 39U, 47U, 46U, 38U, 44U, 36U,
                29U, 21U, 31U, 23U, 22U, 30U, 20U, 28U
    );
}

Recipe8x8 RecipeFactory8x8::MapleC() {
    //  AA AB AC AD AE AF AG AH      HG HB GD GE BE BD AB AG
    //  BA BB BC BD BE BF BG BH  ->  HH HA GC GF BF BC AA AH
    //  CA CB CC CD CE CF CG CH      FG FB ED EE DE DD CB CG
    //  DA DB DC DD DE DF DG DH      FH FA EC EF DF DC CA CH
    //  EA EB EC ED EE EF EG EH      EH EA FC FF CF CC DA DH
    //  FA FB FC FD FE FF FG FH      EG EB FD FE CE CD DB DG
    //  GA GB GC GD GE GF GG GH      GH GA HC HF AF AC BA BH
    //  HA HB HC HD HE HF HG HH      GG GB HD HE AE AD BB BG
    return Make("MapleC",
                62U, 57U, 51U, 52U, 12U, 11U,  1U,  6U,
                63U, 56U, 50U, 53U, 13U, 10U,  0U,  7U,
                46U, 41U, 35U, 36U, 28U, 27U, 17U, 22U,
                47U, 40U, 34U, 37U, 29U, 26U, 16U, 23U,
                39U, 32U, 42U, 45U, 21U, 18U, 24U, 31U,
                38U, 33U, 43U, 44U, 20U, 19U, 25U, 30U,
                55U, 48U, 58U, 61U,  5U,  2U,  8U, 15U,
                54U, 49U, 59U, 60U,  4U,  3U,  9U, 14U
    );
}

Recipe8x8 RecipeFactory8x8::MapleD() {
    //  AA AB AC AD AE AF AG AH      GB GG HE HD AD AE BG BB
    //  BA BB BC BD BE BF BG BH  ->  GA GH HF HC AC AF BH BA
    //  CA CB CC CD CE CF CG CH      EB EG FE FD CD CE DG DB
    //  DA DB DC DD DE DF DG DH      EA EH FF FC CC CF DH DA
    //  EA EB EC ED EE EF EG EH      FA FH EF EC DC DF CH CA
    //  FA FB FC FD FE FF FG FH      FB FG EE ED DD DE CG CB
    //  GA GB GC GD GE GF GG GH      HA HH GF GC BC BF AH AA
    //  HA HB HC HD HE HF HG HH      HB HG GE GD BD BE AG AB
    return Make("MapleD",
                49U, 54U, 60U, 59U,  3U,  4U, 14U,  9U,
                48U, 55U, 61U, 58U,  2U,  5U, 15U,  8U,
                33U, 38U, 44U, 43U, 19U, 20U, 30U, 25U,
                32U, 39U, 45U, 42U, 18U, 21U, 31U, 24U,
                40U, 47U, 37U, 34U, 26U, 29U, 23U, 16U,
                41U, 46U, 36U, 35U, 27U, 28U, 22U, 17U,
                56U, 63U, 53U, 50U, 10U, 13U,  7U,  0U,
                57U, 62U, 52U, 51U, 11U, 12U,  6U,  1U
    );
}

Recipe8x8 RecipeFactory8x8::WillowA() {
    //  AA AB AC AD AE AF AG AH      HG GG HE GE GF HF GH HH
    //  BA BB BC BD BE BF BG BH  ->  AG BG AE BE BF AF BH AH
    //  CA CB CC CD CE CF CG CH      CH DH CF DF DE CE DG CG
    //  DA DB DC DD DE DF DG DH      FH EH FF EF EE FE EG FG
    //  EA EB EC ED EE EF EG EH      FA EA FC EC ED FD EB FB
    //  FA FB FC FD FE FF FG FH      CA DA CC DC DD CD DB CB
    //  GA GB GC GD GE GF GG GH      AB BB AD BD BC AC BA AA
    //  HA HB HC HD HE HF HG HH      HB GB HD GD GC HC GA HA
    return Make("WillowA",
                62U, 54U, 60U, 52U, 53U, 61U, 55U, 63U,
                 6U, 14U,  4U, 12U, 13U,  5U, 15U,  7U,
                23U, 31U, 21U, 29U, 28U, 20U, 30U, 22U,
                47U, 39U, 45U, 37U, 36U, 44U, 38U, 46U,
                40U, 32U, 42U, 34U, 35U, 43U, 33U, 41U,
                16U, 24U, 18U, 26U, 27U, 19U, 25U, 17U,
                 1U,  9U,  3U, 11U, 10U,  2U,  8U,  0U,
                57U, 49U, 59U, 51U, 50U, 58U, 48U, 56U
    );
}

Recipe8x8 RecipeFactory8x8::WillowB() {
    //  AA AB AC AD AE AF AG AH      AH BH AF BF BE AE BG AG
    //  BA BB BC BD BE BF BG BH  ->  HH GH HF GF GE HE GG HG
    //  CA CB CC CD CE CF CG CH      FG EG FE EE EF FF EH FH
    //  DA DB DC DD DE DF DG DH      CG DG CE DE DF CF DH CH
    //  EA EB EC ED EE EF EG EH      CB DB CD DD DC CC DA CA
    //  FA FB FC FD FE FF FG FH      FB EB FD ED EC FC EA FA
    //  GA GB GC GD GE GF GG GH      HA GA HC GC GD HD GB HB
    //  HA HB HC HD HE HF HG HH      AA BA AC BC BD AD BB AB
    return Make("WillowB",
                 7U, 15U,  5U, 13U, 12U,  4U, 14U,  6U,
                63U, 55U, 61U, 53U, 52U, 60U, 54U, 62U,
                46U, 38U, 44U, 36U, 37U, 45U, 39U, 47U,
                22U, 30U, 20U, 28U, 29U, 21U, 31U, 23U,
                17U, 25U, 19U, 27U, 26U, 18U, 24U, 16U,
                41U, 33U, 43U, 35U, 34U, 42U, 32U, 40U,
                56U, 48U, 58U, 50U, 51U, 59U, 49U, 57U,
                 0U,  8U,  2U, 10U, 11U,  3U,  9U,  1U
    );
}

Recipe8x8 RecipeFactory8x8::WillowC() {
    //  AA AB AC AD AE AF AG AH      ED EE FG FB CB CG DE DD
    //  BA BB BC BD BE BF BG BH  ->  EC EF FH FA CA CH DF DC
    //  CA CB CC CD CE CF CG CH      GD GE HG HB AB AG BE BD
    //  DA DB DC DD DE DF DG DH      GC GF HH HA AA AH BF BC
    //  EA EB EC ED EE EF EG EH      HC HF GH GA BA BH AF AC
    //  FA FB FC FD FE FF FG FH      HD HE GG GB BB BG AE AD
    //  GA GB GC GD GE GF GG GH      FC FF EH EA DA DH CF CC
    //  HA HB HC HD HE HF HG HH      FD FE EG EB DB DG CE CD
    return Make("WillowC",
                35U, 36U, 46U, 41U, 17U, 22U, 28U, 27U,
                34U, 37U, 47U, 40U, 16U, 23U, 29U, 26U,
                51U, 52U, 62U, 57U,  1U,  6U, 12U, 11U,
                50U, 53U, 63U, 56U,  0U,  7U, 13U, 10U,
                58U, 61U, 55U, 48U,  8U, 15U,  5U,  2U,
                59U, 60U, 54U, 49U,  9U, 14U,  4U,  3U,
                42U, 45U, 39U, 32U, 24U, 31U, 21U, 18U,
                43U, 44U, 38U, 33U, 25U, 30U, 20U, 19U
    );
}

Recipe8x8 RecipeFactory8x8::WillowD() {
    //  AA AB AC AD AE AF AG AH      FE FD EB EG DG DB CD CE
    //  BA BB BC BD BE BF BG BH  ->  FF FC EA EH DH DA CC CF
    //  CA CB CC CD CE CF CG CH      HE HD GB GG BG BB AD AE
    //  DA DB DC DD DE DF DG DH      HF HC GA GH BH BA AC AF
    //  EA EB EC ED EE EF EG EH      GF GC HA HH AH AA BC BF
    //  FA FB FC FD FE FF FG FH      GE GD HB HG AG AB BD BE
    //  GA GB GC GD GE GF GG GH      EF EC FA FH CH CA DC DF
    //  HA HB HC HD HE HF HG HH      EE ED FB FG CG CB DD DE
    return Make("WillowD",
                44U, 43U, 33U, 38U, 30U, 25U, 19U, 20U,
                45U, 42U, 32U, 39U, 31U, 24U, 18U, 21U,
                60U, 59U, 49U, 54U, 14U,  9U,  3U,  4U,
                61U, 58U, 48U, 55U, 15U,  8U,  2U,  5U,
                53U, 50U, 56U, 63U,  7U,  0U, 10U, 13U,
                52U, 51U, 57U, 62U,  6U,  1U, 11U, 12U,
                37U, 34U, 40U, 47U, 23U, 16U, 26U, 29U,
                36U, 35U, 41U, 46U, 22U, 17U, 27U, 28U
    );
}

Recipe8x8 RecipeFactory8x8::BirchA() {
    //  AA AB AC AD AE AF AG AH      FB EB FD ED EC FC EA FA
    //  BA BB BC BD BE BF BG BH  ->  CB DB CD DD DC CC DA CA
    //  CA CB CC CD CE CF CG CH      AA BA AC BC BD AD BB AB
    //  DA DB DC DD DE DF DG DH      HA GA HC GC GD HD GB HB
    //  EA EB EC ED EE EF EG EH      HH GH HF GF GE HE GG HG
    //  FA FB FC FD FE FF FG FH      AH BH AF BF BE AE BG AG
    //  GA GB GC GD GE GF GG GH      CG DG CE DE DF CF DH CH
    //  HA HB HC HD HE HF HG HH      FG EG FE EE EF FF EH FH
    return Make("BirchA",
                41U, 33U, 43U, 35U, 34U, 42U, 32U, 40U,
                17U, 25U, 19U, 27U, 26U, 18U, 24U, 16U,
                 0U,  8U,  2U, 10U, 11U,  3U,  9U,  1U,
                56U, 48U, 58U, 50U, 51U, 59U, 49U, 57U,
                63U, 55U, 61U, 53U, 52U, 60U, 54U, 62U,
                 7U, 15U,  5U, 13U, 12U,  4U, 14U,  6U,
                22U, 30U, 20U, 28U, 29U, 21U, 31U, 23U,
                46U, 38U, 44U, 36U, 37U, 45U, 39U, 47U
    );
}

Recipe8x8 RecipeFactory8x8::BirchB() {
    //  AA AB AC AD AE AF AG AH      CA DA CC DC DD CD DB CB
    //  BA BB BC BD BE BF BG BH  ->  FA EA FC EC ED FD EB FB
    //  CA CB CC CD CE CF CG CH      HB GB HD GD GC HC GA HA
    //  DA DB DC DD DE DF DG DH      AB BB AD BD BC AC BA AA
    //  EA EB EC ED EE EF EG EH      AG BG AE BE BF AF BH AH
    //  FA FB FC FD FE FF FG FH      HG GG HE GE GF HF GH HH
    //  GA GB GC GD GE GF GG GH      FH EH FF EF EE FE EG FG
    //  HA HB HC HD HE HF HG HH      CH DH CF DF DE CE DG CG
    return Make("BirchB",
                16U, 24U, 18U, 26U, 27U, 19U, 25U, 17U,
                40U, 32U, 42U, 34U, 35U, 43U, 33U, 41U,
                57U, 49U, 59U, 51U, 50U, 58U, 48U, 56U,
                 1U,  9U,  3U, 11U, 10U,  2U,  8U,  0U,
                 6U, 14U,  4U, 12U, 13U,  5U, 15U,  7U,
                62U, 54U, 60U, 52U, 53U, 61U, 55U, 63U,
                47U, 39U, 45U, 37U, 36U, 44U, 38U, 46U,
                23U, 31U, 21U, 29U, 28U, 20U, 30U, 22U
    );
}

Recipe8x8 RecipeFactory8x8::BirchC() {
    //  AA AB AC AD AE AF AG AH      GE GD HB HG AG AB BD BE
    //  BA BB BC BD BE BF BG BH  ->  GF GC HA HH AH AA BC BF
    //  CA CB CC CD CE CF CG CH      EE ED FB FG CG CB DD DE
    //  DA DB DC DD DE DF DG DH      EF EC FA FH CH CA DC DF
    //  EA EB EC ED EE EF EG EH      FF FC EA EH DH DA CC CF
    //  FA FB FC FD FE FF FG FH      FE FD EB EG DG DB CD CE
    //  GA GB GC GD GE GF GG GH      HF HC GA GH BH BA AC AF
    //  HA HB HC HD HE HF HG HH      HE HD GB GG BG BB AD AE
    return Make("BirchC",
                52U, 51U, 57U, 62U,  6U,  1U, 11U, 12U,
                53U, 50U, 56U, 63U,  7U,  0U, 10U, 13U,
                36U, 35U, 41U, 46U, 22U, 17U, 27U, 28U,
                37U, 34U, 40U, 47U, 23U, 16U, 26U, 29U,
                45U, 42U, 32U, 39U, 31U, 24U, 18U, 21U,
                44U, 43U, 33U, 38U, 30U, 25U, 19U, 20U,
                61U, 58U, 48U, 55U, 15U,  8U,  2U,  5U,
                60U, 59U, 49U, 54U, 14U,  9U,  3U,  4U
    );
}

Recipe8x8 RecipeFactory8x8::BirchD() {
    //  AA AB AC AD AE AF AG AH      HD HE GG GB BB BG AE AD
    //  BA BB BC BD BE BF BG BH  ->  HC HF GH GA BA BH AF AC
    //  CA CB CC CD CE CF CG CH      FD FE EG EB DB DG CE CD
    //  DA DB DC DD DE DF DG DH      FC FF EH EA DA DH CF CC
    //  EA EB EC ED EE EF EG EH      EC EF FH FA CA CH DF DC
    //  FA FB FC FD FE FF FG FH      ED EE FG FB CB CG DE DD
    //  GA GB GC GD GE GF GG GH      GC GF HH HA AA AH BF BC
    //  HA HB HC HD HE HF HG HH      GD GE HG HB AB AG BE BD
    return Make("BirchD",
                59U, 60U, 54U, 49U,  9U, 14U,  4U,  3U,
                58U, 61U, 55U, 48U,  8U, 15U,  5U,  2U,
                43U, 44U, 38U, 33U, 25U, 30U, 20U, 19U,
                42U, 45U, 39U, 32U, 24U, 31U, 21U, 18U,
                34U, 37U, 47U, 40U, 16U, 23U, 29U, 26U,
                35U, 36U, 46U, 41U, 17U, 22U, 28U, 27U,
                50U, 53U, 63U, 56U,  0U,  7U, 13U, 10U,
                51U, 52U, 62U, 57U,  1U,  6U, 12U, 11U
    );
}

Recipe8x8 RecipeFactory8x8::CedarA() {
    //  AA AB AC AD AE AF AG AH      EF FF EH FH FG EG FE EE
    //  BA BB BC BD BE BF BG BH  ->  DF CF DH CH CG DG CE DE
    //  CA CB CC CD CE CF CG CH      BE AE BG AG AH BH AF BF
    //  DA DB DC DD DE DF DG DH      GE HE GG HG HH GH HF GF
    //  EA EB EC ED EE EF EG EH      GD HD GB HB HA GA HC GC
    //  FA FB FC FD FE FF FG FH      BD AD BB AB AA BA AC BC
    //  GA GB GC GD GE GF GG GH      DC CC DA CA CB DB CD DD
    //  HA HB HC HD HE HF HG HH      EC FC EA FA FB EB FD ED
    return Make("CedarA",
                37U, 45U, 39U, 47U, 46U, 38U, 44U, 36U,
                29U, 21U, 31U, 23U, 22U, 30U, 20U, 28U,
                12U,  4U, 14U,  6U,  7U, 15U,  5U, 13U,
                52U, 60U, 54U, 62U, 63U, 55U, 61U, 53U,
                51U, 59U, 49U, 57U, 56U, 48U, 58U, 50U,
                11U,  3U,  9U,  1U,  0U,  8U,  2U, 10U,
                26U, 18U, 24U, 16U, 17U, 25U, 19U, 27U,
                34U, 42U, 32U, 40U, 41U, 33U, 43U, 35U
    );
}

Recipe8x8 RecipeFactory8x8::CedarB() {
    //  AA AB AC AD AE AF AG AH      DE CE DG CG CH DH CF DF
    //  BA BB BC BD BE BF BG BH  ->  EE FE EG FG FH EH FF EF
    //  CA CB CC CD CE CF CG CH      GF HF GH HH HG GG HE GE
    //  DA DB DC DD DE DF DG DH      BF AF BH AH AG BG AE BE
    //  EA EB EC ED EE EF EG EH      BC AC BA AA AB BB AD BD
    //  FA FB FC FD FE FF FG FH      GC HC GA HA HB GB HD GD
    //  GA GB GC GD GE GF GG GH      ED FD EB FB FA EA FC EC
    //  HA HB HC HD HE HF HG HH      DD CD DB CB CA DA CC DC
    return Make("CedarB",
                28U, 20U, 30U, 22U, 23U, 31U, 21U, 29U,
                36U, 44U, 38U, 46U, 47U, 39U, 45U, 37U,
                53U, 61U, 55U, 63U, 62U, 54U, 60U, 52U,
                13U,  5U, 15U,  7U,  6U, 14U,  4U, 12U,
                10U,  2U,  8U,  0U,  1U,  9U,  3U, 11U,
                50U, 58U, 48U, 56U, 57U, 49U, 59U, 51U,
                35U, 43U, 33U, 41U, 40U, 32U, 42U, 34U,
                27U, 19U, 25U, 17U, 16U, 24U, 18U, 26U
    );
}

Recipe8x8 RecipeFactory8x8::CedarC() {
    //  AA AB AC AD AE AF AG AH      HB HG GE GD BD BE AG AB
    //  BA BB BC BD BE BF BG BH  ->  HA HH GF GC BC BF AH AA
    //  CA CB CC CD CE CF CG CH      FB FG EE ED DD DE CG CB
    //  DA DB DC DD DE DF DG DH      FA FH EF EC DC DF CH CA
    //  EA EB EC ED EE EF EG EH      EA EH FF FC CC CF DH DA
    //  FA FB FC FD FE FF FG FH      EB EG FE FD CD CE DG DB
    //  GA GB GC GD GE GF GG GH      GA GH HF HC AC AF BH BA
    //  HA HB HC HD HE HF HG HH      GB GG HE HD AD AE BG BB
    return Make("CedarC",
                57U, 62U, 52U, 51U, 11U, 12U,  6U,  1U,
                56U, 63U, 53U, 50U, 10U, 13U,  7U,  0U,
                41U, 46U, 36U, 35U, 27U, 28U, 22U, 17U,
                40U, 47U, 37U, 34U, 26U, 29U, 23U, 16U,
                32U, 39U, 45U, 42U, 18U, 21U, 31U, 24U,
                33U, 38U, 44U, 43U, 19U, 20U, 30U, 25U,
                48U, 55U, 61U, 58U,  2U,  5U, 15U,  8U,
                49U, 54U, 60U, 59U,  3U,  4U, 14U,  9U
    );
}

Recipe8x8 RecipeFactory8x8::CedarD() {
    //  AA AB AC AD AE AF AG AH      GG GB HD HE AE AD BB BG
    //  BA BB BC BD BE BF BG BH  ->  GH GA HC HF AF AC BA BH
    //  CA CB CC CD CE CF CG CH      EG EB FD FE CE CD DB DG
    //  DA DB DC DD DE DF DG DH      EH EA FC FF CF CC DA DH
    //  EA EB EC ED EE EF EG EH      FH FA EC EF DF DC CA CH
    //  FA FB FC FD FE FF FG FH      FG FB ED EE DE DD CB CG
    //  GA GB GC GD GE GF GG GH      HH HA GC GF BF BC AA AH
    //  HA HB HC HD HE HF HG HH      HG HB GD GE BE BD AB AG
    return Make("CedarD",
                54U, 49U, 59U, 60U,  4U,  3U,  9U, 14U,
                55U, 48U, 58U, 61U,  5U,  2U,  8U, 15U,
                38U, 33U, 43U, 44U, 20U, 19U, 25U, 30U,
                39U, 32U, 42U, 45U, 21U, 18U, 24U, 31U,
                47U, 40U, 34U, 37U, 29U, 26U, 16U, 23U,
                46U, 41U, 35U, 36U, 28U, 27U, 17U, 22U,
                63U, 56U, 50U, 53U, 13U, 10U,  0U,  7U,
                62U, 57U, 51U, 52U, 12U, 11U,  1U,  6U
    );
}

Recipe8x8 RecipeFactory8x8::HickoryA() {
    //  AA AB AC AD AE AF AG AH      HH HG FH FG EE EF GE GF
    //  BA BB BC BD BE BF BG BH  ->  HE HF FE FF ED EC GD GC
    //  CA CB CC CD CE CF CG CH      GA GB EA EB FD FC HD HC
    //  DA DB DC DD DE DF DG DH      GH GG EH EG FA FB HA HB
    //  EA EB EC ED EE EF EG EH      BB BA DB DA CG CH AG AH
    //  FA FB FC FD FE FF FG FH      BC BD DC DD CB CA AB AA
    //  GA GB GC GD GE GF GG GH      AC AD CC CD DF DE BF BE
    //  HA HB HC HD HE HF HG HH      AF AE CF CE DG DH BG BH
    return Make("HickoryA",
                63U, 62U, 47U, 46U, 36U, 37U, 52U, 53U,
                60U, 61U, 44U, 45U, 35U, 34U, 51U, 50U,
                48U, 49U, 32U, 33U, 43U, 42U, 59U, 58U,
                55U, 54U, 39U, 38U, 40U, 41U, 56U, 57U,
                 9U,  8U, 25U, 24U, 22U, 23U,  6U,  7U,
                10U, 11U, 26U, 27U, 17U, 16U,  1U,  0U,
                 2U,  3U, 18U, 19U, 29U, 28U, 13U, 12U,
                 5U,  4U, 21U, 20U, 30U, 31U, 14U, 15U
    );
}

Recipe8x8 RecipeFactory8x8::HickoryB() {
    //  AA AB AC AD AE AF AG AH      GC GD EC ED FF FE HF HE
    //  BA BB BC BD BE BF BG BH  ->  GF GE EF EE FG FH HG HH
    //  CA CB CC CD CE CF CG CH      HB HA FB FA EG EH GG GH
    //  DA DB DC DD DE DF DG DH      HC HD FC FD EB EA GB GA
    //  EA EB EC ED EE EF EG EH      AA AB CA CB DD DC BD BC
    //  FA FB FC FD FE FF FG FH      AH AG CH CG DA DB BA BB
    //  GA GB GC GD GE GF GG GH      BH BG DH DG CE CF AE AF
    //  HA HB HC HD HE HF HG HH      BE BF DE DF CD CC AD AC
    return Make("HickoryB",
                50U, 51U, 34U, 35U, 45U, 44U, 61U, 60U,
                53U, 52U, 37U, 36U, 46U, 47U, 62U, 63U,
                57U, 56U, 41U, 40U, 38U, 39U, 54U, 55U,
                58U, 59U, 42U, 43U, 33U, 32U, 49U, 48U,
                 0U,  1U, 16U, 17U, 27U, 26U, 11U, 10U,
                 7U,  6U, 23U, 22U, 24U, 25U,  8U,  9U,
                15U, 14U, 31U, 30U, 20U, 21U,  4U,  5U,
                12U, 13U, 28U, 29U, 19U, 18U,  3U,  2U
    );
}

Recipe8x8 RecipeFactory8x8::HickoryC() {
    //  AA AB AC AD AE AF AG AH      CG FA HB AH AA HC FD CB
    //  BA BB BC BD BE BF BG BH  ->  DA EG GH BB BC GA EB DD
    //  CA CB CC CD CE CF CG CH      CE FG HH AF AC HE FF CD
    //  DA DB DC DD DE DF DG DH      DG EE GF BH BE GC ED DF
    //  EA EB EC ED EE EF EG EH      DH EF GE BG BF GD EC DE
    //  FA FB FC FD FE FF FG FH      CF FH HG AE AD HF FE CC
    //  GA GB GC GD GE GF GG GH      DB EH GG BA BD GB EA DC
    //  HA HB HC HD HE HF HG HH      CH FB HA AG AB HD FC CA
    return Make("HickoryC",
                22U, 40U, 57U,  7U,  0U, 58U, 43U, 17U,
                24U, 38U, 55U,  9U, 10U, 48U, 33U, 27U,
                20U, 46U, 63U,  5U,  2U, 60U, 45U, 19U,
                30U, 36U, 53U, 15U, 12U, 50U, 35U, 29U,
                31U, 37U, 52U, 14U, 13U, 51U, 34U, 28U,
                21U, 47U, 62U,  4U,  3U, 61U, 44U, 18U,
                25U, 39U, 54U,  8U, 11U, 49U, 32U, 26U,
                23U, 41U, 56U,  6U,  1U, 59U, 42U, 16U
    );
}

Recipe8x8 RecipeFactory8x8::HickoryD() {
    //  AA AB AC AD AE AF AG AH      FB CH AG HA HD AB CA FC
    //  BA BB BC BD BE BF BG BH  ->  EH DB BA GG GB BD DC EA
    //  CA CB CC CD CE CF CG CH      FH CF AE HG HF AD CC FE
    //  DA DB DC DD DE DF DG DH      EF DH BG GE GD BF DE EC
    //  EA EB EC ED EE EF EG EH      EE DG BH GF GC BE DF ED
    //  FA FB FC FD FE FF FG FH      FG CE AF HH HE AC CD FF
    //  GA GB GC GD GE GF GG GH      EG DA BB GH GA BC DD EB
    //  HA HB HC HD HE HF HG HH      FA CG AH HB HC AA CB FD
    return Make("HickoryD",
                41U, 23U,  6U, 56U, 59U,  1U, 16U, 42U,
                39U, 25U,  8U, 54U, 49U, 11U, 26U, 32U,
                47U, 21U,  4U, 62U, 61U,  3U, 18U, 44U,
                37U, 31U, 14U, 52U, 51U, 13U, 28U, 34U,
                36U, 30U, 15U, 53U, 50U, 12U, 29U, 35U,
                46U, 20U,  5U, 63U, 60U,  2U, 19U, 45U,
                38U, 24U,  9U, 55U, 48U, 10U, 27U, 33U,
                40U, 22U,  7U, 57U, 58U,  0U, 17U, 43U
    );
}

Recipe8x8 RecipeFactory8x8::JuniperA() {
    //  AA AB AC AD AE AF AG AH      BB DA DB FA EA CB CA AB
    //  BA BB BC BD BE BF BG BH  ->  DG BH FG DH CH EG AH CG
    //  CA CB CC CD CE CF CG CH      CE AF EE CF DF FE BF DE
    //  DA DB DC DD DE DF DG DH      AD CC CD EC FC DD DC BD
    //  EA EB EC ED EE EF EG EH      HD BC FD HC GC ED AC GD
    //  FA FB FC FD FE FF FG FH      BE HF HE FF EF GE GF AE
    //  GA GB GC GD GE GF GG GH      AG GH GG EH FH HG HH BG
    //  HA HB HC HD HE HF HG HH      GB AA EB GA HA FB BA HB
    return Make("JuniperA",
                 9U, 24U, 25U, 40U, 32U, 17U, 16U,  1U,
                30U, 15U, 46U, 31U, 23U, 38U,  7U, 22U,
                20U,  5U, 36U, 21U, 29U, 44U, 13U, 28U,
                 3U, 18U, 19U, 34U, 42U, 27U, 26U, 11U,
                59U, 10U, 43U, 58U, 50U, 35U,  2U, 51U,
                12U, 61U, 60U, 45U, 37U, 52U, 53U,  4U,
                 6U, 55U, 54U, 39U, 47U, 62U, 63U, 14U,
                49U,  0U, 33U, 48U, 56U, 41U,  8U, 57U
    );
}

Recipe8x8 RecipeFactory8x8::JuniperB() {
    //  AA AB AC AD AE AF AG AH      CG AH EG CH DH FG BH DG
    //  BA BB BC BD BE BF BG BH  ->  AB CA CB EA FA DB DA BB
    //  CA CB CC CD CE CF CG CH      BD DC DD FC EC CD CC AD
    //  DA DB DC DD DE DF DG DH      DE BF FE DF CF EE AF CE
    //  EA EB EC ED EE EF EG EH      AE GF GE EF FF HE HF BE
    //  FA FB FC FD FE FF FG FH      GD AC ED GC HC FD BC HD
    //  GA GB GC GD GE GF GG GH      HB BA FB HA GA EB AA GB
    //  HA HB HC HD HE HF HG HH      BG HH HG FH EH GG GH AG
    return Make("JuniperB",
                22U,  7U, 38U, 23U, 31U, 46U, 15U, 30U,
                 1U, 16U, 17U, 32U, 40U, 25U, 24U,  9U,
                11U, 26U, 27U, 42U, 34U, 19U, 18U,  3U,
                28U, 13U, 44U, 29U, 21U, 36U,  5U, 20U,
                 4U, 53U, 52U, 37U, 45U, 60U, 61U, 12U,
                51U,  2U, 35U, 50U, 58U, 43U, 10U, 59U,
                57U,  8U, 41U, 56U, 48U, 33U,  0U, 49U,
                14U, 63U, 62U, 47U, 39U, 54U, 55U,  6U
    );
}

Recipe8x8 RecipeFactory8x8::JuniperC() {
    //  AA AB AC AD AE AF AG AH      GC FC BD GD AE DE DF EF
    //  BA BB BC BD BE BF BG BH  ->  HC EC AD HD BE CE CF FF
    //  CA CB CC CD CE CF CG CH      GA FA BB GB AG DG DH EH
    //  DA DB DC DD DE DF DG DH      HA EA AB HB BG CG CH FH
    //  EA EB EC ED EE EF EG EH      FB CB CA BA HH AH EG HG
    //  FA FB FC FD FE FF FG FH      EB DB DA AA GH BH FG GG
    //  GA GB GC GD GE GF GG GH      FD CD CC BC HF AF EE HE
    //  HA HB HC HD HE HF HG HH      ED DD DC AC GF BF FE GE
    return Make("JuniperC",
                50U, 42U, 11U, 51U,  4U, 28U, 29U, 37U,
                58U, 34U,  3U, 59U, 12U, 20U, 21U, 45U,
                48U, 40U,  9U, 49U,  6U, 30U, 31U, 39U,
                56U, 32U,  1U, 57U, 14U, 22U, 23U, 47U,
                41U, 17U, 16U,  8U, 63U,  7U, 38U, 62U,
                33U, 25U, 24U,  0U, 55U, 15U, 46U, 54U,
                43U, 19U, 18U, 10U, 61U,  5U, 36U, 60U,
                35U, 27U, 26U,  2U, 53U, 13U, 44U, 52U
    );
}

Recipe8x8 RecipeFactory8x8::JuniperD() {
    //  AA AB AC AD AE AF AG AH      DD ED AC DC BF GF GE FE
    //  BA BB BC BD BE BF BG BH  ->  CD FD BC CC AF HF HE EE
    //  CA CB CC CD CE CF CG CH      DB EB AA DA BH GH GG FG
    //  DA DB DC DD DE DF DG DH      CB FB BA CA AH HH HG EG
    //  EA EB EC ED EE EF EG EH      EA HA HB AB CG BG FH CH
    //  FA FB FC FD FE FF FG FH      FA GA GB BB DG AG EH DH
    //  GA GB GC GD GE GF GG GH      EC HC HD AD CE BE FF CF
    //  HA HB HC HD HE HF HG HH      FC GC GD BD DE AE EF DF
    return Make("JuniperD",
                27U, 35U,  2U, 26U, 13U, 53U, 52U, 44U,
                19U, 43U, 10U, 18U,  5U, 61U, 60U, 36U,
                25U, 33U,  0U, 24U, 15U, 55U, 54U, 46U,
                17U, 41U,  8U, 16U,  7U, 63U, 62U, 38U,
                32U, 56U, 57U,  1U, 22U, 14U, 47U, 23U,
                40U, 48U, 49U,  9U, 30U,  6U, 39U, 31U,
                34U, 58U, 59U,  3U, 20U, 12U, 45U, 21U,
                42U, 50U, 51U, 11U, 28U,  4U, 37U, 29U
    );
}

Recipe8x8 RecipeFactory8x8::YorkA() {
    //  AA AB AC AD AE AF AG AH      AG EA GG EC GE CC AE CA
    //  BA BB BC BD BE BF BG BH  ->  AH EB GH ED GF CD AF CB
    //  CA CB CC CD CE CF CG CH      CG GA EG GC EE AC CE AA
    //  DA DB DC DD DE DF DG DH      CH GB EH GD EF AD CF AB
    //  EA EB EC ED EE EF EG EH      HG FA HE FC BE DC BG DA
    //  FA FB FC FD FE FF FG FH      HH FB HF FD BF DD BH DB
    //  GA GB GC GD GE GF GG GH      FG HA FE HC DE BC DG BA
    //  HA HB HC HD HE HF HG HH      FH HB FF HD DF BD DH BB
    return Make("YorkA",
                 6U, 32U, 54U, 34U, 52U, 18U,  4U, 16U,
                 7U, 33U, 55U, 35U, 53U, 19U,  5U, 17U,
                22U, 48U, 38U, 50U, 36U,  2U, 20U,  0U,
                23U, 49U, 39U, 51U, 37U,  3U, 21U,  1U,
                62U, 40U, 60U, 42U, 12U, 26U, 14U, 24U,
                63U, 41U, 61U, 43U, 13U, 27U, 15U, 25U,
                46U, 56U, 44U, 58U, 28U, 10U, 30U,  8U,
                47U, 57U, 45U, 59U, 29U, 11U, 31U,  9U
    );
}

Recipe8x8 RecipeFactory8x8::YorkB() {
    //  AA AB AC AD AE AF AG AH      FA HG FC HE DC BE DA BG
    //  BA BB BC BD BE BF BG BH  ->  FB HH FD HF DD BF DB BH
    //  CA CB CC CD CE CF CG CH      HA FG HC FE BC DE BA DG
    //  DA DB DC DD DE DF DG DH      HB FH HD FF BD DF BB DH
    //  EA EB EC ED EE EF EG EH      CA GG EA GE EC AE CC AG
    //  FA FB FC FD FE FF FG FH      CB GH EB GF ED AF CD AH
    //  GA GB GC GD GE GF GG GH      AA EG GA EE GC CE AC CG
    //  HA HB HC HD HE HF HG HH      AB EH GB EF GD CF AD CH
    return Make("YorkB",
                40U, 62U, 42U, 60U, 26U, 12U, 24U, 14U,
                41U, 63U, 43U, 61U, 27U, 13U, 25U, 15U,
                56U, 46U, 58U, 44U, 10U, 28U,  8U, 30U,
                57U, 47U, 59U, 45U, 11U, 29U,  9U, 31U,
                16U, 54U, 32U, 52U, 34U,  4U, 18U,  6U,
                17U, 55U, 33U, 53U, 35U,  5U, 19U,  7U,
                 0U, 38U, 48U, 36U, 50U, 20U,  2U, 22U,
                 1U, 39U, 49U, 37U, 51U, 21U,  3U, 23U
    );
}

Recipe8x8 RecipeFactory8x8::YorkC() {
    //  AA AB AC AD AE AF AG AH      GG EA GE EC AE CC AG CA
    //  BA BB BC BD BE BF BG BH  ->  GH EB GF ED AF CD AH CB
    //  CA CB CC CD CE CF CG CH      EG GA EE GC CE AC CG AA
    //  DA DB DC DD DE DF DG DH      EH GB EF GD CF AD CH AB
    //  EA EB EC ED EE EF EG EH      HG FC HE DC BE DA BG FA
    //  FA FB FC FD FE FF FG FH      HH FD HF DD BF DB BH FB
    //  GA GB GC GD GE GF GG GH      FG HC FE BC DE BA DG HA
    //  HA HB HC HD HE HF HG HH      FH HD FF BD DF BB DH HB
    return Make("YorkC",
                54U, 32U, 52U, 34U,  4U, 18U,  6U, 16U,
                55U, 33U, 53U, 35U,  5U, 19U,  7U, 17U,
                38U, 48U, 36U, 50U, 20U,  2U, 22U,  0U,
                39U, 49U, 37U, 51U, 21U,  3U, 23U,  1U,
                62U, 42U, 60U, 26U, 12U, 24U, 14U, 40U,
                63U, 43U, 61U, 27U, 13U, 25U, 15U, 41U,
                46U, 58U, 44U, 10U, 28U,  8U, 30U, 56U,
                47U, 59U, 45U, 11U, 29U,  9U, 31U, 57U
    );
}

Recipe8x8 RecipeFactory8x8::YorkD() {
    //  AA AB AC AD AE AF AG AH      FA HE FC BE DC BG DA HG
    //  BA BB BC BD BE BF BG BH  ->  FB HF FD BF DD BH DB HH
    //  CA CB CC CD CE CF CG CH      HA FE HC DE BC DG BA FG
    //  DA DB DC DD DE DF DG DH      HB FF HD DF BD DH BB FH
    //  EA EB EC ED EE EF EG EH      EA GG EC GE CC AE CA AG
    //  FA FB FC FD FE FF FG FH      EB GH ED GF CD AF CB AH
    //  GA GB GC GD GE GF GG GH      GA EG GC EE AC CE AA CG
    //  HA HB HC HD HE HF HG HH      GB EH GD EF AD CF AB CH
    return Make("YorkD",
                40U, 60U, 42U, 12U, 26U, 14U, 24U, 62U,
                41U, 61U, 43U, 13U, 27U, 15U, 25U, 63U,
                56U, 44U, 58U, 28U, 10U, 30U,  8U, 46U,
                57U, 45U, 59U, 29U, 11U, 31U,  9U, 47U,
                32U, 54U, 34U, 52U, 18U,  4U, 16U,  6U,
                33U, 55U, 35U, 53U, 19U,  5U, 17U,  7U,
                48U, 38U, 50U, 36U,  2U, 20U,  0U, 22U,
                49U, 39U, 51U, 37U,  3U, 21U,  1U, 23U
    );
}

Recipe8x8 RecipeFactory8x8::EssexA() {
    //  AA AB AC AD AE AF AG AH      CE AC CG AA EG GA EE GC
    //  BA BB BC BD BE BF BG BH  ->  CF AD CH AB EH GB EF GD
    //  CA CB CC CD CE CF CG CH      AE CC AG CA GG EA GE EC
    //  DA DB DC DD DE DF DG DH      AF CD AH CB GH EB GF ED
    //  EA EB EC ED EE EF EG EH      DE BA DG HA FG HC FE BC
    //  FA FB FC FD FE FF FG FH      DF BB DH HB FH HD FF BD
    //  GA GB GC GD GE GF GG GH      BE DA BG FA HG FC HE DC
    //  HA HB HC HD HE HF HG HH      BF DB BH FB HH FD HF DD
    return Make("EssexA",
                20U,  2U, 22U,  0U, 38U, 48U, 36U, 50U,
                21U,  3U, 23U,  1U, 39U, 49U, 37U, 51U,
                 4U, 18U,  6U, 16U, 54U, 32U, 52U, 34U,
                 5U, 19U,  7U, 17U, 55U, 33U, 53U, 35U,
                28U,  8U, 30U, 56U, 46U, 58U, 44U, 10U,
                29U,  9U, 31U, 57U, 47U, 59U, 45U, 11U,
                12U, 24U, 14U, 40U, 62U, 42U, 60U, 26U,
                13U, 25U, 15U, 41U, 63U, 43U, 61U, 27U
    );
}

Recipe8x8 RecipeFactory8x8::EssexB() {
    //  AA AB AC AD AE AF AG AH      GF ED GH EB AH CB AF CD
    //  BA BB BC BD BE BF BG BH  ->  GE EC GG EA AG CA AE CC
    //  CA CB CC CD CE CF CG CH      EF GD EH GB CH AB CF AD
    //  DA DB DC DD DE DF DG DH      EE GC EG GA CG AA CE AC
    //  EA EB EC ED EE EF EG EH      BF FD HF FB HH DB BH DD
    //  FA FB FC FD FE FF FG FH      BE FC HE FA HG DA BG DC
    //  GA GB GC GD GE GF GG GH      DF HD FF HB FH BB DH BD
    //  HA HB HC HD HE HF HG HH      DE HC FE HA FG BA DG BC
    return Make("EssexB",
                53U, 35U, 55U, 33U,  7U, 17U,  5U, 19U,
                52U, 34U, 54U, 32U,  6U, 16U,  4U, 18U,
                37U, 51U, 39U, 49U, 23U,  1U, 21U,  3U,
                36U, 50U, 38U, 48U, 22U,  0U, 20U,  2U,
                13U, 43U, 61U, 41U, 63U, 25U, 15U, 27U,
                12U, 42U, 60U, 40U, 62U, 24U, 14U, 26U,
                29U, 59U, 45U, 57U, 47U,  9U, 31U, 11U,
                28U, 58U, 44U, 56U, 46U,  8U, 30U, 10U
    );
}

Recipe8x8 RecipeFactory8x8::EssexC() {
    //  AA AB AC AD AE AF AG AH      FD HF FB HH DB BH DD BF
    //  BA BB BC BD BE BF BG BH  ->  FC HE FA HG DA BG DC BE
    //  CA CB CC CD CE CF CG CH      HD FF HB FH BB DH BD DF
    //  DA DB DC DD DE DF DG DH      HC FE HA FG BA DG BC DE
    //  EA EB EC ED EE EF EG EH      ED GH EB AH CB AF CD GF
    //  FA FB FC FD FE FF FG FH      EC GG EA AG CA AE CC GE
    //  GA GB GC GD GE GF GG GH      GD EH GB CH AB CF AD EF
    //  HA HB HC HD HE HF HG HH      GC EG GA CG AA CE AC EE
    return Make("EssexC",
                43U, 61U, 41U, 63U, 25U, 15U, 27U, 13U,
                42U, 60U, 40U, 62U, 24U, 14U, 26U, 12U,
                59U, 45U, 57U, 47U,  9U, 31U, 11U, 29U,
                58U, 44U, 56U, 46U,  8U, 30U, 10U, 28U,
                35U, 55U, 33U,  7U, 17U,  5U, 19U, 53U,
                34U, 54U, 32U,  6U, 16U,  4U, 18U, 52U,
                51U, 39U, 49U, 23U,  1U, 21U,  3U, 37U,
                50U, 38U, 48U, 22U,  0U, 20U,  2U, 36U
    );
}

Recipe8x8 RecipeFactory8x8::EssexD() {
    //  AA AB AC AD AE AF AG AH      GF EB GH CB AH CD AF ED
    //  BA BB BC BD BE BF BG BH  ->  GE EA GG CA AG CC AE EC
    //  CA CB CC CD CE CF CG CH      EF GB EH AB CH AD CF GD
    //  DA DB DC DD DE DF DG DH      EE GA EG AA CG AC CE GC
    //  EA EB EC ED EE EF EG EH      HF FD HH FB BH DB BF DD
    //  FA FB FC FD FE FF FG FH      HE FC HG FA BG DA BE DC
    //  GA GB GC GD GE GF GG GH      FF HD FH HB DH BB DF BD
    //  HA HB HC HD HE HF HG HH      FE HC FG HA DG BA DE BC
    return Make("EssexD",
                53U, 33U, 55U, 17U,  7U, 19U,  5U, 35U,
                52U, 32U, 54U, 16U,  6U, 18U,  4U, 34U,
                37U, 49U, 39U,  1U, 23U,  3U, 21U, 51U,
                36U, 48U, 38U,  0U, 22U,  2U, 20U, 50U,
                61U, 43U, 63U, 41U, 15U, 25U, 13U, 27U,
                60U, 42U, 62U, 40U, 14U, 24U, 12U, 26U,
                45U, 59U, 47U, 57U, 31U,  9U, 29U, 11U,
                44U, 58U, 46U, 56U, 30U,  8U, 28U, 10U
    );
}

Recipe8x8 RecipeFactory8x8::WessexA() {
    //  AA AB AC AD AE AF AG AH      BE FC HE FA HG DA BG DC
    //  BA BB BC BD BE BF BG BH  ->  BF FD HF FB HH DB BH DD
    //  CA CB CC CD CE CF CG CH      DE HC FE HA FG BA DG BC
    //  DA DB DC DD DE DF DG DH      DF HD FF HB FH BB DH BD
    //  EA EB EC ED EE EF EG EH      GE EC GG EA AG CA AE CC
    //  FA FB FC FD FE FF FG FH      GF ED GH EB AH CB AF CD
    //  GA GB GC GD GE GF GG GH      EE GC EG GA CG AA CE AC
    //  HA HB HC HD HE HF HG HH      EF GD EH GB CH AB CF AD
    return Make("WessexA",
                12U, 42U, 60U, 40U, 62U, 24U, 14U, 26U,
                13U, 43U, 61U, 41U, 63U, 25U, 15U, 27U,
                28U, 58U, 44U, 56U, 46U,  8U, 30U, 10U,
                29U, 59U, 45U, 57U, 47U,  9U, 31U, 11U,
                52U, 34U, 54U, 32U,  6U, 16U,  4U, 18U,
                53U, 35U, 55U, 33U,  7U, 17U,  5U, 19U,
                36U, 50U, 38U, 48U, 22U,  0U, 20U,  2U,
                37U, 51U, 39U, 49U, 23U,  1U, 21U,  3U
    );
}

Recipe8x8 RecipeFactory8x8::WessexB() {
    //  AA AB AC AD AE AF AG AH      EC GE EA GG CA AG CC AE
    //  BA BB BC BD BE BF BG BH  ->  ED GF EB GH CB AH CD AF
    //  CA CB CC CD CE CF CG CH      GC EE GA EG AA CG AC CE
    //  DA DB DC DD DE DF DG DH      GD EF GB EH AB CH AD CF
    //  EA EB EC ED EE EF EG EH      DC HE FC HG FA BG DA BE
    //  FA FB FC FD FE FF FG FH      DD HF FD HH FB BH DB BF
    //  GA GB GC GD GE GF GG GH      BC FE HC FG HA DG BA DE
    //  HA HB HC HD HE HF HG HH      BD FF HD FH HB DH BB DF
    return Make("WessexB",
                34U, 52U, 32U, 54U, 16U,  6U, 18U,  4U,
                35U, 53U, 33U, 55U, 17U,  7U, 19U,  5U,
                50U, 36U, 48U, 38U,  0U, 22U,  2U, 20U,
                51U, 37U, 49U, 39U,  1U, 23U,  3U, 21U,
                26U, 60U, 42U, 62U, 40U, 14U, 24U, 12U,
                27U, 61U, 43U, 63U, 41U, 15U, 25U, 13U,
                10U, 44U, 58U, 46U, 56U, 30U,  8U, 28U,
                11U, 45U, 59U, 47U, 57U, 31U,  9U, 29U
    );
}

Recipe8x8 RecipeFactory8x8::WessexC() {
    //  AA AB AC AD AE AF AG AH      HE FC HG FA BG DA BE DC
    //  BA BB BC BD BE BF BG BH  ->  HF FD HH FB BH DB BF DD
    //  CA CB CC CD CE CF CG CH      FE HC FG HA DG BA DE BC
    //  DA DB DC DD DE DF DG DH      FF HD FH HB DH BB DF BD
    //  EA EB EC ED EE EF EG EH      GE EA GG CA AG CC AE EC
    //  FA FB FC FD FE FF FG FH      GF EB GH CB AH CD AF ED
    //  GA GB GC GD GE GF GG GH      EE GA EG AA CG AC CE GC
    //  HA HB HC HD HE HF HG HH      EF GB EH AB CH AD CF GD
    return Make("WessexC",
                60U, 42U, 62U, 40U, 14U, 24U, 12U, 26U,
                61U, 43U, 63U, 41U, 15U, 25U, 13U, 27U,
                44U, 58U, 46U, 56U, 30U,  8U, 28U, 10U,
                45U, 59U, 47U, 57U, 31U,  9U, 29U, 11U,
                52U, 32U, 54U, 16U,  6U, 18U,  4U, 34U,
                53U, 33U, 55U, 17U,  7U, 19U,  5U, 35U,
                36U, 48U, 38U,  0U, 22U,  2U, 20U, 50U,
                37U, 49U, 39U,  1U, 23U,  3U, 21U, 51U
    );
}

Recipe8x8 RecipeFactory8x8::WessexD() {
    //  AA AB AC AD AE AF AG AH      EC GG EA AG CA AE CC GE
    //  BA BB BC BD BE BF BG BH  ->  ED GH EB AH CB AF CD GF
    //  CA CB CC CD CE CF CG CH      GC EG GA CG AA CE AC EE
    //  DA DB DC DD DE DF DG DH      GD EH GB CH AB CF AD EF
    //  EA EB EC ED EE EF EG EH      FC HE FA HG DA BG DC BE
    //  FA FB FC FD FE FF FG FH      FD HF FB HH DB BH DD BF
    //  GA GB GC GD GE GF GG GH      HC FE HA FG BA DG BC DE
    //  HA HB HC HD HE HF HG HH      HD FF HB FH BB DH BD DF
    return Make("WessexD",
                34U, 54U, 32U,  6U, 16U,  4U, 18U, 52U,
                35U, 55U, 33U,  7U, 17U,  5U, 19U, 53U,
                50U, 38U, 48U, 22U,  0U, 20U,  2U, 36U,
                51U, 39U, 49U, 23U,  1U, 21U,  3U, 37U,
                42U, 60U, 40U, 62U, 24U, 14U, 26U, 12U,
                43U, 61U, 41U, 63U, 25U, 15U, 27U, 13U,
                58U, 44U, 56U, 46U,  8U, 30U, 10U, 28U,
                59U, 45U, 57U, 47U,  9U, 31U, 11U, 29U
    );
}

Recipe8x8 RecipeFactory8x8::MerciaA() {
    //  AA AB AC AD AE AF AG AH      BG DA BE DC HE FC HG FA
    //  BA BB BC BD BE BF BG BH  ->  BH DB BF DD HF FD HH FB
    //  CA CB CC CD CE CF CG CH      DG BA DE BC FE HC FG HA
    //  DA DB DC DD DE DF DG DH      DH BB DF BD FF HD FH HB
    //  EA EB EC ED EE EF EG EH      AG CC AE EC GE EA GG CA
    //  FA FB FC FD FE FF FG FH      AH CD AF ED GF EB GH CB
    //  GA GB GC GD GE GF GG GH      CG AC CE GC EE GA EG AA
    //  HA HB HC HD HE HF HG HH      CH AD CF GD EF GB EH AB
    return Make("MerciaA",
                14U, 24U, 12U, 26U, 60U, 42U, 62U, 40U,
                15U, 25U, 13U, 27U, 61U, 43U, 63U, 41U,
                30U,  8U, 28U, 10U, 44U, 58U, 46U, 56U,
                31U,  9U, 29U, 11U, 45U, 59U, 47U, 57U,
                 6U, 18U,  4U, 34U, 52U, 32U, 54U, 16U,
                 7U, 19U,  5U, 35U, 53U, 33U, 55U, 17U,
                22U,  2U, 20U, 50U, 36U, 48U, 38U,  0U,
                23U,  3U, 21U, 51U, 37U, 49U, 39U,  1U
    );
}

Recipe8x8 RecipeFactory8x8::MerciaB() {
    //  AA AB AC AD AE AF AG AH      FH HB FF HD DF BD DH BB
    //  BA BB BC BD BE BF BG BH  ->  FG HA FE HC DE BC DG BA
    //  CA CB CC CD CE CF CG CH      HH FB HF FD BF DD BH DB
    //  DA DB DC DD DE DF DG DH      HG FA HE FC BE DC BG DA
    //  EA EB EC ED EE EF EG EH      CH GB EH GD EF AD CF AB
    //  FA FB FC FD FE FF FG FH      CG GA EG GC EE AC CE AA
    //  GA GB GC GD GE GF GG GH      AH EB GH ED GF CD AF CB
    //  HA HB HC HD HE HF HG HH      AG EA GG EC GE CC AE CA
    return Make("MerciaB",
                47U, 57U, 45U, 59U, 29U, 11U, 31U,  9U,
                46U, 56U, 44U, 58U, 28U, 10U, 30U,  8U,
                63U, 41U, 61U, 43U, 13U, 27U, 15U, 25U,
                62U, 40U, 60U, 42U, 12U, 26U, 14U, 24U,
                23U, 49U, 39U, 51U, 37U,  3U, 21U,  1U,
                22U, 48U, 38U, 50U, 36U,  2U, 20U,  0U,
                 7U, 33U, 55U, 35U, 53U, 19U,  5U, 17U,
                 6U, 32U, 54U, 34U, 52U, 18U,  4U, 16U
    );
}

Recipe8x8 RecipeFactory8x8::MerciaC() {
    //  AA AB AC AD AE AF AG AH      GB EH GD EF AD CF AB CH
    //  BA BB BC BD BE BF BG BH  ->  GA EG GC EE AC CE AA CG
    //  CA CB CC CD CE CF CG CH      EB GH ED GF CD AF CB AH
    //  DA DB DC DD DE DF DG DH      EA GG EC GE CC AE CA AG
    //  EA EB EC ED EE EF EG EH      HB FF HD DF BD DH BB FH
    //  FA FB FC FD FE FF FG FH      HA FE HC DE BC DG BA FG
    //  GA GB GC GD GE GF GG GH      FB HF FD BF DD BH DB HH
    //  HA HB HC HD HE HF HG HH      FA HE FC BE DC BG DA HG
    return Make("MerciaC",
                49U, 39U, 51U, 37U,  3U, 21U,  1U, 23U,
                48U, 38U, 50U, 36U,  2U, 20U,  0U, 22U,
                33U, 55U, 35U, 53U, 19U,  5U, 17U,  7U,
                32U, 54U, 34U, 52U, 18U,  4U, 16U,  6U,
                57U, 45U, 59U, 29U, 11U, 31U,  9U, 47U,
                56U, 44U, 58U, 28U, 10U, 30U,  8U, 46U,
                41U, 61U, 43U, 13U, 27U, 15U, 25U, 63U,
                40U, 60U, 42U, 12U, 26U, 14U, 24U, 62U
    );
}

Recipe8x8 RecipeFactory8x8::MerciaD() {
    //  AA AB AC AD AE AF AG AH      FH HD FF BD DF BB DH HB
    //  BA BB BC BD BE BF BG BH  ->  FG HC FE BC DE BA DG HA
    //  CA CB CC CD CE CF CG CH      HH FD HF DD BF DB BH FB
    //  DA DB DC DD DE DF DG DH      HG FC HE DC BE DA BG FA
    //  EA EB EC ED EE EF EG EH      EH GB EF GD CF AD CH AB
    //  FA FB FC FD FE FF FG FH      EG GA EE GC CE AC CG AA
    //  GA GB GC GD GE GF GG GH      GH EB GF ED AF CD AH CB
    //  HA HB HC HD HE HF HG HH      GG EA GE EC AE CC AG CA
    return Make("MerciaD",
                47U, 59U, 45U, 11U, 29U,  9U, 31U, 57U,
                46U, 58U, 44U, 10U, 28U,  8U, 30U, 56U,
                63U, 43U, 61U, 27U, 13U, 25U, 15U, 41U,
                62U, 42U, 60U, 26U, 12U, 24U, 14U, 40U,
                39U, 49U, 37U, 51U, 21U,  3U, 23U,  1U,
                38U, 48U, 36U, 50U, 20U,  2U, 22U,  0U,
                55U, 33U, 53U, 35U,  5U, 19U,  7U, 17U,
                54U, 32U, 52U, 34U,  4U, 18U,  6U, 16U
    );
}

Recipe8x8 RecipeFactory8x8::SussexA() {
    //  AA AB AC AD AE AF AG AH      BC FE HC FG HA DG BA DE
    //  BA BB BC BD BE BF BG BH  ->  BD FF HD FH HB DH BB DF
    //  CA CB CC CD CE CF CG CH      DC HE FC HG FA BG DA BE
    //  DA DB DC DD DE DF DG DH      DD HF FD HH FB BH DB BF
    //  EA EB EC ED EE EF EG EH      GE EG GC EA AC CA AE CG
    //  FA FB FC FD FE FF FG FH      GF EH GD EB AD CB AF CH
    //  GA GB GC GD GE GF GG GH      EE GG EC GA CC AA CE AG
    //  HA HB HC HD HE HF HG HH      EF GH ED GB CD AB CF AH
    return Make("SussexA",
                10U, 44U, 58U, 46U, 56U, 30U,  8U, 28U,
                11U, 45U, 59U, 47U, 57U, 31U,  9U, 29U,
                26U, 60U, 42U, 62U, 40U, 14U, 24U, 12U,
                27U, 61U, 43U, 63U, 41U, 15U, 25U, 13U,
                52U, 38U, 50U, 32U,  2U, 16U,  4U, 22U,
                53U, 39U, 51U, 33U,  3U, 17U,  5U, 23U,
                36U, 54U, 34U, 48U, 18U,  0U, 20U,  6U,
                37U, 55U, 35U, 49U, 19U,  1U, 21U,  7U
    );
}

Recipe8x8 RecipeFactory8x8::SussexB() {
    //  AA AB AC AD AE AF AG AH      EG GE EA GC CA AC CG AE
    //  BA BB BC BD BE BF BG BH  ->  EH GF EB GD CB AD CH AF
    //  CA CB CC CD CE CF CG CH      GG EE GA EC AA CC AG CE
    //  DA DB DC DD DE DF DG DH      GH EF GB ED AB CD AH CF
    //  EA EB EC ED EE EF EG EH      DE HC FE HA FG BA DG BC
    //  FA FB FC FD FE FF FG FH      DF HD FF HB FH BB DH BD
    //  GA GB GC GD GE GF GG GH      BE FC HE FA HG DA BG DC
    //  HA HB HC HD HE HF HG HH      BF FD HF FB HH DB BH DD
    return Make("SussexB",
                38U, 52U, 32U, 50U, 16U,  2U, 22U,  4U,
                39U, 53U, 33U, 51U, 17U,  3U, 23U,  5U,
                54U, 36U, 48U, 34U,  0U, 18U,  6U, 20U,
                55U, 37U, 49U, 35U,  1U, 19U,  7U, 21U,
                28U, 58U, 44U, 56U, 46U,  8U, 30U, 10U,
                29U, 59U, 45U, 57U, 47U,  9U, 31U, 11U,
                12U, 42U, 60U, 40U, 62U, 24U, 14U, 26U,
                13U, 43U, 61U, 41U, 63U, 25U, 15U, 27U
    );
}

Recipe8x8 RecipeFactory8x8::SussexC() {
    //  AA AB AC AD AE AF AG AH      HC FE HA FG BA DG BC DE
    //  BA BB BC BD BE BF BG BH  ->  HD FF HB FH BB DH BD DF
    //  CA CB CC CD CE CF CG CH      FC HE FA HG DA BG DC BE
    //  DA DB DC DD DE DF DG DH      FD HF FB HH DB BH DD BF
    //  EA EB EC ED EE EF EG EH      GE EA GC CA AC CG AE EG
    //  FA FB FC FD FE FF FG FH      GF EB GD CB AD CH AF EH
    //  GA GB GC GD GE GF GG GH      EE GA EC AA CC AG CE GG
    //  HA HB HC HD HE HF HG HH      EF GB ED AB CD AH CF GH
    return Make("SussexC",
                58U, 44U, 56U, 46U,  8U, 30U, 10U, 28U,
                59U, 45U, 57U, 47U,  9U, 31U, 11U, 29U,
                42U, 60U, 40U, 62U, 24U, 14U, 26U, 12U,
                43U, 61U, 41U, 63U, 25U, 15U, 27U, 13U,
                52U, 32U, 50U, 16U,  2U, 22U,  4U, 38U,
                53U, 33U, 51U, 17U,  3U, 23U,  5U, 39U,
                36U, 48U, 34U,  0U, 18U,  6U, 20U, 54U,
                37U, 49U, 35U,  1U, 19U,  7U, 21U, 55U
    );
}

Recipe8x8 RecipeFactory8x8::SussexD() {
    //  AA AB AC AD AE AF AG AH      EG GC EA AC CA AE CG GE
    //  BA BB BC BD BE BF BG BH  ->  EH GD EB AD CB AF CH GF
    //  CA CB CC CD CE CF CG CH      GG EC GA CC AA CE AG EE
    //  DA DB DC DD DE DF DG DH      GH ED GB CD AB CF AH EF
    //  EA EB EC ED EE EF EG EH      FE HC FG HA DG BA DE BC
    //  FA FB FC FD FE FF FG FH      FF HD FH HB DH BB DF BD
    //  GA GB GC GD GE GF GG GH      HE FC HG FA BG DA BE DC
    //  HA HB HC HD HE HF HG HH      HF FD HH FB BH DB BF DD
    return Make("SussexD",
                38U, 50U, 32U,  2U, 16U,  4U, 22U, 52U,
                39U, 51U, 33U,  3U, 17U,  5U, 23U, 53U,
                54U, 34U, 48U, 18U,  0U, 20U,  6U, 36U,
                55U, 35U, 49U, 19U,  1U, 21U,  7U, 37U,
                44U, 58U, 46U, 56U, 30U,  8U, 28U, 10U,
                45U, 59U, 47U, 57U, 31U,  9U, 29U, 11U,
                60U, 42U, 62U, 40U, 14U, 24U, 12U, 26U,
                61U, 43U, 63U, 41U, 15U, 25U, 13U, 27U
    );
}

Recipe8x8 RecipeFactory8x8::UmbriaA() {
    //  AA AB AC AD AE AF AG AH      CB GH AB GF AD EF CD EH
    //  BA BB BC BD BE BF BG BH  ->  AA EG GA EE GC CE AC CG
    //  CA CB CC CD CE CF CG CH      EB AH GB AF GD CF ED CH
    //  DA DB DC DD DE DF DG DH      CA GG EA GE EC AE CC AG
    //  EA EB EC ED EE EF EG EH      BB HH BD HF DD FF DB FH
    //  FA FB FC FD FE FF FG FH      HA FG HC FE BC DE BA DG
    //  GA GB GC GD GE GF GG GH      HB BH HD BF FD DF FB DH
    //  HA HB HC HD HE HF HG HH      FA HG FC HE DC BE DA BG
    return Make("UmbriaA",
                17U, 55U,  1U, 53U,  3U, 37U, 19U, 39U,
                 0U, 38U, 48U, 36U, 50U, 20U,  2U, 22U,
                33U,  7U, 49U,  5U, 51U, 21U, 35U, 23U,
                16U, 54U, 32U, 52U, 34U,  4U, 18U,  6U,
                 9U, 63U, 11U, 61U, 27U, 45U, 25U, 47U,
                56U, 46U, 58U, 44U, 10U, 28U,  8U, 30U,
                57U, 15U, 59U, 13U, 43U, 29U, 41U, 31U,
                40U, 62U, 42U, 60U, 26U, 12U, 24U, 14U
    );
}

Recipe8x8 RecipeFactory8x8::UmbriaB() {
    //  AA AB AC AD AE AF AG AH      HH BB HF BD FF DD FH DB
    //  BA BB BC BD BE BF BG BH  ->  FG HA FE HC DE BC DG BA
    //  CA CB CC CD CE CF CG CH      BH HB BF HD DF FD DH FB
    //  DA DB DC DD DE DF DG DH      HG FA HE FC BE DC BG DA
    //  EA EB EC ED EE EF EG EH      EH AB GH AD GF CD EF CB
    //  FA FB FC FD FE FF FG FH      CG GA EG GC EE AC CE AA
    //  GA GB GC GD GE GF GG GH      CH GB AH GD AF ED CF EB
    //  HA HB HC HD HE HF HG HH      AG EA GG EC GE CC AE CA
    return Make("UmbriaB",
                63U,  9U, 61U, 11U, 45U, 27U, 47U, 25U,
                46U, 56U, 44U, 58U, 28U, 10U, 30U,  8U,
                15U, 57U, 13U, 59U, 29U, 43U, 31U, 41U,
                62U, 40U, 60U, 42U, 12U, 26U, 14U, 24U,
                39U,  1U, 55U,  3U, 53U, 19U, 37U, 17U,
                22U, 48U, 38U, 50U, 36U,  2U, 20U,  0U,
                23U, 49U,  7U, 51U,  5U, 35U, 21U, 33U,
                 6U, 32U, 54U, 34U, 52U, 18U,  4U, 16U
    );
}

Recipe8x8 RecipeFactory8x8::UmbriaC() {
    //  AA AB AC AD AE AF AG AH      AB GH AD GF CD EF CB EH
    //  BA BB BC BD BE BF BG BH  ->  GA EG GC EE AC CE AA CG
    //  CA CB CC CD CE CF CG CH      GB AH GD AF ED CF EB CH
    //  DA DB DC DD DE DF DG DH      EA GG EC GE CC AE CA AG
    //  EA EB EC ED EE EF EG EH      BB HF BD FF DD FH DB HH
    //  FA FB FC FD FE FF FG FH      HA FE HC DE BC DG BA FG
    //  GA GB GC GD GE GF GG GH      HB BF HD DF FD DH FB BH
    //  HA HB HC HD HE HF HG HH      FA HE FC BE DC BG DA HG
    return Make("UmbriaC",
                 1U, 55U,  3U, 53U, 19U, 37U, 17U, 39U,
                48U, 38U, 50U, 36U,  2U, 20U,  0U, 22U,
                49U,  7U, 51U,  5U, 35U, 21U, 33U, 23U,
                32U, 54U, 34U, 52U, 18U,  4U, 16U,  6U,
                 9U, 61U, 11U, 45U, 27U, 47U, 25U, 63U,
                56U, 44U, 58U, 28U, 10U, 30U,  8U, 46U,
                57U, 13U, 59U, 29U, 43U, 31U, 41U, 15U,
                40U, 60U, 42U, 12U, 26U, 14U, 24U, 62U
    );
}

Recipe8x8 RecipeFactory8x8::UmbriaD() {
    //  AA AB AC AD AE AF AG AH      HH BD HF DD FF DB FH BB
    //  BA BB BC BD BE BF BG BH  ->  FG HC FE BC DE BA DG HA
    //  CA CB CC CD CE CF CG CH      BH HD BF FD DF FB DH HB
    //  DA DB DC DD DE DF DG DH      HG FC HE DC BE DA BG FA
    //  EA EB EC ED EE EF EG EH      GH AB GF AD EF CD EH CB
    //  FA FB FC FD FE FF FG FH      EG GA EE GC CE AC CG AA
    //  GA GB GC GD GE GF GG GH      AH GB AF GD CF ED CH EB
    //  HA HB HC HD HE HF HG HH      GG EA GE EC AE CC AG CA
    return Make("UmbriaD",
                63U, 11U, 61U, 27U, 45U, 25U, 47U,  9U,
                46U, 58U, 44U, 10U, 28U,  8U, 30U, 56U,
                15U, 59U, 13U, 43U, 29U, 41U, 31U, 57U,
                62U, 42U, 60U, 26U, 12U, 24U, 14U, 40U,
                55U,  1U, 53U,  3U, 37U, 19U, 39U, 17U,
                38U, 48U, 36U, 50U, 20U,  2U, 22U,  0U,
                 7U, 49U,  5U, 51U, 21U, 35U, 23U, 33U,
                54U, 32U, 52U, 34U,  4U, 18U,  6U, 16U
    );
}

Recipe8x8 RecipeFactory8x8::TokyoA() {
    //  AA AB AC AD AE AF AG AH      DA AA DC AC BG CG BE CE
    //  BA BB BC BD BE BF BG BH  ->  DB AB DD AD BH CH BF CF
    //  CA CB CC CD CE CF CG CH      HC CA HA CC FE AG FG AE
    //  DA DB DC DD DE DF DG DH      HD CB HB CD FF AH FH AF
    //  EA EB EC ED EE EF EG EH      FC GC FA GA HE EE HG EG
    //  FA FB FC FD FE FF FG FH      FD GD FB GB HF EF HH EH
    //  GA GB GC GD GE GF GG GH      BA EC BC EA DG GE DE GG
    //  HA HB HC HD HE HF HG HH      BB ED BD EB DH GF DF GH
    return Make("TokyoA",
                24U,  0U, 26U,  2U, 14U, 22U, 12U, 20U,
                25U,  1U, 27U,  3U, 15U, 23U, 13U, 21U,
                58U, 16U, 56U, 18U, 44U,  6U, 46U,  4U,
                59U, 17U, 57U, 19U, 45U,  7U, 47U,  5U,
                42U, 50U, 40U, 48U, 60U, 36U, 62U, 38U,
                43U, 51U, 41U, 49U, 61U, 37U, 63U, 39U,
                 8U, 34U, 10U, 32U, 30U, 52U, 28U, 54U,
                 9U, 35U, 11U, 33U, 31U, 53U, 29U, 55U
    );
}

Recipe8x8 RecipeFactory8x8::TokyoB() {
    //  AA AB AC AD AE AF AG AH      BA CA BC CC DG AG DE AE
    //  BA BB BC BD BE BF BG BH  ->  BB CB BD CD DH AH DF AF
    //  CA CB CC CD CE CF CG CH      DA GC DC GA BG EE BE EG
    //  DA DB DC DD DE DF DG DH      DB GD DD GB BH EF BF EH
    //  EA EB EC ED EE EF EG EH      HC EC HA EA FE GE FG GG
    //  FA FB FC FD FE FF FG FH      HD ED HB EB FF GF FH GH
    //  GA GB GC GD GE GF GG GH      FC AA FA AC HE CG HG CE
    //  HA HB HC HD HE HF HG HH      FD AB FB AD HF CH HH CF
    return Make("TokyoB",
                 8U, 16U, 10U, 18U, 30U,  6U, 28U,  4U,
                 9U, 17U, 11U, 19U, 31U,  7U, 29U,  5U,
                24U, 50U, 26U, 48U, 14U, 36U, 12U, 38U,
                25U, 51U, 27U, 49U, 15U, 37U, 13U, 39U,
                58U, 34U, 56U, 32U, 44U, 52U, 46U, 54U,
                59U, 35U, 57U, 33U, 45U, 53U, 47U, 55U,
                42U,  0U, 40U,  2U, 60U, 22U, 62U, 20U,
                43U,  1U, 41U,  3U, 61U, 23U, 63U, 21U
    );
}

Recipe8x8 RecipeFactory8x8::TokyoC() {
    //  AA AB AC AD AE AF AG AH      FE EE FG EG HC GC HA GA
    //  BA BB BC BD BE BF BG BH  ->  HB GB FF EF FH EH HD GD
    //  CA CB CC CD CE CF CG CH      HE GE HG GG FC EC FA EA
    //  DA DB DC DD DE DF DG DH      FB EB HF GF HH GH FD ED
    //  EA EB EC ED EE EF EG EH      DG CG DE CE BA AA BC AC
    //  FA FB FC FD FE FF FG FH      BD AD DH CH DF CF BB AB
    //  GA GB GC GD GE GF GG GH      BG AG BE AE DA CA DC CC
    //  HA HB HC HD HE HF HG HH      DD CD BH AH BF AF DB CB
    return Make("TokyoC",
                44U, 36U, 46U, 38U, 58U, 50U, 56U, 48U,
                57U, 49U, 45U, 37U, 47U, 39U, 59U, 51U,
                60U, 52U, 62U, 54U, 42U, 34U, 40U, 32U,
                41U, 33U, 61U, 53U, 63U, 55U, 43U, 35U,
                30U, 22U, 28U, 20U,  8U,  0U, 10U,  2U,
                11U,  3U, 31U, 23U, 29U, 21U,  9U,  1U,
                14U,  6U, 12U,  4U, 24U, 16U, 26U, 18U,
                27U, 19U, 15U,  7U, 13U,  5U, 25U, 17U
    );
}

Recipe8x8 RecipeFactory8x8::TokyoD() {
    //  AA AB AC AD AE AF AG AH      HA GA FE EE FG EG HC GC
    //  BA BB BC BD BE BF BG BH  ->  FF EF FH EH HD GD HB GB
    //  CA CB CC CD CE CF CG CH      FA EA HE GE HG GG FC EC
    //  DA DB DC DD DE DF DG DH      HF GF HH GH FD ED FB EB
    //  EA EB EC ED EE EF EG EH      BC AC DG CG DE CE BA AA
    //  FA FB FC FD FE FF FG FH      DH CH DF CF BB AB BD AD
    //  GA GB GC GD GE GF GG GH      DC CC BG AG BE AE DA CA
    //  HA HB HC HD HE HF HG HH      BH AH BF AF DB CB DD CD
    return Make("TokyoD",
                56U, 48U, 44U, 36U, 46U, 38U, 58U, 50U,
                45U, 37U, 47U, 39U, 59U, 51U, 57U, 49U,
                40U, 32U, 60U, 52U, 62U, 54U, 42U, 34U,
                61U, 53U, 63U, 55U, 43U, 35U, 41U, 33U,
                10U,  2U, 30U, 22U, 28U, 20U,  8U,  0U,
                31U, 23U, 29U, 21U,  9U,  1U, 11U,  3U,
                26U, 18U, 14U,  6U, 12U,  4U, 24U, 16U,
                15U,  7U, 13U,  5U, 25U, 17U, 27U, 19U
    );
}

Recipe8x8 RecipeFactory8x8::KyotoA() {
    //  AA AB AC AD AE AF AG AH      GC FC GA FA EE HE EG HG
    //  BA BB BC BD BE BF BG BH  ->  GD FD GB FB EF HF EH HH
    //  CA CB CC CD CE CF CG CH      EC BA EA BC GE DG GG DE
    //  DA DB DC DD DE DF DG DH      ED BB EB BD GF DH GH DF
    //  EA EB EC ED EE EF EG EH      AA DA AC DC CG BG CE BE
    //  FA FB FC FD FE FF FG FH      AB DB AD DD CH BH CF BF
    //  GA GB GC GD GE GF GG GH      CA HC CC HA AG FE AE FG
    //  HA HB HC HD HE HF HG HH      CB HD CD HB AH FF AF FH
    return Make("KyotoA",
                50U, 42U, 48U, 40U, 36U, 60U, 38U, 62U,
                51U, 43U, 49U, 41U, 37U, 61U, 39U, 63U,
                34U,  8U, 32U, 10U, 52U, 30U, 54U, 28U,
                35U,  9U, 33U, 11U, 53U, 31U, 55U, 29U,
                 0U, 24U,  2U, 26U, 22U, 14U, 20U, 12U,
                 1U, 25U,  3U, 27U, 23U, 15U, 21U, 13U,
                16U, 58U, 18U, 56U,  6U, 44U,  4U, 46U,
                17U, 59U, 19U, 57U,  7U, 45U,  5U, 47U
    );
}

Recipe8x8 RecipeFactory8x8::KyotoB() {
    //  AA AB AC AD AE AF AG AH      EC HC EA HA GE FE GG FG
    //  BA BB BC BD BE BF BG BH  ->  ED HD EB HB GF FF GH FH
    //  CA CB CC CD CE CF CG CH      AA FC AC FA CG HE CE HG
    //  DA DB DC DD DE DF DG DH      AB FD AD FB CH HF CF HH
    //  EA EB EC ED EE EF EG EH      CA BA CC BC AG DG AE DE
    //  FA FB FC FD FE FF FG FH      CB BB CD BD AH DH AF DF
    //  GA GB GC GD GE GF GG GH      GC DA GA DC EE BG EG BE
    //  HA HB HC HD HE HF HG HH      GD DB GB DD EF BH EH BF
    return Make("KyotoB",
                34U, 58U, 32U, 56U, 52U, 44U, 54U, 46U,
                35U, 59U, 33U, 57U, 53U, 45U, 55U, 47U,
                 0U, 42U,  2U, 40U, 22U, 60U, 20U, 62U,
                 1U, 43U,  3U, 41U, 23U, 61U, 21U, 63U,
                16U,  8U, 18U, 10U,  6U, 30U,  4U, 28U,
                17U,  9U, 19U, 11U,  7U, 31U,  5U, 29U,
                50U, 24U, 48U, 26U, 36U, 14U, 38U, 12U,
                51U, 25U, 49U, 27U, 37U, 15U, 39U, 13U
    );
}

Recipe8x8 RecipeFactory8x8::KyotoC() {
    //  AA AB AC AD AE AF AG AH      EE FE EG FG GC HC GA HA
    //  BA BB BC BD BE BF BG BH  ->  EH FH GD HD GB HB EF FF
    //  CA CB CC CD CE CF CG CH      GE HE GG HG EC FC EA FA
    //  DA DB DC DD DE DF DG DH      GH HH ED FD EB FB GF HF
    //  EA EB EC ED EE EF EG EH      CG DG CE DE AA BA AC BC
    //  FA FB FC FD FE FF FG FH      CF DF AB BB AD BD CH DH
    //  GA GB GC GD GE GF GG GH      AG BG AE BE CA DA CC DC
    //  HA HB HC HD HE HF HG HH      AF BF CB DB CD DD AH BH
    return Make("KyotoC",
                36U, 44U, 38U, 46U, 50U, 58U, 48U, 56U,
                39U, 47U, 51U, 59U, 49U, 57U, 37U, 45U,
                52U, 60U, 54U, 62U, 34U, 42U, 32U, 40U,
                55U, 63U, 35U, 43U, 33U, 41U, 53U, 61U,
                22U, 30U, 20U, 28U,  0U,  8U,  2U, 10U,
                21U, 29U,  1U,  9U,  3U, 11U, 23U, 31U,
                 6U, 14U,  4U, 12U, 16U, 24U, 18U, 26U,
                 5U, 13U, 17U, 25U, 19U, 27U,  7U, 15U
    );
}

Recipe8x8 RecipeFactory8x8::KyotoD() {
    //  AA AB AC AD AE AF AG AH      EG FG GC HC GA HA EE FE
    //  BA BB BC BD BE BF BG BH  ->  EF FF EH FH GD HD GB HB
    //  CA CB CC CD CE CF CG CH      GG HG EC FC EA FA GE HE
    //  DA DB DC DD DE DF DG DH      GF HF GH HH ED FD EB FB
    //  EA EB EC ED EE EF EG EH      CE DE AA BA AC BC CG DG
    //  FA FB FC FD FE FF FG FH      CH DH CF DF AB BB AD BD
    //  GA GB GC GD GE GF GG GH      AE BE CA DA CC DC AG BG
    //  HA HB HC HD HE HF HG HH      AH BH AF BF CB DB CD DD
    return Make("KyotoD",
                38U, 46U, 50U, 58U, 48U, 56U, 36U, 44U,
                37U, 45U, 39U, 47U, 51U, 59U, 49U, 57U,
                54U, 62U, 34U, 42U, 32U, 40U, 52U, 60U,
                53U, 61U, 55U, 63U, 35U, 43U, 33U, 41U,
                20U, 28U,  0U,  8U,  2U, 10U, 22U, 30U,
                23U, 31U, 21U, 29U,  1U,  9U,  3U, 11U,
                 4U, 12U, 16U, 24U, 18U, 26U,  6U, 14U,
                 7U, 15U,  5U, 13U, 17U, 25U, 19U, 27U
    );
}

Recipe8x8 RecipeFactory8x8::OsakaA() {
    //  AA AB AC AD AE AF AG AH      EE EF GE GF GG GH EG EH
    //  BA BB BC BD BE BF BG BH  ->  DG DH HE HF FE FF BG BH
    //  CA CB CC CD CE CF CG CH      AG AH CG CH CE CF AE AF
    //  DA DB DC DD DE DF DG DH      DE DF HG HH FG FH BE BF
    //  EA EB EC ED EE EF EG EH      CC CD AC AD AA AB CA CB
    //  FA FB FC FD FE FF FG FH      BA BB FC FD HC HD DA DB
    //  GA GB GC GD GE GF GG GH      GA GB EA EB EC ED GC GD
    //  HA HB HC HD HE HF HG HH      BC BD FA FB HA HB DC DD
    return Make("OsakaA",
                36U, 37U, 52U, 53U, 54U, 55U, 38U, 39U,
                30U, 31U, 60U, 61U, 44U, 45U, 14U, 15U,
                 6U,  7U, 22U, 23U, 20U, 21U,  4U,  5U,
                28U, 29U, 62U, 63U, 46U, 47U, 12U, 13U,
                18U, 19U,  2U,  3U,  0U,  1U, 16U, 17U,
                 8U,  9U, 42U, 43U, 58U, 59U, 24U, 25U,
                48U, 49U, 32U, 33U, 34U, 35U, 50U, 51U,
                10U, 11U, 40U, 41U, 56U, 57U, 26U, 27U
    );
}

Recipe8x8 RecipeFactory8x8::OsakaB() {
    //  AA AB AC AD AE AF AG AH      GE GF GG GH EG EH EE EF
    //  BA BB BC BD BE BF BG BH  ->  BG BH DG DH HE HF FE FF
    //  CA CB CC CD CE CF CG CH      CG CH CE CF AE AF AG AH
    //  DA DB DC DD DE DF DG DH      BE BF DE DF HG HH FG FH
    //  EA EB EC ED EE EF EG EH      AC AD AA AB CA CB CC CD
    //  FA FB FC FD FE FF FG FH      DA DB BA BB FC FD HC HD
    //  GA GB GC GD GE GF GG GH      EA EB EC ED GC GD GA GB
    //  HA HB HC HD HE HF HG HH      DC DD BC BD FA FB HA HB
    return Make("OsakaB",
                52U, 53U, 54U, 55U, 38U, 39U, 36U, 37U,
                14U, 15U, 30U, 31U, 60U, 61U, 44U, 45U,
                22U, 23U, 20U, 21U,  4U,  5U,  6U,  7U,
                12U, 13U, 28U, 29U, 62U, 63U, 46U, 47U,
                 2U,  3U,  0U,  1U, 16U, 17U, 18U, 19U,
                24U, 25U,  8U,  9U, 42U, 43U, 58U, 59U,
                32U, 33U, 34U, 35U, 50U, 51U, 48U, 49U,
                26U, 27U, 10U, 11U, 40U, 41U, 56U, 57U
    );
}

Recipe8x8 RecipeFactory8x8::OsakaC() {
    //  AA AB AC AD AE AF AG AH      AA ED CA GD CC GB AC EB
    //  BA BB BC BD BE BF BG BH  ->  FC FB HC HB DA DD BA BD
    //  CA CB CC CD CE CF CG CH      EC GH GC EH GA EF EA GF
    //  DA DB DC DD DE DF DG DH      FA HF HA FF DC BH BC DH
    //  EA EB EC ED EE EF EG EH      GG CF EG AF EE AH GE CH
    //  FA FB FC FD FE FF FG FH      HE HH FE FH BG BF DG DF
    //  GA GB GC GD GE GF GG GH      CE AB AE CB AG CD CG AD
    //  HA HB HC HD HE HF HG HH      HG FD FG HD BE DB DE BB
    return Make("OsakaC",
                 0U, 35U, 16U, 51U, 18U, 49U,  2U, 33U,
                42U, 41U, 58U, 57U, 24U, 27U,  8U, 11U,
                34U, 55U, 50U, 39U, 48U, 37U, 32U, 53U,
                40U, 61U, 56U, 45U, 26U, 15U, 10U, 31U,
                54U, 21U, 38U,  5U, 36U,  7U, 52U, 23U,
                60U, 63U, 44U, 47U, 14U, 13U, 30U, 29U,
                20U,  1U,  4U, 17U,  6U, 19U, 22U,  3U,
                62U, 43U, 46U, 59U, 12U, 25U, 28U,  9U
    );
}

Recipe8x8 RecipeFactory8x8::OsakaD() {
    //  AA AB AC AD AE AF AG AH      EC AB GC CB GA CD EA AD
    //  BA BB BC BD BE BF BG BH  ->  FA FD HA HD DC DB BC BB
    //  CA CB CC CD CE CF CG CH      GG ED EG GD EE GB GE EB
    //  DA DB DC DD DE DF DG DH      HE FB FE HB BG DD DG BD
    //  EA EB EC ED EE EF EG EH      CE GH AE EH AG EF CG GF
    //  FA FB FC FD FE FF FG FH      HG HF FG FF BE BH DE DH
    //  GA GB GC GD GE GF GG GH      AA CF CA AF CC AH AC CH
    //  HA HB HC HD HE HF HG HH      FC HH HC FH DA BF BA DF
    return Make("OsakaD",
                34U,  1U, 50U, 17U, 48U, 19U, 32U,  3U,
                40U, 43U, 56U, 59U, 26U, 25U, 10U,  9U,
                54U, 35U, 38U, 51U, 36U, 49U, 52U, 33U,
                60U, 41U, 44U, 57U, 14U, 27U, 30U, 11U,
                20U, 55U,  4U, 39U,  6U, 37U, 22U, 53U,
                62U, 61U, 46U, 45U, 12U, 15U, 28U, 31U,
                 0U, 21U, 16U,  5U, 18U,  7U,  2U, 23U,
                42U, 63U, 58U, 47U, 24U, 13U,  8U, 29U
    );
}

Recipe8x8 RecipeFactory8x8::NaraA() {
    //  AA AB AC AD AE AF AG AH      FH EH FF EF HB GB HD GD
    //  BA BB BC BD BE BF BG BH  ->  FE EE HA GA HC GC FG EG
    //  CA CB CC CD CE CF CG CH      HH GH HF GF FB EB FD ED
    //  DA DB DC DD DE DF DG DH      HE GE FA EA FC EC HG GG
    //  EA EB EC ED EE EF EG EH      DF CF DH CH BD AD BB AB
    //  FA FB FC FD FE FF FG FH      DG CG BC AC BA AA DE CE
    //  GA GB GC GD GE GF GG GH      BF AF BH AH DD CD DB CB
    //  HA HB HC HD HE HF HG HH      BG AG DC CC DA CA BE AE
    return Make("NaraA",
                47U, 39U, 45U, 37U, 57U, 49U, 59U, 51U,
                44U, 36U, 56U, 48U, 58U, 50U, 46U, 38U,
                63U, 55U, 61U, 53U, 41U, 33U, 43U, 35U,
                60U, 52U, 40U, 32U, 42U, 34U, 62U, 54U,
                29U, 21U, 31U, 23U, 11U,  3U,  9U,  1U,
                30U, 22U, 10U,  2U,  8U,  0U, 28U, 20U,
                13U,  5U, 15U,  7U, 27U, 19U, 25U, 17U,
                14U,  6U, 26U, 18U, 24U, 16U, 12U,  4U
    );
}

Recipe8x8 RecipeFactory8x8::NaraB() {
    //  AA AB AC AD AE AF AG AH      FF EF HB GB HD GD FH EH
    //  BA BB BC BD BE BF BG BH  ->  FG EG FE EE HA GA HC GC
    //  CA CB CC CD CE CF CG CH      HF GF FB EB FD ED HH GH
    //  DA DB DC DD DE DF DG DH      HG GG HE GE FA EA FC EC
    //  EA EB EC ED EE EF EG EH      DH CH BD AD BB AB DF CF
    //  FA FB FC FD FE FF FG FH      DE CE DG CG BC AC BA AA
    //  GA GB GC GD GE GF GG GH      BH AH DD CD DB CB BF AF
    //  HA HB HC HD HE HF HG HH      BE AE BG AG DC CC DA CA
    return Make("NaraB",
                45U, 37U, 57U, 49U, 59U, 51U, 47U, 39U,
                46U, 38U, 44U, 36U, 56U, 48U, 58U, 50U,
                61U, 53U, 41U, 33U, 43U, 35U, 63U, 55U,
                62U, 54U, 60U, 52U, 40U, 32U, 42U, 34U,
                31U, 23U, 11U,  3U,  9U,  1U, 29U, 21U,
                28U, 20U, 30U, 22U, 10U,  2U,  8U,  0U,
                15U,  7U, 27U, 19U, 25U, 17U, 13U,  5U,
                12U,  4U, 14U,  6U, 26U, 18U, 24U, 16U
    );
}

Recipe8x8 RecipeFactory8x8::NaraC() {
    //  AA AB AC AD AE AF AG AH      BD CD BB CB DF AF DH AH
    //  BA BB BC BD BE BF BG BH  ->  BC CC BA CA DE AE DG AG
    //  CA CB CC CD CE CF CG CH      DD GB DB GD BF EH BH EF
    //  DA DB DC DD DE DF DG DH      DC GA DA GC BE EG BG EE
    //  EA EB EC ED EE EF EG EH      HB EB HD ED FH GH FF GF
    //  FA FB FC FD FE FF FG FH      HA EA HC EC FG GG FE GE
    //  GA GB GC GD GE GF GG GH      FB AD FD AB HH CF HF CH
    //  HA HB HC HD HE HF HG HH      FA AC FC AA HG CE HE CG
    return Make("NaraC",
                11U, 19U,  9U, 17U, 29U,  5U, 31U,  7U,
                10U, 18U,  8U, 16U, 28U,  4U, 30U,  6U,
                27U, 49U, 25U, 51U, 13U, 39U, 15U, 37U,
                26U, 48U, 24U, 50U, 12U, 38U, 14U, 36U,
                57U, 33U, 59U, 35U, 47U, 55U, 45U, 53U,
                56U, 32U, 58U, 34U, 46U, 54U, 44U, 52U,
                41U,  3U, 43U,  1U, 63U, 21U, 61U, 23U,
                40U,  2U, 42U,  0U, 62U, 20U, 60U, 22U
    );
}

Recipe8x8 RecipeFactory8x8::NaraD() {
    //  AA AB AC AD AE AF AG AH      DD AD DB AB BF CF BH CH
    //  BA BB BC BD BE BF BG BH  ->  DC AC DA AA BE CE BG CG
    //  CA CB CC CD CE CF CG CH      HB CD HD CB FH AF FF AH
    //  DA DB DC DD DE DF DG DH      HA CC HC CA FG AE FE AG
    //  EA EB EC ED EE EF EG EH      FB GB FD GD HH EH HF EF
    //  FA FB FC FD FE FF FG FH      FA GA FC GC HG EG HE EE
    //  GA GB GC GD GE GF GG GH      BD EB BB ED DF GH DH GF
    //  HA HB HC HD HE HF HG HH      BC EA BA EC DE GG DG GE
    return Make("NaraD",
                27U,  3U, 25U,  1U, 13U, 21U, 15U, 23U,
                26U,  2U, 24U,  0U, 12U, 20U, 14U, 22U,
                57U, 19U, 59U, 17U, 47U,  5U, 45U,  7U,
                56U, 18U, 58U, 16U, 46U,  4U, 44U,  6U,
                41U, 49U, 43U, 51U, 63U, 39U, 61U, 37U,
                40U, 48U, 42U, 50U, 62U, 38U, 60U, 36U,
                11U, 33U,  9U, 35U, 29U, 55U, 31U, 53U,
                10U, 32U,  8U, 34U, 28U, 54U, 30U, 52U
    );
}

Recipe8x8 RecipeFactory8x8::KobeA() {
    //  AA AB AC AD AE AF AG AH      ED BB EB BD GF DH GH DF
    //  BA BB BC BD BE BF BG BH  ->  EC BA EA BC GE DG GG DE
    //  CA CB CC CD CE CF CG CH      GD FD GB FB EF HF EH HH
    //  DA DB DC DD DE DF DG DH      GC FC GA FA EE HE EG HG
    //  EA EB EC ED EE EF EG EH      CB HD CD HB AH FF AF FH
    //  FA FB FC FD FE FF FG FH      CA HC CC HA AG FE AE FG
    //  GA GB GC GD GE GF GG GH      AB DB AD DD CH BH CF BF
    //  HA HB HC HD HE HF HG HH      AA DA AC DC CG BG CE BE
    return Make("KobeA",
                35U,  9U, 33U, 11U, 53U, 31U, 55U, 29U,
                34U,  8U, 32U, 10U, 52U, 30U, 54U, 28U,
                51U, 43U, 49U, 41U, 37U, 61U, 39U, 63U,
                50U, 42U, 48U, 40U, 36U, 60U, 38U, 62U,
                17U, 59U, 19U, 57U,  7U, 45U,  5U, 47U,
                16U, 58U, 18U, 56U,  6U, 44U,  4U, 46U,
                 1U, 25U,  3U, 27U, 23U, 15U, 21U, 13U,
                 0U, 24U,  2U, 26U, 22U, 14U, 20U, 12U
    );
}

Recipe8x8 RecipeFactory8x8::KobeB() {
    //  AA AB AC AD AE AF AG AH      AB FD AD FB CH HF CF HH
    //  BA BB BC BD BE BF BG BH  ->  AA FC AC FA CG HE CE HG
    //  CA CB CC CD CE CF CG CH      ED HD EB HB GF FF GH FH
    //  DA DB DC DD DE DF DG DH      EC HC EA HA GE FE GG FG
    //  EA EB EC ED EE EF EG EH      GD DB GB DD EF BH EH BF
    //  FA FB FC FD FE FF FG FH      GC DA GA DC EE BG EG BE
    //  GA GB GC GD GE GF GG GH      CB BB CD BD AH DH AF DF
    //  HA HB HC HD HE HF HG HH      CA BA CC BC AG DG AE DE
    return Make("KobeB",
                 1U, 43U,  3U, 41U, 23U, 61U, 21U, 63U,
                 0U, 42U,  2U, 40U, 22U, 60U, 20U, 62U,
                35U, 59U, 33U, 57U, 53U, 45U, 55U, 47U,
                34U, 58U, 32U, 56U, 52U, 44U, 54U, 46U,
                51U, 25U, 49U, 27U, 37U, 15U, 39U, 13U,
                50U, 24U, 48U, 26U, 36U, 14U, 38U, 12U,
                17U,  9U, 19U, 11U,  7U, 31U,  5U, 29U,
                16U,  8U, 18U, 10U,  6U, 30U,  4U, 28U
    );
}

Recipe8x8 RecipeFactory8x8::KobeC() {
    //  AA AB AC AD AE AF AG AH      AF BF CB DB CD DD AH BH
    //  BA BB BC BD BE BF BG BH  ->  AG BG AE BE CA DA CC DC
    //  CA CB CC CD CE CF CG CH      CF DF AB BB AD BD CH DH
    //  DA DB DC DD DE DF DG DH      CG DG CE DE AA BA AC BC
    //  EA EB EC ED EE EF EG EH      GH HH ED FD EB FB GF HF
    //  FA FB FC FD FE FF FG FH      GE HE GG HG EC FC EA FA
    //  GA GB GC GD GE GF GG GH      EH FH GD HD GB HB EF FF
    //  HA HB HC HD HE HF HG HH      EE FE EG FG GC HC GA HA
    return Make("KobeC",
                 5U, 13U, 17U, 25U, 19U, 27U,  7U, 15U,
                 6U, 14U,  4U, 12U, 16U, 24U, 18U, 26U,
                21U, 29U,  1U,  9U,  3U, 11U, 23U, 31U,
                22U, 30U, 20U, 28U,  0U,  8U,  2U, 10U,
                55U, 63U, 35U, 43U, 33U, 41U, 53U, 61U,
                52U, 60U, 54U, 62U, 34U, 42U, 32U, 40U,
                39U, 47U, 51U, 59U, 49U, 57U, 37U, 45U,
                36U, 44U, 38U, 46U, 50U, 58U, 48U, 56U
    );
}

Recipe8x8 RecipeFactory8x8::KobeD() {
    //  AA AB AC AD AE AF AG AH      AH BH AF BF CB DB CD DD
    //  BA BB BC BD BE BF BG BH  ->  AE BE CA DA CC DC AG BG
    //  CA CB CC CD CE CF CG CH      CH DH CF DF AB BB AD BD
    //  DA DB DC DD DE DF DG DH      CE DE AA BA AC BC CG DG
    //  EA EB EC ED EE EF EG EH      GF HF GH HH ED FD EB FB
    //  FA FB FC FD FE FF FG FH      GG HG EC FC EA FA GE HE
    //  GA GB GC GD GE GF GG GH      EF FF EH FH GD HD GB HB
    //  HA HB HC HD HE HF HG HH      EG FG GC HC GA HA EE FE
    return Make("KobeD",
                 7U, 15U,  5U, 13U, 17U, 25U, 19U, 27U,
                 4U, 12U, 16U, 24U, 18U, 26U,  6U, 14U,
                23U, 31U, 21U, 29U,  1U,  9U,  3U, 11U,
                20U, 28U,  0U,  8U,  2U, 10U, 22U, 30U,
                53U, 61U, 55U, 63U, 35U, 43U, 33U, 41U,
                54U, 62U, 34U, 42U, 32U, 40U, 52U, 60U,
                37U, 45U, 39U, 47U, 51U, 59U, 49U, 57U,
                38U, 46U, 50U, 58U, 48U, 56U, 36U, 44U
    );
}

Recipe8x8 RecipeFactory8x8::SapporoA() {
    //  AA AB AC AD AE AF AG AH      HH CF HF CH FB AD FD AB
    //  BA BB BC BD BE BF BG BH  ->  HG CE HE CG FA AC FC AA
    //  CA CB CC CD CE CF CG CH      DF AF DH AH BD CD BB CB
    //  DA DB DC DD DE DF DG DH      DE AE DG AG BC CC BA CA
    //  EA EB EC ED EE EF EG EH      BF EH BH EF DD GB DB GD
    //  FA FB FC FD FE FF FG FH      BE EG BG EE DC GA DA GC
    //  GA GB GC GD GE GF GG GH      FH GH FF GF HB EB HD ED
    //  HA HB HC HD HE HF HG HH      FG GG FE GE HA EA HC EC
    return Make("SapporoA",
                63U, 21U, 61U, 23U, 41U,  3U, 43U,  1U,
                62U, 20U, 60U, 22U, 40U,  2U, 42U,  0U,
                29U,  5U, 31U,  7U, 11U, 19U,  9U, 17U,
                28U,  4U, 30U,  6U, 10U, 18U,  8U, 16U,
                13U, 39U, 15U, 37U, 27U, 49U, 25U, 51U,
                12U, 38U, 14U, 36U, 26U, 48U, 24U, 50U,
                47U, 55U, 45U, 53U, 57U, 33U, 59U, 35U,
                46U, 54U, 44U, 52U, 56U, 32U, 58U, 34U
    );
}

Recipe8x8 RecipeFactory8x8::SapporoB() {
    //  AA AB AC AD AE AF AG AH      DF GH DH GF BD EB BB ED
    //  BA BB BC BD BE BF BG BH  ->  DE GG DG GE BC EA BA EC
    //  CA CB CC CD CE CF CG CH      BF CF BH CH DD AD DB AB
    //  DA DB DC DD DE DF DG DH      BE CE BG CG DC AC DA AA
    //  EA EB EC ED EE EF EG EH      FH AF FF AH HB CD HD CB
    //  FA FB FC FD FE FF FG FH      FG AE FE AG HA CC HC CA
    //  GA GB GC GD GE GF GG GH      HH EH HF EF FB GB FD GD
    //  HA HB HC HD HE HF HG HH      HG EG HE EE FA GA FC GC
    return Make("SapporoB",
                29U, 55U, 31U, 53U, 11U, 33U,  9U, 35U,
                28U, 54U, 30U, 52U, 10U, 32U,  8U, 34U,
                13U, 21U, 15U, 23U, 27U,  3U, 25U,  1U,
                12U, 20U, 14U, 22U, 26U,  2U, 24U,  0U,
                47U,  5U, 45U,  7U, 57U, 19U, 59U, 17U,
                46U,  4U, 44U,  6U, 56U, 18U, 58U, 16U,
                63U, 39U, 61U, 37U, 41U, 49U, 43U, 51U,
                62U, 38U, 60U, 36U, 40U, 48U, 42U, 50U
    );
}

Recipe8x8 RecipeFactory8x8::SapporoC() {
    //  AA AB AC AD AE AF AG AH      FF EF HB GB HD GD FH EH
    //  BA BB BC BD BE BF BG BH  ->  HA GA HC GC FG EG FE EE
    //  CA CB CC CD CE CF CG CH      HF GF FB EB FD ED HH GH
    //  DA DB DC DD DE DF DG DH      FA EA FC EC HG GG HE GE
    //  EA EB EC ED EE EF EG EH      DH CH BD AD BB AB DF CF
    //  FA FB FC FD FE FF FG FH      BC AC BA AA DE CE DG CG
    //  GA GB GC GD GE GF GG GH      BH AH DD CD DB CB BF AF
    //  HA HB HC HD HE HF HG HH      DC CC DA CA BE AE BG AG
    return Make("SapporoC",
                45U, 37U, 57U, 49U, 59U, 51U, 47U, 39U,
                56U, 48U, 58U, 50U, 46U, 38U, 44U, 36U,
                61U, 53U, 41U, 33U, 43U, 35U, 63U, 55U,
                40U, 32U, 42U, 34U, 62U, 54U, 60U, 52U,
                31U, 23U, 11U,  3U,  9U,  1U, 29U, 21U,
                10U,  2U,  8U,  0U, 28U, 20U, 30U, 22U,
                15U,  7U, 27U, 19U, 25U, 17U, 13U,  5U,
                26U, 18U, 24U, 16U, 12U,  4U, 14U,  6U
    );
}

Recipe8x8 RecipeFactory8x8::SapporoD() {
    //  AA AB AC AD AE AF AG AH      HB GB HD GD FH EH FF EF
    //  BA BB BC BD BE BF BG BH  ->  FE EE HA GA HC GC FG EG
    //  CA CB CC CD CE CF CG CH      FB EB FD ED HH GH HF GF
    //  DA DB DC DD DE DF DG DH      HE GE FA EA FC EC HG GG
    //  EA EB EC ED EE EF EG EH      BD AD BB AB DF CF DH CH
    //  FA FB FC FD FE FF FG FH      DG CG BC AC BA AA DE CE
    //  GA GB GC GD GE GF GG GH      DD CD DB CB BF AF BH AH
    //  HA HB HC HD HE HF HG HH      BG AG DC CC DA CA BE AE
    return Make("SapporoD",
                57U, 49U, 59U, 51U, 47U, 39U, 45U, 37U,
                44U, 36U, 56U, 48U, 58U, 50U, 46U, 38U,
                41U, 33U, 43U, 35U, 63U, 55U, 61U, 53U,
                60U, 52U, 40U, 32U, 42U, 34U, 62U, 54U,
                11U,  3U,  9U,  1U, 29U, 21U, 31U, 23U,
                30U, 22U, 10U,  2U,  8U,  0U, 28U, 20U,
                27U, 19U, 25U, 17U, 13U,  5U, 15U,  7U,
                14U,  6U, 26U, 18U, 24U, 16U, 12U,  4U
    );
}

Recipe8x8 RecipeFactory8x8::NagoyaA() {
    //  AA AB AC AD AE AF AG AH      CE AB AE CF EG GH GG ED
    //  BA BB BC BD BE BF BG BH  ->  BE DF FG HH HG FD DE BB
    //  CA CB CC CD CE CF CG CH      CG AD AG CH EE GF GE EB
    //  DA DB DC DD DE DF DG DH      BG DH FE HF HE FB DG BD
    //  EA EB EC ED EE EF EG EH      AC CD CC AH GA EF EA GB
    //  FA FB FC FD FE FF FG FH      DC BH HA FF FA HB BC DD
    //  GA GB GC GD GE GF GG GH      AA CB CA AF GC EH EC GD
    //  HA HB HC HD HE HF HG HH      DA BF HC FH FC HD BA DB
    return Make("NagoyaA",
                20U,  1U,  4U, 21U, 38U, 55U, 54U, 35U,
                12U, 29U, 46U, 63U, 62U, 43U, 28U,  9U,
                22U,  3U,  6U, 23U, 36U, 53U, 52U, 33U,
                14U, 31U, 44U, 61U, 60U, 41U, 30U, 11U,
                 2U, 19U, 18U,  7U, 48U, 37U, 32U, 49U,
                26U, 15U, 56U, 45U, 40U, 57U, 10U, 27U,
                 0U, 17U, 16U,  5U, 50U, 39U, 34U, 51U,
                24U, 13U, 58U, 47U, 42U, 59U,  8U, 25U
    );
}

Recipe8x8 RecipeFactory8x8::NagoyaB() {
    //  AA AB AC AD AE AF AG AH      AE CF EG GH GG ED CE AB
    //  BA BB BC BD BE BF BG BH  ->  DE BB BE DF FG HH HG FD
    //  CA CB CC CD CE CF CG CH      AG CH EE GF GE EB CG AD
    //  DA DB DC DD DE DF DG DH      DG BD BG DH FE HF HE FB
    //  EA EB EC ED EE EF EG EH      CC AH GA EF EA GB AC CD
    //  FA FB FC FD FE FF FG FH      BC DD DC BH HA FF FA HB
    //  GA GB GC GD GE GF GG GH      CA AF GC EH EC GD AA CB
    //  HA HB HC HD HE HF HG HH      BA DB DA BF HC FH FC HD
    return Make("NagoyaB",
                 4U, 21U, 38U, 55U, 54U, 35U, 20U,  1U,
                28U,  9U, 12U, 29U, 46U, 63U, 62U, 43U,
                 6U, 23U, 36U, 53U, 52U, 33U, 22U,  3U,
                30U, 11U, 14U, 31U, 44U, 61U, 60U, 41U,
                18U,  7U, 48U, 37U, 32U, 49U,  2U, 19U,
                10U, 27U, 26U, 15U, 56U, 45U, 40U, 57U,
                16U,  5U, 50U, 39U, 34U, 51U,  0U, 17U,
                 8U, 25U, 24U, 13U, 58U, 47U, 42U, 59U
    );
}

Recipe8x8 RecipeFactory8x8::NagoyaC() {
    //  AA AB AC AD AE AF AG AH      GA EH EA GD AC CB CC AF
    //  BA BB BC BD BE BF BG BH  ->  HA FH FA HD BC DB DC BF
    //  CA CB CC CD CE CF CG CH      GC GH EC ED AA AB CA CF
    //  DA DB DC DD DE DF DG DH      HC HH FC FD BA BB DA DF
    //  EA EB EC ED EE EF EG EH      EG GF GG EB CE AD AE CH
    //  FA FB FC FD FE FF FG FH      FG HF HG FB DE BD BE DH
    //  GA GB GC GD GE GF GG GH      EE EF GE GB CG CD AG AH
    //  HA HB HC HD HE HF HG HH      FE FF HE HB DG DD BG BH
    return Make("NagoyaC",
                48U, 39U, 32U, 51U,  2U, 17U, 18U,  5U,
                56U, 47U, 40U, 59U, 10U, 25U, 26U, 13U,
                50U, 55U, 34U, 35U,  0U,  1U, 16U, 21U,
                58U, 63U, 42U, 43U,  8U,  9U, 24U, 29U,
                38U, 53U, 54U, 33U, 20U,  3U,  4U, 23U,
                46U, 61U, 62U, 41U, 28U, 11U, 12U, 31U,
                36U, 37U, 52U, 49U, 22U, 19U,  6U,  7U,
                44U, 45U, 60U, 57U, 30U, 27U, 14U, 15U
    );
}

Recipe8x8 RecipeFactory8x8::NagoyaD() {
    //  AA AB AC AD AE AF AG AH      GC EF EC GB AA CD CA AH
    //  BA BB BC BD BE BF BG BH  ->  HC FF FC HB BA DD DA BH
    //  CA CB CC CD CE CF CG CH      EG EH GG GD CE CB AE AF
    //  DA DB DC DD DE DF DG DH      FG FH HG HD DE DB BE BF
    //  EA EB EC ED EE EF EG EH      EE GH GE ED CG AB AG CF
    //  FA FB FC FD FE FF FG FH      FE HH HE FD DG BB BG DF
    //  GA GB GC GD GE GF GG GH      GA GF EA EB AC AD CC CH
    //  HA HB HC HD HE HF HG HH      HA HF FA FB BC BD DC DH
    return Make("NagoyaD",
                50U, 37U, 34U, 49U,  0U, 19U, 16U,  7U,
                58U, 45U, 42U, 57U,  8U, 27U, 24U, 15U,
                38U, 39U, 54U, 51U, 20U, 17U,  4U,  5U,
                46U, 47U, 62U, 59U, 28U, 25U, 12U, 13U,
                36U, 55U, 52U, 35U, 22U,  1U,  6U, 21U,
                44U, 63U, 60U, 43U, 30U,  9U, 14U, 29U,
                48U, 53U, 32U, 33U,  2U,  3U, 18U, 23U,
                56U, 61U, 40U, 41U, 10U, 11U, 26U, 31U
    );
}

Recipe8x8 RecipeFactory8x8::FukuokaA() {
    //  AA AB AC AD AE AF AG AH      CE DE CG DG AC BC AA BA
    //  BA BB BC BD BE BF BG BH  ->  CH DH AD BD AB BB CF DF
    //  CA CB CC CD CE CF CG CH      AE BE AG BG CC DC CA DA
    //  DA DB DC DD DE DF DG DH      AH BH CD DD CB DB AF BF
    //  EA EB EC ED EE EF EG EH      EG FG EE FE GA HA GC HC
    //  FA FB FC FD FE FF FG FH      EF FF GB HB GD HD EH FH
    //  GA GB GC GD GE GF GG GH      GG HG GE HE EA FA EC FC
    //  HA HB HC HD HE HF HG HH      GF HF EB FB ED FD GH HH
    return Make("FukuokaA",
                20U, 28U, 22U, 30U,  2U, 10U,  0U,  8U,
                23U, 31U,  3U, 11U,  1U,  9U, 21U, 29U,
                 4U, 12U,  6U, 14U, 18U, 26U, 16U, 24U,
                 7U, 15U, 19U, 27U, 17U, 25U,  5U, 13U,
                38U, 46U, 36U, 44U, 48U, 56U, 50U, 58U,
                37U, 45U, 49U, 57U, 51U, 59U, 39U, 47U,
                54U, 62U, 52U, 60U, 32U, 40U, 34U, 42U,
                53U, 61U, 33U, 41U, 35U, 43U, 55U, 63U
    );
}

Recipe8x8 RecipeFactory8x8::FukuokaB() {
    //  AA AB AC AD AE AF AG AH      CG DG AC BC AA BA CE DE
    //  BA BB BC BD BE BF BG BH  ->  CF DF CH DH AD BD AB BB
    //  CA CB CC CD CE CF CG CH      AG BG CC DC CA DA AE BE
    //  DA DB DC DD DE DF DG DH      AF BF AH BH CD DD CB DB
    //  EA EB EC ED EE EF EG EH      EE FE GA HA GC HC EG FG
    //  FA FB FC FD FE FF FG FH      EH FH EF FF GB HB GD HD
    //  GA GB GC GD GE GF GG GH      GE HE EA FA EC FC GG HG
    //  HA HB HC HD HE HF HG HH      GH HH GF HF EB FB ED FD
    return Make("FukuokaB",
                22U, 30U,  2U, 10U,  0U,  8U, 20U, 28U,
                21U, 29U, 23U, 31U,  3U, 11U,  1U,  9U,
                 6U, 14U, 18U, 26U, 16U, 24U,  4U, 12U,
                 5U, 13U,  7U, 15U, 19U, 27U, 17U, 25U,
                36U, 44U, 48U, 56U, 50U, 58U, 38U, 46U,
                39U, 47U, 37U, 45U, 49U, 57U, 51U, 59U,
                52U, 60U, 32U, 40U, 34U, 42U, 54U, 62U,
                55U, 63U, 53U, 61U, 33U, 41U, 35U, 43U
    );
}

Recipe8x8 RecipeFactory8x8::FukuokaC() {
    //  AA AB AC AD AE AF AG AH      GA FA GC FC EG HG EE HE
    //  BA BB BC BD BE BF BG BH  ->  GB FB GD FD EH HH EF HF
    //  CA CB CC CD CE CF CG CH      EA BC EC BA GG DE GE DG
    //  DA DB DC DD DE DF DG DH      EB BD ED BB GH DF GF DH
    //  EA EB EC ED EE EF EG EH      AC DC AA DA CE BE CG BG
    //  FA FB FC FD FE FF FG FH      AD DD AB DB CF BF CH BH
    //  GA GB GC GD GE GF GG GH      CC HA CA HC AE FG AG FE
    //  HA HB HC HD HE HF HG HH      CD HB CB HD AF FH AH FF
    return Make("FukuokaC",
                48U, 40U, 50U, 42U, 38U, 62U, 36U, 60U,
                49U, 41U, 51U, 43U, 39U, 63U, 37U, 61U,
                32U, 10U, 34U,  8U, 54U, 28U, 52U, 30U,
                33U, 11U, 35U,  9U, 55U, 29U, 53U, 31U,
                 2U, 26U,  0U, 24U, 20U, 12U, 22U, 14U,
                 3U, 27U,  1U, 25U, 21U, 13U, 23U, 15U,
                18U, 56U, 16U, 58U,  4U, 46U,  6U, 44U,
                19U, 57U, 17U, 59U,  5U, 47U,  7U, 45U
    );
}

Recipe8x8 RecipeFactory8x8::FukuokaD() {
    //  AA AB AC AD AE AF AG AH      EA HA EC HC GG FG GE FE
    //  BA BB BC BD BE BF BG BH  ->  EB HB ED HD GH FH GF FF
    //  CA CB CC CD CE CF CG CH      AC FA AA FC CE HG CG HE
    //  DA DB DC DD DE DF DG DH      AD FB AB FD CF HH CH HF
    //  EA EB EC ED EE EF EG EH      CC BC CA BA AE DE AG DG
    //  FA FB FC FD FE FF FG FH      CD BD CB BB AF DF AH DH
    //  GA GB GC GD GE GF GG GH      GA DC GC DA EG BE EE BG
    //  HA HB HC HD HE HF HG HH      GB DD GD DB EH BF EF BH
    return Make("FukuokaD",
                32U, 56U, 34U, 58U, 54U, 46U, 52U, 44U,
                33U, 57U, 35U, 59U, 55U, 47U, 53U, 45U,
                 2U, 40U,  0U, 42U, 20U, 62U, 22U, 60U,
                 3U, 41U,  1U, 43U, 21U, 63U, 23U, 61U,
                18U, 10U, 16U,  8U,  4U, 28U,  6U, 30U,
                19U, 11U, 17U,  9U,  5U, 29U,  7U, 31U,
                48U, 26U, 50U, 24U, 38U, 12U, 36U, 14U,
                49U, 27U, 51U, 25U, 39U, 13U, 37U, 15U
    );
}

Recipe8x8 RecipeFactory8x8::GlendaleA() {
    //  AA AB AC AD AE AF AG AH      CE BE CG BG AC DC AA DA
    //  BA BB BC BD BE BF BG BH  ->  CF BF CH BH AD DD AB DB
    //  CA CB CC CD CE CF CG CH      AE FG AG FE CC HA CA HC
    //  DA DB DC DD DE DF DG DH      AF FH AH FF CD HB CB HD
    //  EA EB EC ED EE EF EG EH      EG HG EE HE GA FA GC FC
    //  FA FB FC FD FE FF FG FH      EH HH EF HF GB FB GD FD
    //  GA GB GC GD GE GF GG GH      GG DE GE DG EA BC EC BA
    //  HA HB HC HD HE HF HG HH      GH DF GF DH EB BD ED BB
    return Make("GlendaleA",
                20U, 12U, 22U, 14U,  2U, 26U,  0U, 24U,
                21U, 13U, 23U, 15U,  3U, 27U,  1U, 25U,
                 4U, 46U,  6U, 44U, 18U, 56U, 16U, 58U,
                 5U, 47U,  7U, 45U, 19U, 57U, 17U, 59U,
                38U, 62U, 36U, 60U, 48U, 40U, 50U, 42U,
                39U, 63U, 37U, 61U, 49U, 41U, 51U, 43U,
                54U, 28U, 52U, 30U, 32U, 10U, 34U,  8U,
                55U, 29U, 53U, 31U, 33U, 11U, 35U,  9U
    );
}

Recipe8x8 RecipeFactory8x8::GlendaleB() {
    //  AA AB AC AD AE AF AG AH      AE DE AG DG CC BC CA BA
    //  BA BB BC BD BE BF BG BH  ->  AF DF AH DH CD BD CB BB
    //  CA CB CC CD CE CF CG CH      EG BE EE BG GA DC GC DA
    //  DA DB DC DD DE DF DG DH      EH BF EF BH GB DD GD DB
    //  EA EB EC ED EE EF EG EH      GG FG GE FE EA HA EC HC
    //  FA FB FC FD FE FF FG FH      GH FH GF FF EB HB ED HD
    //  GA GB GC GD GE GF GG GH      CE HG CG HE AC FA AA FC
    //  HA HB HC HD HE HF HG HH      CF HH CH HF AD FB AB FD
    return Make("GlendaleB",
                 4U, 28U,  6U, 30U, 18U, 10U, 16U,  8U,
                 5U, 29U,  7U, 31U, 19U, 11U, 17U,  9U,
                38U, 12U, 36U, 14U, 48U, 26U, 50U, 24U,
                39U, 13U, 37U, 15U, 49U, 27U, 51U, 25U,
                54U, 46U, 52U, 44U, 32U, 56U, 34U, 58U,
                55U, 47U, 53U, 45U, 33U, 57U, 35U, 59U,
                20U, 62U, 22U, 60U,  2U, 40U,  0U, 42U,
                21U, 63U, 23U, 61U,  3U, 41U,  1U, 43U
    );
}

Recipe8x8 RecipeFactory8x8::GlendaleC() {
    //  AA AB AC AD AE AF AG AH      DD CD BH AH BF AF DB CB
    //  BA BB BC BD BE BF BG BH  ->  BG AG BE AE DA CA DC CC
    //  CA CB CC CD CE CF CG CH      BD AD DH CH DF CF BB AB
    //  DA DB DC DD DE DF DG DH      DG CG DE CE BA AA BC AC
    //  EA EB EC ED EE EF EG EH      FB EB HF GF HH GH FD ED
    //  FA FB FC FD FE FF FG FH      HE GE HG GG FC EC FA EA
    //  GA GB GC GD GE GF GG GH      HB GB FF EF FH EH HD GD
    //  HA HB HC HD HE HF HG HH      FE EE FG EG HC GC HA GA
    return Make("GlendaleC",
                27U, 19U, 15U,  7U, 13U,  5U, 25U, 17U,
                14U,  6U, 12U,  4U, 24U, 16U, 26U, 18U,
                11U,  3U, 31U, 23U, 29U, 21U,  9U,  1U,
                30U, 22U, 28U, 20U,  8U,  0U, 10U,  2U,
                41U, 33U, 61U, 53U, 63U, 55U, 43U, 35U,
                60U, 52U, 62U, 54U, 42U, 34U, 40U, 32U,
                57U, 49U, 45U, 37U, 47U, 39U, 59U, 51U,
                44U, 36U, 46U, 38U, 58U, 50U, 56U, 48U
    );
}

Recipe8x8 RecipeFactory8x8::GlendaleD() {
    //  AA AB AC AD AE AF AG AH      BH AH BF AF DB CB DD CD
    //  BA BB BC BD BE BF BG BH  ->  DC CC BG AG BE AE DA CA
    //  CA CB CC CD CE CF CG CH      DH CH DF CF BB AB BD AD
    //  DA DB DC DD DE DF DG DH      BC AC DG CG DE CE BA AA
    //  EA EB EC ED EE EF EG EH      HF GF HH GH FD ED FB EB
    //  FA FB FC FD FE FF FG FH      FA EA HE GE HG GG FC EC
    //  GA GB GC GD GE GF GG GH      FF EF FH EH HD GD HB GB
    //  HA HB HC HD HE HF HG HH      HA GA FE EE FG EG HC GC
    return Make("GlendaleD",
                15U,  7U, 13U,  5U, 25U, 17U, 27U, 19U,
                26U, 18U, 14U,  6U, 12U,  4U, 24U, 16U,
                31U, 23U, 29U, 21U,  9U,  1U, 11U,  3U,
                10U,  2U, 30U, 22U, 28U, 20U,  8U,  0U,
                61U, 53U, 63U, 55U, 43U, 35U, 41U, 33U,
                40U, 32U, 60U, 52U, 62U, 54U, 42U, 34U,
                45U, 37U, 47U, 39U, 59U, 51U, 57U, 49U,
                56U, 48U, 44U, 36U, 46U, 38U, 58U, 50U
    );
}

Recipe8x8 RecipeFactory8x8::BurbankA() {
    //  AA AB AC AD AE AF AG AH      CB HD CD HB AH FF AF FH
    //  BA BB BC BD BE BF BG BH  ->  CA HC CC HA AG FE AE FG
    //  CA CB CC CD CE CF CG CH      AB DB AD DD CH BH CF BF
    //  DA DB DC DD DE DF DG DH      AA DA AC DC CG BG CE BE
    //  EA EB EC ED EE EF EG EH      ED BB EB BD GF DH GH DF
    //  FA FB FC FD FE FF FG FH      EC BA EA BC GE DG GG DE
    //  GA GB GC GD GE GF GG GH      GD FD GB FB EF HF EH HH
    //  HA HB HC HD HE HF HG HH      GC FC GA FA EE HE EG HG
    return Make("BurbankA",
                17U, 59U, 19U, 57U,  7U, 45U,  5U, 47U,
                16U, 58U, 18U, 56U,  6U, 44U,  4U, 46U,
                 1U, 25U,  3U, 27U, 23U, 15U, 21U, 13U,
                 0U, 24U,  2U, 26U, 22U, 14U, 20U, 12U,
                35U,  9U, 33U, 11U, 53U, 31U, 55U, 29U,
                34U,  8U, 32U, 10U, 52U, 30U, 54U, 28U,
                51U, 43U, 49U, 41U, 37U, 61U, 39U, 63U,
                50U, 42U, 48U, 40U, 36U, 60U, 38U, 62U
    );
}

Recipe8x8 RecipeFactory8x8::BurbankB() {
    //  AA AB AC AD AE AF AG AH      GD DB GB DD EF BH EH BF
    //  BA BB BC BD BE BF BG BH  ->  GC DA GA DC EE BG EG BE
    //  CA CB CC CD CE CF CG CH      CB BB CD BD AH DH AF DF
    //  DA DB DC DD DE DF DG DH      CA BA CC BC AG DG AE DE
    //  EA EB EC ED EE EF EG EH      AB FD AD FB CH HF CF HH
    //  FA FB FC FD FE FF FG FH      AA FC AC FA CG HE CE HG
    //  GA GB GC GD GE GF GG GH      ED HD EB HB GF FF GH FH
    //  HA HB HC HD HE HF HG HH      EC HC EA HA GE FE GG FG
    return Make("BurbankB",
                51U, 25U, 49U, 27U, 37U, 15U, 39U, 13U,
                50U, 24U, 48U, 26U, 36U, 14U, 38U, 12U,
                17U,  9U, 19U, 11U,  7U, 31U,  5U, 29U,
                16U,  8U, 18U, 10U,  6U, 30U,  4U, 28U,
                 1U, 43U,  3U, 41U, 23U, 61U, 21U, 63U,
                 0U, 42U,  2U, 40U, 22U, 60U, 20U, 62U,
                35U, 59U, 33U, 57U, 53U, 45U, 55U, 47U,
                34U, 58U, 32U, 56U, 52U, 44U, 54U, 46U
    );
}

Recipe8x8 RecipeFactory8x8::BurbankC() {
    //  AA AB AC AD AE AF AG AH      EE EH GE GH CG CF AG AF
    //  BA BB BC BD BE BF BG BH  ->  FE FH HE HH DG DF BG BF
    //  CA CB CC CD CE CF CG CH      EG GD GG ED CE AB AE CB
    //  DA DB DC DD DE DF DG DH      FG HD HG FD DE BB BE DB
    //  EA EB EC ED EE EF EG EH      GC GB EC EB AA AD CA CD
    //  FA FB FC FD FE FF FG FH      HC HB FC FB BA BD DA DD
    //  GA GB GC GD GE GF GG GH      GA EF EA GF AC CH CC AH
    //  HA HB HC HD HE HF HG HH      HA FF FA HF BC DH DC BH
    return Make("BurbankC",
                36U, 39U, 52U, 55U, 22U, 21U,  6U,  5U,
                44U, 47U, 60U, 63U, 30U, 29U, 14U, 13U,
                38U, 51U, 54U, 35U, 20U,  1U,  4U, 17U,
                46U, 59U, 62U, 43U, 28U,  9U, 12U, 25U,
                50U, 49U, 34U, 33U,  0U,  3U, 16U, 19U,
                58U, 57U, 42U, 41U,  8U, 11U, 24U, 27U,
                48U, 37U, 32U, 53U,  2U, 23U, 18U,  7U,
                56U, 45U, 40U, 61U, 10U, 31U, 26U, 15U
    );
}

Recipe8x8 RecipeFactory8x8::BurbankD() {
    //  AA AB AC AD AE AF AG AH      EG EF GG GF CE CH AE AH
    //  BA BB BC BD BE BF BG BH  ->  FG FF HG HF DE DH BE BH
    //  CA CB CC CD CE CF CG CH      GC EH EC GH AA CF CA AF
    //  DA DB DC DD DE DF DG DH      HC FH FC HH BA DF DA BF
    //  EA EB EC ED EE EF EG EH      GA GD EA ED AC AB CC CB
    //  FA FB FC FD FE FF FG FH      HA HD FA FD BC BB DC DB
    //  GA GB GC GD GE GF GG GH      EE GB GE EB CG AD AG CD
    //  HA HB HC HD HE HF HG HH      FE HB HE FB DG BD BG DD
    return Make("BurbankD",
                38U, 37U, 54U, 53U, 20U, 23U,  4U,  7U,
                46U, 45U, 62U, 61U, 28U, 31U, 12U, 15U,
                50U, 39U, 34U, 55U,  0U, 21U, 16U,  5U,
                58U, 47U, 42U, 63U,  8U, 29U, 24U, 13U,
                48U, 51U, 32U, 35U,  2U,  1U, 18U, 17U,
                56U, 59U, 40U, 43U, 10U,  9U, 26U, 25U,
                36U, 49U, 52U, 33U, 22U,  3U,  6U, 19U,
                44U, 57U, 60U, 41U, 30U, 11U, 14U, 27U
    );
}

Recipe8x8 RecipeFactory8x8::InglewoodA() {
    //  AA AB AC AD AE AF AG AH      BC BD FA FB HA HB DC DD
    //  BA BB BC BD BE BF BG BH  ->  GA GB EA EB EC ED GC GD
    //  CA CB CC CD CE CF CG CH      BA BB FC FD HC HD DA DB
    //  DA DB DC DD DE DF DG DH      CC CD AC AD AA AB CA CB
    //  EA EB EC ED EE EF EG EH      DE DF HG HH FG FH BE BF
    //  FA FB FC FD FE FF FG FH      AG AH CG CH CE CF AE AF
    //  GA GB GC GD GE GF GG GH      DG DH HE HF FE FF BG BH
    //  HA HB HC HD HE HF HG HH      EE EF GE GF GG GH EG EH
    return Make("InglewoodA",
                10U, 11U, 40U, 41U, 56U, 57U, 26U, 27U,
                48U, 49U, 32U, 33U, 34U, 35U, 50U, 51U,
                 8U,  9U, 42U, 43U, 58U, 59U, 24U, 25U,
                18U, 19U,  2U,  3U,  0U,  1U, 16U, 17U,
                28U, 29U, 62U, 63U, 46U, 47U, 12U, 13U,
                 6U,  7U, 22U, 23U, 20U, 21U,  4U,  5U,
                30U, 31U, 60U, 61U, 44U, 45U, 14U, 15U,
                36U, 37U, 52U, 53U, 54U, 55U, 38U, 39U
    );
}

Recipe8x8 RecipeFactory8x8::InglewoodB() {
    //  AA AB AC AD AE AF AG AH      DC DD BC BD FA FB HA HB
    //  BA BB BC BD BE BF BG BH  ->  EA EB EC ED GC GD GA GB
    //  CA CB CC CD CE CF CG CH      DA DB BA BB FC FD HC HD
    //  DA DB DC DD DE DF DG DH      AC AD AA AB CA CB CC CD
    //  EA EB EC ED EE EF EG EH      BE BF DE DF HG HH FG FH
    //  FA FB FC FD FE FF FG FH      CG CH CE CF AE AF AG AH
    //  GA GB GC GD GE GF GG GH      BG BH DG DH HE HF FE FF
    //  HA HB HC HD HE HF HG HH      GE GF GG GH EG EH EE EF
    return Make("InglewoodB",
                26U, 27U, 10U, 11U, 40U, 41U, 56U, 57U,
                32U, 33U, 34U, 35U, 50U, 51U, 48U, 49U,
                24U, 25U,  8U,  9U, 42U, 43U, 58U, 59U,
                 2U,  3U,  0U,  1U, 16U, 17U, 18U, 19U,
                12U, 13U, 28U, 29U, 62U, 63U, 46U, 47U,
                22U, 23U, 20U, 21U,  4U,  5U,  6U,  7U,
                14U, 15U, 30U, 31U, 60U, 61U, 44U, 45U,
                52U, 53U, 54U, 55U, 38U, 39U, 36U, 37U
    );
}

Recipe8x8 RecipeFactory8x8::InglewoodC() {
    //  AA AB AC AD AE AF AG AH      HG FD FG HD BE DB DE BB
    //  BA BB BC BD BE BF BG BH  ->  CE AB AE CB AG CD CG AD
    //  CA CB CC CD CE CF CG CH      HE HH FE FH BG BF DG DF
    //  DA DB DC DD DE DF DG DH      GG CF EG AF EE AH GE CH
    //  EA EB EC ED EE EF EG EH      FA HF HA FF DC BH BC DH
    //  FA FB FC FD FE FF FG FH      EC GH GC EH GA EF EA GF
    //  GA GB GC GD GE GF GG GH      FC FB HC HB DA DD BA BD
    //  HA HB HC HD HE HF HG HH      AA ED CA GD CC GB AC EB
    return Make("InglewoodC",
                62U, 43U, 46U, 59U, 12U, 25U, 28U,  9U,
                20U,  1U,  4U, 17U,  6U, 19U, 22U,  3U,
                60U, 63U, 44U, 47U, 14U, 13U, 30U, 29U,
                54U, 21U, 38U,  5U, 36U,  7U, 52U, 23U,
                40U, 61U, 56U, 45U, 26U, 15U, 10U, 31U,
                34U, 55U, 50U, 39U, 48U, 37U, 32U, 53U,
                42U, 41U, 58U, 57U, 24U, 27U,  8U, 11U,
                 0U, 35U, 16U, 51U, 18U, 49U,  2U, 33U
    );
}

Recipe8x8 RecipeFactory8x8::InglewoodD() {
    //  AA AB AC AD AE AF AG AH      FC HH HC FH DA BF BA DF
    //  BA BB BC BD BE BF BG BH  ->  AA CF CA AF CC AH AC CH
    //  CA CB CC CD CE CF CG CH      HG HF FG FF BE BH DE DH
    //  DA DB DC DD DE DF DG DH      CE GH AE EH AG EF CG GF
    //  EA EB EC ED EE EF EG EH      HE FB FE HB BG DD DG BD
    //  FA FB FC FD FE FF FG FH      GG ED EG GD EE GB GE EB
    //  GA GB GC GD GE GF GG GH      FA FD HA HD DC DB BC BB
    //  HA HB HC HD HE HF HG HH      EC AB GC CB GA CD EA AD
    return Make("InglewoodD",
                42U, 63U, 58U, 47U, 24U, 13U,  8U, 29U,
                 0U, 21U, 16U,  5U, 18U,  7U,  2U, 23U,
                62U, 61U, 46U, 45U, 12U, 15U, 28U, 31U,
                20U, 55U,  4U, 39U,  6U, 37U, 22U, 53U,
                60U, 41U, 44U, 57U, 14U, 27U, 30U, 11U,
                54U, 35U, 38U, 51U, 36U, 49U, 52U, 33U,
                40U, 43U, 56U, 59U, 26U, 25U, 10U,  9U,
                34U,  1U, 50U, 17U, 48U, 19U, 32U,  3U
    );
}

Recipe8x8 RecipeFactory8x8::PasadenaA() {
    //  AA AB AC AD AE AF AG AH      BG AG DC CC DA CA BE AE
    //  BA BB BC BD BE BF BG BH  ->  BF AF BH AH DD CD DB CB
    //  CA CB CC CD CE CF CG CH      DG CG BC AC BA AA DE CE
    //  DA DB DC DD DE DF DG DH      DF CF DH CH BD AD BB AB
    //  EA EB EC ED EE EF EG EH      HE GE FA EA FC EC HG GG
    //  FA FB FC FD FE FF FG FH      HH GH HF GF FB EB FD ED
    //  GA GB GC GD GE GF GG GH      FE EE HA GA HC GC FG EG
    //  HA HB HC HD HE HF HG HH      FH EH FF EF HB GB HD GD
    return Make("PasadenaA",
                14U,  6U, 26U, 18U, 24U, 16U, 12U,  4U,
                13U,  5U, 15U,  7U, 27U, 19U, 25U, 17U,
                30U, 22U, 10U,  2U,  8U,  0U, 28U, 20U,
                29U, 21U, 31U, 23U, 11U,  3U,  9U,  1U,
                60U, 52U, 40U, 32U, 42U, 34U, 62U, 54U,
                63U, 55U, 61U, 53U, 41U, 33U, 43U, 35U,
                44U, 36U, 56U, 48U, 58U, 50U, 46U, 38U,
                47U, 39U, 45U, 37U, 57U, 49U, 59U, 51U
    );
}

Recipe8x8 RecipeFactory8x8::PasadenaB() {
    //  AA AB AC AD AE AF AG AH      BE AE BG AG DC CC DA CA
    //  BA BB BC BD BE BF BG BH  ->  BH AH DD CD DB CB BF AF
    //  CA CB CC CD CE CF CG CH      DE CE DG CG BC AC BA AA
    //  DA DB DC DD DE DF DG DH      DH CH BD AD BB AB DF CF
    //  EA EB EC ED EE EF EG EH      HG GG HE GE FA EA FC EC
    //  FA FB FC FD FE FF FG FH      HF GF FB EB FD ED HH GH
    //  GA GB GC GD GE GF GG GH      FG EG FE EE HA GA HC GC
    //  HA HB HC HD HE HF HG HH      FF EF HB GB HD GD FH EH
    return Make("PasadenaB",
                12U,  4U, 14U,  6U, 26U, 18U, 24U, 16U,
                15U,  7U, 27U, 19U, 25U, 17U, 13U,  5U,
                28U, 20U, 30U, 22U, 10U,  2U,  8U,  0U,
                31U, 23U, 11U,  3U,  9U,  1U, 29U, 21U,
                62U, 54U, 60U, 52U, 40U, 32U, 42U, 34U,
                61U, 53U, 41U, 33U, 43U, 35U, 63U, 55U,
                46U, 38U, 44U, 36U, 56U, 48U, 58U, 50U,
                45U, 37U, 57U, 49U, 59U, 51U, 47U, 39U
    );
}

Recipe8x8 RecipeFactory8x8::PasadenaC() {
    //  AA AB AC AD AE AF AG AH      FA AC FC AA HG CE HE CG
    //  BA BB BC BD BE BF BG BH  ->  FB AD FD AB HH CF HF CH
    //  CA CB CC CD CE CF CG CH      HA EA HC EC FG GG FE GE
    //  DA DB DC DD DE DF DG DH      HB EB HD ED FH GH FF GF
    //  EA EB EC ED EE EF EG EH      DC GA DA GC BE EG BG EE
    //  FA FB FC FD FE FF FG FH      DD GB DB GD BF EH BH EF
    //  GA GB GC GD GE GF GG GH      BC CC BA CA DE AE DG AG
    //  HA HB HC HD HE HF HG HH      BD CD BB CB DF AF DH AH
    return Make("PasadenaC",
                40U,  2U, 42U,  0U, 62U, 20U, 60U, 22U,
                41U,  3U, 43U,  1U, 63U, 21U, 61U, 23U,
                56U, 32U, 58U, 34U, 46U, 54U, 44U, 52U,
                57U, 33U, 59U, 35U, 47U, 55U, 45U, 53U,
                26U, 48U, 24U, 50U, 12U, 38U, 14U, 36U,
                27U, 49U, 25U, 51U, 13U, 39U, 15U, 37U,
                10U, 18U,  8U, 16U, 28U,  4U, 30U,  6U,
                11U, 19U,  9U, 17U, 29U,  5U, 31U,  7U
    );
}

Recipe8x8 RecipeFactory8x8::PasadenaD() {
    //  AA AB AC AD AE AF AG AH      BC EA BA EC DE GG DG GE
    //  BA BB BC BD BE BF BG BH  ->  BD EB BB ED DF GH DH GF
    //  CA CB CC CD CE CF CG CH      FA GA FC GC HG EG HE EE
    //  DA DB DC DD DE DF DG DH      FB GB FD GD HH EH HF EF
    //  EA EB EC ED EE EF EG EH      HA CC HC CA FG AE FE AG
    //  FA FB FC FD FE FF FG FH      HB CD HD CB FH AF FF AH
    //  GA GB GC GD GE GF GG GH      DC AC DA AA BE CE BG CG
    //  HA HB HC HD HE HF HG HH      DD AD DB AB BF CF BH CH
    return Make("PasadenaD",
                10U, 32U,  8U, 34U, 28U, 54U, 30U, 52U,
                11U, 33U,  9U, 35U, 29U, 55U, 31U, 53U,
                40U, 48U, 42U, 50U, 62U, 38U, 60U, 36U,
                41U, 49U, 43U, 51U, 63U, 39U, 61U, 37U,
                56U, 18U, 58U, 16U, 46U,  4U, 44U,  6U,
                57U, 19U, 59U, 17U, 47U,  5U, 45U,  7U,
                26U,  2U, 24U,  0U, 12U, 20U, 14U, 22U,
                27U,  3U, 25U,  1U, 13U, 21U, 15U, 23U
    );
}

Recipe8x8 RecipeFactory8x8::TorranceA() {
    //  AA AB AC AD AE AF AG AH      DF GH DH GF BD EB BB ED
    //  BA BB BC BD BE BF BG BH  ->  DE GG DG GE BC EA BA EC
    //  CA CB CC CD CE CF CG CH      HH EH HF EF FB GB FD GD
    //  DA DB DC DD DE DF DG DH      HG EG HE EE FA GA FC GC
    //  EA EB EC ED EE EF EG EH      FH AF FF AH HB CD HD CB
    //  FA FB FC FD FE FF FG FH      FG AE FE AG HA CC HC CA
    //  GA GB GC GD GE GF GG GH      BF CF BH CH DD AD DB AB
    //  HA HB HC HD HE HF HG HH      BE CE BG CG DC AC DA AA
    return Make("TorranceA",
                29U, 55U, 31U, 53U, 11U, 33U,  9U, 35U,
                28U, 54U, 30U, 52U, 10U, 32U,  8U, 34U,
                63U, 39U, 61U, 37U, 41U, 49U, 43U, 51U,
                62U, 38U, 60U, 36U, 40U, 48U, 42U, 50U,
                47U,  5U, 45U,  7U, 57U, 19U, 59U, 17U,
                46U,  4U, 44U,  6U, 56U, 18U, 58U, 16U,
                13U, 21U, 15U, 23U, 27U,  3U, 25U,  1U,
                12U, 20U, 14U, 22U, 26U,  2U, 24U,  0U
    );
}

Recipe8x8 RecipeFactory8x8::TorranceB() {
    //  AA AB AC AD AE AF AG AH      HH CF HF CH FB AD FD AB
    //  BA BB BC BD BE BF BG BH  ->  HG CE HE CG FA AC FC AA
    //  CA CB CC CD CE CF CG CH      FH GH FF GF HB EB HD ED
    //  DA DB DC DD DE DF DG DH      FG GG FE GE HA EA HC EC
    //  EA EB EC ED EE EF EG EH      BF EH BH EF DD GB DB GD
    //  FA FB FC FD FE FF FG FH      BE EG BG EE DC GA DA GC
    //  GA GB GC GD GE GF GG GH      DF AF DH AH BD CD BB CB
    //  HA HB HC HD HE HF HG HH      DE AE DG AG BC CC BA CA
    return Make("TorranceB",
                63U, 21U, 61U, 23U, 41U,  3U, 43U,  1U,
                62U, 20U, 60U, 22U, 40U,  2U, 42U,  0U,
                47U, 55U, 45U, 53U, 57U, 33U, 59U, 35U,
                46U, 54U, 44U, 52U, 56U, 32U, 58U, 34U,
                13U, 39U, 15U, 37U, 27U, 49U, 25U, 51U,
                12U, 38U, 14U, 36U, 26U, 48U, 24U, 50U,
                29U,  5U, 31U,  7U, 11U, 19U,  9U, 17U,
                28U,  4U, 30U,  6U, 10U, 18U,  8U, 16U
    );
}

Recipe8x8 RecipeFactory8x8::TorranceC() {
    //  AA AB AC AD AE AF AG AH      HA FF FA HF BC DH DC BH
    //  BA BB BC BD BE BF BG BH  ->  GA EF EA GF AC CH CC AH
    //  CA CB CC CD CE CF CG CH      HC HB FC FB BA BD DA DD
    //  DA DB DC DD DE DF DG DH      GC GB EC EB AA AD CA CD
    //  EA EB EC ED EE EF EG EH      FG HD HG FD DE BB BE DB
    //  FA FB FC FD FE FF FG FH      EG GD GG ED CE AB AE CB
    //  GA GB GC GD GE GF GG GH      FE FH HE HH DG DF BG BF
    //  HA HB HC HD HE HF HG HH      EE EH GE GH CG CF AG AF
    return Make("TorranceC",
                56U, 45U, 40U, 61U, 10U, 31U, 26U, 15U,
                48U, 37U, 32U, 53U,  2U, 23U, 18U,  7U,
                58U, 57U, 42U, 41U,  8U, 11U, 24U, 27U,
                50U, 49U, 34U, 33U,  0U,  3U, 16U, 19U,
                46U, 59U, 62U, 43U, 28U,  9U, 12U, 25U,
                38U, 51U, 54U, 35U, 20U,  1U,  4U, 17U,
                44U, 47U, 60U, 63U, 30U, 29U, 14U, 13U,
                36U, 39U, 52U, 55U, 22U, 21U,  6U,  5U
    );
}

Recipe8x8 RecipeFactory8x8::TorranceD() {
    //  AA AB AC AD AE AF AG AH      FE HB HE FB DG BD BG DD
    //  BA BB BC BD BE BF BG BH  ->  EE GB GE EB CG AD AG CD
    //  CA CB CC CD CE CF CG CH      HA HD FA FD BC BB DC DB
    //  DA DB DC DD DE DF DG DH      GA GD EA ED AC AB CC CB
    //  EA EB EC ED EE EF EG EH      HC FH FC HH BA DF DA BF
    //  FA FB FC FD FE FF FG FH      GC EH EC GH AA CF CA AF
    //  GA GB GC GD GE GF GG GH      FG FF HG HF DE DH BE BH
    //  HA HB HC HD HE HF HG HH      EG EF GG GF CE CH AE AH
    return Make("TorranceD",
                44U, 57U, 60U, 41U, 30U, 11U, 14U, 27U,
                36U, 49U, 52U, 33U, 22U,  3U,  6U, 19U,
                56U, 59U, 40U, 43U, 10U,  9U, 26U, 25U,
                48U, 51U, 32U, 35U,  2U,  1U, 18U, 17U,
                58U, 47U, 42U, 63U,  8U, 29U, 24U, 13U,
                50U, 39U, 34U, 55U,  0U, 21U, 16U,  5U,
                46U, 45U, 62U, 61U, 28U, 31U, 12U, 15U,
                38U, 37U, 54U, 53U, 20U, 23U,  4U,  7U
    );
}

Recipe8x8 RecipeFactory8x8::HawthorneA() {
    //  AA AB AC AD AE AF AG AH      FG GG FE GE HA EA HC EC
    //  BA BB BC BD BE BF BG BH  ->  FH GH FF GF HB EB HD ED
    //  CA CB CC CD CE CF CG CH      BE EG BG EE DC GA DA GC
    //  DA DB DC DD DE DF DG DH      BF EH BH EF DD GB DB GD
    //  EA EB EC ED EE EF EG EH      DE AE DG AG BC CC BA CA
    //  FA FB FC FD FE FF FG FH      DF AF DH AH BD CD BB CB
    //  GA GB GC GD GE GF GG GH      HG CE HE CG FA AC FC AA
    //  HA HB HC HD HE HF HG HH      HH CF HF CH FB AD FD AB
    return Make("HawthorneA",
                46U, 54U, 44U, 52U, 56U, 32U, 58U, 34U,
                47U, 55U, 45U, 53U, 57U, 33U, 59U, 35U,
                12U, 38U, 14U, 36U, 26U, 48U, 24U, 50U,
                13U, 39U, 15U, 37U, 27U, 49U, 25U, 51U,
                28U,  4U, 30U,  6U, 10U, 18U,  8U, 16U,
                29U,  5U, 31U,  7U, 11U, 19U,  9U, 17U,
                62U, 20U, 60U, 22U, 40U,  2U, 42U,  0U,
                63U, 21U, 61U, 23U, 41U,  3U, 43U,  1U
    );
}

Recipe8x8 RecipeFactory8x8::HawthorneB() {
    //  AA AB AC AD AE AF AG AH      HG EG HE EE FA GA FC GC
    //  BA BB BC BD BE BF BG BH  ->  HH EH HF EF FB GB FD GD
    //  CA CB CC CD CE CF CG CH      FG AE FE AG HA CC HC CA
    //  DA DB DC DD DE DF DG DH      FH AF FF AH HB CD HD CB
    //  EA EB EC ED EE EF EG EH      BE CE BG CG DC AC DA AA
    //  FA FB FC FD FE FF FG FH      BF CF BH CH DD AD DB AB
    //  GA GB GC GD GE GF GG GH      DE GG DG GE BC EA BA EC
    //  HA HB HC HD HE HF HG HH      DF GH DH GF BD EB BB ED
    return Make("HawthorneB",
                62U, 38U, 60U, 36U, 40U, 48U, 42U, 50U,
                63U, 39U, 61U, 37U, 41U, 49U, 43U, 51U,
                46U,  4U, 44U,  6U, 56U, 18U, 58U, 16U,
                47U,  5U, 45U,  7U, 57U, 19U, 59U, 17U,
                12U, 20U, 14U, 22U, 26U,  2U, 24U,  0U,
                13U, 21U, 15U, 23U, 27U,  3U, 25U,  1U,
                28U, 54U, 30U, 52U, 10U, 32U,  8U, 34U,
                29U, 55U, 31U, 53U, 11U, 33U,  9U, 35U
    );
}

Recipe8x8 RecipeFactory8x8::HawthorneC() {
    //  AA AB AC AD AE AF AG AH      DC CC DA CA BE AE BG AG
    //  BA BB BC BD BE BF BG BH  ->  BH AH DD CD DB CB BF AF
    //  CA CB CC CD CE CF CG CH      BC AC BA AA DE CE DG CG
    //  DA DB DC DD DE DF DG DH      DH CH BD AD BB AB DF CF
    //  EA EB EC ED EE EF EG EH      FA EA FC EC HG GG HE GE
    //  FA FB FC FD FE FF FG FH      HF GF FB EB FD ED HH GH
    //  GA GB GC GD GE GF GG GH      HA GA HC GC FG EG FE EE
    //  HA HB HC HD HE HF HG HH      FF EF HB GB HD GD FH EH
    return Make("HawthorneC",
                26U, 18U, 24U, 16U, 12U,  4U, 14U,  6U,
                15U,  7U, 27U, 19U, 25U, 17U, 13U,  5U,
                10U,  2U,  8U,  0U, 28U, 20U, 30U, 22U,
                31U, 23U, 11U,  3U,  9U,  1U, 29U, 21U,
                40U, 32U, 42U, 34U, 62U, 54U, 60U, 52U,
                61U, 53U, 41U, 33U, 43U, 35U, 63U, 55U,
                56U, 48U, 58U, 50U, 46U, 38U, 44U, 36U,
                45U, 37U, 57U, 49U, 59U, 51U, 47U, 39U
    );
}

Recipe8x8 RecipeFactory8x8::HawthorneD() {
    //  AA AB AC AD AE AF AG AH      BG AG DC CC DA CA BE AE
    //  BA BB BC BD BE BF BG BH  ->  DD CD DB CB BF AF BH AH
    //  CA CB CC CD CE CF CG CH      DG CG BC AC BA AA DE CE
    //  DA DB DC DD DE DF DG DH      BD AD BB AB DF CF DH CH
    //  EA EB EC ED EE EF EG EH      HE GE FA EA FC EC HG GG
    //  FA FB FC FD FE FF FG FH      FB EB FD ED HH GH HF GF
    //  GA GB GC GD GE GF GG GH      FE EE HA GA HC GC FG EG
    //  HA HB HC HD HE HF HG HH      HB GB HD GD FH EH FF EF
    return Make("HawthorneD",
                14U,  6U, 26U, 18U, 24U, 16U, 12U,  4U,
                27U, 19U, 25U, 17U, 13U,  5U, 15U,  7U,
                30U, 22U, 10U,  2U,  8U,  0U, 28U, 20U,
                11U,  3U,  9U,  1U, 29U, 21U, 31U, 23U,
                60U, 52U, 40U, 32U, 42U, 34U, 62U, 54U,
                41U, 33U, 43U, 35U, 63U, 55U, 61U, 53U,
                44U, 36U, 56U, 48U, 58U, 50U, 46U, 38U,
                57U, 49U, 59U, 51U, 47U, 39U, 45U, 37U
    );
}


Recipe8x8 RecipeFactory8x8::WizardA() {
    //  AA AB AC AD AE AF AG AH      DA AA HC CA FG AE BE CE
    //  BA BB BC BD BE BF BG BH  ->  DB AB HD CB FH AF BF CF
    //  CA CB CC CD CE CF CG CH      DC AC HA CC FE AG BG CG
    //  DA DB DC DD DE DF DG DH      DD AD HB CD FF AH BH CH
    //  EA EB EC ED EE EF EG EH      BC EA FA GA HE EE DG GE
    //  FA FB FC FD FE FF FG FH      BD EB FB GB HF EF DH GF
    //  GA GB GC GD GE GF GG GH      BA EC FC GC HG EG DE GG
    //  HA HB HC HD HE HF HG HH      BB ED FD GD HH EH DF GH
    return Make("WizardA",
                24U,  0U, 58U, 16U, 46U,  4U, 12U, 20U,
                25U,  1U, 59U, 17U, 47U,  5U, 13U, 21U,
                26U,  2U, 56U, 18U, 44U,  6U, 14U, 22U,
                27U,  3U, 57U, 19U, 45U,  7U, 15U, 23U,
                10U, 32U, 40U, 48U, 60U, 36U, 30U, 52U,
                11U, 33U, 41U, 49U, 61U, 37U, 31U, 53U,
                 8U, 34U, 42U, 50U, 62U, 38U, 28U, 54U,
                 9U, 35U, 43U, 51U, 63U, 39U, 29U, 55U
    );
}

Recipe8x8 RecipeFactory8x8::WizardB() {
    //  AA AB AC AD AE AF AG AH      BA CA DA GC BE EG DE AE
    //  BA BB BC BD BE BF BG BH  ->  BB CB DB GD BF EH DF AF
    //  CA CB CC CD CE CF CG CH      BC CC DC GA BG EE DG AG
    //  DA DB DC DD DE DF DG DH      BD CD DD GB BH EF DH AH
    //  EA EB EC ED EE EF EG EH      FA AC HA EA FE GE HE CG
    //  FA FB FC FD FE FF FG FH      FB AD HB EB FF GF HF CH
    //  GA GB GC GD GE GF GG GH      FC AA HC EC FG GG HG CE
    //  HA HB HC HD HE HF HG HH      FD AB HD ED FH GH HH CF
    return Make("WizardB",
                 8U, 16U, 24U, 50U, 12U, 38U, 28U,  4U,
                 9U, 17U, 25U, 51U, 13U, 39U, 29U,  5U,
                10U, 18U, 26U, 48U, 14U, 36U, 30U,  6U,
                11U, 19U, 27U, 49U, 15U, 37U, 31U,  7U,
                40U,  2U, 56U, 32U, 44U, 52U, 60U, 22U,
                41U,  3U, 57U, 33U, 45U, 53U, 61U, 23U,
                42U,  0U, 58U, 34U, 46U, 54U, 62U, 20U,
                43U,  1U, 59U, 35U, 47U, 55U, 63U, 21U
    );
}

Recipe8x8 RecipeFactory8x8::WizardC() {
    //  AA AB AC AD AE AF AG AH      CB DB AB BB AD BD CD DD
    //  BA BB BC BD BE BF BG BH  ->  CC DC AC BC CG DG AG BG
    //  CA CB CC CD CE CF CG CH      AF BF CF DF CH DH AH BH
    //  DA DB DC DD DE DF DG DH      CA DA AA BA CE DE AE BE
    //  EA EB EC ED EE EF EG EH      EH FH GH HH GF HF EF FF
    //  FA FB FC FD FE FF FG FH      GC HC EC FC GG HG EG FG
    //  GA GB GC GD GE GF GG GH      GD HD ED FD EB FB GB HB
    //  HA HB HC HD HE HF HG HH      GA HA EA FA GE HE EE FE
    return Make("WizardC",
                17U, 25U,  1U,  9U,  3U, 11U, 19U, 27U,
                18U, 26U,  2U, 10U, 22U, 30U,  6U, 14U,
                 5U, 13U, 21U, 29U, 23U, 31U,  7U, 15U,
                16U, 24U,  0U,  8U, 20U, 28U,  4U, 12U,
                39U, 47U, 55U, 63U, 53U, 61U, 37U, 45U,
                50U, 58U, 34U, 42U, 54U, 62U, 38U, 46U,
                51U, 59U, 35U, 43U, 33U, 41U, 49U, 57U,
                48U, 56U, 32U, 40U, 52U, 60U, 36U, 44U
    );
}

Recipe8x8 RecipeFactory8x8::WizardD() {
    //  AA AB AC AD AE AF AG AH      CD DD AD BD CH DH AH BH
    //  BA BB BC BD BE BF BG BH  ->  CA DA AA BA AC BC CC DC
    //  CA CB CC CD CE CF CG CH      CB DB AB BB CF DF AF BF
    //  DA DB DC DD DE DF DG DH      AE BE CE DE CG DG AG BG
    //  EA EB EC ED EE EF EG EH      GD HD ED FD GH HH EH FH
    //  FA FB FC FD FE FF FG FH      EG FG GG HG GE HE EE FE
    //  GA GB GC GD GE GF GG GH      GB HB EB FB GF HF EF FF
    //  HA HB HC HD HE HF HG HH      GC HC EC FC EA FA GA HA
    return Make("WizardD",
                19U, 27U,  3U, 11U, 23U, 31U,  7U, 15U,
                16U, 24U,  0U,  8U,  2U, 10U, 18U, 26U,
                17U, 25U,  1U,  9U, 21U, 29U,  5U, 13U,
                 4U, 12U, 20U, 28U, 22U, 30U,  6U, 14U,
                51U, 59U, 35U, 43U, 55U, 63U, 39U, 47U,
                38U, 46U, 54U, 62U, 52U, 60U, 36U, 44U,
                49U, 57U, 33U, 41U, 53U, 61U, 37U, 45U,
                50U, 58U, 34U, 42U, 32U, 40U, 48U, 56U
    );
}



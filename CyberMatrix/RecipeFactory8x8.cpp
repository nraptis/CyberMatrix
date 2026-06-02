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

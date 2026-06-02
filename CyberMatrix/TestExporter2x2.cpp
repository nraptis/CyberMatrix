//
//  TestExporter2x2.cpp
//  CyberMatrix
//

#include "TestExporter2x2.hpp"

#include <cstdio>

char TestExporter2x2::Letter(int pIndex) {
    return static_cast<char>('A' + pIndex);
}

void TestExporter2x2::Export(const Recipe2x2 &pRecipe) {
    std::printf("// ============================================================\n");
    std::printf("// %s 2x2 tests\n", pRecipe.mName);
    std::printf("// ============================================================\n\n");

    ExportFullTests(pRecipe);
    ExportRepeatedTests(pRecipe);
    ExportQuadTests(pRecipe);
    ExportMiniTests(pRecipe);
}

void TestExporter2x2::PrintExpected4x4From2x2(const Recipe2x2 &pRecipe,
                                               int pIndent) {
    unsigned aExpected[4][4] = {};

    for (int destBlockY = 0; destBlockY < 2; destBlockY++) {
        for (int destBlockX = 0; destBlockX < 2; destBlockX++) {
            const unsigned aSourceBlock = pRecipe.mMap[destBlockY][destBlockX];

            const int sourceBlockX = static_cast<int>(aSourceBlock & 1U);
            const int sourceBlockY = static_cast<int>(aSourceBlock >> 1U);

            for (int by = 0; by < 2; by++) {
                for (int bx = 0; bx < 2; bx++) {
                    const int destX = destBlockX * 2 + bx;
                    const int destY = destBlockY * 2 + by;

                    const int sourceX = sourceBlockX * 2 + bx;
                    const int sourceY = sourceBlockY * 2 + by;

                    aExpected[destY][destX] =
                        static_cast<unsigned>(sourceY * 4 + sourceX);
                }
            }
        }
    }

    for (int i = 0; i < pIndent; i++) { std::printf(" "); }
    std::printf("const M aExpected = {\n");

    for (int y = 0; y < 4; y++) {
        for (int i = 0; i < pIndent + 4; i++) { std::printf(" "); }

        std::printf("{ ");
        for (int x = 0; x < 4; x++) {
            std::printf("%2u", aExpected[y][x]);
            if (x < 3) { std::printf(", "); }
        }
        std::printf(" }");

        if (y < 3) { std::printf(","); }
        std::printf("\n");
    }

    for (int i = 0; i < pIndent; i++) { std::printf(" "); }
    std::printf("};\n");
}

void TestExporter2x2::PrintExpected8x8From2x2Full(const Recipe2x2 &pRecipe,
                                                   int pIndent) {
    unsigned aExpected[8][8] = {};

    for (int destBlockY = 0; destBlockY < 2; destBlockY++) {
        for (int destBlockX = 0; destBlockX < 2; destBlockX++) {
            const unsigned aSourceBlock = pRecipe.mMap[destBlockY][destBlockX];

            const int sourceBlockX = static_cast<int>(aSourceBlock & 1U);
            const int sourceBlockY = static_cast<int>(aSourceBlock >> 1U);

            for (int by = 0; by < 4; by++) {
                for (int bx = 0; bx < 4; bx++) {
                    const int destX = destBlockX * 4 + bx;
                    const int destY = destBlockY * 4 + by;

                    const int sourceX = sourceBlockX * 4 + bx;
                    const int sourceY = sourceBlockY * 4 + by;

                    aExpected[destY][destX] =
                        static_cast<unsigned>(sourceY * 8 + sourceX);
                }
            }
        }
    }

    for (int i = 0; i < pIndent; i++) { std::printf(" "); }
    std::printf("const M aExpected = {\n");

    for (int y = 0; y < 8; y++) {
        for (int i = 0; i < pIndent + 4; i++) { std::printf(" "); }

        std::printf("{ ");
        for (int x = 0; x < 8; x++) {
            std::printf("%2u", aExpected[y][x]);
            if (x < 7) { std::printf(", "); }
        }
        std::printf(" }");

        if (y < 7) { std::printf(","); }
        std::printf("\n");
    }

    for (int i = 0; i < pIndent; i++) { std::printf(" "); }
    std::printf("};\n");
}

void TestExporter2x2::PrintExpected8x8EachQuad2x2(const Recipe2x2 &pRecipe,
                                                   int pIndent) {
    unsigned aExpected[8][8] = {};

    for (int quadY = 0; quadY < 2; quadY++) {
        for (int quadX = 0; quadX < 2; quadX++) {
            const int quadBaseX = quadX * 4;
            const int quadBaseY = quadY * 4;

            for (int destBlockY = 0; destBlockY < 2; destBlockY++) {
                for (int destBlockX = 0; destBlockX < 2; destBlockX++) {
                    const unsigned aSourceBlock = pRecipe.mMap[destBlockY][destBlockX];

                    const int sourceBlockX = static_cast<int>(aSourceBlock & 1U);
                    const int sourceBlockY = static_cast<int>(aSourceBlock >> 1U);

                    for (int by = 0; by < 2; by++) {
                        for (int bx = 0; bx < 2; bx++) {
                            const int destX = quadBaseX + destBlockX * 2 + bx;
                            const int destY = quadBaseY + destBlockY * 2 + by;

                            const int sourceX = quadBaseX + sourceBlockX * 2 + bx;
                            const int sourceY = quadBaseY + sourceBlockY * 2 + by;

                            aExpected[destY][destX] =
                                static_cast<unsigned>(sourceY * 8 + sourceX);
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < pIndent; i++) { std::printf(" "); }
    std::printf("const M aExpected = {\n");

    for (int y = 0; y < 8; y++) {
        for (int i = 0; i < pIndent + 4; i++) { std::printf(" "); }

        std::printf("{ ");
        for (int x = 0; x < 8; x++) {
            std::printf("%2u", aExpected[y][x]);
            if (x < 7) { std::printf(", "); }
        }
        std::printf(" }");

        if (y < 7) { std::printf(","); }
        std::printf("\n");
    }

    for (int i = 0; i < pIndent; i++) { std::printf(" "); }
    std::printf("};\n");
}

void TestExporter2x2::PrintQuadTest(const Recipe2x2 &pRecipe,
                                     int pQuadIndex) {
    const char aLetter = Letter(pQuadIndex);

    std::printf("- (void)testQuad_%s_2x2_%c {\n", pRecipe.mName, aLetter);
    std::printf("    M88 aBefore = VerifyQuad::SpawnTestMatrixQuad%c();\n", aLetter);
    std::printf("    M88 aAfter = aBefore;\n\n");

    std::printf("    aAfter.Quad_%s_2x2_%c();\n\n", pRecipe.mName, aLetter);

    PrintExpected4x4From2x2(pRecipe, 4);

    std::printf("\n");
    std::printf("    if (!VerifyQuad::CheckQuad%c(aBefore, aAfter, aExpected)) {\n", aLetter);
    std::printf("        Logging::Log(\"Before\", aBefore);\n");
    std::printf("        Logging::Log(\"After\", aAfter);\n");
    std::printf("        XCTFail(@\"%%s failed\", sel_getName(_cmd));\n");
    std::printf("        return;\n");
    std::printf("    }\n");
    std::printf("}\n\n");
}

void TestExporter2x2::PrintQuadEachMiniTest(const Recipe2x2 &pRecipe,
                                            int pQuadIndex) {
    const char aLetter = Letter(pQuadIndex);

    std::printf("- (void)testQuad_%s_EachMini_2x2_%c {\n", pRecipe.mName, aLetter);
    std::printf("    M88 aBefore = VerifyQuad::SpawnTestMatrixQuad%c();\n", aLetter);
    std::printf("    M88 aAfter = aBefore;\n\n");

    std::printf("    aAfter.Quad_%s_EachMini_2x2_%c();\n\n", pRecipe.mName, aLetter);

    PrintExpected4x4EachMini(pRecipe, 4);

    std::printf("\n");
    std::printf("    if (!VerifyQuad::CheckQuad%c(aBefore, aAfter, aExpected)) {\n", aLetter);
    std::printf("        Logging::Log(\"Before\", aBefore);\n");
    std::printf("        Logging::Log(\"After\", aAfter);\n");
    std::printf("        XCTFail(@\"%%s failed\", sel_getName(_cmd));\n");
    std::printf("        return;\n");
    std::printf("    }\n");
    std::printf("}\n\n");
}

void TestExporter2x2::ExportQuadTests(const Recipe2x2 &pRecipe) {
    for (int i = 0; i < 4; i++) {
        PrintQuadEachMiniTest(pRecipe, i);
    }

    for (int i = 0; i < 4; i++) {
        PrintQuadTest(pRecipe, i);
    }
}

void TestExporter2x2::PrintFullTest(const Recipe2x2 &pRecipe) {
    std::printf("- (void)testFull_%s_2x2 {\n", pRecipe.mName);
    std::printf("    M88 aBefore = VerifyFull::SpawnTestMatrixFull();\n");
    std::printf("    M88 aAfter = aBefore;\n\n");

    std::printf("    aAfter.Full_%s_2x2();\n\n", pRecipe.mName);

    PrintExpected8x8From2x2Full(pRecipe, 4);

    std::printf("\n");
    std::printf("    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {\n");
    std::printf("        Logging::Log(\"Before\", aBefore);\n");
    std::printf("        Logging::Log(\"After\", aAfter);\n");
    std::printf("        XCTFail(@\"%%s failed\", sel_getName(_cmd));\n");
    std::printf("        return;\n");
    std::printf("    }\n");
    std::printf("}\n\n");
}

void TestExporter2x2::PrintFullEachQuadTest(const Recipe2x2 &pRecipe) {
    std::printf("- (void)testFull_%s_EachQuad_2x2 {\n", pRecipe.mName);
    std::printf("    M88 aBefore = VerifyFull::SpawnTestMatrixFull();\n");
    std::printf("    M88 aAfter = aBefore;\n\n");

    std::printf("    aAfter.Full_%s_EachQuad_2x2();\n\n", pRecipe.mName);

    PrintExpected8x8EachQuad2x2(pRecipe, 4);

    std::printf("\n");
    std::printf("    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {\n");
    std::printf("        Logging::Log(\"Before\", aBefore);\n");
    std::printf("        Logging::Log(\"After\", aAfter);\n");
    std::printf("        XCTFail(@\"%%s failed\", sel_getName(_cmd));\n");
    std::printf("        return;\n");
    std::printf("    }\n");
    std::printf("}\n\n");
}

void TestExporter2x2::PrintFullEachMiniTest(const Recipe2x2 &pRecipe) {
    std::printf("- (void)testFull_%s_EachMini_2x2 {\n", pRecipe.mName);
    std::printf("    M88 aBefore = VerifyFull::SpawnTestMatrixFull();\n");
    std::printf("    M88 aAfter = aBefore;\n\n");

    std::printf("    aAfter.Full_%s_EachMini_2x2();\n\n", pRecipe.mName);

    PrintExpected8x8EachMini2x2(pRecipe, 4);

    std::printf("\n");
    std::printf("    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {\n");
    std::printf("        Logging::Log(\"Before\", aBefore);\n");
    std::printf("        Logging::Log(\"After\", aAfter);\n");
    std::printf("        XCTFail(@\"%%s failed\", sel_getName(_cmd));\n");
    std::printf("        return;\n");
    std::printf("    }\n");
    std::printf("}\n\n");
}

void TestExporter2x2::ExportFullTests(const Recipe2x2 &pRecipe) {
    PrintFullTest(pRecipe);
}

void TestExporter2x2::ExportRepeatedTests(const Recipe2x2 &pRecipe) {
    PrintFullEachQuadTest(pRecipe);
    PrintFullEachMiniTest(pRecipe);
}

void TestExporter2x2::PrintExpected8x8EachMini2x2(const Recipe2x2 &pRecipe,
                                                   int pIndent) {
    unsigned aExpected[8][8] = {};

    for (int miniY = 0; miniY < 4; miniY++) {
        for (int miniX = 0; miniX < 4; miniX++) {
            const int baseX = miniX * 2;
            const int baseY = miniY * 2;

            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 2; x++) {
                    const unsigned aLocalSource = pRecipe.mMap[y][x];

                    const int sourceLocalX = static_cast<int>(aLocalSource & 1U);
                    const int sourceLocalY = static_cast<int>(aLocalSource >> 1U);

                    const int destX = baseX + x;
                    const int destY = baseY + y;

                    const int sourceX = baseX + sourceLocalX;
                    const int sourceY = baseY + sourceLocalY;

                    aExpected[destY][destX] =
                        static_cast<unsigned>(sourceY * 8 + sourceX);
                }
            }
        }
    }

    for (int i = 0; i < pIndent; i++) { std::printf(" "); }
    std::printf("const M aExpected = {\n");

    for (int y = 0; y < 8; y++) {
        for (int i = 0; i < pIndent + 4; i++) { std::printf(" "); }

        std::printf("{ ");
        for (int x = 0; x < 8; x++) {
            std::printf("%2u", aExpected[y][x]);
            if (x < 7) { std::printf(", "); }
        }
        std::printf(" }");

        if (y < 7) { std::printf(","); }
        std::printf("\n");
    }

    for (int i = 0; i < pIndent; i++) { std::printf(" "); }
    std::printf("};\n");
}

void TestExporter2x2::PrintExpected4x4EachMini(const Recipe2x2 &pRecipe,
                                                int pIndent) {
    unsigned aExpected[4][4] = {};

    for (int miniY = 0; miniY < 2; miniY++) {
        for (int miniX = 0; miniX < 2; miniX++) {
            const int baseX = miniX * 2;
            const int baseY = miniY * 2;

            for (int y = 0; y < 2; y++) {
                for (int x = 0; x < 2; x++) {
                    const unsigned aLocalSource = pRecipe.mMap[y][x];

                    const int sourceLocalX = static_cast<int>(aLocalSource & 1U);
                    const int sourceLocalY = static_cast<int>(aLocalSource >> 1U);

                    const int destX = baseX + x;
                    const int destY = baseY + y;

                    const int sourceX = baseX + sourceLocalX;
                    const int sourceY = baseY + sourceLocalY;

                    aExpected[destY][destX] =
                        static_cast<unsigned>(sourceY * 4 + sourceX);
                }
            }
        }
    }

    for (int i = 0; i < pIndent; i++) { std::printf(" "); }
    std::printf("const M aExpected = {\n");

    for (int y = 0; y < 4; y++) {
        for (int i = 0; i < pIndent + 4; i++) { std::printf(" "); }

        std::printf("{ ");
        for (int x = 0; x < 4; x++) {
            std::printf("%2u", aExpected[y][x]);
            if (x < 3) { std::printf(", "); }
        }
        std::printf(" }");

        if (y < 3) { std::printf(","); }
        std::printf("\n");
    }

    for (int i = 0; i < pIndent; i++) { std::printf(" "); }
    std::printf("};\n");
}

void TestExporter2x2::PrintExpected2x2(const Recipe2x2 &pRecipe,
                                        int pIndent) {
    for (int i = 0; i < pIndent; i++) {
        std::printf(" ");
    }

    std::printf("const M aExpected = {\n");

    for (int y = 0; y < 2; y++) {
        for (int i = 0; i < pIndent + 4; i++) {
            std::printf(" ");
        }

        std::printf("{ %u, %u }",
                    static_cast<unsigned>(pRecipe.mMap[y][0]),
                    static_cast<unsigned>(pRecipe.mMap[y][1]));

        if (y == 0) {
            std::printf(",");
        }

        std::printf("\n");
    }

    for (int i = 0; i < pIndent; i++) {
        std::printf(" ");
    }

    std::printf("};\n");
}

void TestExporter2x2::PrintMiniTest(const Recipe2x2 &pRecipe,
                                     int pMiniIndex) {
    const char aLetter = Letter(pMiniIndex);

    std::printf("- (void)testMini_%s_2x2_%c {\n", pRecipe.mName, aLetter);
    std::printf("    M88 aBefore = VerifyMini::SpawnTestMatrixMini%c();\n", aLetter);
    std::printf("    M88 aAfter = aBefore;\n\n");

    std::printf("    aAfter.Mini_%s_2x2_%c();\n\n", pRecipe.mName, aLetter);

    PrintExpected2x2(pRecipe, 4);

    std::printf("\n");
    std::printf("    if (!VerifyMini::CheckMini%c(aBefore, aAfter, aExpected)) {\n", aLetter);
    std::printf("        Logging::Log(\"Before\", aBefore);\n");
    std::printf("        Logging::Log(\"After\", aAfter);\n");
    std::printf("        XCTFail(@\"%%s failed\", sel_getName(_cmd));\n");
    std::printf("        return;\n");
    std::printf("    }\n");
    std::printf("}\n\n");
}

void TestExporter2x2::ExportMiniTests(const Recipe2x2 &pRecipe) {
    for (int i = 0; i < 16; i++) {
        PrintMiniTest(pRecipe, i);
    }
}


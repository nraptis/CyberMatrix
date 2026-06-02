//
//  TestExporter4x4.cpp
//  CyberMatrix
//

#include "TestExporter4x4.hpp"

#include <cstdio>

char TestExporter4x4::Letter(int pIndex) {
    return static_cast<char>('A' + pIndex);
}

void TestExporter4x4::Export(const Recipe4x4 &pRecipe) {
    std::printf("// ============================================================\n");
    std::printf("// %s 4x4 tests\n", pRecipe.mName);
    std::printf("// ============================================================\n\n");

    ExportFullTests(pRecipe);
    ExportRepeatedTests(pRecipe);
    ExportQuadTests(pRecipe);
}

void TestExporter4x4::PrintExpected4x4(const Recipe4x4 &pRecipe,
                                        int pIndent) {
    for (int i = 0; i < pIndent; i++) {
        std::printf(" ");
    }

    std::printf("const M aExpected = {\n");

    for (int y = 0; y < 4; y++) {
        for (int i = 0; i < pIndent + 4; i++) {
            std::printf(" ");
        }

        std::printf("{ ");

        for (int x = 0; x < 4; x++) {
            std::printf("%2u",
                        static_cast<unsigned>(pRecipe.mMap[y][x]));

            if (x < 3) {
                std::printf(", ");
            }
        }

        std::printf(" }");

        if (y < 3) {
            std::printf(",");
        }

        std::printf("\n");
    }

    for (int i = 0; i < pIndent; i++) {
        std::printf(" ");
    }

    std::printf("};\n");
}

void TestExporter4x4::PrintExpected8x8From4x4Full(const Recipe4x4 &pRecipe,
                                                   int pIndent) {
    unsigned aExpected[8][8] = {};

    for (int destBlockY = 0; destBlockY < 4; destBlockY++) {
        for (int destBlockX = 0; destBlockX < 4; destBlockX++) {
            const unsigned aSourceBlock = pRecipe.mMap[destBlockY][destBlockX];

            const int sourceBlockX = static_cast<int>(aSourceBlock & 3U);
            const int sourceBlockY = static_cast<int>(aSourceBlock >> 2U);

            for (int by = 0; by < 2; by++) {
                for (int bx = 0; bx < 2; bx++) {
                    const int destX = destBlockX * 2 + bx;
                    const int destY = destBlockY * 2 + by;

                    const int sourceX = sourceBlockX * 2 + bx;
                    const int sourceY = sourceBlockY * 2 + by;

                    aExpected[destY][destX] =
                        static_cast<unsigned>(sourceY * 8 + sourceX);
                }
            }
        }
    }

    for (int i = 0; i < pIndent; i++) {
        std::printf(" ");
    }

    std::printf("const M aExpected = {\n");

    for (int y = 0; y < 8; y++) {
        for (int i = 0; i < pIndent + 4; i++) {
            std::printf(" ");
        }

        std::printf("{ ");

        for (int x = 0; x < 8; x++) {
            std::printf("%2u", aExpected[y][x]);

            if (x < 7) {
                std::printf(", ");
            }
        }

        std::printf(" }");

        if (y < 7) {
            std::printf(",");
        }

        std::printf("\n");
    }

    for (int i = 0; i < pIndent; i++) {
        std::printf(" ");
    }

    std::printf("};\n");
}

void TestExporter4x4::PrintExpected8x8EachQuad(const Recipe4x4 &pRecipe,
                                                int pIndent) {
    unsigned aExpected[8][8] = {};

    for (int QuadY = 0; QuadY < 2; QuadY++) {
        for (int QuadX = 0; QuadX < 2; QuadX++) {
            const int baseX = QuadX * 4;
            const int baseY = QuadY * 4;

            for (int y = 0; y < 4; y++) {
                for (int x = 0; x < 4; x++) {
                    const unsigned aLocalSource = pRecipe.mMap[y][x];

                    const int sourceLocalX = static_cast<int>(aLocalSource & 3U);
                    const int sourceLocalY = static_cast<int>(aLocalSource >> 2U);

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

    for (int i = 0; i < pIndent; i++) {
        std::printf(" ");
    }

    std::printf("const M aExpected = {\n");

    for (int y = 0; y < 8; y++) {
        for (int i = 0; i < pIndent + 4; i++) {
            std::printf(" ");
        }

        std::printf("{ ");

        for (int x = 0; x < 8; x++) {
            std::printf("%2u", aExpected[y][x]);

            if (x < 7) {
                std::printf(", ");
            }
        }

        std::printf(" }");

        if (y < 7) {
            std::printf(",");
        }

        std::printf("\n");
    }

    for (int i = 0; i < pIndent; i++) {
        std::printf(" ");
    }

    std::printf("};\n");
}

void TestExporter4x4::PrintQuadTest(const Recipe4x4 &pRecipe,
                                     int pQuadIndex) {
    const char aLetter = Letter(pQuadIndex);

    std::printf("- (void)testQuad_%s_4x4_%c {\n", pRecipe.mName, aLetter);
    std::printf("    M88 aBefore = VerifyQuad::SpawnTestMatrixQuad%c();\n", aLetter);
    std::printf("    M88 aAfter = aBefore;\n\n");

    std::printf("    aAfter.Quad_%s_4x4_%c();\n\n", pRecipe.mName, aLetter);

    PrintExpected4x4(pRecipe, 4);

    std::printf("\n");
    std::printf("    if (!VerifyQuad::CheckQuad%c(aBefore, aAfter, aExpected)) {\n", aLetter);
    std::printf("        Logging::Log(\"Before\", aBefore);\n");
    std::printf("        Logging::Log(\"After\", aAfter);\n");
    std::printf("        XCTFail(@\"%%s failed\", sel_getName(_cmd));\n");
    std::printf("        return;\n");
    std::printf("    }\n");
    std::printf("}\n\n");
}

void TestExporter4x4::PrintFullTest(const Recipe4x4 &pRecipe) {
    std::printf("- (void)testFull_%s_4x4 {\n", pRecipe.mName);
    std::printf("    M88 aBefore = VerifyFull::SpawnTestMatrixFull();\n");
    std::printf("    M88 aAfter = aBefore;\n\n");

    std::printf("    aAfter.Full_%s_4x4();\n\n", pRecipe.mName);

    PrintExpected8x8From4x4Full(pRecipe, 4);

    std::printf("\n");
    std::printf("    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {\n");
    std::printf("        Logging::Log(\"Before\", aBefore);\n");
    std::printf("        Logging::Log(\"After\", aAfter);\n");
    std::printf("        XCTFail(@\"%%s failed\", sel_getName(_cmd));\n");
    std::printf("        return;\n");
    std::printf("    }\n");
    std::printf("}\n\n");
}

void TestExporter4x4::PrintFullEachQuadTest(const Recipe4x4 &pRecipe) {
    std::printf("- (void)testFull_%s_EachQuad_4x4 {\n", pRecipe.mName);
    std::printf("    M88 aBefore = VerifyFull::SpawnTestMatrixFull();\n");
    std::printf("    M88 aAfter = aBefore;\n\n");

    std::printf("    aAfter.Full_%s_EachQuad_4x4();\n\n", pRecipe.mName);

    PrintExpected8x8EachQuad(pRecipe, 4);

    std::printf("\n");
    std::printf("    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {\n");
    std::printf("        Logging::Log(\"Before\", aBefore);\n");
    std::printf("        Logging::Log(\"After\", aAfter);\n");
    std::printf("        XCTFail(@\"%%s failed\", sel_getName(_cmd));\n");
    std::printf("        return;\n");
    std::printf("    }\n");
    std::printf("}\n\n");
}

void TestExporter4x4::ExportQuadTests(const Recipe4x4 &pRecipe) {
    for (int i = 0; i < 4; i++) {
        PrintQuadTest(pRecipe, i);
    }
}

void TestExporter4x4::ExportFullTests(const Recipe4x4 &pRecipe) {
    PrintFullTest(pRecipe);
}

void TestExporter4x4::ExportRepeatedTests(const Recipe4x4 &pRecipe) {
    PrintFullEachQuadTest(pRecipe);
}


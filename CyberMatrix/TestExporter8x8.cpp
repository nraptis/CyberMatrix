//
//  TestExporter8x8.cpp
//  CyberMatrix
//

#include "TestExporter8x8.hpp"

#include <cstdio>

void TestExporter8x8::Export(const Recipe8x8 &pRecipe) {
    std::printf("// ============================================================\n");
    std::printf("// %s 8x8 tests\n", pRecipe.mName);
    std::printf("// ============================================================\n\n");

    PrintFullTest(pRecipe);
}

void TestExporter8x8::PrintExpected8x8(const Recipe8x8 &pRecipe,
                                        int pIndent) {
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
            std::printf("%2u",
                        static_cast<unsigned>(pRecipe.mMap[y][x]));

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

void TestExporter8x8::PrintFullTest(const Recipe8x8 &pRecipe) {
    std::printf("- (void)testFull_%s_8x8 {\n", pRecipe.mName);
    std::printf("    M88 aBefore = VerifyFull::SpawnTestMatrixFull();\n");
    std::printf("    M88 aAfter = aBefore;\n\n");

    std::printf("    aAfter.Full_%s_8x8();\n\n", pRecipe.mName);

    PrintExpected8x8(pRecipe, 4);

    std::printf("\n");
    std::printf("    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {\n");
    std::printf("        Logging::Log(\"Before\", aBefore);\n");
    std::printf("        Logging::Log(\"After\", aAfter);\n");
    std::printf("        XCTFail(@\"%%s failed\", sel_getName(_cmd));\n");
    std::printf("        return;\n");
    std::printf("    }\n");
    std::printf("}\n\n");
}

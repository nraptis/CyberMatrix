//
//  TestFileExporter4x4And8x8.hpp
//  CyberMatrix
//

#ifndef TestFileExporter4x4And8x8_hpp
#define TestFileExporter4x4And8x8_hpp

#include "RecipeFactory4x4.hpp"
#include "RecipeFactory8x8.hpp"
#include "FileIO.hpp"

#include <cstdint>
#include <sstream>
#include <string>
#include <vector>

class TestFileExporter4x4And8x8 {

public:

    static bool Export(const std::string pFolder,
                       const Recipe4x4 &pRecipe4x4,
                       const Recipe8x8 &pRecipe8x8) {
        const std::string aTestsPath = FileIO::ProjectRoot(pFolder);

        printf("aTestsPath = %s\n", aTestsPath.c_str());
        
        const std::string aQuadPath =
            FileIO::Join(aTestsPath, "Test_Quad_" + std::string(pRecipe4x4.mName) + ".mm");

        const std::string aFullPath =
            FileIO::Join(aTestsPath, "Test_Full_" + std::string(pRecipe4x4.mName) + ".mm");

        const std::string aQuadText = BuildQuadFile(pRecipe4x4);
        const std::string aFullText = BuildFullFile(pRecipe4x4, pRecipe8x8);

        return SaveText(aQuadPath, aQuadText) &&
               SaveText(aFullPath, aFullText);
    }

private:

    static bool SaveText(const std::string &pPath,
                         const std::string &pText) {
        std::vector<std::uint8_t> aData;
        aData.assign(pText.begin(), pText.end());
        return FileIO::Save(pPath, aData);
    }

    static char Letter(int pIndex) {
        return static_cast<char>('A' + pIndex);
    }

    static void Indent(std::ostringstream &pStream,
                       int pCount) {
        for (int i = 0; i < pCount; i++) {
            pStream << ' ';
        }
    }

    static void PrintValue(std::ostringstream &pStream,
                           unsigned pValue) {
        if (pValue < 10) {
            pStream << ' ';
        }
        pStream << pValue;
    }

    static void PrintExpected4x4(std::ostringstream &pStream,
                                 const Recipe4x4 &pRecipe,
                                 int pIndent) {
        Indent(pStream, pIndent);
        pStream << "const M aExpected = {\n";

        for (int y = 0; y < 4; y++) {
            Indent(pStream, pIndent + 4);
            pStream << "{ ";

            for (int x = 0; x < 4; x++) {
                PrintValue(pStream, static_cast<unsigned>(pRecipe.mMap[y][x]));

                if (x < 3) {
                    pStream << ", ";
                }
            }

            pStream << " }";

            if (y < 3) {
                pStream << ",";
            }

            pStream << "\n";
        }

        Indent(pStream, pIndent);
        pStream << "};\n";
    }

    static void PrintExpected8x8(std::ostringstream &pStream,
                                 const Recipe8x8 &pRecipe,
                                 int pIndent) {
        Indent(pStream, pIndent);
        pStream << "const M aExpected = {\n";

        for (int y = 0; y < 8; y++) {
            Indent(pStream, pIndent + 4);
            pStream << "{ ";

            for (int x = 0; x < 8; x++) {
                PrintValue(pStream, static_cast<unsigned>(pRecipe.mMap[y][x]));

                if (x < 7) {
                    pStream << ", ";
                }
            }

            pStream << " }";

            if (y < 7) {
                pStream << ",";
            }

            pStream << "\n";
        }

        Indent(pStream, pIndent);
        pStream << "};\n";
    }

    static void PrintExpected8x8From4x4Full(std::ostringstream &pStream,
                                            const Recipe4x4 &pRecipe,
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

        PrintExpected8x8Array(pStream, aExpected, pIndent);
    }

    static void PrintExpected8x8EachQuad(std::ostringstream &pStream,
                                         const Recipe4x4 &pRecipe,
                                         int pIndent) {
        unsigned aExpected[8][8] = {};

        for (int quadY = 0; quadY < 2; quadY++) {
            for (int quadX = 0; quadX < 2; quadX++) {
                const int baseX = quadX * 4;
                const int baseY = quadY * 4;

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

        PrintExpected8x8Array(pStream, aExpected, pIndent);
    }

    static void PrintExpected8x8Array(std::ostringstream &pStream,
                                      const unsigned pExpected[8][8],
                                      int pIndent) {
        Indent(pStream, pIndent);
        pStream << "const M aExpected = {\n";

        for (int y = 0; y < 8; y++) {
            Indent(pStream, pIndent + 4);
            pStream << "{ ";

            for (int x = 0; x < 8; x++) {
                PrintValue(pStream, pExpected[y][x]);

                if (x < 7) {
                    pStream << ", ";
                }
            }

            pStream << " }";

            if (y < 7) {
                pStream << ",";
            }

            pStream << "\n";
        }

        Indent(pStream, pIndent);
        pStream << "};\n";
    }

    static std::string BuildQuadFile(const Recipe4x4 &pRecipe) {
        std::ostringstream aStream;

        aStream << "//\n";
        aStream << "//  Test_Quad_" << pRecipe.mName << ".mm\n";
        aStream << "//  CyberMatrixTests\n";
        aStream << "//\n\n";

        aStream << "#import <XCTest/XCTest.h>\n\n";
        aStream << "#include \"M88.hpp\"\n";
        aStream << "#include \"VerifyQuad.hpp\"\n";
        aStream << "#include \"Tests.hpp\"\n";
        aStream << "#include \"Logging.hpp\"\n\n";

        aStream << "@interface Test_Quad_" << pRecipe.mName << " : XCTestCase\n\n";
        aStream << "@end\n\n";

        aStream << "@implementation Test_Quad_" << pRecipe.mName << "\n\n";

        for (int i = 0; i < 4; i++) {
            PrintQuadTest(aStream, pRecipe, i);
        }

        aStream << "@end\n";

        return aStream.str();
    }

    static std::string BuildFullFile(const Recipe4x4 &pRecipe4x4,
                                     const Recipe8x8 &pRecipe8x8) {
        std::ostringstream aStream;

        aStream << "//\n";
        aStream << "//  Test_Full_" << pRecipe4x4.mName << ".mm\n";
        aStream << "//  CyberMatrixTests\n";
        aStream << "//\n\n";

        aStream << "#import <XCTest/XCTest.h>\n\n";
        aStream << "#include \"M88.hpp\"\n";
        aStream << "#include \"VerifyFull.hpp\"\n";
        aStream << "#include \"Tests.hpp\"\n";
        aStream << "#include \"Logging.hpp\"\n\n";

        aStream << "@interface Test_Full_" << pRecipe4x4.mName << " : XCTestCase\n\n";
        aStream << "@end\n\n";

        aStream << "@implementation Test_Full_" << pRecipe4x4.mName << "\n\n";

        PrintFull4x4Test(aStream, pRecipe4x4);
        PrintFullEachQuad4x4Test(aStream, pRecipe4x4);
        PrintFull8x8Test(aStream, pRecipe8x8);

        aStream << "@end\n";

        return aStream.str();
    }

    static void PrintQuadTest(std::ostringstream &pStream,
                              const Recipe4x4 &pRecipe,
                              int pQuadIndex) {
        const char aLetter = Letter(pQuadIndex);

        pStream << "- (void)testQuad_" << pRecipe.mName << "_4x4_" << aLetter << " {\n";
        pStream << "    M88 aBefore = VerifyQuad::SpawnTestMatrixQuad" << aLetter << "();\n";
        pStream << "    M88 aAfter = aBefore;\n\n";

        pStream << "    aAfter.Quad_" << pRecipe.mName << "_4x4_" << aLetter << "();\n\n";

        PrintExpected4x4(pStream, pRecipe, 4);

        pStream << "\n";
        pStream << "    if (!VerifyQuad::CheckQuad" << aLetter << "(aBefore, aAfter, aExpected)) {\n";
        pStream << "        Logging::Log(\"Before\", aBefore);\n";
        pStream << "        Logging::Log(\"After\", aAfter);\n";
        pStream << "        XCTFail(@\"%s failed\", sel_getName(_cmd));\n";
        pStream << "        return;\n";
        pStream << "    }\n";
        pStream << "}\n\n";
    }

    static void PrintFull4x4Test(std::ostringstream &pStream,
                                 const Recipe4x4 &pRecipe) {
        pStream << "- (void)testFull_" << pRecipe.mName << "_4x4 {\n";
        pStream << "    M88 aBefore = VerifyFull::SpawnTestMatrixFull();\n";
        pStream << "    M88 aAfter = aBefore;\n\n";

        pStream << "    aAfter.Full_" << pRecipe.mName << "_4x4();\n\n";

        PrintExpected8x8From4x4Full(pStream, pRecipe, 4);

        pStream << "\n";
        pStream << "    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {\n";
        pStream << "        Logging::Log(\"Before\", aBefore);\n";
        pStream << "        Logging::Log(\"After\", aAfter);\n";
        pStream << "        XCTFail(@\"%s failed\", sel_getName(_cmd));\n";
        pStream << "        return;\n";
        pStream << "    }\n";
        pStream << "}\n\n";
    }

    static void PrintFullEachQuad4x4Test(std::ostringstream &pStream,
                                         const Recipe4x4 &pRecipe) {
        pStream << "- (void)testFull_" << pRecipe.mName << "_EachQuad_4x4 {\n";
        pStream << "    M88 aBefore = VerifyFull::SpawnTestMatrixFull();\n";
        pStream << "    M88 aAfter = aBefore;\n\n";

        pStream << "    aAfter.Full_" << pRecipe.mName << "_EachQuad_4x4();\n\n";

        PrintExpected8x8EachQuad(pStream, pRecipe, 4);

        pStream << "\n";
        pStream << "    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {\n";
        pStream << "        Logging::Log(\"Before\", aBefore);\n";
        pStream << "        Logging::Log(\"After\", aAfter);\n";
        pStream << "        XCTFail(@\"%s failed\", sel_getName(_cmd));\n";
        pStream << "        return;\n";
        pStream << "    }\n";
        pStream << "}\n\n";
    }

    static void PrintFull8x8Test(std::ostringstream &pStream,
                                 const Recipe8x8 &pRecipe) {
        pStream << "- (void)testFull_" << pRecipe.mName << "_8x8 {\n";
        pStream << "    M88 aBefore = VerifyFull::SpawnTestMatrixFull();\n";
        pStream << "    M88 aAfter = aBefore;\n\n";

        pStream << "    aAfter.Full_" << pRecipe.mName << "_8x8();\n\n";

        PrintExpected8x8(pStream, pRecipe, 4);

        pStream << "\n";
        pStream << "    if (!VerifyFull::CheckFull(aBefore, aAfter, aExpected)) {\n";
        pStream << "        Logging::Log(\"Before\", aBefore);\n";
        pStream << "        Logging::Log(\"After\", aAfter);\n";
        pStream << "        XCTFail(@\"%s failed\", sel_getName(_cmd));\n";
        pStream << "        return;\n";
        pStream << "    }\n";
        pStream << "}\n\n";
    }
};

#endif /* TestFileExporter4x4And8x8_hpp */

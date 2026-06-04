//
//  PrintRecipeTool.cpp
//  CyberMatrix
//

#include "PrintRecipeTool.hpp"

#include "M88.hpp"

#include <cstdio>
#include <sstream>

void PrintRecipeTool::ApplyEntryToSlice(Slice &pSlice,
                                        const PrintRecipeToolEntry &pEntry) {
    pSlice.PrepareSlots();

    for (void (Slice::*aFunction)() : pEntry.mFunctions) {
        (pSlice.*aFunction)();
    }

    pSlice.RealizeSlots();
}

Slice PrintRecipeTool::Build4x4Slice(const PrintRecipeToolEntry &pEntry) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aSlice = aMatrix.GetQuadA();

    ApplyEntryToSlice(aSlice, pEntry);

    aMatrix.RecordStart();
    aMatrix.Paste(aSlice);
    aMatrix.RecordStop();

    return aSlice;
}

Slice PrintRecipeTool::Build8x8Slice(const PrintRecipeToolEntry &pEntry) {
    M88 aMatrix;
    aMatrix.Reset();

    Slice aSlice = aMatrix.GetFull();

    ApplyEntryToSlice(aSlice, pEntry);

    aMatrix.RecordStart();
    aMatrix.Paste(aSlice);
    aMatrix.RecordStop();

    return aSlice;
}

std::string PrintRecipeTool::BuildRecipeFactory4x4HPP(const std::vector<PrintRecipeToolEntry> &pEntries) {
    std::ostringstream aStream;

    for (const PrintRecipeToolEntry &aEntry : pEntries) {
        Slice aSlice;
        aSlice.Make(0U, 0U, 4U);

        aStream << aSlice.BuildRecipeFactory4x4HPP(aEntry.mName);
    }

    return aStream.str();
}

std::string PrintRecipeTool::BuildRecipeFactory4x4CPP(const std::vector<PrintRecipeToolEntry> &pEntries) {
    std::ostringstream aStream;

    for (const PrintRecipeToolEntry &aEntry : pEntries) {
        Slice aSlice = Build4x4Slice(aEntry);

        aStream << aSlice.BuildRecipeFactory4x4CPP(aEntry.mName);
    }

    return aStream.str();
}

std::string PrintRecipeTool::BuildRecipeFactory8x8HPP(const std::vector<PrintRecipeToolEntry> &pEntries) {
    std::ostringstream aStream;

    for (const PrintRecipeToolEntry &aEntry : pEntries) {
        Slice aSlice;
        aSlice.Make(0U, 0U, 8U);

        aStream << aSlice.BuildRecipeFactory8x8HPP(aEntry.mName);
    }

    return aStream.str();
}

std::string PrintRecipeTool::BuildRecipeFactory8x8CPP(const std::vector<PrintRecipeToolEntry> &pEntries) {
    std::ostringstream aStream;

    for (const PrintRecipeToolEntry &aEntry : pEntries) {
        Slice aSlice = Build8x8Slice(aEntry);

        aStream << aSlice.BuildRecipeFactory8x8CPP(aEntry.mName);
    }

    return aStream.str();
}

std::string PrintRecipeTool::BuildRecipeFactories(const std::vector<PrintRecipeToolEntry> &pEntries) {
    std::ostringstream aStream;

    aStream << "\n";
    aStream << "// ============================================================\n";
    aStream << "// RecipeFactory4x4.hpp entries\n";
    aStream << "// ============================================================\n\n";
    aStream << BuildRecipeFactory4x4HPP(pEntries);

    aStream << "\n";
    aStream << "// ============================================================\n";
    aStream << "// RecipeFactory4x4.cpp entries\n";
    aStream << "// ============================================================\n\n";
    aStream << BuildRecipeFactory4x4CPP(pEntries);

    aStream << "\n";
    aStream << "// ============================================================\n";
    aStream << "// RecipeFactory8x8.hpp entries\n";
    aStream << "// ============================================================\n\n";
    aStream << BuildRecipeFactory8x8HPP(pEntries);

    aStream << "\n";
    aStream << "// ============================================================\n";
    aStream << "// RecipeFactory8x8.cpp entries\n";
    aStream << "// ============================================================\n\n";
    aStream << BuildRecipeFactory8x8CPP(pEntries);

    return aStream.str();
}

void PrintRecipeTool::PrintRecipeFactories(const std::vector<PrintRecipeToolEntry> &pEntries) {
    const std::string aText = BuildRecipeFactories(pEntries);

    std::printf("%s", aText.c_str());
}

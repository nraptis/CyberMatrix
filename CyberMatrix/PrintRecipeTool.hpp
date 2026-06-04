//
//  PrintRecipeTool.hpp
//  CyberMatrix
//

#ifndef PrintRecipeTool_hpp
#define PrintRecipeTool_hpp

#include "M88Slice.hpp"

#include <string>
#include <vector>

struct PrintRecipeToolEntry {
    std::string mName;
    std::vector<void (Slice::*)()> mFunctions;
};

class PrintRecipeTool {
public:

    static std::string BuildRecipeFactories(const std::vector<PrintRecipeToolEntry> &pEntries);

    static std::string BuildRecipeFactory4x4HPP(const std::vector<PrintRecipeToolEntry> &pEntries);
    static std::string BuildRecipeFactory4x4CPP(const std::vector<PrintRecipeToolEntry> &pEntries);

    static std::string BuildRecipeFactory8x8HPP(const std::vector<PrintRecipeToolEntry> &pEntries);
    static std::string BuildRecipeFactory8x8CPP(const std::vector<PrintRecipeToolEntry> &pEntries);

    static void PrintRecipeFactories(const std::vector<PrintRecipeToolEntry> &pEntries);

private:

    static void ApplyEntryToSlice(Slice &pSlice,
                                  const PrintRecipeToolEntry &pEntry);

    static Slice Build4x4Slice(const PrintRecipeToolEntry &pEntry);
    static Slice Build8x8Slice(const PrintRecipeToolEntry &pEntry);
};

#endif /* PrintRecipeTool_hpp */

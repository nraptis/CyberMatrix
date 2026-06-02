//
//  RecipeScaler.cpp
//  CyberMatrix
//
//  Created by Wu Tang on 6/1/26.
//

#include "RecipeScaler.hpp"
#include <cstdint>
#include <vector>

Recipe4x4 RecipeScaler::Scale2x2To4x4(const Recipe2x2 &pRecipe) {
    Recipe4x4 aResult = { pRecipe.mName, {} };

    for (std::size_t destY = 0U; destY < 2U; destY++) {
        for (std::size_t destX = 0U; destX < 2U; destX++) {
            const std::uint8_t aSourceBlock = pRecipe.mMap[destY][destX];
            const std::size_t sourceX = aSourceBlock & 1U;
            const std::size_t sourceY = aSourceBlock >> 1U;
            const std::size_t destBaseX = destX * 2U;
            const std::size_t destBaseY = destY * 2U;
            const std::size_t sourceBaseX = sourceX * 2U;
            const std::size_t sourceBaseY = sourceY * 2U;

            aResult.mMap[destBaseY][destBaseX] =
                static_cast<std::uint8_t>(sourceBaseY * 4U + sourceBaseX);

            aResult.mMap[destBaseY][destBaseX + 1U] =
                static_cast<std::uint8_t>(sourceBaseY * 4U + sourceBaseX + 1U);

            aResult.mMap[destBaseY + 1U][destBaseX] =
                static_cast<std::uint8_t>((sourceBaseY + 1U) * 4U + sourceBaseX);

            aResult.mMap[destBaseY + 1U][destBaseX + 1U] =
                static_cast<std::uint8_t>((sourceBaseY + 1U) * 4U + sourceBaseX + 1U);
        }
    }

    return aResult;
}

Recipe8x8 RecipeScaler::Scale4x4To8x8(const Recipe4x4 &pRecipe) {
    Recipe8x8 aResult = { pRecipe.mName, {} };

    for (std::size_t destY = 0U; destY < 4U; destY++) {
        for (std::size_t destX = 0U; destX < 4U; destX++) {
            const std::uint8_t aSourceBlock = pRecipe.mMap[destY][destX];

            const std::size_t sourceX = aSourceBlock & 3U;
            const std::size_t sourceY = aSourceBlock >> 2U;

            const std::size_t destBaseX = destX * 2U;
            const std::size_t destBaseY = destY * 2U;

            const std::size_t sourceBaseX = sourceX * 2U;
            const std::size_t sourceBaseY = sourceY * 2U;

            aResult.mMap[destBaseY][destBaseX] =
                static_cast<std::uint8_t>(sourceBaseY * 8U + sourceBaseX);

            aResult.mMap[destBaseY][destBaseX + 1U] =
                static_cast<std::uint8_t>(sourceBaseY * 8U + sourceBaseX + 1U);

            aResult.mMap[destBaseY + 1U][destBaseX] =
                static_cast<std::uint8_t>((sourceBaseY + 1U) * 8U + sourceBaseX);

            aResult.mMap[destBaseY + 1U][destBaseX + 1U] =
                static_cast<std::uint8_t>((sourceBaseY + 1U) * 8U + sourceBaseX + 1U);
        }
    }

    return aResult;
}

Recipe8x8 RecipeScaler::Scale2x2To8x8(const Recipe2x2 &pRecipe) {
    const Recipe4x4 aRecipe4x4 = Scale2x2To4x4(pRecipe);
    return Scale4x4To8x8(aRecipe4x4);
}

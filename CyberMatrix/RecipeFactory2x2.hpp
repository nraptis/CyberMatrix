//
//  RecipeFactory2x2.hpp
//  CyberMatrix
//

#ifndef RecipeFactory2x2_hpp
#define RecipeFactory2x2_hpp

#include <cstdint>

struct Recipe2x2 {
    const char  *mName;
    std::uint8_t mMap[2][2];
};

class RecipeFactory2x2 {
public:
    
    // Rotations
    static Recipe2x2 RotA();      // rotate right
    static Recipe2x2 RotB();      // rotate left
    static Recipe2x2 RotC();      // rotate 180

    // Reflections / transposes
    static Recipe2x2 FlipA();     // horizontal
    static Recipe2x2 FlipB();     // vertical
    static Recipe2x2 FlipC();     // main diagonal transpose
    static Recipe2x2 FlipD();     // anti diagonal transpose

    // Single swaps
    static Recipe2x2 SwapA();     // AB
    static Recipe2x2 SwapB();     // AC
    static Recipe2x2 SwapC();     // BD
    static Recipe2x2 SwapD();     // CD

    // 3-cycles
    static Recipe2x2 TriadA();    // BCAD
    static Recipe2x2 TriadB();    // CABD
    static Recipe2x2 TriadC();    // BDCA
    static Recipe2x2 TriadD();    // DACB
    static Recipe2x2 TriadE();    // CBDA
    static Recipe2x2 TriadF();    // DBAC
    static Recipe2x2 TriadG();    // ACDB
    static Recipe2x2 TriadH();    // ADBC

    // 4-layouts / snakes
    static Recipe2x2 SnakeA();    // BCDA
    static Recipe2x2 SnakeB();    // DABC
    static Recipe2x2 SnakeC();    // CDBA
    static Recipe2x2 SnakeD();    // DCAB

private:
    static Recipe2x2 Make(const char *pName,
                          std::uint8_t pA,
                          std::uint8_t pB,
                          std::uint8_t pC,
                          std::uint8_t pD);
};

#endif /* RecipeFactory2x2_hpp */

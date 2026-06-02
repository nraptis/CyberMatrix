//
//  RecipeFactory4x4.hpp
//  CyberMatrix
//

#ifndef RecipeFactory4x4_hpp
#define RecipeFactory4x4_hpp

#include <cstdint>

struct Recipe4x4 {
    const char  *mName;
    std::uint8_t mMap[4][4];
};

class RecipeFactory4x4 {
public:
    static Recipe4x4        Identity();

    // Rotations
    static Recipe4x4        RotA();
    static Recipe4x4        RotB();
    static Recipe4x4        RotC();
    
    static Recipe4x4        FlipA();
    static Recipe4x4        FlipB();
    static Recipe4x4        FlipC();
    static Recipe4x4        FlipD();
    
    static Recipe4x4        PinA();
    static Recipe4x4        PinB();
    
    static Recipe4x4        CastleA();
    static Recipe4x4        CastleB();
    static Recipe4x4        CastleC();
    static Recipe4x4        CastleD();
    
    static Recipe4x4        TowerA();
    static Recipe4x4        TowerB();
    
    static Recipe4x4        FortressA();
    static Recipe4x4        FortressB();
    
private:
    static Recipe4x4 Make(const char *pName,
                          std::uint8_t p00,
                          std::uint8_t p01,
                          std::uint8_t p02,
                          std::uint8_t p03,
                          std::uint8_t p10,
                          std::uint8_t p11,
                          std::uint8_t p12,
                          std::uint8_t p13,
                          std::uint8_t p20,
                          std::uint8_t p21,
                          std::uint8_t p22,
                          std::uint8_t p23,
                          std::uint8_t p30,
                          std::uint8_t p31,
                          std::uint8_t p32,
                          std::uint8_t p33);
};

#endif /* RecipeFactory4x4_hpp */

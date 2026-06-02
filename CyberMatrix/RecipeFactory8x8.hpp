//
//  RecipeFactory8x8.hpp
//  CyberMatrix
//

#ifndef RecipeFactory8x8_hpp
#define RecipeFactory8x8_hpp

#include <cstdint>

struct Recipe8x8 {
    const char  *mName;
    std::uint8_t mMap[8][8];
};

class RecipeFactory8x8 {
public:
    static Recipe8x8        Identity();
    
    // Rotations
    static Recipe8x8        RotA();
    static Recipe8x8        RotB();
    static Recipe8x8        RotC();
    
    static Recipe8x8        FlipA();
    static Recipe8x8        FlipB();
    static Recipe8x8        FlipC();
    static Recipe8x8        FlipD();
    
    
    
    static Recipe8x8        PinA();
    static Recipe8x8        PinB();
    
    
private:
    static Recipe8x8        MakeIdentityNamed(const char *pName);
    
    static Recipe8x8        Make(const char *pName,
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
                                 std::uint8_t p74, std::uint8_t p75, std::uint8_t p76, std::uint8_t p77);
};

#endif /* RecipeFactory8x8_hpp */

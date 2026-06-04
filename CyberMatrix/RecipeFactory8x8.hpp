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
    static Recipe8x8                    Identity();
    
    // Rotations
    static Recipe8x8                    RotA();
    static Recipe8x8                    RotB();
    static Recipe8x8                    RotC();
    
    static Recipe8x8                    FlipA();
    static Recipe8x8                    FlipB();
    static Recipe8x8                    FlipC();
    static Recipe8x8                    FlipD();
    
    static Recipe8x8                    PinA();
    static Recipe8x8                    PinB();

    
    static Recipe8x8                    ShearA();
    static Recipe8x8                    ShearB();
    static Recipe8x8                    ShearC();
    static Recipe8x8                    ShearD();

    static Recipe8x8                    JewelA();
    static Recipe8x8                    JewelB();
    static Recipe8x8                    JewelC();
    static Recipe8x8                    JewelD();
    
    static Recipe8x8                    CrystalA();
    static Recipe8x8                    CrystalC();
    static Recipe8x8                    CrystalB();
    static Recipe8x8                    CrystalD();
    
    
    static Recipe8x8                    OpalA();
    static Recipe8x8                    OpalC();
    static Recipe8x8                    OpalB();
    static Recipe8x8                    OpalD();
    
    
    static Recipe8x8                    PeridotA();
    static Recipe8x8                    PeridotB();
    static Recipe8x8                    PeridotC();
    static Recipe8x8                    PeridotD();
    
    
    static Recipe8x8                    SwanA();
    static Recipe8x8                    SwanB();
    static Recipe8x8                    SwanC();
    static Recipe8x8                    SwanD();
    static Recipe8x8                    GooseA();
    static Recipe8x8                    GooseB();
    static Recipe8x8                    GooseC();
    static Recipe8x8                    GooseD();
    
    static Recipe8x8                    HeronA();
    static Recipe8x8                    HeronB();
    static Recipe8x8                    HeronC();
    static Recipe8x8                    HeronD();
    static Recipe8x8                    FalconA();
    static Recipe8x8                    FalconB();
    static Recipe8x8                    FalconC();
    static Recipe8x8                    FalconD();
    
    
    static Recipe8x8                    IronA();
    static Recipe8x8                    IronB();
    static Recipe8x8                    IronC();
    static Recipe8x8                    IronD();
    static Recipe8x8                    SteelA();
    static Recipe8x8                    SteelB();
    static Recipe8x8                    SteelC();
    static Recipe8x8                    SteelD();
    static Recipe8x8                    SilverA();
    static Recipe8x8                    SilverB();
    static Recipe8x8                    SilverC();
    static Recipe8x8                    SilverD();
    static Recipe8x8                    GoldA();
    static Recipe8x8                    GoldB();
    static Recipe8x8                    GoldC();
    static Recipe8x8                    GoldD();
    static Recipe8x8                    BronzeA();
    static Recipe8x8                    BronzeB();
    static Recipe8x8                    BronzeC();
    static Recipe8x8                    BronzeD();
    static Recipe8x8                    BrassA();
    static Recipe8x8                    BrassB();
    static Recipe8x8                    BrassC();
    static Recipe8x8                    BrassD();
    static Recipe8x8                    NickelA();
    static Recipe8x8                    NickelB();
    static Recipe8x8                    NickelC();
    static Recipe8x8                    NickelD();
    static Recipe8x8                    CobaltA();
    static Recipe8x8                    CobaltB();
    static Recipe8x8                    CobaltC();
    static Recipe8x8                    CobaltD();
    static Recipe8x8                    TitaniumA();
    static Recipe8x8                    TitaniumB();
    static Recipe8x8                    TitaniumC();
    static Recipe8x8                    TitaniumD();
    static Recipe8x8                    PlatinumA();
    static Recipe8x8                    PlatinumB();
    static Recipe8x8                    PlatinumC();
    static Recipe8x8                    PlatinumD();
    static Recipe8x8                    TungstenA();
    static Recipe8x8                    TungstenB();
    static Recipe8x8                    TungstenC();
    static Recipe8x8                    TungstenD();
    static Recipe8x8                    MercuryA();
    static Recipe8x8                    MercuryB();
    static Recipe8x8                    MercuryC();
    static Recipe8x8                    MercuryD();
    static Recipe8x8                    PalladiumA();
    static Recipe8x8                    PalladiumB();
    static Recipe8x8                    PalladiumC();
    static Recipe8x8                    PalladiumD();
    static Recipe8x8                    RhodiumA();
    static Recipe8x8                    RhodiumB();
    static Recipe8x8                    RhodiumC();
    static Recipe8x8                    RhodiumD();
    static Recipe8x8                    ChromiumA();
    static Recipe8x8                    ChromiumB();
    static Recipe8x8                    ChromiumC();
    static Recipe8x8                    ChromiumD();
    static Recipe8x8                    ZirconiumA();
    static Recipe8x8                    ZirconiumB();
    static Recipe8x8                    ZirconiumC();
    static Recipe8x8                    ZirconiumD();
    
    
    
    
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

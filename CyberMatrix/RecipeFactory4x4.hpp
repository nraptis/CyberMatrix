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

    static Recipe4x4        ShearA();
    static Recipe4x4        ShearB();
    static Recipe4x4        ShearC();
    static Recipe4x4        ShearD();
    
    static Recipe4x4        CastleA();
    static Recipe4x4        CastleB();
    static Recipe4x4        CastleC();
    static Recipe4x4        CastleD();
    
    static Recipe4x4        TowerA();
    static Recipe4x4        TowerB();
    
    static Recipe4x4        FortressA();
    static Recipe4x4        FortressB();
    
    static Recipe4x4        JewelA();
    static Recipe4x4        JewelB();
    static Recipe4x4        JewelC();
    static Recipe4x4        JewelD();
    
    
    static Recipe4x4        CrystalA();
    static Recipe4x4        CrystalC();
    static Recipe4x4        CrystalB();
    static Recipe4x4        CrystalD();
    
    
    static Recipe4x4        OpalA();
    static Recipe4x4        OpalC();
    static Recipe4x4        OpalB();
    static Recipe4x4        OpalD();
    
    
    static Recipe4x4                    PeridotA();
    static Recipe4x4                    PeridotB();
    static Recipe4x4                    PeridotC();
    static Recipe4x4                    PeridotD();
    
    
    static Recipe4x4                    SwanA();
    static Recipe4x4                    SwanB();
    static Recipe4x4                    SwanC();
    static Recipe4x4                    SwanD();
    static Recipe4x4                    GooseA();
    static Recipe4x4                    GooseB();
    static Recipe4x4                    GooseC();
    static Recipe4x4                    GooseD();
    
    static Recipe4x4                    HeronA();
    static Recipe4x4                    HeronB();
    static Recipe4x4                    HeronC();
    static Recipe4x4                    HeronD();
    static Recipe4x4                    FalconA();
    static Recipe4x4                    FalconB();
    static Recipe4x4                    FalconC();
    static Recipe4x4                    FalconD();
    
    
    static Recipe4x4                    IronA();
    static Recipe4x4                    IronB();
    static Recipe4x4                    IronC();
    static Recipe4x4                    IronD();
    static Recipe4x4                    SteelA();
    static Recipe4x4                    SteelB();
    static Recipe4x4                    SteelC();
    static Recipe4x4                    SteelD();
    static Recipe4x4                    SilverA();
    static Recipe4x4                    SilverB();
    static Recipe4x4                    SilverC();
    static Recipe4x4                    SilverD();
    static Recipe4x4                    GoldA();
    static Recipe4x4                    GoldB();
    static Recipe4x4                    GoldC();
    static Recipe4x4                    GoldD();
    static Recipe4x4                    BronzeA();
    static Recipe4x4                    BronzeB();
    static Recipe4x4                    BronzeC();
    static Recipe4x4                    BronzeD();
    static Recipe4x4                    BrassA();
    static Recipe4x4                    BrassB();
    static Recipe4x4                    BrassC();
    static Recipe4x4                    BrassD();
    static Recipe4x4                    NickelA();
    static Recipe4x4                    NickelB();
    static Recipe4x4                    NickelC();
    static Recipe4x4                    NickelD();
    static Recipe4x4                    CobaltA();
    static Recipe4x4                    CobaltB();
    static Recipe4x4                    CobaltC();
    static Recipe4x4                    CobaltD();
    static Recipe4x4                    TitaniumA();
    static Recipe4x4                    TitaniumB();
    static Recipe4x4                    TitaniumC();
    static Recipe4x4                    TitaniumD();
    static Recipe4x4                    PlatinumA();
    static Recipe4x4                    PlatinumB();
    static Recipe4x4                    PlatinumC();
    static Recipe4x4                    PlatinumD();
    static Recipe4x4                    TungstenA();
    static Recipe4x4                    TungstenB();
    static Recipe4x4                    TungstenC();
    static Recipe4x4                    TungstenD();
    static Recipe4x4                    MercuryA();
    static Recipe4x4                    MercuryB();
    static Recipe4x4                    MercuryC();
    static Recipe4x4                    MercuryD();
    static Recipe4x4                    PalladiumA();
    static Recipe4x4                    PalladiumB();
    static Recipe4x4                    PalladiumC();
    static Recipe4x4                    PalladiumD();
    static Recipe4x4                    RhodiumA();
    static Recipe4x4                    RhodiumB();
    static Recipe4x4                    RhodiumC();
    static Recipe4x4                    RhodiumD();
    static Recipe4x4                    ChromiumA();
    static Recipe4x4                    ChromiumB();
    static Recipe4x4                    ChromiumC();
    static Recipe4x4                    ChromiumD();
    static Recipe4x4                    ZirconiumA();
    static Recipe4x4                    ZirconiumB();
    static Recipe4x4                    ZirconiumC();
    static Recipe4x4                    ZirconiumD();
    
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

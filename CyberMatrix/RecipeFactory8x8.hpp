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
    
    static Recipe8x8                    HydrogenA();
    static Recipe8x8                    HydrogenB();
    static Recipe8x8                    HydrogenC();
    static Recipe8x8                    HydrogenD();
    static Recipe8x8                    HeliumA();
    static Recipe8x8                    HeliumB();
    static Recipe8x8                    HeliumC();
    static Recipe8x8                    HeliumD();
    static Recipe8x8                    NeonA();
    static Recipe8x8                    NeonB();
    static Recipe8x8                    NeonC();
    static Recipe8x8                    NeonD();
    static Recipe8x8                    ArgonA();
    static Recipe8x8                    ArgonB();
    static Recipe8x8                    ArgonC();
    static Recipe8x8                    ArgonD();
    static Recipe8x8                    KryptonA();
    static Recipe8x8                    KryptonB();
    static Recipe8x8                    KryptonC();
    static Recipe8x8                    KryptonD();
    static Recipe8x8                    XenonA();
    static Recipe8x8                    XenonB();
    static Recipe8x8                    XenonC();
    static Recipe8x8                    XenonD();
    static Recipe8x8                    RadonA();
    static Recipe8x8                    RadonB();
    static Recipe8x8                    RadonC();
    static Recipe8x8                    RadonD();
    static Recipe8x8                    FluorineA();
    static Recipe8x8                    FluorineB();
    static Recipe8x8                    FluorineC();
    static Recipe8x8                    FluorineD();
    static Recipe8x8                    ChlorineA();
    static Recipe8x8                    ChlorineB();
    static Recipe8x8                    ChlorineC();
    static Recipe8x8                    ChlorineD();
    
    static Recipe8x8                    MapleA();
    static Recipe8x8                    MapleB();
    static Recipe8x8                    MapleC();
    static Recipe8x8                    MapleD();
    static Recipe8x8                    WillowA();
    static Recipe8x8                    WillowB();
    static Recipe8x8                    WillowC();
    static Recipe8x8                    WillowD();
    static Recipe8x8                    BirchA();
    static Recipe8x8                    BirchB();
    static Recipe8x8                    BirchC();
    static Recipe8x8                    BirchD();
    static Recipe8x8                    CedarA();
    static Recipe8x8                    CedarB();
    static Recipe8x8                    CedarC();
    static Recipe8x8                    CedarD();
    static Recipe8x8                    HickoryA();
    static Recipe8x8                    HickoryB();
    static Recipe8x8                    HickoryC();
    static Recipe8x8                    HickoryD();
    static Recipe8x8                    JuniperA();
    static Recipe8x8                    JuniperB();
    static Recipe8x8                    JuniperC();
    static Recipe8x8                    JuniperD();
    
    
    static Recipe8x8                    YorkA();
    static Recipe8x8                    YorkB();
    static Recipe8x8                    YorkC();
    static Recipe8x8                    YorkD();
    static Recipe8x8                    EssexA();
    static Recipe8x8                    EssexB();
    static Recipe8x8                    EssexC();
    static Recipe8x8                    EssexD();
    static Recipe8x8                    WessexA();
    static Recipe8x8                    WessexB();
    static Recipe8x8                    WessexC();
    static Recipe8x8                    WessexD();
    static Recipe8x8                    MerciaA();
    static Recipe8x8                    MerciaB();
    static Recipe8x8                    MerciaC();
    static Recipe8x8                    MerciaD();
    static Recipe8x8                    SussexA();
    static Recipe8x8                    SussexB();
    static Recipe8x8                    SussexC();
    static Recipe8x8                    SussexD();
    static Recipe8x8                    UmbriaA();
    static Recipe8x8                    UmbriaB();
    static Recipe8x8                    UmbriaC();
    static Recipe8x8                    UmbriaD();
    
    
    static Recipe8x8                    TokyoA();
    static Recipe8x8                    TokyoB();
    static Recipe8x8                    TokyoC();
    static Recipe8x8                    TokyoD();
    static Recipe8x8                    KyotoA();
    static Recipe8x8                    KyotoB();
    static Recipe8x8                    KyotoC();
    static Recipe8x8                    KyotoD();
    static Recipe8x8                    OsakaA();
    static Recipe8x8                    OsakaB();
    static Recipe8x8                    OsakaC();
    static Recipe8x8                    OsakaD();
    static Recipe8x8                    NaraA();
    static Recipe8x8                    NaraB();
    static Recipe8x8                    NaraC();
    static Recipe8x8                    NaraD();
    static Recipe8x8                    KobeA();
    static Recipe8x8                    KobeB();
    static Recipe8x8                    KobeC();
    static Recipe8x8                    KobeD();
    static Recipe8x8                    SapporoA();
    static Recipe8x8                    SapporoB();
    static Recipe8x8                    SapporoC();
    static Recipe8x8                    SapporoD();
    static Recipe8x8                    NagoyaA();
    static Recipe8x8                    NagoyaB();
    static Recipe8x8                    NagoyaC();
    static Recipe8x8                    NagoyaD();
    static Recipe8x8                    FukuokaA();
    static Recipe8x8                    FukuokaB();
    static Recipe8x8                    FukuokaC();
    static Recipe8x8                    FukuokaD();
    
    static Recipe8x8                    GlendaleA();
    static Recipe8x8                    GlendaleB();
    static Recipe8x8                    GlendaleC();
    static Recipe8x8                    GlendaleD();
    static Recipe8x8                    BurbankA();
    static Recipe8x8                    BurbankB();
    static Recipe8x8                    BurbankC();
    static Recipe8x8                    BurbankD();
    static Recipe8x8                    InglewoodA();
    static Recipe8x8                    InglewoodB();
    static Recipe8x8                    InglewoodC();
    static Recipe8x8                    InglewoodD();
    static Recipe8x8                    PasadenaA();
    static Recipe8x8                    PasadenaB();
    static Recipe8x8                    PasadenaC();
    static Recipe8x8                    PasadenaD();
    static Recipe8x8                    TorranceA();
    static Recipe8x8                    TorranceB();
    static Recipe8x8                    TorranceC();
    static Recipe8x8                    TorranceD();
    static Recipe8x8                    HawthorneA();
    static Recipe8x8                    HawthorneB();
    static Recipe8x8                    HawthorneC();
    static Recipe8x8                    HawthorneD();
    
    static Recipe8x8                    WizardA();
    static Recipe8x8                    WizardB();
    static Recipe8x8                    WizardC();
    static Recipe8x8                    WizardD();
    
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

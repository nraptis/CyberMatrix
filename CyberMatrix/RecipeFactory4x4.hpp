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


    static Recipe4x4                    HydrogenA();
    static Recipe4x4                    HydrogenB();
    static Recipe4x4                    HydrogenC();
    static Recipe4x4                    HydrogenD();
    static Recipe4x4                    HeliumA();
    static Recipe4x4                    HeliumB();
    static Recipe4x4                    HeliumC();
    static Recipe4x4                    HeliumD();
    static Recipe4x4                    NeonA();
    static Recipe4x4                    NeonB();
    static Recipe4x4                    NeonC();
    static Recipe4x4                    NeonD();
    static Recipe4x4                    ArgonA();
    static Recipe4x4                    ArgonB();
    static Recipe4x4                    ArgonC();
    static Recipe4x4                    ArgonD();
    static Recipe4x4                    KryptonA();
    static Recipe4x4                    KryptonB();
    static Recipe4x4                    KryptonC();
    static Recipe4x4                    KryptonD();
    static Recipe4x4                    XenonA();
    static Recipe4x4                    XenonB();
    static Recipe4x4                    XenonC();
    static Recipe4x4                    XenonD();
    static Recipe4x4                    RadonA();
    static Recipe4x4                    RadonB();
    static Recipe4x4                    RadonC();
    static Recipe4x4                    RadonD();
    static Recipe4x4                    FluorineA();
    static Recipe4x4                    FluorineB();
    static Recipe4x4                    FluorineC();
    static Recipe4x4                    FluorineD();
    static Recipe4x4                    ChlorineA();
    static Recipe4x4                    ChlorineB();
    static Recipe4x4                    ChlorineC();
    static Recipe4x4                    ChlorineD();


    static Recipe4x4                    MapleA();
    static Recipe4x4                    MapleB();
    static Recipe4x4                    MapleC();
    static Recipe4x4                    MapleD();
    static Recipe4x4                    WillowA();
    static Recipe4x4                    WillowB();
    static Recipe4x4                    WillowC();
    static Recipe4x4                    WillowD();
    static Recipe4x4                    BirchA();
    static Recipe4x4                    BirchB();
    static Recipe4x4                    BirchC();
    static Recipe4x4                    BirchD();
    static Recipe4x4                    CedarA();
    static Recipe4x4                    CedarB();
    static Recipe4x4                    CedarC();
    static Recipe4x4                    CedarD();
    static Recipe4x4                    HickoryA();
    static Recipe4x4                    HickoryB();
    static Recipe4x4                    HickoryC();
    static Recipe4x4                    HickoryD();
    static Recipe4x4                    JuniperA();
    static Recipe4x4                    JuniperB();
    static Recipe4x4                    JuniperC();
    static Recipe4x4                    JuniperD();

    static Recipe4x4                    YorkA();
    static Recipe4x4                    YorkB();
    static Recipe4x4                    YorkC();
    static Recipe4x4                    YorkD();
    static Recipe4x4                    EssexA();
    static Recipe4x4                    EssexB();
    static Recipe4x4                    EssexC();
    static Recipe4x4                    EssexD();
    static Recipe4x4                    WessexA();
    static Recipe4x4                    WessexB();
    static Recipe4x4                    WessexC();
    static Recipe4x4                    WessexD();
    static Recipe4x4                    MerciaA();
    static Recipe4x4                    MerciaB();
    static Recipe4x4                    MerciaC();
    static Recipe4x4                    MerciaD();
    static Recipe4x4                    SussexA();
    static Recipe4x4                    SussexB();
    static Recipe4x4                    SussexC();
    static Recipe4x4                    SussexD();
    static Recipe4x4                    UmbriaA();
    static Recipe4x4                    UmbriaB();
    static Recipe4x4                    UmbriaC();
    static Recipe4x4                    UmbriaD();


    static Recipe4x4                    TokyoA();
    static Recipe4x4                    TokyoB();
    static Recipe4x4                    TokyoC();
    static Recipe4x4                    TokyoD();
    static Recipe4x4                    KyotoA();
    static Recipe4x4                    KyotoB();
    static Recipe4x4                    KyotoC();
    static Recipe4x4                    KyotoD();
    static Recipe4x4                    OsakaA();
    static Recipe4x4                    OsakaB();
    static Recipe4x4                    OsakaC();
    static Recipe4x4                    OsakaD();
    static Recipe4x4                    NaraA();
    static Recipe4x4                    NaraB();
    static Recipe4x4                    NaraC();
    static Recipe4x4                    NaraD();
    static Recipe4x4                    KobeA();
    static Recipe4x4                    KobeB();
    static Recipe4x4                    KobeC();
    static Recipe4x4                    KobeD();
    static Recipe4x4                    SapporoA();
    static Recipe4x4                    SapporoB();
    static Recipe4x4                    SapporoC();
    static Recipe4x4                    SapporoD();
    static Recipe4x4                    NagoyaA();
    static Recipe4x4                    NagoyaB();
    static Recipe4x4                    NagoyaC();
    static Recipe4x4                    NagoyaD();
    static Recipe4x4                    FukuokaA();
    static Recipe4x4                    FukuokaB();
    static Recipe4x4                    FukuokaC();
    static Recipe4x4                    FukuokaD();

    static Recipe4x4                    GlendaleA();
    static Recipe4x4                    GlendaleB();
    static Recipe4x4                    GlendaleC();
    static Recipe4x4                    GlendaleD();
    static Recipe4x4                    BurbankA();
    static Recipe4x4                    BurbankB();
    static Recipe4x4                    BurbankC();
    static Recipe4x4                    BurbankD();
    static Recipe4x4                    InglewoodA();
    static Recipe4x4                    InglewoodB();
    static Recipe4x4                    InglewoodC();
    static Recipe4x4                    InglewoodD();
    static Recipe4x4                    PasadenaA();
    static Recipe4x4                    PasadenaB();
    static Recipe4x4                    PasadenaC();
    static Recipe4x4                    PasadenaD();
    static Recipe4x4                    TorranceA();
    static Recipe4x4                    TorranceB();
    static Recipe4x4                    TorranceC();
    static Recipe4x4                    TorranceD();
    static Recipe4x4                    HawthorneA();
    static Recipe4x4                    HawthorneB();
    static Recipe4x4                    HawthorneC();
    static Recipe4x4                    HawthorneD();


    static Recipe4x4                    WizardA();
    static Recipe4x4                    WizardB();
    static Recipe4x4                    WizardC();
    static Recipe4x4                    WizardD();
    
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

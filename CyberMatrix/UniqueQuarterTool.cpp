//
//  UniqueQuarterTool.cpp
//  CyberMatrix
//

#include "UniqueQuarterTool.hpp"

#include <algorithm>
#include <cstdio>

static constexpr std::size_t kCandidateDistanceWarningThreshold = 8U;

static const std::vector<UniqueQuarterExistingOp> kExistingQuarterAOps = {
    
    { "Identity",             &M88::Reset },
    
    { "Quad_RotA_2x2_A",             &M88::Quad_RotA_2x2_A },
    { "Quad_RotA_EachMini_2x2_A",    &M88::Quad_RotA_EachMini_2x2_A },
    { "Quad_RotB_2x2_A",             &M88::Quad_RotB_2x2_A },
    { "Quad_RotB_EachMini_2x2_A",    &M88::Quad_RotB_EachMini_2x2_A },
    { "Quad_RotC_2x2_A",             &M88::Quad_RotC_2x2_A },
    { "Quad_RotC_EachMini_2x2_A",    &M88::Quad_RotC_EachMini_2x2_A },

    { "Quad_FlipA_2x2_A",            &M88::Quad_FlipA_2x2_A },
    { "Quad_FlipA_EachMini_2x2_A",   &M88::Quad_FlipA_EachMini_2x2_A },
    { "Quad_FlipB_2x2_A",            &M88::Quad_FlipB_2x2_A },
    { "Quad_FlipB_EachMini_2x2_A",   &M88::Quad_FlipB_EachMini_2x2_A },
    { "Quad_FlipC_2x2_A",            &M88::Quad_FlipC_2x2_A },
    { "Quad_FlipC_EachMini_2x2_A",   &M88::Quad_FlipC_EachMini_2x2_A },
    { "Quad_FlipD_2x2_A",            &M88::Quad_FlipD_2x2_A },
    { "Quad_FlipD_EachMini_2x2_A",   &M88::Quad_FlipD_EachMini_2x2_A },

    { "Quad_TriadA_2x2_A",           &M88::Quad_TriadA_2x2_A },
    { "Quad_TriadA_EachMini_2x2_A",  &M88::Quad_TriadA_EachMini_2x2_A },
    { "Quad_TriadB_2x2_A",           &M88::Quad_TriadB_2x2_A },
    { "Quad_TriadB_EachMini_2x2_A",  &M88::Quad_TriadB_EachMini_2x2_A },
    { "Quad_TriadC_2x2_A",           &M88::Quad_TriadC_2x2_A },
    { "Quad_TriadC_EachMini_2x2_A",  &M88::Quad_TriadC_EachMini_2x2_A },
    { "Quad_TriadD_2x2_A",           &M88::Quad_TriadD_2x2_A },
    { "Quad_TriadD_EachMini_2x2_A",  &M88::Quad_TriadD_EachMini_2x2_A },
    { "Quad_TriadE_2x2_A",           &M88::Quad_TriadE_2x2_A },
    { "Quad_TriadE_EachMini_2x2_A",  &M88::Quad_TriadE_EachMini_2x2_A },
    { "Quad_TriadF_2x2_A",           &M88::Quad_TriadF_2x2_A },
    { "Quad_TriadF_EachMini_2x2_A",  &M88::Quad_TriadF_EachMini_2x2_A },
    { "Quad_TriadG_2x2_A",           &M88::Quad_TriadG_2x2_A },
    { "Quad_TriadG_EachMini_2x2_A",  &M88::Quad_TriadG_EachMini_2x2_A },
    { "Quad_TriadH_2x2_A",           &M88::Quad_TriadH_2x2_A },
    { "Quad_TriadH_EachMini_2x2_A",  &M88::Quad_TriadH_EachMini_2x2_A },

    { "Quad_SnakeA_2x2_A",           &M88::Quad_SnakeA_2x2_A },
    { "Quad_SnakeA_EachMini_2x2_A",  &M88::Quad_SnakeA_EachMini_2x2_A },
    { "Quad_SnakeB_2x2_A",           &M88::Quad_SnakeB_2x2_A },
    { "Quad_SnakeB_EachMini_2x2_A",  &M88::Quad_SnakeB_EachMini_2x2_A },
    { "Quad_SnakeC_2x2_A",           &M88::Quad_SnakeC_2x2_A },
    { "Quad_SnakeC_EachMini_2x2_A",  &M88::Quad_SnakeC_EachMini_2x2_A },
    { "Quad_SnakeD_2x2_A",           &M88::Quad_SnakeD_2x2_A },
    { "Quad_SnakeD_EachMini_2x2_A",  &M88::Quad_SnakeD_EachMini_2x2_A },

    { "Quad_SwapA_2x2_A",            &M88::Quad_SwapA_2x2_A },
    { "Quad_SwapA_EachMini_2x2_A",   &M88::Quad_SwapA_EachMini_2x2_A },
    { "Quad_SwapB_2x2_A",            &M88::Quad_SwapB_2x2_A },
    { "Quad_SwapB_EachMini_2x2_A",   &M88::Quad_SwapB_EachMini_2x2_A },
    { "Quad_SwapC_2x2_A",            &M88::Quad_SwapC_2x2_A },
    { "Quad_SwapC_EachMini_2x2_A",   &M88::Quad_SwapC_EachMini_2x2_A },
    { "Quad_SwapD_2x2_A",            &M88::Quad_SwapD_2x2_A },
    { "Quad_SwapD_EachMini_2x2_A",   &M88::Quad_SwapD_EachMini_2x2_A },
    
    
    { "Quad_RotA_4x4_A",      &M88::Quad_RotA_4x4_A },
    { "Quad_RotB_4x4_A",      &M88::Quad_RotB_4x4_A },
    { "Quad_RotC_4x4_A",      &M88::Quad_RotC_4x4_A },

    { "Quad_FlipA_4x4_A",     &M88::Quad_FlipA_4x4_A },
    { "Quad_FlipB_4x4_A",     &M88::Quad_FlipB_4x4_A },
    { "Quad_FlipC_4x4_A",     &M88::Quad_FlipC_4x4_A },
    { "Quad_FlipD_4x4_A",     &M88::Quad_FlipD_4x4_A },

    { "Quad_TowerA_4x4_A",    &M88::Quad_TowerA_4x4_A },
    { "Quad_TowerB_4x4_A",    &M88::Quad_TowerB_4x4_A },

    { "Quad_ShearA_4x4_A",    &M88::Quad_ShearA_4x4_A },
    { "Quad_ShearB_4x4_A",    &M88::Quad_ShearB_4x4_A },
    { "Quad_ShearC_4x4_A",    &M88::Quad_ShearC_4x4_A },
    { "Quad_ShearD_4x4_A",    &M88::Quad_ShearD_4x4_A },
    
    { "Quad_JewelA_4x4_A",    &M88::Quad_JewelA_4x4_A },
    { "Quad_JewelB_4x4_A",    &M88::Quad_JewelB_4x4_A },
    { "Quad_JewelC_4x4_A",    &M88::Quad_JewelC_4x4_A },
    { "Quad_JewelD_4x4_A",    &M88::Quad_JewelD_4x4_A },
     
    { "Quad_CrystalA_4x4_A",  &M88::Quad_CrystalA_4x4_A },
    { "Quad_CrystalC_4x4_A",  &M88::Quad_CrystalC_4x4_A },
    { "Quad_CrystalB_4x4_A",  &M88::Quad_CrystalB_4x4_A },
    { "Quad_CrystalD_4x4_A",  &M88::Quad_CrystalD_4x4_A },
    
    { "Quad_OpalA_4x4_A",     &M88::Quad_OpalA_4x4_A },
    { "Quad_OpalC_4x4_A",     &M88::Quad_OpalC_4x4_A },
    { "Quad_OpalB_4x4_A",     &M88::Quad_OpalB_4x4_A },
    { "Quad_OpalD_4x4_A",     &M88::Quad_OpalD_4x4_A },
    
    { "Quad_PeridotA_4x4_A",  &M88::Quad_PeridotA_4x4_A },
    { "Quad_PeridotB_4x4_A",  &M88::Quad_PeridotB_4x4_A },
    { "Quad_PeridotC_4x4_A",  &M88::Quad_PeridotC_4x4_A },
    { "Quad_PeridotD_4x4_A",  &M88::Quad_PeridotD_4x4_A },
    
    { "Quad_SwanA_4x4_A",     &M88::Quad_SwanA_4x4_A },
    { "Quad_SwanB_4x4_A",     &M88::Quad_SwanB_4x4_A },
    { "Quad_SwanC_4x4_A",     &M88::Quad_SwanC_4x4_A },
    { "Quad_SwanD_4x4_A",     &M88::Quad_SwanD_4x4_A },

    { "Quad_GooseA_4x4_A",    &M88::Quad_GooseA_4x4_A },
    { "Quad_GooseB_4x4_A",    &M88::Quad_GooseB_4x4_A },
    { "Quad_GooseC_4x4_A",    &M88::Quad_GooseC_4x4_A },
    { "Quad_GooseD_4x4_A",    &M88::Quad_GooseD_4x4_A },
    
    
    
    { "Quad_IronA_4x4_A",      &M88::Quad_IronA_4x4_A },
    { "Quad_IronB_4x4_A",      &M88::Quad_IronB_4x4_A },
    { "Quad_IronC_4x4_A",      &M88::Quad_IronC_4x4_A },
    { "Quad_IronD_4x4_A",      &M88::Quad_IronD_4x4_A },

    { "Quad_SteelA_4x4_A",     &M88::Quad_SteelA_4x4_A },
    { "Quad_SteelB_4x4_A",     &M88::Quad_SteelB_4x4_A },
    { "Quad_SteelC_4x4_A",     &M88::Quad_SteelC_4x4_A },
    { "Quad_SteelD_4x4_A",     &M88::Quad_SteelD_4x4_A },

    { "Quad_SilverA_4x4_A",    &M88::Quad_SilverA_4x4_A },
    { "Quad_SilverB_4x4_A",    &M88::Quad_SilverB_4x4_A },
    { "Quad_SilverC_4x4_A",    &M88::Quad_SilverC_4x4_A },
    { "Quad_SilverD_4x4_A",    &M88::Quad_SilverD_4x4_A },

    { "Quad_GoldA_4x4_A",      &M88::Quad_GoldA_4x4_A },
    { "Quad_GoldB_4x4_A",      &M88::Quad_GoldB_4x4_A },
    { "Quad_GoldC_4x4_A",      &M88::Quad_GoldC_4x4_A },
    { "Quad_GoldD_4x4_A",      &M88::Quad_GoldD_4x4_A },

    { "Quad_BronzeA_4x4_A",    &M88::Quad_BronzeA_4x4_A },
    { "Quad_BronzeB_4x4_A",    &M88::Quad_BronzeB_4x4_A },
    { "Quad_BronzeC_4x4_A",    &M88::Quad_BronzeC_4x4_A },
    { "Quad_BronzeD_4x4_A",    &M88::Quad_BronzeD_4x4_A },

    { "Quad_BrassA_4x4_A",     &M88::Quad_BrassA_4x4_A },
    { "Quad_BrassB_4x4_A",     &M88::Quad_BrassB_4x4_A },
    { "Quad_BrassC_4x4_A",     &M88::Quad_BrassC_4x4_A },
    { "Quad_BrassD_4x4_A",     &M88::Quad_BrassD_4x4_A },

    { "Quad_NickelA_4x4_A",    &M88::Quad_NickelA_4x4_A },
    { "Quad_NickelB_4x4_A",    &M88::Quad_NickelB_4x4_A },
    { "Quad_NickelC_4x4_A",    &M88::Quad_NickelC_4x4_A },
    { "Quad_NickelD_4x4_A",    &M88::Quad_NickelD_4x4_A },

    { "Quad_CobaltA_4x4_A",    &M88::Quad_CobaltA_4x4_A },
    { "Quad_CobaltB_4x4_A",    &M88::Quad_CobaltB_4x4_A },
    { "Quad_CobaltC_4x4_A",    &M88::Quad_CobaltC_4x4_A },
    { "Quad_CobaltD_4x4_A",    &M88::Quad_CobaltD_4x4_A },


    { "Quad_PlatinumA_4x4_A",  &M88::Quad_PlatinumA_4x4_A },
    { "Quad_PlatinumB_4x4_A",  &M88::Quad_PlatinumB_4x4_A },
    { "Quad_PlatinumC_4x4_A",  &M88::Quad_PlatinumC_4x4_A },
    { "Quad_PlatinumD_4x4_A",  &M88::Quad_PlatinumD_4x4_A },


    { "Quad_PalladiumA_4x4_A", &M88::Quad_PalladiumA_4x4_A },
    { "Quad_PalladiumB_4x4_A", &M88::Quad_PalladiumB_4x4_A },
    { "Quad_PalladiumC_4x4_A", &M88::Quad_PalladiumC_4x4_A },
    { "Quad_PalladiumD_4x4_A", &M88::Quad_PalladiumD_4x4_A },


    { "Quad_ChromiumA_4x4_A",  &M88::Quad_ChromiumA_4x4_A },
    { "Quad_ChromiumB_4x4_A",  &M88::Quad_ChromiumB_4x4_A },
    { "Quad_ChromiumC_4x4_A",  &M88::Quad_ChromiumC_4x4_A },
    { "Quad_ChromiumD_4x4_A",  &M88::Quad_ChromiumD_4x4_A },

    { "Quad_ZirconiumA_4x4_A", &M88::Quad_ZirconiumA_4x4_A },
    { "Quad_ZirconiumB_4x4_A", &M88::Quad_ZirconiumB_4x4_A },
    { "Quad_ZirconiumC_4x4_A", &M88::Quad_ZirconiumC_4x4_A },
    { "Quad_ZirconiumD_4x4_A", &M88::Quad_ZirconiumD_4x4_A },
    
    
    { "Quad_HydrogenA_4x4_A",  &M88::Quad_HydrogenA_4x4_A },
    { "Quad_HydrogenB_4x4_A",  &M88::Quad_HydrogenB_4x4_A },
    { "Quad_HydrogenC_4x4_A",  &M88::Quad_HydrogenC_4x4_A },
    { "Quad_HydrogenD_4x4_A",  &M88::Quad_HydrogenD_4x4_A },

    { "Quad_HeliumA_4x4_A",    &M88::Quad_HeliumA_4x4_A },
    { "Quad_HeliumB_4x4_A",    &M88::Quad_HeliumB_4x4_A },
    { "Quad_HeliumC_4x4_A",    &M88::Quad_HeliumC_4x4_A },
    { "Quad_HeliumD_4x4_A",    &M88::Quad_HeliumD_4x4_A },

    { "Quad_NeonA_4x4_A",      &M88::Quad_NeonA_4x4_A },
    { "Quad_NeonB_4x4_A",      &M88::Quad_NeonB_4x4_A },
    { "Quad_NeonC_4x4_A",      &M88::Quad_NeonC_4x4_A },
    { "Quad_NeonD_4x4_A",      &M88::Quad_NeonD_4x4_A },

    { "Quad_ArgonA_4x4_A",     &M88::Quad_ArgonA_4x4_A },
    { "Quad_ArgonB_4x4_A",     &M88::Quad_ArgonB_4x4_A },
    { "Quad_ArgonC_4x4_A",     &M88::Quad_ArgonC_4x4_A },
    { "Quad_ArgonD_4x4_A",     &M88::Quad_ArgonD_4x4_A },

    { "Quad_KryptonA_4x4_A",   &M88::Quad_KryptonA_4x4_A },
    { "Quad_KryptonB_4x4_A",   &M88::Quad_KryptonB_4x4_A },
    { "Quad_KryptonC_4x4_A",   &M88::Quad_KryptonC_4x4_A },
    { "Quad_KryptonD_4x4_A",   &M88::Quad_KryptonD_4x4_A },

    { "Quad_XenonA_4x4_A",     &M88::Quad_XenonA_4x4_A },
    { "Quad_XenonB_4x4_A",     &M88::Quad_XenonB_4x4_A },
    { "Quad_XenonC_4x4_A",     &M88::Quad_XenonC_4x4_A },
    { "Quad_XenonD_4x4_A",     &M88::Quad_XenonD_4x4_A },
    
    { "Quad_MapleA_4x4_A",     &M88::Quad_MapleA_4x4_A },
    { "Quad_MapleB_4x4_A",     &M88::Quad_MapleB_4x4_A },
    { "Quad_MapleC_4x4_A",     &M88::Quad_MapleC_4x4_A },
    { "Quad_MapleD_4x4_A",     &M88::Quad_MapleD_4x4_A },

    { "Quad_WillowA_4x4_A",    &M88::Quad_WillowA_4x4_A },
    { "Quad_WillowB_4x4_A",    &M88::Quad_WillowB_4x4_A },
    { "Quad_WillowC_4x4_A",    &M88::Quad_WillowC_4x4_A },
    { "Quad_WillowD_4x4_A",    &M88::Quad_WillowD_4x4_A },


    { "Quad_CedarA_4x4_A",     &M88::Quad_CedarA_4x4_A },
    { "Quad_CedarB_4x4_A",     &M88::Quad_CedarB_4x4_A },
    { "Quad_CedarC_4x4_A",     &M88::Quad_CedarC_4x4_A },
    { "Quad_CedarD_4x4_A",     &M88::Quad_CedarD_4x4_A },

    { "Quad_HickoryA_4x4_A",   &M88::Quad_HickoryA_4x4_A },
    { "Quad_HickoryB_4x4_A",   &M88::Quad_HickoryB_4x4_A },
    { "Quad_HickoryC_4x4_A",   &M88::Quad_HickoryC_4x4_A },
    { "Quad_HickoryD_4x4_A",   &M88::Quad_HickoryD_4x4_A },

    { "Quad_JuniperA_4x4_A",   &M88::Quad_JuniperA_4x4_A },
    { "Quad_JuniperB_4x4_A",   &M88::Quad_JuniperB_4x4_A },
    { "Quad_JuniperC_4x4_A",   &M88::Quad_JuniperC_4x4_A },
    { "Quad_JuniperD_4x4_A",   &M88::Quad_JuniperD_4x4_A },
    
    { "Quad_TokyoA_4x4_A",    &M88::Quad_TokyoA_4x4_A },
    { "Quad_TokyoB_4x4_A",    &M88::Quad_TokyoB_4x4_A },
    { "Quad_TokyoC_4x4_A",    &M88::Quad_TokyoC_4x4_A },
    { "Quad_TokyoD_4x4_A",    &M88::Quad_TokyoD_4x4_A },

    { "Quad_KyotoA_4x4_A",    &M88::Quad_KyotoA_4x4_A },
    { "Quad_KyotoB_4x4_A",    &M88::Quad_KyotoB_4x4_A },
    { "Quad_KyotoC_4x4_A",    &M88::Quad_KyotoC_4x4_A },
    { "Quad_KyotoD_4x4_A",    &M88::Quad_KyotoD_4x4_A },

    { "Quad_OsakaA_4x4_A",    &M88::Quad_OsakaA_4x4_A },
    { "Quad_OsakaB_4x4_A",    &M88::Quad_OsakaB_4x4_A },
    { "Quad_OsakaC_4x4_A",    &M88::Quad_OsakaC_4x4_A },
    { "Quad_OsakaD_4x4_A",    &M88::Quad_OsakaD_4x4_A },

    { "Quad_NaraA_4x4_A",     &M88::Quad_NaraA_4x4_A },
    { "Quad_NaraB_4x4_A",     &M88::Quad_NaraB_4x4_A },
    { "Quad_NaraC_4x4_A",     &M88::Quad_NaraC_4x4_A },
    { "Quad_NaraD_4x4_A",     &M88::Quad_NaraD_4x4_A },

    { "Quad_KobeA_4x4_A",     &M88::Quad_KobeA_4x4_A },
    { "Quad_KobeB_4x4_A",     &M88::Quad_KobeB_4x4_A },
    { "Quad_KobeC_4x4_A",     &M88::Quad_KobeC_4x4_A },
    { "Quad_KobeD_4x4_A",     &M88::Quad_KobeD_4x4_A },

    { "Quad_SapporoA_4x4_A",  &M88::Quad_SapporoA_4x4_A },
    { "Quad_SapporoB_4x4_A",  &M88::Quad_SapporoB_4x4_A },
    { "Quad_SapporoC_4x4_A",  &M88::Quad_SapporoC_4x4_A },
    { "Quad_SapporoD_4x4_A",  &M88::Quad_SapporoD_4x4_A },

    { "Quad_NagoyaA_4x4_A",   &M88::Quad_NagoyaA_4x4_A },
    { "Quad_NagoyaB_4x4_A",   &M88::Quad_NagoyaB_4x4_A },
    { "Quad_NagoyaC_4x4_A",   &M88::Quad_NagoyaC_4x4_A },
    { "Quad_NagoyaD_4x4_A",   &M88::Quad_NagoyaD_4x4_A },

    { "Quad_FukuokaA_4x4_A",  &M88::Quad_FukuokaA_4x4_A },
    { "Quad_FukuokaB_4x4_A",  &M88::Quad_FukuokaB_4x4_A },
    { "Quad_FukuokaC_4x4_A",  &M88::Quad_FukuokaC_4x4_A },
    { "Quad_FukuokaD_4x4_A",  &M88::Quad_FukuokaD_4x4_A },
    
    
    { "Quad_GlendaleA_4x4_A",  &M88::Quad_GlendaleA_4x4_A },
    { "Quad_GlendaleB_4x4_A",  &M88::Quad_GlendaleB_4x4_A },
    { "Quad_GlendaleC_4x4_A",  &M88::Quad_GlendaleC_4x4_A },
    { "Quad_GlendaleD_4x4_A",  &M88::Quad_GlendaleD_4x4_A },

    { "Quad_BurbankA_4x4_A",   &M88::Quad_BurbankA_4x4_A },
    { "Quad_BurbankB_4x4_A",   &M88::Quad_BurbankB_4x4_A },
    { "Quad_BurbankC_4x4_A",   &M88::Quad_BurbankC_4x4_A },
    { "Quad_BurbankD_4x4_A",   &M88::Quad_BurbankD_4x4_A },

    { "Quad_InglewoodA_4x4_A", &M88::Quad_InglewoodA_4x4_A },
    { "Quad_InglewoodB_4x4_A", &M88::Quad_InglewoodB_4x4_A },
    { "Quad_InglewoodC_4x4_A", &M88::Quad_InglewoodC_4x4_A },
    { "Quad_InglewoodD_4x4_A", &M88::Quad_InglewoodD_4x4_A },

    { "Quad_PasadenaA_4x4_A",  &M88::Quad_PasadenaA_4x4_A },
    { "Quad_PasadenaB_4x4_A",  &M88::Quad_PasadenaB_4x4_A },
    { "Quad_PasadenaC_4x4_A",  &M88::Quad_PasadenaC_4x4_A },
    { "Quad_PasadenaD_4x4_A",  &M88::Quad_PasadenaD_4x4_A },

    { "Quad_TorranceA_4x4_A",  &M88::Quad_TorranceA_4x4_A },
    { "Quad_TorranceB_4x4_A",  &M88::Quad_TorranceB_4x4_A },
    { "Quad_TorranceC_4x4_A",  &M88::Quad_TorranceC_4x4_A },
    { "Quad_TorranceD_4x4_A",  &M88::Quad_TorranceD_4x4_A },

    { "Quad_HawthorneA_4x4_A", &M88::Quad_HawthorneA_4x4_A },
    { "Quad_HawthorneB_4x4_A", &M88::Quad_HawthorneB_4x4_A },
    { "Quad_HawthorneC_4x4_A", &M88::Quad_HawthorneC_4x4_A },
    { "Quad_HawthorneD_4x4_A", &M88::Quad_HawthorneD_4x4_A },
    
    { "Quad_WizardA_4x4_A", &M88::Quad_WizardA_4x4_A },
    { "Quad_WizardB_4x4_A", &M88::Quad_WizardB_4x4_A },
    { "Quad_WizardC_4x4_A", &M88::Quad_WizardC_4x4_A },
    { "Quad_WizardD_4x4_A", &M88::Quad_WizardD_4x4_A },
    
    
    /*
    { "Quad_YorkA_4x4_A",     &M88::Quad_YorkA_4x4_A },
    { "Quad_YorkB_4x4_A",     &M88::Quad_YorkB_4x4_A },
    { "Quad_YorkC_4x4_A",     &M88::Quad_YorkC_4x4_A },
    { "Quad_YorkD_4x4_A",     &M88::Quad_YorkD_4x4_A },

    { "Quad_EssexA_4x4_A",    &M88::Quad_EssexA_4x4_A },
    { "Quad_EssexB_4x4_A",    &M88::Quad_EssexB_4x4_A },
    { "Quad_EssexC_4x4_A",    &M88::Quad_EssexC_4x4_A },
    { "Quad_EssexD_4x4_A",    &M88::Quad_EssexD_4x4_A },

    { "Quad_WessexA_4x4_A",   &M88::Quad_WessexA_4x4_A },
    { "Quad_WessexB_4x4_A",   &M88::Quad_WessexB_4x4_A },
    { "Quad_WessexC_4x4_A",   &M88::Quad_WessexC_4x4_A },
    { "Quad_WessexD_4x4_A",   &M88::Quad_WessexD_4x4_A },

    { "Quad_MerciaA_4x4_A",   &M88::Quad_MerciaA_4x4_A },
    { "Quad_MerciaB_4x4_A",   &M88::Quad_MerciaB_4x4_A },
    { "Quad_MerciaC_4x4_A",   &M88::Quad_MerciaC_4x4_A },
    { "Quad_MerciaD_4x4_A",   &M88::Quad_MerciaD_4x4_A },

    { "Quad_SussexA_4x4_A",   &M88::Quad_SussexA_4x4_A },
    { "Quad_SussexB_4x4_A",   &M88::Quad_SussexB_4x4_A },
    { "Quad_SussexC_4x4_A",   &M88::Quad_SussexC_4x4_A },
    { "Quad_SussexD_4x4_A",   &M88::Quad_SussexD_4x4_A },

    { "Quad_UmbriaA_4x4_A",   &M88::Quad_UmbriaA_4x4_A },
    { "Quad_UmbriaB_4x4_A",   &M88::Quad_UmbriaB_4x4_A },
    { "Quad_UmbriaC_4x4_A",   &M88::Quad_UmbriaC_4x4_A },
    { "Quad_UmbriaD_4x4_A",   &M88::Quad_UmbriaD_4x4_A },
    */
    
};

static const std::vector<UniqueQuarterCandidateOp> kCandidateQuarterOps = {
    { "Candidate_00", &UniqueQuarterTool::Candidate_00 },
    { "Candidate_01", &UniqueQuarterTool::Candidate_01 },
    { "Candidate_02", &UniqueQuarterTool::Candidate_02 },
    { "Candidate_03", &UniqueQuarterTool::Candidate_03 },

    /*
    { "Candidate_04", &UniqueQuarterTool::Candidate_04 },
    { "Candidate_05", &UniqueQuarterTool::Candidate_05 },
    { "Candidate_06", &UniqueQuarterTool::Candidate_06 },
    { "Candidate_07", &UniqueQuarterTool::Candidate_07 },

    
    { "Candidate_08", &UniqueQuarterTool::Candidate_08 },
    { "Candidate_09", &UniqueQuarterTool::Candidate_09 },
    { "Candidate_10", &UniqueQuarterTool::Candidate_10 },
    { "Candidate_11", &UniqueQuarterTool::Candidate_11 },
    
    

    { "Candidate_12", &UniqueQuarterTool::Candidate_12 },
    { "Candidate_13", &UniqueQuarterTool::Candidate_13 },
    { "Candidate_14", &UniqueQuarterTool::Candidate_14 },
    { "Candidate_15", &UniqueQuarterTool::Candidate_15 },
    
    

    { "Candidate_16", &UniqueQuarterTool::Candidate_16 },
    { "Candidate_17", &UniqueQuarterTool::Candidate_17 },
    { "Candidate_18", &UniqueQuarterTool::Candidate_18 },
    { "Candidate_19", &UniqueQuarterTool::Candidate_19 },

    { "Candidate_20", &UniqueQuarterTool::Candidate_20 },
    { "Candidate_21", &UniqueQuarterTool::Candidate_21 },
    { "Candidate_22", &UniqueQuarterTool::Candidate_22 },
    { "Candidate_23", &UniqueQuarterTool::Candidate_23 },
    
    
    
    { "Candidate_24", &UniqueQuarterTool::Candidate_24 },
    { "Candidate_25", &UniqueQuarterTool::Candidate_25 },
    { "Candidate_26", &UniqueQuarterTool::Candidate_26 },
    { "Candidate_27", &UniqueQuarterTool::Candidate_27 },

    { "Candidate_28", &UniqueQuarterTool::Candidate_28 },
    { "Candidate_29", &UniqueQuarterTool::Candidate_29 },
    { "Candidate_30", &UniqueQuarterTool::Candidate_30 },
    { "Candidate_31", &UniqueQuarterTool::Candidate_31 },
    
    
    
    { "Candidate_32", &UniqueQuarterTool::Candidate_32 },
    { "Candidate_33", &UniqueQuarterTool::Candidate_33 },
    { "Candidate_34", &UniqueQuarterTool::Candidate_34 },
    { "Candidate_35", &UniqueQuarterTool::Candidate_35 },
    
   

    { "Candidate_36", &UniqueQuarterTool::Candidate_36 },
    { "Candidate_37", &UniqueQuarterTool::Candidate_37 },
    { "Candidate_38", &UniqueQuarterTool::Candidate_38 },
    { "Candidate_39", &UniqueQuarterTool::Candidate_39 },

    { "Candidate_40", &UniqueQuarterTool::Candidate_40 },
    { "Candidate_41", &UniqueQuarterTool::Candidate_41 },
    { "Candidate_42", &UniqueQuarterTool::Candidate_42 },
    { "Candidate_43", &UniqueQuarterTool::Candidate_43 },

    { "Candidate_44", &UniqueQuarterTool::Candidate_44 },
    { "Candidate_45", &UniqueQuarterTool::Candidate_45 },
    { "Candidate_46", &UniqueQuarterTool::Candidate_46 },
    { "Candidate_47", &UniqueQuarterTool::Candidate_47 },

    { "Candidate_48", &UniqueQuarterTool::Candidate_48 },
    { "Candidate_49", &UniqueQuarterTool::Candidate_49 },
    { "Candidate_50", &UniqueQuarterTool::Candidate_50 },
    { "Candidate_51", &UniqueQuarterTool::Candidate_51 },

    { "Candidate_52", &UniqueQuarterTool::Candidate_52 },
    { "Candidate_53", &UniqueQuarterTool::Candidate_53 },
    { "Candidate_54", &UniqueQuarterTool::Candidate_54 },
    { "Candidate_55", &UniqueQuarterTool::Candidate_55 },

    { "Candidate_56", &UniqueQuarterTool::Candidate_56 },
    { "Candidate_57", &UniqueQuarterTool::Candidate_57 },
    { "Candidate_58", &UniqueQuarterTool::Candidate_58 },
    { "Candidate_59", &UniqueQuarterTool::Candidate_59 },

    { "Candidate_60", &UniqueQuarterTool::Candidate_60 },
    { "Candidate_61", &UniqueQuarterTool::Candidate_61 },
    { "Candidate_62", &UniqueQuarterTool::Candidate_62 },
    { "Candidate_63", &UniqueQuarterTool::Candidate_63 },
    */
    
};


void UniqueQuarterTool::Candidate_00(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.HexA();
    pGrid.SwapTallQuartersA();
    pGrid.ShearA();
    pGrid.RotateRight();
    pGrid.FlipB();
    pGrid.Rotate180();
    pGrid.HexB();
    pGrid.FlipA();
}

void UniqueQuarterTool::Candidate_01(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.HexA();
    pGrid.SwapTallQuartersA();
    pGrid.ShearB();
    pGrid.RotateRight();
    pGrid.FlipB();
    pGrid.Rotate180();
    pGrid.HexB();
    pGrid.FlipA();
}

void UniqueQuarterTool::Candidate_02(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.HexA();
    pGrid.SwapTallQuartersA();
    pGrid.ShearC();
    pGrid.RotateRight();
    pGrid.FlipB();
    pGrid.HexB();
    pGrid.FlipA();
}

void UniqueQuarterTool::Candidate_03(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.HexA();
    pGrid.SwapTallQuartersA();
    pGrid.ShearD();
    pGrid.RotateRight();
    pGrid.FlipB();
    pGrid.HexB();
    pGrid.FlipA();
}

void UniqueQuarterTool::Candidate_04(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.HexB();
    pGrid.SwapLongQuartersB();
    pGrid.ShearA();
    pGrid.FlipC();
    pGrid.SwapHalvesVer();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_05(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.HexB();
    pGrid.SwapLongQuartersB();
    pGrid.ShearB();
    pGrid.FlipC();
    pGrid.SwapHalvesVer();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_06(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.HexB();
    pGrid.SwapLongQuartersB();
    pGrid.ShearC();
    pGrid.FlipC();
    pGrid.FlipB();
    pGrid.RotateRight();
}

void UniqueQuarterTool::Candidate_07(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.HexB();
    pGrid.SwapLongQuartersB();
    pGrid.ShearD();
    pGrid.FlipC();
    pGrid.FlipB();
    pGrid.RotateRight();
}

void UniqueQuarterTool::Candidate_08(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.ShearB();
    pGrid.HexA();
    pGrid.SwapTallQuartersC();
    pGrid.ShearA();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_09(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.ShearB();
    pGrid.HexA();
    pGrid.SwapTallQuartersC();
    pGrid.ShearB();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_10(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.ShearB();
    pGrid.HexA();
    pGrid.SwapTallQuartersC();
    pGrid.ShearC();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_11(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.ShearB();
    pGrid.HexA();
    pGrid.SwapTallQuartersC();
    pGrid.ShearD();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_12(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.FlipD();
    pGrid.HexB();
    pGrid.SwapLongQuartersC();
    pGrid.ShearA();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_13(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.FlipD();
    pGrid.HexB();
    pGrid.SwapLongQuartersC();
    pGrid.ShearB();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_14(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.FlipD();
    pGrid.HexB();
    pGrid.SwapLongQuartersC();
    pGrid.ShearC();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_15(UniqueQuarterGrid &pGrid) {
    pGrid.SwapAD();
    pGrid.FlipD();
    pGrid.HexB();
    pGrid.SwapLongQuartersC();
    pGrid.ShearD();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_16(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.HexB();
    pGrid.SwapTallQuartersB();
    pGrid.ShearA();
    pGrid.RotateLeft();
    pGrid.FlipB();
    pGrid.Rotate180();
}

void UniqueQuarterTool::Candidate_17(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.HexB();
    pGrid.SwapTallQuartersB();
    pGrid.ShearB();
    pGrid.RotateLeft();
    pGrid.FlipB();
    pGrid.Rotate180();
}

void UniqueQuarterTool::Candidate_18(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.HexB();
    pGrid.SwapTallQuartersB();
    pGrid.ShearC();
    pGrid.RotateLeft();
    pGrid.FlipB();
    pGrid.RotateLeft();
}

void UniqueQuarterTool::Candidate_19(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.HexB();
    pGrid.SwapTallQuartersB();
    pGrid.ShearD();
    pGrid.RotateLeft();
    pGrid.FlipB();
    pGrid.RotateLeft();
}

void UniqueQuarterTool::Candidate_20(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.HexA();
    pGrid.SwapLongQuartersA();
    pGrid.ShearA();
    pGrid.FlipD();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_21(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.HexA();
    pGrid.SwapLongQuartersA();
    pGrid.ShearB();
    pGrid.FlipD();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_22(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.HexA();
    pGrid.SwapLongQuartersA();
    pGrid.ShearC();
    pGrid.FlipD();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_23(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.HexA();
    pGrid.SwapLongQuartersA();
    pGrid.ShearD();
    pGrid.FlipD();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_24(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.ShearC();
    pGrid.HexB();
    pGrid.SwapTallQuartersC();
    pGrid.ShearA();
    pGrid.FlipB();
}

void UniqueQuarterTool::Candidate_25(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.ShearC();
    pGrid.HexB();
    pGrid.SwapTallQuartersC();
    pGrid.ShearB();
}

void UniqueQuarterTool::Candidate_26(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.ShearC();
    pGrid.HexB();
    pGrid.SwapTallQuartersC();
    pGrid.ShearC();
}

void UniqueQuarterTool::Candidate_27(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.ShearC();
    pGrid.HexB();
    pGrid.SwapTallQuartersC();
    pGrid.ShearD();
}

void UniqueQuarterTool::Candidate_28(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.FlipC();
    pGrid.HexA();
    pGrid.SwapLongQuartersC();
    pGrid.ShearA();
    pGrid.SwapHalvesVer();
}

void UniqueQuarterTool::Candidate_29(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.FlipC();
    pGrid.HexA();
    pGrid.SwapLongQuartersC();
    pGrid.ShearB();
    pGrid.SwapHalvesVer();
}

void UniqueQuarterTool::Candidate_30(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.FlipC();
    pGrid.HexA();
    pGrid.SwapLongQuartersC();
    pGrid.ShearC();
    pGrid.SwapHalvesVer();
}

void UniqueQuarterTool::Candidate_31(UniqueQuarterGrid &pGrid) {
    pGrid.SwapBC();
    pGrid.FlipC();
    pGrid.HexA();
    pGrid.SwapLongQuartersC();
    pGrid.ShearD();
    pGrid.SwapHalvesVer();
}

void UniqueQuarterTool::Candidate_32(UniqueQuarterGrid &pGrid) {
    pGrid.RotateLeft();
    pGrid.HexB();
    pGrid.SwapLongQuartersC();
    pGrid.ZigZagB();
}

void UniqueQuarterTool::Candidate_33(UniqueQuarterGrid &pGrid) {
    pGrid.RotateLeft();
    pGrid.HexA();
    pGrid.SwapLongQuartersA();
    pGrid.ZigZagB();
}

void UniqueQuarterTool::Candidate_34(UniqueQuarterGrid &pGrid) {
    pGrid.RotateLeft();
    pGrid.HexA();
    pGrid.SwapLongQuartersB();
    pGrid.ZigZagB();
}

void UniqueQuarterTool::Candidate_35(UniqueQuarterGrid &pGrid) {
    pGrid.RotateLeft();
    pGrid.HexA();
    pGrid.SwapLongQuartersC();
    pGrid.ZigZagB();
}

void UniqueQuarterTool::Candidate_36(UniqueQuarterGrid &pGrid) {
    pGrid.RotateRight();
    pGrid.HexB();
    pGrid.SwapLongQuartersA();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_37(UniqueQuarterGrid &pGrid) {
    pGrid.RotateRight();
    pGrid.HexB();
    pGrid.SwapLongQuartersB();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_38(UniqueQuarterGrid &pGrid) {
    pGrid.RotateRight();
    pGrid.HexB();
    pGrid.SwapLongQuartersC();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_39(UniqueQuarterGrid &pGrid) {
    pGrid.RotateRight();
    pGrid.HexA();
    pGrid.SwapLongQuartersA();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_40(UniqueQuarterGrid &pGrid) {
    pGrid.RotateRight();
    pGrid.HexA();
    pGrid.SwapLongQuartersB();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_41(UniqueQuarterGrid &pGrid) {
    pGrid.RotateRight();
    pGrid.HexA();
    pGrid.SwapLongQuartersC();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_42(UniqueQuarterGrid &pGrid) {
    pGrid.RotateLeft();
    pGrid.HexB();
    pGrid.SwapLongQuartersA();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_43(UniqueQuarterGrid &pGrid) {
    pGrid.RotateLeft();
    pGrid.HexB();
    pGrid.SwapLongQuartersB();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_44(UniqueQuarterGrid &pGrid) {
    pGrid.RotateLeft();
    pGrid.HexB();
    pGrid.SwapLongQuartersC();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_45(UniqueQuarterGrid &pGrid) {
    pGrid.RotateLeft();
    pGrid.HexA();
    pGrid.SwapLongQuartersA();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_46(UniqueQuarterGrid &pGrid) {
    pGrid.RotateLeft();
    pGrid.HexA();
    pGrid.SwapLongQuartersB();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_47(UniqueQuarterGrid &pGrid) {
    pGrid.RotateLeft();
    pGrid.HexA();
    pGrid.SwapLongQuartersC();
    pGrid.ZigZagC();
}

void UniqueQuarterTool::Candidate_48(UniqueQuarterGrid &pGrid) {
    pGrid.ShearA();
    pGrid.FlipB();
    pGrid.ZigZagB();
}

void UniqueQuarterTool::Candidate_49(UniqueQuarterGrid &pGrid) {
    pGrid.ShearA();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.RotateRight();
}

void UniqueQuarterTool::Candidate_50(UniqueQuarterGrid &pGrid) {
    pGrid.ShearA();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.Rotate180();
}

void UniqueQuarterTool::Candidate_51(UniqueQuarterGrid &pGrid) {
    pGrid.ShearA();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.RotateLeft();
}

void UniqueQuarterTool::Candidate_52(UniqueQuarterGrid &pGrid) {
    pGrid.ShearB();
    pGrid.FlipB();
    pGrid.ZigZagB();
}

void UniqueQuarterTool::Candidate_53(UniqueQuarterGrid &pGrid) {
    pGrid.ShearB();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.RotateRight();
}

void UniqueQuarterTool::Candidate_54(UniqueQuarterGrid &pGrid) {
    pGrid.ShearB();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.Rotate180();
}

void UniqueQuarterTool::Candidate_55(UniqueQuarterGrid &pGrid) {
    pGrid.ShearB();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.RotateLeft();
}

void UniqueQuarterTool::Candidate_56(UniqueQuarterGrid &pGrid) {
    pGrid.ShearC();
    pGrid.FlipB();
    pGrid.ZigZagB();
}

void UniqueQuarterTool::Candidate_57(UniqueQuarterGrid &pGrid) {
    pGrid.ShearC();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.RotateRight();
}

void UniqueQuarterTool::Candidate_58(UniqueQuarterGrid &pGrid) {
    pGrid.ShearC();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.Rotate180();
}

void UniqueQuarterTool::Candidate_59(UniqueQuarterGrid &pGrid) {
    pGrid.ShearC();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.RotateLeft();
}

void UniqueQuarterTool::Candidate_60(UniqueQuarterGrid &pGrid) {
    pGrid.ShearD();
    pGrid.FlipB();
    pGrid.ZigZagB();
}

void UniqueQuarterTool::Candidate_61(UniqueQuarterGrid &pGrid) {
    pGrid.ShearD();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.RotateRight();
}

void UniqueQuarterTool::Candidate_62(UniqueQuarterGrid &pGrid) {
    pGrid.ShearD();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.Rotate180();
}

void UniqueQuarterTool::Candidate_63(UniqueQuarterGrid &pGrid) {
    pGrid.ShearD();
    pGrid.FlipB();
    pGrid.ZigZagB();
    pGrid.RotateLeft();
}


std::vector<UniqueQuarterCompareResult>
UniqueQuarterTool::CompareCandidateOpsToQuarterOps() {
    std::vector<UniqueQuarterCompareResult> results;

    std::vector<UniqueQuarterGrid> existingGrids;
    existingGrids.reserve(kExistingQuarterAOps.size());

    for (const UniqueQuarterExistingOp &entry : kExistingQuarterAOps) {
        M88 matrix;
        matrix.Reset();

        (matrix.*entry.mFunction)();

        UniqueQuarterGrid grid;
        grid.LoadFromM88QuadA(matrix);

        existingGrids.push_back(grid);
    }

    for (const UniqueQuarterCandidateOp &candidateEntry : kCandidateQuarterOps) {
        UniqueQuarterGrid candidate;
        candidate.Reset();

        candidateEntry.mFunction(candidate);

        for (std::size_t existingIndex = 0;
             existingIndex < kExistingQuarterAOps.size();
             ++existingIndex) {
            const UniqueQuarterGrid &existing = existingGrids[existingIndex];

            const std::size_t distance = candidate.HammingDistance(existing);

            UniqueQuarterCompareResult result;
            result.mCandidateName = candidateEntry.mName;
            result.mExistingName = kExistingQuarterAOps[existingIndex].mName;
            result.mHammingDistance = distance;
            result.mExactDuplicate = distance == 0;

            results.push_back(result);
        }
    }

    std::sort(results.begin(),
              results.end(),
              [](const UniqueQuarterCompareResult &a,
                 const UniqueQuarterCompareResult &b) {
                  if (a.mCandidateName != b.mCandidateName) {
                      return a.mCandidateName < b.mCandidateName;
                  }

                  if (a.mHammingDistance != b.mHammingDistance) {
                      return a.mHammingDistance < b.mHammingDistance;
                  }

                  return a.mExistingName < b.mExistingName;
              });

    return results;
}

void UniqueQuarterTool::PrintCompareCandidateOpsToQuarterOps() {
    const std::vector<UniqueQuarterCompareResult> results =
    CompareCandidateOpsToQuarterOps();

    std::string currentCandidate;

    for (const UniqueQuarterCompareResult &result : results) {
        if (result.mCandidateName != currentCandidate) {
            currentCandidate = result.mCandidateName;

            std::printf("\n%s\n", currentCandidate.c_str());
        }

        std::printf("  distance %2zu  vs  %s%s\n",
                    result.mHammingDistance,
                    result.mExistingName.c_str(),
                    result.mExactDuplicate ? "  DUPLICATE" : "");
    }
}

std::vector<UniqueQuarterExistingCompareResult>
UniqueQuarterTool::CompareExistingOpsToEachOther() {
    std::vector<UniqueQuarterExistingCompareResult> results;

    std::vector<UniqueQuarterGrid> existingGrids;
    existingGrids.reserve(kExistingQuarterAOps.size());

    for (const UniqueQuarterExistingOp &entry : kExistingQuarterAOps) {
        M88 matrix;
        matrix.Reset();

        (matrix.*entry.mFunction)();

        UniqueQuarterGrid grid;
        grid.LoadFromM88QuadA(matrix);

        existingGrids.push_back(grid);
    }

    for (std::size_t indexA = 0; indexA < kExistingQuarterAOps.size(); ++indexA) {
        for (std::size_t indexB = indexA + 1; indexB < kExistingQuarterAOps.size(); ++indexB) {
            const UniqueQuarterGrid &gridA = existingGrids[indexA];
            const UniqueQuarterGrid &gridB = existingGrids[indexB];

            const std::size_t distance = gridA.HammingDistance(gridB);

            UniqueQuarterExistingCompareResult result;
            result.mNameA = kExistingQuarterAOps[indexA].mName;
            result.mNameB = kExistingQuarterAOps[indexB].mName;
            result.mHammingDistance = distance;
            result.mExactDuplicate = distance == 0;

            results.push_back(result);
        }
    }

    std::sort(results.begin(),
              results.end(),
              [](const UniqueQuarterExistingCompareResult &a,
                 const UniqueQuarterExistingCompareResult &b) {
                  if (a.mHammingDistance != b.mHammingDistance) {
                      return a.mHammingDistance < b.mHammingDistance;
                  }

                  if (a.mNameA != b.mNameA) {
                      return a.mNameA < b.mNameA;
                  }

                  return a.mNameB < b.mNameB;
              });

    return results;
}


void UniqueQuarterTool::PrintCompareExistingOpsToEachOther() {
    const std::vector<UniqueQuarterExistingCompareResult> results =
    CompareExistingOpsToEachOther();

    std::printf("\nExisting quarter ops vs existing quarter ops\n");

    for (const UniqueQuarterExistingCompareResult &result : results) {
        std::printf("  distance %2zu  %s  vs  %s%s\n",
                    result.mHammingDistance,
                    result.mNameA.c_str(),
                    result.mNameB.c_str(),
                    result.mExactDuplicate ? "  DUPLICATE" : "");
    }
}

std::vector<UniqueQuarterCandidateCompareResult>
UniqueQuarterTool::CompareCandidateOpsToEachOther() {
    std::vector<UniqueQuarterCandidateCompareResult> results;

    std::vector<UniqueQuarterGrid> candidateGrids;
    candidateGrids.reserve(kCandidateQuarterOps.size());

    for (const UniqueQuarterCandidateOp &entry : kCandidateQuarterOps) {
        UniqueQuarterGrid grid;
        grid.Reset();

        entry.mFunction(grid);

        candidateGrids.push_back(grid);
    }

    for (std::size_t indexA = 0U; indexA < kCandidateQuarterOps.size(); ++indexA) {
        for (std::size_t indexB = indexA + 1U; indexB < kCandidateQuarterOps.size(); ++indexB) {
            const UniqueQuarterGrid &gridA = candidateGrids[indexA];
            const UniqueQuarterGrid &gridB = candidateGrids[indexB];

            const std::size_t distance = gridA.HammingDistance(gridB);

            UniqueQuarterCandidateCompareResult result;
            result.mNameA = kCandidateQuarterOps[indexA].mName;
            result.mNameB = kCandidateQuarterOps[indexB].mName;
            result.mHammingDistance = distance;
            result.mExactDuplicate = distance == 0U;

            results.push_back(result);
        }
    }

    std::sort(results.begin(),
              results.end(),
              [](const UniqueQuarterCandidateCompareResult &a,
                 const UniqueQuarterCandidateCompareResult &b) {
                  if (a.mHammingDistance != b.mHammingDistance) {
                      return a.mHammingDistance < b.mHammingDistance;
                  }

                  if (a.mNameA != b.mNameA) {
                      return a.mNameA < b.mNameA;
                  }

                  return a.mNameB < b.mNameB;
              });

    return results;
}


void UniqueQuarterTool::PrintCompareCandidateOpsToEachOther() {
    std::vector<UniqueQuarterGrid> candidateGrids;
    candidateGrids.reserve(kCandidateQuarterOps.size());

    for (const UniqueQuarterCandidateOp &entry : kCandidateQuarterOps) {
        UniqueQuarterGrid grid;
        grid.Reset();

        entry.mFunction(grid);

        candidateGrids.push_back(grid);
    }

    std::printf("\nCandidate quarter ops vs candidate quarter ops\n");

    for (std::size_t indexA = 0U; indexA < kCandidateQuarterOps.size(); ++indexA) {
        for (std::size_t indexB = indexA + 1U; indexB < kCandidateQuarterOps.size(); ++indexB) {
            const UniqueQuarterGrid &gridA = candidateGrids[indexA];
            const UniqueQuarterGrid &gridB = candidateGrids[indexB];

            const std::size_t distance = gridA.HammingDistance(gridB);

            std::printf("  distance %2zu  %s  vs  %s%s\n",
                        distance,
                        kCandidateQuarterOps[indexA].mName,
                        kCandidateQuarterOps[indexB].mName,
                        distance == 0U ? "  DUPLICATE" : "");
        }
    }
}

void UniqueQuarterTool::PrintCompareCandidates() {
    const std::vector<UniqueQuarterCompareResult> candidateVsExisting =
        CompareCandidateOpsToQuarterOps();

    const std::vector<UniqueQuarterCandidateCompareResult> candidateVsCandidate =
        CompareCandidateOpsToEachOther();

    std::printf("\n");
    std::printf("// ============================================================\n");
    std::printf("// Candidate compare warnings: distance < %zu\n", kCandidateDistanceWarningThreshold);
    std::printf("// ============================================================\n");

    std::printf("\nCandidate quarter ops vs existing quarter ops\n");

    bool foundLowCandidateVsExisting = false;

    for (const UniqueQuarterCompareResult &result : candidateVsExisting) {
        if (result.mHammingDistance >= kCandidateDistanceWarningThreshold) {
            continue;
        }

        foundLowCandidateVsExisting = true;

        std::printf("  distance %2zu  %s  vs  %s%s\n",
                    result.mHammingDistance,
                    result.mCandidateName.c_str(),
                    result.mExistingName.c_str(),
                    result.mExactDuplicate ? "  DUPLICATE" : "");
    }

    if (!foundLowCandidateVsExisting) {
        std::printf("  none\n");
    }

    std::printf("\nCandidate quarter ops vs candidate quarter ops\n");

    bool foundLowCandidateVsCandidate = false;

    for (const UniqueQuarterCandidateCompareResult &result : candidateVsCandidate) {
        if (result.mHammingDistance >= kCandidateDistanceWarningThreshold) {
            continue;
        }

        foundLowCandidateVsCandidate = true;

        std::printf("  distance %2zu  %s  vs  %s%s\n",
                    result.mHammingDistance,
                    result.mNameA.c_str(),
                    result.mNameB.c_str(),
                    result.mExactDuplicate ? "  DUPLICATE" : "");
    }

    if (!foundLowCandidateVsCandidate) {
        std::printf("  none\n");
    }

    std::printf("\n");
}

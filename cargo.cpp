#include "cargo.h"

QString enumToString(Cargo const & _cargo)
{
    switch (_cargo)
    {
    case CargoFish:
        return "Fish";
    case CargoCotton:
        return "Cotton";
    case CargoWood:
        return "Wood";
    case CargoCacao:
        return "Cacao";
    case CargoSugar:
        return "Sugar";
    case CargoWeapon:
        return "Weapon";
    case CargoTextile:
        return "Textile";
    case CargoTobacco:
        return "Tobacco";
    case CargoWine:
        return "Wine";
    case CargoGems:
        return "Gems";
    default:
        return "Unknown cargo";
    }
}

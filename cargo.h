#pragma once

#include <QString>

enum Cargo
{
    CargoFish = 0,
    CargoCotton,
    CargoWood,
    CargoCacao,
    CargoSugar,
    CargoWeapon,
    CargoTextile,
    CargoTobacco,
    CargoWine,
    CargoGems
};

QString enumToString(Cargo const & _cargo);

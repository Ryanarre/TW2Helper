#pragma once

#include <QString>

enum City
{
    CitySantoDomingo = 0,
    CityPortRoyale,
    CityCount
};

QString enumToString(City const & _city);

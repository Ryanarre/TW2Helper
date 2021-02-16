#pragma once

enum City
{
    CitySantoDomingo = 0,
    CityPortRoyale,
    CityCount
};

QString enumToString(City const & _city)
{
    switch (_city)
    {
        case CitySantoDomingo:
            return "Santo Domingo";
        case CityPortRoyale:
            return "Port Royale";
        default:
            return "Unknown city";
    }
}

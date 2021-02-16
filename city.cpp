#include "city.h"

QString enumToString(const City &_city)
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

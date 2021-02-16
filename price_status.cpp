#include "price_status.h"

QString enumToString(PriceStatus const & _status)
{
    switch (_status)
    {
    case PriceStatusLowest:
        return "LOWEST!";
    case PriceStatusLow:
        return "Low";
    case PriceStatusHigh:
        return "High";
    case PriceStatusHighest:
        return "HIGHEST!";
    default:
        return "Unknown";
    }
}

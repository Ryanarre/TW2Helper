#pragma once

#include <QString>

enum PriceStatus
{
    PriceStatusUnknown = 0,
    PriceStatusLowest,
    PriceStatusLow,
    PriceStatusHigh,
    PriceStatusHighest
};

QString enumToString(PriceStatus const & _status);

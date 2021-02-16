#pragma once

#include "price_status.h"

class TradeData
{
public:
    TradeData();

    PriceStatus appendPrice(unsigned int _price);

    unsigned int getPrice(bool _isMax = true, bool _isHigh = true);

private:
    unsigned int m_maxHigh;
    unsigned int m_maxLow;

    unsigned int m_minHigh;
    unsigned int m_minLow;
};

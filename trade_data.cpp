#include "trade_data.h"

TradeData::TradeData()
    : m_maxHigh(0)
    , m_maxLow(0)
    , m_minHigh(0)
    , m_minLow(0)
{}

PriceStatus TradeData::appendPrice(unsigned int _price)
{
    if (m_maxHigh == 0)
    {
        m_maxHigh = _price;
        m_minLow = _price;
        return PriceStatusUnknown;
    }

    if (_price > m_maxHigh)
    {
        m_maxHigh = _price;
        return PriceStatusHighest;
    }
    else if (_price < m_minLow)
    {
        m_minLow = _price;
        return PriceStatusLowest;
    }

    unsigned int deltaMin = _price - m_minLow;
    unsigned int deltaMax = m_maxHigh - _price;
    if (deltaMin < deltaMax)
    {
        m_minHigh = _price;
        return PriceStatusLow;
    }

    m_maxLow = _price;
    return PriceStatusHigh;
}

unsigned int TradeData::getPrice(bool _isMax, bool _isHigh)
{
    return _isMax ? (_isHigh ? m_maxHigh : m_maxLow) : (_isHigh ? m_minHigh : m_minLow);
}

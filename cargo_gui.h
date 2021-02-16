#pragma once

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

#include "cargo.h"

class CargoGui
{
public:
    CargoGui();

    CargoGui(QLabel * _pLbl, QLineEdit * _pPriceTxt, QLineEdit * _pQtyTxt, QPushButton * _pContraBtn = nullptr);

    void setVisible(bool _isVisible);

    void enablePrice(bool _isEnabled = true);

    void enableQty(bool _isEnabled = true);

    bool isValid() const;

    bool isPriceEnabled() const;

    unsigned int getPrice() const;

    unsigned int getQty() const;

private:
    /* CANNOT be nullptr */
    QLabel * m_pLbl;
    QLineEdit * m_pPriceTxt;
    QLineEdit * m_pQtyTxt;

    /* Can be nullptr */
    QPushButton * m_pContraBtn;
};

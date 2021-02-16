#include "cargo_gui.h"

CargoGui::CargoGui()
{}

CargoGui::CargoGui(QLabel *_pLbl, QLineEdit *_pPriceTxt, QLineEdit *_pQtyTxt, QPushButton *_pContraBtn)
    : m_pLbl(_pLbl)
    , m_pPriceTxt(_pPriceTxt)
    , m_pQtyTxt(_pQtyTxt)
    , m_pContraBtn(_pContraBtn)
{
    m_pQtyTxt->setEnabled(false);
}

void CargoGui::setVisible(bool _isVisible)
{
    m_pPriceTxt->setVisible(_isVisible);
    m_pQtyTxt->setVisible(_isVisible);
    m_pLbl->setVisible(_isVisible);

    if (m_pContraBtn != nullptr)
        m_pContraBtn->setVisible(_isVisible);
}

void CargoGui::enablePrice(bool _isEnabled)
{
    m_pPriceTxt->setEnabled(_isEnabled);
}

void CargoGui::enableQty(bool _isEnabled)
{
    m_pQtyTxt->setEnabled(_isEnabled);
}

bool CargoGui::isValid() const
{
    if (!m_pPriceTxt->isVisible())
        return true;
    if (m_pPriceTxt->isEnabled() && m_pPriceTxt->text().size() == 0)
        return false;
    if (m_pQtyTxt->isEnabled() && m_pQtyTxt->text().size() == 0)
        return false;

    return true;
}

bool CargoGui::isPriceEnabled() const
{
    return m_pPriceTxt->isEnabled();
}

unsigned int CargoGui::getPrice() const
{
    return m_pPriceTxt->text().toUInt();
}

unsigned int CargoGui::getQty() const
{
    return m_pQtyTxt->text().toUInt();
}

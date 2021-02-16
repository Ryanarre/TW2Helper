#pragma once

#include <QMainWindow>

/* Structure includes */
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

#include "cargo.h"
#include "month.h"
#include "trade_data.h"

namespace Ui {
class MainWindow;
}

struct CargoGui
{
    /* CANNOT be nullptr */
    QLineEdit * priceTxt;
    QLineEdit * qtyTxt;
    QLabel * lbl;

    /* Can be nullptr */
    QPushButton * contraBtn = nullptr;

    void setVisible(bool _isVisible)
    {
        priceTxt->setVisible(_isVisible);
        qtyTxt->setVisible(_isVisible);
        lbl->setVisible(_isVisible);

        if (contraBtn != nullptr)
            contraBtn->setVisible(_isVisible);
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void enableCargo();
    // void enableQty

private /*functions:*/:
    void connectAndDisable();

private /*declarations*/:
    using MonthStatus = std::map<Month, PriceStatus>;
    using CargoData = std::map<Cargo, MonthStatus>;

private /*fields*/:
    Ui::MainWindow *ui;
    std::map<Cargo, CargoGui> m_widgets;
    size_t m_disabledCargo;

    std::map<Cargo, TradeData> m_tradeData;
    std::map<std::string /*city*/, CargoData> m_cargoData;
};

#pragma once

#include <QMainWindow>

#include "cargo_gui.h"
#include "month.h"
#include "trade_data.h"
#include "city.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void enableCargo();
    void enableQty(bool _isEnabled);
    void travel();

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
    std::map<City, CargoData> m_cargoData;
};

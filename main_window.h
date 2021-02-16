#pragma once

#include <QMainWindow>

#include "cargo.h"
#include "month.h"
#include "trade_data.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    using MonthStatus = std::map<Month, PriceStatus>;
    using CargoData = std::map<Cargo, MonthStatus>;

private:
    Ui::MainWindow *ui;

    std::map<Cargo, TradeData> m_tradeData;
    std::map<std::string /*city*/, CargoData> m_cargoData;
};

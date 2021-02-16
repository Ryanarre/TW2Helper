#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    Ui::MainWindow *ui;

    // std::map<enum Cargo, struct TradeData> m_tradeData;

    // using PriceInMonth = std::map<enum Month, unsigned int Price>;
    // using CargoData = std::map<enum Cargo, struct PriceInMonth>;
    // std::map<std::string City, struct CargoData> m_cargoData;
};

#endif // MAINWINDOW_H

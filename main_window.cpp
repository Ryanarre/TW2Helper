#include "main_window.h"
#include "ui_main_window.h"

#include "city.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_disabledCargo(CargoWeapon)
{
    ui->setupUi(this);

    for (size_t i = 0; i < CityCount; ++i)
        ui->comboBox->addItem(enumToString(static_cast<City>(i)));

    connectAndDisable();

    connect(ui->enableBtn, &QPushButton::clicked, this, &MainWindow::enableCargo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectAndDisable()
{
    CargoGui weaponGui;
    weaponGui.lbl = ui->label_6;
    weaponGui.priceTxt = ui->weaponPriceTxt;
    weaponGui.qtyTxt = ui->weaponQtyTxt;
    weaponGui.setVisible(false);
    m_widgets[CargoWeapon] = weaponGui;

    CargoGui textileGui;
    textileGui.lbl = ui->label_7;
    textileGui.priceTxt = ui->textilePriceTxt;
    textileGui.qtyTxt = ui->textileQtyTxt;
    textileGui.setVisible(false);
    m_widgets[CargoTextile] = textileGui;

    CargoGui tobaccoGui;
    tobaccoGui.lbl = ui->label_8;
    tobaccoGui.priceTxt = ui->tobaccoPriceTxt;
    tobaccoGui.qtyTxt = ui->tobaccoQtyTxt;
    tobaccoGui.contraBtn = ui->tContrBtn;
    tobaccoGui.setVisible(false);
    m_widgets[CargoTobacco] = tobaccoGui;

    CargoGui wineGui;
    wineGui.lbl = ui->label_9;
    wineGui.priceTxt = ui->winePriceTxt;
    wineGui.qtyTxt = ui->wineQtyTxt;
    wineGui.contraBtn = ui->wContrBtn;
    wineGui.setVisible(false);
    m_widgets[CargoWine] = wineGui;

    ui->enableBtn->setText("Enable cargo");
}

void MainWindow::enableCargo()
{
    m_widgets[static_cast<Cargo>(m_disabledCargo++)].setVisible(true);

    if (m_disabledCargo == CargoGems)
        ui->enableBtn->setVisible(false);
}

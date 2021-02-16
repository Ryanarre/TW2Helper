#include "main_window.h"
#include "ui_main_window.h"

#include <QMessageBox>

namespace
{
    const static int s_travelLenght = 14;
}

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
    connect(ui->travelBtn, &QPushButton::clicked, this, &MainWindow::travel);
    connect(ui->predefinedChk, SIGNAL(toggled(bool)), this, SLOT(enableQty(bool)));

    ui->enableBtn->setText("Enable cargo");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectAndDisable()
{
    m_widgets[CargoFish] = CargoGui(ui->label, ui->fishPriceTxt, ui->fishQtyTxt);
    m_widgets[CargoCotton] = CargoGui(ui->label_2, ui->cottonPriceTxt, ui->cottonQtyTxt);
    m_widgets[CargoWood] = CargoGui(ui->label_3, ui->woodPriceTxt, ui->woodQtyTxt);
    m_widgets[CargoCacao] = CargoGui(ui->label_4, ui->cacaoPriceTxt, ui->cacaoQtyTxt);
    m_widgets[CargoSugar] = CargoGui(ui->label_5, ui->sugarPriceTxt, ui->sugarQtyTxt);
    m_widgets[CargoWeapon] = CargoGui(ui->label_6, ui->weaponPriceTxt, ui->weaponQtyTxt);
    m_widgets[CargoTextile] = CargoGui(ui->label_7, ui->textilePriceTxt, ui->textileQtyTxt);
    m_widgets[CargoTobacco] = CargoGui(ui->label_8, ui->tobaccoPriceTxt, ui->tobaccoQtyTxt, ui->tContrBtn);
    m_widgets[CargoWine] = CargoGui(ui->label_9, ui->winePriceTxt, ui->wineQtyTxt, ui->wContrBtn);
    m_widgets[CargoGems] = CargoGui(ui->label_10, ui->gemsPriceTxt, ui->gemsQtyTxt);

    for (int i = m_disabledCargo; i < CargoGems; ++i)
        m_widgets[static_cast<Cargo>(i)].setVisible(false);
}

void MainWindow::enableCargo()
{
    m_widgets[static_cast<Cargo>(m_disabledCargo++)].setVisible(true);

    if (m_disabledCargo == CargoGems)
        ui->enableBtn->setVisible(false);
}

void MainWindow::enableQty(bool _isEnabled)
{
    for (auto & pair : m_widgets)
        pair.second.enableQty(_isEnabled);
}

void MainWindow::travel()
{
    /* Validation */
    for (size_t i = 0; i < CargoGems; ++i)
    {
        if (!m_widgets[static_cast<Cargo>(i)].isValid())
        {
            QMessageBox msgBox;
            msgBox.setText("One or more cargos are unfulfilled!");
            msgBox.exec();
            return;
        }
    }

    if (!ui->optRdb->isChecked() && !ui->pesRdb->isChecked())
    {
        QMessageBox msgBox;
        msgBox.setText("Select a way of calculation!");
        msgBox.exec();
        return;
    }

    /* Data extraction */
    Month month = static_cast<Month>(ui->dateEdit->date().month());
    City city = static_cast<City>(ui->comboBox->currentIndex());
    for (size_t i = 0; i < m_disabledCargo; ++i)
    {
        Cargo cargo = static_cast<Cargo>(i);
        auto const & widget = m_widgets[cargo];
        if (widget.isPriceEnabled())
        {
            PriceStatus status = m_tradeData[cargo].appendPrice(widget.getPrice());
            ui->logTxt->append(enumToString(cargo) + "'s price is " + enumToString(status));

            switch (status)
            {
            case PriceStatusHigh:
            case PriceStatusHighest:
                m_cargoData[city][cargo][month] = PriceStatusHigh;
                break;
            case PriceStatusLow:
            case PriceStatusLowest:
                m_cargoData[city][cargo][month] = PriceStatusLow;
                break;
            default:
                break;
            }
        }
    }

    /* Calculation */
    QDate date = ui->dateEdit->date();
    date = date.addDays(s_travelLenght);
    ui->dateEdit->setDate(date);

    Month newMonth = static_cast<Month>(date.month());

    // TODO: Exclude current city from the predictory search
    for (auto & cityPair : m_cargoData)
    {
        for (auto & cargoPair : cityPair.second)
        {
            if (cargoPair.second[newMonth] == PriceStatusHigh &&
                m_cargoData[city][cargoPair.first][month] == PriceStatusLow)
            {
                ui->logTxt->append(enumToString(cityPair.first) + " " + enumToString(cargoPair.first));
            }
        }
    }

    ui->logTxt->hide();
    ui->logTxt->show();

    ui->dateEdit->hide();
    ui->dateEdit->show();
}

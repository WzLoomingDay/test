#include "waterstock.h"
#include "ui_waterstock.h"

WaterStock::WaterStock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WaterStock)
{
    ui->setupUi(this);
}

WaterStock::~WaterStock()
{
    delete ui;
}

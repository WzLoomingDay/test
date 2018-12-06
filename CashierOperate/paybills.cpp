#include "paybills.h"
#include "ui_paybills.h"

PayBills::PayBills(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PayBills)
{
    ui->setupUi(this);
}

PayBills::~PayBills()
{
    delete ui;
}

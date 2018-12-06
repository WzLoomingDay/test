#include "ordermeals.h"
#include "ui_ordermeals.h"

OrderMeals::OrderMeals(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderMeals)
{
    ui->setupUi(this);
}

OrderMeals::~OrderMeals()
{
    delete ui;
}
void OrderMeals::slotShowOrderMeals()
{

    this->show();
}



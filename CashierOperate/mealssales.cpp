#include "mealssales.h"
#include "ui_mealssales.h"

MealsSales::MealsSales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MealsSales)
{
    ui->setupUi(this);
}

MealsSales::~MealsSales()
{
    delete ui;
}

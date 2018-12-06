#include "addmeals.h"
#include "ui_addmeals.h"

AddMeals::AddMeals(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddMeals)
{
    ui->setupUi(this);
}

AddMeals::~AddMeals()
{
    delete ui;
}

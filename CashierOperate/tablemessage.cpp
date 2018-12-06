#include "tablemessage.h"
#include "ui_tablemessage.h"

TableMessage::TableMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableMessage)
{
    ui->setupUi(this);
}

TableMessage::~TableMessage()
{
    delete ui;
}

#include "waitermessage.h"
#include "ui_waitermessage.h"

WaiterMessage::WaiterMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WaiterMessage)
{
    ui->setupUi(this);
}

WaiterMessage::~WaiterMessage()
{
    delete ui;
}

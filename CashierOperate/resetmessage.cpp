#include "resetmessage.h"
#include "ui_resetmessage.h"

ResetMessage::ResetMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResetMessage)
{
    ui->setupUi(this);
}

ResetMessage::~ResetMessage()
{
    delete ui;
}

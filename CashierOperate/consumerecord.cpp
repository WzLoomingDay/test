#include "consumerecord.h"
#include "ui_consumerecord.h"

ConsumeRecord::ConsumeRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConsumeRecord)
{
    ui->setupUi(this);
}

ConsumeRecord::~ConsumeRecord()
{
    delete ui;
}

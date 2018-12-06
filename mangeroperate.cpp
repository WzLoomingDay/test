#include "mangeroperate.h"
#include "ui_mangeroperate.h"

MangerOperate::MangerOperate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MangerOperate)
{
    ui->setupUi(this);
}

MangerOperate::~MangerOperate()
{
    delete ui;
}
void MangerOperate::slotShowMangerLogin(QString ID)
{
    QString title = "当前管理员ID号为"+ID;
    qDebug()<<title;
    this->setWindowTitle(title);
    this->show();
}

#include "cashieroperate.h"
#include "ui_cashieroperate.h"

CashierOperate::CashierOperate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CashierOperate)
{
    PointerToOrderMeal = new OrderMeals();
    connect(this,SIGNAL(SignalOrderMeal()),PointerToOrderMeal,SLOT(slotShowOrderMeals()));
    ui->setupUi(this);
}

CashierOperate::~CashierOperate()
{
    delete ui;
}
void CashierOperate::slotShowCashierLogin(QString UID)
{
    QString title = "当前前台ID号为"+UID;
    qDebug()<<title;
    this->setWindowTitle(title);
    this->show();
}


void CashierOperate::on_PB_OrderMeal_clicked()
{
    emit SignalOrderMeal();
    this->hide();
}

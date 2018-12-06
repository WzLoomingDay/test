#include "foodmanger.h"
#include "ui_foodmanger.h"

FoodManger::FoodManger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FoodManger)
{
    ui->setupUi(this);
}

FoodManger::~FoodManger()
{
    qDebug()<<"~FoodManger()"<<endl;
    //delete PointertoCashier;
   // delete PointertoManger;
    delete ui;
}

void FoodManger::on_PB_CasierhLogin_clicked()
{
    QString tips;
    QString name;
    UserInfo UserTemp =
    DataBaseOperate::selectUserCashierInfo(ui->lineEdit_ID->text(),ui->lineEdit_Passwd->text());
    if(UserTemp.getID() == "NULL")
    {
        tips = "错误：没有该前台ID";
        name = "ID错误";
        QMessageBox::information(this,name,tips,0x00000400);
    }else if(UserTemp.getPswd() == "NULL")
    {
        tips = "错误：密码错误";
        name = "密码错误";
        QMessageBox::information(this,name,tips,0x00000400);
    }else
    {
        PointertoCashier = new CashierOperate();
        connect(this,SIGNAL(SignalCashierLogin(QString)),PointertoCashier,SLOT(slotShowCashierLogin(QString)));

        emit SignalCashierLogin(ui->lineEdit_ID->text());
        this->hide();
    }
}

void FoodManger::on_PB_MangerLogin_clicked()
{
    QString tips;
    QString name;
    UserInfo UserTemp =
    DataBaseOperate::selectUserMangerInfo(ui->lineEdit_ID->text(),ui->lineEdit_Passwd->text());
    if(UserTemp.getID() == "NULL")
    {
        tips = "错误：没有该管理员ID";
        name = "ID错误";
        QMessageBox::information(this,name,tips,0x00000400);
    }else if(UserTemp.getPswd() == "NULL")
    {
        tips = "错误：密码错误";
        name = "密码错误";
        QMessageBox::information(this,name,tips,0x00000400);
    }else
    {
        PointertoManger = new MangerOperate();
        connect(this,SIGNAL(SignalMangerLogin(QString)),PointertoManger,SLOT(slotShowMangerLogin(QString)));
        emit SignalMangerLogin(ui->lineEdit_ID->text());
        this->hide();
       // delete this;
    }

}

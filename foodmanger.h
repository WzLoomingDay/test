#ifndef FOODMANGER_H
#define FOODMANGER_H

#include <QMainWindow>
#include<QMessageBox>
#include "mangeroperate.h"
#include "cashieroperate.h"
#include "databaseoperate.h"
#include "userinfo.h"


namespace Ui {
class FoodManger;
}

class FoodManger : public QMainWindow
{
    Q_OBJECT

public:
    explicit FoodManger(QWidget *parent = 0);
    ~FoodManger();
signals:
    void SignalCashierLogin(QString UID);
    void SignalMangerLogin(QString UID);
private slots:
    void on_PB_CasierhLogin_clicked();

    void on_PB_MangerLogin_clicked();

private:
    Ui::FoodManger *ui;
    MangerOperate* PointertoManger;
    CashierOperate* PointertoCashier;
};

#endif // FOODMANGER_H

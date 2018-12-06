#ifndef CASHIEROPERATE_H
#define CASHIEROPERATE_H

#include <QWidget>
#include <QDebug>
#include "ordermeals.h"
#include "addmeals.h"
#include "mealssales.h"
#include "paybills.h"
#include "consumerecord.h"
#include "resetmessage.h"
#include "tablemessage.h"
#include "waitermessage.h"
#include "waterstock.h"

namespace Ui {
class CashierOperate;
}

class CashierOperate : public QWidget
{
    Q_OBJECT

public:
    explicit CashierOperate(QWidget *parent = 0);
    ~CashierOperate();
signals:
    void SignalOrderMeal();
    void SignalAddMeal();
    void SignalPayOff();
    void SignalWaiterInfo();
    void SignalTableInfo();
    void SignalMealSales();
    void SignalConsumeRecord();
    void SignalResetMessage();
    void SignalWaterStock();
    void SignalCashierExit();
private slots:
void slotShowCashierLogin(QString UID);
void on_PB_OrderMeal_clicked();

private:
    OrderMeals *PointerToOrderMeal;

    Ui::CashierOperate *ui;
};

#endif // CASHIEROPERATE_H

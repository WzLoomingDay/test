#ifndef DATABASEOPERATE_H
#define DATABASEOPERATE_H
#include<QDebug>
#include<QSqlQuery>
#include<QStandardItem>
#include<QObject>
#include<QWidget>
#include<QSqlRecord>
#include<QVariant>
#include<QList>
#include "userinfo.h"
#include "workerinfo.h"


class DataBaseOperate
{
public:
    DataBaseOperate();
    ~DataBaseOperate();
    static UserInfo selectUserCashierInfo(QString id,QString passwd);
    static UserInfo selectUserMangerInfo(QString id,QString passwd);

    static bool AddWorkerInfo();
    static void DeleteWorkerInfo(const QString &ID);
    static bool CreateWorkerInfo(WorkerInfo &info);

    static void UpdateUserType(QString const &ID,const QString &new_type);
    static void UpdateUserMessage(QString const &ID,QString const &name,const QString &new_type);
     QString  GetIdnumber();//得到第一个不连续的id
protected:
    int  countbits(int number);//计算数字有几位

public slots:
};

#endif // DATABASEOPERATE_H

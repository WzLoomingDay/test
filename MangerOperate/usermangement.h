#ifndef USERMANGEMENT_H
#define USERMANGEMENT_H

#include <QWidget>
#include <QDebug>
#include <QTableView>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QRegExp>
#include "databaseoperate.h"
#include "userinfobox.h"
#include "comboxdelegate.h"
#include "pushbottondelegate.h"
#include "calenderdelegate.h"
#include "comboxsexdelegate.h"
#include "lineeditdelegate.h"
#include "spinboxdelegate.h"
#include "checkboxdelegate.h"


namespace Ui {
class UserMangement;
}

class UserMangement : public QWidget
{
    Q_OBJECT

public:
    void selectUserData(const QString &sql,QSqlQuery &query,const QString &name);
    ~UserMangement();
    void closeEvent(QCloseEvent *event);
    static UserMangement *getUserMangement();
    static void setUserMangermentnullptr();
signals:
    void SignalBackToMangerMenu();
    void SignalShowCreateUser();
private slots:

    void slotShowUsermangement();
    void slotNameDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);


    void on_CB_UserTypeSearch_activated(const QString &arg1);

    void on_PB_SearchUserID_clicked();

    void on_PB_BacktoMenu_clicked();

    void on_pb_AddUser_clicked();

   // void CreateDetailedMessage();


private:
    UserMangement(QWidget *parent = 0);
    Ui::UserMangement *ui;
    QPushButton *m_button;
    UserInfoBox *PointerToUserInfoBox;//单例模式，user info 类中提供函数作为位移创建对象方法


    QStandardItemModel* model;
    Comboxdelegate *comdelegate;
    PushBottonDelegate *Buttondelegate;
    CalenderDelegate *Calenderdelegate;
    comboxSexDelegate *SexDelegate;
    LineEditDelegate * mLineEditDelegat;
    SpinBoxDelegate * mSpinBoxDelegate;
    CheckBoxDelegate *mCheckBoxDelegate;

    static UserMangement *m_userMangement;

};

#endif // USERMANGEMENT_H

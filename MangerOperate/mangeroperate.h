#ifndef MANGEROPERATE_H
#define MANGEROPERATE_H

#include <QWidget>
#include <QDebug>
#include "usermangement.h"
#include "settingmenu.h"
#include "settingtable.h"


namespace Ui {
class MangerOperate;
}

class MangerOperate : public QWidget
{
    Q_OBJECT

public:

    explicit MangerOperate(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~MangerOperate();
signals:
    void SignalShowUserMangement();
    void SignalShowSettingMenu();
private slots:
    void slotShowMangerLogin(const QString ID);


    void on_PB_UserMangement_clicked();


    void on_PB_SettingMeal_clicked();

private:
    UserMangement *PointerToUserMangement;
    SettingMenu *PointerToSettingMenu;
    SettingTable *PointerToSettingTable;
    Ui::MangerOperate *ui;
};

#endif // MANGEROPERATE_H

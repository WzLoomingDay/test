#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QWidget>

namespace Ui {
class SettingMenu;
}

class SettingMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SettingMenu(QWidget *parent = 0);
    ~SettingMenu();
    void closeEvent(QCloseEvent *event);
    static SettingMenu *GetSettingMenu();
    static void setSettingmenuNullptr();
private slots:
    void slotShowSettingMenu();
private:
    static SettingMenu* m_settingmenu;
    Ui::SettingMenu *ui;
};

#endif // SETTINGMENU_H

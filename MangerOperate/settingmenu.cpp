#include "settingmenu.h"
#include "ui_settingmenu.h"


SettingMenu::SettingMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingMenu)
{
    ui->setupUi(this);
}

SettingMenu* SettingMenu::m_settingmenu = nullptr;

SettingMenu::~SettingMenu()
{
    delete ui;
}
SettingMenu * SettingMenu::GetSettingMenu()
{
    if(m_settingmenu == nullptr)
    {
        m_settingmenu = new SettingMenu();
    }
    return m_settingmenu;
}
void SettingMenu::slotShowSettingMenu()
{
    this->show();
}
void SettingMenu::setSettingmenuNullptr()
{
    m_settingmenu = nullptr;
}
void SettingMenu::closeEvent(QCloseEvent *event)
{
    setSettingmenuNullptr();
    delete this;
}

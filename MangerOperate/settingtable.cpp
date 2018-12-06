#include "settingtable.h"
#include "ui_settingtable.h"

SettingTable::SettingTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingTable)
{
    ui->setupUi(this);
}
SettingTable* SettingTable::m_settingtable = nullptr;
SettingTable::~SettingTable()
{
    delete ui;
}
SettingTable* SettingTable::GetSettingTable()
{
    if(m_settingtable == nullptr)
    {
        m_settingtable = new SettingTable;
    }
    return m_settingtable;
}
void SettingTable::closeEvent(QCloseEvent *event)
{
    m_settingtable = nullptr;
    delete this;
}

#ifndef SETTINGTABLE_H
#define SETTINGTABLE_H

#include <QWidget>

namespace Ui {
class SettingTable;
}

class SettingTable : public QWidget
{
    Q_OBJECT

public:

    explicit SettingTable(QWidget *parent = 0);
    ~SettingTable();
    void closeEvent(QCloseEvent *event);
    static SettingTable * GetSettingTable();
private:
    Ui::SettingTable *ui;
    static SettingTable *m_settingtable;

};

#endif // SETTINGTABLE_H

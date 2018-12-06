#ifndef PAYBILLS_H
#define PAYBILLS_H

#include <QWidget>

namespace Ui {
class PayBills;
}

class PayBills : public QWidget
{
    Q_OBJECT

public:
    explicit PayBills(QWidget *parent = 0);
    ~PayBills();

private:
    Ui::PayBills *ui;
};

#endif // PAYBILLS_H

#ifndef ORDERMEALS_H
#define ORDERMEALS_H

#include <QWidget>

namespace Ui {
class OrderMeals;
}

class OrderMeals : public QWidget
{
    Q_OBJECT

public:
    explicit OrderMeals(QWidget *parent = 0);

    ~OrderMeals();
private slots:
void slotShowOrderMeals();

private:
    Ui::OrderMeals *ui;
};

#endif // ORDERMEALS_H

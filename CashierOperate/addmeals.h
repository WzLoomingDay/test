#ifndef ADDMEALS_H
#define ADDMEALS_H

#include <QWidget>

namespace Ui {
class AddMeals;
}

class AddMeals : public QWidget
{
    Q_OBJECT

public:
    explicit AddMeals(QWidget *parent = 0);
    ~AddMeals();

private:
    Ui::AddMeals *ui;
};

#endif // ADDMEALS_H

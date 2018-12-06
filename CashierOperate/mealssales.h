#ifndef MEALSSALES_H
#define MEALSSALES_H

#include <QWidget>

namespace Ui {
class MealsSales;
}

class MealsSales : public QWidget
{
    Q_OBJECT

public:
    explicit MealsSales(QWidget *parent = 0);
    ~MealsSales();

private:
    Ui::MealsSales *ui;
};

#endif // MEALSSALES_H

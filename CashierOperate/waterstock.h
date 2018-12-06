#ifndef WATERSTOCK_H
#define WATERSTOCK_H

#include <QWidget>

namespace Ui {
class WaterStock;
}

class WaterStock : public QWidget
{
    Q_OBJECT

public:
    explicit WaterStock(QWidget *parent = 0);
    ~WaterStock();

private:
    Ui::WaterStock *ui;
};

#endif // WATERSTOCK_H

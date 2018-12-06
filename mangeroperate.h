#ifndef MANGEROPERATE_H
#define MANGEROPERATE_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class MangerOperate;
}

class MangerOperate : public QWidget
{
    Q_OBJECT

public:
    explicit MangerOperate(QWidget *parent = 0);
    ~MangerOperate();
private slots:
    void slotShowMangerLogin(const QString ID);
private:
    Ui::MangerOperate *ui;
};

#endif // MANGEROPERATE_H

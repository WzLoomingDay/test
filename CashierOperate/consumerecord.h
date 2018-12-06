#ifndef CONSUMERECORD_H
#define CONSUMERECORD_H

#include <QWidget>

namespace Ui {
class ConsumeRecord;
}

class ConsumeRecord : public QWidget
{
    Q_OBJECT

public:
    explicit ConsumeRecord(QWidget *parent = 0);
    ~ConsumeRecord();

private:
    Ui::ConsumeRecord *ui;
};

#endif // CONSUMERECORD_H

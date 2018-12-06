#ifndef TABLEMESSAGE_H
#define TABLEMESSAGE_H

#include <QWidget>

namespace Ui {
class TableMessage;
}

class TableMessage : public QWidget
{
    Q_OBJECT

public:
    explicit TableMessage(QWidget *parent = 0);
    ~TableMessage();

private:
    Ui::TableMessage *ui;
};

#endif // TABLEMESSAGE_H

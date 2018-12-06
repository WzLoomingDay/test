#ifndef WAITERMESSAGE_H
#define WAITERMESSAGE_H

#include <QWidget>

namespace Ui {
class WaiterMessage;
}

class WaiterMessage : public QWidget
{
    Q_OBJECT

public:
    explicit WaiterMessage(QWidget *parent = 0);
    ~WaiterMessage();

private:
    Ui::WaiterMessage *ui;
};

#endif // WAITERMESSAGE_H

#ifndef RESETMESSAGE_H
#define RESETMESSAGE_H

#include <QWidget>

namespace Ui {
class ResetMessage;
}

class ResetMessage : public QWidget
{
    Q_OBJECT

public:
    explicit ResetMessage(QWidget *parent = 0);
    ~ResetMessage();

private:
    Ui::ResetMessage *ui;
};

#endif // RESETMESSAGE_H

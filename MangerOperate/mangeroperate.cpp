#include "mangeroperate.h"
#include "ui_mangeroperate.h"

MangerOperate::MangerOperate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MangerOperate)
{
    ui->setupUi(this);
}

MangerOperate::~MangerOperate()
{
    qDebug()<<"delete MangerOperate"<<endl;
    delete ui;
}
void MangerOperate::slotShowMangerLogin(QString ID)
{
    QString title = "当前管理员ID号为"+ID;
    qDebug()<<title;
    this->setWindowTitle(title);
    this->show();
}


void MangerOperate::on_PB_UserMangement_clicked()
{
    PointerToUserMangement = UserMangement::getUserMangement();
    //PointerToUserMangement = new UserMangement();
    connect(this,SIGNAL(SignalShowUserMangement()),PointerToUserMangement,SLOT(slotShowUsermangement()));
    emit SignalShowUserMangement();
}
void MangerOperate::closeEvent(QCloseEvent *event)
{
    //delete this->parent();
    delete this;
}

void MangerOperate::on_PB_SettingMeal_clicked()
{
   PointerToSettingMenu = SettingMenu::GetSettingMenu();
   connect(this,SIGNAL(SignalShowSettingMenu()),PointerToSettingMenu,SLOT(slotShowSettingMenu()));
    emit SignalShowSettingMenu();
}




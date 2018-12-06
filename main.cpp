
#include <QApplication>

#include <QDebug>
#include "database.h"
#include "foodmanger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase MyDataBase;
    if(MyDataBase.DataBase_Connect())
    {
        qDebug()<<"Error"<<endl;

        return -1;
    }
    // qDebug()<<"test git"<<endl;
    // qDebug()<<"test git"<<endl;
   // FoodManger *w = new FoodManger;
   // w->show();
    FoodManger w;
    w.show();
   //qDebug()<<"quitquitquit"<<endl;
   //delete w;
   return  a.exec();

}

#include "databaseoperate.h"

DataBaseOperate::DataBaseOperate()
{

}
DataBaseOperate::~DataBaseOperate()
{

}

UserInfo DataBaseOperate::selectUserCashierInfo(QString id,QString passwd)
{
    UserInfo info;
    QSqlQuery query;
    QString queryString =
    QString("select * from user where ID = '%1' and type_name = 'Cashier'").arg(id);
    //查找id并且是cashier的用户
    qDebug() << queryString;
    query.exec(queryString);
    if(query.isActive())//isActive判断sql语句是否正确
    {
    if(query.first())//first判断是否查到，查到true，没查到false
    {//如果有该前台用户判断密码是否正确
        queryString =
        QString("select * from user where ID = '%1' and pswd = '%2'").arg(id).arg(passwd);
        qDebug() << queryString;
        query.exec(queryString);
        if(query.first())
        {
         int select_ID = query.record().indexOf(QString("ID"));//查到了一条完整数据的ID
         QString select_IDstr =query.value(select_ID).toString();
         qDebug()<<"ID:"<<select_IDstr<<endl;
        }else
        {
            info.setPswd(QString("NULL"));
        }
    }else
    {

        qDebug() << "Error select User"<<endl;
        info.setID(QString("NULL"));//没查到就返回ID为NULL
    }
    }else
    {
        qDebug() << "Error select sql order"<<endl;//select的sql语句错误，查找失败
    }
    return info;

}


UserInfo DataBaseOperate::selectUserMangerInfo(QString id,QString passwd)
{
    UserInfo info;
    QSqlQuery query;
    QString queryString =
    QString("select * from user where ID = '%1' and type_name = 'Manger'").arg(id);
    query.exec(queryString);
    if(query.isActive())
    {
    if(query.first())
    {//如果有该管理员用户判断密码是否正确
        queryString =
        QString("select * from user where ID = '%1' and pswd = '%2'").arg(id).arg(passwd);
        query.exec(queryString);
        if(query.first())
        {
         QString i1=query.value(0).toString();
         qDebug() << i1;
        }else
        {
            info.setPswd(QString("NULL"));
        }
    }else
    {

        qDebug() << "Error select User"<<endl;
        info.setID(QString("NULL"));//没查到就返回ID为NULL
    }
    }else
    {
        qDebug() << "Error select sql order"<<endl;//select的sql语句错误，查找失败
    }
    return info;

}


bool DataBaseOperate::CreateWorkerInfo(WorkerInfo &info)
{
    QSqlQuery Createquery;
    QString CreateUserqueryString =
    QString("insert into user values('%1','%2','%3')")
            .arg(info.getID()).arg(info.getPswd()).arg(info.getType());
    QString CreateWorkerqueryString =
    QString("insert into Worker values ('%1','%2','%3','%4','%5','%6','%7')")
            .arg(info.GetWorkerID()).arg(info.GetWorkerName()).arg(info.GetWorkerSex())
            .arg(info.GetWorkerCall()).arg(info.GetWorkerSalary())
            .arg(info.GetWorkerBirth()).arg(info.GetWorkerJoinTime());
     qDebug()<<CreateUserqueryString;
     qDebug()<<CreateWorkerqueryString;
    Createquery.exec(CreateUserqueryString);
    Createquery.exec(CreateWorkerqueryString);
     return true;

}


void DataBaseOperate::UpdateUserType(const QString &ID,const QString &new_type)
{
    QSqlQuery UpdateTypequery;
    QString UpataUserTypeString =
            QString("update user set type_name = '%1' where ID = '%2'").arg(new_type).arg(ID);
    qDebug()<<UpataUserTypeString;
    UpdateTypequery.exec(UpataUserTypeString);
}


void DataBaseOperate::UpdateUserMessage(const QString &ID,QString const &name,const QString &new_type)
{
    QSqlQuery UpdateUserMessagequery;
    QString UpdateUserMessageString =
            QString("update worker set %1 = '%2' where ID = '%3'").arg(name).arg(new_type).arg(ID);
    qDebug()<<UpdateUserMessageString;
    UpdateUserMessagequery.exec(UpdateUserMessageString);
}


void DataBaseOperate::DeleteWorkerInfo(const QString &ID)
{
    QSqlQuery DeleteWorkerInfoquery;
    QString  DeleteWorkerInfoString =
            QString("delete from worker where ID = '%1'").arg(ID);
    DeleteWorkerInfoquery.exec(DeleteWorkerInfoString);
    DeleteWorkerInfoString =
            QString("delete from user where ID = '%1'").arg(ID);
     DeleteWorkerInfoquery.exec(DeleteWorkerInfoString);

}


QString DataBaseOperate::GetIdnumber()
{
      QString New_ID;
      QSqlQuery GetAllIdQuery;
      QList<int> userIdList;
      int i = 0;
      QString  GetAllIdString =
              QString("select id from user");
      GetAllIdQuery.exec(GetAllIdString);
      //在exec之后必须执行一下first()或者next()因为exec之后record指针没有在数据上，而是在数据的上面

      while(GetAllIdQuery.next())
      {
          //qDebug()<<"id "<<GetAllIdQuery.at()<<" = "<<GetAllIdQuery.value(0).toInt()<<endl;
          userIdList.append(GetAllIdQuery.value(0).toInt());
      }
      int totalnumber =userIdList.size();//总共的用户数量
      int MaxIdnumber = userIdList.last();
      if(totalnumber==MaxIdnumber)
      {
           //qDebug()<<"当前位数"<<this->countbits(MaxIdnumber+1)<<endl;
           QVariant temp = MaxIdnumber+1;
           QString tempstr =temp.toString();
           for(int j = 0;j<6-this->countbits(MaxIdnumber+1);j++)//id最大为6位数，如果数字是两位数前面就有6-2个0
           {
              New_ID.append('0');
           }
           New_ID = New_ID+tempstr;
           qDebug()<<"New_ID = "<<New_ID<<endl;
           return New_ID;
      }else
      {
          for(i = 0;i<=totalnumber;i++)
          {
             if(userIdList.value(i)!=(i+1))//如果数据库数据都是按照id自增排序的话那么，第0个索引放的是id为1的账户
             {
                 QVariant temp = i+1;
                 QString tempstr =temp.toString();
                 for(int j = 0;j<6-this->countbits(i+1);j++)//id最大为6位数，如果数字是两位数前面就有6-2个0
                 {
                    New_ID.append('0');
                 }
                 New_ID = New_ID+tempstr;
                 qDebug()<<"New_ID = "<<New_ID<<endl;
                 return New_ID;

             }
          }
      }
}

int DataBaseOperate::countbits(int number)
{
    int count = 0;
    while(number)
    {
        number = number/10;
        count++;
    }
    return count;
}

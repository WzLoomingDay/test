#include "usermangement.h"
#include "ui_usermangement.h"

UserMangement::UserMangement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserMangement)
{
    //this->setAttribute(Qt::WA_DeleteOnClose);

    model = new QStandardItemModel(this);//Qtableview用到的
    comdelegate = new Comboxdelegate(this);//还没delete
    Buttondelegate = new PushBottonDelegate(this);
    Calenderdelegate = new CalenderDelegate(this);
    SexDelegate = new comboxSexDelegate(this);
    mLineEditDelegat = new LineEditDelegate(this);
    mSpinBoxDelegate = new SpinBoxDelegate(this);
    mCheckBoxDelegate = new CheckBoxDelegate(this);
    ui->setupUi(this);
}
UserMangement* UserMangement::m_userMangement = nullptr;
UserMangement::~UserMangement()
{
    qDebug()<<"delete UserMangement"<<endl;
    //delete PointerToUserInfoBox;//点击一次会有错
   /* delete model;
    delete comdelegate;
    delete Calenderdelegate;
    delete SexDelegate;
    delete mLineEditDelegat;
    delete mSpinBoxDelegate;
    delete Buttondelegate;
    //delete StandardItem;//创建对象时候，有些功能未使用，指针指向空，此时delete程序会崩
     delete mCheckBoxDelegate;*/
    delete ui;
}
UserMangement* UserMangement::getUserMangement()
{
    if(m_userMangement == nullptr)
    {
        m_userMangement = new UserMangement();
    }
    return m_userMangement;
}
void UserMangement::setUserMangermentnullptr()
{
    m_userMangement = nullptr;
}

void UserMangement::slotShowUsermangement()
{
    this->show();
}
void UserMangement::selectUserData(const QString &sql, QSqlQuery &query,const QString &name)
{
    if(query.exec(sql))
    {
    int id_idx = query.record().indexOf("ID");
    int name_idx = query.record().indexOf(name);
    int sex_idx = query.record().indexOf("Worker_sex");
    int type_idx = query.record().indexOf("type_name");
    int call_idx = query.record().indexOf("Worker_call");
    int salary_idx = query.record().indexOf("Worker_Salary");
    int Birth_idx = query.record().indexOf("Worker_Birth");
    int JoinTime_idx = query.record().indexOf("Worker_JoinTime");
    QString Select_Id;
    QString Select_Name;
    QString Select_Sex;
    QString Select_Type;
    QString Select_Call;
    QString Select_Salary;
    QString Select_Birth;
    QString Select_JoinTime;

    while (query.next())
    {
       Select_Id = query.value(id_idx).toString();
       Select_Name = query.value(name_idx).toString();
       Select_Sex = query.value(sex_idx).toString();
       Select_Type = query.value(type_idx).toString();
       Select_Call = query.value(call_idx).toString();
       Select_Salary = query.value(salary_idx).toString();
       Select_Birth = query.value(Birth_idx).toString();
       Select_JoinTime = query.value(JoinTime_idx).toString();
      qDebug()<<"Select_Id"<<Select_Id<<"Select_Name"<<Select_Name<<"Select_Type"<<Select_Type<<endl;
      QStandardItem * StandardItem = new QStandardItem(Select_Id);
      StandardItem->setBackground(QBrush(QColor(241,244,244) ) );
      StandardItem->setEditable(false);
      model->setItem(query.at(),0,StandardItem);

      StandardItem = new QStandardItem(Select_Name);
      StandardItem->setBackground(QBrush(QColor(153,255,153) ) );
      StandardItem->setEditable(true);
      model->setItem(query.at(), 1,StandardItem);

      StandardItem = new QStandardItem(Select_Sex);
      StandardItem->setBackground(QBrush(QColor(137,207,240) ) );
      StandardItem->setEditable(true);
      model->setItem(query.at(), 2,StandardItem);

      StandardItem = new QStandardItem(Select_Type);
      StandardItem->setEditable(true);
      StandardItem->setBackground(QBrush(QColor(137,207,240) ) );//设置为浅蓝色
      model->setItem(query.at(),3,StandardItem);

      StandardItem = new QStandardItem(Select_Call);
      StandardItem->setBackground(QBrush(QColor(153,255,153) ) );
      StandardItem->setEditable(true);
      model->setItem(query.at(), 4,StandardItem);

      StandardItem = new QStandardItem(Select_Salary);
      StandardItem->setBackground(QBrush(QColor(255,255,153) ) );
      StandardItem->setEditable(true);
      model->setItem(query.at(), 5,StandardItem);

      StandardItem =new QStandardItem(Select_Birth);
      StandardItem->setEditable(true);//设置该列是否可以被修改
      StandardItem->setBackground(QBrush(QColor( 255, 204, 255) ) );
      model->setItem(query.at(), 6,StandardItem);

      StandardItem =new QStandardItem("点击删除");
      StandardItem->setEditable(true);//设置该列是否可以被修改
      StandardItem->setBackground(QBrush(QColor(255,185,115) ) );
      model->setItem(query.at(), 7,StandardItem);

      StandardItem =new QStandardItem("点击修改");
      StandardItem->setEditable(true);//设置该列是否可以被修改
      model->setItem(query.at(), 8,StandardItem);

      StandardItem =new QStandardItem(Select_JoinTime);
      StandardItem->setBackground(QBrush(QColor(241,244,244) ) );
      StandardItem->setEditable(false);//设置该列是否可以被修改
      model->setItem(query.at(),9,StandardItem);
     /*ui->tableView_User->horizontaladeHer()->setSectionResizeMode(0,QHeaderView::ResizeToContents);//让该列根据字数大小进行自动调整*/
    }
    }else
    {
         qDebug()<<"no Select"<<endl;
    }
    /*for(int i = 0;i<model->rowCount();i++)
    {
    standardItem = model->item(i,2);
    emit model->itemChanged(standardItem);
    }*/

}
void UserMangement::on_CB_UserTypeSearch_activated(const QString &arg1)
{

    qDebug()<<"activated"<<arg1<<endl;
    Comboxdelegate *comdelegate = new Comboxdelegate();//还没delete
   // PushBottonDelegate *Buttondelegate = new PushBottonDelegate();
    model->clear();//清除上一次表格中的内容
    model->setColumnCount(10);//设置表格几列
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"性别");
     model->setHeaderData(3,Qt::Horizontal,"职位");
     model->setHeaderData(4,Qt::Horizontal,"电话");
      model->setHeaderData(5,Qt::Horizontal,"工资");
      model->setHeaderData(6,Qt::Horizontal,"出生日期");
    model->setHeaderData(7,Qt::Horizontal,"删除用户");
    model->setHeaderData(8,Qt::Horizontal,"修改密码");
     model->setHeaderData(9,Qt::Horizontal,"入职时间");
    if(arg1 == "管理员")
    {
         QSqlQuery queryManger;
         QString queryStringManger =
         QString("select * from (user natural join worker) where id in (select id from user where type_name = 'manger')"
                 "ORDER BY id ASC");//ORDER BY id ASC防止mysql乱序排列
         UserMangement::selectUserData(queryStringManger,queryManger,"worker_name");

    }else if(arg1 == "前台")
    {
        QSqlQuery queryCashier;
        QString queryStringCashier =
        QString("select * from (user natural join worker) where id in (select id from user where type_name = 'Cashier')"
                "ORDER BY id ASC");
        UserMangement::selectUserData(queryStringCashier,queryCashier,"worker_name");

    }else if(arg1 == "服务员")
    {
        QSqlQuery queryWaiter;
        QString queryStringWaiter =
        QString("select * from (user natural join worker) where id in (select id from user where type_name = 'Waiter')"
                "ORDER BY id ASC");
        UserMangement::selectUserData(queryStringWaiter,queryWaiter,"worker_name");

    }else if(arg1 == "所有用户")
    {
        QSqlQuery queryUser;
        QString queryStringUser =
        QString("select * from (user natural join worker) ORDER BY id ASC");
        UserMangement::selectUserData(queryStringUser,queryUser,"worker_name");
    }

    ui->tableView_User->setModel(model);
    ui->tableView_User->setItemDelegateForColumn(1,mLineEditDelegat);
    ui->tableView_User->setItemDelegateForColumn(2,SexDelegate);
    ui->tableView_User->setItemDelegateForColumn(3,comdelegate);
    ui->tableView_User->setItemDelegateForColumn(4,mLineEditDelegat);
    ui->tableView_User->setItemDelegateForColumn(6,Calenderdelegate);
    ui->tableView_User->setItemDelegateForColumn(5,mSpinBoxDelegate);
    ui->tableView_User->setItemDelegateForColumn(7,mCheckBoxDelegate);
    ui->tableView_User->setItemDelegateForColumn(8,Buttondelegate);


   // ui->tableView_User->resizeColumnToContents(4);
    //ui->tableView_User->resizeColumnToContents(7);
   ui->tableView_User->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//让表格大小适应model，即是tableview
   // ui->tableView_User->setEditTriggers(QAbstractItemView::SelectedClicked);//设置表格不允许编辑

}

void UserMangement::on_PB_SearchUserID_clicked()
{
     QString Searchid = ui->LineEdit_UserIDSearch->text();

     qDebug()<<"Search id = "<<Searchid<<endl;
     model->clear();//清除上一次表格中的内容
     model->setColumnCount(10);//设置表格几列
     model->setHeaderData(0,Qt::Horizontal,"id");
     model->setHeaderData(1,Qt::Horizontal,"姓名");
    model->setHeaderData(2,Qt::Horizontal,"性别");
     model->setHeaderData(3,Qt::Horizontal,"职位");
     model->setHeaderData(4,Qt::Horizontal,"电话");
      model->setHeaderData(5,Qt::Horizontal,"工资");
      model->setHeaderData(6,Qt::Horizontal,"出生日期");
       model->setHeaderData(7,Qt::Horizontal,"删除用户");
       model->setHeaderData(8,Qt::Horizontal,"修改密码");
        model->setHeaderData(9,Qt::Horizontal,"入职时间");
     QSqlQuery querySearchID;
     QString queryStringSearchID =
     QString("select * from (user natural join worker) where id = %1").arg(Searchid);
     UserMangement::selectUserData(queryStringSearchID,querySearchID,"worker_name");
     ui->tableView_User->setModel(model);
     ui->tableView_User->setItemDelegateForColumn(1,mLineEditDelegat);
     ui->tableView_User->setItemDelegateForColumn(2,SexDelegate);
     ui->tableView_User->setItemDelegateForColumn(3,comdelegate);
     ui->tableView_User->setItemDelegateForColumn(4,mLineEditDelegat);
     ui->tableView_User->setItemDelegateForColumn(5,mSpinBoxDelegate);
     ui->tableView_User->setItemDelegateForColumn(6,Calenderdelegate);
     ui->tableView_User->setItemDelegateForColumn(7,mCheckBoxDelegate);
     ui->tableView_User->setItemDelegateForColumn(8,Buttondelegate);
    // ui->tableView_User->setItemDelegateForColumn(3,Buttondelegate);
     ui->tableView_User->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//让表格大小适应model，即是tableview
    // ui->tableView_User->resizeColumnsToContents();
    // ui->tableView_User->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格不允许编辑

}

void UserMangement::on_PB_BacktoMenu_clicked()
{
    emit SignalBackToMangerMenu();
    this->hide();
}

void UserMangement::on_pb_AddUser_clicked()
{
    PointerToUserInfoBox = UserInfoBox::GetUserInfoBox();
    //PointerToUserInfoBox = new UserInfoBox();
    connect(this,SIGNAL(SignalShowCreateUser()),PointerToUserInfoBox,SLOT(slotShowUserInfoBox()));
    emit SignalShowCreateUser();
}

void UserMangement::slotNameDataChanged(const QModelIndex &topLeft,
                                        const QModelIndex &bottomRight)
{
    qDebug()<<"name data changed"<<endl;
}
 void UserMangement::closeEvent(QCloseEvent *event)
 {
     UserMangement::setUserMangermentnullptr();//因为删除对象后，ptr不为nullptr就不会在下一次创建新对象
     delete this;
 }





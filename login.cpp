#include "login.h"
#include "ui_login.h"

LOGIN::LOGIN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LOGIN)
{
    ui->setupUi(this);


    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("Manager.db");
    db.setUserName("admin");
    db.setPassword("123456");
    query = QSqlQuery(db);
    bool sql_open=db.open();
    if(!sql_open){
        qDebug()<<"打开失败";
    }
        //创建roomstatu sql
        QString create_table="create table if not exists RoomStatu(RoomNumber int primary key,Reservation bool,ReservationDate datetime, CheckIn bool,CheckInDate datetime,CheckInTime datetime,PeopleNumber int not null,Remark text)";
        bool create=query.exec(create_table);
        if(!create){
            qDebug()<<"创建失败"<<query.lastError().text();
        }else{
            qDebug()<<"创建成功";
        }

    query.exec("create table if not exists Event(Etime datetime primary key,RoomNumber int not null,Event text not null,state int ) ");
    query.exec("create table if not exists Room(RoomNumber int primary key,Price int not null,ViP int)");
    query.exec("create table if not exists Roomer(RTime datetime primary key,Name text not null,PersonID text not null,Phone text not null,Gender bool not null,RoomNumber int not null,UseVIP bool ,State int )");
    query.exec("create table if not exists User(Username int not null primary key,Password varchar not null,Vip bool default false)");


    query.exec("insert into user(Username,Password,Vip) values(123456,'password',1)");
    query.exec("insert into user(Username,Password,Vip) values(987654,'password',0)");
    query.exec("insert into user(Username,Password,Vip) values(552252,'password')");
}

LOGIN::~LOGIN()
{
    delete ui;
}

void LOGIN::on_login_clicked()
{
    Manager *m=new Manager;
    m->show();
    close();
}




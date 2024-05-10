#include "Manager.h"

Manager::Manager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("酒店前台管理系统");
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
        query.exec("create table if not exists Event(DateTime datetime primary key,RoomNumber int not null,Event text not null,state int ) ");
        query.exec("create table if not exists Room(RoomNumber int primary key,Price int not null,VIP int)");
        query.exec("create table if not exists Roomer(DateTime datetime primary key,Name text not null,PersonID text(18) not null,Phone text(11) not null,Gender bool not null,RoomNumber int not null,UseVIP bool ,State int )");

        //设置stackedwidget初始页面
        ui.stackedWidget->setCurrentWidget(ui.page_2);
    db.close();
}

Manager::~Manager()
{}


//预约按钮
void Manager::on_appoin_button_clicked()
{
    ui.stackedWidget->setCurrentIndex(0);
}
//登记
void Manager::on_register_button_clicked()
{
    ui.stackedWidget->setCurrentIndex(1);
}
//退房
void Manager::on_check_out_clicked()
{
    ui.stackedWidget->setCurrentIndex(2);
}
//事件
void Manager::on_event_clicked()
{
    ui.stackedWidget->setCurrentIndex(3);
}
//今日房源
void Manager::on_room_infor_clicked()
{
    ui.stackedWidget->setCurrentIndex(4);
}

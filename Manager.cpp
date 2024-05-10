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
    ui.name->setPlaceholderText("姓名");
    ui.gender->setPlaceholderText("性别");
    ui.phone->setPlaceholderText("手机号");
    ui.personID->setPlaceholderText("身份证号");
    ui.roomnumber->setPlaceholderText("房间号");
    ui.vip->setPlaceholderText("VIP");
    ui.datetime->setPlaceholderText("入住时间");

        //创建roomstatu sql
        QString create_table="create table if not exists RoomStatu(RoomNumber int primary key,Reservation bool,ReservationDate datetime, CheckIn bool,CheckInDate datetime,CheckInTime datetime,PeopleNumber int not null,Remark text)";
        bool create=query.exec(create_table);
        if(!create){
            qDebug()<<"创建失败"<<query.lastError().text();
        }else{
            qDebug()<<"创建成功";
        }

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

void Manager::on_dengji_clicked()
{
    db.open();
    QString dengji_sql = "insert into Roomer(Rtime,Name,PersonID,Phone,Gender,RoomNumber,UseVIP) values(?,?,?,?,?,?,?)";
    QSqlQuery query;
    query.prepare(dengji_sql);
    query.addBindValue(ui.datetime->text());
    query.addBindValue(ui.name->text());
    query.addBindValue(ui.personID->text());
    query.addBindValue(ui.phone->text());
    query.addBindValue(ui.gender->text());
    query.addBindValue(ui.roomnumber->text());
    query.addBindValue(ui.vip->text());

    if(!query.exec()){
        qDebug()<<"登记失败"<<query.lastError().text();
    }else{
        qDebug()<<"登记成功";
    }
    db.close();
}

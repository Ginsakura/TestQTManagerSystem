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
    this->setWindowTitle(QString::fromLocal8Bit("酒店前台管理系统"));
    //设置stackedwidget初始页面
    ui.stackedWidget->setCurrentWidget(ui.page_2);

    //今日房源信息输出
//    QSqlQuery query = sql.SelectAll("RoomStatu");
//    while (query.next()) {
//        RoomNumberList <<query.value(0).toString();
//        for(int row=0;row<12;row++){
//            int col=0;
//        ui.tableWidget->setItem(row,col,new QTableWidgetItem(RoomNumberList[row]));
//        }
//    }
//        RoomNumberList <<query.value(0).toString();
//        for(int row=0;row<12;row++){
//            int col=0;
//        ui.tableWidget->setItem(row,col,new QTableWidgetItem(RoomNumberList[row]));
//        }
    QSqlQuery q=sql.SelectAll("RoomStatu");

    int i=0;
    while (q.next()){
//        QStringList RoomNumberList;
        QString RoomNumber=q.value(0).toString();
        QString Reservation=q.value(1).toString();
        QString ReservationDate=q.value(2).toString();
        QString CheckIn=q.value(3).toString();
        QString CheckInDate=q.value(4).toString();
        QString CheckInTime=q.value(5).toString();
        QString PeopleNumber=q.value(6).toString();
        QString Remark =q.value(7).toString();
        ui.tableWidget->insertRow(i);
        ui.tableWidget->setItem(i,0,new QTableWidgetItem(RoomNumber));
        ui.tableWidget->setItem(i,1,new QTableWidgetItem(Reservation));
        ui.tableWidget->setItem(i,2,new QTableWidgetItem(ReservationDate));
        ui.tableWidget->setItem(i,3,new QTableWidgetItem(CheckIn));
        ui.tableWidget->setItem(i,4,new QTableWidgetItem(CheckInDate));
        ui.tableWidget->setItem(i,5,new QTableWidgetItem(CheckInDate));
        ui.tableWidget->setItem(i,6,new QTableWidgetItem(PeopleNumber));
        ui.tableWidget->setItem(i,7,new QTableWidgetItem(Remark));
        i++;
    }

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

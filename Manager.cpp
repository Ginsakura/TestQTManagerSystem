#include "Manager.h"


Manager::Manager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //设置stackedwidget初始页面
    ui.stackedWidget->setCurrentWidget(ui.page_2);
    this->setWindowTitle(QString::fromLocal8Bit("酒店前台管理系统"));
    //设置stackedwidget初始页面
    ui.stackedWidget->setCurrentWidget(ui.page_2);

    ui.name->setPlaceholderText(QString::fromLocal8Bit("姓名"));
    ui.gender->setPlaceholderText(QString::fromLocal8Bit("性别"));
    ui.phone->setPlaceholderText(QString::fromLocal8Bit("手机号"));
    ui.personID->setPlaceholderText(QString::fromLocal8Bit("身份证号"));
    ui.roomnumber->setPlaceholderText(QString::fromLocal8Bit("房间号"));
    ui.vip->setPlaceholderText(QString::fromLocal8Bit("VIP"));
    ui.datetime->setPlaceholderText(QString::fromLocal8Bit("入住时间"));

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
        QString CheckEndDate=q.value(5).toString();
        QString PeopleNumber=q.value(6).toString();
        QString Remark =q.value(7).toString();
        ui.tableWidget->insertRow(i);
        ui.tableWidget->setItem(i,0,new QTableWidgetItem(RoomNumber));
        ui.tableWidget->setItem(i,1,new QTableWidgetItem(Reservation));
        ui.tableWidget->setItem(i,2,new QTableWidgetItem(ReservationDate));
        ui.tableWidget->setItem(i,3,new QTableWidgetItem(CheckIn));
        ui.tableWidget->setItem(i,4,new QTableWidgetItem(CheckInDate));
        ui.tableWidget->setItem(i,5,new QTableWidgetItem(CheckEndDate));
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
    Roomer roomer;
    if (ui.datetime->text() == "") {
        roomer.recordTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    }
    else {
        roomer.recordTime = ui.datetime->text();
    }
    roomer.name = ui.name->text();
    roomer.personID = ui.personID->text();
    roomer.phone = ui.phone->text();
    roomer.gender = ui.gender->text() == "1" ? 1 : 0;
    roomer.roomNumber = ui.roomnumber->text().toInt();
    roomer.useVIP = ui.vip->text() == "1" ? 1 : 0;
    roomer.state = 0;
    roomer.save();
    //QString value = QString("\"%1\",\"%2\",\"%3\",\"%4\",%5,\"%6\",%7,%8")
    //    .arg("2024-05-10 18:09:00").arg()
    //    .arg().arg().arg("true")
    //    .arg().arg("false").arg("0");
    //sql.Insert("Roomer", "RecordTime,Name,PersonID,Phone,Gender,RoomNumber,UseVIP,State", value);
}

#include "Manager.h"
#include "sql.h"

Manager::Manager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("酒店前台管理系统");
    //设置stackedwidget初始页面
    ui.stackedWidget->setCurrentWidget(ui.page_2);

    //今日房源信息输出
<<<<<<< HEAD
//    QSqlQuery query = sql.SelectAll("RoomStatu");
//    while (query.next()) {
=======
    QStringList RoomNumberList;
    QSqlQuery query = sql.SelectAll("RoomStatu");
    while (query.next()) {
        RoomNumberList <<query.value(0).toString();
        for(int row=0;row<12;row++){
            int col=0;
        ui.tableWidget->setItem(row,col,new QTableWidgetItem(RoomNumberList[row]));
        }
    }
>>>>>>> 5d39af8eafcfa731f6eb69cb9b7759d48ac3411f
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
//    qDebug()<<
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

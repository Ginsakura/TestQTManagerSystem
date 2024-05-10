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
    QStringList RoomNumberList;
    QSqlQuery query = sql.SelectAll("RoomStatu");
    while (query.next()) {
        RoomNumberList <<query.value(0).toString();
        for(int row=0;row<12;row++){
            int col=0;
        ui.tableWidget->setItem(row,col,new QTableWidgetItem(RoomNumberList[row]));
        }
    }
//        RoomNumberList <<query.value(0).toString();
//        for(int row=0;row<12;row++){
//            int col=0;
//        ui.tableWidget->setItem(row,col,new QTableWidgetItem(RoomNumberList[row]));
//        }
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

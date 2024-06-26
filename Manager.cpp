﻿#include "Manager.h"

Manager::Manager(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("酒店前台管理系统"));
	//设置stackedwidget初始页面
	ui.stackedWidget->setCurrentWidget(ui.dengji);
    UpdateRoomStatus();
}
Manager::Manager(bool admin, QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	if (admin) {
		ui.isAdmin->setText("Admin");
		isAdmin = admin;
	}
	this->setWindowTitle(QString::fromLocal8Bit("酒店前台管理系统"));
	//设置stackedwidget初始页面
	ui.stackedWidget->setCurrentWidget(ui.dengji);
    UpdateRoomStatus();
}

Manager::~Manager()
{}

//预约页面
void Manager::on_yuyuePageBtn_clicked() {
	ui.stackedWidget->setCurrentIndex(0);
}
//登记页面
void Manager::on_dengjiPageBtn_clicked() {
	ui.stackedWidget->setCurrentIndex(1);
}
//退房页面
void Manager::on_tuifangPageBtn_clicked() {
	ui.stackedWidget->setCurrentIndex(2);
}
//事件页面
void Manager::on_eventPageBtn_clicked() {
	ui.stackedWidget->setCurrentIndex(3);
}
//提交入住登记数据
void Manager::on_dengjiBtn_clicked() {
	Roomer roomer;
	roomer.recordTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	roomer.name = ui.name->text();
	roomer.personID = ui.personID->text();
	roomer.phone = ui.phone->text();
	roomer.gender = ui.gender->currentIndex();
	roomer.roomNumber = ui.roomnumber->text().toInt();
	roomer.useVIP = ui.isVIP->isChecked();
	roomer.state = QString::fromLocal8Bit("登记入住");
	roomer.save();

    QString roomn = QString("RoomNumber=%0").arg(ui.roomnumber->text().toInt());
	sql.Update("RoomStatu", "Reservation", "false", roomn);
	QDateTime curr = QDateTime::currentDateTime();
	sql.Update("RoomStatu", "ReservationDate", "", roomn);
	sql.Update("RoomStatu", "CheckIn", "true", roomn);
	sql.Update("RoomStatu", "CheckInDate", curr.toString("yyyy-MM-dd hh:mm:ss"), roomn);
	sql.Update("RoomStatu", "CheckEndDate", curr.addDays(ui.dateLenth->value()).toString("yyyy-MM-dd hh:mm:ss"), roomn);
	sql.Update("RoomStatu", "PeopleNumber", "1", roomn);
	UpdateRoomStatus();

    QMessageBox msgbox;
    msgbox.setWindowTitle(" ");
    msgbox.setText("登记成功");
    msgbox.setIcon(QMessageBox::Information);
    msgbox.addButton(QMessageBox::Ok);
    msgbox.exec();

    ui.name->setText("");
    ui.roomnumber->setText("");
    ui.personID->setText("");
    ui.phone->setText("");
    ui.isVIP->setChecked(false);

}
//提交预约数据
void Manager::on_yuyueBtn_clicked() {
    Roomer roomer;
	roomer.recordTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	roomer.name = ui.nameYu->text();
	roomer.personID = ui.personIDYu->text();
	roomer.phone = ui.phoneYu->text();
	roomer.gender = ui.genderYu->currentIndex();
    roomer.roomNumber = ui.roomnumberYu->text().toInt();
	roomer.useVIP = ui.isVIPYu->isChecked();
	roomer.state = QString::fromLocal8Bit("预约");
	roomer.save();

    QString roomn = QString("RoomNumber=%1").arg(ui.roomnumberYu->text().toInt());
	sql.Update("RoomStatu", "Reservation", "true", roomn);
	sql.Update("RoomStatu", "ReservationDate", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"), roomn);
	sql.Update("RoomStatu", "CheckIn", "false", roomn);
	sql.Update("RoomStatu", "CheckInDate", "", roomn);
	sql.Update("RoomStatu", "CheckEndDate", "", roomn);
    sql.Update("RoomStatu", "PeopleNumber", "1", roomn);
	UpdateRoomStatus();
}
//今日房源视图
void Manager::UpdateRoomStatus() {
	ui.tableWidget->reset();
	QSqlQuery q = sql.SelectAll("RoomStatu");
	int i = 0;
	while (q.next()) {
		//        QStringList RoomNumberList;
		QString RoomNumber = q.value(0).toString();
		QString Reservation = q.value(1).toString();
		QString ReservationDate = q.value(2).toString();
		QString CheckIn = q.value(3).toString();
		QString CheckInDate = q.value(4).toString();
		QString CheckEndDate = q.value(5).toString();
        QString PeopleNumber = q.value(6).toString();
		QString Remark = q.value(7).toString();
		ui.tableWidget->insertRow(i);
		ui.tableWidget->setItem(i, 0, new QTableWidgetItem(RoomNumber));
		ui.tableWidget->setItem(i, 1, new QTableWidgetItem(Reservation));
		ui.tableWidget->setItem(i, 2, new QTableWidgetItem(ReservationDate));
		ui.tableWidget->setItem(i, 3, new QTableWidgetItem(CheckIn));
		ui.tableWidget->setItem(i, 4, new QTableWidgetItem(CheckInDate));
		ui.tableWidget->setItem(i, 5, new QTableWidgetItem(CheckEndDate));
		ui.tableWidget->setItem(i, 6, new QTableWidgetItem(PeopleNumber));
		ui.tableWidget->setItem(i, 7, new QTableWidgetItem(Remark));
		i++;
	}
}
//事件查询按钮
void Manager::on_incident_view_clicked()
{
    QSqlQuery event_query =sql.SelectAll("Event");
    int i=0;
    while(event_query.next()){
        QString RecordTime=event_query.value(0).toString();
        QString RoomNumber=event_query.value(1).toString();
        QString Event=event_query.value(2).toString();
        QString State=event_query.value(3).toString();
        ui.event_view->insertRow(i);
        ui.event_view->setItem(i,0,new QTableWidgetItem(RecordTime));
        ui.event_view->setItem(i,1,new QTableWidgetItem(Event));
        ui.event_view->setItem(i,2,new QTableWidgetItem(RoomNumber));
        ui.event_view->setItem(i,3,new QTableWidgetItem(State));
        i++;
    }

}
//事件插入按钮
void Manager::on_event_insert_clicked()
{
    Event event;
    event.recordTime=ui.event_time->text();
    event.roomNumber=ui.room_number_event->text().toInt();
    event.event=ui.event_edit->text();
    event.state=ui.event_status->currentText();
    event.save();

}
//事件状态更新按钮
void Manager::on_event_update_clicked()
{

    QString event = QString("RecordTime=\"%0\"").arg(ui.event_time->text());
    sql.Update("Event","State",ui.event_status->currentText(),event);
}

//退房
void Manager::on_tuifangBtn_clicked() {
	int roomN = ui.roomNumberTui->text().toInt();

	Roomer roomer;
	QMessageBox msg;
	QSqlQuery q = sql.Select("Roomer", "*", QString("RoomNumber=%0 order by RecordTime DESC").arg(roomN));
	if (q.next()) {
		roomer.recordTime = q.value(0).toString();
		roomer.name = q.value(1).toString();
		roomer.personID = q.value(2).toString();
		roomer.phone = q.value(3).toString();
		roomer.gender = q.value(4).toBool();
		roomer.roomNumber = q.value(5).toInt();
		roomer.useVIP = q.value(6).toBool();
		roomer.state = q.value(7).toString();
        if (roomer.state == "登记入住"||roomer.state=="预约") {
            QString roomn = QString("RoomNumber=%1").arg(ui.roomNumberTui->text().toInt());
            sql.Update("RoomStatu", "Reservation", "0", roomn);
            sql.Update("RoomStatu", "ReservationDate","", roomn);
            sql.Update("RoomStatu", "CheckIn", "0", roomn);
			sql.Update("RoomStatu", "CheckInDate", "", roomn);
			sql.Update("RoomStatu", "CheckEndDate", "", roomn);
            sql.Update("RoomStatu", "PeopleNumber", "0", roomn);
			UpdateRoomStatus();
		}
		else {
			qout << QFgColor(0xff, 0, 0) << QString::fromLocal8Bit("当前房间无人入住") << QResetColor();
			msg.setText("当前房间无人入住");
			msg.exec();
		}
	}
	else {
		qout << QFgColor(0xff, 0, 0) << QString::fromLocal8Bit("当前房间无记录") << QResetColor();
		msg.setText("当前房间无记录");
		msg.exec();
	}
}

#include "Manager.h"

Manager::Manager(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setWindowTitle(QString::fromLocal8Bit("酒店前台管理系统"));
	//设置stackedwidget初始页面
	ui.stackedWidget->setCurrentWidget(ui.dengji);
}

Manager::~Manager()
{}

//预约按钮
void Manager::on_yuyuePageBtn_clicked() {
	ui.stackedWidget->setCurrentIndex(0);
}
//登记
void Manager::on_dengjiPageBtn_clicked() {
	ui.stackedWidget->setCurrentIndex(1);
}
//退房
void Manager::on_tuifangPageBtn_clicked() {
	ui.stackedWidget->setCurrentIndex(2);
}
//事件
void Manager::on_eventPageBtn_clicked() {
	ui.stackedWidget->setCurrentIndex(3);
}

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

	RoomStatu rooms;
	rooms.roomNumber = ui.roomnumber->text().toInt();
	rooms.checkIn = true;
	QDateTime curr = QDateTime::currentDateTime();
	rooms.checkInDate = curr.toString("yyyy-MM-dd hh:mm:ss");
	rooms.checkEndTime = curr.addDays(1).toString("yyyy-MM-dd hh:mm:ss");
	rooms.peopleNumber = 1;
	rooms.save();
	UpdateRoomStatus();
}
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

	RoomStatu rooms;
	rooms.roomNumber = ui.roomnumberYu->text().toInt();
	rooms.reservation = true;
	rooms.reservationDate = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	rooms.peopleNumber = 1;
	rooms.save();
	UpdateRoomStatus();
}

void Manager::UpdateRoomStatus() {
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
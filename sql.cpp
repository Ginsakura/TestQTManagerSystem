#include "sql.h"
#include "functions.h"

SQLOperat::SQLOperat(QSqlDatabase db) {
	DB = db;
	cursor = QSqlQuery(DB);
}
SQLOperat::SQLOperat() {
	DB = QSqlDatabase::addDatabase("QSQLITE");
	DB.setHostName("127.0.0.1");
	DB.setDatabaseName("Manager.db");
	DB.setUserName("admin");
	DB.setPassword("123456");
	if (!DB.open()) {
		qout << QFgColor(0xff, 0, 0) << QString::fromLocal8Bit("打开失败") << QResetColor();
	}
	cursor = QSqlQuery(DB);
	bool create = false;
	//create table
	cursor.prepare("create table if not exists RoomStatu ("
		"RoomNumber int primary key,"
		"Reservation bool,"
		"ReservationDate datetime,"
		"CheckIn bool,"
		"CheckInDate datetime,"
		"CheckInTime datetime,"
		"PeopleNumber int not null,"
		"Remark text );");
	create = cursor.exec();
	if (create) {
		qout << QFgColor(0, 0xff, 0) << QString::fromLocal8Bit("RoomStatu表创建成功或已存在") << QResetColor();
	}
	else {
		qout << QFgColor(0xff, 0, 0) << QString::fromLocal8Bit("RoomStatu表创建失败: ") << QResetColor() << cursor.lastError();
	}
	cursor.prepare("create table if not exists Event ("
		"RecordTime datetime primary key,"
		"RoomNumber int not null,"
		"Event text not null,"
		"state int );");
	create = cursor.exec();
	if (create) {
		qout << QFgColor(0, 0xff, 0) << QString::fromLocal8Bit("Event表创建成功或已存在") << QResetColor();
	}
	else {
		qout << QFgColor(0xff, 0, 0) << QString::fromLocal8Bit("Event表创建失败: ") << QResetColor() << cursor.lastError();
	}
	cursor.prepare("create table if not exists Room ("
		"RoomNumber int primary key,"
		"Price int not null,"
		"VIP int);");
	create = cursor.exec();
	if (create) {
		qout << QFgColor(0, 0xff, 0) << QString::fromLocal8Bit("Room表创建成功或已存在") << QResetColor();
	}
	else {
		qout << QFgColor(0xff, 0, 0) << QString::fromLocal8Bit("Room表创建失败: ") << QResetColor() << cursor.lastError();
	}
	cursor.prepare("create table if not exists Roomer ("
		"RecordTime datetime primary key,"
		"Name text not null,"
		"PersonID text(18) not null,"
		"Phone text(11) not null,"
		"Gender bool not null,"
		"RoomNumber int not null,"
		"UseVIP bool,"
		"State int);");
	create = cursor.exec();
	if (create) {
		qout << QFgColor(0, 0xff, 0) << QString::fromLocal8Bit("Roomer表创建成功或已存在") << QResetColor();
	}
	else {
		qout << QFgColor(0xff, 0, 0) << QString::fromLocal8Bit("Roomer表创建失败: ") << QResetColor() << cursor.lastError();
	}
	cursor.prepare("create table if not exists User ("
		"UserName text primary key,"
		"Password not null,"
		"Permission bool default false);");
	create = cursor.exec();
	if (create) {
		qout << QFgColor(0, 0xff, 0) << QString::fromLocal8Bit("User表创建成功或已存在") << QResetColor();
	}
	else {
		qout << QFgColor(0xff, 0, 0) << QString::fromLocal8Bit("User表创建失败: ") << QResetColor() << cursor.lastError();
	}
}
QSqlQuery SQLOperat::SelectAll(const QString table) {
	QSqlQuery cur = QSqlQuery(DB);
	cur.prepare(QString("SELECT * from %1").arg(table));
	bool state = cur.exec();
	if (state) {
		return cur;
	}
	else {
		qout << QFgColor(0xff, 0, 0) << "select error: " << QResetColor() << cur.lastError();
	}
}
bool SQLOperat::Insert(const QString table, const QString keys, const QString value) {
	cursor.prepare(QString("Insert into %1(%2) values (%3)").arg(table).arg(keys).arg(value));
	bool state = cursor.exec();
	if (!state) {
		qout << QFgColor(0xff, 0, 0) << "Insert to" << table << " error: " << QResetColor() << cursor.lastError();
	}
	return state;
}
bool SQLOperat::Insert(const QString table, const QString value) {
	cursor.prepare(QString("Insert into %1 values (%2)").arg(table).arg(value));
	bool state = cursor.exec();
	if (!state) {
		qout << QFgColor(0xff, 0, 0) << "Insert to" << table << " error: " << QResetColor() << cursor.lastError();
	}
	return state;
}
bool SQLOperat::Update(const QString table, const QString keys, const QString value, const QString condition) {
	cursor.prepare(QString("Update %1 set '%2'='%3' where %3").arg(table).arg(keys).arg(value).arg(condition));
	bool state = cursor.exec();
	if (!state) {
		qout << QFgColor(0xff, 0, 0) << "Insert to" << table << " error: " << QResetColor() << cursor.lastError();
	}
	return state;
}
QSqlQuery SQLOperat::Select(const QString table, const QString getter, const QString condition) {
	QSqlQuery cur = QSqlQuery(DB);
	cur.prepare(QString("select %1 from %2 where %3").arg(getter).arg(table).arg(condition));
	bool state = cur.exec();
	if (state) {
		return cur;
	}
	else {
		qout << QFgColor(0xff, 0, 0) << "select error: " << QResetColor() << cur.lastError();
	}
}
QSqlQuery SQLOperat::Select(const QString table, const QString getter = "*") {
	QSqlQuery cur = QSqlQuery(DB);
	cursor.prepare(QString("select %1 from %2").arg(getter).arg(table));
	bool state = cursor.exec();
	if (state) {
		return cur;
	}
	else {
		qout << QFgColor(0xff, 0, 0) << "select error: " << QResetColor() << cur.lastError();
	}
}

SQLOperat::~SQLOperat() {
}

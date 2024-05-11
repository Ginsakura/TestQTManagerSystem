#pragma once
#include <qstring.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qlist.h>
#include <qdebug.h>
#include "functions.h"

#define qout qDebug().noquote().nospace()

class SQLOperat
{
public:
	SQLOperat(QSqlDatabase);
	SQLOperat();
	~SQLOperat();
	QSqlQuery SelectAll(QString);
	QSqlQuery Select(QString, QString, QString);
	QSqlQuery Select(QString, QString);
	bool Insert(QString, QString, QString);
	bool Insert(QString, QString);
	bool InsertRoomStatu(QString, QString, QString, QString, QString, QString, QString, QString, QString);
	bool Update(QString, QString, QString, QString);

private:
	QSqlDatabase DB;
	QSqlQuery cursor;
	QSqlQuery tempCur;
};

class RoomStatu
{
public:
	RoomStatu() {}
	~RoomStatu() {}
	int roomNumber = 0;
	bool reservation = false;
	QString reservationDate = "";
	bool checkIn = false;
	QString checkInDate = "";
	QString checkEndTime = "";
	int peopleNumber = 0;
	QString remark = "";
	bool save() {
		if (roomNumber == 0) {
			qout << QFgColor(0xff, 0, 0) << "roomNumber not exists" << QResetColor();
			return false;
		}
		else {
			sqlo = QString("%1,%2,\"%3\",%4,\"%5\",\"%6\",%7,\"%8\"").arg(roomNumber)
				.arg(reservation).arg(reservationDate).arg(checkIn).arg(checkInDate)
				.arg(checkEndTime).arg(peopleNumber).arg(remark);
			sql.Insert("RoomStatu", sqlo);
			return true;
		}
	}

private:
	SQLOperat sql;
	QString sqlo;
};

class Room {
public:
	Room() {}
	~Room() {}
	int roomNumber = 0;
	int price = 0;
	int vip = 0;
	bool save() {
		if (roomNumber == 0 || price == 0 || vip == 0) {
			qout << QFgColor(0xff, 0, 0) << "roomNumber/price/vip has not exists" << QResetColor();
			return false;
		}
		else {
			sqlo = QString("%1,%2,%3").arg(roomNumber).arg(price).arg(vip);
			sql.Insert("Room", sqlo);
			return true;
		}
	}
private:
	SQLOperat sql;
	QString sqlo;
};

class Roomer {
public:
	Roomer() {}
	~Roomer() {}
	QString recordTime = "";
	QString name = "";
	QString personID = "";
	QString phone = "";
	bool gender = false;
	int roomNumber = 0;
	bool useVIP = false;
	int state = 0;
	bool save() {
		if (recordTime == "") {
			qout << QFgColor(0xff, 0, 0) << "recordTime not exists" << QResetColor();
			return false;
		}
		else {
			sqlo = QString("\"%1\",\"%2\",\"%3\",\"%4\",%5,%6,%7,%8").arg(recordTime).arg(name)
				.arg(personID).arg(phone).arg(gender).arg(roomNumber).arg(useVIP).arg(state);
			sql.Insert("Roomer", sqlo);
			return true;
		}
	}
private:
	SQLOperat sql;
	QString sqlo;
};

//class User {
//public:
//	User();
//	~User();
//	bool save() {
//
//	}
//private:
//	SQLOperat sql;
//	QString sqlo;
//};

class Event {
public:
	Event() {}
	~Event() {}
	QString recordTime = "";
	int roomNumber = 0;
	QString event = "";
	int state = 0;
	bool save() {
		if (roomNumber == 0) {
			qout << QFgColor(0xff, 0, 0) << "roomNumber not exists" << QResetColor();
			return false;
		}
		else {
			sqlo = QString("\"%1\",%2,\"%3\",%4").arg(recordTime).arg(roomNumber).arg(event).arg(state);
			sql.Insert("Event", sqlo);
			return true;
		}
	}
private:
	SQLOperat sql;
	QString sqlo;
};
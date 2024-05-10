#pragma once
#include <qstring.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qsqlerror.h>
#include <qlist.h>
#include <qdebug.h>

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
	RoomStatu();
	~RoomStatu();
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
			//qout <<;
		}
		sqlo = QString("%1,%2,\"%3\",%4,\"%5\",\"%6\",%7,\"%8\"").arg(roomNumber)
			.arg(reservation).arg(reservationDate).arg(checkIn).arg(checkInDate)
			.arg(checkEndTime).arg(peopleNumber).arg(remark);
		sql.Insert("RoomStatu", sqlo);
	}

private:
	SQLOperat sql;
	QString sqlo;
};
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
	~SQLOperat();
	QListData* getAll(QString);

private:
	const QSqlDatabase DB;
	QSqlQuery cursor;
};

SQLOperat::SQLOperat(QSqlDatabase db) :DB(db) {
	cursor = QSqlQuery(DB);
}
QListData* SQLOperat::getAll(QString table) {
	cursor.prepare(QString("SELECT * from %1").arg(table));
	if (!cursor.exec()) {
		qout << QFgColor(0xff, 0, 0) << "select error: " << QResetColor() << cursor.lastError();
	}
}

SQLOperat::~SQLOperat() {
}
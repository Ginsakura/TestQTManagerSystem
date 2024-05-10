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
	bool Update(QString, QString, QString, QString);

private:
	QSqlDatabase DB;
	QSqlQuery cursor;
};
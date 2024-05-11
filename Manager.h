#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Manager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <qtabwidget.h>
#include <QDateTime>
#include <QCheckBox>
#include <QComboBox>
#include "sql.h"
class Manager : public QMainWindow
{
    Q_OBJECT

public:
    Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
    //void on_pushButton_5_clicked();

    void on_yuyuePageBtn_clicked();

    void on_dengjiPageBtn_clicked();

    void on_tuifangPageBtn_clicked();

    void on_eventPageBtn_clicked();

    void on_dengjiBtn_clicked();

    void on_yuyueBtn_clicked();

private:
    Ui::ManagerClass ui;
    SQLOperat sql;
    QSqlQuery query;
    void UpdateRoomStatus();

};

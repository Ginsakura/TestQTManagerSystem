#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Manager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include "sql.h"

class Manager : public QMainWindow
{
    Q_OBJECT

public:
    Manager(QWidget *parent = nullptr);
    ~Manager();

private slots:
    //void on_pushButton_5_clicked();

    void on_appoin_button_clicked();

    void on_register_button_clicked();

    void on_check_out_clicked();

    void on_event_clicked();

    void on_room_infor_clicked();

private:
    Ui::ManagerClass ui;
    SQLOperat sql;


};

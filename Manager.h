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
#include <QSpinBox>
#include "sql.h"

class Manager : public QMainWindow
{
    Q_OBJECT

public:
    Manager(QWidget *parent = nullptr);
    Manager(bool, QWidget* parent = nullptr);
    ~Manager();
    bool isAdmin = false;

private slots:
    void on_yuyuePageBtn_clicked();

    void on_dengjiPageBtn_clicked();

    void on_tuifangPageBtn_clicked();

    void on_eventPageBtn_clicked();

    void on_dengjiBtn_clicked();

    void on_yuyueBtn_clicked();

    void on_incident_view_clicked();

    void on_event_insert_clicked();

    void on_event_update_clicked();

private:
    Ui::ManagerClass ui;
    SQLOperat sql;
    QSqlQuery query;
    void UpdateRoomStatus();
    QMessageBox Mybox;

};

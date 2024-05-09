#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Manager.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
class Manager : public QMainWindow
{
    Q_OBJECT

public:
    Manager(QWidget *parent = nullptr);
    ~Manager();

private:
    Ui::ManagerClass ui;
    QSqlDatabase db;
    QSqlQuery query;

};

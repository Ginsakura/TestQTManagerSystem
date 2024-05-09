#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Manager.h"

class Manager : public QMainWindow
{
    Q_OBJECT

public:
    Manager(QWidget *parent = nullptr);
    ~Manager();

private:
    Ui::ManagerClass ui;
};

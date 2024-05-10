#pragma once

#include <QWidget>
#include <Manager.h>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace Ui {
class LOGIN;
}
class Signin;
class LOGIN : public QWidget
{
    Q_OBJECT

public:
    explicit LOGIN(QWidget *parent = nullptr);
    ~LOGIN();

private slots:
    void on_login_clicked();

private:
    Ui::LOGIN *ui;
    SQLOperat sql;
    Signin * sign_page = NULL;
};

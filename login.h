#pragma once

#include <QWidget>
#include <Manager.h>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class LOGIN;
}

class LOGIN : public QWidget
{
    Q_OBJECT

public:
    explicit LOGIN(QWidget *parent = nullptr);
    ~LOGIN();
signals:
    void login_success();
private slots:
    void on_login_clicked();

private:
    Ui::LOGIN *ui;
    SQLOperat sql;
    Manager *page2 = NULL;
};

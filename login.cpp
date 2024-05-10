#include "login.h"
#include "ui_login.h"
#include "sql.h"

LOGIN::LOGIN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LOGIN)
{
    ui->setupUi(this);

    //query.exec("insert into user(Username,Password,Vip) values(123456,'password',1)");
    //query.exec("insert into user(Username,Password,Vip) values(987654,'password',0)");
    //query.exec("insert into user(Username,Password,Vip) values(552252,'password')");
}

LOGIN::~LOGIN()
{
    delete ui;
}

void LOGIN::on_login_clicked()
{
    Manager* m = new Manager;
    m->show();
    close();
}




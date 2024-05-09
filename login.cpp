#include "login.h"
#include "ui_login.h"

LOGIN::LOGIN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LOGIN)
{
    ui->setupUi(this);
}

LOGIN::~LOGIN()
{
    delete ui;
}

void LOGIN::on_login_clicked()
{
    Manager *m=new Manager;
    m->show();
    close();
}

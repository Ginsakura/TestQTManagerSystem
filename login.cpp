#include "login.h"
#include "ui_login.h"
#include "sql.h"

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
{   //登录

    QString where = QString("UserName = '%0' and Password = '%1'").arg(ui->username_edit->text()).arg(ui->password_edit->text());
    QSqlQuery query = sql.Select("User", "Permission", where);

    if (query.next()) {
        emit login_success();
        this->page2 = new Manager(query.value(0).toBool());//实例化manager主页界面
        this->close();
        this->page2->show();
        return;
    }
    else{
        QMessageBox::warning(nullptr, QString::fromLocal8Bit("登录失败"), QString::fromLocal8Bit("账户或密码错误"));    }
}




#include "login.h"
#include "ui_login.h"
#include "sql.h"

LOGIN::LOGIN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LOGIN)
{
    ui->setupUi(this);
    this->page2 = new Manager;

}

LOGIN::~LOGIN()
{
    delete ui;
}

void LOGIN::on_login_clicked()
{   //登录
    QString log_sql = QString("select * from User where Username = '%0' and Password = '%1'")
            .arg(ui->username_edit->text()).arg(ui->password_edit->text());
    QSqlQuery query;
    query.exec(log_sql);

    //账号密码正确，登录成功
    while (query.next()) {
        emit login_success();
        this->close();
        this->page2->show();
        return;
    }
    QString sql = QString("select * from User where Username = '%0'").arg(ui->username_edit->text());
    query.exec(sql);
    if (!query.next()) {
        // 如果查询结果为空，则提示用户账号不存在
        QMessageBox::warning(nullptr, "登陆失败", "账号不存在!");
    } else {
        // 如果查询结果不为空，则提示用户密码错误
        QMessageBox::warning(nullptr, "登录失败", "密码错误!");
    }


}




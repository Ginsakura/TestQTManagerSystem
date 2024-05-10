#ifndef LOGIN_H
#define LOGIN_H

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
    void comeBackToPrev();
    void on_sign1_clicked();

private:
    Ui::LOGIN *ui;
    QSqlQuery query;
    QSqlDatabase db;
    Signin * sign_page = NULL;
};

#endif // LOGIN_H

#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "Manager.h"
namespace Ui {
class LOGIN;
}

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
};

#endif // LOGIN_H

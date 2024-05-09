#include "Manager.h"

Manager::Manager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("Manager");
    db.setUserName("admin");
    db.setPassword("123456");
    bool sql_open=db.open();
    if(!sql_open){
        qDebug()<<"打开失败";
    }
    db.close();
}

Manager::~Manager()
{}

﻿#include "functions.h"
#include "Manager.h"
#include "login.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LOGIN l;
    l.show();
    return a.exec();
}

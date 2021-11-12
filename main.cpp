#include "mainwindow.h"
#include "employee.h"
#include <QApplication>
#include <iostream>
#include "changing_employee.h"



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
     w.show();
    return a.exec();
//    changing_employee e;
//    e.show();

//    e.exec();
//    return 0;
}

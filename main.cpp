#include "mainwindow.h"
#include "employee.h"
#include <QApplication>
#include <iostream>
#include "changing_employee.h"
#include <string>

#include <sstream>
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
     w.show();
    return a.exec();

}

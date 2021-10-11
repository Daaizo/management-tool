#include "mainwindow.h"
#include "employee.h"
#include <QApplication>
#include <iostream>

int Employee::how_many = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::cout << " how many " << Employee::how_many;
    return a.exec();
}

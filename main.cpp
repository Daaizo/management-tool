#include "mainwindow.h"
#include "employee.h"
#include <QApplication>
#include <iostream>



int main(int argc, char *argv[])
{

   QApplication a(argc, argv);
   MainWindow w;
   w.show();


   return a.exec();



 // return 0;
}

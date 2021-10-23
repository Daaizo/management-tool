#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet(" border-style: outset; border-radius: 5px;background: rgb(74,89,98);   color: white;  text-align: left; padding-left: 5px; border-bottom: 1px solid black;");
    this->setFixedSize(907,589);


}


MainWindow::~MainWindow()
{
    delete ui;
}

#include "adding_employee.h"
void MainWindow::on_pushButton_clicked()
{
    Adding_employee x;
    x.show();

    x.exec();
}

#include "showing_employee.h"
void MainWindow::on_pushButton_4_clicked()
{
    showing_employee x;

    x.show();
    x.exec();
}
#include "changing_employee.h"
void MainWindow::on_pushButton_2_clicked()
{
    changing_employee x;
    x.show();
    x.exec();
}

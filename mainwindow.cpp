#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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


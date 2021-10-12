#include "showing_employee.h"


showing_employee::showing_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showing_employee)
{
    ui->setupUi(this);
    this->setStyleSheet("background: rgb(74,89,98);    border-radius: 0px; text-align: left; padding-left: 5px; border-bottom: 1px solid black; color: white");

}

showing_employee::~showing_employee()
{
    delete ui;
}

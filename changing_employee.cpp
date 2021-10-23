#include "changing_employee.h"
#include "ui_changing_employee.h"

changing_employee::changing_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changing_employee)
{
    ui->setupUi(this);
}

changing_employee::~changing_employee()
{
    delete ui;
}

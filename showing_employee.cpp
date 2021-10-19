#include "showing_employee.h"
#include "employee.h"
#include <QString>
showing_employee::showing_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showing_employee)
{
    ui->setupUi(this);
    this->setStyleSheet("background: rgb(74,89,98);    border-radius: 0px; text-align: left; padding-left: 5px; border-bottom: 1px solid black; color: white");

    Employee::count_employees();
    Employee *tab_of_employees = new Employee[Employee::how_many];
    tab_of_employees->load_employee(tab_of_employees);
    QString temp ;
    for(int i = 0 ; i < Employee::how_many; i++)
    {
         temp =temp + "\n" + QString::fromStdString(tab_of_employees[i].name);
        ui->name->setText(temp );
    }


}

showing_employee::~showing_employee()
{

    delete ui;
}


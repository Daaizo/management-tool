#include "showing_employee.h"
#include "employee.h"
#include <QString>
#include <QtCore>

showing_employee::showing_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showing_employee)
{
    ui->setupUi(this);

    this->setStyleSheet("background: rgb(74,89,98);   text-align: left; padding-left: 5px;   color: white");
    Employee::count_employees();
    Employee *tab_of_employees = new Employee[Employee::how_many];

    tab_of_employees->load_employee(tab_of_employees);
    QString name = "NAME:\n",ln = "LAST NAME:\n",a = "AGE:\n" ,j="JOB:\n";
    if(Employee::how_many)
    {
        for(int i = 0 ; i < Employee::how_many; i++)
        {
             name +=QString::fromStdString(tab_of_employees[i].name)+ "\n\n";
             ln += QString::fromStdString(tab_of_employees[i].last_name)+ "\n\n";
             a += QString::fromStdString(tab_of_employees[i].age)+ "\n\n";
             j += QString::fromStdString(tab_of_employees[i].job)+ " \n\n";

        }
        ui->name->setText(name );
        ui->name->setFixedHeight(Employee::how_many * 61);

        ui->last_name->setText(ln);
        ui->last_name->setFixedHeight(Employee::how_many * 61);

        ui->age->setText(a);
        ui->age->setFixedHeight(Employee::how_many * 61);
        ui->job->setText(j);
         ui->job->setFixedHeight(Employee::how_many * 61);

    }
    else  ui->name->setText("Currently there are no employees in data base");



}

showing_employee::~showing_employee()
{

    delete ui;
}


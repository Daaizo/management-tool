#include "showing_employee.h"
#include "employee.h"
#include <QString>
#include <QtCore>

showing_employee::showing_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showing_employee)
{

    ui->setupUi(this);

    this->setStyleSheet(" border: 2px solid blue;border-radius: 8px;padding: 5px;font-family: Garamond, serif;border-style: outset; background: rgb(44, 171, 255);   color: white;  text-align: left; padding-left: 5px; ");
    //this->setStyleSheet("background: rgb(74,89,98);   text-align: left; padding-left: 5px;   color: white");
    Employee::count_employees();
    Employee *tab_of_employees = new Employee[Employee::how_many];

    tab_of_employees->load_employee(tab_of_employees);

    QString id = "ID:\n\n", name = "NAME:\n\n",ln = "LAST NAME:\n\n",a = "AGE:\n\n" ,j="JOB:\n\n";
    if(Employee::how_many)
    {
        for(int i = 0 ; i < Employee::how_many; i++)
        {
             id += QString::number(i)+ "\n\n" ;
             name +=QString::fromStdString(tab_of_employees[i].name)+ "\n\n";
             ln += QString::fromStdString(tab_of_employees[i].last_name)+ "\n\n";
             a += QString::fromStdString(tab_of_employees[i].age)+ "\n\n";
             j += QString::fromStdString(tab_of_employees[i].job)+ "\n\n";

        }
            ui->id->setText(id);
            ui->name->setText(name);
            ui->last_name->setText(ln);
            ui->age->setText(a);
            ui->job->setText(j);
            ui->job->setFixedWidth(340);
    }
    else
    {
        msg.setWindowTitle("INFORMATION");
        msg.information(nullptr, "Information", "Data base is empty");
    }


}


showing_employee::~showing_employee()
{
    delete ui;
}


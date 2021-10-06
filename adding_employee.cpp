#include "adding_employee.h"
#include "ui_adding_employee.h"


Adding_employee::Adding_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adding_employee)
{
    ui->setupUi(this);
    ui->Job->addItem("Scheduler" );
    ui->Job->addItem("Customer service representative" );
    ui->Job->addItem("Accounts payable clerk" );
    ui->Job->addItem("Office manager" );
    ui->Job->addItem("CAD technician" );
    ui->Age->setValidator( new QIntValidator(0, 99, this) );

}
void Adding_employee::show_Error_msg()
{
    msg.critical(nullptr, "Error" ,"Fill all blanks before saving");
}
Adding_employee::~Adding_employee()
{
    delete ui;
}

void Adding_employee::on_Clear_clicked()
{
    ui->Age->clear();
    ui->Name->clear();
    ui->Last_name->clear();
}

#include <iostream>
#include "employee.h"
#include <string>
using namespace std;
void Adding_employee::on_Save_clicked()
{
   // Employee *list = new Employee ;
    QString n, ln, a ,j;
    j = ui->Job->currentText();
    n = ui->Name->toPlainText();
    ln = ui->Last_name->toPlainText();
    a = ui->Age->text();
   // int age = a.toInt();
    if(!n.isEmpty() && !ln.isEmpty() && !a.isEmpty() && !j.isEmpty())
    {
        cout << "\nname : " << n.toUtf8().constData();
        cout << "\nlast name : " << ln.toUtf8().constData();
        cout << "\nage : " << a.toUtf8().constData();
        cout << "\njob : " << j.toUtf8().constData();
        //list[Employee::how_many].add_employee(n.toUtf8().constData(),ln.toUtf8().constData() , j.toUtf8().constData(), age);
        close();
    }
    else
    {
       show_Error_msg();
    }


}

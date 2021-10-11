#include "adding_employee.h"
#include "ui_adding_employee.h"


Adding_employee::Adding_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adding_employee)
{
    ui->setupUi(this);
    this->setStyleSheet("background: rgb(74,89,98);    border-radius: 0px; text-align: left; padding-left: 5px; border-bottom: 1px solid black; color: white");
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
#include <fstream>
using namespace std;
void Adding_employee::on_Save_clicked()
{
    ofstream outdata;
    QString n, ln, a ,j;
    j = ui->Job->currentText();
    n = ui->Name->toPlainText();
    ln = ui->Last_name->toPlainText();
    a = ui->Age->text();
    if(!n.isEmpty() && !ln.isEmpty() && !a.isEmpty() && !j.isEmpty())
    {
        cout << "\nname : " << n.toUtf8().constData();
        cout << "\nlast name : " << ln.toUtf8().constData();
        cout << "\nage : " << a.toUtf8().constData();
        cout << "\njob : " << j.toUtf8().constData();
        outdata.open("data_base.txt",ios::app);
        if(!outdata)
        {
            cout << " some error occured !";
        }
        else
        {
            outdata << n.toUtf8().constData() << ";";
            outdata << ln.toUtf8().constData() << ";";
            outdata << a.toUtf8().constData() << ";";
            outdata << j.toUtf8().constData() << ";" << endl;
            outdata.close();
        }
        close();
    }
    else
    {
       show_Error_msg();
    }
}

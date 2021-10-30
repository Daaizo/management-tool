#include "changing_employee.h"
#include "ui_changing_employee.h"
#include "employee.h"
#include <string>
#include <fstream>
changing_employee::changing_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changing_employee)
{
    ui->setupUi(this);
    Employee::count_employees();
    tab_of_employees = new Employee[Employee::how_many];
    tab_of_employees->load_employee(tab_of_employees);
    msg.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);


}

changing_employee::~changing_employee()
{
    delete ui;
}

void changing_employee::on_search_button_clicked()
{

    ui->name->clear();
    ui->last_name->clear();
    ui->age->clear();
    ui->job->clear();
    QString id = ui->search->toPlainText();
    int x = id.toInt() ;
    if(Employee::how_many)
    {
       if(x < 0 ||  x> Employee::how_many)
       {
           msg.critical(nullptr, "Error", "there is no matching id in data base, try again");
       }
       else
       {
           ui->name->setText(QString::fromStdString(tab_of_employees[x].name));
           ui->last_name->setText(QString::fromStdString(tab_of_employees[x].last_name));
           ui->age->setText(QString::fromStdString(tab_of_employees[x].age));
           ui->job->setText(QString::fromStdString(tab_of_employees[x].job));

       }

    }
    else
    {
       msg.information(nullptr, "Information", "Data base is empty");
    }





}

void changing_employee::on_save_button_clicked()
{
    msg.setText("The data has been modified");
    msg.setInformativeText("Do you want to save your changes?");
    msg.icon();
    msg.standardButtons();
    QString id = ui->search->toPlainText();
    int x = id.toInt();
    cout << x << "from save";
    QString n,ln,a,j;
    ofstream outdata;
    n = ui->name->toPlainText();
    ln = ui->last_name->toPlainText();
    a = ui->age->toPlainText();
    j = ui->job->toPlainText();

    tab_of_employees[x].name =  n.toStdString() ;
    tab_of_employees[x].last_name = ln.toStdString();
    tab_of_employees[x].age = a.toStdString();
    tab_of_employees[x].job = j.toStdString();

    if(!n.isEmpty() && !ln.isEmpty() && !a.isEmpty() && !j.isEmpty())
    {

        outdata.open("data_base.txt",ios::trunc);
        if(!outdata)
        {
            msg.critical(nullptr, "ERROR", "there was an error with data base");
        }
        else
        {
            for(int i =0 ; i < Employee::how_many; i++)
            {
                outdata << tab_of_employees[i].name << ";";
                outdata << tab_of_employees[i].last_name << ";";
                outdata << tab_of_employees[i].age << ";";
                outdata << tab_of_employees[i].job << ";";
            }
            outdata.close();
            msg.setWindowTitle("INFORMATION");
            msg.information(nullptr, "Information", "data succesfully changed");
            close();

        }
    }
    else
    {
       msg.setWindowTitle("ERROR");
       msg.critical(nullptr, "Error" ,"Fill all blanks before saving");

    }


}

void changing_employee::on_delete_all_button_clicked()
{

    msg.setText("Are you sure");
    msg.setWindowTitle("deleting all employess");
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
    msg.setDefaultButton(QMessageBox::No);
    int choice = msg.exec();
}

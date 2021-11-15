#include "changing_employee.h"
#include "ui_changing_employee.h"
#include "employee.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
changing_employee::changing_employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changing_employee)
{
     this->setStyleSheet("border: 1px solid blue;border-radius: 3px;border-style: outset;background: rgb(44, 171, 255);    border-radius: 3px; text-align: left; padding-left: 5px; border-bottom: 1px solid black; color: white");
    //this->setFixedSize(500,400);
    //this->setStyleSheet(" border: 2px solid blue;border-radius: 8px;padding: 5px;font-family: Garamond, serif;border-style: outset; background: rgb(44, 171, 255);   color: white;  text-align: left; padding-left: 5px; ");
    this->setFixedSize(609,391);
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
    if(!id.toStdString().empty())
    {
        int x = id.toInt() ;
        if(Employee::how_many)
        {
           if(x < 0 ||  x>= Employee::how_many)
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

}

void changing_employee::on_save_button_clicked()
{

    QString id = ui->search->toPlainText();

    int x = id.toInt();

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

    if(!n.isEmpty() && !ln.isEmpty() && !a.isEmpty() && !j.isEmpty()  )
    {
        outdata.open("data_base.txt",ios::trunc);
        if(!outdata)
        {
            msg.critical(nullptr, "ERROR", "there was an error with data base");
            close();
        }
        else
        {
            for(int i =0 ; i < Employee::how_many; i++)
            {


                deleteSpaces(tab_of_employees[i].name);
                deleteSpaces(tab_of_employees[i].last_name);
                deleteSpaces(tab_of_employees[i].age);
                deleteSpaces(tab_of_employees[i].job);
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
    switch (choice)
    {
        case  QMessageBox::Yes:
        {
            remove("data_base.txt");
            msg.setWindowTitle("INFORMATION");
            msg.information(nullptr, "Information", "data base succesfully deleted");
            close();
            break;

        }
        case  QMessageBox::No:
        {
            break;
        }
    }
}

void changing_employee::on_delete_button_clicked()
{
    msg.setText("Are you sure");
    msg.setWindowTitle("deleting employee");
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
    msg.setDefaultButton(QMessageBox::No);
    int choice = msg.exec();
    switch (choice)
    {
        case  QMessageBox::Yes:
        {
            QString id = ui->search->toPlainText();
            int x = id.toInt();
            if(!id.toStdString().empty())
            {
            ifstream data;
            ofstream outdata;
            stringstream buff;
            int found =0,count = 0;;
            if(Employee::how_many == 1 && x == 0)
            {
                outdata.open("data_base.txt");
                close();
                break;
            }

            data.open("data_base.txt",ios::out);
            if(!data)
            {
                std::cout << " ERROR" ;
            }
            else
            {
                buff << data.rdbuf(); // all data in buff
                data.close();
            }
            string temp,a = buff.str();
            if(a.empty())
            {
                msg.information(nullptr, "Information", "data base is empty");
                break;
            }
            while(count != x*4)
            {
                  found = a.find(';',found + 1);
                  count++;

            }
            temp = a.substr(0,found);
            for(unsigned int i = 0; i < 4;i++)
            {
                found = a.find(';',found + 1);
            }
            temp += a.substr(found);
            outdata.open("data_base.txt",ios::out);
            if(!data)
            {
                std::cout << " ERROR" ;
            }
            else
            {
                if(x == 0) outdata << a.substr(found+1);
                else  outdata << temp;

               outdata.close();
            }

            msg.setWindowTitle("INFORMATION");
            msg.information(nullptr, "Information", "employee deleted");
            close();
            break;

            }
        }
        case  QMessageBox::No:
        {
            break;
        }
    }
}
void changing_employee::deleteSpaces(string &a)
{

    int frontCounter = -1, backCounter = 1 ;
    for(unsigned int i = 0; i < a.size();i++)
    {
        if(isspace(a[0]))
        {
            while(isspace(a[i]))
            {

                i++;
                frontCounter++;
            }
            if(frontCounter != -1)
            {
                a = a.substr(frontCounter + 1 );
            }
        }
        while(isspace(a[i]))
        {
            backCounter++;
            i++;
        }
        if(backCounter >= 2 && i != a.size())
        {
            string temp = a.substr(0,i - backCounter);
            a = temp + " "+ a.substr(i);
            backCounter = 0;
        }
        else if(backCounter >= 1 && i >= a.size())
        {
            a = a.substr(0,i - backCounter);
            backCounter =0 ;
        }
        else backCounter = 0;
      }


}

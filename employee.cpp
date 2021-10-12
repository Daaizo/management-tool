#include "employee.h"
#include <sstream>
#include <fstream>

int Employee::how_many = 0;

Employee::Employee()
{

    cout<<"\nrecord successfully created\n";
}
void Employee::add_employee(string n, string l,string j, int a)
{
    this->age = a;
    this->job = j;
    this->last_name = l;
    this->name = n;

}

void Employee::show_employee(Employee *tab_of_emp)
{

}

Employee* Employee::load_employee()
{
    ifstream data;
    stringstream buff;
    cout << " A ";
    data.open("data_base.txt");
    if(!data)
    {
        std::cout << " ERROR" ;
    }
    else
    {
        buff << data.rdbuf(); // all data in buff
        data.close();
    }


    //return this;
}

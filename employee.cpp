#include "employee.h"


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
    how_many++;
}

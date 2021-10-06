#include "employee.h"
//int Employee::how_many = 0;
Employee::Employee()
{
   // how_many++;
    cout<<"\nrecord successfully created\n";
}
void Employee::add_employee(string n, string l,string j, int a)
{
    name =  n;
    last_name = l;
    age = a;
    job = j;

}

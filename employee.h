#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;
class Employee
{
public:
    static int how_many ;
    int age;
    string name;
    string last_name;
    string job;
    void add_employee(string, string ,string , int);
    ~Employee();
    Employee();
    static void show_employee(Employee *);
    Employee* load_employee();

};

#endif // EMPLOYEE_H


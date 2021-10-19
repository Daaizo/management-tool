#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;
class Employee
{


    public:
        static int how_many ;
        static void count_employees();
        void show_employee(Employee *);
        ~Employee();
        Employee();
        void load_employee(Employee *&);
        void add_employee(string, string ,string , int);
        string age;
        string name;
        string last_name;
        string job;



};

#endif // EMPLOYEE_H


#include "employee.h"
#include <sstream>
#include <fstream>
#include <string>

int Employee::how_many = 0;

Employee::Employee()
{
}

Employee::~Employee()
{
    delete this;
}


void Employee::add_employee(string n, string l,string j, int a)
{
    this->age = a;
    this->job = j;
    this->last_name = l;
    this->name = n;

}
void Employee::count_employees()
{
    string line;
    ifstream data;
    stringstream buff, temp;
     data.open("data_base.txt",ios::out);
    if(!data)
    {
        std::cout << " ERROR" ;
    }
    else
    {
        temp << data.rdbuf(); // all data in buff
        data.close();
    }
    int line_count=0;

    while(getline(temp, line, ';'))
    {
        line_count++;
    }
    Employee::how_many = line_count/4;

}

void Employee::load_employee(Employee* &tab)
{
    ifstream data;
    stringstream buff;
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

   // cout << "czy buff dziala " << buff.str();
    int temp = 0, temp2 = 0;
    string var;
    for(auto i : buff.str())
    {
        if(i == ';')
        {
            temp++;
            switch(temp)
            {
                case 1:
                {
                    tab[temp2].name = var; 
                    break;
                }
                case 2:
                {
                    tab[temp2].last_name = var;
                    break;
                }
                case 3:
                {
                    tab[temp2].age = var;
                    break;
                }
                case 4:
                {
                    tab[temp2].job = var;
                    temp = 0;
                    temp2++;
                    break;
                }
            }
            var = " ";
        }
        else var += i;
    }
}




















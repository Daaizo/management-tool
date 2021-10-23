#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
class Person
{
public:
    int age;
    std::string name;
    std::string last_name;
    static int how_many;
    ~Person();
    Person();
};
int Person::how_many = 0;
#endif // PERSON_H

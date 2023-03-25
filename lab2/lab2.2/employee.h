#pragma once
#include "date.h"
class Employee 
{
private:
    string lastName;
    string firstName;
    Date birthDate;
    Date hireDate;

public:
    Employee(string lastName, string firstName, Date birthDate, Date hireDate);
    ~Employee();
    void display();
};

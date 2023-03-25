#include "employee.h"
Employee::Employee(string lastName, string firstName, Date birthDate, Date hireDate)
{
    this->lastName=lastName;
    this->firstName=firstName;
    this->birthDate = birthDate;
    this->hireDate = hireDate;
}
Employee::~Employee() 
{
}
void Employee::display()
{
    cout << firstName << " " << lastName << "," << endl;
    birthDate.display();
    cout << endl;
    hireDate.display();
    cout << endl;
}
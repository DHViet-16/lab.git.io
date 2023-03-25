#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 1990;
    }
    Date(int month, int day, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    ~Date()
    {
    }
    void setDay(int day)
    {
        this->day = day;
    }
    int getDay()
    {
        return day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    int getMonth()
    {
        return month;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    int getYear()
    {
        return year;
    }
    void display()
    {
        cout << day << "/" << month << "/" << year;
    }
    bool ktra_date()
    {
        if (year > 0)
        {
            if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            {
                if (month > 0 && month < 13)
                {
                    if (month == 2)
                    {
                        if (day > 0 && day < 30)
                        {
                            return true;
                        }
                        return false;
                    }
                    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                    {
                        if (day > 0 && day < 32)
                        {
                            return true;
                        }
                        return false;
                    }
                    if (month == 4 || month == 6 || month == 9 || month == 11)
                    {
                        if (day > 0 && day < 31)
                        {
                            return true;
                        }
                        return false;
                    }
                }
                return false;
            }
            else
            {
                if (month > 0 && month < 13)
                {
                    if (month == 2)
                    {
                        if (day > 0 && day < 29)
                        {
                            return true;
                        }
                        return false;
                    }
                    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                    {
                        if (day > 0 && day < 32)
                        {
                            return true;
                        }
                        return false;
                    }
                    if (month == 4 || month == 6 || month == 9 || month == 11)
                    {
                        if (day > 0 && day < 31)
                        {
                            return true;
                        }
                        return false;
                    }
                }
            }
        }
        return false;
        /* if (year <= 0) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            if (day < 1 || day > 29) {
                return false;
            }
        } else {
            if (day < 1 || day > 28) {
                return false;
            }
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1 || day > 30) {
            return false;
        }
    } else {
        if (day < 1 || day > 31) {
            return false;
        }
    }
    return true;
    */
    }
};

class Employee : public Date
{
private:
    string lastname;
    string firstname;
    Date birthdate;
    Date hiredate;

public:
    Employee()
    {
    }
    Employee(string lastname, string firstname, Date birthdate, Date hiredate)
    {
        this->lastname = lastname;
        this->firstname = firstname;
        this->birthdate = birthdate;
        this->hiredate = hiredate;
    }
    ~Employee() {}
    void display()
    {
        cout << firstname << " " << lastname << "," << endl;
        birthdate.display() ;
        cout << endl;
        hiredate.display() ;
        cout<< endl;
    }
};
int main()
{
    Date birth(7, 24, 1949);
    Date hire(3, 12, 1988);
    Employee manager("Bob", "Blue", birth, hire);
    cout << endl;
    manager.display();
    cout << "\nTest Date constructor with invalid values:\n";
    Date lastDayOff(14, 35, 1994); // invalid month and day
    if (!lastDayOff.ktra_date())
        cout << "Invalid" << endl;
    cout << endl;
    return 0;
}

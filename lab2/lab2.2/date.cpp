#include "date.h"
Date::Date()
{
    day = 1;
    month = 1;
    year = 1990;
}
Date::Date(int month, int day, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
Date:: ~Date()
{
}
void Date::display()
{
    cout << day << "/" << month << "/" << year;
}
bool Date::ktr_date()
{
    if (year <= 0)
    {
        return false;
    }
    if (month < 1 || month > 12)
    {
        return false;
    }
    if (month == 2)
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            if (day < 1 || day > 29)
            {
                return false;
            }
        }
        else
        {
            if (day < 1 || day > 28)
            {
                return false;
            }
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 1 || day > 30)
        {
            return false;
        }
    }
    else
    {
        if (day < 1 || day > 31)
        {
            return false;
        }
    }
    return true;
}

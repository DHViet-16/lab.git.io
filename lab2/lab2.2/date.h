#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int month, int day, int year);
    ~Date();
    void display();
    bool ktr_date();
};
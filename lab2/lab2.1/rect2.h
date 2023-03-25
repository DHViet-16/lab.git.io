// Khai báo hàm
#pragma once
#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
class Rectangle
{
private:
    double len;
    double wid;
    static int thisMany;
    char *fillString;
public:
    Rectangle();                                         
    Rectangle(double len, double wid, const char*fillString); 
    ~Rectangle();
    // các setter và getter
    void setLength(double len);
    double getLength() const;
    void setWidth(double wid);
    double getWidth() const;
    double getPerimeter() const; 
    double getDiagonal() const;  
    double getArea() const;      
    void display() const;      
    bool isSquare();       
    void draw(char x);     
    static int howMany();
    char *fill() const;
};

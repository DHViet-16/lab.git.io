#pragma once
#include<iostream>
using namespace std;

class Rational{
private:
    int numerator;
    int denominator;
    Rational reduce();
public:
    Rational();
    Rational(int numerator, int denominator);
    Rational(const Rational &other);
    ~Rational();
    int gCD(int , int );
    friend Rational operator+(Rational a, Rational b);
    friend Rational operator-(Rational a, Rational b);
    friend Rational operator*(Rational a, Rational b);
    friend Rational operator/(Rational a, Rational b);
    friend bool operator==(Rational a, Rational b);
    friend bool operator!=(Rational a, Rational b);
    friend bool operator>(Rational a, Rational b);
    friend bool operator<(Rational a, Rational b);
    friend Rational operator+(Rational a, int b);
    friend Rational operator+(int a, Rational b);
    friend ostream &operator<<(ostream &output, Rational a);
    friend istream &operator>>(istream &input, Rational &a);
};
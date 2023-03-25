#include "Rational.h"

Rational Rational::reduce()
{
    int gcd = gCD(numerator, denominator);
    numerator = numerator / gcd;
    denominator = denominator / gcd;
    return Rational(numerator, denominator);
}
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}
Rational::Rational(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}
Rational ::Rational(const Rational &other)
{
    numerator = other.numerator;
    denominator = other.denominator;
}
Rational::~Rational() {}
int Rational::gCD(int a, int b)
{
    int r;
    while (a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}
Rational operator+(Rational a, Rational b)
{
    a = a.reduce();
    b = b.reduce();
    Rational res(a.numerator * b.denominator + a.denominator * b.numerator, a.denominator * b.denominator);
    return res;
}
Rational operator-(Rational a, Rational b)
{
    a = a.reduce();
    b = b.reduce();
    Rational res(a.numerator * b.denominator - a.denominator * b.numerator, a.denominator * b.denominator);
    return res;
}
Rational operator*(Rational a, Rational b)
{
    a = a.reduce();
    b = b.reduce();
    Rational res(a.numerator * b.numerator, a.denominator * b.denominator);
    return res;
}
Rational operator/(Rational a, Rational b)
{
    a = a.reduce();
    b = b.reduce();
    Rational res(a.numerator * b.denominator, a.denominator * b.numerator);
    return res;
}
bool operator==(Rational a, Rational b)
{
    return (a.numerator * b.denominator == a.denominator * b.numerator);
}
bool operator!=(Rational a, Rational b)
{
    return !(a == b);
}
bool operator>(Rational a, Rational b)
{
    return a.numerator * b.denominator > a.denominator * b.numerator;
}
bool operator<(Rational a, Rational b)
{
    return a.numerator * b.denominator < a.denominator * b.numerator;
}
Rational operator+(Rational a, int b)
{
    a = a.reduce();
    Rational res(a.numerator + a.denominator * b, a.denominator);
    return res;
}
Rational operator+(int a, Rational b)
{
    return b + a;
}
ostream &operator<<(ostream &output, Rational a)
{
    if (a.denominator == 0)
    {
        output << "Invalid";
    }
    else
    {
        a = a.reduce();
        if (a.denominator == 1)
        {
            output << a.numerator << endl;
        }
        else
        {
            output << a.numerator << "/" << a.denominator <<" \n";
        }
    }
    return output;
}
istream &operator>>(istream &input, Rational &a)
{
    cout << "Numerator: ";
    input >> a.numerator;
    cout << "Denominator: ";
    input >> a.denominator;
    return input;
}

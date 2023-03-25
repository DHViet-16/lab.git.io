#include <iostream>
using namespace std;

int gCD(int a, int b)
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
class Rational
{
private:
    int numerator;
    int denominator;
    Rational reduce()
    {
        int UCLN = gCD(numerator, denominator);
        numerator = numerator / UCLN;
        denominator = denominator / UCLN;
        return Rational(numerator, denominator);
    }

public:
    Rational()
    {
        numerator = 0;
        denominator = 1;
    }
    Rational(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            this->numerator = 1;
            this->denominator = 0;
        }
        else
        {
            this->numerator = numerator;
            this->denominator = denominator;
        }
    }
    void operator=(const Rational &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    ~Rational() {}
    friend Rational operator+(Rational a, Rational b)
    {
        a = a.reduce();
        b = b.reduce();
        Rational res(a.numerator * b.denominator + a.denominator * b.numerator, a.denominator * b.denominator);
        res = res.reduce();
        return res;
    }
    friend Rational operator-(Rational a, Rational b)
    {
        a = a.reduce();
        b = b.reduce();
        Rational res(a.numerator * b.denominator - a.denominator * b.numerator, a.denominator * b.denominator);
        res = res.reduce();
        return res;
    }
    friend Rational operator*(Rational a, Rational b)
    {
        a = a.reduce();
        b = b.reduce();
        Rational res(a.numerator * b.numerator, a.denominator * b.denominator);
        res = res.reduce();
        return res;
    }
    friend Rational operator/(Rational a, Rational b)
    {
        a = a.reduce();
        b = b.reduce();
        Rational res(a.numerator * b.denominator, a.denominator * b.numerator);
        res = res.reduce();
        return res;
    }
    friend bool operator==(Rational a, Rational b)
    {
        return (a.numerator * b.denominator == a.denominator * b.numerator);
    }
    friend bool operator!=(Rational a, Rational b)
    {
        return !(a == b);
    }
    friend bool operator>(Rational a, Rational b)
    {
        return a.numerator * b.denominator > a.denominator * b.numerator;
    }
    friend bool operator<(Rational a, Rational b)
    {
        return a.numerator * b.denominator < a.denominator * b.numerator;
    }
    friend Rational operator+(Rational a, double b)
    {
        a = a.reduce();
        Rational res(a.numerator + a.denominator * b, a.denominator);
        res = res.reduce();
        return res;
    }
    friend Rational operator+(double a, Rational b)
    {
        return b + a;
    }
    friend ostream &operator<<(ostream &output, Rational a)
    {
        if (a.denominator == 1)
        {
            output << a.numerator << endl;
        }
        else
        {
            if (a.denominator == 0)
            {
                output << -1;
            }
            else
            {
                output << a.numerator << "/" << a.denominator << "\n";
            }
        }
        return output;
    }
    friend istream &operator>>(istream &input, Rational &a)
    {
        cout << "Numerator: ";
        input >> a.numerator;
        cout << "Denominator: ";
        input >> a.denominator;
        if (a.denominator == 0)
        {
            cout << "Invalid,denominator other 0!";
        }
        return input;
    }
};

int main()
{
    Rational a(2, 5);
    Rational b(8, 5);
    Rational c(2, 1);
    Rational d(c);
    Rational e;
    Rational i;
    cout << "the first rational (A) should be 2/5 : " << a << endl;
    cout << "the second rational (B) should be 8/5 : " << b << endl;
    cout << "the third rational (C) should be 2 : " << c << endl;
    cout << "the fourth rational (D) should be like (c) = 2 : " << d << endl;
    cout << "the fifth rational (E) should be 0 : " << e << endl;
    cout << "=======================" << endl;
    cout << "enter I = " << endl;
    cin >> i;
    cout << i << endl;
    cout << " Arithmathics operations " << endl;
    cout << "=====================" << endl;
    cout << a << "+" << b << "=" << a + b << endl;
    cout << c << "-" << b << "=" << c - b << endl;
    cout << b << "-" << c << "=" << b - c << endl;
    cout << c << "*" << b << "=" << c * b << endl;
    cout << b << "/" << a << "=" << b / a << endl;
    cout << "=====================" << endl;
    cout << " Logical operations " << endl;
cout << " ===================== " << endl;
cout <<a<<">"<<b<<"should be false: " << (a>b) << endl;
cout << a<<"<"<<b<<"should be True: " << (a<b) << endl;
cout << a<<"=="<<b<<"should be false: " << (a==b) << endl;
cout << a<<"!="<<b<<" should be True: " << (a!=b) << endl;
cout << c<<"=="<<d<<" should be True: " << (c==d) << endl;
cout << " ============================== " << endl;
    cout << " Arithmathics operations " << endl;
    cout << " ============================== " << endl;
    cout << a << "+ 2 =" << a + 2 << endl;
    cout << " 2 + " << a << "=" << 2 + a << endl;
    cout << " ===============================" << endl;
    cout << "\n\nDivision by Zero" << endl;
    cout << " ============================== " << endl;
    cout << "Rational g(3,0): ";
    Rational g(3, 0);
    cout << g << endl;
    Rational h(0, 1);
    cout << "Divide by zero - a/h should not give abnormal exit:" << a / h << endl;
    cout << " ============================== " << endl;
    cout << "Good Luck" << endl;
    return 0;
}
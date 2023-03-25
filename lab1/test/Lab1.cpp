#include <iostream>
#include <math.h>
using namespace std;

class Rectangle
{
private:
    double len;
    double wid;

public:
    Rectangle()
    {
        len = 10;
        wid = 10;
    }
    Rectangle(double len, double wid)
    {
        if (len < 0 || len > 20 || wid < 0 || wid > 20)
        {
            cout << "Length and width must be between 0 and 20" << endl;
        }
        this->len = len;
        this->wid = wid;
    }
    void setLength(double len)
    {
        this->len = len;
    }
    double getLength()
    {
        return len;
    }
    void setWidth(double wid)
    {
        this->wid = wid;
    }
    double getWidth()
    {
        return wid = wid;
    }
    double getPerimeter()
    {
        return (len + wid) * 2;
    }
    double getDiagonal()
    {
        return sqrt(pow(len, 2) + pow(wid, 2));
    }
    double getArea()
    {
        return len * wid;
    }
    void display()
    {
        if (len < 0 || wid < 0)
            cout << "Invalid Length" << endl;
        else
            cout << "[" << len << "x" << wid << "]" << endl;
    }
    void isSquare()
    {
        if (getLength() == getWidth())
            cout << "a square" << endl;
        else
            cout << "not" << endl;
    }
    void draw()
    {
        for (int i = 0; i < getWidth(); i++)
        {
            for (int j = 0; j < getLength(); j++)
            {
                cout << " * ";
            }
            cout << endl;
        }
    }
};
int main(void)
{
    Rectangle a;         // test rectangle -- default constructor
    Rectangle b(12, 20); // parameterized constructor
    Rectangle c(-5, 15); // invalid length
    cout << "Rectangle A = ";
    a.display();
    cout << endl;
    cout << "Rectangle B = ";
    b.display();
    cout << endl;
    cout << "Rectangle C = ";
    c.display();
    cout << endl
         << endl;

    int newLen, newWid; // input vars for update
    cout << "Enter new length and width for rectangle A: ";
    cin >> newLen >> newWid;
    a.setLength(newLen);
    a.setWidth(newWid);
    cout << "New rectangle A: ";
    a.display();
    cout << endl;
    cout << "Perimeter = " << a.getPerimeter() << endl;
    cout << "Diagonal = " << a.getDiagonal() << endl;
    cout << "Area = " << a.getArea() << endl;
    cout << "Rectangle A is ";
    a.isSquare();
    cout << "Rectangle A:" << endl;
    a.draw();
    cout << endl;
    return 0;
}

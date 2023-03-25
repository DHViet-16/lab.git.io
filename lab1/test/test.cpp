#include <iostream>
#include <math.h>
#include<string.h>
using namespace std;

class Rectangle
{
private:
    double len;
    double wid;
    static int thisMany;
    char *fillstring;

public:
    Rectangle()
    {
        len = 10;
        wid = 10;
        fillstring=NULL;
    }
    Rectangle(double len, double wid, string fs)
    {
        if (len >= 0 && len <= 20)
        {
            this->len = len;
        }
        else
        {
            this->len = 10;
        }
        if (wid >= 0 && wid <= 20)
        {
            this->wid = wid;
        }
        else
        {
            this->wid = 10;
        }
        fillstring= &fs[0];
        thisMany++;
    }
    ~Rectangle()
    {
        delete[] fillstring;
        thisMany--;
    }
    void setLength(double len)
    {
        if (len >= 0 && len <= 20)
        {
            this->len = len;
        }
    }
    double getLength() const
    {
        return len;
    }
    void setWidth(double wid)
    {
        if (wid >= 0 && wid <= 20)
        {
            this->wid = wid;
        }
    }
    double getWidth() const
    {
        return wid;
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
        cout << "[" << len << "x" << wid << "]" << fill()<<endl;
    }
    bool isSquare()
    {
        if (getLength() == getWidth())
            return true;
        return false;
    }
    void draw(char x)
    {
        for (int i = 0; i < getWidth(); i++)
        {
            for (int j = 0; j < getLength(); j++)
            {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
    static int howMany()
    {
        return thisMany;
    }
    char *fill()
    {
        return fillstring;
    }
};

int main()
{
    Rectangle a;         // test rectangle -- default constructor
    Rectangle b(12, 20,"B"); // parameterized constructor
    Rectangle c(-5, 15,"C"); // invalid length
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
     if (!a.isSquare())
         cout << "not ";
     cout << "a square." << endl
          << endl;
     cout << "Rectangle A:" << endl;
     a.draw('*');
     cout << endl;
    return 0;
}

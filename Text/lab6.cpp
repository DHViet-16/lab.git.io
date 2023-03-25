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
    char *fillstring;

public:
    Rectangle() // là phương thức khởi tạo không tham số.
    {
        len = 10;
        wid = 10;
        fillstring = NULL;
        thisMany++;
    }
    Rectangle(double len, double wid, const char *fillstring) // là phương thức khởi tạo có tham số dùng để khởi tạo giá trị cho thuộc tính length và width
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
        if (fillstring != NULL)
        {
            this->fillstring = new char[strlen(fillstring) + 1];
            strcpy(this->fillstring, fillstring);
        }
        thisMany++;
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
    double getPerimeter() const // là phương thức trả về chu vi hình chữ nhật.
    {
        return (len + wid) * 2;
    }
    double getDiagonal() const // là phương thức trả về đường chéo hình chữ nhật.
    {
        return sqrt(pow(len, 2) + pow(wid, 2));
    }
    double getArea() const // là phương thức trả về diện tích hình chữ nhật.
    {
        return len * wid;
    }
    void display() const
    {
        cout << "[" << len << "x" << wid << "]"
             << " " << endl;
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
    char *fill() const
    {
        return fillstring;
    }
    ~Rectangle()
    {
        delete[] fillstring;
        thisMany--;
    }
};
int Rectangle::thisMany = 0;
int main()
{
    cout << "Starting # of Rectangles: " << Rectangle::howMany()
         << endl
         << endl;
    Rectangle a;
    cout << "Rectangle A = ";
    a.display();
    cout << endl
         << "Now this many Rectangles: " << a.howMany();
    cout << endl
         << endl;
    Rectangle b(12, 20, "Rectangle B");
    cout << "Rectangle B = ";
    b.display();
    cout << endl
         << "Now this many Rectangles: " << b.howMany();
    cout << endl
         << endl;
    { // block to test destructor
        const Rectangle c(-5, 15, "Rectangle C");
        cout << "Rectangle C = ";
        c.display();
        cout << endl
             << "Now this many Rectangles: " << c.howMany();
        // testing const functions and new fill function
        cout << endl
             << "Perimeter of Rectangle C is: " << c.getPerimeter();
        cout << endl
             << "Fill string of Rectangle C is: " << c.fill();
        cout << endl
             << endl;
    }
    // should be one less now, since block exited
    cout << "After exiting block, this many Rectangles: " << Rectangle::howMany() << endl
         << endl;
    return 0;
}

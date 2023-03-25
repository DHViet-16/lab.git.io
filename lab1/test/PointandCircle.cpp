#include <iostream>
using namespace std;

class Point
{
public:
   int x, y;
    Point()
    {
        cout << "Constructor of Point class is called " << endl;
        x = 0;
        y = 0;
    }

    Point(int x, int y)
    {
        cout << "Constructor of Point class is called " << endl;
        this->x = x;
        this->y = y;
    }

    ~Point()
    {
        cout << "Destructor of Point class is called  " << endl;
    }
    void display()
    {
        cout << "[" << x << ", " << y << "]" << endl;
    }
};

class Circle : public Point
{
private:
    int radius;

public:
    Circle()
    {
        cout << "Constructor of Circle class is called " << endl;
        radius = 0;
    }

    Circle(int x, int y, int radius) : Point(x, y)
    {
        cout << "Constructor of Circle class is called " << endl;
        this->radius = radius;
    }

    ~Circle()
    {
        cout << "Destructor of Circle class is called " << endl;
    }

    void display()
    {
        cout << "Center of circle: [" << x << "," << y << "]" << endl;
        cout << "Radius of circle: " << radius << endl;
    }
};

int main()
{
    Point p1;
    Circle c(3, 4, 0);
    p1.display();
    c.display();
    return 0;
}
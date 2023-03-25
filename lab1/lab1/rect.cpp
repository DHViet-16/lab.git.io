//viết hàm
#include "rect.h"
#include <math.h>
using namespace std;

Rectangle::Rectangle() // là phương thức khởi tạo không tham số.
{
    len = 10;
    wid = 10;
}
Rectangle::Rectangle(double len, double wid)//là phương thức khởi tạo có tham số dùng để khởi tạo giá trị cho thuộc tính length và width
{
    if (len >= 0 && len <= 20)
    {
        this->len = len;
    }
    else
    {
        this->len = 10;
    }

        this->wid = wid;

}
void Rectangle::setLength(double len)
{
    if (len >= 0 && len <= 20)
    {
        this->len = len;
    }
}
double Rectangle::getLength()
{
    return len;
}
void Rectangle::setWidth(double wid)
{
    if (wid >= 0 && wid <= 20)
    {
        this->wid = wid;
    }
}
double Rectangle::getWidth()
{
    return wid = wid;
}
double Rectangle::getPerimeter()//là phương thức trả về chu vi hình chữ nhật.
{
    return (len + wid) * 2;
}
double Rectangle::getDiagonal()//là phương thức trả về đường chéo hình chữ nhật.
{
    return sqrt(pow(len, 2) + pow(wid, 2));
}
double Rectangle::getArea()//là phương thức trả về diện tích hình chữ nhật.
{
    return len * wid;
}
void Rectangle::display()
{
        cout << "[" << len << "x" << wid << "]" << endl;
}
bool Rectangle::isSquare()
{
    if (getLength() == getWidth())
        return true;
    return false;
}
void Rectangle::draw(char x)
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
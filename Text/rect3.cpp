#include "rect3.h"
Rectangle::Rectangle() // là phương thức khởi tạo không tham số.
{
    len = 10;
    wid = 10;
    fillstring = NULL;
    thisMany++;
}
Rectangle::Rectangle(double len, double wid, const char *fillstring) // là phương thức khởi tạo có tham số dùng để khởi tạo giá trị cho thuộc tính length và width
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
Rectangle::~Rectangle()
{
    delete[] fillstring;
    thisMany--;
}

void Rectangle::setLength(double len)
{
    if (len >= 0 && len <= 20)
    {
        this->len = len;
    }
}
double Rectangle:: getLength() const
{
    return len;
}
void Rectangle:: setWidth(double wid)
{
    if (wid >= 0 && wid <= 20)
    {
        this->wid = wid;
    }
}
double Rectangle:: getWidth() const
{
    return wid;
}
double Rectangle:: getPerimeter() const // là phương thức trả về chu vi hình chữ nhật.
{
    return (len + wid) * 2;
}
double Rectangle:: getDiagonal() const // là phương thức trả về đường chéo hình chữ nhật.
{
    return sqrt(pow(len, 2) + pow(wid, 2));
}
double Rectangle:: getArea() const // là phương thức trả về diện tích hình chữ nhật.
{
    return len * wid;
}
void Rectangle:: display() const
{
    cout << "[" << len << "x" << wid << "]"
         << " " << endl;
}
bool Rectangle:: isSquare()
{
    if (getLength() == getWidth())
        return true;
    return false;
}
void Rectangle:: draw(char x)
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
int Rectangle:: howMany()
{
    return thisMany;
}
char *Rectangle::fill() const
{
    return fillstring;
}
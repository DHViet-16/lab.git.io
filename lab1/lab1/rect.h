//Khai báo hàm
#pragma once
#include <iostream>
using namespace std;
class Rectangle
{
private:
        double len;
        double wid;
public:
    Rectangle();// là phương thức khởi tạo không tham số.
    Rectangle(double len, double wid);//là phương thức khởi tạo có tham số dùng để khởi tạo giá trị cho thuộc tính length và width
    //các setter và getter
    void setLength(double len);
    double getLength();
    void setWidth(double wid);
    double getWidth();
    double getPerimeter();//là phương thức trả về chu vi hình chữ nhật.
    double getDiagonal();//là phương thức trả về đường chéo hình chữ nhật.
    double getArea();//là phương thức trả về diện tích hình chữ nhật.
    void display();// là phương thức dùng để hiển thị thông tin về hình chữ nhật
    bool isSquare();//là phương thức dùng để kiểm tra hình vuông
    void draw(char x);//là phương thức dùng để vẻ hình chữ nhật
};
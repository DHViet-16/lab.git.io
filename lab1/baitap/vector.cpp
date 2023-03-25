/*#include <iostream>
using namespace std;

class Vector
{
private:
    int n;
    float *v;

public:
    Vector(int size)
    {
        int i = 0;
        n = size;
        v = new float[n];
    }
    int getN(){
        return n;
    }
    void add(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "v[" << i << "] : ";
            cin >> v[i];
        }
    }
    ~Vector()
    {
        delete v;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
    }
};
int main()
{
    int n;
    cout << "Nhap so phan tu cua vector a: ";
    cin >> n;
    Vector a(n);
    cout << "Nhap vector a: \n";
    a.add(n);
    cout << "\nNhap so phan tu cua vector b: ";
    cin >> n;
    Vector b(n);
    cout << "Nhap vector b: \n";
    b.add(n);
    cout << "vector a: ";
    a.display();
    cout << "\nvector b: ";
    b.display();
    return 0;
}*/
#include <iostream>
#include <vector>

using namespace std;

class Vector
{
private:
    vector<double> data; // khởi tạo vector data kiEeu thực
    int n;

public:
    Vector(int n)
    {
        this->n = n;
        data.resize(n);
    }
    void setN()
    {
        this->n = n;
    }
    int getN()
    {
        return n;
    }
    void getVector()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Vector[" << i << "]:";
            cin >> data[i];
        }
    }
    ~Vector()
    {
        // Destructor
    }

    void Display() const
    {
        for (int i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Vector v(3);
    v.getVector();
    v.Display();

    return 0;
}
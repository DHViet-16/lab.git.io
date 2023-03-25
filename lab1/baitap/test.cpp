#include <iostream>
#include <vector>

using namespace std;
class Vector
{
private:
    double a[100];
    int n;

public:
    Vector() {}
    Vector(int n)
    {
        this->n = n;
    }
    void setN(int n)
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
            cin >> a[i];
        }
    }
    ~Vector()
    {
        // Destructor
    }

    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    friend Vector multiply(const Vector &v, const class Matrix &m); // Câu lệnh này sử dụng từ khóa "class" trước Matrix để xác định rằng Matrix là một lớp được định nghĩa trước đó, và phải được khai báo trước khi được sử dụng trong hàm.
};

class Matrix
{
private:
    double b[100][100];
    int rows, cols;

public:
    Matrix() {}
    Matrix(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
    }
    void setRows(int rows)
    {
        this->rows = rows;
    }
    void setCols(int cols)
    {
        this->cols = cols;
    }
    int getRows()
    {
        return rows;
    }
    int getCols()
    {
        return cols;
    }
    void getMatrix()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Matrix[" << i << j << "]:";
                cin >> b[i][j];
            }
        }
    }
    void Display() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
    friend Vector multiply(const Vector &v, const Matrix &m);
    ~Matrix()
    {
        // Destructor
    }
};

Vector multiply(const Vector &v, const Matrix &m)
{
    double c[100][100];
    for (int j = 0; j < m.cols; j++)
    {
        double sum = 0;
        for (int i = 0; i < m.rows; i++)
        {
            sum += v.a[i] * m.b[i][j];
        }
        c[j][0] = sum;
    }
    for (int j = 0; j < m.cols; j++)
    {
        cout << c[j][0] << "  ";
    }
    return 0;
}
int main()
{
    Vector v;
    Matrix m;
    int n, rows, cols;
    cout << "Enter the length of the vector: ";
    cin >> n;
    v.setN(n);
    v.getVector();
    v.Display();
    cout << endl;
    cout << "Enter rows and cols for Matrix: ";
    cin >> rows >> cols;
    m.setRows(rows);
    m.setCols(cols);
    Matrix(rows, cols);
    m.getMatrix();
    m.Display();
    if (n != rows)
    {
        cout << "Invalid";
    }
    else
    {
        cout << "Multiply: ";
        Vector vm = multiply(v, m);
    }
    return 0;
}

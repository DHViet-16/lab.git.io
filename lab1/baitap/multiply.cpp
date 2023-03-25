#include <iostream>
#include <vector>

using namespace std;
class Vector
{
private:
    vector<double> data; // khởi tạo vector data kiểu thực
    int n;

public:
    Vector() {}
    Vector(int n)
    {
        this->n = n;
        data.resize(n);
    }
    void setSize(int n)
    {
        this->n = n;
    }
    int getSize()
    {
        return n;
    }
    void getVector()
    {
        data.resize(n);
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
    friend Vector multiply(const Vector &v, const class Matrix &m); // Câu lệnh này sử dụng từ khóa "class" trước Matrix để xác định rằng Matrix là một lớp được định nghĩa trước đó, và phải được khai báo trước khi được sử dụng trong hàm.
};

class Matrix
{
private:
    vector<vector<double>> data;
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
        data.resize(rows, vector<double>(cols));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "Matrix[" << i << j << "]:";
                cin >> data[i][j];
            }
        }
    }
    ~Matrix()
    {
        // Destructor
    }

    void Display() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    friend Vector multiply(const Vector &v, const Matrix &m);
};

Vector multiply(const Vector &v, const Matrix &m)
{
    Vector result(m.cols);
    for (int j = 0; j < m.cols; j++)
    {
        double sum = 0;
        for (int i = 0; i < m.rows; i++)
        {
            sum += v.data[i] * m.data[i][j];
        }
        result.data[j] = sum;
    }
    return result;
}
int main()
{
    Vector v;
    Matrix m;
    int n, rows, cols;
    cout << "Enter the length of the vector: ";
    cin >> n;
    v.setSize(n);
    v.getVector();
    v.Display();
    cout << endl;
    cout << "Enter rows and cols for Matrix: ";
    cin >> rows >> cols;
    m.setRows(rows);
    m.setCols(cols);
    m.getMatrix();
    m.Display();
    if (n != rows)
    {
        cout <<"Invalid";
    }
    else
    {
        Vector vm = multiply(v, m);
        cout << "Multiply: ";
        vm.Display();
    }
    return 0;
}

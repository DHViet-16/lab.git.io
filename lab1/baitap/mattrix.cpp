/*#include <iostream>
using namespace std;

class Matrix
{
private:
    int m, n;
    float **a;

public:
    Matrix()
    {
        {
            int i, j;
            cout << "Nhap so hang : ";
            cin >> n;
            cout << "Nhap so cot : ";
            cin >> m;
            a = new float *[n];
            for (i = 0; i < n; i++)
                a[i] = new float[m];
            for (i = 0; i < n; i++)
                for (j = 0; j < m; j++)
                {
                    cout << "a[" << i << j << "] : ";
                    cin >> a[i][j];
                }
        }
    }
    Matrix(int size1, int size2)
    {
        int i, j;
        n = size1;
        m = size2;
        a = new float *[n];
        for (i = 0; i < n; i++)
            a[i] = new float[m];
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                cout << "a[" << i << j << "] : ";
                cin >> a[i][j];
            }
    }
    ~Matrix()
    {

        int i;
        for (i = 0; i < n; i++)
            delete a[i];
        delete a;
    }
    int ktra(Matrix &a)
    {
        if ((n == a.n) && (m == a.m))
            return 1;
        return 0;
    }
    void display()
    {
        int i, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
                cout << a[i][j] << " ";
            cout << "\n";
        }
    }
};
int main()
{
    cout << ("Nhap ma tran A:\n");
    Matrix a;
    cout << ("Nhap ma tran B:\n");
    Matrix b;
    a.display();
    cout << endl;
    b.display();
    return 0;
}*/
#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
private:
    vector<vector<double>> data;
    int m, n;

public:
    Matrix(int m, int n)
    {
        this->m = m;
        this->n = n;
        data.resize(m,vector<double>(n));
    }
    void setM()
    {
        this->m = m;
    }
    void setN()
    {
        this->n = n;
    }
    int getM()
    {
        return m;
    }
    int getN()
    {
        return n;
    }
    void getMatrix()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
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
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix m(2, 3);
    m.getMatrix();
    m.Display();

    return 0;
}
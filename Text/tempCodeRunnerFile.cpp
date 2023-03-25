#include <cstdlib>
#include "rect3.h"
int main(void)
{
    Rectangle a;
    Rectangle b(12, 20, "Rectangle B");
    Rectangle c(-5, 15, "C");
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

    return 0;
}

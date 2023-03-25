//Demonstrating composition--an object with member objects.
#include <iostream>
#include "employee.h" // Employee class definition
int main()
{
        Date birth(7, 24, 1949);
        Date hire(3, 12, 1988);
        Employee manager("Bob", "Blue", birth, hire);
        cout << endl;
        manager.display();
        cout << "\nTest Date constructor with invalid values:\n";
        Date lastDayOff(14, 35, 1994); // invalid month and day
        if (!lastDayOff.ktr_date())
                cout << "Invalid" << endl;
        cout << endl;
        return 0;
} // end main
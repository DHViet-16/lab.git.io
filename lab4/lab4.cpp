#include <iostream>
using namespace std;

class Vehicle
{
public:
    string mfgName;
    int dealerCost;
    Vehicle(string mfgName, int dealerCost)
    {
        this->mfgName = mfgName;
        this->dealerCost = dealerCost;
    }
    ~Vehicle() {}
    int retailPrice()
    {
        return dealerCost + dealerCost * 0.2;
    }
    friend ostream &operator<<(ostream &output, Vehicle a)
    {
        output << "Ten nha san xuat: " << a.mfgName << endl;
        output << "Gia ban le: " << a.retailPrice() << endl;
        return output;
    }
};
class Car : public Vehicle
{
private:
    string modelName;
    bool sunroof;

public:
    Car(string mfgName, int dealerCost, string modelName, bool sunroof) : Vehicle(mfgName, dealerCost)
    {
        this->modelName = modelName;
        this->sunroof = sunroof;
    }
    ~Car() {}
    friend ostream &operator<<(ostream &output, Car a)
    {
        // output << static_cast<Vehicle &>(a);
        output << (Vehicle &)a;
        // Vehicle*t=&a;
        // output<<*t;
        output << "Ten kieu: " << a.modelName << endl;
        output << "Xe co cua hay khong? " << a.sunroof << endl;
        return output;
    }
};
class Truck : public Vehicle
{
private:
    double capacity;
    bool automaticTransmission;

public:
    Truck(string mfgName, int dealerCost, double capacity, bool automaticTransmission) : Vehicle(mfgName, dealerCost)
    {
        this->capacity = capacity;
        this->automaticTransmission = automaticTransmission;
    }
    ~Truck() {}
    friend ostream &operator<<(ostream &output, Truck a)
    {
        // output << static_cast<Vehicle &>(a);
        output << (Vehicle &)a;
        // Vehicle*t=&a;
        // output<<*t;
        output << "Suc chua cua xe: " << a.capacity << endl;
        output << "Xe co bo truyen luc tu dong hay khong? " << a.automaticTransmission << endl;
        return output;
    }
};
int main()
{
    Car c1("Ford", 10000, "Mustang", false),
        c2("Chevy", 15000, "Camaro", true);
    Truck t1("Ford", 12000, 1.5, true),
        t2("Dodge", 14000, 2.0, false);
    cout << "Dealer inventory:" << endl
         << endl;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << t1 << endl;
    cout << t2 << endl;
    return 0;
}
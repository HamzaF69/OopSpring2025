#include <iostream>
#include <string>
using namespace std;
class Vehicle
{
protected:
    string brand;
    int speed;

public:
    Vehicle(string brand, int speed) : brand(brand), speed(speed) {}
    void displayDetails()
    {
        cout << "brand: " << brand << endl;
        cout << "speed: " << speed << endl;
    }
};

class Car : public Vehicle
{
protected:
    int seats;

public:
    Car(string brand, int speed, int seats) : Vehicle(brand, speed), seats(seats) {}

    void displayDetails()
    {
        Vehicle::displayDetails();
        cout << "seats: " << seats << endl;
    }
};

class ElectricCar : public Car
{
    int batterylife;

public:
    ElectricCar(string brand, int speed, int seats, int bl) : Car(brand, speed, seats), batterylife(bl) {}

    void displayDetails()
    {
        Car::displayDetails();
        cout << "battery life: " << batterylife << endl;
    }
};

int main()
{
    ElectricCar e1("tesla", 250, 5, 24);
    e1.displayDetails();
}

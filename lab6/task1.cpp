#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
    string name;
    float salary;
    Employee(string name, float salary) : name(name), salary(salary) {}
    void displayDetails()
    {
        cout << "name: " << name << endl;
        cout << "salary: " << salary << endl;
    }
};
class Manager : public Employee
{
protected:
    float bonus;

public:
    Manager(string name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}
    void displayDetails()
    {
        Employee::displayDetails();
        cout << "bonus: " << bonus << endl;
    }
};
int main()
{
    Manager m1("hamza", 25000, 10000);
    m1.displayDetails();
}

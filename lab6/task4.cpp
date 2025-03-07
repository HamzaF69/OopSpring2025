#include <iostream>
#include <string>
using namespace std;
class Account{
    protected:
        int accountNumber;
        float balance;
    public:
        Account(int accountNumber,float balance): balance(balance),accountNumber(accountNumber){}
    void displayDetails(){
        cout<<"account number: "<<accountNumber<<endl;
        cout<<"balance: "<<balance<<endl;
    }
};
class SavingsAccount:public Account{
    protected:
    float interestRate;
    public:
    SavingsAccount(int accNum,float bal,float intRate):Account(accNum,bal),interestRate(intRate){}
    void displayDetails(){
        Account::displayDetails();
        cout<<"interest rate: "<<interestRate<<"%"<<endl;
    }
};
class CheckingAccount:public Account{
    protected:
    float overdraftLimit;
    public:
    CheckingAccount(int accNum,float bal,float odLimit):Account(accNum,bal),overdraftLimit(odLimit){}
    void displayDetails(){
        Account::displayDetails();
        cout<<"overdraft limit: "<<overdraftLimit<<endl;
    }
};
int main(){
    CheckingAccount c(2215200,56000.0,6000);
    SavingsAccount s(576,60000,2.5);
    c.displayDetails();
    s.displayDetails();
    return 0;
}

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <type_traits>
using namespace std;



class InsufficientFundsException:public exception{
    string mess;
    public:
    InsufficientFundsException(float amt){
        mess= "InsufficientFundsException - Deficit: ";
    }
    const char* what() const noexcept override{
        return mess.c_str();
    }
};

template<typename T>
class BankAccount{
    public:
    T amount;
    BankAccount(T amo):amount(amo){}
    void withdraw(T amt){
        if(amt>amount){
            throw InsufficientFundsException(amt-amount);
        }
    }
    
};

int main(){
    BankAccount b(500);
    try{
        b.withdraw(600);
       
    }
    catch(InsufficientFundsException e){
        cout<<e.what();
    }
}
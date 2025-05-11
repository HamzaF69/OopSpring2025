#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
using namespace std;

class InvalidValueException:public exception{
    public:
    const char* what() const noexcept override{
        return "InvalidValueException - age cannot be negative or over 120\n";
    }
};

int main (){
    int age;
    cout<<"enter age:";
    cin>>age;
    try{
        if(age<0||age>120){
            throw InvalidValueException();
        }
    }
    catch(const exception &e){
        cout<<"error: "<<e.what()<<endl;
    }
    return 0;
}


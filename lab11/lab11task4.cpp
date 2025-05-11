#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <type_traits>
using namespace std;

class NegativeNumberException:public exception{
    public:
    const char* what() const noexcept override {
        return "NegativeNumberException - number is less than zero\n";
    }

};

class InvalidTypeException:public exception{
    public:
    const char* what() const noexcept override {
        return "InvalidTypeException - value is not a number\n";
    }

};
template<typename T>
double sqrtVal(T num){
    if(!is_arithmetic<T>::value){
        throw InvalidTypeException();
    }

    if(num<0){
        throw NegativeNumberException();
    }
    return sqrt(static_cast<double>(num));
}

int main(){

    try {
        int m = 2;
        double result = sqrtVal(m);
        cout << "sqrt(" << m << ") = " << result << endl;
    }
    catch (const InvalidTypeException& e) {
        cout << "error: " << e.what() << endl;
    }
    catch (const NegativeNumberException& e) {
        cout << "error: " << e.what() << endl;
    }

    try {
        string s = "hello";
        double result = sqrtVal(s); // This will throw
        cout << "sqrt(\"" << s << "\") = " << result << endl;
    }
    catch (const exception& e) {
        cout << "error: " << e.what() << endl;
    }
}
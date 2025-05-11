#include <iostream>
#include <string>
#include <exception>
#include <cmath>
#include <type_traits>
using namespace std;
class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException - number is less than zero\n";
    }
};
class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException - value is not a number\n";
    }
};

template<typename T>
typename enable_if<is_arithmetic<T>::value, double>::type
sqrtVal(T num) {
    if (num < 0) {
        throw NegativeNumberException();
    }
    return sqrt(static_cast<double>(num));
}
template<typename T>
typename enable_if<!is_arithmetic<T>::value, double>::type
sqrtVal(T) {
    throw InvalidTypeException();
}

int main() {
    try {
        int m = 2;
        double result = sqrtVal(m);
        cout << "sqrt(" << m << ") = " << result << endl;
    }
    catch (const exception& e) {
        cout << "error: " << e.what();
    }

    try {
        string s = "hello";
        double result = sqrtVal(s);
        cout << "sqrt(\"" << s<<"\") = " << result << endl;
    }
    catch (const exception& e) {
        cout << "error: " << e.what();
    }
}

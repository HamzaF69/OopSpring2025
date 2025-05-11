#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <type_traits>
using namespace std;
class InsufficientFundsException : public exception{
    string mess;
    public:
    InsufficientFundsException(float deficit) {
        stringstream ss;
        ss << "InsufficientFundsException - Deficit: " << deficit;
        mess = ss.str();
    }

    const char* what() const noexcept override{
        return mess.c_str();
    }
};
template<typename T>
class BankAccount{
    static_assert(is_arithmetic<T>::value, "BankAccount requires a numeric type.");
    public:
    T amount;

    BankAccount(T amo):amount(amo) {}

    void withdraw(T amt) {
        if (amt > amount) {
            throw InsufficientFundsException(static_cast<float>(amt - amount));
        }
        amount -= amt;
        cout << "Withdrawn: " << amt << ", Remaining: " << amount << endl;
    }
};
int main() {
    BankAccount<float> b(500);
    try {
        b.withdraw(600);
    }
    catch (const InsufficientFundsException& e) {
        cout << "error: " << e.what() << endl;
    }
}

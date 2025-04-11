#include <iostream>
#include <string>
using namespace std;
class Currency{
    public:
    float f;
    Currency(float f):f(f){}
    Currency operator+(Currency c){
        return Currency(f+c.f);
    }
    Currency operator-(){
        return Currency(-f);

    }
    Currency operator-(Currency c){
        return Currency(f-c.f);
    }
    Currency& operator+=(const Currency& c) {
        f += c.f;
        return *this;
    }
    Currency& operator-=(const Currency& c) {
        f -= c.f;
        return *this;
    }


    friend ostream& operator<<(ostream& os,Currency c);

};
ostream& operator<<(ostream& os,Currency c){
    os<<c.f;
    return os;
}

int main() {
    Currency p1(19.99);
    Currency p2(5.49);
    Currency d(2.50);
    cout << "initial values:\n";
    cout << "P1: " << p1 << "\nP2: " << p2 << "\nD: " << d << "\n\n";
    Currency sum = p1 + p2;
    cout << "P1 + P2 = " << sum << endl;
    Currency diff = p1 - p2;
    cout << "P1 - P2 = " << diff << endl << endl;
    cout << "negative of P1: " << -p1 << endl;
    cout << "applying discount (-" << d << ")" << endl;
    p1 -= d;
    cout << "new P1: " << p1 << endl;
    p2 += d;
    cout << "P2 after adding discount: " << p2 << endl;
    sum = p1 + p2;
    cout << "\nfinal total: " << sum << endl;

    return 0;
}

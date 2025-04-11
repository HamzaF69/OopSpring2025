#include <iostream>
#include <string>
using namespace std;

class Fraction {
private:
    int num;
    int den;
public:
    Fraction(int n = 0, int d = 1) {
        num = n;
        den = d;
        
    }
    Fraction operator+( Fraction f){
        int n=num*f.den+f.num*den;
        int d=den*f.den;
        return Fraction(n, d);
    }

    Fraction operator-( Fraction f){
        int n=num*f.den-f.num *den;
        int d=den*f.den;
        return Fraction(n, d);
    }
    Fraction operator*(Fraction f){
        return Fraction(num*f.num,den*f.den);
    }

    Fraction operator/( Fraction f){
        return Fraction(num*f.den,den*f.num);
    }

    // Overload <<
    friend ostream& operator<<(ostream& os,  Fraction f){
        os << f.num << "/" << f.den;
        return os;
    }
};

int main() {
    Fraction f1(3, 4);
    Fraction f2(5, 6);
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl << endl;
    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    cout << "f1 / f2 = " << (f1 / f2) << endl;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
class Currency{
    protected:
    float amount;
    int currencyCode;
    string currencySymbol;
    float exchangeRate;
    Currency(float amount ,int code,string symbol,float exchange):amount(amount),currencyCode(code),currencySymbol(symbol),exchangeRate(exchange){}
    public:

        virtual double convertToBase() {
            return amount * exchangeRate; 
        }
       virtual float convertTo(Currency &target){
        double baseAmount = convertToBase();
        return baseAmount * target.exchangeRate;
       }
       virtual void displayCurrency(){
            cout<<"currency code: "<<currencyCode<<endl;
            cout<<"exchange rate: "<<exchangeRate<<"\nsymbol: "<<currencySymbol;
       }
};

class Dollar:public Currency{
    public:
    Dollar(double amt) : Currency(amt, 1122, "$", 1.0) {}

    void displayCurrency() override {
        cout << "$" << amount << " USD" << endl;
    }
};
class Euro:public Currency{
    public:
    Euro(double amt) : Currency(amt, 2211, "@", 0.9) {}

    void displayCurrency() override {
        cout << "@" << amount << " Euro" << endl;
    }
};

class Rupee:public Currency{
    public:
    Rupee(double amt) : Currency(amt, 1212, "R.", 270) {}

    void displayCurrency() override {
        cout << "R. " << amount << " Rupee" << endl;
    }
};
int main (){
    Dollar usd(100);
    Euro eur(0);
    Rupee pkr(0);

    cout << "Original Currencies:" << endl;
    usd.displayCurrency();

    cout << "\nConverting USD to EUR:" << endl;
    double eurAmount = usd.convertTo(eur);
    Euro convertedEuro(eurAmount);
    convertedEuro.displayCurrency();

    cout << "\nConverting USD to PKR:" << endl;
    double inrAmount = usd.convertTo(pkr);
    Rupee convertedRupee(inrAmount);
    convertedRupee.displayCurrency();
    return 0;
}

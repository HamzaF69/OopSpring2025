#include <iostream>
#include <string>
using namespace std;
class Car{
    int regNum;
    string model;
    string owner;
    public:
        Car (int regNum,string model,string owner){
            this->model=model;
            this->regNum=regNum;
            this->owner=owner;
            
            cout<<"registeration number is set to: "<<regNum<<endl;
            cout<<"model is set to: "<<model<<endl;
            cout<<"owner is set to: "<<owner<<endl;
        }
        Car(Car &c,string newOwn){
            regNum=c.regNum;
            model=c.model;
            owner=newOwn;
            cout<<"new owner is : "<<owner<<endl;
        }
        void displayDetails(){
            cout<<"registeration number is : "<<regNum<<endl;
            cout<<"model is : "<<model<<endl;
            cout<<"owner is : "<<owner<<endl;
        }
        ~Car(){}
};
int main (){
    Car c1(2211,"supra","hamza");
    Car c2(9090,"yaris","fuzail");
    Car c3(c1,"zaid");
    Car c4(c2,"hatim");
    c3.displayDetails();
    c4.displayDetails();
}

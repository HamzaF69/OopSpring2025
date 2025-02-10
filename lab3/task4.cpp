#include <iostream>
#include <string>
using namespace std;
class Laptop {
    public:
    string brand;
    string model;
    int processor, RAM,storage;
};
void compare(){
    Laptop b,a;
    int bpoints=0,apoints=0;
    cout<<"Bilal, enter details of your laptop\n";
    cout<<"enter brand: ";
    cin>>b.brand;
    cout<<"enter model: ";
    cin>>b.model;
    cout<<"enter processor (eg if its core i5 then enter 5): i";
    cin>>b.processor;
    cout<<"enter RAM: ";
    cin>>b.RAM;
    cout<<"enter storage: ";
    cin>>b.storage;

    cout<<"Ayesha, enter details of your laptop\n";
    cout<<"enter brand: ";
    cin>>a.brand;
    cout<<"enter model: ";
    cin>>a.model;
    cout<<"enter processor (eg if its core i5 then enter 5): i";
    cin>>a.processor;
    cout<<"enter RAM: ";
    cin>>a.RAM;
    cout<<"enter storage: ";
    cin>>a.storage;
    if (b.processor > a.processor) {
        bpoints++;
    } else if (a.processor > b.processor) {
        apoints++;
    }
    if (b.RAM > a.RAM) {
        bpoints++;
    } else if (a.RAM > b.RAM) {
        apoints++;
    }
    if (b.storage > a.storage) {
        bpoints++;
    } else if (a.storage > b.storage) {
        apoints++;
    }
    if (bpoints>apoints)
    {
        cout<<"bilal has the better laptop\n";
    } else if(apoints>bpoints){
        cout<<"ayesha has the better laptop\n";
    } else {
        cout<<"both bilal and ayesha have laptops that are equally good\n";
    }
}
int main (){
    Laptop l;
    cout<<"press 1 to turn on the pc...\n";
    int ch;
    cin>>ch;
    if (ch==1){
        int c;
        cout<<"press 2 to run a program to compare laptops...\n"; cin>>c;
        if (ch==2){
            compare();
        }
        int choice;
        while(1){
            cout<<"press 1 to continue\npress any key to exit\n";
            cin>>choice;
            if (choice==1){
                compare();
            } else {
                return 0;
            }
        }
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
class Battery{
    int mAh;
    public:
        Battery(){}
        Battery(int mAh){
            this->mAh=mAh;
        }
        int getMah(){
            return mAh;
        }
};
class Smartphone{
    int storage,ram;
    string model;
    Battery b;
    public:
        Smartphone(string model,int ram,int storage,int mAh){
            this->model=model;
            this->ram=ram;
            this->storage=storage;
            b=Battery(mAh);
        }
    void details(){
        cout<<"smartphone details\n";
        cout<<"model: "<<model<<endl;
        cout<<"Storage: "<<storage<<endl;
        cout<<"RAM: "<<ram<<endl;
        cout<<"Battery in mAh: "<<b.getMah()<<endl;
    }    
};
int main (){
    Smartphone s("12 pro",8,128,5000);
    s.details();
    return 0;
}

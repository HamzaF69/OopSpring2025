#include <iostream>
#include <string>
using namespace std;
class Device{
    protected:
    bool status;
    int deviceID;
    public:
    Device(int id,bool stat):status(status),deviceID(id){}
    void displayDetails(){
        cout<<"device id: "<<deviceID<<endl;
        cout<<"status: ";
        if(status){cout<<"enable"<<endl;}else{cout<<"disable"<<endl;}
    }
};
class SmartPhone:public Device{
    protected:
    float screenSize;
    public:
    SmartPhone(int id,bool stat,float size):screenSize(size),Device(id,stat){}
    void displayDetails(){
        Device::displayDetails();
        cout<<"screensize: "<<screenSize<<endl;
    }
};
class SmartWatch:public Device{
    protected:
    bool heartRateMonitor;
    public:
    SmartWatch(int id,bool stat,bool heartRate):heartRateMonitor(heartRate),Device(id,stat){}
    void displayDetails(){
        Device::displayDetails();
        cout<<"heart rate monitor: ";
        if(heartRateMonitor){cout<<"on"<<endl;}else{cout<<"off"<<endl;}
    }
};
class SmartWearable:public SmartPhone,public SmartWatch{
    protected:
    int stepCounter;
    public:
        SmartWearable(int id,bool stat,float size,bool heartRate,int stepC):SmartPhone(id,stat,size),SmartWatch(id,stat,heartRate),
        stepCounter(stepC){}
        void displayDetails(){
            SmartWatch::displayDetails();
            cout<<"screen size: "<<screenSize<<endl;
            cout<<"step counter: "<<stepCounter<<endl;
        }
};
int main(){
    SmartWearable s(2211,true,4.4,true,5500);
    s.displayDetails();
}

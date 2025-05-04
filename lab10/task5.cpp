#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main (){
    ifstream ipFile("vehicles.txt");
    string line;
    if(ipFile.is_open()){
        while(getline(ipFile,line)){
            istringstream  s(line);
            string type, id, name,year,data,cert;
            getline(s,type,',');
            getline(s,id,',');
            getline(s,name,',');
            getline(s,year,',');
            getline(s,data,',');
            getline(s,cert,',');
            if (type=="AutonomousCar"){
                size_t pos=data.find(':');
                if(pos!=string::npos){
                    string str=data.substr(pos+1);
                    float ver=stof(str);
                    cout<<"id: "<<id<<" version: "<<ver<<endl;
                }
            } else if(type=="ElectricVehicle"){
                size_t pos=data.find(':');
                if(pos!=string::npos){
                    string str=data.substr(pos+1);
                    float bat=stof(str);
                    cout<<"id: "<<id<<" battery: "<<bat<<endl;
                }
            } else if(type=="HybridTruck"){
                size_t cpos=data.find(":");
                size_t ppos=data.find("|");
                size_t bpos=data.rfind(":");
                if(bpos!=string::npos && ppos!=string::npos && cpos!=string::npos){
                    string strcargo = data.substr(cpos+1,ppos-cpos-2);
                    string strbattery = data.substr(bpos+1);
                    int cargo=stoi(strcargo);
                    int battery=stoi(strbattery);
                    cout<<"cargo: "<<cargo<<" battery: "<<battery<<endl;
                }
            }
        }
    }
}

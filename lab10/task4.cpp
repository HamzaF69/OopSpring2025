#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
int main(){
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
            }
            
        }
    }else{
        cout<<"couldnt open file\n";
    }
}

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
            int y=stoi(year);
            cout<<type<<endl;
            cout<<id<<endl;
            cout<<name<<endl;
            cout<<y<<endl;
            cout<<data<<endl;
            cout<<cert<<endl;
            cout<<endl;
            
        }
    }else{
        cout<<"couldnt open file\n";
    }
}

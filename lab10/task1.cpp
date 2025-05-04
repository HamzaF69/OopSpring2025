#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ifstream ipFile("vehicles.txt");
    string line;
    if(ipFile.is_open()){
        while(getline(ipFile,line)){
            cout<<line<<endl;
        }
    }else{
        cout<<"couldnt open file\n";
    }
}

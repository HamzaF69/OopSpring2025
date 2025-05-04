#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
int main (){
    ofstream oFile("sensor_log.txt");
    string line;
    oFile<<"Sensor 1: 25.5C\n";
    streampos p1= oFile.tellp();
    cout<<"current position: "<<p1<<endl;

    oFile<<"Sensor 2: 98.1 %RH\n";
    streampos p2= oFile.tellp();
    cout<<"more recent position: "<<p2<<endl;

}

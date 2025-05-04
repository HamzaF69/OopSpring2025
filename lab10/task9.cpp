#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main(){
    ifstream oFile("large_log.txt");
    char line[11];
    oFile.read(line,10);
    cout<<"first 10: "<<line<<endl;
    cout<<"position after first read: "<<oFile.tellg()<<endl;
    char nline[11];
    oFile.read(nline,10);
    cout<<"next 10: "<<nline<<endl;
    cout<<"new position: "<<oFile.tellg()<<endl;

}

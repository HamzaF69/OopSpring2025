#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
int main (){
    ifstream file("data_records.txt");
    file.seekg(20,ios::beg);
    string line;
    getline(file,line);
    cout<<"record: "<<line;
}

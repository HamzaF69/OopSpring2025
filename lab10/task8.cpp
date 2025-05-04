#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main (){
    ofstream ofile("config.txt");
    ofile<<"AAAAABBBBBCCCCC";
    ofile.close();
    fstream oFile("config.txt",ios::in|ios::out);
    oFile.seekp(5);
    oFile<<"XXXXX";
    oFile.close();

    ifstream rfile("config.txt");
    string line;
    getline(rfile,line);
    cout<<"updated content: "<<line;
}

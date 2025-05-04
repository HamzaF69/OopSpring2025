#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class InventoryItem{
    public:
    int itemID;
    char itemName[20];
};
int main (){
    InventoryItem i={2121,"choco cake"};
    ofstream oFile("inventory.dat",ios::binary);
    oFile.write((char*)&i,sizeof(i));
    oFile.close();

    InventoryItem i2;
    ifstream iFile("inventory.dat",ios::binary);
    iFile.read((char*)&i2,sizeof(i2));
    iFile.close();

    cout<<i2.itemID<<endl<<i2.itemName;
}

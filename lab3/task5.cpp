#include <iostream>
#include <string>
using namespace std;
class GroceryStore {
    private:
    string* items;
    float* price;
    int size;
    public:
        GroceryStore(int iniSize){
            size=iniSize;
            items = new string[size];
            price = new float[size];
            items[0]={"bread"};
            items[1]={"eggs"};
            items[2]={"milk"};
            items[3]={"butter"};
            price[0]={110.0};
            price[1]={180.0};
            price[2]={220.0};
            price[3]={150.0};
        }
    void add(string nItem,float nPrice){
        int nSize=size+1;
        string* tItems= new string[nSize]; 
        float* tPrice= new float[nSize];
        for (int i=0;i<size;i++){
            tItems[i]=items[i];
            tPrice[i]=price[i];
        }
        tItems[nSize-1]=nItem;
        tPrice[nSize-1]=nPrice;
        delete[] items;
        delete[] price;
        items=tItems;
        price=tPrice;
        size = nSize;
    }
    void update(string item,float nPrice){
        int ind=-1;
        for (int i = 0; i < size; i++)
        {
            if (item==items[i]){
                ind=i;
            }
        }
        if (ind>-1)
        {
            price[ind]=nPrice;
        } else{
            cout<<"item not found";
        }
    }
    void displayItems() {
        cout<<"Grocery Store Inventory:\n";
        for(int i = 0; i < size; i++) {
            cout<<items[i]<<" - Rs. " << price[i]<<endl;
        }
    }
    void generateReceipt() {
        int itemCount;
        cout << "How many items do you want to buy? ";
        cin >> itemCount;
        string selectedItems[itemCount];
        int quantities[itemCount];
        float totalCost = 0;
        for (int i = 0; i < itemCount; i++) {
            int choice;
            cout << "enter item number: ";
            cin >> choice;
            choice--; 
            if (choice < 0 || choice >= size) {
                cout << "Invalid selection, try again.\n";
                i--; 
                continue;
            }
            selectedItems[i] = items[choice];
            cout << "Enter quantity: ";
            cin >> quantities[i];

            totalCost += price[choice] * quantities[i];
        }
        cout << "        RECEIPT\n";
    cout << "Item           Qty    Price\n";
    cout << "-----------------------------\n";
    for (int i = 0; i < itemCount; i++) {
        int index = -1;
        for (int j = 0; j < size; j++) {
            if (selectedItems[i] == items[j]) {
                index = j;
                break;
            }
        }
        if (index != -1) {
            cout << selectedItems[i] << "       " << quantities[i] << "     Rs. " << (price[index] * quantities[i]) << endl;
        }
    }
    cout << "-----------------------------\n";
    cout << "Total:      Rs." << totalCost << endl;
    }

};
int main (){
    GroceryStore s(4);
    while (1)
    {
        int ch;
        int p;
        string i;
        cout<<"press 1 to add item\n";
        cout<<"press 2 to update item price\n";
        cout<<"press 3 to display inventory\n";
        cout<<"press 4 to generate receipt\n";
        cout<<"enter what you want to do:\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"enter new item's name: "<<endl;
            cin>>i;
            cout<<"enter price: "<<endl;
            cin>>p;
            s.add(i,p);
            break;
        case 2:
            cout<<"enter item you want to update the price of "<<endl;
            cin>>i;
            cout<<"enter new price: "<<endl;
            cin>>p;
            s.update(i,p);
            break;
        case 3:   
            s.displayItems(); 
            break;
        case 4:
            s.generateReceipt();
            break;
        case 5:
            cout<<"exiting...";
            break;    
        default:
            break;
        }
    }
    return 0;
}

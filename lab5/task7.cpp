#include <iostream>
#include <string>
using namespace std;
class Product{
    int id;
    float price;
    string name;
    public:
        Product(){}
        Product(string name,int id,float price){
            this->price=price;
            this->id=id;
            this->name=name;
        }
        string getname(){
            return name;
        }
        float getprice(){
            return price;
        }
        int getid(){
            return id;
        }
        void getInfo(){
            cout<<"Product: "<<name<<"\nID: "<<id<<"\nPrice: $"<<price;
        }
};
class Inventory{
    Product p[100];
    int count;
    string name;
    public:
        Inventory(string name){
            count=0;
            this->name=name;
        }
        void add(string name,int id, float price){
            p[count]=Product(name,id,price);
            count++;
        }
        void sort(){
            for (int i = 0; i < count-1; i++)
            {
                for (int j = 0; j < count-1-i; j++)
                {
                    if (p[j].getprice() > p[j + 1].getprice()) {
                        Product temp = p[j];
                        p[j] = p[j + 1];
                        p[j + 1] = temp;
                    }
                }
            }
        }
        void search(string searchName){
            for (int i = 0; i < count; i++)
            {
                if(p[i].getname()==searchName){
                    cout<<"product found:\n";
                    p[i].getInfo();
                    break;
                }
            }
        }
        void display(){
            for (int i = 0; i < count; i++) {
                p[i].getInfo();
                cout << "\n--------------------\n";
            }
        }

};
int main(){
    Inventory i("inventory 1");
    i.add("iPhone 12 Pro",2211,999.9);
    i.add("MacBook",1122,1999.9);
    i.add("Lenovo ThinkBook",1212,500);
    i.add("Nike Mercurial",0111,249.9);
    i.add("Apple Watch Series 10",2112,399.9);
    cout<<"\ninventory\n";
    i.display();
    cout<<"\nsorted inventory\n";
    i.sort();
    i.display();
    i.search("MacBook");
}

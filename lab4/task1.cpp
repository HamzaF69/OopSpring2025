#include <iostream>
#include <string>
using namespace std;
class Book{
    private:
    string title;
    float price;
    int *stock;
    public:
    Book() {
        title="Unknown";
        price=0.0;
        stock=new int(30);
    }
    void update(string t,float p,int s){
        title=t;
        price=p;
        *stock=s;
    }
    void purchase(int quan){
        if (quan>*stock){
            cout<<"not enough books";
            return;
        } else{
            *stock =*stock-quan;
            cout<<quan<<" many books have been purchased\n";
        }
        if (*stock<5){
            cout<<"warning- low stock\n";
        }
    }
    void display(){
        cout<<"book: "<<title<<" price: "<<price<<" stock: "<<*stock<<endl;
    }
};
int main(){
    Book b1;
    
}


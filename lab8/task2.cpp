#include <iostream>
#include <string>
using namespace std;
class Librarian;
class Book{
    private:
    string title;
    float price;
    public:
    Book(string t,float p):title(t),price(p){}
    friend Librarian;
};

class Librarian{
    public:
    void applyDiscount(Book b){
        cout<<"applying discount\nprice before discount: "<<b.price<<endl;
        b.price*=0.7;
        cout<<"after 30% discount: "<<b.price<<"\n";
    }
    void displayInfo(Book b){
        cout<<"title: "<<b.title<<endl;
        cout<<"price: "<<b.price<<endl;
    }
};
int main (){
    Book b("harry potter",1000);
    Librarian l;
    l.displayInfo(b);
    l.applyDiscount(b);
    l.displayInfo(b);
}

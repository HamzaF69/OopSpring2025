#include <iostream>
#include <string>
using namespace std;
class Book{
    private:
    string *title;
    float *price;
    int *stock;
    public:
    Book() {
        title = new string("Unknown");
        price = new float(0.0);
        stock=new int(30);
    }
    Book(string t,float p,int s){
        title = new string(t);
        price = new float(p);
        stock=new int(s);
        cout<<"changes saved\n";
    }
    //copy constructor
    Book(const Book &b) {
        cout<<"custom copy constructor\n";
        title = new string(*b.title);
        price = new float(*b.price);
        stock = new int(*b.stock);
    }
    ~Book(){
        delete title;
        delete price;
        delete stock;
    }
    void update(string t,float p,int s){
        cout<<"title is update from "<<*title<<" to "<<t<<endl;;
        cout<<"price is update from "<<*price<<" to "<<p<<endl;;
        cout<<"stock is update from "<<*stock<<" to "<<s<<endl;;
        *title=t;
        *price=p;
        *stock=s;
    }
    float purchase(int quan){
        float cost;
        if (quan>*stock){
            cout<<"not enough books, maximum available quantity is: "<<*stock;
            return 0;
        } else{
            *stock =*stock-quan;
            cost= *price*quan;
            cout<<quan<<" books have been purchased\n";
            cout<<"total cost: "<<cost<<endl;
            return cost;
        }
        if (*stock<5){
            cout<<"warning- low stock\n";
        }
    }
    void applyDiscount(int quan,float cost){
        float finalCost;
        if(quan>5 &&quan<=10){
            finalCost=cost*0.95;
            cout<<"final cost is: "<<finalCost<<endl;
        } else if(quan>10){
            finalCost=cost*0.90;
            cout<<"final cost is: "<<finalCost<<endl;
        } else{
            cout<<"discount not applicable\n";
        }
    }
    void display(){
        cout<<"book: "<<*title<<" price: "<<*price<<" stock: "<<*stock<<endl;
    }
};
int main(){
    Book b1("matilda",49.9,20);
    Book b2(b1);
    b1.applyDiscount(6,b1.purchase(6));
    cout << "\nOriginal Book:\n";
    b1.display();

    cout << "\nCopied Book:\n";
    b2.display();
    b2.update("harry potter",99.9,15);
    cout<<"\nupdated copied book:\n";
    b2.display();
}

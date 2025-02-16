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
    Book(const Book &b) {
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
        cout<<"title is update from "<<*this->title<<" to "<<t<<endl;;
        cout<<"price is update from "<<*this->price<<" to "<<p<<endl;;
        cout<<"stock is update from "<<*this->stock<<" to "<<s<<endl;;
        *title=t;
        *price=p;
        *stock=s;
    }
    void purchase(int quan){
        float discountPrice;
        if (quan>5 &&quan<=10){
            discountPrice=(*price)*quan*0.95;
            cout<<"since you have bulked purchased, you get a discount of 5 %:\n";
            cout<<"cost before discount: "<<(*this->price)*quan<<"\ncost after discount: "<<discountPrice<<endl;
            *stock-=quan;
        }else if (quan>10){
            discountPrice=(*price)*quan*0.90;
            cout<<"since you have bulked purchased, you get a discount of 10 %:\n";
            cout<<"cost before discount: "<<(*this->price)*quan<<"\ncost after discount: "<<discountPrice<<endl;
            *stock-=quan;
        } else{
            cout<<"no discount, final cost is: "<<*this->price;
        }
    }
    void display(){
        cout<<"book: "<<*title<<" price: "<<*price<<" stock: "<<*stock<<endl;
    }
};
int main(){
    Book b1("matilda",49.9,20);
    Book b2(b1);
    b1.purchase(11);
    b1.display();
}

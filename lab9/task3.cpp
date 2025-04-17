#include "Book.h"
#include <iostream>
#include <string>
using namespace std;
int main(){
    Book h("harry potter", "jk rowling","AJ5544");
    cout<<"title: "<<h.getTitle()<<"\nauthor: "<<h.getAuthor()<<"\nisbn: "<<h.getISBN()<<endl;

}

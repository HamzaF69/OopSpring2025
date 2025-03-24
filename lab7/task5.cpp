#include <iostream>
#include <string>
using namespace std;
class Media{
    protected:
    string title,publisher;
    int publicationDate,uniqueID;
    public:
    Media(string t,string pub,int date,int id):title(t),publisher(pub),publicationDate(date),uniqueID(id){}
    virtual void displayInfo(){
        cout<<"title: "<<title<<"\npublisher: "<<publisher<<"\npublication date: "<<publicationDate<<"\nID: "<<uniqueID<<endl;
    }
    void checkout(){
        cout<<"checked out\n";
    }
    void returnItem(){
        cout<<"item returned\n";
    }
    string getTitle(){
        return title;
    }
    ~Media(){}
};

class Book:public Media{
    private:
    string author;
    int ISBN,numberOfPages;
    public:
    Book(string t,string pub,int date,int id,string auth,int isbn,int pages):Media(t, pub, date, id),ISBN(isbn),author(auth),
    numberOfPages(pages){}
    void displayInfo()override{
       Media::displayInfo();
        cout<<"author: "<<author<<"\nISBN: "<<ISBN<<"\npages: "<<numberOfPages<<endl;
    }
    void checkout(){
        cout<<"book "<<getTitle()<<" checked out\n";
    }
    ~Book(){}
};

class DVD:public Media{
    private:
    string director;
    float duration,rating;
    public:
    DVD(string t,string pub,int date,int id,string dir,float dur,float r):Media(t, pub, date, id),duration(dur),director(dir),
    rating(r){}
    void displayInfo()override{
        Media::displayInfo();
        cout<<"director: "<<director<<"\nduration: "<<duration<<"\nrating: "<<rating<<endl;
    }
    void checkout(){
        cout<<"DVD "<<getTitle()<<" checked out\n";
    }
    ~DVD(){}
};

class CD:public Media{
    private:
    string artist,genre;
    int numberOfTracks;
    public:
    CD(string t,string pub,int date,int id,string art,string gen,int tracks):Media(t, pub, date, id),artist(art),genre(gen),numberOfTracks(tracks){}

    void displayInfo()override{
        Media::displayInfo();
        cout<<"artist: "<<artist<<"\ngenre: "<<genre<<"\nnumber of tracks: "<<numberOfTracks<<endl;
    }
    
    void checkout(){
        cout<<"CD "<<getTitle()<<" checked out\n";
    }
    ~CD(){}
};

class Magzine:public Media{
    private:
    int fee;
    public:
    Magzine(string t,string pub,int date,int id,int f):Media(t, pub, date, id),fee(f){}

    void displayInfo()override{
        Media::displayInfo();
        cout<<"fee: "<<fee<<endl;
    }
    
    void checkout(){
        cout<<"magzine "<<getTitle()<<" checked out\n";
    }
    ~Magzine(){}
};

int main (){
    Magzine m1("daily","vogue",13062024,2211,3000);
    Book b1("harry potter","matt damond",14072023,1122,"JK rowling",522450,556);
    DVD d1("deadpool","rayn renolds",15022022,5566,"sam raimi",2.5,8.9);
    CD c1("Aadat","farooq sattar",14072021,3322,"atif aslam","pop",52);
    c1.displayInfo();
    cout<<endl;
    d1.displayInfo();
    cout<<endl;
    b1.displayInfo();
    cout<<endl;
    m1.displayInfo();
    cout<<endl;
    c1.checkout();
    cout<<endl;
    c1.returnItem();
    cout<<endl;

}

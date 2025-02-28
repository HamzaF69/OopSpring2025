#include <iostream>
#include <string>
using namespace std;
class Movie{
    string director;
    string title;
    float duration;
    public:
        Movie(){}
        Movie(string title,string director,float duration){
            this->director=director;
            this->duration=duration;
            this->title=title;
        }
        void getInfo(){
            cout<<"title: "<<title<<"\ndirector: "<<director<<"\nduration: "<<duration<<" hours\n";
            
        }
};
class CinemaHall{
    Movie m[5];
    int count=0;
    string cinemaName;
    public:
        CinemaHall(string cinemaName){
            this->cinemaName=cinemaName;
        }
        void add(string title,string director,float duration){
            
            if(count<5){
                m[count]=Movie(title,director,duration);
                count++;
            }else {
                cout<<"max capacity of movies has reached\n";
            }
        }
        void display(){
            cout<<"cinema: "<<cinemaName<<endl;
            for (int i = 0; i < count; i++)
            {
                cout<<"---------------------\n";
                m[i].getInfo();
                cout<<"---------------------\n";
            }
            
        }
};
int main (){
    CinemaHall c1("cinema 1");
    CinemaHall c2("cinema 2");
    c1.add("interstellar","christopher nolan",2.9);
    c1.add("transformers","michael bay",2.5);
    c2.add("the dark knight","christopher nolan",3);
    c1.display();
    c2.display();
}

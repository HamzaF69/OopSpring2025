#include <iostream>
#include <string>
using namespace std;
class TourGuide{
    string name;
    int experience;
    string specialization;
    public:
    TourGuide(){
        name="";
        specialization="";
        experience=0;
    }
    TourGuide(string name,int experience,string specialization){
        this->name=name;
        this->experience=experience;
        this->specialization=specialization;
    }
    void getinfo(){
        cout<<"name: "<<name<<endl;
        cout<<"experience: "<<experience<<" years"<<endl;
        cout<<"specialization: "<<specialization<<endl;
    }
};
class TravelAgency{
    string name;
    int count,cap;
    TourGuide *guides;
    public:
        TravelAgency(string name,int cap){
            this->name=name;
            this->cap=cap;
            guides = new TourGuide[cap];
            count=0;
        }
        void addGuide(string name,int exp,string specialization){
            if(count<cap){
            guides[count]= TourGuide(name,exp,specialization);
            count++;
            }else{
                cout<<"maximum capacity reached. couldnt add tour guide\n";
            }
        }
        void display(){
            cout<<"tour guides available:"<<endl;
            for (int i = 0; i < count; i++)
            {
                guides[i].getinfo();
            }
            
        }
};
int main (){
    TravelAgency t("You Travel",4);
    t.addGuide("hamza",10,"cultural tourism");
    t.addGuide("zaid",9,"historical tours");
    t.display();
}

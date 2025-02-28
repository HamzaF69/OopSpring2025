#include <iostream>
#include <string>
using namespace std;
class Patient{
    int id;
    string name;
    float *results;
    public:
        Patient(string name,int id,float* results){
            this->id=id;
            this->name=name;
            this->results= new float[5];
            for (int i = 0; i < 5; i++)
            {
                this->results[i]=results[i];
            } 
        }
        Patient(Patient &p){
            cout<<"copying details...\n";
            id=p.id;
            name=p.name;
            results = new float[5];
            for (int i = 0; i < 5; i++)
            {
                results[i]=p.results[i];
            }
        }
    void display(){
        cout<<"\ndisplaying results\n";
        cout<<"name "<<name<<endl;
        cout<<"ID "<<id<<endl;
        cout<<"test results:\n";
        for (int i = 0; i < 5; i++){
            cout<<results[i]<<endl;
        }
    }
    ~Patient(){
        delete[] results;
    }
};
int main (){
    float results[5]={22.2,56.9,50.0,30.3,41.7};
    Patient p1("hamza",0576,results);
    Patient p2(p1);
    p2.display();
    return 0;
}

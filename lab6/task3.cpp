#include <iostream>
#include <string>
using namespace std;
class Person{
    protected:
        string name;
        int age;
    public:
        Person(string name,int age):name(name),age(age){}
        void displayDetails(){
            cout<<"name: "<<name<<endl;
            cout<<"age: "<<age<<endl;
        }
};
class Teacher: public Person{
    protected:
        string subject;
    public:
    Teacher(string name,int age,string subject):Person(name,age),subject(subject){}
    void displayDetails(){
        Person::displayDetails();
        cout<<"subject: "<<subject<<endl;
    }
};
class Researcher: public Person{
    protected:
        string researchArea;
    public:
    Researcher(string name,int age,string researchArea):Person(name,age),researchArea(researchArea){}
    void displayDetails(){
        Person::displayDetails();
        cout<<"research area: "<<researchArea<<endl;
    }
};
class Professor:public Researcher,public Teacher{
    protected:
        int publications;
    public:
        Professor(string name,int age,string subject,string researchArea,int publications):Teacher(name,age,subject),Researcher(name,age,researchArea),
        publications(publications){}
        void displayDetails(){
            Teacher::displayDetails();
            cout<<"research area: "<<researchArea<<endl;
            cout<<"publications: "<<publications<<endl;
        }
};
int main(){
    Professor p("hamza",18,"math","computer science",40);
    p.displayDetails();
    return 0;
}

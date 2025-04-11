#include <iostream>
#include <string>
using namespace std;
class Teacher;
class Student{
    private:
    string name;
    int grades[3];
    public:
    Student(string n,int g[]):name(n){
        for (int i = 0; i <3; i++)
        {
            grades[i]=g[i];
        }
    }
    friend  Teacher;
    friend float calculateAverageGrade(Student s);
};

class Teacher{
public:
    void update(Student s){
        int g,i;
        cout<<"enter new grade: ";
        cin>>g;
        cout<<"enter subject index you want to change: ";
        cin>>i;
        s.grades[i]=g;
    }
    void viewgrade(Student s){

        cout<<s.grades[0]<<endl;
        cout<<s.grades[1]<<endl;
        cout<<s.grades[2]<<endl;
    }
    
};
float calculateAverageGrade(Student s){
    float avg=0;
    for (int i = 0; i < 3; i++)
    {
        avg+=s.grades[i];
    }
    avg=avg/3;
    return avg;
    
}

int main(){
    int g[3]={90,95,100};
    Student s("hamza",g);
    Teacher t;
    t.viewgrade(s);
    cout<<"average grade: "<<calculateAverageGrade(s)<<endl;
    t.update(s);
}

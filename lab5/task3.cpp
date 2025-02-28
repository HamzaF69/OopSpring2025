#include <iostream>
#include <string>
using namespace std;
class Professor{
    string name;
    string department;
    public:
        Professor() {
            name = "";
            department = "";
        }
        Professor(string name,string department){
            this->department=department;
            this->name=name;
        }
        void displaydetails(){
            cout<<"name: "<<name<<endl;
            cout<<"department: "<<department<<endl;
        }
};
class University{
    string name;
    Professor *profs;
    int count;
    int capacity;
    public:
        University(string name,int cap){
            this->name=name;
            capacity=cap;
            count =0;
            profs = new Professor[capacity];
        }
        void addProf(string name,string department){
            if (count<capacity){
            profs[count] = Professor(name, department);
            count++;
            }else{
               cout<<"cannot add professor, maximum capacity reached\n"; 
            }
        }
        void displayDetails() {
            cout<<"university Name: " << name << endl;
            cout<<"professors:"<<endl;
            for (int i = 0; i < count; i++) {
                profs[i].displaydetails();
            }
        }
};
int main (){
    University u("FAST", 12);
    u.addProf("hamza","Computer Science");
    u.addProf("zaid","SE");
    u.displayDetails();
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
class Person {
    protected:
    string name;
    string address, email;
    int phoneNum;
    public:
    Person(string n,int num,string add,string em):name(n),phoneNum(num),address(add),email(em){}
    virtual void displayInfo(){
        cout<<"name: "<<name<<"\nPhone Number: "<<phoneNum<<"\nAddress: "<<address<<"\nemail: "<<email<<endl;
    }
    string getName() const {
        return name;
    }
    void updateInfo(){
        int ch;
        cout<<"\nenter choice:\n";
        cout<<"press 1 to update name\npress 2 to update address\npress 3 to update number\npress 4 to update email\n";
        cin>>ch;
        string nName,Naddress,Nemail;
        int Nnum;
        switch (ch)
        {
        case 1:
            cout<<"enter new name: ";
            cin>>nName;
            name=nName;
            break;
        case 2:
            cout<<"enter new address: ";
            cin>>Naddress;
            address=Naddress;
            break;
        case 3:
            cout<<"enter new number: ";
            cin>>Nnum;
            phoneNum=Nnum;
            break;    
        case 4:
            cout<<"enter new email: ";
            cin>>Nemail;
            email=Nemail;
            break;
            default:
            cout<<"invalid option\n";
            break;
        }
    }
};

class Student:public Person{
    protected:
    float gpa;
    string coursesEnrolled[2];
    int enrollmentYear;
    public:
    Student(string n,int num,string add,string em,float gpa,string c1,string c2,int year):
    Person(n,num, add, em),gpa(gpa),enrollmentYear(year)  {
        coursesEnrolled[0]=c1;
        coursesEnrolled[1]=c2;
    }
    void displayInfo()override{
        cout<<"name: "<<name<<"\nPhone Number: "<<phoneNum<<"\nAddress: "<<address<<"\nemail: "<<email<<endl;
        cout<<"gpa: "<<gpa<<"\nenrollment Year: "<<enrollmentYear<<endl;
        cout<<"courses:\n";
        cout<<coursesEnrolled[0]<<"\n"<<coursesEnrolled[1]<<endl;
    }
};

class Professor:public Person{
    protected:
    float salary;
    string coursesTaught[2],department;
    public:
    Professor(string n,int num,string add,string em,float salary,string c1,string c2,string dep):
    Person(n,num, add, em),salary(salary),department(dep){
        coursesTaught[0]=c1;
        coursesTaught[1]=c2;
    }
    void displayInfo()override{
        cout<<"name: "<<name<<"\nPhone Number: "<<phoneNum<<"\nAddress: "<<address<<"\nemail: "<<email<<endl;
        cout<<"salary: "<<salary<<"department: "<<department<< endl;
        cout<<"courses taught:\n";
        cout<<coursesTaught[0]<<"\n"<<coursesTaught[1]<<endl;
    }
};

class Staff:public Person{
    protected:
    float salary;
    string postion,department;
    public:
    Staff(string n,int num,string add,string em,float salary,string dep,string pos):
    Person(n,num, add, em),salary(salary),department(dep),postion(pos){
    }
    void displayInfo()override{
        cout<<"name: "<<name<<"\nPhone Number: "<<phoneNum<<"\nAddress: "<<address<<"\nemail: "<<email<<endl;
        cout<<"salary: "<<salary<<"\ndepartment: "<<department<<"\nposition: "<<postion<<endl;
    }
};

class Course
{
    private:
    int courseId,credits;
    string courseName,instructor;
    string schedule;
    public:
    Course(int id, string name, string instr, int cred, string sched)
    :courseId(id), courseName(name), instructor(instr), credits(cred), schedule(sched){}
    void displayCourse() {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName<< "\nInstructor: " << instructor << "\nCredits: " << credits
             << "\nSchedule: " << schedule << endl;
    }
    void registerStudent(Student &s){
        cout << s.getName() << " has been registered for "<<courseName<<endl;
    }
};
int main (){
    Student s1("hamza",92335,"street 2, house no. 6, DHA phase 8","hamza123@gmail.com",3.8,"OOP","MVC",2024);
    Professor p1("Dr. Smith", 12345, "University Road", "smith@uni.edu", 95000.50, "AI", "Data Science", "CS Department");
    Staff staff1("John Doe", 67890, "Admin Block", "john.doe@uni.edu", 50000.75, "Admin", "Manager");
    Course c1(101, "Object-Oriented Programming", "Dr. Smith", 3, "MWF 10:00 AM - 11:30 AM");
    s1.displayInfo();
    s1.updateInfo();
    s1.displayInfo();
    p1.displayInfo();
    staff1.displayInfo();
    c1.displayCourse();
    c1.registerStudent(s1);
    return 0;
}

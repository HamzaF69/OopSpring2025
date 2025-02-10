#include <iostream>
#include <string>
using namespace std;

class Planner{
    private:
    string task[12][31];
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    public:
    Planner(){
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 31; j++){
                task[i][j]="";
            }
            
        }
    }
    void add(int mon, int day,string &t){
        if (mon<1||mon>12||day<1||day>days[mon-1]) {
            cout<<"invalid date entered...\n";
        } if(task[mon-1][day-1]!="") {
            cout<<"task is already assigned to that date\n";
        } else {
            task[mon-1][day-1]=t;
            cout<<"task added successfully\n";
        }
    } 
    void remove(int mon, int day){
        if(mon<1||mon>12||day < 1 || day > days[mon - 1]){
            cout<<"invalid date entered...\n";
        } else{
            task[mon-1][day-1]="";
        }
    }
    void display(){
        cout<<"--DISPLAYING TASKS--\n";
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                if(task[i][j]!=""){
                    cout<<"task of month "<<i+1<<" day "<<j+1<<": "<<task[i][j]<<endl;
                }
            }
            
        }
    }
};
int main(){
    Planner p;
    string task;
    int day,mon,ch;
    while(1){
        cout<<"1- ADD TASK\n";
        cout<<"2- REMOVE TASK\n";
        cout<<"3- DISPLAY TASKS\n";
        cout<<"4- EXIT\n";
        cout<<"enter your choice:"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"enter month you want (1-12): \n";
            cin>>mon;
            cout<<"enter day you want: \n";
            cin>>day;
            cin.ignore();
            cout<<"enter task you want to add: \n";
            getline(cin, task);
            p.add(mon,day,task);
            break;
        case 2:
            cout<<"enter month you want to remove the task of: \n";cin>>mon;
            cout<<"enter day you want to remove the task of: \n";cin>>day;
            p.remove(mon,day); 
            break;
        case 3:
            p.display();       
            break;
        case 4:
            cout<<"exiting...\n";
            return 0;
            break;    
        default:
        cout<<"invalid choice, try again\n";
            break;
        }
    }
    return 0;
}
    

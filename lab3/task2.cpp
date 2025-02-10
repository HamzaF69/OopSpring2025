#include <iostream>
#include <string>
using namespace std;
class TeaMug{
    public:
    string brand;
    string color;
    int capacity=10;
    int fillLevel=capacity;
};
int main (){
    TeaMug t;
    t.brand ="tappal";
    t.color = "green";
    cout<<"Hi Fatima... lets track your tea mug: "<<endl;
    while (1){
        cout<<"press 1 to sip the tea "<<endl;
        cout<<"press 2 to refill the mug"<<endl;
        cout<<"press 3 to check if the mug is empty "<<endl;
        cout<<"press 4 to exit "<<endl;
        int ch;
        cin>>ch;
        switch (ch)
        {
        case 1:
            if(t.fillLevel>0){
                cout<<"you are sipping the tea...\n";
                t.fillLevel--;
            } else{
                cout<<"not enought tea. please refill\n";
            }
            break;
        case 2:
            cout<<"refilling the mug...\n";
            t.fillLevel=10;
            break;
        case 3:
            if(t.fillLevel>0){
                cout<<"you you have tea in your mug. enjoy!\n";
            } else{
                cout<<"not enough tea. you need to refill your mug\n";
            }
            break;
        case 4:
            cout<<"exiting...";
            return 0;    
        default:
            break;
        }
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
class MarkerPen {
public:
    string brand;
    string color;
    int inkLevel=10;
    int refills=0;
};
void write(MarkerPen &p) {
    cout<<"writing..."<<endl;
    p.inkLevel--;
}
void refill(MarkerPen &p) {
    p.inkLevel =10;
    p.refills++;
}
void displayPenDetails(const MarkerPen &p) {
    cout<<"Brand: "<<p.brand<<endl;
    cout<<"Color: "<<p.color<<endl;
    cout<<"Refills: "<<p.refills<<endl;
    cout<<"Current ink level: "<<p.inkLevel<<endl;
}
int main(){
    MarkerPen pens[3];
    pens[0].brand="Parker";
    pens[0].color="Blue";
    pens[1].brand="Pilot";
    pens[1].color="Red";
    pens[2].brand="Faber-Castell";
    pens[2].color="Black";
    while (true) {
        cout<<"Hi Ahmed... what would you like to do today?"<<endl;
        cout<<"Press 1 to write with a pen"<<endl;
        cout<<"Press 2 to refill a pen"<<endl;
        cout<<"Press 3 to check details about a pen"<<endl;
        cout<<"Press 4 to exit"<<endl;
        int ch;
        cin >>ch;
        switch (ch) {
            case 1: {
                cout << "Select a pen (1-3): ";
                int penIndex;
                cin>>penIndex;
                if (penIndex<1||penIndex>3) {
                    cout<<"Invalid pen selection" << endl;
                    break;
                }
                MarkerPen &selectedPen=pens[penIndex-1];
                if (selectedPen.inkLevel>0) {
                    write(selectedPen);
                } else {
                    cout<<"not enough ink to write"<<endl;
                }
                break;
            }
            case 2: {
                cout<<"select a pen (1-3):";
                int penIndex;
                cin>>penIndex;
                if (penIndex<1||penIndex>3) {
                    cout<<"Invalid pen selection"<<endl;
                    break;
                }
                MarkerPen &selectedPen=pens[penIndex-1];
                if (selectedPen.inkLevel==10) {
                    cout << "pen is full and doesnt need a refill"<< endl;
                } else {
                    refill(selectedPen);
                    cout<<"pen refilled successfully"<<endl;
                }
                break;
            }
            case 3: {
                cout << "Select a pen (1-3): ";
                int penIndex;
                cin >> penIndex;
                if (penIndex < 1 || penIndex > 3) {
                    cout<<"invalid pen selection"<<endl;
                    break;
                }
                displayPenDetails(pens[penIndex-1]);
                break;
            }
            case 4: {
                cout<<"exiting..."<<endl;
                return 0;
            }
            default: {
                cout<<"Invalid choice. Please try again"<<endl;
                break;
            }
        }
    }
    return 0;
}

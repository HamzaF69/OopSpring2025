#include <iostream>
#include <string>
using namespace std;
class Humidity;

class Temperature{
    private:
    float temp;
    public:
    Temperature(float t):temp(t){}
    friend float calculateHeatIndex(Temperature obj,Humidity ob);
};

class Humidity{
    private:
    float hum;
    public:
    Humidity(float h):hum(h){}
    friend float calculateHeatIndex(Temperature obj,Humidity ob);
};

float calculateHeatIndex(Temperature obj,Humidity ob){
    return obj.temp +(0.05*ob.hum);
}
int main() {
    Temperature temp(32.0);
    Humidity hum(70.0);
    
    float heatIndex = calculateHeatIndex(temp, hum);
    cout << "Calculated Heat Index: " << heatIndex << endl;
    
    return 0;
}

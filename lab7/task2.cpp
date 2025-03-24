#include <iostream>
#include <string>
using namespace std;
class Shape {
    protected:
    int position;
    string color;
    float thickness;
    public:
    Shape(int pos,string c,float thick):position(pos),color(c),thickness(thick){}
    virtual void draw(){}
    virtual float calculateArea(){
        return 2*2;
    }
    virtual float calculatePerimeter(){
        return 2+2+2;
    }
};

class Circle:public Shape{
    private:
    float radius;
    int Cposition;
    public:
    Circle(int pos,string c,float thick,float r):Shape(pos,c,thick),Cposition(pos),radius(r){}
    void draw()override{
        cout << "Drawing Rectangle at (" << Cposition <<") with radius "<<radius<< " and color " << color << "\n";
    }
    float calculatePerimeter()override{
        return 2*3.14*radius;
    }
    float calculateArea()override{
        return 3.14*radius*radius;
    }
};

class Rectangle:public Shape{
    private:
    float width,height;
    int Lposition;
    public:
    Rectangle(int pos,string c,float thick,float w,float h):Shape(pos,c,thick),Lposition(pos),width(w),height(h){}
    void draw()override {
        cout << "Drawing Rectangle at (" << Lposition <<") with width " << width << " and height " << height
             << " and color " << color << "\n";
    }
    float calculatePerimeter()override{
        return 2*width+2*height;
    }
    float calculateArea()override{
        return width*height;
    }
};

class Triangle:public Shape{
    private:
    float a,b,c;
    int Cposition;
    public:
    Triangle(int pos,string col,float thick,float a,float b,float c):Shape(pos,col,thick),Cposition(pos),a(a),b(b),c(c){}
    void draw()override{
        cout << "Drawing Rectangle at (" << Cposition <<") with base "<<a<<" height" <<b <<" adjacent"<<c<<" and color " << color << "\n";
    }
    float calculatePerimeter()override{
        return a+b+c;
    }
    float calculateArea()override{
        return 0.5*a*b;
    }
};
int main(){
    Circle c(10,"red",2,5);
    cout << "Area: " << c.calculateArea() << "\n";
    cout << "Perimeter: " <<c.calculatePerimeter() << "\n";
}

#include <iostream>
using namespace std;
#define pai 3.14159

class Shape
{
    protected:
    double S;
    public:
    virtual int area() = 0;


};

class Circle :public Shape
{
    protected:
    double radius ;
    public:
    Circle ()
    {
        cout<<"请输入圆的半径"<<endl;
        cin>>radius;
    }
    int area()
    {
        S = radius*radius*pai;
    }
    void show()
    {
        cout<<"area of circle = "<<S<<endl;
    }
};
class Rectangle :public Shape
{
    protected:
    double length ;
    double width ;
    public:
    Rectangle ()
    {
        cout<<"请输入矩形的长和宽"<<endl;
        cin>>length>>width;
    }
    int area()
    {
        S = width*length;
    }
    void show()
    {
        cout<<"area of rectangle = "<<S<<endl;
    }
};

int main ()
{
    Circle c;
    c.area();
    c.show();
    Rectangle r;
    r.area();
    r.show();

    return 0;

}

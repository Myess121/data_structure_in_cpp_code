#include <iostream>
#define pai 3.14
using namespace std;

class Shape
{
    protected:
    double area;
    double volume;
    public:
    virtual double Area() = 0;
    virtual double Volume() = 0;
    virtual void display() = 0;

    void show()
    {
        cout<<" 面积、体积："<<area<<" "<<volume<<endl;
    }

};

class Square: public Shape
{
    protected:
    double a;
    public:
    Square()
    {
        cin>>a;
    }
    void display()
    {
        cout<<"Shape：正方体"<<endl;
        show();
    }
    double Area()
    {
        area = 6*a*a;
    }
    double Volume()
    {
        volume = a*a*a;
    }
};
class Ball: public Shape
{
    protected:
    double a;
    public:
    Ball()
    {
        cin>>a;
    }
    void display()
    {
        cout<<"Shape：球体"<<endl;
        show();
    }
    double Area()
    {
        area = 4*pai*a*a;
    }
    double Volume()
    {
        volume = a*a*a*pai*4/3;
    }
};
class cylinder: public Shape
{
    protected:
    double a;
    double h;
    public:
    cylinder()
    {
        cin>>a>>h;
    }
    void display()
    {
        cout<<"Shape：圆柱体"<<endl;
        show();
    }
    double Area()
    {
        area = h*pai*a*2 + 2*a*a*pai;
    }
    double Volume()
    {
        volume = a*a*h*pai;
    }
};

int main ()
{
    Square s;
    Ball b;
    cylinder c;
    Shape *p[3];
    p[0] = &s;
    p[1] = &b;
    p[2] = &c;
    for(int i = 0;i<3;i++)
    {
        p[i] ->Area();
        p[i] ->Volume();
        p[i] ->display();
    }
    return 0;

}
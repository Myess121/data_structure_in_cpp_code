#include <iostream>
using namespace std;
#define pai 3.1415926
class Shape
{
    public:
    virtual void calcArea() = 0;
    virtual void calcVolume() = 0;
    virtual void set_r(double r) = 0;
    virtual void set_a(double a) = 0;
    virtual void set_b(double b) = 0;
    virtual void set_c(double c) = 0;
    virtual void printValue() = 0;
    Shape()
    {
        cout<<"Shape constructor"<<endl;
    }
    virtual ~Shape()
    {
        cout<<"Shape destructor"<<endl;
    }

};

class Circle :public Shape
{
    protected:
    double r,s;
    public:
    Circle()
    {
        r=0;
        s=0;
        cout<<"Circle constructor"<<endl;
    }
    void calcVolume(){}
    void set_a(double a){}
    void set_b(double b){}
    void set_c(double c){}
    void calcArea()
    {
        s = r*r*pai;
    }
    void set_r(double r)
    {
        Circle::r = r;
    }
    void printValue()
    {
        cout<<"Circle"<<endl;
        cout<<"r="<<r<<endl;
        cout<<"s="<<s<<endl;
    }
    ~Circle()
    {
        cout<<"Circle destructor"<<endl;
    }
};
class Rectangle :public Shape
{
    protected:
    double a,b,s;
    public:
    void set_r(double r){}
    void set_c(double c){}
    void calcVolume(){}
    Rectangle()
    {
        a = 0;b = 0;s = 0;
        cout<<"Rectangle constructor"<<endl;
    }
    void calcArea()
    {
        s = a*b;
    }
    void set_a(double a)
    {
        Rectangle::a = a;
    }
    void set_b(double b)
    {
        Rectangle::b = b;
    }
    void printValue()
    {
        cout<<"Rectangle"<<endl;
        cout<<"a="<<a<<endl;
        cout<<"b="<<b<<endl;
        cout<<"s="<<s<<endl;
    }
    ~Rectangle()
    {
        cout<<"Rectangle destructor"<<endl;
    }
};
class Cuboid :public Shape
{
    protected:
    double a,b,c,v;
    public:
    void set_r(double r){}
    void calcArea(){}
    Cuboid()
    {
        a = 0;b = 0;c = 0;v = 0;
        cout<<"Cuboid constructor"<<endl;
    }
    void calcVolume()
    {
        v = a*b*c;
    }
    void set_a(double a)
    {
        Cuboid::a = a;
    }
    void set_b(double b)
    {
        Cuboid::b = b;
    }
    void set_c(double c)
    {
        Cuboid::c = c;
    }
    void printValue()
    {
        cout<<"Cuboid"<<endl;
        cout<<"a="<<a<<endl;
        cout<<"b="<<b<<endl;
        cout<<"c="<<c<<endl;
        cout<<"v="<<v<<endl;
    }
    ~Cuboid()
    {
        cout<<"Cuboid destructor"<<endl;
    }
};

int main ()
{
    Shape *p;
    int k;
    double a,b,c,r;
    cin>>k;
    if(k == 1)
    {
        p = new Circle;
        cin>>r;
    }else if(k == 2)
    {
        p = new Rectangle;
        cin>>a>>b;
    }else{
        p = new Cuboid;
        cin>>a>>b>>c;
    }
    p->set_a(a);
    p->set_b(b);
    p->set_c(c);
    p->set_r(r);
    p->calcArea();
    p->calcVolume();
    p->printValue();
    delete p;

    return 0;
}
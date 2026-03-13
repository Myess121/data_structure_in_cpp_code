#include <iostream>
using namespace std;

#define pi 3.14159

class Circle
{
    private :
    double radius;
    public:
    Circle (int r):radius(r){}
    double perimeter();
    double square();
};
double Circle::perimeter()
{
    return (radius + 3) * 2 * pi;
}
double Circle::square()
{
    return ((radius + 3)*(radius + 3) - radius*radius) * pi;
}

int main()
{
    double a;
    cin>>a;
    Circle c(a);
    cout<<"Enter the radius of the pool:"<<a<<endl;
    cout<<"Fencing Cost is "<<35*c.perimeter()<<endl;
    cout<<"Concrete Cost is "<<20*c.square()<<endl;
    return 0;


}
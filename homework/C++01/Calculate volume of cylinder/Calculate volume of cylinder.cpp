#include <iostream>
using namespace std;

#define pi 3.14

class Cylinder{
    private :
    double radius;
    double height;
    public:
    Cylinder(double r,double h);
    void Calculate();

};
Cylinder::Cylinder(double r,double h)
{
    radius = r;
    height = h;
}
void Cylinder::Calculate()
{
    cout<<"v="<<pi*radius*radius*height<<endl;
}

int main()
{
    double a,b;
    cin>>a>>b;
    Cylinder cylinder(a,b);
    cylinder.Calculate();

}

#include <iostream>
using namespace std;

class Felid
{
    public:
    Felid(){cout<<"Felid constructor"<<endl;}
    virtual ~Felid(){cout<<"Felid destructor"<<endl;}
    virtual void sound() = 0;
};

class Cat :public Felid
{
    public:
    Cat(){cout<<"Cat constructor"<<endl;}
    ~Cat(){cout<<"Cat destructor"<<endl;}
    void sound()
    {
        cout<<"Miaow !"<<endl;
    }
};

class Leopard :public Felid
{
    public:
    Leopard(){cout<<"Leopard constructor"<<endl;}
    ~Leopard(){cout<<"Leopard destructor"<<endl;}
    void sound()
    {
        cout<<"Howl !"<<endl;
    }
};

int main ()
{
    Felid *p = new Cat;
    p->sound();
    delete p;
    p = new Leopard;
    p->sound();
    delete p;
    return 0;
}
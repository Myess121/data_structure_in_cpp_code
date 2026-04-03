#include <iostream>
using namespace std;

class CPU
{
    public:
    virtual void show() = 0;
};
class IntelCPU:public CPU
{
    public:
    void show()
    {
        cout<<"Intel的CPU开始计算了"<<endl;
    }
};
class LenovoCPU:public CPU
{
    public:
    void show()
    {
        cout<<"Lenovo的CPU开始计算了"<<endl;
    }
};

class GPU
{
    public:
    virtual void show() = 0;
};
class IntelGPU:public GPU
{
    public:
    void show()
    {
        cout<<"Inte的显卡开始显示了"<<endl;
    }
};
class LenovoGPU:public GPU
{
    public:
    void show()
    {
        cout<<"Lenovo的显卡开始显示了"<<endl;
    }
};

class GOLD
{
    public:
    virtual void show() = 0;
};
class IntelGOLD:public GOLD
{
    public:
    void show()
    {
        cout<<"Intel的内存条开始存储了"<<endl;
    }
};
class LenovoGOLD:public GOLD
{
    public:
    void show()
    {
        cout<<"Lenovo的内存条开始存储了"<<endl;
    }
};

class computer
{
    protected:
    CPU *cpu;
    GPU *gpu;
    GOLD *gold;
    public:
    computer()
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a == 1)
        {
            cpu = new IntelCPU;
        }else{
            cpu = new LenovoCPU;
        }
        if(b == 1)
        {
            gpu = new IntelGPU;
        }else{
            gpu = new LenovoGPU;
        }
        if(c == 1)
        {
            gold = new IntelGOLD;
        }else{
            gold = new LenovoGOLD;
        }
    }
    void display ()
    {
        cpu->show();
        gpu->show();
        gold->show();
    }
};
int main()
{
    computer com;
    com.display();
    return 0;
}
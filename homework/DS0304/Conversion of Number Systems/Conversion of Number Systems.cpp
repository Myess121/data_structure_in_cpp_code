#include <iostream>

using namespace std;

class Stack
{
    protected:
    int top;
    char *sta;
    int maxsize;

    public:
    Stack()
    {
        top = -1;
        sta = new char [100];
        maxsize = 100;
    }

    bool Istop()
    {
        if(top == maxsize -1)
        {
            return 1;
        }
        return 0;
    }

    bool Isempty()
    {
        if(top == -1)
        {
            return 1;
        }
        return 0;
    }
    bool push(char a)
    {
        if(Istop() == 1)
        {
            return 0;
        }
        sta[top] = a;
        top ++;
        return 1;
    }

    bool pop(char &x)
    {
        if(Isempty() == 1)
        {
            return 0;
        }
        top --;
        x = sta[top];
        return 1;
    }

    bool show ()
    {
        while(Isempty() == 0)
        {
            char y;
            pop(y);
            cout<<y;
        }
        cout<<endl;
        return 1;
    }
};

int main()
{
    int n,a;
    char c;
    Stack t;
    cin>>n;
    if(n ==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    while(n>0)
    {
        a = n%16;
        if(a<=9)
        {
            t.push(a+'0');
        }else{
            t.push(a-10+'A');
        }
        n = n/16;   
    }
    t.show();
    return 0;
}
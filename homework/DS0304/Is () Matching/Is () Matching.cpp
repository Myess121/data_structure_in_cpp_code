#include <iostream>

using namespace std;

class Stack
{
    protected:
    int *sta = new int [100];
    int top = -1;
    int maxsize = 100;

    public:
    bool IsFull()
    {
        if(top == maxsize - 1)
        {
            return 1;
        }
        return 0;
    }

    bool IsEmpty()
    {
        if(top == -1)
        {
            return 1;
        }
        return 0;
    }

    bool push(int a)
    {
        if(IsFull () == 1)
        {
            return 0;
        }
        top ++;
        sta[top] = a;
        return 1;
    }
    bool pop(int &x)
    {
        if(IsEmpty() == 1)
        {
            return 0;
        }
        x = sta[top];
        top --;
        return 1;
    }
    bool readtop(int &x)
    {
        if(IsEmpty() == 1)
        {
            return 0;
        }
        x = sta[top];
        return 1;
    }
};

int main ()
{
    char c;
    int a;
    bool flag = 0;
    Stack  t;
    while((c = getchar())!='\n')
    {
        if(c == '(')
        {
            t.push(1);
        }else if(c == ')')
        {
            if(t.readtop(a) == 1 && a == 1)
            {
                t.pop(a);
            }else{
                flag = 1;
            }
        }else if(c == '[')
        {
            t.push(2);
        }else if(c == ']')
        {
            if(t.readtop(a) == 1 && a == 2)
            {
                t.pop(a);
            }else{
                flag = 1;
            }
        }else if(c == '{')
        {
            t.push(3);
        }else if(c == '}')
        {
            if(t.readtop(a) == 1 && a == 3)
            {
                t.pop(a);
            }else{
                flag = 1;
            }
        }
    }
    if(flag == 1 || t.readtop(a) == 1)
    {
        cout<<"括号不配对"<<endl;
        return 0;
    }
    cout<<"括号配对"<<endl;
    return 0;

}
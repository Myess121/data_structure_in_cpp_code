#include <iostream>

using namespace std;

class Stack
{
    protected:
    int *sta;
    int top = -1;
    int maxsize;

    public:
    Stack(int n)
    {
        sta = new int [n];
        maxsize = n;
        top = -1;
    }
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

int main()
{
    int n,a;
    cin>>n;
    bool flag = 0;
    int *p = new int [n],*q = new int [n];
    for(int i = 0;i<n;i++)
    {
        cin>>p[i];
    }
    for(int i = 0;i<n;i++)
    {
        cin>>q[i];
    }
    Stack t(n);
    int j = 0;
    for(int i = 0;i<n;i++)
    {
        if(p[i] == q[j])
        {
            t.push(p[i]);
            t.pop(a);
            j++;
            flag = t.readtop(a);
            while(flag != 0&&a == q[j])
            {
                j++;
                t.pop(a);
                flag = t.readtop(a);
            }
        }else{
            t.push(p[i]);
        }
    }
    if(t.IsEmpty() == 1)
    {
        cout<<"The pop order is possible."<<endl;
        return 0;
    }
    cout<<"The pop order is impossible."<<endl;
    return 0;

}
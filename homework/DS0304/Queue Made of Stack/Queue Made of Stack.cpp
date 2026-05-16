#include <iostream>
#include <cstring>

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
    bool move(Stack &st)
    {
        if(st.IsEmpty() == 1)
        {
            return 0;
        }
        int a;
        while(st.pop(a) == 1)
        {
            push(a);
        } 
        return 1;
    }
};

int main()
{
    Stack stin ,stout;
    int a;
    string order;
    while(cin>>order)
    {
        if(order == "enqueue")
        {
            cin>>a;
            stin.push(a);
        }else if(order == "dequeue")
        {
            if(stout.IsEmpty() == 1)
            {
                stout.move(stin);
            }
            stout.pop(a);
            cout<<a<<endl;
        }else if(order == "isEmpty")
        {
            if(stin.IsEmpty() == 1&&stout.IsEmpty() == 1)
            {
                cout<<"1"<<endl;
            }else{
                cout<<"0"<<endl;
            }
        }
    }
    return 0;
}
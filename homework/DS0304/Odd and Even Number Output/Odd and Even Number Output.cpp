#include <iostream>

using namespace std;

class Queue
{
    protected:
    int *que;
    int head,tail,qsize;
    int maxsize;

    public:
    Queue(int a)
    {
        head = 0;
        tail = 0;
        qsize = 0;
        maxsize = a;
        que = new int [a];
    }
    bool IsFull()
    {
        if(head == (tail + 1)%maxsize)
        {
            return 1;
        }
        return 0;
    }
    bool IsEmpty()
    {
        if(head == tail)
        {
            return 1;
        }
        return 0;
    }
    bool insert(int a)
    {
        if(IsFull() == 1)
        {
            return 0;
        }
        tail = (tail+1) % maxsize;
        que[tail] = a;
        qsize ++;
        return 1;
    }
    bool dequeue (int &a)
    {
        if(IsEmpty() == 1)
        {
            return 0;
        }
        head = (head+1)%maxsize;
        a = que[head];
        return 1;
    }

};

int main()
{
    int n,a;
    cin>>n;
    Queue odd(n),even(n);
    for(int i = 0;i<n;i++)
    {
        cin>>a;
        if(a%2 == 1)
        {
            odd.insert(a);
        }else{
            even.insert(a);
        }
    }
    while(odd.IsEmpty() == 0&&even.IsEmpty() == 0)
    {
        odd.dequeue(a);
        cout<<a<<" ";
        even.dequeue(a);
        cout<<a<<endl;

    }
    return 0;
}
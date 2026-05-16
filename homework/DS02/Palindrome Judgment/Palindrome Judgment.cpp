#include <iostream>

using namespace std;

struct node 
{
    int val;
    node *next = NULL;
    node *prior = NULL;
};

class list
{
    protected :
    node *head = new node ;
    node *nail = new node;
    int n = 0;

    public:
    list()
    {
        head->next = nail;
        nail->prior = head;
    }
    void insert (int a)
    {
        node *p = head, *q = new node;
        q->val = a;
        q->next = p->next;
        p->next->prior = q;
        q->prior = p;
        p->next = q;
        n++;
        return ;
    }

    int  judge ()
    {
        node *p = head, *q = nail;
        if(n == 0 || n == 1)
        {
            return 1;
        }
        q = q->prior;
        p = p->next;
        while (q != p && q->next != p)
        {
            if(q->val != p->val)
            {
                return 0;
            }
            q = q->prior;
            p = p->next;
        }
        return 1;
    }
};

int main()
{
    int a = 0;
    bool flag = 0;
    char c;
    list l;
    while (c = getchar())
    {
        if(c>='0' && c<='9')
        {
            a = a*10 + c - '0';
            flag = 1;
        }else
        {
            if(flag == 1)
            {
                flag = 0;
                l.insert(a);
                a = 0;
            }
            if(c == '\n')
            {
                break;
            }
        }
    }
    cout<<l.judge()<<endl;
    return 0;
}
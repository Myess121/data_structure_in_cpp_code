#include <iostream>

using namespace std;

struct node 
{
    int val;
    node *next = NULL;
};
 
class list 
{
    protected:
    int n = 0;
    node *head = new node;

    public:
    void insert(int a)
    {
        node *p = head;
        node *q = new node;
        q ->val = a;
        q->next = p->next;
        p->next = q;
        n++;
        return ;
    }
    int middle()
    {
        node *p = head->next;
        if(n == 0)
        {
            return 0;
        }
        for(int i = 0;i<(n-1)/2;i++)
        {
            p = p->next;
        }
        return p->val;
    }
};

int main()
{
    int cnt,num;
    list li;
    cin>>cnt;
    for(int i = 0;i<cnt;i++)
    {
        cin>>num;
        li.insert(num);
    }
    cout<<li.middle()<<endl;
    return 0;
}
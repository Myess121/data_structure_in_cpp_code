#include <iostream>
#include <cstring>

using namespace std;

struct node 
{
    int value;
    node *next = NULL;
};

class linkedlist
{
    private:
    node *head = new node ;
    int n = 0;
    public:
    void insert(int direct ,int val)
    {
        node *p = head;
        node *q = new node;
        q->value = val;
        while(p->next != NULL)
        {
            if(p->next->value == direct)
            {
                n++;
                q->next = p->next;
                p->next = q;
                return ;
            }
            p = p->next;
        }
        p->next = q;
        n++;
        return ;
        
    }
    void  del (int dir)
    {
        node *p = head;
        while(p->next != NULL)
        {
            if(p->next->value == dir)
            {
                n--;
                node *q = p->next;
                p->next = q->next;
                delete q;
                return ;
            }
            p = p->next;
        }
    }
    void show()
    {
        node *p = head;
        if(p->next == NULL )
        {
            cout<<"NULL"<<endl;
            return ;
        }
        while(p->next != NULL)
        {
            if(p == head){}else{
                cout<<p->value<<" ";
            }
            p = p->next;
        }
        cout<<p->value<<" ";    
        cout<<endl;
    }
};

int main ()
{
    int a,num,v;
    linkedlist list;
    string t;
    cin>>a;
    for(int i =0;i<a;i++)
    {
        cin>>t;
        if(t == "delete"){
            cin>>v;
            list.del(v);
        }else if(t == "insert"){
            cin>>num>>v;
            list.insert(num,v);
        }
    }
    list.show();
    return 0;
}
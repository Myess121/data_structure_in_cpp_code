#include <iostream>

using namespace std;

struct node 
{
    int val;
    node *next = NULL;
};

class list
{
    public:
    node *head = new node;
    int n;

    public :
    void insert(int a)
    {
        node *p = head;
        node *q = new node;
        q->val = a;
        while (p->next!= NULL)
        {
            if(p->next->val >= a)
            {
                q->next = p->next;
                p->next = q;
                n++;
                return ;
            }
            p = p->next;
        }
        p->next = q;
        n++;
        return ;
    }

    void compare(list *pa,list *pb)
    {
        node *pa1 = pa->head->next,*pb1 = pb->head->next;
        node *p = head;

        while(pa1!= NULL && pb1 != NULL)
        {
            while(pa1->val > pb1->val )
            {
                pb1 = pb1->next;
                if(pb1 == NULL)
                {
                    return ;
                }
            }
            
            if(pa1->val == pb1->val)
            {
                insert(pa1->val);
                pa1 = pa1->next;
                pb1 = pb1->next;
            }else{
                pa1 = pa1->next;
            }
        }

        return ;
    }

    void show()
    {
        if(head ->next == NULL)
        {
            cout<<"没有交集"<<endl;
            return;
        }
        node *p = head->next;
        while(p != NULL)
        {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
        return ;
    }
};

int main()
{
    list l1,l2,lf;
    bool flag = 0;
    int a = 0;
    char c;
    while(c = getchar())
    {
        if(c >='0' && c<='9')
        {
            a = 10*a + c -'0';
            flag = 1;
        }else{
            if(flag == 1)
            {
                l1.insert(a);
                a = 0;
                flag = 0;
            }
            if(c == '\n')
            {
                break;
            }
        }
    }
     while(c = getchar())
    {
        if(c >='0' && c<='9')
        {
            a = 10*a + c -'0';
            flag = 1;
        }else{
            if(flag == 1)
            {
                l2.insert(a);
                a = 0;
                flag = 0;
            }
            if(c == '\n')
            {
                break;
            }
        }
    }
    lf.compare(&l1,&l2);
    lf.show();
    return 0;
}

#include <iostream>

using namespace std;

struct edge
{
    int dest;
    edge *next = NULL;
};

struct vertex
{
    char info;
    edge *first = NULL;
};

class graph
{
    private :
    vertex * ver;
    int numv = 0;
    public:
    graph(int n)
    {
        ver = new vertex[n];
    }
    void addnode(char a)
    {
        ver[numv].info = a;
        numv++;
    }
    int search(char c)
    {
        for(int i = 0;i<numv;i++)
        {
            if(ver[i].info == c)
            {
                return i;
            } 
        }
        return -1;
    }
    void addedge(char a,char b)
    {
        int an,bn;
        an = search(a);
        bn = search(b);
        edge *q = new edge;
        q->dest = bn;
        if(ver[an].first == NULL)
        {
            ver[an].first = q;
            return;
        }
        edge *p = ver[an].first;
        while(p->next!= NULL)
        {
            p = p->next;
        }
        p->next = q;
        return;
    }
    void output()
    {
        for(int i = 0;i<numv;i++)
        {
            cout<<i<<" "<<ver[i].info;
            edge *p = ver[i].first;
            while(p!=NULL)
            {
                cout<<"-"<<p->dest;
                p = p->next;
            }
            cout<<"-^"<<endl;
        }
    }

};

int main ()
{
    int t,n,k;
    char a,b;
    cin>>t;
    while(t>0)
    {
        cin>>n>>k;
        graph gra(n);
        for(int i = 0;i<n;i++)
        {
            cin>>a;
            gra.addnode(a);
        }
        for(int i=0;i<k;i++)
        {
            cin>>a>>b;
            gra.addedge(a,b);
        }
        gra.output();
        t--;
    }
}
#include <iostream>

using namespace std;

class graph
{
    private:
    char *node;
    char **arcs;
    int numv,nume;

    public:
    graph(int n)
    {
        node = new char[n];
        arcs = new char*[n];
        for(char i = 0;i<n;i++)
        {
            arcs[i] = new char [n];
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                arcs[i][j] = '0';
            }
        }
        numv = 0;
        nume = 0;
    }
    void addnode(char n)
    {
        node[numv] = n;
        numv++;
    }
    int search(char n)
    {
        int i;
        for(i = 0;i<numv;i++)
        {
            if(node[i] == n)
            {
                return i;
            }
        }
        return -1;
    }
    void addside(int a,int b,char val)
    {
        int u,v;
       // u = search(a);
       // v = search(b);
        arcs[a-1][b-1] = val;
        arcs[b-1][a-1] = val;
    }
    void output()
    {
        cout<<"  ";
        for(int i = 0;i<numv;i++)
        {
            cout<<node[i]<<" ";
        }
        cout<<endl;

        for(int i = 0;i<numv;i++)
        {
            cout<<node[i]<<" ";
            
            for(int j = 0;j<numv;j++)
            {
                cout<<arcs[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    int v , s;
    char a;
    cout<<"请输入图的顶点数和边数："<<endl;
    cin>>v>>s;
    graph gra(v);
    cout<<"请输入图的各个顶点的信息（A,B…）："<<endl;
    for(int i = 0;i<v;i++)
    {
        cin>>a;
        gra.addnode(a);
    }
    int x,y;
    char z;
    cout<<"请输入各条边的信息（例：1 2表示在A顶点和B顶点之间有一条边）:"<<endl;
    for(int i = 0;i<s;i++)
    {
        cin>>x>>y>>z;
        gra.addside(x,y,z);
    }

    gra.output();
    
}
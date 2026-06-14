#include <iostream>
using namespace std;

class graph
{
    private:
    bool *val;
    int **g;
    int numv;

    public:
    graph(int n)
    {
        g = new int *[n];
        val = new bool[n];
        for(int i = 0;i<n;i++)
        {
            val[i] = 0;
            g[i] = new int[n];
            for(int j = 0;j<n;j++)
            {
                g[i][j] = 0;
            }
        }
        numv = n;
    }
    void addedge(int a,int b)
    {
        g[a][b] = 1;
        g[b][a] = 1;
    }
    int find()
    {
        int n = 0;
        for(int i = 0;i<numv;i++)
        {
            if(val[i] == 1)
            {
                continue;
            }
            val[i] = 1;
            for(int j = 0;j<numv;j++)
            {
                if(g[i][j] == 1)
                {
                    val[j] = 1;
                }
            }
            n++;
        }
        return n;
    }

};

int main()
{
    int n,m;
    cin>>n>>m;
    graph gra(n);
    for(int i = 0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        gra.addedge(a,b);
    }
    cout<<gra.find()<<endl;
}
#include <iostream>
using namespace std;

template<class T>
int count(T *p,T x,int n)
{
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        if(p[i] == x)
        {
            cnt++;
        }
    }
    return cnt;
}

int main ()
{
    int c,n;
    cin>>c>>n;
    switch (c)
    {
        case 1:
       { int *a = new int[n],x;
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>x;
        cout<<count(a,x,n)<<endl;}
        break;
        case 2:
        {float *b = new float[n],y;
        for(int i = 0;i<n;i++)
        {
            cin>>b[i];
        }
        cin>>y;
        cout<<count(b,y,n)<<endl;}
        break;
        case 3:
       { double *d = new double[n],z;
        for(int i = 0;i<n;i++)
        {
            cin>>d[i];
        }
        cin>>z;
        cout<<count(d,z,n)<<endl;}
        break;
        case 4:
        string e[n],q;
        for(int i = 0;i<n;i++)
        {
            cin>>e[i];
        }
        cin>>q;
        cout<<count(e,q,n)<<endl;
        break;
    }
}

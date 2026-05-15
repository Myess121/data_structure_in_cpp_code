#include <iostream>
#include <cstring>

using namespace std;

class ver
{
    private:
    int *arr;
    int n;
    int k;
    
    public :
    ver(int nu ):n(nu)
    {
        arr = new int[n];
    };
    void insert(int n1)
    {
        for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
    }
    void print(int n1)
    {
        int *p = arr;
        for(int i = 0;i<n;i++)
        {
            if(i != 0)
            {
                cout<<" ";
            }
            cout<<p[i];
        }
        cout<<endl;
        return;
    }
    int LeftMove(int n1,int k1)
    {
        int kk = k1 % n;
        int *p = arr;
        for(int i = 0;i<kk;i++)
        {
            int t = arr[0];
            for(int j = 0;j<n-1;j++)
            {
                p[j] = p[j+1];
            }
            p[n-1] = t;
        }
    }

};

int main()  
{  
    int n, k;  
    cin >> n;  
    cin >> k;  
    ver a(n);  
    a.insert(n);  
    a.LeftMove(n, k);  
    a.print(n);  
    return 0;  
}  

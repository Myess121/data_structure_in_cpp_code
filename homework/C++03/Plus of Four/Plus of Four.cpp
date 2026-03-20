#include <iostream>
using namespace std;
class Four
{
    public:
    int a;
    friend Four operator +(Four f1,Four f2);
    Four(int n):a(n){};
    Four(){
        cin>>a;
    }
    int display()
    {
        cout<<a<<endl;
        return 0;
    }
};
Four operator +(Four f1,Four f2)
{
    int t = f1.a + f2.a;
    int flag = 0;
    int j = 1,aa = 0;
    while(t)
    {
        if(t%10 +flag>= 4)
        {
            aa += (t%10+flag-4) * j;
            flag = 1;
        }else {
            aa += (t%10+flag) * j;
            flag = 0;
        }
        t = t/10;
        j *= 10;
    }
    if(flag == 1)
    {
        aa += flag * j;
    }
    return Four(aa);
}

int main()
{
    int n;
    Four x(0);
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        Four y;
        x = x+y;
    }
    x.display();

    return 0;


}
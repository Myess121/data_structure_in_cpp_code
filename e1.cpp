#include <iostream>
#include <cstring>
using namespace std;

class item 
{
    private :
     int a;
    int b;
    char c[10];

    public:
    item (int a1,int b1,char c1[]):a(a1),b(b1){
        strcpy(c,c1);
    };
    item():a(66){
        b = 8;
    }
    void display()
    {
        cout<<a<<"  "<<b<<"  "<<c<<endl;
    }

};
item s(3,2,"hello"),t;
int main()
{
    s.display();
    t.display();
    t = s;
    t.display();
    return 0;

}
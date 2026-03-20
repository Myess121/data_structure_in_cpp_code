#include <iostream>
using namespace std;
class RMB
{
    private :
    int yuan;
    int jiao;
    int fen;

    public:
    RMB()
    {
        cout<<"请输入元、角、分："<<endl;
        cin>>yuan>>jiao>>fen;
    }
    RMB(int a)
    {
        yuan = 0;
        jiao = 0;
        fen = 0;
    }
    RMB(int a,int b,int c):yuan(a),jiao(b),fen(c){};
    friend RMB operator +(RMB a1,RMB a2);
    friend RMB operator -(RMB a1,RMB a2);
    void display ()
    {
        cout<<yuan<<"元"<<jiao<<"角"<<fen<<"分"<<endl;
    }
};
RMB operator +(RMB a1,RMB a2)
{
    int y,j,f,flag = 0;
    f = a1.fen + 10 * a1.jiao + 100 * a1.yuan + a2.fen + 10 * a2.jiao + 100 * a2.yuan;
    return RMB(f/100,f/10-f/100*10,f%10);
}
RMB operator -(RMB a1,RMB a2)
{
    int y,j,f,flag = 0;
    f = a1.fen + 10 * a1.jiao + 100 * a1.yuan - (a2.fen + 10 * a2.jiao + 100 * a2.yuan);
    if(f < 0){
        f = -f;
        return RMB(-f/100,f/10-f/100*10,f%10);
    }
    return RMB(f/100,f/10-f/100*10,f%10);
}
int main()
{
    RMB x,y,m(0),n(0);
    m = x + y;
    cout<<"和：";
    m.display();
    n = x - y;
    cout<<"差：";
    n.display();

    return 0;


}
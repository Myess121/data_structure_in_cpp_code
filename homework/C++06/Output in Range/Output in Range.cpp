#include <iostream>
using namespace std;

template<class T>
class input
{
    protected:
    T max,min;
    public:
    input(T x,T y):min(x),max(y){}
    void output(T n)
    {
        if(n>=min && n<= max)
        {
            cout<<n<<endl;
            return ;
        }
        cout<<"数据不符合范围，请重新输入。"<<endl;
    }
};

int main() {  
    int x, y, z;  
    cin >> x >> y >> z;  
    char a, b, c;  
    cin >> a >> b >> c;  
    input< int> in1(x, y);  
    in1.output(z);  
      
    input < char> in2(a, b);  
    in2.output(c);  
  
}  
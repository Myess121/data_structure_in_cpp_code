#include <iostream>
using namespace std;

template <class T>
class Store
{
    protected:
    T item;
    public:
    void putElem(T a)
    {
        item = a;
    }
    T getElem()
    {
        return item;
    }
};

int main() {  
  
    int a;  
    double b;  
    cout << "请输入整变量a，以及浮点型变量b：" << endl;  
    cin >> a >> b;  
  
    Store<int> s1;  
    Store<double> s2;  
    s1.putElem(a);  
    s2.putElem(b);  
    cout << "s1.getElem() = " << s1.getElem() << "  " << "s2.getElem() = " << s2.getElem() << endl;  
  
    return 0;  
}  
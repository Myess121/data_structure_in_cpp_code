#include <iostream>
using namespace std;

class Time
{
    private:
    int hour;
    int min;
    int sec;
    public:
    Time(int h,int m,int s);
    void show();
};
Time::Time(int h,int m,int s)
{
    hour = h;
    min = m;
    sec = s;
}
void Time::show()
{
    cout<<hour<<":"<<min<<":"<<sec<<endl;
    return;

}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    Time time(a,b,c);
    time.show();

}
#include <iostream>
using namespace std;
class Time;
class Date
{
    private :
    int year;
    int month;
    int day;
    public:
    Date()
    {
        cin>>year>>month>>day;   
    }
    friend void display(Date d,Time t);
};
class Time
{
    private :
    int hour;
    int minute;
    int second;
    public:
    Time()
    {
        cin>>hour>>minute>>second;   
    }
    friend void display(Date d,Time t);
};

void display(Date d,Time t)
{
    cout<<d.year<<"/"<<d.month<<"/"<<d.day<<endl;
    cout<<t.hour<<":"<<t.minute<<":"<<t.second<<endl;
}

int main ()
{
    Date date;
    Time time;
    display(date , time);
    return 0;

}
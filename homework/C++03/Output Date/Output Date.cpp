#include <iostream>
using namespace std;

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
    friend ostream & operator <<(ostream &os,Date &date);
};

ostream & operator <<(ostream &os,Date &date)
{
    cout<<date.year<<"-"<<date.month<<"-"<<date.day<<endl;
    return os;
}

int main ()
{
    Date d;
    cout<<d;
    return 0;
}
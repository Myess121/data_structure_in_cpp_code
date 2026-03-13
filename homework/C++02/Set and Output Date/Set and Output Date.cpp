#include <iostream>
using namespace std;

class Date 
{
    private:
    int year;
    int month;
    int day;
    public:
    Date(int y,int m, int d): year(y),month(m),day(d){}
    ~Date(){}
    int GetDay();
    int GetMonth();
    int GetYear();
    void ShowDate();
};
int Date::GetDay()
{
    cout<<"day "<<day<<endl;
    return 0;
}
int Date::GetMonth()
{
    cout<<"month "<<month<<endl;
    return 0;
}
int Date::GetYear()
{
    cout<<"year "<<year<<endl;
    return 0;
}
void Date::ShowDate()
{
    cout<<year<<"/"<<month<<"/"<<day<<endl;
}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    Date date(a,b,c);
    date.ShowDate();
    date.GetYear();
    date.GetMonth();
    date.GetDay();
    return 0;

}
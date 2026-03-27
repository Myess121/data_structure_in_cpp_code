#include <iostream>
using namespace std;

class building 
{
    protected:
    int floor;
    int room;
    double aera;

    public:
    building(int f,int r,double a):floor(f),room(r),aera(a){};
    void show ()
    {
        cout<<"floor:"<<floor<<endl;
        cout<<"room:"<<room<<endl;
        cout<<"area:"<<aera<<endl;
        return;
    }
};
class House :public building 
{
    protected:
    int Bedrooms;
    int Bathrooms;

    public:
    House(int f,int r,double a,int bed,int bath):building(f,r,a),Bedrooms(bed),Bathrooms(bath){}
    void show()
    {
        building::show();
        cout<<"Bedrooms:"<<Bedrooms<<endl;
        cout<<"Bathrooms:"<<Bathrooms<<endl;
        return ;
    }
};
class Office :public building 
{
    protected:
    int tables;
    int phones;

    public:
    Office(int f,int r,double a,int t,int p):building(f,r,a),tables(t),phones(p){}
    void show()
    {
        building::show();
        cout<<"tables:"<<tables<<endl;
        cout<<"Phones:"<<phones<<endl;
        return ;
    }
};
int main()
{
    int f,r;
    double a;
    int bed;
    int bath;
    cin>>f>>r>>a>>bed>>bath;
    House house(f,r,a,bed,bath);
    cout<<"house_information"<<endl;
    house.show();
    int t,p;
    cin>>f>>r>>a>>t>>p;
    Office office(f,r,a,t,p);
    cout<<"office_information"<<endl;
    office.show();

    return 0;

}
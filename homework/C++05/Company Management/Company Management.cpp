#include <iostream>
#include <cstring>
using namespace std;
class employee
{
    protected:
    char *name;
    int salary;
    public:
    virtual void count() = 0;
};

class manager :public employee
{
    public:
    manager(char *n)
    {
        salary = 8000;
        name = new char[strlen(n) + 1];
        strcpy(name , n);
    }
    void count(){}
    void show()
    {
        cout<<name<<"本月工资"<<salary<<endl;
    }
};
class technician :public employee
{
    protected:
    int hour;
    public:
    technician(char *n)
    {
        cin>>hour;
        name = new char[strlen(n) + 1];
        strcpy(name , n);
    }
    void count()
    {
        salary = 100*hour;
    }
    void show()
    {
        cout<<name<<"本月工资"<<salary<<endl;
    }
};
class sales :public employee
{
    protected:
    int money;
    public:
    sales(char *n)
    {
        cin>>money;
        name = new char[strlen(n) + 1];
        strcpy(name , n);
    }
    void count()
    {
        salary = money*4/100;
    }
    void show()
    {
        cout<<name<<"本月工资"<<salary<<endl;
    }
};
class salesmanager :public employee
{
    protected:
    int money;
    public:
    salesmanager(char *n)
    {
        cin>>money;
        name = new char[strlen(n) + 1];
        strcpy(name , n);
    }
    void count()
    {
        salary = money*5/1000 + 5000;
    }
    void show()
    {
        cout<<name<<"本月工资"<<salary<<endl;
    }
};

int main()
{
    manager Tom("Tom");
    technician John("John");
    salesmanager Antony("Antony");
    sales Jane("Jane");
    Tom.count();
    Tom.show();
    John.count();
    John.show();
    Antony.count();
    Antony.show();
    Jane.count();
    Jane.show();

    return 0;
}

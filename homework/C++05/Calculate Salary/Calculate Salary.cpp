#include <iostream>
#include <cstring>
using namespace std;

class teacher
{
    protected:
    char *name;
    char *sex;
    char *ID;
    int Asalary;
    int hour;
    int Zsalary;

    public:
    virtual int pay() = 0;
    teacher(char* n,char* s,char *id,int h):hour(h)
    {
        name = new char[strlen(n) + 1];
        strcpy(name , n);
        sex = new char[strlen(s) + 1];
        strcpy(sex , s);
        ID = new char[strlen(id) + 1];
        strcpy(ID , id);
    }
    virtual void show()
    {
        cout<<"姓名："<<name<<endl;
        cout<<"性别："<<sex<<endl;
        cout<<"工号："<<ID<<endl;
        cout<<"课时数："<<hour<<endl;
        cout<<"本月工资："<<Zsalary<<endl;
    }
};

class professor:public teacher
{
    public:
    professor(char* n,char* s,char *id,int h):teacher(n,s,id,h){Asalary = 20000;};
    int pay()
    {
        Zsalary = Asalary + hour*50;
    }
    void show()
    {
        cout<<"职称：教授"<<endl;
        teacher::show();
    }
};
class associate_professor:public teacher
{
    public:
    associate_professor(char* n,char* s,char *id,int h):teacher(n,s,id,h){Asalary = 15000;};
    int pay()
    {
        Zsalary = Asalary + hour*30;
    }
    void show()
    {
        cout<<"职称：副教授"<<endl;
        teacher::show();
    }
};
class lecturer:public teacher
{
    public:
    lecturer(char* n,char* s,char *id,int h):teacher(n,s,id,h){Asalary = 10000;};
    int pay()
    {
        Zsalary = Asalary + hour*20;
    }
    void show()
    {
        cout<<"职称：讲师"<<endl;
        teacher::show();
    }
};

int main ()
{
    int k;
    char n[100];
    char s[100];
    char id[100];
    int h;
    teacher *p;
    cin>>k>>n>>s>>id>>h;
    if(k ==1)
    {
        p = new professor(n,s,id,h);
    }else if(k == 2)
    {
        p = new associate_professor(n,s,id,h);
    }else
    {
        p = new lecturer(n,s,id,h);
    }

    p->pay();
    p->show();
    return 0;
}
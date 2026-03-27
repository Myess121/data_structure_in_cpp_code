#include <iostream>
#include <cstring>
using namespace std;

class Person 
{
    protected:
    char *name;
    int sex;
    int age ;

    public:
    Person(char *p,int s,int a):sex(s),age(a){
        name = new char[strlen(p) + 1];
        strcpy(name,p);
    }
    void show ()
    {
        cout<<"name:"<<name<<endl;
        cout<<"age:"<<age<<endl;
        if(sex == 0)
        {
            cout<<"sex:女"<<endl;
            return;
        }
        cout<<"sex:男"<<endl;
    }

};
class Employee:public Person
{
    protected:
    int basicSalary;
    int leaveDays;

    public:
    Employee(char *p,int s,int a,int b,int l):Person(p,s,a),basicSalary(b),leaveDays(l){};
    void show()
    {
        Person::show();
        cout<<"basicSalary:"<<basicSalary<<endl;
        cout<<"leavedays:"<<leaveDays<<endl;
        return ;
    }
};

int main()
{
    char arr[100];
    int s,a,b,l;
    cin>>arr>>s>>a>>b>>l;
    Employee E(arr,s,a,b,l);
    E.show();
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

class People 
{
    protected:
    char *Name ;
    char * Sex;//0:woman 1:man
    int Age;

    public:
    People(char *name,char* s,int a):Age(a)
    {
        Name = new char[strlen(name) + 1];
        strcpy(Name,name);
        Sex = new char[strlen(s) + 1];
        strcpy(Sex,s);
    }
    void show()
    {
        cout<<"Name: "<<Name<<endl;
        cout<<"Sex: "<<Sex<<endl;
        cout<<"Age: "<<Age<<endl;
    }
};

class Student:virtual public People
{
    protected:
    char *No;
    double Score;

    public:
    Student(char *name,char* s,int a,char* no,double score): 
        People(name, s, a),Score(score)
    {
        No = new char[strlen(no) + 1];
        strcpy(No,no);
    }

    void show()
    {
        People::show();
        cout<<"No.: "<<No<<endl;
        cout<<"Score: "<<Score<<endl;
    }
};

class Teacher:virtual public People
{
    protected:
    char *Position;
    char *Department;

    public:
    Teacher(char *name,char* s,int a,char* position,char* department):
        People(name, s, a)
    {
        Position = new char[strlen(position) + 1];
        strcpy(Position,position);
        Department = new char[strlen(department) + 1];
        strcpy(Department,department);
    }
    void show()
    {
        People::show();
        cout<<"Position: "<<Position<<endl;
        cout<<"Department: "<<Department<<endl;
    }
};
class GrandOnWork:public Student,public Teacher
{
    protected:
    char *Direction;
    char *Turtor;

    public:
    GrandOnWork(char *name,char* s,int a,char* no,double score,char* position,char* department,char *d,char* t):
        People(name, s, a),Student(name, s, a,no,score),Teacher(name, s, a,position,department)
    {
        Direction = new char[strlen(d) + 1];
        strcpy(Direction,d);
        Turtor = new char[strlen(t) + 1];
        strcpy(Turtor,t);
    }

    void show()
    {
        Student::show();
        cout<<"Position: "<<Position<<endl;
        cout<<"Department: "<<Department<<endl;
        cout<<"Direction: "<<Direction<<endl;
        cout<<"Tutor: "<<Turtor<<endl;
    }
};

int main ()
{
    char name[100],no[100],s[100],position[100],department[100],d[100],t[100];
    int a;
    double score;
    cin>>name>>s>>a>>no>>score>>position>>department>>d>>t;
    GrandOnWork grand(name, s, a,no,score,position,department,d,t);
    cout<<"People:"<<endl;
    grand.People::show();
    cout<<endl;
    cout<<"Student:"<<endl;
    grand.Student::show();
    cout<<endl;
    cout<<"Teacher:"<<endl;
    grand.Teacher::show();
    cout<<endl;
    cout<<"GardOnWork:"<<endl;
    grand.show();
    return 0;
}
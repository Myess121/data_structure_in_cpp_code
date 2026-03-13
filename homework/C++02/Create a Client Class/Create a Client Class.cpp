#include <bits/stdc++.h>
using namespace std;
char name[100];
class Client
{
    private :
    char *m_name;
    int m_age;
    public:
    Client(char* a,int n);
    ~Client(){delete [] m_name;}
    void display();
};
void Client::display()
{
    cout<<"Name:"<<m_name<<endl<<"Age:"<<m_age<<endl;
}
Client::Client(char* a,int n)
{
    m_age = n;
    m_name = new char[strlen(a) + 1];
    strcpy(m_name,a);
}

int main ()
{
    int age;
    cin>>name>>age;
    Client c(name,age);
    c.display();
    return 0;


}
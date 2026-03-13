#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Number
{
private:
    int cnt = 0;
    char *sen;
public:
    Number(char *p);
    ~Number(){}
    int countWord();

};

Number::Number(char *p)
{
    sen = new char[strlen(p) + 1];
    strcpy(sen,p);
}
int Number::countWord()
{
    int i = 0;
    for(i = 0;sen[i] != 0;i++)
    {
        if(sen[i] == ' ')
        {
            cnt ++;
        }
    }
    if(i != 0)
    {
        cnt ++;
    }
    cout<<"Words="<<cnt<<endl;
    return 0;
}

int main()
{
    char s[100];
    cin.getline(s,100);
    Number number(s);
    number.countWord();
    return 0;
}

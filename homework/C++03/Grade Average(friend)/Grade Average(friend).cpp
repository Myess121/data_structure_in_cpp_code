#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    private :
    char name[100];
    double grade[100];
    double score[100] ;

    friend double average ();

    public:
    int get_message()
    {
        int j = 0;
        cin>>name;
        if(strcmp(name,"no") == 0)
        {
            name[0] = 0;
            return -2;
        }
        while(1)
        {
            cin>>grade[j];
            if(grade[j] == -1){
                grade[j] = 0;
                return -1;
            }
            cin>>score[j];
            j++;
        }
    }

};
Student student[100];
double average()
{
    int i = 0;
    double G = 0,S = 0;
    while(student[i].name[0] != 0)
    {
        int j = 0;
        while(student[i].grade[j] != 0)
        {
            G += student[i].grade[j];
            S += student[i].score[j]*student[i].grade[j];
            j++;
        }
        i++;
    }
    cout<<(S/G)<<endl;
    return 0;

}
int main()
{
    int i = 0;
    while(student[i].get_message() == -1)
    {
        i++;
    }
    average();
    return 0;

}


#include <iostream>
#include <cstring>
using namespace std;

class book
{
    protected :
    char *BookName; 
    char *Num;
    char *BookConcern;
    char *Price;

    public:
    book(char* bn,char *num,char* bc,char*price)
    {
        BookName = new char[strlen(bn) + 1];
        strcpy (BookName,bn);

        Num = new char[strlen(num) + 1];
        strcpy (Num,num);

        BookConcern = new char[strlen(bc) + 1];
        strcpy (BookConcern,bc);

        Price = new char[strlen(price) + 1];
        strcpy (Price,price);
    }

    void show_BookName()
    {
        cout<<"BookName:"<<BookName<<endl;
    }
    void show_Num()
    {
        cout<<"Num:"<<Num<<endl;
    }
    void show_BookConcern()
    {
        cout<<"BookConcern:"<<BookConcern<<endl;
    }
    void show_Price()
    {
        cout<<"Price:"<<Price<<endl;
    }

};
class author
{
    protected:
    char *Authorname ;
    char *Authorage;
    int PrintTime[3];

    public:
    author(char *an,char* aa,int y,int m,int d)
    {
        Authorname = new char[strlen(an) + 1];
        strcpy (Authorname,an);
        Authorage = new char[strlen(aa) + 1];
        strcpy (Authorage,aa);
        PrintTime[0] = y;
        PrintTime[1] = m;
        PrintTime[2] = d;
    }

    void show_Authorname()
    {
        cout<<"AuthorName:"<<Authorname<<endl;
    }
    void show_Authorage()
    {
        cout<<"AuthorAge:"<<Authorage<<endl;
    }
    void show_PrintTime()
    {
        cout<<"PrintTime:"<<PrintTime[0]<<"-"<<PrintTime[1]<<"-"<<PrintTime[2]<<endl;
    }
};

class card:public book,public author
{
    protected:
    char *Sysname;

    public:
    card(char* bn,char *num,char* bc,char*price,char *an,char* aa,int y,int m,int d,char*sys):
    book(bn,num,bc,price),author(an,aa,y,m,d)
    {
        Sysname = new char[strlen(sys) + 1];
        strcpy (Sysname,sys);
    }

    void show()
    {
        cout<<"SysName:"<<Sysname<<endl;
        show_Num();
        show_BookName();
        show_BookConcern();
        show_Price();
        show_Authorname();
        show_Authorage();
        show_PrintTime();
        return ;
    }
};

int main()
{
    char bn[100],num[100],bc[100],price[100],an[100],aa[100],sys[100];
    int y,m,d;
    cin>>sys>>num>>bn>>bc>>price>>an>>aa>>y>>m>>d;
    card bit(bn,num,bc,price,an,aa,y,m,d,sys);
    bit.show();
    return 0;
}


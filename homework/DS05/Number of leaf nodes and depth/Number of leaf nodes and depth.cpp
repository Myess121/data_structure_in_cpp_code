#include <iostream>
using namespace std;

struct bintreeNode
{
    char data;
    bintreeNode *Lchild = NULL;
    bintreeNode *Rchild = NULL;
    bintreeNode(char a):data(a){};
};

class bintree
{
    private:
    bintreeNode *root;
    int cnt;
    void Build(bintreeNode *& t)
    {
        char c;
        cin>>c;
        if(c == '#')
        {
            t = NULL;
            return ;
        }
        t = new bintreeNode(c);
        Build(t->Lchild);
        Build(t->Rchild);
    }

    void preorder(bintreeNode * t,int &n,int h,int &h0)
    {
        if(t == NULL)
        {
            if(h > h0)
            {
                h0 = h;
            }
            return ;
        }
        if(t->Lchild == NULL &&  t->Rchild == NULL)
        {
            n++;
        }
        h++;
        preorder(t->Lchild,n,h,h0);
        preorder(t->Rchild,n,h,h0);
    }
    public:
    
    bintree()
    {
        Build(root);
    }

    void count(int &n,int h,int &h0)
    {
        preorder(root,n,h,h0);
    }
};

int main ()
{
    int n = 0,h0 = -1;
    bintree tree;
    tree.count(n,-1,h0);
    cout<<"leafs="<<n<<endl;
    cout<<"Depth="<<h0<<endl;
}
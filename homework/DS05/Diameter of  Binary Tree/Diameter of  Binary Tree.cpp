#include <iostream>

using namespace std;

struct treenode
{
    treenode * Lchild = NULL ;
    treenode * Rchild = NULL ;
};

class bintree 
{
    private:
    treenode * root;

    void deep(treenode * t,int h,int &h0)
    {
        if(t == NULL)
        {
            if(h>h0)
            {
                h0 = h;
            }
            return ;
        }
        h++;
        deep(t->Lchild,h,h0);
        deep(t->Rchild,h,h0);

    }
    int func(treenode * t)
    {
        int hl = -1,hr = -1;
        deep(t->Lchild,-1,hl);
        deep(t->Rchild,-1,hr);
        return hl + hr + 2;
    }
    void order(treenode *t,int &hi)
    {
        if(t == NULL)
        {
            return ;
        }
        int h = func(t);
        if(hi < h)
        {
            hi = h;
        }
        order(t->Lchild,hi);
        order(t->Rchild,hi);

    }
    void build(treenode *&t)
    {
        char c;
        cin>>c;
        if(c == '#')
        {
            return ;
        }
        t = new treenode;
        build(t->Lchild);
        build(t->Rchild);
        
    }
    public:
    bintree()
    {
        build(root);
    }
    int dia()
    {
        int n = 0;
        order(root,n);
        return n;
    }
    
};

int main ()
{
    bintree tree;
    cout<<tree.dia()<<endl;
    return 0;
}
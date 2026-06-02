#include <iostream>
using namespace std;

struct BintreeNode
{
    char data;
    BintreeNode * Lchild = NULL;
    BintreeNode * Rchild = NULL;
    BintreeNode(char a):data(a){};
};

class Bintree
{
    private:
    int cnt = -1;
    BintreeNode * root = NULL;
    void output_preorder(BintreeNode * t)
    {
        if(t == NULL)
        {
            return ;
        }
        cout<<t->data<<" ";
        output_preorder(t->Lchild);
        output_preorder(t->Rchild);
    }
    void output_inorder(BintreeNode * t)
    {
        if(t == NULL)
        {
            return ;
        }
        output_inorder(t->Lchild);
        cout<<t->data<<" ";
        output_inorder(t->Rchild);
    }
    void output_postorder(BintreeNode * t)
    {
        if(t == NULL)
        {
            return ;
        }
        output_postorder(t->Lchild);
        output_postorder(t->Rchild);
        cout<<t->data<<" ";
    }


    public:
    void Build(BintreeNode*& t)
    {
        char c;
        cin>>c;
        if(c == '#')
        {
            t = NULL;
            return ;
        }
        t = new BintreeNode(c);
        cnt ++;
        Build(t->Lchild);
        Build(t->Rchild);
        return ;
    }
    Bintree()
    {
        Build(root);
    }
    bool output_in()
    {
        if(root == NULL)
        {
            return 0;
        }
        cout<<"中序遍历结果：";
        output_inorder(root);
        cout<<endl;
        return 1;
    }
    bool output_pre()
    {
        if(root == NULL)
        {
            return 0;
        }
        cout<<"前序遍历结果：";
        output_preorder(root);
        cout<<endl;
        return 1;
    }
    bool output_post()
    {
        if(root == NULL)
        {
            return 0;
        }
        cout<<"后序遍历结果：";
        output_postorder(root);
        cout<<endl;
        return 1;
    }


};

int main ()
{
    char a;
    Bintree tree;
    tree.output_pre();
    tree.output_in();
    tree.output_post();

    return 0;
}
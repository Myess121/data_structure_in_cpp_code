#include <iostream>
using namespace std;

struct treenode
{
    int data;
    treenode *Lchild = NULL;
    treenode *Rchild = NULL;
    treenode(int a):data(a){};
};
 
class bintree
{
    private:
    treenode *root = NULL;

    void inorder(treenode * t)
    {
        if(t == NULL)
        {
            return ;
        }
        inorder(t->Lchild);
        cout<<t->data<<"  ";
        inorder(t->Rchild);

    }
    bool my_delete(int a,treenode *& ptr)
    {
        if(ptr == NULL)
        {
            return 0;
        }
        if(ptr->data > a)
        {
            return my_delete(a,ptr->Lchild);
        }else if(a > ptr->data)
        {
            return my_delete(a,ptr->Rchild);
        }else if(ptr->Lchild != NULL && ptr->Rchild != NULL)
        {
            treenode *temp = ptr;
            temp = temp->Lchild;
            while(temp->Rchild != NULL)
            {
                temp = temp->Rchild;
            }
            ptr->data = temp->data;
            delete temp;
        }else{
            treenode *temp = ptr;
            
            if(temp->Rchild == NULL)
            {
                ptr = ptr->Lchild;
            }else ptr = ptr->Rchild;
            delete temp;
        }
        return 1;
    }
    public:
    treenode* my_order(int a,treenode* t)
    {
        if(t == NULL)
        {
            return t;
        }
        if(a == t->data)
        {
            return t;
        }
        if(a> t->data)
        {
            if(t->Rchild == NULL)
            {
                return t;
            }
            return my_order(a,t->Rchild);
        }else{
            if(t->Lchild == NULL)
            {
                return t;
            }
            return my_order(a,t->Lchild);
        }

    }
    bool insert(int a)
    {
        treenode *temp = my_order(a,root);
        if(temp == NULL)
        {
            root = new treenode(a);
            return 1;
        }
        if(a>temp->data)
        {
            temp->Rchild = new treenode(a);
            return 1;
        }else if(a<temp->data)
        {
            temp->Lchild = new treenode(a);
            return 1;
        }
        return 0;
    }

    bool del(int a)
    {
        return my_delete(a,root);
    }

    void output()
    {
        inorder(root);

    }

};

int main()
{
    int n,a;
    bintree tree;
    cin>>n;
    int *p = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>p[i];
        tree.insert(p[i]);
    }
    cout<<"原始数据：";
    for(int i = 0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<"中序遍历结果：";
    tree.output();
    cout<<endl;

    cin>>a;
    if(tree.del(a))
    {
        cout<<"删除结点后结果：";
        tree.output();
        cout<<endl;
    }else{
        cout<<"删除结点后结果：没有"<<a<<"结点。"<<endl;
    }
    

    return 0;
}

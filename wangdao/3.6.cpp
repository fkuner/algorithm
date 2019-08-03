// 未完成，需要改动
#include<iostream>
using namespace std;
struct Node
{
    Node *lchild;
    Node *rchild;
    int c;
}Tree[101];
int loc;
Node *creat();
void preOrder(Node *T);
void inOrder(Node *T);
void postOrder(Node *T);
Node *Insert(Node *T,int x);

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        Node *T=NULL;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            T=Insert(T,x);
        }
        preOrder(T);
        cout<<endl;
        inOrder(T);
        cout<<endl;
        postOrder(T);
        cout<<endl;
    }
    return 1;
}
//前序遍历
void preOrder(Node *T)
{
    cout<<T->c;
    if (T -> lchild != NULL) {
        preOrder(T -> lchild);
    }
    if (T -> rchild != NULL) {
        preOrder(T -> rchild);
    }
}
//中序遍历
void inOrder(Node *T)
{
    if (T -> lchild != NULL) {
        inOrder(T -> lchild);
    }
    cout<<T->c;
    if (T -> rchild != NULL) {
        inOrder(T -> rchild);
    }
}
//后序遍历
void postOrder(Node *T)
{
    if (T -> lchild != NULL) {
        postOrder(T -> lchild);
    }
    if (T -> rchild != NULL) {
        postOrder(T -> rchild);
    }
    cout<<T->c;
}
Node *Insert(Node *T,int x)
{
    if(T==NULL)
    {
        T=creat();
        T->c=x;
        return T;
    }
    else if(x<T->c)
    {
        T->lchild=Insert(T->lchild,x);
    }
    else if(x>T->c)
    {
        T->rchild=Insert(T->rchild,x);
    }
    return T;
}
Node *creat()
{
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}
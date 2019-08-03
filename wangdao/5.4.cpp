#include <iostream>
#define N 10000001
using namespace std;
int Tree[N];
int Sum[N];
int findRoot(int x)
{
    if(Tree[x]==-1)
        return x;
    else
    {
        int tmp=findRoot(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a,b;
        for (int i = 1;i < N;i ++) { //初始化结点信息 
            Tree[i] = -1; //所有结点为孤立集合
            Sum[i] = 1; //所有集合的元素个数为1
        }
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            a=findRoot(a);
            b=findRoot(b);
            if(a!=b)
            {
                Tree[a]=b;
                Sum[b]=Sum[b]+Sum[a];
            }
        }
        int ans=1;
        for(int i=1;i<=N;i++)
        {
            if(Tree[i]==-1&&Sum[i]>ans)
                ans=Sum[i];
        }
        cout<<ans<<endl;
    }
    
}
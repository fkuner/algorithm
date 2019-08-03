#include <iostream>
using namespace std;
int par[101];
int rank1[101];
int main()
{
    
}
//初始化n个元素
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        rank1[i]=0;
    }
}
//查询树的根
int find(int x)
{
    if(par[x]==x)
        return x;
    else
    {
        return find(par[x]);
    }
}

//合并x和y所属的集合
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return ;
    if(rank1[x]<rank1[y])
    {
        par[x]=y;
    }
    else
    {
        par[y]=x;
        if(rank1[x]==rank1[y]) rank1[x]++;
    }
}

//判断x和y是否属于同一个集合
bool same(int x,int y)
{
    return find(x)==find(y);
}

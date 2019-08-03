#include <iostream>
using namespace std;
int N,K; //N代表有N只动物，K代表有K条信息
int par[50001], rank1[50001];
void init(int n);
int find(int x);
void unite(int x,int y);
bool same(int x,int y);
int main()
{
    cin>>N>>K;
    init(N*3);
    int a,b,c;
    int res;
    for(int i=0;i<K;i++)
    {
        cin>>a>>b>>c;
        if(b>N || c>N)
        {
            res++;
        }
        else
        {
            if(a==1)
            {
                if(!same(b,c)&&same(b+N,c+N)&&same(b+2*N,c+2*N))
                    res++;
            }
            else
            {
                
            }
        }
    }
}
void slove()
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
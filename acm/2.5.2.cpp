#include <iostream>
#define INF 100001 
#define MAX_V 20001
using namespace std;
int cost[MAX_V][MAX_V];  //cost[u][v]表示边e=(u,v)的权值
int mincost[MAX_V];     //从集合X出发的边到每个顶点的最小权值
bool used[MAX_V];      //顶点i是否包含在集合X中
int n,m;
int r; //关系的个数
int V; //顶点个数
int prime();
int main()
{
    int a,b,co;
    cin>>n>>m;
    cin>>r;
    V=n+m;
    for(int i=0;i<r;i++)
    {
        cin>>a>>b>>co;
        cost[a][b+n]=-co;
        cost[b+n][a]=-co;
    }
    cout<<10000*(n+m)+prime()<<endl;
    return 0;
}
int prime()
{
    for(int i=0;i<V;i++)
    {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<V;u++)
        {
            if(!used[u] && (v==-1 || mincost[u]<mincost[v]))
                v=u;
        }
        if(v==-1) break;
        used[v]=true;
        res+=mincost[v];
        for(int u=0;u<V;u++)
        {
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
}

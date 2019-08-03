#include <iostream>
#define INF 100001
using namespace std;
int n,l,d;
int dis[1001];
struct edge
{
    int from;
    int to;
    int cost;
};
edge G[20001];
void bellmanFord(int s);
int main()
{
    cin>>n>>l>>d;
    int a,b,cost;
    //建图
    for(int i=0;i<l;i++) //d[AL]+DL >= d[BL]
    {
        cin>>a>>b>>cost;
        G[i].from=a;
        G[i].to=b;
        G[i].cost=cost;
    }
    for(int i=l;i<d+l;i++) //d[AD]+DD <= d[BD]
    {
        cin>>a>>b>>cost;
        G[i].from=b;
        G[i].to=a;
        G[i].cost=-cost;
    }
    for(int i=l+d;i<l+d+n-1;i++)
    {
        G[i].to=i-(l+d-1);
        G[i].from=G[i].to+1;
        G[i].cost=0;
    }
    bellmanFord(1);
    cout<<dis[n]<<endl;
    return 0;
}
void bellmanFord(int s)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
    }
    dis[s]=0;
    while (true)
    {
        bool update=false;
        for(int i=0;i<l+d+n-1;i++)
        {
            edge e=G[i];
            if(dis[e.from]!=INF && dis[e.to] > dis[e.from]+e.cost)
            {
                dis[e.to]=dis[e.from]+e.cost;
                update=true;
            } 
        }
        if(!update)
            break;
    }
}
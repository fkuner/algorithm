#include <iostream>
#include <algorithm>
#include <queue>
#define INF 100001
using namespace std;
int n,r;
int dist1[5001];
int dist2[5001];
struct edge
{
    int to;
    int cost;
};
vector<edge> G[5001];  //邻接链表
typedef pair<int,int> P; //first代表最短距离，second代表结点标号
priority_queue<P,vector<P>,greater<P> > Q;
void dijkstra(int s);
int main()
{
    cin>>n>>r;
    int a,b,cost;
    for(int i=0;i<r;i++)
    {
        cin>>a>>b>>cost;
        edge e1,e2;
        e1.to=b;
        e1.cost=cost;
        e2.to=a;
        e2.cost=cost;
        G[a].push_back(e1);
        G[b].push_back(e2);
    }
    cout<<"test"<<endl;
    dijkstra(1);
    cout<<"最段路径为:"<<endl;
    cout<<dist1[4]<<endl;
    cout<<"次短路径为:"<<endl;
    cout<<dist2[4]<<endl;
    return 0;
}
void dijkstra(int s)
{
    Q.push(P(0,s));
    fill(dist1,dist1+n+1,INF);
    fill(dist2,dist2+n+1,INF);
    dist1[s]=0;
    dist2[s]=0;
    while(!Q.empty())
    {
        P p=Q.top();
        Q.pop();
        int v=p.second;
        int d=p.first;
        if(dist2[v]<d)
            continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            int d2=d+e.cost;
            if(dist1[e.to]>d2)
            {
                dist1[e.to]=d2;
                Q.push(P(dist1[e.to],e.to));
            }
            if(dist2[e.to]>d2 && dist1[e.to]<d2)
            {
                dist2[e.to]=d2;
                Q.push(P(dist2[e.to],e.to));
            }
        }
    }
}

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
struct E
{
    int next;
    int weight;
    int cost;
};
vector<E> edge[1001];
bool mark[1001];
int Dis[1001];
int Cos[1001];

int main()
{
    int n,m;
    int s,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        for(int i=1;i<=n;i++)
            edge[i].clear();
        while(m--)
        {
            int a,b,d,p;
            cin>>a>>b>>d>>p;
            E tmp;
            tmp.next=b;
            tmp.weight=d;
            tmp.cost=p;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        for(int i=1;i<=n;i++)
        {
            Dis[i]=-1;
            //Cos[i]=-1;
            mark[i]=false;
        }
        cin>>s>>t;
        Dis[s]=0;
        //Cos[s]=0;
        mark[s]=true;
        int newP=s;
        //来了老弟，n-1次循环！！
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<edge[newP].size();j++)
            {
                int t=edge[newP][j].next;
                int c=edge[newP][j].weight;
                int s=edge[newP][j].cost;
                if(mark[t]==true) continue;
                if(Dis[t]==-1||Dis[t]>Dis[newP]+c||(Dis[t]==Dis[newP]+c && Cos[t]>Cos[newP]+s))
                {
                    Dis[t]=Dis[newP]+c;
                    Cos[t]=Cos[newP]+s;
                }
            }
            int min=123123123;
            for(int j=1;j<=n;j++)
            {
                if(mark[j]==true) continue;
                if(Dis[j]==-1) continue;
                if(Dis[j]<min)
                {
                    min=Dis[j];
                    newP=j;
                }
            }
            mark[newP]=true;
        }
        cout<<Dis[t]<<" "<<Cos[t]<<endl;
    }
    return 0;
}
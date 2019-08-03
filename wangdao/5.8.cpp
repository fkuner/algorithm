#include <iostream>
#include <vector>
using namespace std;
// 邻接链表中的链表元素结构体
struct  E
{
    int next; //代表直接相邻的结点
    int c; //代表该边的权值
};
vector<E> edge[101];
bool mark[101];
int Dis[101];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        for(int i=1;i<=n;i++)
            edge[i].clear();
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            E tmp;
            tmp.next=b;
            tmp.c=c;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        for(int i=1;i<=n;i++)
        {
            Dis[i]=-1;
            mark[i]=false;
        }
        Dis[1]=0;
        mark[1]=true; //将结点1加入集合K
        int newP=1; //集合K中新加入的点为结点1
        //循环n-1??????? 因为到n-1就已经知道1-n所有点的最短路径
        for(int i=1;i<n;i++) 
        {
            for(int j=0;j<edge[newP].size();j++)
            {
                // if(Dis[j]==-1)
                //     Dis[j]=edge[newP][j].c;
                // if(Dis[j]>Dis[newP]+edge[newP][j].c)
                //     Dis[j]=Dis[newP]+edge[newP][j].c;
                int t=edge[newP][j].next;
                int c=edge[newP][j].c;
                if(mark[t]==true) continue;
                if(Dis[t]==-1||Dis[t]>Dis[newP]+c)
                    Dis[t]=Dis[newP]+c;
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
        cout<<Dis[n]<<endl;
    }
}
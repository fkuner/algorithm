#include <iostream>
#include <math.h>
#define N 101
using namespace std;
int Tree[N];
int findRoot(int x)
{
    if(Tree[x]==-1)
        return x;
    else
    {
        int tmp=findRoot(Tree[x]);
        Tree
        [x]=tmp;
        return tmp;
    }
}
struct Point{
    float x,y;
    float getDistance(Point b)
    {
        float tmp=(x-b.x)*(x-b.x)+(y-b.y)*(y-b.y);
        return sqrt(tmp);
    }
}point[101];
struct Edge{
    int a,b;
    float cost; //该边的权值
    bool operator < (const Edge &A) const{
        return cost<A.cost;
    }
}edge[6000];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int edgeSize=0;
        for(int i=0;i<n;i++)
            cin>>point[i].x>>point[i].y;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                edge[edgeSize].a=i;
                edge[edgeSize].a=j;
                edge[edgeSize++].cost= point[i].getDistance(point[j]);
            }
        for(int i=0;i<N;i++)
            Tree[i]=-1;
        float ans=0.0;
        sort(edge,edge+n*(n-1)/2);
        for(int i=0;i<edgeSize;i++)
        {
            int a=findRoot(edge[i].a);
            int b=findRoot(edge[i].b);
            if(a!=b)
            {
                Tree[a]=b;
                ans+=edge[i].cost;
            }
        }
        printf("%.2lf\n",ans);
    }
    return 1;
}
#include <iostream>
using namespace std;
#define INF 0x7fffffff
struct E{
    int w; //重量
    int v; //价值
}list[501];
int dp[10001];
int min(int a,int b)
{
    return a < b ? a : b;
}
int main()
{
    int T;
    int e,f; //e,f分别为空和满时的重量
    int n;
    cin>>T;
    while(T--)
    {
        cin>>e>>f;
        cin>>n;
        int s=f-e;
        for(int i=0;i<n;i++)
        {
            cin>>list[i].v>>list[i].w;
        }
        for(int i=0;i<=s;i++)
        {
            dp[i]=INF;
        }
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=list[i].w;j<=s;j++)
            {
                if(dp[j-list[i].w]!=INF)
                    dp[j]=min(dp[j],dp[j-list[i].w]+list[i].v);
            }
        }
        if(dp[s]!=INF)
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[s]<<endl;
        else
            cout<<"This is impossible"<<endl;
    }
    return 0;
}
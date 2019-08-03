#include<iostream>
using namespace std;
int tm[101];
int weight[101];
int dp[101][101];
int max(int a,int b)
{
    return a>b ? a:b;
}
int main()
{
    int t,m;
    while(scanf("%d%d",&t,&m)!=EOF)
    {
        for(int i=0;i<m;i++)
        {
            cin>>tm[i]>>weight[i];
        }
        for(int i=0;i<=t;i++)
            dp[0][i]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<=t;j++)
            {
                if(j-tm[i]>=0)
                {
                    dp[i][j]=max(dp[i-1][j-tm[i]]+weight[i],dp[i-1][j]);
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[m][t]<<endl;
    }
}
#include <iostream>
using namespace std;
int max(int a,int b);
void solve_dp();
int n,W;
int w[101],v[101];
int dp[101][10001]; //max[i][j]表示给定重量为j时，挑选前i件，最多的价值

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    cin>>W;
    solve_dp();
}
/////////////穷举
int rec(int i,int j)
{
    int res;
    if(i==n)
        res=0;
    else if(j<w[i]){
        res=rec(i+1,j);
    }
    else{
        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }
    return res;
}
////////////DP
int max(int a,int b)
{
    return a >b ? a:b;
}
void solve_dp()
{
    for(int i=0;i<W;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(j>=w[i])
                dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][W]<<endl;
}
/////////////DP book
void solve_dpbook()
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=W;j++)
        {
            if(j<w[i])
                dp[i][j]=dp[i+1][j];
            else
                dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
        }
    }
}
#include <iostream>
using namespace std;
int list[26]; //按袭击事件顺序保存各导弹高度
int dp[26]; //dp[i]保存以第i个导弹结尾的最长不增子序列长度
int max(int a,int b)
{
    return a > b ? a : b;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>list[i];
        }
        for(int i=1;i<=n;i++)
        {
            int tmax=1;
            for(int j=1;j<i;j++)
            {
                if(list[j]>=list[i])
                {
                    tmax=max(tmax,dp[j]+1);
                }
            }
            dp[i]=tmax;
        }
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
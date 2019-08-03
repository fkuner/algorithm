#include <iostream>
using namespace std;
int max(int a,int b)
{
    return a>b? a:b;
}
int dp[101][101];
int main()
{
    char s1[101],s2[101];
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int l1=strlen(s1);
        int l2=strlen(s2);
        for(int i=0;i<=l1;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=l2;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(s1[i-1]!=s2[j-1])
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                else
                    dp[i][j]=dp[i-1][j-1]+1;
            }
        }
        cout<<dp[l1][l2]<<endl;
    }
}
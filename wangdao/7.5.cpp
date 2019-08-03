#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff
int list[2001]; //表示每件物品的重量
int dp[1001][2001];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>list[i];
        }
        sort(list+1,list+1+n);
        
    }
}
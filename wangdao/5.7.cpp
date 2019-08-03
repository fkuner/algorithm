#include <iostream>
using namespace std;
int ans[101][101]; //二维数组，其初始值即为该图的邻接矩阵
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if (n == 0 && m == 0) break;
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= n;j ++) {
                ans[i][j] = -1; //对邻接矩阵初始化,我们用-1代表无穷
            }           
            ans[i][i] = 0;//自己到自己的路径长度设为0 
        }
        int a,b,c;
        while(m--)
        {
            cin>>a>>b>>c;
            ans[a][b]=ans[b][a]=c;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(ans[i][k]==-1||ans[k][j]==-1) continue;
                    if(ans[i][j]==-1||ans[i][j]>ans[i][k]+ans[k][j])
                        ans[i][j]=ans[i][k]+ans[k][j];
                }
        cout<<ans[1][n]<<endl;
    }
    return 1;
}
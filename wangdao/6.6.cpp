#include <iostream>
using namespace std;
char maze[101][101];
bool mark[101][101];
int convert[8][2]={
    1,0,
    -1,0,
    0,1,
    0,-1,
    1,1,
    -1,1,
    -1,-1,
    1,-1
};
void DFS(int a,int b)
{
    mark[a][b]=true;
    int tmp_x,tmp_y;
    for(int i=0;i<8;i++)
    {
        tmp_x=a+convert[i][0];
        tmp_y=b+convert[i][1];
        if(mark[tmp_x][tmp_y]==false&&maze[tmp_x][tmp_y]=='@')
            DFS(tmp_x,tmp_y);
    }
}
int main()
{
    int m,n;
    int ans=0;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==0) break;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>maze[i][j];
                mark[i][j]=false;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(maze[i][j]=='@'&&mark[i][j]==false)
                {
                    ans++;
                    DFS(i,j);
                }
            }
        }
        cout<<ans<<endl;
    }
}
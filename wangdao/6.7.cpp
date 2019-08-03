#include<iostream>
using namespace std;
char maze[8][8];
int go[4][2]={
    1,0,
    -1,0,
    0,1,
    0,-1
};
bool success;
int m,n,T;
void DFS(int a,int b,int t)
{
    int tmp_x,tmp_y;
    for(int i=0;i<4;i++)
    {
        tmp_x=a+go[i][0];
        tmp_y=b+go[i][1];
        if(maze[tmp_x][tmp_y]=='X') continue;
        if(tmp_x<1||tmp_x>n||tmp_y<1||tmp_y>m) continue;
        if(maze[tmp_x][tmp_y]=='D')
        {
            if(T==t+1)
            {
                success=true;
                return ;
            }
            else continue;
        }
        maze[tmp_x][tmp_y]='X';
        DFS(tmp_x,tmp_y,t+1);
        maze[tmp_x][tmp_y]='.';
        if(success) return ;
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&T))
    {
        if(n==0&&m==0&&T==0) break;
        for(int i=1;i<=n;i++) 
        {
            scanf("%s",maze[i]+1);
        }
        success=false;
        int sx,sy;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(maze[i][j]=='D')
                {
                    sx=i;
                    sy=j;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(maze[i][j]=='S'&&(i+j)%2==((sx+sy)%2+T%2)%2)
                {
                    maze[i][j]='X';
                    DFS(i,j,0);
                }
            }
        }
        puts(success == true? "YES":"NO");
    }
    return 0;
}

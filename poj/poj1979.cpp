#include <iostream>
using namespace std;
int W,H; 
int ans=0;
char maze[21][21];
bool mark[21][21];
int go[4][2]={
    1,0,
    -1,0,
    0,1,
    0,-1
};
void DFS(int x,int y);
int main()
{
    while(scanf("%d%d",&H,&W)!=EOF)
    {
        if(W==0&&H==0) break;
        int tmp_x,tmp_y;
        for(int i=0;i<W;i++)
        {
            for(int j=0;j<H;j++)
            {
                cin>>maze[i][j];
                mark[i][j]=false;
            }
        }
        for(int i=0;i<W;i++)
        {
            for(int j=0;j<H;j++)
            {
                if(maze[i][j]=='@')
                {
                    tmp_x=i;
                    tmp_y=j;
                    mark[i][j]=true;
                }
            }
        }
        DFS(tmp_x,tmp_y);
        cout<<ans<<endl;

    }
    return 0;
}
void DFS(int x,int y)
{
    ans++;
    int nx,ny;
    for(int i=0;i<4;i++)
    {
        nx=x+go[i][0];
        ny=y+go[i][1];

        if(nx<0||nx>=W||ny<0||ny>=H) continue;

        if(mark[nx][ny]==true) continue;


        if(maze[nx][ny]=='#') continue;

        mark[nx][ny] = true;
        DFS(nx,ny);
    }
}
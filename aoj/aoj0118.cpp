#include <iostream>
using namespace std;
char maze[101][101];
bool mark[101][101];
int go[4][2]={
    1,0,
    -1,0,
    0,1,
    0,-1
};
int W,H; //H行W列
void DFS(int x,int y,char c);
int main()
{
    while(scanf("%d%d",&H,&W)!=EOF)
    {
        if(H==0&&W==0)
            break;
        int ans=0;
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                cin>>maze[i][j];
                mark[i][j]=false;
            }
        }
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                if(mark[i][j]==false)
                {
                    ans++;
                    DFS(i,j,maze[i][j]);
                }
            }
        }
        cout<<ans<<endl;
    }  
    return 0;
}
void DFS(int x,int y,char c)
{
    int nx,ny;
    for(int i=0;i<4;i++)
    {
        nx=x+go[i][0];
        ny=y+go[i][1];

        if(nx<0||nx>=W||ny<0||ny>=H) continue;

        if(mark[nx][ny]==true) continue;

        if(maze[nx][ny]!=c) continue;

        mark[nx][ny]=true;
        DFS(nx,ny,c);
    }
}
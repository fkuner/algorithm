#include <iostream>
#include <queue>
#define INF 999999
using namespace std;
int H,W,N; //
char maze[1001][1001]; 
bool mark[1001][1001];
int dp[1001][1001];
typedef pair<int,int> P;
queue<P> Q;
int go[4][2]={
    1,0,
    -1,0,
    0,1,
    0,-1
};
int sx,sy;
int BFS(int x,int y,int n);
int main()
{
    cin>>H>>W>>N;
    int ans=0;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            cin>>maze[i][j];
        }
    }
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(maze[i][j]=='S')
            {
                sx=i;
                sy=j;
                break;
            }
        }
    }
    
    Q.push(make_pair(sx,sy));
    ans+=BFS(sx,sy,1);
    while (!Q.empty()) Q.pop();

    for(int z=1;z<=N-1;z++)
    {
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                if(maze[i][j]==z+'0')
                {
                    Q.push(make_pair(i,j));
                    ans+=BFS(i,j,z+1);
                    while (!Q.empty()) Q.pop();
                }   
            }
        }
    }  
    cout<<ans<<endl; 
}
int BFS(int x,int y,int n)
{
    int tmp_x,tmp_y;
    int nx,ny;
    int res=0;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            //mark[i][j]=false;
            dp[i][j]=INF;
            if(maze[i][j]==n+'0')
            {
                nx=i;
                ny=j;
            }
        }
    }
    dp[x][y]=0;
    while(!Q.empty())
    {
        tmp_x=Q.front().first;
        tmp_y=Q.front().second;
        int tx=tmp_x;
        int ty=tmp_y;
        Q.pop();
        for(int i=0;i<4;i++)
        {
            tmp_x=tx+go[i][0];
            tmp_y=ty+go[i][1];

            if(tmp_x<0 || tmp_x>=H || tmp_y<0 ||tmp_y>=W) continue;

            if(maze[tmp_x][tmp_y]=='X') continue;

            //if(mark[tmp_x][tmp_y]==true) continue;

            if(dp[tmp_x][tmp_y]==INF)
            {
                Q.push(make_pair(tmp_x,tmp_y));
                dp[tmp_x][tmp_y]=dp[tx][ty]+1;
            }
            //mark[tmp_x][tmp_y]=true;
        }
        
    }
    return dp[nx][ny];
}

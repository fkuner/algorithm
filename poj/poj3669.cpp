#include <iostream>
#include <algorithm>
#include <queue>
#define INF 10000001
using namespace std;
int maze[301][301];
int M;
int go[4][2]={
    1,0,
    -1,0,
    0,1,
    0,-1
};
typedef pair<int,int> P;
queue<P> Q;
int dp[301][301];
int BFS();
int main()
{  
    cin>>M;
    int x,y,t;
    int tmp_x,tmp_y;
    int ans;
    for(int i=0;i<300;i++)
        for(int j=0;j<300;j++)
            maze[i][j]=INF;
    for(int i=0;i<M;i++)
    {
        cin>>x>>y>>t;
        maze[x][y]=t;
        for(int i=0;i<4;i++)
        {
            tmp_x=x+go[i][0];
            tmp_y=y+go[i][1];
            if(tmp_x<0 || tmp_x>=300 || tmp_y<0 || tmp_y>=300) continue;
            maze[tmp_x][tmp_y]=min(t,maze[tmp_x][tmp_y]);
        }
    }
    for(int i=0;i<300;i++)
        for(int j=0;j<300;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    Q.push(make_pair(0,0));
    ans=BFS();
    cout<<ans<<endl;
    return 0;
}
int BFS()
{
    if(maze[0][0]==0)
        return -1;
    int tmp_x,tmp_y;
    int tx,ty;
    while(!Q.empty())
    {
        tx=Q.front().first;
        ty=Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++)
        {
            tmp_x=tx+go[i][0];
            tmp_y=ty+go[i][1];

            if(maze[tmp_x][tmp_y]==INF)
            {
                return dp[tx][ty]+1;
            }
            if(tmp_x>=0 && tmp_x<300 && tmp_y>=0 && tmp_y<300 && dp[tx][ty]+1<maze[tmp_x][tmp_y])
            {
                dp[tmp_x][tmp_y]=min(dp[tx][ty]+1,dp[tmp_x][tmp_y]);
                Q.push(make_pair(tmp_x,tmp_y));
            }
        }
    }
    return -1;
}
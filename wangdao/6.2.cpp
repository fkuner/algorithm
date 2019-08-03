#include <iostream>
#include <queue>
using namespace std;
struct N{
    int x,y,z; //位置坐标
    int t; //所需时间
};
int maze[50][50][50];  //迷宫
bool mark[50][50][50]; //标记数组
queue<N> Q; //队列，队列中的元素为状态
int convert[6][3]={
    1,0,0,
    -1,0,0,
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1
};
int BFS(int a,int b,int c);
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,c,t;
        cin>>a>>b>>c>>t;
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                for(int z=0;z<c;z++)
                {
                    cin>>maze[i][j][z];
                    mark[i][j][z]=false;
                }
        while(Q.empty()==false) Q.pop(); //清空队列
        mark[0][0][0]=true;
        N tmp;
        tmp.x=tmp.y=tmp.z=tmp.t=0;
        Q.push(tmp);
        int rec=BFS(a,b,c);
        if(rec<=t) 
            cout<<rec<<endl;
        else 
            cout<<-1<<endl;
    }
    return 1;
}
int BFS(int a,int b,int c)
{
    while(!Q.empty())
    {
        N now=Q.front();
        Q.pop();
        for(int i=0;i<6;i++)
        {
            int nx=now.x+convert[i][0];
            int ny=now.y+convert[i][1];
            int nz=now.z+convert[i][2];
            if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c) continue; //若新坐标在立方体外，则丢弃该坐标
            if(maze[nx][ny][nz]==1) continue; //若该位置为墙，则丢弃该坐标
            if(mark[nx][ny][nz]==true) continue; //若该状态已经得到过，则丢弃该状态
            N tmp;
            tmp.x=nx;
            tmp.y=ny;
            tmp.z=nz;
            tmp.t=now.t+1;
            Q.push(tmp);
            mark[nx][ny][nz]=true;
            if(nx==a-1&&ny==b-1&&nz==c-1)
                return tmp.t;
            
        }

    }
    return -1;
}
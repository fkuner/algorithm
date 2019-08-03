//
//  poj2386.cpp
//  test
//
//  Created by SleEp on 2019/5/14.
//  Copyright © 2019 SleEp. All rights reserved.
//

#include <iostream>
using namespace std;
int go[][2]={
    1,0,
    -1,0,
    0,1,
    0,-1,
    1,1,
    1,-1,
    -1,-1,
    -1,1
};
int n,m;
bool mark[101][101];
char maze[101][101];
void DFS(int a,int b)
{
    for(int i=0;i<8;i++)
    {
        int tmp_x=a+go[i][0];
        int tmp_y=b+go[i][1];
        if(tmp_x<1||tmp_x>n||tmp_y<1||tmp_y>m) continue;
        if(maze[tmp_x][tmp_y]=='W') continue;
        if(mark[tmp_x][tmp_y]==false&&maze[tmp_x][tmp_y]=='.')
        {
            mark[tmp_x][tmp_y]=true;
            DFS(tmp_x, tmp_y);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>maze[i][j];
                mark[i][j]=false;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(maze[i][j]=='.'&&mark[i][j]==false)
                {
                    cnt++;
                    DFS(i,j);
                }
                
            }
        }
        cout<<cnt<<endl;
    }
}

#include <iostream>
using namespace std;
int H,W;
int maze[21][21];
bool mark[21][21];
int go[4][2]={
    1,0,
    -1,0,
    0,1,
    0,-1
};
int sumStep;
int flag;
int sx,sy,ex,ey;
void DFS(int x,int y,int step);
int main()
{
    
    while(scanf("%d%d",&W,&H)!=EOF)
    {
        if(W==0 && H==0)
            break;
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
                if(maze[i][j]==2)
                {
                    sx=i;
                    sy=j;
                    maze[i][j]=0;
                }
                if(maze[i][j]==3)
                {
                    ex=i;
                    ey=j;
                    maze[i][j]=0;
                }
            }
        }
        flag=0;
        sumStep=999999;
        DFS(sx,sy,0);
        if(!flag)
            cout<<-1<<endl;
        else
            cout<<sumStep<<endl;
    }
    return 1;
}
void DFS(int x,int y,int step)
{
    int tmp_x,tmp_y;
    if(step>=10)
        return ;
    for(int i=0;i<4;i++)
    {
        if(!maze[x+go[i][0]][y+go[i][1]])
        {
            tmp_x=x;
            tmp_y=y;   
            while(!maze[tmp_x+go[i][0]][tmp_y+go[i][1]])
            {
                tmp_x+=go[i][0]; //符合条件才加
                tmp_y+=go[i][1];
                
                if(tmp_x==ex && tmp_y==ey)
                {
                    if(sumStep>step+1)
                        sumStep=step+1;
                    flag=1;
                    return ;
                }
                if(tmp_x<0||tmp_x>=H||tmp_y<0||tmp_y>=W)
                    break;
            }
            if(tmp_x>=0 && tmp_x<H && tmp_y>=0 && tmp_y<W && step+1<10)
            {
                maze[tmp_x+go[i][0]][tmp_y+go[i][1]]=0;
                DFS(tmp_x,tmp_y,step+1);
                maze[tmp_x+go[i][0]][tmp_y+go[i][1]]=1;
            }
        }
    }
}
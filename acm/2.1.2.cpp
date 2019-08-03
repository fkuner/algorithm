#include <iostream>
#include <queue>
using namespace std;
char maze[101][101];
bool mark[101][101];
queue<char> Q;
void BFS(int n,int m)
{
    while(!Q.empty())
    {
        
    }
}
int main()
{
    int n,m;
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
    }
}

///////////////////


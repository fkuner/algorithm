#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
set<int> st;
int go[4][2]={
    1,0,
    -1,0,
    0,1,
    0,-1
};
int maze[5][5];
void DFS(int x,int y,int k,int num);
int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            cin>>maze[i][j];
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            DFS(i,j,1,maze[i][j]);
    cout<<st.size()<<endl;
    return 1;
}
void DFS(int x,int y,int k,int num)
{
    int tmp_x,tmp_y;
    if(k==6)
    {
        st.insert(num);
        return ;
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            tmp_x=x+go[i][0];
            tmp_y=y+go[i][1];

            if(tmp_x>=0 && tmp_x<5 && tmp_y>=0 && tmp_y<5)
            {
                k++;
                DFS(tmp_x,tmp_y,k,num*10+maze[tmp_x][tmp_y]);
                k--;
            }    
        }   
    }
}
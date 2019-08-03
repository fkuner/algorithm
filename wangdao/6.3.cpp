#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct N{
    int a,b,c;  //每个杯子中可乐的体积
    int t;  //得到该体积的倾倒次数
};
queue<N> Q; //状态队列
bool mark[101][101][101]; //标记

void Pour(int &a,int sa,int &b,int sb) //a向b倾倒可乐
{
    if(sb-b>=a) //如何b可以全部容纳a中的可乐
    {
        b+=a;
        a=0;
    }
    else
    {
        a=a-(sb-b);
        b=sb;
    }
}
int BFS(int sa,int sb,int sc)
{
    int na,nb,nc;
    while(!Q.empty())
    {
        N tmp=Q.front();
        Q.pop();

        na=tmp.a;
        nb=tmp.b;
        nc=tmp.c;

        //a向b倾倒
        Pour(na,sa,nb,sb); 
        if(mark[na][nb][nc]==false)
        {
            mark[na][nb][nc]=true;
            N n;
            n.a=na;
            n.b=nb;
            n.c=nc;
            n.t=tmp.t+1;
            if(na==sa/2&&nb==sa/2) return n.t;
            if(nb==sa/2&&nc==sa/2) return n.t;
            if(na==sa/2&&nc==sa/2) return n.t;
            Q.push(n);
        }
        na=tmp.a;
        nb=tmp.b;
        nc=tmp.c;   

        //a向c倾倒
        Pour(na,sa,nc,sc); 
        if(mark[na][nb][nc]==false)
        {
            mark[na][nb][nc]=true;
            N n;
            n.a=na;
            n.b=nb;
            n.c=nc;
            n.t=tmp.t+1;
            if(na==sa/2&&nb==sa/2) return n.t;
            if(nb==sa/2&&nc==sa/2) return n.t;
            if(na==sa/2&&nc==sa/2) return n.t;
            Q.push(n);
        }
        na=tmp.a;
        nb=tmp.b;
        nc=tmp.c;

        //b向c倾倒
        Pour(nb,sb,nc,sc); 
        if(mark[na][nb][nc]==false)
        {
            mark[na][nb][nc]=true;
            N n;
            n.a=na;
            n.b=nb;
            n.c=nc;
            n.t=tmp.t+1;
            if(na==sa/2&&nb==sa/2) return n.t;
            if(nb==sa/2&&nc==sa/2) return n.t;
            if(na==sa/2&&nc==sa/2) return n.t;
            Q.push(n);
        }
        na=tmp.a;
        nb=tmp.b;
        nc=tmp.c;

        //c向b倾倒
        Pour(nc,sc,nb,sb); 
        if(mark[na][nb][nc]==false)
        {
            mark[na][nb][nc]=true;
            N n;
            n.a=na;
            n.b=nb;
            n.c=nc;
            n.t=tmp.t+1;
            if(na==sa/2&&nb==sa/2) return n.t;
            if(nb==sa/2&&nc==sa/2) return n.t;
            if(na==sa/2&&nc==sa/2) return n.t;
            Q.push(n);
        }
        na=tmp.a;
        nb=tmp.b;
        nc=tmp.c;

        //b向a倾倒
        Pour(nb,sb,na,sa); 
        if(mark[na][nb][nc]==false)
        {
            mark[na][nb][nc]=true;
            N n;
            n.a=na;
            n.b=nb;
            n.c=nc;
            n.t=tmp.t+1;
            if(na==sa/2&&nb==sa/2) return n.t;
            if(nb==sa/2&&nc==sa/2) return n.t;
            if(na==sa/2&&nc==sa/2) return n.t;
            Q.push(n);
        }
        na=tmp.a;
        nb=tmp.b;
        nc=tmp.c;

        //c向a倾倒
        Pour(nc,sc,na,sa); 
        if(mark[na][nb][nc]==false)
        {
            mark[na][nb][nc]=true;
            N n;
            n.a=na;
            n.b=nb;
            n.c=nc;
            n.t=tmp.t+1;
            if(na==sa/2&&nb==sa/2) return n.t;
            if(nb==sa/2&&nc==sa/2) return n.t;
            if(na==sa/2&&nc==sa/2) return n.t;
            Q.push(n);
            
        }
        na=tmp.a;
        nb=tmp.b;
        nc=tmp.c;
    }
    return -1;
}
int main()
{
    int s,n,m;
    while(scanf("%d%d%d",&s,&n,&m)!=EOF)
    {
        if(s%2!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int z=0;z<m;z++)
                {
                    mark[i][j][z]=false;
                }
            }
        }
        N tmp;
        tmp.a=s;
        tmp.b=0;
        tmp.c=0;
        tmp.t=0;
        while(Q.empty()==false) Q.pop();
        Q.push(tmp);
        mark[s][0][0]=true;
        int res=BFS(s,n,m);
        if(res==-1)
            cout<<"NO"<<endl;
        else
            cout<<res<<endl;
    }
    return 0;
}
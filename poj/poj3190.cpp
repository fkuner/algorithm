#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct Node
{
    int l;
    int r;
    int pos; //属于m段
    bool operator < (Node &a) 
    {
        if(r==a.r)
            return l<a.l;
        return r<a.r;
    }
};
Node cow[50001];
int use[50001];
priority_queue<Node,vector<Node>,greater<Node> > Q;
bool cmp(Node a,Node b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>cow[i].l>>cow[i].r;
            cow[i].pos=i;
        }
        sort(cow,cow+n,cmp);
        Q.push(cow[0]);
        int now=0,ans=1;
        use[cow[0].pos]=1;
        for(int i=1;i<n;i++)
        {
            if(!Q.empty() && Q.top().r<cow[i].l)
            {
                use[cow[i].pos]=use[Q.top().pos];
                Q.pop();
            }
            else
            {
                ans++;
                use[cow[i].pos]=ans;
            }
            Q.push(cow[i]);
        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++)
            cout<<use[i]<<endl;
        while(!Q.empty())
        {
            Q.pop();
        }
    }
    return 1;
}
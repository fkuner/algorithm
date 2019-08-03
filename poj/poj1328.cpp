#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,d=2; //n为岛屿数目，d为雷达覆盖面积
int flag;
struct position{
    int x;
    int y;
};
typedef pair<float,float> P;
P interval[1001];
position island[1001];
bool mark[1001];
float cal(position a);
bool cmp(P a,P b);
int main()
{
    while(cin>>n>>d)
    {
        if(n==0 && d==0) break;
        flag=1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>island[i].x>>island[i].y;
            float x1,x2;
            float tmp=cal(island[i]);
            if(flag==0)
                break;
            x1=tmp-d;
            x2=tmp+d;
            interval[i]=make_pair(x1,x2);
            mark[i]=false;
        }
        if(flag==0)
            cout<<-1<<endl;
        else
        {
            sort(interval,interval+n,cmp);
            for(int i=0;i<n;i++)
            {
                if(mark[i]==true) continue;
                ans++;
                mark[i]=true;
                int tmp=interval[i].second;
                for(int j=i+1;j<n;j++)
                {
                    if(interval[j].first<=tmp)
                        mark[j]=true;
                    else
                        break;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 1; 
}
float cal(position a)
{
    int x=a.x;
    int y=a.y;
    float tmp=pow(d,2)-pow(y,2);
    if(tmp<0)
    {
        flag=0;
        return -1;
    } 
    else
    {
        tmp=sqrt(tmp);
        return x+tmp;
    }
}
bool cmp(P a,P b)
{
    return a.first<b.first;
}
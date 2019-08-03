#include <iostream>
#include <algorithm>
#define INF 10000001
using namespace std;
struct coin{
    int v;
    int b;
};
int n,c; //n为不同面值纸币的数量，c为每周付的最少钱
coin list[25];
int need[25];
bool cmp(coin a, coin b)
{
    return a.v>b.v;
}
int main()
{
    int n,c,i;
    int l;
    
    while(cin>>n>>c)
    {
        int ans=0;
        for(int i=0;i<n;i++)
            cin>>list[i].v>>list[i].b;
        sort(list,list+n,cmp);

        for(i=0;i<n;i++)
        {
            if(list[i].v>=c)
                ans+=list[i].b;
            else
                break;
        }
        if(i==n+1)
        {
            cout<<ans<<endl;
            return 1;
        }
        l=i;
        while(1)
        {
            memset(need,0,sizeof(need));
            int tmp=c;
            for(i=l;i<n;i++)
            {
                need[i]=min(list[i].b,tmp/list[i].v);
                tmp-=need[i]*list[i].v;
            }
            if(tmp>0)
            {
                for(i=n-1;i>=l;i--)
                {
                    if(list[i].b && list[i].v>=tmp)
                    {
                        tmp-=list[i].v;
                        need[i]++;
                        break;
                    }
                }
            }
            if(tmp>0)
                break;
            int t=INF;
            for(i=l;i<n;i++)
            {
                if(need[i])
                    t=min(t,list[i].b/need[i]);
            }
            ans+=t;
            for(i=l;i<n;i++)
            {
                if(need[i])
                    list[i].b-=t*need[i];
            }

        }
        cout<<ans<<endl;
    }
    return 1;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,T; //N为牛的个数，T为时间
typedef pair<int,int> t;
vector<t> list;
bool cmp(t a,t b)
{
    return a.first<b.first;
}
int main()
{
    cin>>N>>T;
    int tmp1,tmp2;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&tmp1);
        scanf("%d",&tmp2);
        list.push_back(make_pair(tmp1,tmp2));
    }
    sort(list.begin(),list.end(),cmp);
    int time=0; //右边界
    int tmp=-1; //最大值
    int ans=0; //答案
    vector<t>::iterator it;
    
    for(it=list.begin();it!=list.end();it++)
    {
        if(it->first>time+1)
        {
            if(tmp==-1)
                break;
            ans++;
            time=tmp;
            tmp=-1;
        }
        if(it->first<=time+1 && it->second>=time+1)
        {
            tmp=max(tmp,it->second);
            if(tmp>=T)
            {
                ans++;
                break;
            }
        }
    }
    if(tmp>=T)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 1;
}

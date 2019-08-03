#include <iostream>
using namespace std;
struct Program{
    int startTime;
    int endTime;
    bool operator <(const Program & A) const{
        return endTime<A.endTime;
    }
}buf[101];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            cin>>buf[i].startTime>>buf[i].endTime;
        }
        sort(buf,buf+n);
        int cnt=1;
        int j=0; //记录最近一次加入的活动
        for(int i=0;i<n;i++)
        {
            if(buf[i].startTime>=buf[j].endTime)
            {
                cnt++;
                j=i;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;
int n,l,p;
int A[1000001];
int B[1000001];
priority_queue<int> Q;
int main()
{
    cin>>n>>l>>p;
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    int ans=0;
    int tmp;
    for(int i=0;i<n;i++)
    {
        if(p>=A[i])
            Q.push(A[i]);
        else
        {
            tmp=Q.top();
            Q.pop();
            p=p+tmp;
            ans++;
            if(p==l)
                break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
////////book
void slove()
{
    A[n]=l;
    B[n]=0;
    // ans: 加油次数，pos：现在所在位置，tank：邮箱中汽油的量
    int ans=0, pos=0,tank=p;
    for(int i=0;i<n;i++)
    {
        //接下来要前进的距离
        int d=A[i]-pos;
        //不断加油直到油量足够行驶到下一个加油站
        while(tank-d<0)
        {
            if(Q.empty())
            {
                puts("-1");
                return ;
            }
            tank +=Q.top();
            Q.pop();
            ans++;
        }
        tank -=d;
        pos=A[i];
        Q.push(B[i]);
    }
    cout<<ans<<endl;
}

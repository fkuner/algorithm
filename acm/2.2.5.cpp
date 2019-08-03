#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > L;
int main()
{
    int n,tmp;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        L.push(tmp);
    }
    while(L.size()!=1)
    {
        int tmp1=L.top();
        L.pop();
        int tmp2=L.top();
        L.pop();
        int tmp3=tmp1+tmp2;
        L.push(tmp3);
        ans+=tmp3;
    }
    cout<<ans<<endl;
}
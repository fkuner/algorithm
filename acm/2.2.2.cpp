#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 100000;
pair<int,int> job[MAX_N];
int n;
void solve()
{
    sort(job,job+n);
    int t=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(t<job[i].second)
        {
            t=job[i].first;
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>job[i].second>>job[i].first;
    }
    solve();
}
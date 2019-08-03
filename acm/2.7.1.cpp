#include <iostream>
using namespace std;
int n;
int v1[1001];
int v2[1001];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    cin>>n;
    long long res=0;
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>v2[i];
    }
    sort(v1,v1+n);
    sort(v2,v2+n,cmp);
    for(int i=0;i<n;i++)
    {
        res+=v1[i]*v2[i];
    }
    cout<<res<<endl;
}
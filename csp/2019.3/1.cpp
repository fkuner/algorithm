#include <iostream>
using namespace std;
long long a[100001];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(a[0]>a[n-1])
    {
        cout<<a[0]<<" ";
        if(n%2==0)
            cout<<(a[n/2]+a[n/2-1])/2.0<<" ";
        else
            cout<<a[n/2]<<" ";
        cout<<a[n-1]<<endl;
    }
    else
    {
        cout<<a[n-1]<<" ";
        if(n%2==0)
            cout<<(a[n/2]+a[n/2-1])/2.0<<" ";
        else
            cout<<a[n/2]<<" ";
        cout<<a[0]<<endl;
    }
    return 0;
}
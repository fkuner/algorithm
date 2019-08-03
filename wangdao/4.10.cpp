#include<iostream>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a==0&&b==0) break;
        int ans=1;
        while(b!=0)
        {
            if(b%2==1){
                ans*=a;
                ans%=1000;
            }
            b/=2;
            a*=a;
            ans%=1000;
        }
        cout<<ans;
    }
    return 1;
}
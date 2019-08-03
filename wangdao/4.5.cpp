#include<iostream>
using namespace std;
int gcd(int a,int b);
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b))
    {
        cout<<a*b/gcd(a,b);
    }
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
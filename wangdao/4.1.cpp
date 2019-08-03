#include<iostream>
using namespace std;
int main()
{
    int a,b;
    int a1[10]={0};
    int b1[10]={0};
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int size1=0,size2=0;
        while(a!=0)
        {
            a1[size1++]=a%10;
            a/=10;
        }
        while(b!=0)
        {
            b1[size2++]=b%10;
            b/=10;
        }
        int ans=0;
        for(int i=0;i<size1;i++)
            for(int j=0;j<size2;j++)
                ans+=a1[i]*b1[j];
        cout<<ans<<endl;
    }
    return 0;
}
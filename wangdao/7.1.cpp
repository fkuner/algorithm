#include <iostream>
using namespace std;
long long F[91];
int main()
{
    F[1]=1;
    F[2]=2;
    for(int i=3;i<=90;i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<F[n]<<endl;
    }
    return 0;
}
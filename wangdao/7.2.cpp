#include <iostream>
using namespace std;
long long F[21];
int main()
{
    F[1]=0;
    F[2]=1;
    for(int i=3;i<=20;i++)
    {
        F[i]=F[i-1]*(i-1)+F[i-2]*(i-1);
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<F[n]<<endl;
    }
}
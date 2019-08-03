// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// bool isPrime(int a);
// void findPrimeRing(int a,int n);
// bool check(int n);
// bool mark[15];
// int cnt=0;
// int ans[15];
// int main()
// {
//     int n;
//     n=6;
//     while(scanf("%d",&n)!=EOF)
//     {
        
//         for(int i=0;i<n;i++)
//             mark[i]=false;
//         mark[1]=true;
        
//         findPrimeRing(1,n);
//     }
// }
// void findPrimeRing(int a,int n)
// {
//     cnt=(cnt+1)%6;
//     for(int i=1;i<=n;i++)
//     {
//         if(mark[i]==false&&isPrime(a+i)==true)
//         {
//             mark[i]=true;
//             findPrimeRing(i,n);
//             ans[cnt]=i;
//         }
//         if(check(n))
//         {
//             for(int i=0;i<n;i++)
//                 cout<<ans[i]<<endl;
//         }
//     }
// }
// bool isPrime(int a)
// {
//     for(int i=2;i<a;i++)
//     {
//         if(a%i==0)
//             return false;
//     }
//     return true;
// }
// bool check(int n)
// {
//     for(int i=1;i<=n;i++)
//     {
//         if(mark[i]==false)
//             return false;
//     }
//     return true;
// }
#include <iostream>
using namespace std;
int ans[22];
bool mark[22];
int n;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
bool judge(int x)
{
    for(int i=0;i<13;i++)
        if(prime[i]==x) return true;
    return false;
}
void check()
{
    if(judge(ans[n]+ans[1])==false) return;
    for(int i=1;i<=n;i++)
    {
        if(i!=1) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
}
void DFS(int num) //递归枚举，num为当前已经放入环中的数字
{
    if(num>1)
        if(judge(ans[num]+ans[num-1])==false) return;
    if(num==n)
    {
        check();
        return ;
    }
    for(int i=2;i<=n;i++)
    {
        if(mark[i] == false)
        {
            mark[i]=true;
            ans[num+1]=i;
            DFS(num+1);
            mark[i]=false;
        }
    }
}
int main()
{
    int cas=0;
    while(scanf("%d",&n)!=EOF)
    {
        cas++;
        for(int i=0;i<22;i++)
        {
            mark[i]=false;
        }
        ans[1]=1;
        cout<<"Case "<<cas<<":"<<endl;
        mark[1]=true;
        DFS(1);
        cout<<endl;
    }
}

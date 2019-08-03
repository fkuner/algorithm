#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// int X[1001];
// bool mark[1001];
// int main()
// {
//     int n,r;
//     int ans=0;
//     cin>>n>>r;
//     for(int i=0;i<n;i++)
//     {
//         cin>>X[i];
//         mark[i]=false;
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(mark[i]==false)
//         { 
//             int flag;
//             for(int j=i;j<n;j++)
//             {
//                 if(X[j]>X[i]+r)
//                 {
//                     flag=j-1;
//                     ans++;
//                     break; 
//                 }
//             }
//             for(int z=i;z<=flag;z++)
//                 mark[z]=true;
//             for(int j=flag+1;j<n;j++)
//             {
//                 if(X[j]<=X[flag]+r)
//                     mark[i]=true;
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

////////////////////////////book
int N,R;
int X[1001];
void solve()
{
    sort(X,X+N);
    int i=0,ans=0;
    while(i<N)
    {
        //s是没有被覆盖的最左的点的位置
        int s=X[i++];
        //一直向右前进直到距s的距离大于R的点
        while(i<N && X[i]<= s+R ) i++;
        //p是新加上标记的点的位置
        int p=X[i-1];
        //一直向右前进直到距p的距离大于R的点
        while(i<N && X[i]<=p+R) i++;
        ans++;
    }
    cout<<ans<<endl;
}




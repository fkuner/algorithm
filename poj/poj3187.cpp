#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int sum;
int a[15];
int cal(int a[],int n);
void assign(int a[],int b[],int n);
int compare(int a[],int b[],int n);
int main()
{
    int tmp[15];
    cin>>N>>sum;
    for(int i=0;i<N;i++)
    {
        tmp[i]=N;
        a[i]=i+1;
    }
    assign(a,tmp,N);
    do{
        assign(a,tmp,N);
        if(cal(tmp,N)==sum)
        {
            for(int i=0;i<N;i++)
                cout<<a[i]<<" ";
            cout<<endl;
            break;
        }  
    }while(next_permutation(a,a+N));
    return 1;
}
int cal(int a1[],int n)
{
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            a1[j]=a1[j]+a1[j+1];
        }
    }
    return a1[0];   
}
void assign(int a1[],int b1[],int n)
{
    for(int i=0;i<n;i++)
        b1[i]=a1[i];
}
int compare(int a1[],int b1[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a1[i]<b1[i])
            return 1;
        if(a1[i]>b1[i])
            return 0;
    }
    return 1;
}

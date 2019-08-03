#include <iostream>
using namespace std;
int prime[1000]; //保存筛得的素数
int primeSize; //保存的素数的个数
bool mark[1001]; //若mark[x]为true，则表示该数x已经被标记为非素数
void init();
int main()
{
    init();
    int n,a;
    while(scanf("%d%d",&n,&a)!=EOF)
    {
        for(int i=0;i<primeSize;i++)
        {
            if(prime[i]<=n){
                while(n/prime[i]!=0)
                {
                    ans+=n/prime[i];
                    
                }
            }

        }
    }
    return 1;
}
void init()
{
    for(int i=2;i<=1000;i++)
        mark[i]=false;
    primeSize=0;
    for(int i=2;i<=1000;i++)
    {
        if(mark[i]==true) continue;
        prime[primeSize++]=i;
        for(int j=i*i;j<=10000;j=j+i)
            mark[j]=true;
    }
}
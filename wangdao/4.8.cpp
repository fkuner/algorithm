#include <iostream>
using namespace std;
int prime[100000]; //保存筛得的素数
int primeSize; //保存的素数的个数
bool mark[100001]; //若mark[x]为true，则表示该数x已经被标记为非素数
void init();
int main()
{ 
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int ansPrime[30]; //按顺序保存分解出的素因数
        int ansSize=0;  //分解出素因数的个数
        int ansNum[30]; //保存分解出的素因数对应的幂指数
        for(int i=0;i<primeSize;i++)
        {
            if(n%prime[i]==0)
            {
                ansPrime[ansSize++]=prime[i];
            }
            int tmp=0;
            while(n%prime[i]==0)
            {
                n=n/prime[i];
                tmp++;
                if(n==1)
                    break;
            }
            ansNum[ansSize++]=tmp;
            if(n==1)
                break;
        }
        if(n!=1)
        {
            ansPrime[ansSize++]=n;
            ansNum[ansSize++]=1;
        }
        int ans=0;
        for(int i=0;i<ansSize;i++)
        {
            ans+=ansNum[i];
        }
        cout<<ans;
    }
    return 1;
}
void init()
{
    for(int i=2;i<=100000;i++)
        mark[i]=false;
    primeSize=0;
    for(int i=2;i<=100000;i++)
    {
        if(mark[i]==true) continue;
        prime[primeSize++]=i;
        if(i>1000) continue;  //若不加这句话，i*i有可能超int范围
        for(int j=i*i;j<=100000;j=j+i)
            mark[j]=true;
    }
}
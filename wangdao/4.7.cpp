#include <iostream>
using namespace std;
int prime[10000]; //保存筛得的素数
int primeSize; //保存的素数的个数
bool mark[10001]; //若mark[x]为true，则表示该数x已经被标记为非素数
void init();
int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        bool isOutput = false; //表示是否输出了符合条件的数字
        for(int i=1;i<primeSize;i++)
        {
            if(prime[i]<n&&prime[i]%10==1)
            {
                if(isOutput==false)
                {
                    isOutput=true;
                    cout<<prime[i];
                }
                else
                {
                    cout<<" "<<prime[i];
                }
            }
        }
        if(isOutput==false)
            cout<<-1<<endl;
        else
            cout<<endl;
    }
    return 1;
}
void init()
{
    for(int i=2;i<=10000;i++)
        mark[i]=false;
    primeSize=0;
    for(int i=2;i<=10000;i++)
    {
        if(mark[i]==true) continue;
        prime[primeSize++]=i;
        for(int j=i*i;j<=10000;j=j+i)
            mark[j]=true;
    }
}
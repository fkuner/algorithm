#include<iostream>
#include<math.h>
using namespace std;
bool judgePrime(int x);
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        if(judgePrime(x))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}
bool judgePrime(int x)
{
    if(x<=1)
        return false;
    int bound=sqrt(x)+1;
    for(int i=2;i<bound;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
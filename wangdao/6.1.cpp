#include <iostream>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<=100;i++) 
        {
            for(int j=0;j<=100-i;j++) //3元小鸡
            {
                int z=100-i-j;
                if(i*5*3+j*3*3+z<=n*3)
                    printf("x=%d,y=%d,z=%d\n",i,j,z);
            }
        }
    }
    return 0;
}
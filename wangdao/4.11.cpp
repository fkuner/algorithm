#include <iostream>
using namespace std;
struct bigInteger{
    int digit[1000];
    int size;
    void init()
    {
        for(int i=0;i<1000;i++)
            digit[i]=0;
        size=0;
    } 
    //从字符串中提取整数
    void set(char str[])
    {
        init();
    }  
};
bigInteger a;
bigInteger b;
int main()
{
    while(scanf("%d%d",a.digit,b.digit)!=EOF)
    {   
        
    }
    return 1;
}
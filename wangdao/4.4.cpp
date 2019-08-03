#include <iostream>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int r=a%b;
        if(a==0&&b==0)
            cout<<"不存在最大公约数";
        else if(a==0||b==0)
            cout<<max(a,b);
        else
        {
            if(a<b)
                swap(a,b);
            while(a%b!=0)
            {
                int temp=a;
                a=b;
                b=temp%b;
            }
            cout<<b;
        } 
    }
}
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
//递归描述
int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);    
}
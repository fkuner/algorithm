#include <iostream>
using namespace std;
int n;
char list[2001];
void solve()
{
    int a=0,b=n-1;
    while(a<=b)
    {
        bool left=false;
        for(int i=0;a+i<=b;i++)
        {
            if(list[a+i] < list[b-i])
            {
                left=true;
                break;
            }
            if(list[a+i] > list[b-i])
            {
                left=false;
                break;
            }
        }
        if(left) putchar(list[a++]);
        else putchar(list[b--]);
    }
    cout<<endl;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>list[i];
    solve();
    return 0;
}
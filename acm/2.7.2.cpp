#include <iostream>
using namespace std;
int a[40][40];
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    return 0;
}
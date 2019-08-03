#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
using namespace std;
int main()
{
    string a;
    string b; //原字符串
    string c; //为了找到小写字符串
    cin>>a;
    while(cin>>b)
    {   
        c=b;
        for(int i=0;i<a.size();i++)
        {
            a[i]=tolower(a[i]);
        }
        for(int i=0;i<c.size();i++)
        {
            c[i]=tolower(c[i]);
        }
        int pos1=c.find(a,0);
        while(pos1!=string::npos)
        {
            b.erase(pos1,a.size());
            c.erase(pos1,a.size());
            pos1=c.find(a,0);
        }
        int pos2=b.find(' ',0);
        while(pos2!=string::npos)
        {
            b.erase(pos2,1);
            pos2=b.find(' ',0);
        }
        cout<<b<<endl;
    }
}
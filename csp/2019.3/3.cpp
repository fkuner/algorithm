#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cstdio>
#include <vector>
#define UP(x) for(uint32_t i=0;i<x;i++)
typedef unsigned int uint32_t;
using namespace std;

uint32_t n,s,l,m; //n表示阵列中硬盘的数目，s表示阵列条带的大小，l表示现存的硬盘数目,m为读取操作的数目
string a[1001]; //表示存放硬盘内容的数组
//set<int> se;
uint32_t convertToNumber(char c);
char convertToChar(uint32_t a);
void yh(string &a,string b);
char getc(char c);
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>s>>l;
    uint32_t tmp;
    uint32_t len;
    uint32_t b[1001];
    for(uint32_t i=0;i<l;i++)
    {
        cin>>tmp;
        //se.insert(tmp);
        cin>>a[tmp];
    }
    for(uint32_t i=0;i<n;i++)
    {
        if(a[i].length()!=0)
        {
            len=a[i].length();
            break;
        }
    }
    cin>>m;
    for(uint32_t i=0;i<m;i++)
        cin>>b[i];
    for(uint32_t i=0;i<m;i++)
    {
        uint32_t p=b[i];
        uint32_t disk,blk,level,curp; //disk代表磁盘号，blk代表磁盘中第几块
        level=p/((n-1)*s);
        curp=(n-level%n)-1;
        blk=level*s+p%s;
        disk=p%((n-1)*s)/s+curp+1;
        disk=disk%n;
        if(len<blk*8+8 || len==0)
        {
            cout<<"-"<<endl;
            continue;
        }
        if(a[disk].length()!=0)
            cout<<a[disk].substr(8*blk,8)<<endl;
        else if(l==n-1 && a[disk].length()==0)
        {
            string str="00000000";
            // char tmp1[9]="00000000";
            // string tmp2;
            // for(int j=0;j<n;j++)
            // {
            //     if(j==disk) continue;
            //     else
            //     {
            //         tmp2=a[j].substr(blk*8,8);
            //         int a,b;
            //         for(int k=0;k<8;k++)
            //         {
            //             a=convertToNumber(tmp1[k]);
            //             b=convertToNumber(tmp2[k]);
            //             tmp1[k]=convertToChar(a^b);
            //         }
            //     }
            // }
            // for(int j=0;j<8;j++)
            //     cout<<tmp1[j];
            // cout<<endl;
            UP(n){
			    if(i!=disk)
			        yh(str,a[i].substr(blk*8,8));
		    }
		    cout<<str<<endl;
        }
        else
           cout<<"-"<<endl;
    }
    return 0;
}
uint32_t convertToNumber(char c)
{
    if(c>='0'&&c<='9')
        return c-'0';
    else if(c>='a' && c<='f')
        return c-'a'+10;
    else
        return c-'A'+10;
}
char convertToChar(uint32_t a)
{
    if(a<10)
        return a+'0';
    else
        return a+'A'-10;
}
void yh(string &a,string b)
{
	UP(8){
		a[i]=getc(getc(a[i])^getc(b[i]));	
	}
}
char getc(char c)
{
	if(c<10)
		return c+'0';
	else if(c<=16)
		return c+'A'-10;
	else if(c<='9')
		return c-'0';
	else if(c<='F')
		return c-'A'+10;
    return 0;
}
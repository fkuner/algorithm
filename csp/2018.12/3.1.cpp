#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
struct IP{
    int ips[4];
    int length;
};
vector<IP> ip(100005);
IP convertToIp(string s);
vector<string> split(const string &str,const string &delim);
int convertToNumber(string s);
bool cmp(IP a,IP b);
bool isSame(IP a,IP b,int length);
bool isUnion(IP a,IP b,IP c);
bool isChild(IP a,IP b);
void display(vector<IP> ip,int n);
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    int l=n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        ip[i]=convertToIp(s);
    }
    sort(ip.begin(),ip.begin()+n,cmp);
    vector<IP>::iterator it;
    
    //第二步：从小到大合并
    int flag1=0;
    for(it=ip.begin();it!=ip.begin()+l;it++)
    {
        if(flag1==1)
        {
            flag1=0;
            it--;
        }
        if(isChild(*it,*(it+1)))
        {
            ip.erase(it+1);
            flag1=1;
            l--;
        } 
    }
    //第三步：同级合并
    int flag;
    it=ip.begin();
    while(it!=ip.begin()+l)
    {
        flag=0;
        if(it->length==(it+1)->length)
        {
            IP tmp;
            tmp=*it;
            tmp.length-=1;
            if(isUnion(tmp,*it,*(it+1)))
            {
                it=ip.insert(it,tmp);
                ip.erase(it+1,it+3);
                l--;
                if(it!=ip.begin())
                    flag=1;
                else
                    flag=2;
            }
        }
        if(l==1)
            break;
        if(flag==1)
            it--;
        else if(flag==0)
            it++;
        else ;
    }
    display(ip,l);
    return 0;
}
void display(vector<IP> ip,int n)
{
    vector<IP>::iterator it;
    for(it=ip.begin();it!=ip.begin()+n;it++)
    {
        cout<<it->ips[0]<<'.'<<it->ips[1]<<'.'<<it->ips[2]<<'.'<<it->ips[3]<<'/'<<it->length<<endl;
    }
}
IP convertToIp(string s)
{
    IP ip;
    int l=s.size();
    int flag=0;
    int pos=s.find('/');
    if(pos!=-1)
    {
        ip.length=convertToNumber(s.substr(pos+1,l-pos));
        s=s.erase(pos,l-pos);
    }
    else
        flag=1;
    vector<string> strVec;
    vector<string>::iterator it;
    strVec=split(s,".");
    int i;
    for(it=strVec.begin(),i=0;it!=strVec.end()&&i<4;it++,i++)
        ip.ips[i]=convertToNumber(*it);
    if(flag==1)
        ip.length=i*8;
    //处理省略后缀型
    for(int j=i;j<4;j++)
        ip.ips[j]=0;
    return ip;
}
int convertToNumber(string s)
{
    int l=s.size();
    int tmp=0;
    for(int i=0;i<l;i++)
    {
        tmp=tmp*10+(s[i]-'0');
    }
    return tmp;
}
vector<string> split(const string &str,const string &delim)
{
    //const char* convert to char*
    char *strc = new char[str.length()+1];
    strcpy(strc,str.c_str());
    vector<string> resVec;
    char *tmpStr=strtok(strc,delim.c_str());
    while(tmpStr!=NULL)
    {
        string tmp=tmpStr;
        resVec.push_back(tmp);
        tmpStr=strtok(NULL,delim.c_str());
    }
    delete[] strc;
    return resVec;
}
bool cmp(IP a,IP b)
{
    for(int i=0;i<4;i++)
    {
        if(a.ips[i]<b.ips[i])
            return true;
        else if(a.ips[i]==b.ips[i])
            continue;
        else
            return false;
    }
    if(a.length<b.length)
        return true;
    else
        return false;
}
//判断b的匹配集是否是a的子集
bool isChild(IP a,IP b)
{
    if(a.length<=b.length)
    {
        if(isSame(a,b,a.length))
            return true;
        else
            return false;
    }
    else
        return false;
}
//judge whether the first length bit is same
bool isSame(IP a,IP b,int length)
{
    bitset<32> bt1,bt2;
    bitset<8> bta[4],btb[4];
    for(int i=0;i<4;i++)
    {
        bta[i]=a.ips[i];
        btb[i]=b.ips[i];
    }
    for(int i=0;i<32;i++)
    {
        bt1[i]=bta[3-i/8][i%8];
        bt2[i]=btb[3-i/8][i%8];
    }
    int i;
    for(i=31;i>=32-length;i--)
    {
        if(bt1[i]!=bt2[i])
            break;
    }
    if(i<=32-length-1)
        return true;
    else
        return false;
}
//判断IP前缀a是否是b和c的并集
bool isUnion(IP a,IP b,IP c)
{
    if(isChild(a,b)&&isChild(a,c))
        return true;
    else
        return false;
}
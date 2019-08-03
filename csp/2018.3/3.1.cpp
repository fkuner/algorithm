#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
typedef pair<vector<string>,string> P;
P p[105];
string str[105];
vector<string> vecStr[105];
vector<string> split(const string &str,const string &delim);
int Judge(string s);
bool isMatch(vector<string> vecStr1,vector<string> vecStr2,int &flag);
void display();
bool hasPath(vector<string> s);
int main()
{
    cin>>n>>m;
    string s1,s2;
    int flag;
    for(int i=0;i<n;i++)
    {
        cin>>s1;
        cin>>s2;
        p[i].first=split(s1,"/");
        p[i].second=s2;
    }
    for(int i=0;i<m;i++)
    {
        string tmp;
        cin>>tmp;
        str[i]=tmp;
        vecStr[i]=split(tmp,"/");
    }
    for(int i=0;i<m;i++)
    {
        flag=0;
        for(int j=0;j<n;j++)
        {
            if(isMatch(vecStr[i],p[j].first,flag))
            {
                flag=1;
                cout<<p[j].second<<' ';
                for(int k=flag;k<p[j].first.size();k++)
                {
                    string tmp=p[j].first[k];
                    if(tmp=="<int>")
                    {
                        int le=vecStr[i][k].length();
                        int z=0;
                        while(z<le)
                        {
                            if(vecStr[i][k][z]=='0') z++;
                            else break;
                        }
                        for(;z<le;z++)
                            cout<<vecStr[i][k][z];
                        cout<<' ';
                    }
                    else if(tmp=="<str>")
                        cout<<vecStr[i][k]<<' ';
                    else
                    {
                        int le=vecStr[i].size();
                        string tmp2="";
                        for(int z=k;z<le;z++)
                        {
                            tmp2+=vecStr[i][z];
                            if(z!=le-1)
                                tmp2+='/';
                        }
                        cout<<tmp2<<' ';
                    }
                }
                cout<<endl;
            }
        }
        if(flag==0)
            cout<<404<<endl;
    }
    return 0;
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
//vecStr1存放映射，vecStr2存放规则
bool isMatch(vector<string> vecStr1,vector<string> vecStr2,int &flag)
{
    int l1=vecStr1.size(); //映射长度 201
    int l2=vecStr2.size(); //规则长度 <int>
    if(!hasPath(vecStr2) && l1!=l2) return false;
    if(hasPath(vecStr2) && l1<=l2) return false;
    int l=min(l1,l2);
    int i;
    for(i=0;i<l;i++)
    {
        string s1=vecStr1[i],s2=vecStr2[i];
        if(s1==s2) continue;
        else
        {
            flag=i;
            if(s2=="<int>" && Judge(s1)==1) continue;
            if(s2=="<str>" && (Judge(s1)==2||Judge(s1)==1)) continue;
            if(s2=="<path>") continue;
            break;
        }
    }
    if(i==l) return true;
    else return false;
}
//如果是int返回1，str返回2，path返回3
int Judge(string s)
{
    int l=s.length();
    int i;
    int flag=0;
    for(i=0;i<l;i++)
    {
        if(s[i]=='/')
        {
            flag=1;
            break;
        }
        if(s[i]>='0' && s[i]<='9')
            continue;
        break;
    }
    if(flag==1) return 3;
    if(i==l)
        return 1;
    else
        return 2;
}
bool hasPath(vector<string> s)
{
	vector<string>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		if(*it=="<path>")
			return true;
	}
	return false;
}
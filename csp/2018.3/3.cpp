#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
bool isMatch(string s1,string s2,vector<string> &query_temp);
bool isInt(string s);
bool isStr(string s);
bool isPath(string s);
bool isNumber(char c);
bool isSame(string s1,string s2);
bool hasPath(vector<string> s);
int main() {
	int n,m,flag;
	cin>>n>>m; 
	getchar();  
	string s1[n];
	string s2[m];
	string s1_temp1;
	string s1_temp2;
	for(int i=0;i<n;i++)
	{
		cin>>s1_temp1;
		cin>>s1_temp2;
//		getline(cin,s1[i]);
		s1[i]=s1_temp1+' '+s1_temp2;
	}
		
	for(int i=0;i<m;i++)
		cin>>s2[i];
		//getline(cin,s2[i]);
	for(int i=0;i<m;i++)
	{
		vector<string> query_temp;
		string string_temp;
		flag=0;
		for(int j=0;j<n;j++)
		{
			vector<string> query;
			char tmp[105];
			int p;
			for(p=0;p<s1[j].length();p++)
			{
				tmp[p]=s1[j][p];
			}
			tmp[p]='\0';
			char *sp=strtok(tmp," ");
			while(sp)
			{
				query.push_back(sp);
				sp=strtok(NULL," ");
			}
			if(isMatch(s2[i],query[0],query_temp))
			{
				string_temp=query[1];
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<string_temp<<" ";
			vector<string>::iterator it;
			for(it=query_temp.begin()+1;it!=query_temp.end();it++)
			{
				cout<<*it<<" ";
			}
			cout<<endl;
		}
		else
			cout<<"404"<<endl;
	}
	return 0;
}
bool isInt(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(!isnumber(s[i]))
			return false;
	}
	return true;
}
bool isStr(string s)
{
	for(int i=0;i<s.size();i++)
		if(s[i]=='/')
			return false;
	return true;
}
bool isPath(string s)
{
	for(int i=0;i<s.size();i++)
		if(s[i]=='/')
			return true;
	return false;
}
bool isNumber(char c)
{
	if(c>=48&&c<=57)
		return true;
	else
		return false;
}
bool isSame(string s1,string s2)
{
	if(s1==s2)
		return true;
	else if(s2=="<int>"&&isInt(s1))
		return true;
	else if(s2=="<path>"&&isPath(s1))
		return true;
	else if(s2=="<str>"&&isStr(s1))
		return true;
	else
		return false;
}
bool isMatch(string s1,string s2,vector<string> &query_temp)
{
	vector<string> query1;
	vector<string> query2;
	char st1[105];
	char st2[105];
	int m;
	int n;
	for(m=0;m<s1.length();m++)
	{
		st1[m]=s1[m];
	}
	st1[m]='\0';
	for(n=0;n<s2.length();n++)
	{
		st2[n]=s2[n];
	}
	st2[n]='\0';
	char *sp1=strtok(st1,"/"); 
	while(sp1)
	{
		query1.push_back(sp1);
		sp1=strtok(NULL,"/");
	}
	int len1=query1.size();
	char *sp2=strtok(st2,"/"); 
	while(sp2)
	{
		query2.push_back(sp2);
		sp2=strtok(NULL,"/");
	}
	int len2=query2.size();
	if((len1==len2)||hasPath(query2))
	{
		int i;
		if(len1==len2)
		{
			query_temp=query1;
			for(i=0;i<len1;i++)
			{
				if(!isSame(query1[i],query2[i]))
					return false;
			}
			return true;
		}
		else
		{
			string s_temp;
			vector<string>::iterator it1;
			vector<string>::iterator it2;
			vector<string>::iterator it_temp;
			it1=query2.begin();
			it2=query1.begin();
			while(it1!=query2.end()&&it2!=query1.end())
			{
				if(*it1=="<path>")
				{
					it_temp=it2;
					break;
				}
				it1++;
				it2++;
			}
			for(;it2!=query1.end();it2++)
			{
				if(it2==query1.end()-1)
					s_temp=s_temp+(*it2);
				else
					s_temp=s_temp+(*it2)+'/';
			}
			query1.erase(it_temp,query1.end());
			query1.insert(it_temp,s_temp);
			query_temp=query1;
			for(i=0;i<len2;i++)
			{
				if(!isSame(query1[i],query2[i]))
					return false;
			}
			return true;
		}
	}
	else
		return false;
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
#include <iostream>
#include <cstring>
#include <math.h>
#include <list>
using namespace std;
typedef struct ip{
	int ip1;
	int ip2;
	int ip3;
	int ip4;
	int length;
}ip;
int string2number(string s);
int isNumber(char c);
void init_ip(ip &ip_temp);
ip string2ip(string s); //输入的字符串转换为结构体
void sort(list<ip> &ip_list); //对IP地址进行排序
int isSmaller(ip ip_temp1,ip ip_temp2);
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	list<ip> ip_list;
	for(int i=0;i<n;i++)
	{
		ip ip_temp;
		string s_temp;
		cin>>s_temp;
		ip_temp=string2ip(s_temp);
		ip_list.push_back(ip_temp);
	}
	sort(ip_list);
		return 0;
}
//219.216.64.118/27
ip string2ip(string s) //输入的字符串转换为结构体
{
	ip ip_temp;
	init_ip(ip_temp);
	string s1,s2,s3,s4,s5;
	int flag=1;
	for(int i=0;i<s.length();i++)
	{
		if(isNumber(s[i]))
		{
			if(flag==1)
				s1=s1+s[i];
			else if(flag==2)
				s2=s2+s[i];
			else if(flag==3)
				s3=s3+s[i];
			else if(flag==4)
				s4=s4+s[i];
			else 
				s5=s5+s[i];
		}
		else if(s[i]=='.')
			flag++;
		else if(s[i]=='/')
			flag=5;
	}
	ip_temp.ip1=string2number(s1);
	ip_temp.ip2=string2number(s2);
	ip_temp.ip3=string2number(s3);
	ip_temp.ip4=string2number(s4);
	ip_temp.length=string2number(s5);
	return ip_temp;
}
int isNumber(char c)
{
	if(c>=48&&c<=57)
		return 1;
	else 
		return 0;
}
int string2number(string s)
{
	int l=s.length();
	int sum=0;
	for(int i=0;i<l;i++)
	{
		sum=sum+(s[i]-48)*pow(10,l-1-i);
	}
	return sum;
}
void init_ip(ip &ip_temp)
{
	ip_temp.ip1=ip_temp.ip2=ip_temp.ip3=ip_temp.ip4=ip_temp.length=0;
}
void sort(list<ip> &ip_list) //对IP地址进行排序
{
	list<ip>::iterator it,it_temp;
	for(it=ip_list.begin();it!=ip_list.end();it++)
	{
		it_temp=it++;
		if(isSmaller(*it, *it_temp)){}
		else
		{
			ip_list.insert(it_temp++,*it);
			ip_list.erase(it);
		} 	
	}
}
int isSmaller(ip ip_temp1,ip ip_temp2)
{
	if(ip_temp1.ip1<ip_temp2.ip2)
		return 1;
	else if(ip_temp1.ip1==ip_temp2.ip1)
	{
		if(ip_temp1.ip2<ip_temp2.ip2)
			return 1;
		else if(ip_temp1.ip2==ip_temp2.ip2)
		{
			if(ip_temp1.ip3<ip_temp2.ip3)
				return 1;
			else if(ip_temp1.ip3==ip_temp2.ip3)
			{
				if(ip_temp1.ip4<ip_temp2.ip4)
					return 1;
				else if(ip_temp1.ip4==ip_temp2.ip4)
				{
					if(ip_temp1.length<ip_temp2.length)
						return 1;
					else
						return 0;
				}
				else 
					return 0;
			}
			else 
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
	
}
//int isMatchSet(ip IP1,ip IP2)
//{
//	
//}
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <utility>
#include <cstdio>
#include <string.h>
using namespace std;
typedef struct Time{
	int year;
	int month;
	int day;
	int hour;
	int second;
}Time;

string month[13]={"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string week[7]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

int string2int(string s)
{
	int tmp;
	for(int i=0;i<s.length();i++)
	{
		tmp=tmp+10*i*s[i];
	}
	return tmp;
}

void splitTime(string s,Time &t)
{
	t.year=s.substr(0,4);
	t.month=s.substr(4,2);
	t.day=s.substr(6,2);
	t.hour=s.substr(8,2);
	t.second=s.substr(10,2);
}

int mymap(int op,string s)
{
	if(op==3)
	{
		for(int i=0;i<13;i++)
		{
			if(strcmp(month[i],s))
				return i;
		}
	}
	else
	{
		for(int i=0;i<7;i++)
		{
			if(strcmp(week[i],s))
				return i;
		}
	}
}

bool isMatch()

vector<pair<int,int> >v[5]; //0-4分别表示 min,h,d,m,w的范围，如果是 * 则用<-1,-1>表示 

void read(string s,int op,vector<pair<int,int> > &v_temp)
{
		
	vector<string> temp;  //保存用,分割后的结果
	string s1,s2;  //保存用-分割后的两端
	//用,分割
	char *sp=strtok(a,",");
	while(sp){
		tmp.push_back(sp);
		sp=strtok(NULL,",");
	}
	//用-分割
	for(int i=0;i<tmp.size();i++)
	{
		int pos=tmp[i].find("-");   //NB
		if(pos==string::npos)
			s1=s2=tmp[i];
		else
		{
			s1=tmp[i].substr(0,pos);
			s2=tmp[i].substr(pos,tmp.size());
		}
		int v1,v2;
		if(op==3||op==4)
		{
			v1=mymap(op,s1);
			v2=mymap(op,s2);
		}
		else
		{
			v1=string2int(s1);
			v2=string2int(s2);
		}
		v_temp.push_back(make_pair(v1,v2));
	}
	
	
}


int main(int argc, char *argv[]) {
	int n;
	string s_temp,e_temp;  //开始时间、结束时间
	string s; //输入配置信息
	Time stime,etime;
	cin>>n;
	cin>>s_temp>>e_temp;
	splitTime(s_temp, stime);
	splitTime(e_temp, etime);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>s;
			if(s=='*')
				v[j].push_back(make_pair(-1, -1))
			else
				read(s,j,v[j]);
		}
		cin>>task;  //任务名
		for(int year=stime.year;year<etime.year;year++)
		{
			for(int month=stime.month;month<etime.month;month++)
			{
				
			}
		}
	}
}
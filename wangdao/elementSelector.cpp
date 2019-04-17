#include <iostream>
#include <cstring>
using namespace std;
bool isIdSelector(string s);
bool isUnbornSelector(string s);
int computeLevel(string s);
class Selector{
public:
	string s;
	int divLevel;
	//<string>list label[10];
};
int main(int argc, char *argv[]) {
	int n,m;
	int current_level=0;
	int current_divlevel=0;
	cin>>n>>m;
	string s1[n];
	string s2[m];
	Selector se[n];
	for(int i=0;i<n;i++)
	{
		cin>>s1[i];
		int tmp=computeLevel(s1[i]);
		if(isUnbornSelector(s1[i])&&(tmp>current_level))
		{
			current_divlevel++;
		}
		else if(isUnbornSelector(s1[i])&&(tmp==current_level-2))
		{
			current_divlevel--;
		}
		else if(isUnbornSelector(s1[i])&&(tmp==current_level-1))
		{
			current_divlevel=current_divlevel;
		}
		else if(tmp<current_divlevel)
		{
			current_divlevel=tmp;
		}
		else
		{
			current_divlevel=current_divlevel;
		}
		se[i].s=s1[i];
		se[i].divLevel=current_divlevel;
	}
	for(int i=0;i<n;i++)
	{
		cout<<se[i].divLevel;
	}
//	for(int i=0;i<m;i++)
//	{
//		cin>>s2[n];
//	}
}
bool isIdSelector(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='#')
			return true;
	}
	return false;
}
bool isUnbornSelector(string s)
{
	string tmp="div";
	int pos=s.find(tmp);
	if(pos!=-1)
		return true;
	else
		return false;
}
int computeLevel(string s)
{
	int cnt;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='.')
			cnt++;
	}
	return cnt/2;
}
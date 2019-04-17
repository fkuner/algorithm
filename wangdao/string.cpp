#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
//		长度：str.length()
//		尺寸：str.size()
//		比较：str1.compare(str2)
//		连接：str1+=str2
//		连接：str1.append(str2)
//		提取：str2=str2.substr(pos1)
//		查找：pos=str1.find(str2)
//		插入：str1.insert(pos1,str2);
//		替换：str1.replace(pos1,str2);
//		删除：str1.erase(pos,len)
//		清除：str.clear()
	
//	string s1,s2;
//	cin>>s1;
//	cin>>s2;
//	int len,where;
//	len=s1.length();
//	len=s1.size();
//	s1.compare(s2);
//	s1.compare(1,2,s2,1,2);
//	s1+=s2;
//	s1.append(s2);
//	s1.append(s2, 1);
//	//字符串搜索
//	where = s1.find(s2);
//	where = s1.find(s2,1);
//	where = s1.rfind(s2);
//	//插入字符串
//	s1.insert(1,s2);
	
	string s1="hello";
	string s2="xf";
	int pos;
	pos=s1.find(s2);
	cout<<pos;
	return 0;
	}
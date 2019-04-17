#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//typedef struct Student{
//		string name;
//		int age;
//		int grade;
//}Student;
//bool cmp(Student a, Student b);
//int main(int argc, char *argv[]) {
//	int N;
//	cin>>N;
//	Student student[N];
//	for(int i=0;i<N;i++)
//	{
//		cin>>student[i].name;
//		cin>>student[i].age;
//		cin>>student[i].grade;
//	}
//	sort(student,student+N,cmp);
//	for(int i=0;i<N;i++)
//	{
//		cout<<student[i].name<<" ";
//		cout<<student[i].age<<" ";
//		cout<<student[i].grade<<" ";
//	}
//}
//bool cmp(Student a, Student b)
//{
//	if(a.grade<b.grade)
//		return true;
//	else if(a.grade==b.grade)
//	{
//		if(a.name[0]<b.name[0])
//			return true;
//		else if(a.name[0]==b.name[0])
//		{
//			if(a.age<b.age)
//				return true;
//			else {
//				return false;
//			}
//		}
//	}
//	else 
//		return false;
//}
struct Student{
char name[101];
int age;
int score;
bool operator < (const Student &b) const{ //利用c++算符重载直接定义小于运算符
	if (score != b.score) return score < b.score;
		int tmp = strcmp(name,b.name);
		if (tmp != 0) return tmp < 0;
		else return age < b.age;
}
}buf[1000];
int main()
{
	int n;
	while (scanf ("%d",&n) != EOF) {
		for (int i = 0;i < n;i ++) {
			scanf ("%s%d%d",buf[i].name,&buf[i].age,&buf[i].score);
		}
		sort(buf,buf + n);
		for (int i = 0;i < n;i ++) {
			printf ("%s %d %d\n",buf[i].name,buf[i].age,buf[i].score);
		}
	}
	return 0; 
}

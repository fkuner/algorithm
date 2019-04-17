#define N 1001
#define M 10001
#include <iostream>

using namespace std;

struct Student{
	int number;
	string name;
	string sex;
	int age;	
}buf[N];
int main(int argc, char *argv[]) {
	int n,m;
	int id[M];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>Student[i].number;
		cin>>Student[i].name;
		cin>>Student[i].sex;
		cin>>Student[i].age;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>id;
	}
	
}
int biSearch(Student)
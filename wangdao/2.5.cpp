#include <iostream>
#include <algorithm>
#include <vector>
#define N 1001
#define M 10001
using namespace std;

struct Student{
	int number;
	string name;
	string sex;
	int age;
};
bool cmp(Student a,Student b);
int biSearch(Student buf[],int number,int n);
int Search(Student buf[],int number,int n);
int main(int argc, char *argv[]) {
	int n,m;
	int id[M];
	Student buf[N];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>buf[i].number;
		cin>>buf[i].name;
		cin>>buf[i].sex;
		cin>>buf[i].age;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>id[i];
	}
	sort(buf,buf+n,cmp);
    for(int i=0;i<m;i++)
	{
		int temp=biSearch(buf,id[i],n);
		if(temp==-1)
			cout<<"No Answer!"<<endl;
		else
        	cout<<buf[temp].number<<" "<<buf[temp].name<<" "<<buf[temp].sex<<" "<<buf[temp].age<<endl;
	}
    return 1;
}
int biSearch(Student buf[],int number,int n)
{
    int right= n-1;
    int left=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(buf[mid].number == number)
            return mid;
        if(buf[mid].number<number)
			left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}
int Search(Student buf[],int number,int n)
{
	for(int i=0;i<n;i++)
	{
		if(buf[i].number==number)
			return i;
	}
	return -1;
}
bool cmp(Student a,Student b)
{
    return a.number<b.number;
}

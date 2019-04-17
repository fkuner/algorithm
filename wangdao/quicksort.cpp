#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	sort(a,a+n); //升序排列
	sort(b,b+n,cmp); //降序排列，sort()函数的重载
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	for(int i=0;i<n;i++)
	{
		cout<<b[i];
	}
}
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	int a[1001];   //不太懂
	int min=10001;
	int tmp;
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			tmp=abs(a[i]-a[j]);
			if(min>tmp)
				min=tmp;
		}
	}
	cout<<min;
}
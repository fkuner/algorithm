#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(i==0)
			b[i]=floor((a[i]+a[i+1])/2);
		else if(i==n-1)
			b[i]=floor((a[i]+a[i-1])/2);
		else
		{
			b[i]=floor((a[i-1]+a[i]+a[i+1])/3);
		}
	}	
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}	
	return 0;
}
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	int a[2000],b[2000],c[2000],d[2000];
	long long time=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	for(int i=0;i<n;i++)
		cin>>c[i]>>d[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(c[j]>=a[i]&&c[j]<=b[i])
			{
				if(d[j]<=b[i])
				{
					time+=d[j]-c[j];
				}
				else
					time+=b[i]-c[j];
			}
			else if(a[i]>c[j]&&a[i]<d[j])
			{
				if(d[j]<=b[i])
					time+=d[j]-a[i];
				else 
					time+=b[i]-a[i];
			}
		}
	}
	cout<<time;
	return 0;
}
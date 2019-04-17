#include <iostream>
using namespace std;
//统计同成绩学生人数
//int main(int argc, char *argv[]) {
//	int n;
//	while(scanf("%d",&n)!=EOF&&n!=0)
//	{
//		int Hash[101]={0};
//		for(int i=0;i<n;i++)
//		{
//			int x;
//			cin>>x;
//			Hash[x]++;
//		}
//		int x;
//		cin>>x;
//		cout<<Hash[x];
//	}
//}

//Sort
int main(int argc, char *argv[])
{
	int a[1000001]={0};
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a[x+500000]=1;
	}
	int cnt=0;
	for(int i=1000000;i>=0;i--)
	{
		if(a[i]==1)
			cout<<i-500000;
	}
	return 0;
}

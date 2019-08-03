#include <iostream>
#include <queue>
using namespace std;
int main() {
	priority_queue<int,vector<int>,greater<int> > Q;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			Q.push(temp);
		}
		int ans=0;
		while(Q.size()>1)
		{
			int a=Q.top();
			Q.pop();
			int b=Q.top();
			Q.pop();
			ans+=a+b;
			Q.push(a+b);
		}
		cout<<ans<<endl;
	}
	return 1;
}
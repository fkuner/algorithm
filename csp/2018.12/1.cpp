#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int r,y,g; //红黄绿灯的时间
	int T=0;
	cin>>r>>y>>g;
	int n,k,t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		cin>>t;
		if(k==0)
			T=T+t;
		else if(k==1)
			T=T+t;
		else if(k==2)
			T=T+t+r;
		else
			T=T;
	}
	cout<<T;
	return 0;
}
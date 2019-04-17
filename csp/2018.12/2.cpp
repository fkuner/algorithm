#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	long long r,y,g; //红黄绿灯的时间
	long long T=0;
	cin>>r>>y>>g;
	long long n;
	cin>>n;
	long long k;
	long long t;
	long long T_temp;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		cin>>t;
		T_temp=T%(r+y+g);
		if(k==0)
			T=T+t;
		else if(k==1)//红灯
		{
			if(T_temp>=0&&T_temp<t) //红灯
				T=T+t-T_temp;
			else if(T_temp>=t&&T_temp<t+g) //绿灯
				T=T;
			else if(T_temp>=t+g&&T_temp<t+g+y) //黄灯
				T=T+t+r+y+g-T_temp;
			else //红灯
				T=T+r+g+y+t-T_temp;
		} 
		else if(k==2) //黄灯
		{
			if(T_temp>=0&&T_temp<t) //黄灯 
				T=T+t+r-T_temp;
			else if(T_temp>=t&&T_temp<t+r) //红灯
				T=T+r+t-T_temp;
			else if(T_temp>=t+r&&T_temp<t+r+g) //绿灯
				T=T;
			else //黄灯
				T=T+r+g+y+t-T_temp+r;
		}
		else //绿灯
		{
			if(T_temp>=0&&T_temp<t) //绿灯
				T=T;
			else if(T_temp>=t&&T_temp<t+y) //黄灯
				T=T+y+t-T_temp+r;
			else if(T_temp>=t+y&&T_temp<t+y+r) //红灯
				T=T+y+r+t-T_temp;
			else //绿灯
				T=T;
		}
	}
	cout<<T;
	return 0;
}
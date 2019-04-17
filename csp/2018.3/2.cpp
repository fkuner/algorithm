//类和结构体数组的定义
#include <iostream>
using namespace std;
//typedef struct ball{
//	int location;
//	int v;
//}a[100];
class ball{
	public:
		int location;
		int v;
};
int main(int argc, char *argv[]) {
	int n,L,t;
	cin>>n>>L>>t;
	ball a[n];
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		a[i].location=tmp;
		a[i].v=1;
	}
	for(int z=1;z<=t;z++)
	{		
		for(int i=0;i<n;i++)
		{
			if(a[i].location==0)
				a[i].location++;
			else if(a[i].location==L)
				a[i].location--;
			else
			{
				int flag=0;
				for(int j=0;j<n;j++)
				{
					if((i!=j)&&(a[i].location==a[j].location))
					{
						a[i].v=-a[i].v;
						a[i].location=a[i].location+a[i].v;
						flag=1;
					}
				}
				if(flag==0)
				{
					a[i].location=a[i].location+a[i].v;
				}
			}
			cout<<a[i].location;
			
		}
	}
	for(int i=0;i<n;i++)
		cout<<a[i].location<<" ";
}

//#include<iostream>
//#include<algorithm>
//#include<map>
// 
//using namespace std;
// 
//const int N=100;
//int a[N];  //记录开始位置 
//int ans[N]; //记录结束位置
//int tmp[N]; //通过 tmp数组使得输入小球的初始位置和最终位置相对应 
// 
//int main()
//{
//	map<int,int>dic;
//	int n,L,t;
//	cin>>n>>L>>t;
//	for(int i=0;i<n;i++){
//		cin>>a[i];
//		tmp[i]=a[i];
//		int temp=a[i]+t;
//		temp=temp%(2*L);
//		if(temp>L)
//		  ans[i]=L-temp%L;
//		else
//		  ans[i]=temp; 
//	}
//	sort(tmp,tmp+n);//对小球的开始位置进行排序 
//	sort(ans,ans+n); //对小球的最后位置进行排序 
//	for(int i=0;i<n;i++)
//		dic[tmp[i]]=i;
//	for(int i=0;i<n;i++)
//		cout<<ans[dic[a[i]]]<<" "; 
//	return 0;
//}

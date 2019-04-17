#include <iostream>
#include <vector>
//#include <map>
using namespace std;
bool isDelete(int a,int k);
int main(int argc, char *argv[]) {
	int n,k;
	int pos=1;
	cin>>n>>k;
	vector<int> a;
	int cnt=1;
	//map<int,int> m;
	for(int i=0;i<n;i++)
	{
		a.push_back(i+1);
		
	}
	vector<int>::iterator it;
	it=a.begin();
	while(a.size()!=1)
	{
		if(isDelete(cnt, k))
		{
			a.erase(it);
			it--;
			//pos--;
		}
		if(it==a.end()-1)
		{
			it=a.begin();
			pos=1;
		}
		else 
		{
			it++;
			pos++;
		}
		cnt++;
	}
	cout<<*it;
}
bool isDelete(int a,int k)
{
	if((a%k==0)||(a%10==k)) //个位数
		return true;
	else
		return false;
}
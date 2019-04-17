#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	int a;
	int tmp;
	int cnt=0;
	int c;
	int i=0;
	while(scanf("%d",&a)!=EOF)
	{
		if(a==0)
		{
			break;
		}
		else if(a==1)
		{
			c=0;
			cnt++;
		}
		else
		{
			if(tmp==0||tmp==1)
			{
				c++;
				cnt=cnt+2;
			}
			else
			{
				c++;
				cnt=cnt+2*c;
			}
		}
		tmp=a;
		i++;
	}
	cout<<cnt;
	return 0;
}
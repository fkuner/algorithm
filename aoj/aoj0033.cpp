#include <iostream>
using namespace std;
int a[11],flag;
void dfs(int x,int l,int r)
{
    if(x==11)
        return ;
    if(flag)
        return ;
    if(a[x]>l)
        dfs(x+1,a[x],r);
    else if(a[x]>r)
        dfs(x+1,l,a[x]);
    else
    {
        flag=1;
        return ;
    }
}
int main()
{
    int T,i,l,r;
    cin>>T;
    while(T--)
    {
        flag=0;
        l=r=0;
        for(int i=1;i<=10;i++)
        {
            cin>>a[i];
        }
        dfs(1,l,r);
        if(flag==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
///////////bitset方法
/*
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
 
	int n;
	cin >> n;
	while (n--)
	{
		int ball[10];
		
		for (int i = 0; i < 10; ++i)
		{
			cin >> ball[i];
		}
 
		bitset<10> direction;
		int all = 1024;
		while (all-- > 0)
		{
			direction = static_cast<bitset<10> >(all);
			bool perfect = true;
			int left = 0;
			int right = 0;
			for (int i = 0; i < 10; ++i)
			{
				if (direction[i])
				{
					if (ball[i] > left)
					{
						left = ball[i];
					}
					else
					{
						perfect = false;
						break;
					}
				}
				else
				{
					if (ball[i] > right)
					{
						right = ball[i];
					}
					else
					{
						perfect = false;
						break;
					}
				}
			}
			if (perfect)
			{
				break;
			}
		}
	
		if (all >= 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
 
	return 0;
}
///////////////////////////End Sub//////////////////////////////////

*/
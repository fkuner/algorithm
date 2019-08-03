#include <iostream>
#include <bitset>
using namespace std;
int r,c;
bitset<10000> cookie[10];
int main()
{
    while(cin>>r>>c)
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int upwards;
                cin>>upwards;
                cookie[i][j]=upwards;
            }
        }
        int R=1<<r; //R为2^r种情况
        int ans=0;
        for(int i=0;i<R;i++)
        {
            int sum=0;
            //翻转
            for(int j=0;j<r;j++)
            {
                if(i & (1<<j))
                    cookie[j].flip();
            }
            //遍历列
            for(int j=0;j<c;j++)
            {
                int tmp=0;
                for(int k=0;k<r;k++)
                {
                    if(cookie[k][j]==1)
                        tmp++;
                }
                sum+=max(tmp,r-tmp);
            }
            ans=max(sum,ans);
            //还原
            for(int j=0;j<r;j++)
            {
                if(i & (1<<j))
                    cookie[j].flip();
            }
        }
        cout<<ans<<endl;
    }
    return 1;
}
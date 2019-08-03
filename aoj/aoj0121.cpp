#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;

map<string,int> dp; //dp保存所有状态的部署
queue<string> Q; //Q为保存状态的队列
int go[4][1]={
    -1,1,-4,4
}; //代表向左，向右、向下、向上
void BFS();
int main()
{
    string s;
    BFS();
    while (getline(cin,s))
    {
        s.erase(remove(s.begin(),s.end(),' '),s.end());
        //remove(s.begin(),s.end(),' ');
        cout<<dp[s]<<endl;
    }
    return 1;    
}
void BFS()
{
    int t1,t2;
    Q.push("01234567");
    dp["01234567"]=0;
    while(!Q.empty())
    {
        string tmp=Q.front();
        string tmp1=tmp;
        Q.pop();
        for(int i=0;i<8;i++)
        {
            if(tmp[i]=='0')
            {
                t1=i;
                break;
            }
        }
        for(int i=0;i<4;i++)
        {
            t2=t1+go[i][0];
            tmp=tmp1;
            if(t2<0 || t2>=8 || (i==1 && t1==3) ||(t1==4 && i==0) ) continue;
            swap(tmp[t1],tmp[t2]);
            if(dp.find(tmp)==dp.end())
            {
                dp[tmp]=dp[tmp1]+1;
                Q.push(tmp);
            }
        }
    }
}
#include <iostream>
#include <map>
using namespace std;
int in[2001];
map<string,int> M;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<2*n;i++)
            in[i]=0;
        M.clear();
        string a;
        string b;
        int idx=0;
        int idxa,idxb;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            //如果映射中没有a
            if(M.find(a)==M.end())
            {
                idxa=idx;
                M[a]=idx++;
            }
            else idxa=M[a];
            if(M.find(b)==M.end())
            {
                idxb=idx;
                M[b]=idx++;
            }
            else idxb=M[b];
            in[idxb]++; //b的入度通知
        }
        int cnt=0;
        for(int i=0;i<idx;i++)
        {
            if(in[i]==0)
                cnt++;
        }
        puts(cnt==1? "YES":"NO");
    }
    return 0;
}
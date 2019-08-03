#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long
const int MAXN = 1e5+5;
char s[20];
struct node{
    ll val,len;
}a[MAXN];
ll pre[5],p[MAXN];
int vis[MAXN];
bool cmp(node a,node b){
    if(a.val==b.val)return a.len<b.len;
    return a.val<b.val;
}
int main(){
    int n;
    pre[0]=1;
    for(int i=1;i<=3;i++){
        pre[i]=pre[i-1]*256ll;
    }
    while(~scanf("%d",&n)){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            int flag=0,pos=3,num=0;
            a[i].len=a[i].val=0;
            int len=strlen(s);
            for(int j=0;j<len;j++){
                if(s[j]=='.')num++;
                if(flag){
                    a[i].len=a[i].len*10+s[j]-'0';
                }
                if(s[j]=='/')flag=1;
            }
            if(!flag){
                a[i].len=(num+1)*8;
            }
            ll temp=0;
            for(int j=0;j<len;j++){
                if(s[j]=='.'){
                    a[i].val+=temp*pre[pos--];
                    temp=0;
                }
                else if(s[j]=='/'){
                    a[i].val+=temp*pre[pos--];
                    break;
                }
                else{
                    temp=temp*10+s[j]-'0';
                    if(j==len-1){
                        a[i].val+=temp*pre[pos--];
                    }
                }
            }
        }
        sort(a+1,a+n+1,cmp);
        int l=1,r=2;
        while(r<=n){
            int len=a[l].len,flag=0;
            for(int i=31;i>=31-len+1;i--){
                ll temp=1ll<<i;
                if((a[l].val&temp)!=(a[r].val&temp)){
                    flag=1;
                    break;
                }
            }
            if(!flag){
                vis[r]=1;
                r++;
            }
            else{
                l=r;
                r++;
            }
        }
        l=1,r;
        while(vis[l]&&l<=n)l++;
        r=l+1;
        while(vis[r]&&r<=n)r++;
        while(r<=n){
            int len=a[l].len,flag=0;
            if(a[l].len!=a[r].len)flag=1;
            for(int i=31;i>31-len+1;i--){
                ll temp=1ll<<i;
                if((a[l].val&temp)!=(a[r].val&temp)){
                    flag=1;
                    break;
                }
            }
            ll temp=1ll<<(31-len+1);
            if((a[l].val&temp)==(a[r].val&temp)){
                flag=1;
            }
            if(!flag){
                a[l].len--;
                a[l].val=0;
                for(int i=31;i>31-len+1;i--){
                    ll temp=1ll<<i;
                    if((a[r].val&temp)){
                        a[l].val+=temp;
                    }
                }
                vis[r]=1;
                int pos=l-1;
                while(pos>=1&&vis[pos])pos--;
                if(pos>=1){
                    r=l;
                    l=pos;
                }
                else{
                    while(vis[r]&&r<=n)r++;
                }
            }
            else{
                l=r;
                r++;
                while(vis[r]&&r<=n)r++;
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            int num=0;
            ll temp=a[i].val;
            for(int j=1;j<=4;j++)p[j]=0;
            while(temp){
                p[++num]=temp%256;
                temp/=256;
            }
            for(int j=4;j>=1;j--){
                printf("%lld%c",p[j],j==1?'/':'.');
            }
            printf("%lld\n",a[i].len);
        }
    }
    return 0;
}
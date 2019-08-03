#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
typedef long long LL;
const int maxn = 500001;
 
struct edge
{
    int u , v , cost;
};
 
int n , m , r;
int x[maxn] , y[maxn] , d[maxn];
 
 
bool cmp(const edge &e1 , const edge &e2)
{
    return e1.cost < e2.cost;
}
 
edge es[maxn];
int V , E;
 
int f[maxn] , rank1[maxn];  //f为并查集数组，rank1为并查集高度
 
void init_union_find(int cnt)
{
    for(int i = 0 ; i <= cnt ; i ++)
    {
        f[i] = i;
        rank1[i] = 0;
    }
}
 
int find(int key)
{
    return f[key] = f[key] == key ? key : find(f[key]);
}
 
void unite(int x , int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
    {
        if(rank1[x] < rank1[y])
        {
            f[x] = y;
        }
        else
        {
            f[y] = x;
            if(rank1[x] == rank1[y])
                rank1[x] ++;
        }
    }
}
 
 
bool same(int x , int y)
{
    return find(x) == find(y);
}
 
 
 
int kruskal()
{
    sort(es , es + E , cmp);
    init_union_find(V);
    int res = 0;
    for(int i = 0 ; i < E ; i ++)
    {
        edge e = es[i];
        if(!same(e.u , e.v))
        {
            unite(e.u , e.v);
            res += e.cost;
        }
    }
    return res;
}
 
void solve()
{
    V = n + m;
    E = r;
    for(int i = 0 ; i < r ; i ++)
    {
        es[i] = (edge){ x[i] , n + y[i] , -d[i] };
    }
    LL res = 10000 * (n + m) + kruskal();
    printf("%lld\n" , res);
}
 
int main()
{
 
    // #ifdef DoubleQ
    // freopen("in.txt" , "r" , stdin);
    // #endif
    int T;
    cin >> T;
    while(T--)
    {
        //cin >> n >> m >> r;
        scanf("%d%d%d" , &n , &m , &r);
        for(int i = 0 ; i < r ; i ++)
        {
            //cin >> x[i] >> y[i] >> d[i];
            scanf("%d%d%d" , &x[i] , &y[i] , &d[i]);
        }
        solve();
    }
    return 0;
}
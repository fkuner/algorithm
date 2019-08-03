#include <iostream>
#define N 101
using namespace std;
//定义数组，用双亲表示法来表示各棵树(所有的集合元素个数总和为N)
int Tree[N];
//查找x所在树的根结点
int findRoot1(int x)
{
    if(Tree[x]==-1)
        return x;
    else
        return findRoot1(Tree[x]);
}
//查找过程中添加路径压缩的优化
int findRoot2(int x)
{
    if(Tree[x]==-1)
        return x;
    else
    {
        int tmp=findRoot2(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}
int main()
{
    
}
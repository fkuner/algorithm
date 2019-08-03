/*
    int t = lower_bound(a+l,a+r,m)-a
    在升序排列的a数组内二分查找[l,r)区间内的值为m的元素。返回m在数组中的下标

    1.如果m在区间中没有出现过，那么返回第一个比m大的数的下标。
    2.如果m比所有区间内的数都大，那么返回r。这个时候会越界，小心。
    3.如果区间内有多个相同的m，返回第一个m的下标。
    4.时间复杂度：一次查询O(log n)，n为数组长度。
*/
#include <iostream>
using namespace std;
int a[1000010],t,n,l,r;
int main()
{
	cin>>t;
	for(int i=0;i<t;i++)
		cin>>a[i];
	for(int i=0;i<t;++i)
	{
		cin>>l>>r>>n;//在[l,r)区间内查找n的位置
		cout<<lower_bound(a+l,a+r,n)-a+1;
	}
	return 0;
}
#include <iostream>
#define ISYEAP(x) (x%100!=0)&&(x%4==0)||(x%400==0) ? 1:0
//定义宏判断是否是闰年
using namespace std;
int dayOfMonth[12][2]={
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
};
class Date{
	
public:	
	int year;
	int month;
	int day;
	void nextDay(){
		day++;
		if(day>dayOfMonth[month][ISYEAP(year)])
		{
			day=1;
			month++;
			if(month>12)
			{
				month=1;
				year++;
			}
		}
	}
};
int buf[5001][13][32];
int main(int argc, char *argv[]) {
	Date tmp;
	int cnt=0;
	tmp.day=1;
	tmp.month=1;
	tmp.year=0;
	while(tmp.year !=5001){
		buf[tmp.year][tmp.month][tmp.day]=cnt;
		tmp.nextDay();
		cnt++;
	}
	int d1,m1,y1;
	int d2,m2,y2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",buf[y2][m2][d2]-buf[y1][m1][d1]+1);
	}
	return 0;
}
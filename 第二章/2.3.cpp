#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

#define ISYEAP(x) x%100 != 0 && x%4 == 0 || x%400 ==0 ? 1 : 0 	//确定 x 是否是闰年 

using namespace std;

int day[13][2]={
		0, 0,
		31, 31,
		28, 29,
		31, 31,
		30, 30,
		31, 31,
		30, 30,
		31, 31,
		31, 31,
		30, 30,
		31, 31,
		30, 30,
		31, 31
	};
struct Date
	{
		int Day;
		int Month;
		int Year;
		void NextDay()			//计算明天的日期 
		{
			Day++;
			if(Day > day[Month][ISYEAP(Day)])
			{
				Day = 1;
				Month++;
				if(Month > 12)
				{
					Year++;
					Month = 1;
				}
			}
			
		}//end NextDay
	};
int buf[5001][13][32];	//大空间的一定要定义为全局变量 

int main()
{
	Date tmp;
	int cnt = 0;
	tmp.Day = 1;
	tmp.Month = 1;
	tmp.Year = 0;
	while(tmp.Year != 5000)		//计算每一天与 0000 年  1 月 1 日相差的天数 
	{
		buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
		tmp.NextDay();
		cnt++;
	}
	int d1, m1, y1, d2, m2, y2;
	while(scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF)  //输入 
	{
		scanf("%4d%2d%2d", &y2, &m2, &d2);
		printf("%d\n",abs(buf[y1][m1][d1] - buf[y2][m2][d2]) + 1);
	}
	
	return 0;
}


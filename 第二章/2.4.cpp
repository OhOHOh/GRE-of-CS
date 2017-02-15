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
char MonthName[13][20] = {
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
char WeekName[7][20] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
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
	int cnt;
	tmp.Day = 1;
	tmp.Month = 1;
	tmp.Year = 0;
	while(tmp.Year != 5001)
	{
		buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
		tmp.NextDay();
		cnt++;
	}
	int y, m, d;
	char s[20];
	while(scanf("%d%s%d", &d, s, &y) != EOF)
	{
		for(m = 0; m < 12; m++)
		{
			if(strcmp(s, MonthName[m]) == 0)
				break;
		}
		int days = buf[y][m][d] - buf[2017][1][1];
		days += 1;
		puts(WeekName[((days%7)+7)%7]);
	}
	
	return 0;
} 


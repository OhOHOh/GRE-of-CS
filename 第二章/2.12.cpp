#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Program
{
	int Ti_s;	//开始时间 
	int Ti_e;	//结束时间 
	bool operator < (const Program &p) const
	{
		return (Ti_e < p.Ti_e);
	}
}buf[20];

int main()
{
	int n, Ti_s, Ti_e;
	while(scanf("%d", &n) != EOF&&n != 0)
	{
		for(int i = 0; i < n; i++)	//输入 
		{
			scanf("%d%d", &buf[i].Ti_s, &buf[i].Ti_e);
		}
		sort(buf, buf+n);
		int currentTime = 0, ans = 0;
		for(int i = 0; i < n; i++)
		{
			if(currentTime <= buf[i].Ti_s)
			{
				currentTime = buf[i].Ti_e;
				ans++;
			}
		}//end for
		printf("%d", ans);
	}//end while
	
	return 0;
}


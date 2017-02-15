#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Goods
{
	double j;	//物品总重 
	double f;	//物品总价值 
	double s;	//物品性价比 
	bool operator < (const Goods &g) const
	{
		return (s < g.s);
	}
}buf[1000];

int main()
{
	int n;		//n种物品 
	double m;   //m元钱
	while(scanf("%d%f", &n, &m) != EOF)
	{
		if(n == -1&&m == -1)
			break;
		for(int i = 0; i < n; i++)
		{
			scanf("%f%f", &buf[i].j, &buf[i].f);
			buf[i].s = buf[i].j / buf[i].f;
		}
		sort(buf, buf+n);
		int idx = 0;			//当前货物下标 
		double ans = 0;			//累加所能得到的能量
		while(m > 0&&idx < n) 
		{
			if(m > buf[idx].f)
			{
				ans += buf[idx].j;
				m -= buf[idx].f;
			}
			else
			{
				ans += buf[idx].j * m /buf[idx].f;
				m = 0;
			}
			idx++;
		} 
		printf("%.3f\n", ans);
	}
	
	
	return 0;
}


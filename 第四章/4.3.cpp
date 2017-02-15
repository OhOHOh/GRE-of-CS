#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	char str[20];
	while(scanf("%d%s%d", &a, str, &b) != EOF)
	{
		int tmp = 0, len = strlen(str), c = 1;//tmp存放10进制的结果 
		for(int i = len - 1; i >= 0; i--)
		{
			int x;
			if(str[i] > '0'&&str[i] < '9')
				x = str[i] - '0';
			else if(str[i] >= 'a'&&str[i] <= 'z')
				x = str[i] - 'a' + 10;
			else
				x = str[i] - 'A' + 10;
			tmp += x*c;
			c *= a;
		}
		char ans[20], size = 0;
		while(tmp != 0)
		{
			int x = tmp % b;
			if(x >= 0&&x <= 9)
				ans[size++] = x + '0';
			else
				ans[size++] = x - 10 + 'A';
			tmp = tmp / b;
		}
		for(int i = size - 1; i >= 0; i--)
		{
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	
	
	return 0;
}


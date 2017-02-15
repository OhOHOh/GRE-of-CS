#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		if(a == 0&&b == 0)
			break;
		int ans = 1;
		while(b != 0)
		{
			if(b%2 == 1)				
			{
				ans = ans * a;
				ans = ans % 1000;
			}
			b = b / 2;
			a = a * a;
			a = a % 1000;
		}//while
		printf("%d\n", ans);
	}
	
	
	return 0;
}


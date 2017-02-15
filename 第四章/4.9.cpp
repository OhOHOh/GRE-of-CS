#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int fac(int n)
{
	if(n == 1)
		return 1;
	else
		return n*fac(n-1);
}

int main()
{
	int n, a, k = 0;
	while(scanf("%d%d", &n, &a) != EOF)
	{
		int tmp = fac(n);// n!
		for(k = 1; k < 10; k++, a = a*a) 
		{
			if(tmp%a == 0&&tmp%(a*a) != 0)
				break;
		}
		printf("%d\n", k);
	}
	
	
	return 0;
}


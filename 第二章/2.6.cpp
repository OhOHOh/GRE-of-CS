#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define OFFSET 500000
int Hash[1000001] = { 0 };

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m))
	{
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", x);
			Hash[x+OFFSET]++;
		}
		for(int i = 1000000; i >= 0&&m >= 0; i--)
		{
			if(Hash[i] != 0)
			{
				printf("%d  ", i-OFFSET);
				m--;
			}
		}//end for
	}
	
	
	return 0;
}


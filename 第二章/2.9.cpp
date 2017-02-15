#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int *data = new int[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &data[i]);
		int x, ans = -1;
		scanf("%d", &x);
		for(int i = 0; i < n; i++)
		{
			if(data[i] == x)
			{
				ans = i ;
				break;
			}//end if
		}//end for
		printf("%d\n", ans);
	}//end while
	
	return 0;
}


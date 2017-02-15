#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int A, B, m;
	while(scanf("%d", &m) != EOF)
	{
		if(m == 0)
			break;
		scanf("%d%d", &A, &B);
		A = A + B;
		int ans[50], size = 0;
		while(A != 0)
		{
			ans[size++] = A % m;
			A = A / m;
		}
		for(int i = size-1; i >= 0; i--)
		{
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}


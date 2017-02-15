#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
	int a, b, result;
	int a1[11], b1[11];
	while(scanf("%d%d", &a, &b) != EOF)
	{
		int result = 0;
		for(int i = 0; i < 11; i++)//2个数组初始化 
		{
			a1[i] = '\0';
			b1[i] = '\0';
		}
		int ka = 0, kb = 0;
		while(a != 0)
		{
			a1[ka++] = a % 10;
			a = a / 10;
		}
		while(b != 0)
		{
			b1[kb++] = b % 10;
			b = b / 10;
		}
		for(int i = 0; a1[i] != '\0'; i++)
		{
			for(int j = 0; b1[j] != '\0'; j++)
			{
				result += a1[i] * b1[j];
			}
		}
		printf("%d\n", result);
	}
	
	return 0;
}


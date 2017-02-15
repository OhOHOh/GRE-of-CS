#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b)//求a, b的最大公约数 
{
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}
int gcd4_6(int a, int b)
{
	int t;
	while(b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		printf("%d\n", gcd4_6(a, b));
	}
	
	return 0;
}


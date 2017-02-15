#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool IsPrime(int a)
{
	if(a == 1)
		return false;
	int bound = (int)sqrt(a) + 1;
	for(int i = 2; i < bound; i++)
	{
		if(a%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{		
		if(IsPrime(n) == true)
			printf("yes\n");
		else
			printf("no\n");
	}
	
	return 0;
}
//puts(IsPrime(n) ? "yes" : "no");

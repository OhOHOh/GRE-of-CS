#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool mark[1010];
int prime[1010];
int primeSize;
void init()
{
	primeSize = 0;
	for(int i = 0; i < 1010; i++)
	{
		mark[i] = false;
		prime[i] = 0;
	}
	for(int i = 2; i < 1010; i++)
	{
		if(mark[i] == true) 
			continue;					
		prime[primeSize++] = i;
		if(i > 100)
			break;
		for(int j = i*i; j < 1000; j += i)
			mark[j] = true;
	}
}
int cnt[1010];
int cnt2[1010];


int main() 
{
	int n, a;
	init();
	while(scanf("%d%d", &n, &a) != EOF)
	{
		for(int i = 0; i < primeSize; i++)
			cnt[i] = cnt2[i] = 0;
		for(int i = 0; i < primeSize; i++)
		{
			int t = n;
			while(t)
			{
				cnt[i] += t / prime[i];
				t = t / prime[i];
			}
		}//for
		int ans = 123123123;
		for(int i = 0; i < primeSize; i++)
		{
			while(a%prime[i] == 0)
			{
				cnt2[i]++;
				a /= prime[i];
			}
			if(cnt2[i] == 0)
				continue;
			if(cnt[i] / cnt2[i] < ans) 
				ans = cnt[i] / cnt2[i];
		}//for
		printf("%d\n", ans);
		
	}
	
	return 0;
}


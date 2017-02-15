#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool mark[100001]; // 标记数组 ，若值为 flase ，则说明对应为素数 
int prime[100001]; // 保存素数 
int primeSize;	   // 素数个数 
void init()
{
	for(int i = 0; i <= 100000; i++)
		mark[i] = false;
	primeSize = 0;
	for(int i = 2; i <= 100000; i++)
	{
		if(mark[i] == true)// i 是合数 
			continue;
		prime[primeSize++] = i;
		if(i >= 1000)
			break;
		for(int j = i * i; j <= 100000; j += i)
		{
			mark[j] = true;
		}
	}	
}


int main()
{
	init();
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int ansPrime[30];	//存放每个素因数 
		int ansSize = 0;	//素因素的个数 
		int ansNum[30];		//每个素因素对应的 幂 
		for(int i = 0; i < primeSize; i++)
		{
			if(n%prime[i] == 0&&n >= prime[i])
			{
				ansPrime[ansSize] = prime[i];
				ansNum[ansSize] = 0;
				while(n%prime[i] == 0)
				{
					ansNum[ansSize]++;
					n /= prime[i];					
				}//while
				ansSize++;
				if(n == 1)
					break;				
			}
		}//for
		if(n != 1)
		{
			ansPrime[ansSize] = n;
			ansNum[ansSize] = 1;
			ansSize++;
		}
		int ans = 0;
		for(int i = 0; i < ansSize; i++)
		{
			//printf("%d^%d\n", ansPrime[i], ansNum[i]);
			ans += ansNum[i];
		}
		
		printf("%d\n", ans);
	}
	
	
	return 0;
}


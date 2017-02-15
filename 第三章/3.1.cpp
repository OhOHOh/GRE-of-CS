#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

stack<int> S;
char str[110];	//输入的数组 
char ans[110];	//保存输出的数组 

int main() 
{
	while(scanf("%s", str) != EOF)
	{
		int i;
		for(i = 0; str[i] != 0; i++)
		{
			if(str[i] == '(')
			{
				S.push('(');
				ans[i] = '(';
			}//if1
			if(str[i] == ')')
			{
				S.pop();
				ans[i] = ')';
			}
		}
		for(i = 0; i < strlen(str); i++)
		{
			if(ans[i] != '('&&ans[i] != ')')
			{
				if(str[i] == '(')
					ans[i] = '$';
				else if(str[i] == ')')
					ans[i] = '?';
				else
					ans[i] = str[i];
			}
		}
		printf("%s", ans);
	}//while
	
	return 0;
}


#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

char str[100];
int mat[][5] = {//优先级矩阵 
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 0, 0, 0, 0,
	1, 1, 1, 0, 0,
	1, 1, 1, 0, 0
};
stack<int> op;			//运算符栈
stack<double> in;		//数字栈
void GetOp(bool &reto, int &retn, int &i) 
//reto 为 true 时，表示该元素为运算符，否则是数字，保存在 retn 中 
{
	if(i == 0&&op.empty() == true)//刚开始访问输入串 
	{
		reto = true;
		retn = 0;
		return;
	}
	if(i == strlen(str))//输入字符串已经访问完 
	{
		reto = true;
		retn = 0;
		return;
	}
	if(str[i] > '0'&&str[i] < '9')//访问位是数字 
	{
		reto = false;
	}//if
	else//访问位是运算符 
	{
		reto = true;
		switch(str[i])
		{
			case '+': {
				retn = 1;
				break;
			}
			case '-': {
				retn = 2;
				break;
			}
			case '*': {
				retn = 3;
				break;
			}
			case '/': {
				retn = 4;
				break;
			}
		}//switch
		i += 2;
		return;
	}//end else
	//以下其实是当访问的是数字的情况下	, 计算连续数字串表示的数值，妙！ 
	retn = 0;
	for(; str[i] != ' '&&str[i] != 0; i++)
	{
		retn *= 10;
		retn += str[i] - '0';
	}
	while(str[i] == ' ')	//连续的数字串之后，是否是空格？ 
		i++;
	return;
}

int main() 
{
	while(gets(str))// while(scanf("%s", str) 不可行 
	{
		if(str[0] == 0&&str[1] == 0)
			break;
		bool retop;
		int retnum, idx = 0;
		while(!op.empty())	//清空符号栈与数字栈 
			op.pop();
		while(!in.empty())
			in.pop();

		while(true)
		{
			GetOp(retop, retnum, idx);
			if(retop == false)
			{
				in.push((double)retnum);
			}//if
			else//当前访问的是 运算符 
			{
				double tmp;
				if(op.empty() == true||mat[retnum][op.top()] == 1)//运算符能否 进栈
				{
					op.push(retnum);
				}
				else//访问的 运算符优先级小 
				{
					while(mat[retnum][op.top()] == 0)// 优先级小于栈顶运算符 
					{
						int ret = op.top();
						op.pop();
						double b = in.top();
						in.pop();
						double a = in.top();
						in.pop();
						switch(ret)
						{
							case 1: {
								tmp = a + b;
								break;
							}
							case 2: {
								tmp = a - b; 
								break;
							}
							case 3: {
								tmp = a * b;
								break;
							}
							case 4: {
								tmp = a / b;
								break;
							}
						}//switch
						in.push(tmp);
					}//while
					op.push(retnum); //将当前的运算符压入栈 
				}//else 访问的 运算符优先级小 
			}//else 当前访问的是 运算符
			if(op.size() == 2&&op.top() == 0)
				break;
		}//while(true) 
		printf("%.2f\n", in.top());		
	}
	
	return 0;
}


#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node
{
	Node *lchild;
	Node *rchild;
	char c;
}Tree[10];
int loc;
Node *creat()
{
	Node *T = new Node;
	T->lchild = NULL;
	T->rchild = NULL;
	T->c = 0;
	return T;
}
/*
Node *Cmpcreat()
{
	Tree[loc].lchild = NULL;
	Tree[loc].rchild = NULL;
	Tree[loc].c = 0;
	return &Tree[loc++];
}
*/
void PreOrder(Node *T, char *tmp, int &i) //前序遍历 
{
	if(T != NULL)
	{
		//printf("%s", T->c);
		tmp[i++] = T->c;
		PreOrder(T->lchild, tmp, i);
		PreOrder(T->rchild, tmp, i);
	}
}
void InOrder(Node *T, char *tmp, int &i) //中序遍历 
{
	if(T != NULL)
	{
		InOrder(T->lchild, tmp, i);
		//printf("%d", T->c);
		tmp[i++] = T->c;
		InOrder(T->rchild, tmp, i);
	}
}
void PostOrder(Node *T, char *tmp, int &i) //后序遍历 
{
	if(T != NULL)
	{
		PostOrder(T->lchild, tmp, i);
		PostOrder(T->rchild, tmp, i);
		//printf("%d", T->c);
		tmp[i++] = T->c;
	}
}
int *Trans(char *tmp) //将字符串转换为 个位数字 
{
	int len = strlen(tmp);
	int *data = new int[len];
	for(int i = 0; i < len; i++)
		data[i] = tmp[i] - '0';
	return data;
}
Node *Insert(Node *T, char x)
{
	if(T == NULL)
	{
		T = creat();
		T->c = x;
		return T;
	}
	else if(T->c < x)
		T->rchild = Insert(T->rchild, x);
	else
		T->lchild = Insert(T->lchild, x);
	
	return T;
}
/*
Node *CmpInsert(Node *T, char x)
{
	if(T == NULL)
	{
		T = Cmpcreat();
		T->c = x;
		return T;
	}
	else if(T->c < x)
		T->rchild = Insert(T->rchild, x);
	else
		T->lchild = Insert(T->lchild, x);
	
	return T;
}
*/
int main()
{
	int n;
	char tmp[11], tmp1[11], tmp2[11];
	char cmp[11], cmp1[11], cmp2[11];
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < 11; i++)
		{
			tmp[i] = '\0';
			tmp1[i] = '\0';
			tmp2[i] = '\0';
		}
		scanf("%s", tmp);
		Node *T = NULL;
		for(int i = 0; i < strlen(tmp); i++)
		{
			T = Insert(T, tmp[i]);
		}
		int m = 0;
		PreOrder(T, tmp1, m);
		m = 0;
		InOrder(T, tmp2, m);
		//printf("Tmp_Pre:%s\nTmp__In:%s\n", tmp1, tmp2);		
		for(int s = 0; s < n; s++)//输入比较的 数列 
		{
			for(int i = 0; i < 11; i++)
			{
				//tmp[i] = '\0';
				cmp[i] = '\0';
				cmp1[i] = '\0';
				cmp2[i] = '\0';
			}
			scanf("%s", cmp);
			Node *T1 = NULL;			
			if(strlen(tmp) != strlen(cmp))
			{
				printf("Nolalala\n");
				continue;
			}
			for(int i = 0; i < strlen(cmp); i++)
			{
				T1 = Insert(T1, cmp[i]);
			}
			m = 0;
			PreOrder(T1, cmp1, m);
			m = 0;
			InOrder(T1, cmp2, m);
			//printf("Cmp_Pre:%s\nCmp__In:%s\n", cmp1, cmp2);
			if(strcmp(tmp1, cmp1)==0&&strcmp(tmp2, cmp2)==0)
				printf("Yes\n");
			else
				printf("No\n");
			//printf("1:%d, 2:%d\n",strcmp(tmp1, cmp1), strcmp(tmp2, cmp2));
		}
		
	}
	
	return 0;
}


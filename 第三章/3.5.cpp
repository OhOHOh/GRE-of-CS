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
	int c;
}Tree[50];
int loc;
Node *creat()
{
	Tree[loc].lchild = NULL;
	Tree[loc].rchild = NULL;
	Tree[loc].c = 0;
	return &Tree[loc++];
}
void PreOrder(Node *T) //前序遍历 
{
	if(T != NULL)
	{
		printf("%d", T->c);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(Node *T) //中序遍历 
{
	if(T != NULL)
	{
		InOrder(T->lchild);
		printf("%d", T->c);
		InOrder(T->rchild);
	}
}
void PostOrder(Node *T) //后序遍历 
{
	if(T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%d", T->c);
	}
}
Node *Insert(Node *T, int x)
{
	if(T == NULL)
	{
		T = creat();
		T->c = x;
		return T;
	}
	if(T->c == x)
		return T;
	else if(T->c > x) //插在左子树 
		T->lchild = Insert(T->lchild, x);
	else
		T->rchild = Insert(T->rchild, x);
	
	return T;
}


int main()
{
	int n, x;
	while(scanf("%d", &n) != EOF)
	{
		loc = 0;
		Node *T = NULL;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			T = Insert(T, x);			
		}	
		PreOrder(T);
		cout <<endl;
		InOrder(T);
		cout <<endl;
		PostOrder(T);
		cout <<endl;	
	}
	
	return 0;
}


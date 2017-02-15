#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Student
{
	char no[10];		//学号 
	char name[20]; 	//姓名	
	char sex[5]; 		//性别 
	int age;			//年龄 
	bool operator < (const Student &A) const 	//重载 " < " 运算符 
	{
		return (strcmp(no, A.no) < 0);
	}
};

int main() 
{
	int n, m;
	while(scanf("%d", &n) != EOF)
	{
		Student *stu = new Student[n];
		for (int  i = 0; i < n; i++)//输入值得注意
		{
			scanf("%s%s%s%d", stu[i].no, stu[i].name, stu[i].sex, &stu[i].age); 
		}
		sort(stu, stu+n);
		scanf("%d", &m);
		int low, high, mid, find;
		char sel[10];
		for(int i = 0; i < m; i++)
		{
			low = 0;
			high = n;
			find = 0;
			scanf("%s", sel);
			 
			{
				mid = (low+high)/2;
				if(strcmp(sel, stu[mid].no) == 0)
				{
					printf("%s	%s	%s	%d\n", stu[i].no, stu[i].name, stu[i].sex, stu[i].age);
					find = 1;
				}//end if
				else if(strcmp(sel, stu[mid].no) > 0)
					low = mid + 1;
				else
					high = mid - 1;
			}
			if(find == 0)
				printf("No Answer!\n");
		}//end for		
	}//end while
	
	return 0;
}


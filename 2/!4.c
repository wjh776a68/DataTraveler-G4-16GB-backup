#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void f4(node* p)
{
	node* initp = p;
	int sum=0;
	if (p->next != NULL)
	{
		p = p->next;

		while (p != NULL)
		{
			p = p->next;
			sum++;
			
		}


	}
	printf("������Ľ��ֵΪ:");
	show(initp);
	printf("������ĳ���Ϊ:%d",sum);
	
}
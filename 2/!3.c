#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void f3(node* p)
{
	node* initp = p;
	node* lp;
	if (p->next != NULL)
	{
		p = p->next;
		
		while (p != NULL)
		{
			lp = p->next;
			free(p);	
			p = lp;
		}
		
		
	}
	printf("������������\n");
	printf("������Ľ��ֵΪ:");
	initp->next = NULL;
	show(initp);
}
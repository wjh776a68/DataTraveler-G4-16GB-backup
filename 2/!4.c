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
	printf("单链表的结点值为:");
	show(initp);
	printf("单链表的长度为:%d",sum);
	
}
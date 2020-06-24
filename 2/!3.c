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
	printf("单链表已销毁\n");
	printf("单链表的结点值为:");
	initp->next = NULL;
	show(initp);
}
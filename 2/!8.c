#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void f8(node* p, int i)
{
	node *initp = p,*tmp;
	int sum = 0;

	if (p->next != NULL)
	{
		p = p->next;

		while (p != NULL && sum + 2 < i)
		{
			p = p->next;
			sum++;
		}
	}

	if (sum + 2 == i)
	{
		tmp = p->next;
		p->next = tmp->next;
		free(tmp);
		printf("单链表的结点值为:");
		show(initp);
		
	}
	else
		printf("error\n");

}
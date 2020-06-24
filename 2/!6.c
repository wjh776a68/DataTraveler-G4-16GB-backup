#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void f6(node* p, int i, int value)
{
	node* initp = p;
	int sum = 0;
	node* newp = (node*)malloc(sizeof(node));

	if (p->next != NULL)
	{
		p = p->next;

		while (p != NULL && sum + 2 < i)
		{
			p = p->next;
			sum++;
		}
	}
	if (sum + 1 <= i)
	{
		newp->data = value;
		newp->next = p->next;
		p->next = newp;
		printf("单链表的结点值为:");
		show(initp);
	}
	else
		printf("error\n");
}
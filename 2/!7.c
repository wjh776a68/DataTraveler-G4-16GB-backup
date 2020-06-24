#include<stdio.h>
#include<stdlib.h>
#include "2.h"
node* f7(node* p, int value)
{
	node* initp = p;
	int sum = 0;

	if (p->next != NULL)
	{
		p = p->next;

		while (p != NULL)
		{
			if (p->data == value)
				break;
			p = p->next;
			sum++;
		}
	}

	if (p->data == value)
	{
		printf("单链表的结点值为:");
		show(initp);
		printf("单链表值为%d的元素为第%d个\n", value, sum+1);
		return p;
	}
	else
	{
		printf("error\n");
		return NULL;
	}
		

}
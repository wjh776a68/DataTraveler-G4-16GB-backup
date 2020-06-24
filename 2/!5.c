#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void f5(node* p,int i)
{
	node* initp = p;
	int sum = 0;

	if (p->next != NULL)
	{
		p = p->next;

		while (p != NULL && sum + 1 < i)
		{
			p = p->next;
			sum++;
		}
	}

	if (sum+1==i)
	{
		printf("单链表的结点值为:");
		show(initp);
		printf("单链表的第%d个元素值为:%d\n", i, p->data);
	}
	else
		printf("error\n");

}
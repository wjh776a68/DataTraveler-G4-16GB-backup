#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void f2(node* p)
{
	node* initp = p;
	int a;
	printf("请输入数字，输入9999结束输入\n");
	while (1)
	{
		scanf_s("%d", &a);

		if (a == 9999)
			break;

		node* newp = (node*)malloc(sizeof(node));
		newp->data = a;
		newp->next = p->next;
		p->next = newp;
	}
	printf("单链表的结点值为:");
	show(initp);
}
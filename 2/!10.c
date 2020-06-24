#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void f10(node* p)
{
	node* p1 = (node*)malloc(sizeof(node));
	node* p2 = (node*)malloc(sizeof(node));
	p1->next = NULL;
	p2->next = NULL;
	node* initp = p;
	node* initp1 = p1;
	node* initp2 = p2;
	while (p != NULL)
	{
		node* newp= (node*)malloc(sizeof(node));
		newp->data = p->data;
		if (p->data % 2 == 1)
		{
			newp->next = p1->next;
			p1->next = newp;
			p1 = p1->next;
		}
		else if (p->data % 2 == 0)
		{
			newp->next = p2->next;
			p2->next = newp;
			p2 = p2->next;
		}
		p = p->next;
	}
	printf("原表元素");
	show(initp);
	printf("原表奇数项元素组成的新表");
	show(initp1);
	printf("原表偶数项元素组成的新表");
	show(initp2);
}
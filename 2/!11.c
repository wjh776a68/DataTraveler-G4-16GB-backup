#include<stdio.h>
#include<stdlib.h>
#include<2.h>

void f11()
{
	node* p1 = (node*)malloc(sizeof(node));
	node* p2 = (node*)malloc(sizeof(node));
	node* p3 = (node*)malloc(sizeof(node));
	p1->next = NULL;
	p2->next = NULL;
	p3->next = NULL;
	printf("ÇëÊäÈëL1\n");
	f1(p1);
	printf("ÇëÊäÈëL2\n");
	f1(p2);
	node *initp1 = p1, *initp2 = p2, *initp3 = p3;
	p1 = p1->next;
	p2 = p2->next;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data == p2->data)
		{
			node* newp = (node*)malloc(sizeof(node));
			newp->data = p1->data;
			newp->next = p3->next;
			p3->next = newp;
			p3 = p3->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->data < p2->data)
		{
			p1 = p1->next;
		}
		else if (p1->data > p2->data)
		{
			p2 = p2->next;
		}

	}
	show(initp1);
	show(initp2);
	show(initp3);
}
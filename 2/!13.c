#include<stdio.h>
#include<stdlib.h>
#include<2.h>

void f13()
{
	node* p1 = (node*)malloc(sizeof(node));
	node* p2 = (node*)malloc(sizeof(node));

	p1->next = NULL;
	p2->next = NULL;

	printf("ÇëÊäÈëL1\n");
	f1(p1);
	printf("ÇëÊäÈëL2\n");
	f1(p2);
	node* initp1 = p1;
	p1 = p1->next;
	while (p1->next != NULL)
		p1 = p1->next;
	p1->next = p2->next;
	free(p2);
	
	show(initp1);
}
#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void f1(node* p)
{
	node *initp = p;
	int a;
	while (p->next != NULL)
	{
		p = p->next;
	}

	printf("���������֣�����9999��������\n");
	while (1)
	{
		scanf_s("%d", &a);

		if (a == 9999)
			break;
		
		node* newp = (node*)malloc(sizeof(node));
		newp->data = a;
		newp->next = p->next;
		p->next = newp;
		p = newp;
	} 
	printf("������Ľ��ֵΪ:");
	show(initp);
}
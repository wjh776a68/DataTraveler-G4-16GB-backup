#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void f2(node* p)
{
	node* initp = p;
	int a;
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
	}
	printf("������Ľ��ֵΪ:");
	show(initp);
}
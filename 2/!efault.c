#include<stdio.h>
#include<stdlib.h>
#include "2.h"
void show(node* p)
{
	if (p->next != NULL&& p != NULL)
	{
		p = p->next;
		while (p != NULL)
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
	printf("\n");
}
	
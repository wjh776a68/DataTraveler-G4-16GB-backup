#include<stdio.h>
#include<stdlib.h>
#include<2.h>

void f12(node* p)
{
	node *tmp,*initp=p;
	p = p->next;
	while (p->next != NULL)
	{
		if (p->data == p->next->data)
		{
			tmp = p->next;
			p->next = tmp->next;
			free(tmp);
		}
		else
			p = p->next;
	}
	show(initp);
}
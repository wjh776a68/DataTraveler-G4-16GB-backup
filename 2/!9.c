#include<stdio.h>
#include<stdlib.h>
#include "2.h"
node* f9(node* p, int value)
{
	node* initp = p;
	node* newp = (node*)malloc(sizeof(node));
	newp->data = value;
	while (p->next != NULL&&value > p->next->data)
	{
		p = p->next;
	}
	if(p->next==NULL)
	{
		newp->next = p->next;
		p->next = newp;
	}
	else
	{
		newp->next = p->next;
		p->next = newp;
	}

	
	show(initp);

}
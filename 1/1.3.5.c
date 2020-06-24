#include<stdio.h>
#include<stdlib.h>
typedef struct slist{
	int data[20];
	int len;
}node;

void addelement(node *p)
{
	int count,i,tmp;
	printf("please input the amount\n");
	scanf("%d",&count);
	
	for(i=0;i<count;i++)
	{
		printf("element%d: ",i);
		scanf("%d",&tmp);
		p->data[i]=tmp;
		p->len++;
		
	}
}

void echo (node *p)
{
	int i;
	for(i=0;i<p->len;i++)
	{
		printf("%d ",p->data[i]);
	}
	printf("\n");
}

void add(node *p,int x)
{
	p->data[p->len]=x;
	p->len++;
}

void divide(node *p,node *p1,node *p2)
{
	int i;
	for(i=0;i<p->len;i++)
	{
		if(i%2==1)
			add(p1,p->data[i]);
		else
			add(p2,p->data[i]);
	}
}

int main()
{
	int i;
	node *p=(node*)malloc(sizeof(node));
	node *p1=(node*)malloc(sizeof(node));
	node *p2=(node*)malloc(sizeof(node));
	p->len=0;
	p1->len=0;
	p2->len=0;
	
	addelement(p);
	
	printf("p: ");
	echo (p);
	printf("p1: ");
	echo (p1);
	printf("p2: ");
	echo (p2);
	
	printf("After dividing\n");
	divide(p,p1,p2);
	
	printf("p: ");
	echo (p);
	printf("p1: ");
	echo (p1);
	printf("p2: ");
	echo (p2);
	
	return 0;
}

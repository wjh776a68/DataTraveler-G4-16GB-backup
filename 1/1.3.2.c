#include<stdio.h>
#include<stdlib.h>
typedef struct slist{
	int data[20];
	int len;
}node;

void echo (node *p)
{
	int i;
	for(i=0;i<p->len;i++)
	{
		printf("%d ",p->data[i]);
	}
	printf("\n");
}

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

void insert(node *p,int pos,int x)
{
	int i;
	if(pos>p->len+1)
	{
		printf("error");
	}		
	else
	{
		for(i=p->len;i>=pos-1;i--)
		{
			p->data[i+1]=p->data[i];
		}
		p->data[pos-1]=x;
		p->len++;
	}
}

int main()
{
	int i,value;
	node *p=(node*)malloc(sizeof(node));
	p->len=0;
	addelement(p);
	echo(p);
	printf("input the position and the value\n");
	scanf("%d %d",&i,&value);
	insert(p,i,value);
	echo(p);
	return 0;
}

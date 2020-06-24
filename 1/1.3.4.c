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
	printf("%d : ",pos);
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

void insertbyorder(node *p,int x)
{
	int i;
	if(p->data[0]>x)
	{
		for(i=p->len;i>=0;i--)
		{
			p->data[i+1]=p->data[i];
		}
		p->data[0]=x;
		p->len++;
	}
	else if(p->data[p->len-1]<x)
	{
		p->data[p->len]=x;
		p->len++;
	}
	else
	{
		for(i=1;i<p->len;i++)
		{
			if(p->data[i-1]<=x&&x<=p->data[i])
			{
				insert(p,i+1,x);
				printf("%d : ",i+1);
				break;
			}
		}
	}
	
}

int main()
{
	int value;
	node *p=(node*)malloc(sizeof(node));
	p->len=0;
	addelement(p);
	echo(p);
	printf("input the value\n");
	scanf("%d",&value);
	insertbyorder(p,value);
	echo(p);
	return 0;
}

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

void delsame(node *p)
{
	int i1,i;
	for(i1=p->len-1;i1>0;i1--)
		if(p->data[i1]==p->data[i1-1])
		{
			for(i=i1;i<p->len+1;i++)
			{			
				p->data[i]=p->data[i+1];
			}
			p->len--;
		}
		
}
int main()
{
	int i;
	node *p=(node*)malloc(sizeof(node));
	p->len=0;
	addelement(p);
	echo (p);
	printf("After delete same value elements\n");
	delsame(p);
	echo(p);
	return 0;
}

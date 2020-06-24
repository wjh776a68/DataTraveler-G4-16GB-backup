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

void same(node *p,node *p1,node *p2)
{
	 int l=0,l1=0,l2=0;
	 while(l<p->len&&l1<p1->len)
	 {
	 
	 	if(p->data[l]<p1->data[l1])
	 		l++;
	 	else if(p->data[l]>p1->data[l1])
	 		l1++;
	 	else if(p->data[l]==p1->data[l1])
	 	{
	 		p2->data[l2]=p->data[l];
			p2->len++;	
			l++;
			l1++;
			l2++;
		}
	 }
}

int main()
{
	int i;
	node *p=(node*)malloc(sizeof(node));
	node *p1=(node*)malloc(sizeof(node));
	
	p->len=0;
	p1->len=0;
	
	addelement(p);
	echo (p);
	addelement(p1);
	echo (p1);

	
	printf("P1 is%s belong to P",same(p,p1)?" ":"n\'t");

	
	return 0;
}

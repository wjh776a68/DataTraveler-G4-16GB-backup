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

void differentandsame(node *p,node *p1,node *p2)
{
	 int l=0,l1=0,l2=0;
	 while(l<p->len&&l1<p1->len)
	 {
	 
	 	if(p->data[l]<p1->data[l1])
	 	{
	 		p2->data[l2]=p->data[l];
			p2->len++;	
			l2++;
	 		l++;
		}	 		
	 	else if(p->data[l]>p1->data[l1])
	 	{
	 		p2->data[l2]=p1->data[l1];
			p2->len++;	
			l2++;
	 		l1++;
		}	 		
	 	else if(p->data[l]==p1->data[l1])
	 	{
	 		p2->data[l2]=p->data[l];
			p2->len++;	
			l++;
			l1++;
			l2++;
		}
	 }
	 if(l!=p->len)
	 {
	 	p2->data[l2]=p->data[l];
		p2->len++;	
		l2++;
	 	l++;
	 }
	 else if(l1!=p1->len)
	 {
	 	p2->data[l2]=p1->data[l1];
		p2->len++;	
		l2++;
	 	l1++;
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
	echo (p);
	addelement(p1);
	echo (p1);
	echo (p2);
	differentandsame(p,p1,p2);
	printf("After finding,p2: ");
	
	echo(p2);
	
	return 0;
}

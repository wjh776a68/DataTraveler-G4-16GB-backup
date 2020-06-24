#include<stdio.h>
#include<stdlib.h>
typedef struct slist{
	int data[20];
	int len;
}node;

node* inital()
{
	node *p=(node*)malloc(sizeof(node));
	p->len=0;
	return p;
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

void different(node *p,node *p1,node *p2)
{
	int l=0,l1=0,l2=0;
	while(l<p->len&&l1<p1->len)
	{
	
	 	if(p->data[l]<p1->data[l1])
	 	{
	 		p2->data[l2]=p->data[l];
			p2->len++;	
			l++;
			l2++;
		}
	 		
	 	else if(p->data[l]>p1->data[l1])
	 	{
	 		p2->data[l2]=p1->data[l1];
			p2->len++;	
	 		l1++;
	 		l2++;
	 	}
	 	else if(p->data[l]==p1->data[l1])
	 	{
	 		
			l++;
			l1++;
			
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
	node *p,*p1,*p2,*p3,*p4;
	p=inital();
	p1=inital();
	p2=inital();
	p3=inital();
	p4=inital();
	addelement(p);
	echo (p);
	addelement(p1);
	echo (p1);
	echo (p2);
	printf("After finding,P3=P1¡ÉP: ");
	same(p,p1,p3);
	echo(p3);
	printf("After finding,P2=P1UP: ");
	differentandsame(p,p1,p2);
	echo(p2);
	printf("After finding,P4=P1-P: ");
	different(p,p1,p4);
	echo(p4);
	
	
	
	return 0;
}

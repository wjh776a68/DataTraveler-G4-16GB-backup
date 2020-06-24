#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#ifndef _3_H_

typedef struct stackblock{
	int data[31];
	int top;
	
}block;

typedef struct stackchain{
	int data;
	struct stackchain *top;
}chain;

void pushblock(block *ablock,int a)
{
	ablock->top++;
	ablock->data[ablock->top]=a;

}

void *pushchain(chain *achain,int a)
{
	chain *newchain=(chain*)malloc(sizeof(chain));
	newchain->data=a;
	newchain->top=achain->top;
	achain->top=newchain;

}


int popblock(block *ablock)
{
	if(ablock->top>-1)
	{
		int returndata=ablock->data[ablock->top];
		ablock->top--;
		return returndata;
		
	}
	else
	{
		return 2;
    } 	
}

int popchain(chain *achain)
{
	if(achain->top!=NULL)
	{
		chain *delchain=achain->top;
		int returndata=delchain->data;
		achain->top=delchain->top;
		free(delchain);
		return returndata;
	}
	else
	{
		return 2;
    } 	
}

int blockempty(block *ablock)   //1 full 0 empty
{
	if(ablock->top>-1)
		return 1;
	else
		return 0;
}

int chainempty(chain *achain)
{
	if(achain->top!=NULL)
		return 1;
	else 
		return 0;
}
void f1()
{
	int a,count=0;
	char hexarray[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	block *p=(block*)malloc(sizeof(block));
	p->top=-1;
	printf("输入数字\n");
	scanf("%d",&a);
	while(a>0)
	{
		count=(count+1)%4;
		pushblock(p,a%2);	
		a=a/2;	
	}
	while(count!=0)
	{
		pushblock(p,0);
		count=(count+1)%4;
	}
	
	//printf("%d %d %d %d//",p->data[4],p->data[5],p->data[6],p->data[7]);
	printf("转化为16进制：\n");

	
	while(blockempty(p))
	{
		char tmp=hexarray[8*popblock(p)+4*popblock(p)+2*popblock(p)+popblock(p)];
		printf("%c",tmp);	
	}
	printf("\n");
}


void f2()
{
	int i=0;
	char string[30]={0};
	block *p=(block*)malloc(sizeof(block));
	p->top=-1;	
	printf("输入一串字符串\n");
	getchar();
	gets(string);
	while(string[i])
	{
		if(string[i]=='{'||string[i]=='['||string[i]=='(')
			pushblock(p,(int)string[i]);	
		else if(string[i]=='}'||string[i]==']'||string[i]==')')
		{
			if(!blockempty(p)||fabs(popblock(p)-(int)string[i])>3)
				break;
		}
		
		i++;
	}
	if(string[i]||blockempty(p))
		printf("不匹配\n");
	else
		printf("匹配\n");
	
}


void f3()
{
	int a,count=0;
	char hexarray[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	chain *p=(chain*)malloc(sizeof(chain));
	p->top=NULL;
	printf("输入数字\n");
	scanf("%d",&a);
	while(a>0)
	{
		count=(count+1)%4;
		pushchain(p,a%2);	
		a=a/2;	
	}
	while(count!=0)
	{
		pushchain(p,0);
		count=(count+1)%4;
	}
	
	
	printf("转化为16进制：\n");
	
	
	while(chainempty(p))
	{
		char tmp=hexarray[8*popchain(p)+4*popchain(p)+2*popchain(p)+popchain(p)];
		printf("%c",tmp);		
	}
	printf("\n");
}
void f4()
{
	int i=0;
	char string[30]={0};
	chain *p=(chain*)malloc(sizeof(chain));
	p->top=NULL;	
	printf("输入一串字符串\n");
	getchar();
	gets(string);
	while(string[i])
	{
		if(string[i]=='{'||string[i]=='['||string[i]=='(')
			pushchain(p,(int)string[i]);	
		else if(string[i]=='}'||string[i]==']'||string[i]==')')
		{
			if(!chainempty(p)||fabs(popchain(p)-(int)string[i])>3)
				break;
		}
		
		i++;
	}
	if(string[i]||chainempty(p))
		printf("不匹配\n");
	else
		printf("匹配\n");
}

#endif

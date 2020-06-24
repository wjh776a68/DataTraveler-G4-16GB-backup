#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	char data[100];
	int front, rear;
}node;


void f1(node **pointer)
{
	free(*pointer);
	*pointer = (node*)malloc(sizeof(node));
	(*pointer)->front = 0;
	(*pointer)->rear = 0;
}

int f2(node *aqueue)
{
	return (aqueue->front == aqueue->rear);
}

int f3(node* aqueue)
{
	return ((aqueue->rear + 1)%100 == aqueue->front);
}

void f4(node* aqueue)
{
	getchar();
	char x[64] = { 0 };
	printf("请输入内容\n");
		if (f3(aqueue) == 0)
		{
			gets(x);
			 if (x[0] == '#')
			{
				int i;
				for (i = 1; i < 100; i++)
				{
					aqueue->data[aqueue->rear] = i;
					aqueue->rear = (aqueue->rear + 1) % 100;
				}
				printf("1-99填充完毕\n");
			}
			else 
			{
				int len = strlen(x),i;
				int tmp = 0,change=0;
				for (i = 0; i <= len; i++)
				{
					if ((x[i] <= 'z' && x[i] >= 'a') || (x[i] <= 'Z' && x[i] >= 'A'))
					{
						aqueue->data[aqueue->rear] = x[i];
						aqueue->rear = (aqueue->rear + 1) % 100;
					}
					else if (x[i] == ' ' || x[i]=='\0')
					{
						if (change == 1)
						{
							aqueue->data[aqueue->rear] = tmp;
							aqueue->rear = (aqueue->rear + 1) % 100;
							tmp = 0;
							change = 0;
						}						
					}
					else if (x[i] <= '9' && x[i] >= '0')
					{
						tmp = 10 * tmp + x[i] - '0';
						change = 1;
					}
				}			
			}		
		}
		else
		{
			printf("队列已满，退出\n");
		}			
	printf("\n");
}

void f5(node* aqueue)
{
	int x,i,c;
	printf("请输入要出队数量\n");
	scanf_s("%d", &x);
	printf("请输入输出格式【char/int】\n");
	scanf_s("%d", &c);
	for (i = 0; i < x;i++)
	{
		if (f2(aqueue) == 0)
		{
			if (c == 1)
			{
				printf("%c ", aqueue->data[aqueue->front]);
			}
			else
				printf("%d ", aqueue->data[aqueue->front]);
			aqueue->front = (aqueue->front + 1) % 100;
		}
		else
		{
			printf("队列已空，退出\n");
			break;
		}
	}
	printf("\n");
}

void f6(node* aqueue)
{
	int c;
	printf("请输入输出格式【char/int】\n");
	scanf_s("%d", &c);
	if (f2(aqueue) == 0)
	{
		if (c == 1)
		{
			printf("%c ", aqueue->data[aqueue->front]);
		}
		else
			printf("%d ", aqueue->data[aqueue->front]);
	}
	else
	{
		printf("队列已空，退出\n");	
	}
	printf("\n");
}

void f7(node* aqueue)
{
	printf("%d\n", (aqueue->rear - aqueue->front + 100) % 100);
}

void f8()
{
	char choice,i;
	node* aqueue=NULL;// = (node*)malloc(sizeof(node));
	node** pointer = &aqueue;
	f1(pointer);
	while (1)
	{
		printf("输入数字以继续\n");
		getchar();
		scanf_s("%c", &choice,1);

		if (choice == '0')
			break;
		else if (choice % 2 == 1)
		{
			if(f3(aqueue)==0)
				aqueue->data[aqueue->rear++] = choice;

		}
		else if (choice % 2 == 0)
		{
			if (f2(aqueue)==0)
				aqueue->front++;
		}
		for (i = (aqueue->front); i != aqueue->rear; i = (i+1) % 100)
		{
			printf("%c ", aqueue->data[i]);		
		}
		printf("\n");
	}
	printf("算法退出\n");
}
#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	char data;
	struct queue* next;
}node;

typedef struct{
	node *front, *rear;
}cmd;

void f1(node* aqueue,cmd* acmd)
{
	aqueue->next = NULL;
	acmd->front = aqueue;
	acmd->rear = aqueue;
}

int f2(node* aqueue, cmd* acmd)
{
	return (acmd->front == acmd->rear);
}



void f4(node* aqueue, cmd* acmd)
{
	getchar();
	char x[64] = { 0 };
	printf("请输入内容\n");
	
		gets(x);
		if (x[0] == '#')
		{
			int i;
			for (i = 1; i < 100; i++)
			{
				acmd->rear->data= i;
				acmd->rear = acmd->rear->next;
			}
			printf("1-99填充完毕\n");
		}
		else
		{
			int len = strlen(x), i;
			int tmp = 0, change = 0;
			for (i = 0; i <= len; i++)
			{
				if ((x[i] <= 'z' && x[i] >= 'a') || (x[i] <= 'Z' && x[i] >= 'A'))
				{
					
					acmd->rear->data = x[i];
					node* new = (node*)malloc(sizeof(node));
					new->next = NULL;
					acmd->rear->next = new;
					acmd->rear = acmd->rear->next;
				}
				else if (x[i] == ' ' || x[i] == '\0')
				{
					if (change == 1)
					{
						acmd->rear->data = tmp;
						node* new = (node*)malloc(sizeof(node));
						new->next = NULL;
						acmd->rear->next = new;
						acmd->rear = acmd->rear->next;
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
	printf("\n");
}

void f5(node* aqueue, cmd* acmd)
{
	int x, i,c;
	printf("请输入要出队数量\n");
	scanf_s("%d", &x);
	printf("请输入输出格式【char/int】\n");
	scanf_s("%d", &c);
	for (i = 0; i < x; i++)
	{
		if (f2(aqueue,acmd) == 0)
		{
			node* dele = acmd->front;
			if (c == 1)
			{
				printf("%c ", acmd->front->data);
			}
			else
			{
				printf("%d ", acmd->front->data);
			}

			acmd->front = acmd->front->next;
			free(dele);
		}
		else
		{
			printf("队列已空，退出\n");
			break;
		}
	}
	printf("\n");
}

void f6(node* aqueue, cmd* acmd)
{
	int c;
	printf("请输入输出格式【char/int】\n");
	scanf_s("%d", &c);
	if (f2(aqueue,acmd) == 0)
	{
		if (c == 1)
		{
			printf("%c ", acmd->front->data);
		}
		else
		{
			printf("%d ", acmd->front->data);
		}
	}
	else
	{
		printf("队列已空，退出\n");
	}
	printf("\n");
}

void f7(node* aqueue, cmd* acmd)
{
	int sum = 0;
	while (acmd->front != acmd->rear)
	{
		sum++;
		acmd->front = acmd->front->next;
	}
		
	printf("%d\n", sum);
}

void f8()
{
	char choice, i;
	node* aqueue = (node*)malloc(sizeof(node));
	cmd* acmd = (cmd*)malloc(sizeof(cmd));
	f1(aqueue,acmd);
	while (1)
	{
		printf("输入数字以继续\n");
		getchar();
		scanf_s("%c", &choice, 1);

		if (choice == '0')
			break;
		else if (choice % 2 == 1)
		{
			//if (f3(aqueue) == 0)
				acmd->rear->data = choice;
				node* new = (node*)malloc(sizeof(node));
				//new->data = choice;
				new->next = NULL;
				acmd->rear->next = new;
				acmd->rear = acmd->rear->next;

		}
		else if (choice % 2 == 0)
		{
			if (f2(aqueue, acmd) == 0)
			{
				node* dele = acmd->front;
				acmd->front = acmd->front->next;
				free(dele);
			}
				
		}
		node* p;
		for (p = (acmd->front); p != acmd->rear; p=p->next)
		{
			printf("%c ", p->data);
		}
		printf("\n");
	}
	printf("算法退出\n");
}
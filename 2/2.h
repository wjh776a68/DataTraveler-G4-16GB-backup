#pragma once
#ifndef _2_H_
typedef struct slist {
	int data;
	struct slist* next;
}node;

void show(node* p)
{
	if (p->next != NULL&& p != NULL)
	{
		p = p->next;
		while (p != NULL)
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
	printf("\n");
}

void f1(node* p)
{
	node *initp = p;
	int a;
	while (p->next != NULL)
	{
		p = p->next;
	}

	printf("请输入数字，输入9999结束输入\n");
	while (1)
	{
		scanf_s("%d", &a);

		if (a == 9999)
			break;
		
		node* newp = (node*)malloc(sizeof(node));
		newp->data = a;
		newp->next = p->next;
		p->next = newp;
		p = newp;
	} 
	printf("单链表的结点值为:");
	show(initp);
}

void f2(node* p)
{
	node* initp = p;
	int a;
	printf("请输入数字，输入9999结束输入\n");
	while (1)
	{
		scanf_s("%d", &a);

		if (a == 9999)
			break;

		node* newp = (node*)malloc(sizeof(node));
		newp->data = a;
		newp->next = p->next;
		p->next = newp;
	}
	printf("单链表的结点值为:");
	show(initp);
}

void f3(node* p)
{
	node* initp = p;
	node* lp;
	if (p->next != NULL)
	{
		p = p->next;
		
		while (p != NULL)
		{
			lp = p->next;
			free(p);	
			p = lp;
		}
		
		
	}
	printf("单链表已销毁\n");
	printf("单链表的结点值为:");
	initp->next = NULL;
	show(initp);
}

void f4(node* p)
{
	node* initp = p;
	int sum=0;
	if (p->next != NULL)
	{
		
		p=p->next;
		while (p != NULL)
		{
			p = p->next;
			sum++;
			
		}


	}
	printf("单链表的结点值为:");
	show(initp);
	printf("单链表的长度为:%d",sum);
	
}

void f5(node* p,int i)
{
	node* initp = p;
	int sum = 0;

	if (p->next != NULL)
	{
		p = p->next;

		while (p != NULL && sum + 1 < i)
		{
			p = p->next;
			sum++;
		}
	}

	if (p != NULL && sum+1==i)
	{
		printf("单链表的结点值为:");
		show(initp);
		printf("单链表的第%d个元素值为:%d\n", i, p->data);
	}
	else
		printf("error\n");

}

void f6(node* p, int i, int value)
{
	node* initp = p;
	int sum = 0;
	node* newp = (node*)malloc(sizeof(node));

	if (p->next != NULL)
	{
		p = p->next;

		while (p != NULL && sum + 2 < i)
		{
			p = p->next;
			sum++;
		}
	}
	if (p != NULL && sum + 1 <= i)
	{
		newp->data = value;
		newp->next = p->next;
		p->next = newp;
		printf("单链表的结点值为:");
		show(initp);
	}
	else
		printf("error\n");
}

node* f7(node* p, int value)
{
	node* initp = p;
	int sum = 0;

	if (p->next != NULL)
	{
		p = p->next;

		while (p != NULL)
		{
			if (p->data == value)
				break;
			p = p->next;
			sum++;
		}
		
	}

	if (p != NULL && p->data == value)
	{
		printf("单链表的结点值为:");
		show(initp);
		printf("单链表值为%d的元素为第%d个\n", value, sum+1);
		return p;
	}
	else
	{
		printf("error\n");
		return NULL;
	}
		

}

void f8(node* p, int i)
{
	node *initp = p,*tmp;
	int sum = 0;

	if (p->next != NULL)
	{
		p = p->next;

		while (p != NULL && sum + 2 < i)
		{
			p = p->next;
			sum++;
		}
	}

	if (p != NULL && sum + 2 == i)
	{
		tmp = p->next;
		if(p->next!=NULL)
			p->next = tmp->next;
		else
			p->next=NULL;
		free(tmp);
		printf("单链表的结点值为:");
		show(initp);
		
	}
	else
		printf("error\n");

}

node* f9(node* p, int value)
{
	node* initp = p;
	node* newp = (node*)malloc(sizeof(node));
	newp->data = value;
	while (p->next != NULL&&value > p->next->data)
	{
		p = p->next;
	}
	if(p->next==NULL)
	{
		newp->next = p->next;
		p->next = newp;
	}
	else
	{
		newp->next = p->next;
		p->next = newp;
	}

	
	show(initp);

}

void f10(node* p)
{
	node* p1 = (node*)malloc(sizeof(node));
	node* p2 = (node*)malloc(sizeof(node));
	p1->next = NULL;
	p2->next = NULL;
	node* initp = p;
	node* initp1 = p1;
	node* initp2 = p2;
	p=p->next;
	while (p != NULL)
	{
		node* newp= (node*)malloc(sizeof(node));
		newp->data = p->data;
		if (p->data % 2 == 1)
		{
			newp->next = p1->next;
			p1->next = newp;
			p1 = p1->next;
		}
		else if (p->data % 2 == 0)
		{
			newp->next = p2->next;
			p2->next = newp;
			p2 = p2->next;
		}
		p = p->next;
	}
	printf("原表元素");
	show(initp);
	printf("原表奇数项元素组成的新表");
	show(initp1);
	printf("原表偶数项元素组成的新表");
	show(initp2);
}

void f11()
{
	node* p1 = (node*)malloc(sizeof(node));
	node* p2 = (node*)malloc(sizeof(node));
	node* p3 = (node*)malloc(sizeof(node));
	p1->next = NULL;
	p2->next = NULL;
	p3->next = NULL;
	printf("请输入L1\n");
	f1(p1);
	printf("请输入L2\n");
	f1(p2);
	node *initp1 = p1, *initp2 = p2, *initp3 = p3;
	p1 = p1->next;
	p2 = p2->next;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data == p2->data)
		{
			node* newp = (node*)malloc(sizeof(node));
			newp->data = p1->data;
			newp->next = p3->next;
			p3->next = newp;
			p3 = p3->next;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->data < p2->data)
		{
			p1 = p1->next;
		}
		else if (p1->data > p2->data)
		{
			p2 = p2->next;
		}

	}
	printf("原表1: ");
	show(initp1);
	printf("原表2: ");
	show(initp2);
	printf("原表1 交 原表2: ");
	show(initp3);
}

void f12(node* p)
{
	int sum=0;
	node *tmp,*initp=p;
	p = p->next;
	while (p->next != NULL)
	{
		if (p->data == p->next->data)
		{
			tmp = p->next;
			p->next = tmp->next;
			sum++;
			free(tmp);
		}
		else
			p = p->next;
	}
	printf("移动次数%d\n",sum);
	show(initp);
}

void f13()
{
	node* p1 = (node*)malloc(sizeof(node));
	node* p2 = (node*)malloc(sizeof(node));

	p1->next = NULL;
	p2->next = NULL;

	printf("请输入L1\n");
	f1(p1);
	printf("请输入L2\n");
	f1(p2);
	node* initp1 = p1;
//	p1 = p1->next;
	while (p1->next != NULL)
		p1 = p1->next;
	p1->next = p2->next;
	free(p2);
	printf("原表1 + 原表2: ");
	show(initp1);
}

#endif

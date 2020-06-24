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

	printf("���������֣�����9999��������\n");
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
	printf("������Ľ��ֵΪ:");
	show(initp);
}

void f2(node* p)
{
	node* initp = p;
	int a;
	printf("���������֣�����9999��������\n");
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
	printf("������Ľ��ֵΪ:");
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
	printf("������������\n");
	printf("������Ľ��ֵΪ:");
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
	printf("������Ľ��ֵΪ:");
	show(initp);
	printf("������ĳ���Ϊ:%d",sum);
	
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
		printf("������Ľ��ֵΪ:");
		show(initp);
		printf("������ĵ�%d��Ԫ��ֵΪ:%d\n", i, p->data);
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
		printf("������Ľ��ֵΪ:");
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
		printf("������Ľ��ֵΪ:");
		show(initp);
		printf("������ֵΪ%d��Ԫ��Ϊ��%d��\n", value, sum+1);
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
		printf("������Ľ��ֵΪ:");
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
	printf("ԭ��Ԫ��");
	show(initp);
	printf("ԭ��������Ԫ����ɵ��±�");
	show(initp1);
	printf("ԭ��ż����Ԫ����ɵ��±�");
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
	printf("������L1\n");
	f1(p1);
	printf("������L2\n");
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
	printf("ԭ��1: ");
	show(initp1);
	printf("ԭ��2: ");
	show(initp2);
	printf("ԭ��1 �� ԭ��2: ");
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
	printf("�ƶ�����%d\n",sum);
	show(initp);
}

void f13()
{
	node* p1 = (node*)malloc(sizeof(node));
	node* p2 = (node*)malloc(sizeof(node));

	p1->next = NULL;
	p2->next = NULL;

	printf("������L1\n");
	f1(p1);
	printf("������L2\n");
	f1(p2);
	node* initp1 = p1;
//	p1 = p1->next;
	while (p1->next != NULL)
		p1 = p1->next;
	p1->next = p2->next;
	free(p2);
	printf("ԭ��1 + ԭ��2: ");
	show(initp1);
}

#endif

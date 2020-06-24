

typedef struct slist{
	int data[20];
	int len;
}node;

void addelement(node *p)
{
	int count,i,tmp;
	printf("设置该表的元素数量\n");
	scanf("%d",&count);
	for(i=0;i<count;i++)
	{
		printf("设置第%d个元素的值: ",i);
		scanf("%d",&tmp);
		p->data[i]=tmp;
		p->len++;	
	}
}

void delsame(node* p)
{
	int i1, i;
	for (i1 = p->len - 1; i1 > 0; i1--)
		if (p->data[i1] == p->data[i1 - 1])
		{
			for (i = i1; i < p->len + 1; i++)
				p->data[i] = p->data[i + 1];
			p->len--;
		}
}

void same(node* p, node* p1, node* p2)
{
	int l = 0, l1 = 0, l2 = 0;
	while (l < p->len && l1 < p1->len)
		if (p->data[l] < p1->data[l1])
			l++;
		else if (p->data[l] > p1->data[l1])
			l1++;
		else if (p->data[l] == p1->data[l1])
		{
			p2->data[l2] = p->data[l];
			p2->len++;
			l++;
			l1++;
			l2++;
		}
}

void add(node* p, int x)
{
	p->data[p->len] = x;
	p->len++;
}

void divide(node* p, node* p1, node* p2)
{
	int i;
	for (i = 0; i < p->len; i++)
		if (p->data[i] % 2 == 1)
			add(p1, p->data[i]);
		else
			add(p2, p->data[i]);
}

void echo (node *p)
{
	int i;
	for(i=0;i<p->len;i++)
		printf("%d ",p->data[i]);
	printf("\n");
}

int find(node *p,int pos)
{
	if (pos > p->len)
	{
		//printf("error");
		return 9999;
	}
	else if (pos < 1)
		return 9999;
	else
		return 	p->data[pos-1];	
}

int del(node* p, int pos)
{
	int i;
	if (pos > p->len - 1 || pos < 1)
		return 9999;
	else
	{
		for (i = pos - 1; i < p->len-1; i++)
			p->data[i] = p->data[i + 1];
		p->len--;
		return 1;
	}
}

int insert(node* p, int pos, int x)
{
	int i;
	if (pos > p->len ||pos<1)
		return 9999;
	else
	{
		for (i = p->len-1; i >= pos-1 ; i--)
			p->data[i+1 ] = p->data[i];
		p->data[pos-1] = x;
		p->len++;
		return 0;
	}
}

void insertbyorder(node* p, int x)
{
	int i;
	if (p->data[0] > x)
	{
		for (i = p->len; i >= 0; i--)
			p->data[i + 1] = p->data[i];
		p->data[0] = x;
		p->len++;
	}
	else if (p->data[p->len - 1] < x)
	{
		p->data[p->len] = x;
		p->len++;
	}
	else
		for (i = 1; i < p->len; i++)
			if (p->data[i - 1] <= x && x <= p->data[i])
			{
				insert(p, i + 1, x);
				//printf("%d : ", i + 1);
				break;
			}

}
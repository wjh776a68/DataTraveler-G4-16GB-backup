#include<stdio.h>
#include<stdlib.h>
#include "1.h"

int main()
{
	int c = 1;
	int i=1;
	int value,sign;
	node* p = (node*)malloc(sizeof(node));
	node* p1 = (node*)malloc(sizeof(node));
	node* p2 = (node*)malloc(sizeof(node));
	node* p3 = (node*)malloc(sizeof(node));
	p->len = 0;
	p1->len = 0;
	p2->len = 0;
	p3->len = 0;

	while (c != 0)
	{
		i = 1;
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("1.��˳����е�i��Ԫ��\n2.�ڵ�i�����ǰ����ֵΪx�Ľ��\n3.ɾ��˳����е�i��Ԫ�ؽ��\n4.��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ��������������������\n5.��˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳����У�Ȼ��ԭ����±�Ԫ��ͬʱ�����\n  ��Ļ�ϣ��Ա���������\n6.��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3��\n7.ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ���������\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("���빦������Լ���:");
		p->len = 0;
		p1->len = 0;
		p2->len = 0;
		p3->len = 0;
		scanf("%d", &c);
		printf("L: ");
		addelement(p);
		
		printf("������LΪ: ");
		echo(p);
		if (c == 1)
		{		
			printf("����[Ԫ��λ��], ����9999�˳�����\n");
			while (i != 9999)
			{			
				scanf("%d", &i);
				sign = find(p, i);
				if (i == 9999)
				{
					printf("��������\n");
					break;
				}				
				else if (sign != 9999)
					printf("��%d��Ԫ�ص�ֵΪ%d\n", i, sign);
				else
					printf("error\n");
			}
			

		}
		else if (c == 2)
		{	
			printf("����[�ڼ������] [Ҫ�����ֵ],����9999 9999�˳�����\n");
			while (i != 9999)
			{

				scanf("%d %d", &i, &value);
				sign= insert(p, i, value);
				if (i == 9999)
				{
					printf("��������\n");
					break;
				}
				else if (sign != 9999)
				{
					
					printf("������������Ϊ");
					echo(p);
				}				
				else
					printf("error\n");
				
			}
		}
		else if (c == 3)
		{
			printf("����[Ԫ��λ��],����9999�˳�����\n");
			while (i != 9999)
			{
				
				scanf("%d", &i);
				sign=del(p, i);
				if (i == 9999)
				{
					printf("��������\n");
					break;
				}
				else if (sign != 9999)
				{
					printf("ɾ����");
					echo(p);
				}
				else
					printf("error\n");
			}
		}
		else if (c == 4)
		{	
			printf("����[Ҫ�����ֵ],����9999�˳�����\n");
			while (1)
			{
				scanf("%d", &value);
				if (value!= 9999)
				{
					insertbyorder(p, value);
					echo(p);
				}
				else
					break;
			}
		}
		else if (c == 5)
		{

			printf("��������ı�L1��ʼֵ: ");
			echo(p1);
			printf("��ż����ı�L2��ʼֵ: ");
			echo(p2);
			printf("����ż��ֿ���\n");
			divide(p, p1, p2);
			printf("ԭL��: ");
			echo(p);
			printf("��������ı�L1��ֵ: ");
			echo(p1);
			printf("��ż����ı�L2��ֵ: ");
			echo(p2);
		}
		else if (c == 6)
		{
			printf("�����L1��ֵ��");
			addelement(p1);
			printf("��L1��ֵ: ");
			echo(p1);
			printf("�����L2��ֵ��");
			addelement(p2);
			printf("��L2��ֵ: ");
			echo(p2);
			same(p1, p2, p3);
			printf("��L1,L2����Ԫ�صı�L3��ֵΪ: ");
			echo(p3);
		}
		else if (c == 7)
		{
			printf("��ʼֵL:\n");
			echo(p);
			printf("ɾ��L���ظ�Ԫ�غ���L:\n");
			delsame(p);
			echo(p);
		}
		printf("\n");
	}
	return 0;
}

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
		printf("1.求顺序表中第i个元素\n2.在第i个结点前插入值为x的结点\n3.删除顺序表中第i个元素结点\n4.在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性\n5.将顺序表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数），分别放入新的顺序表中，然后原表和新表元素同时输出到\n  屏幕上，以便对照求解结果\n6.求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中\n7.删除递增有序顺序表中的重复元素，并统计移动元素次数，要求时间性能最好\n");
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("输入功能序号以继续:");
		p->len = 0;
		p1->len = 0;
		p2->len = 0;
		p3->len = 0;
		scanf("%d", &c);
		printf("L: ");
		addelement(p);
		
		printf("设置完L为: ");
		echo(p);
		if (c == 1)
		{		
			printf("输入[元素位置], 输入9999退出功能\n");
			while (i != 9999)
			{			
				scanf("%d", &i);
				sign = find(p, i);
				if (i == 9999)
				{
					printf("结束功能\n");
					break;
				}				
				else if (sign != 9999)
					printf("第%d个元素的值为%d\n", i, sign);
				else
					printf("error\n");
			}
			

		}
		else if (c == 2)
		{	
			printf("输入[第几个结点] [要插入的值],输入9999 9999退出功能\n");
			while (i != 9999)
			{

				scanf("%d %d", &i, &value);
				sign= insert(p, i, value);
				if (i == 9999)
				{
					printf("结束功能\n");
					break;
				}
				else if (sign != 9999)
				{
					
					printf("插入后表中序列为");
					echo(p);
				}				
				else
					printf("error\n");
				
			}
		}
		else if (c == 3)
		{
			printf("输入[元素位置],输入9999退出功能\n");
			while (i != 9999)
			{
				
				scanf("%d", &i);
				sign=del(p, i);
				if (i == 9999)
				{
					printf("结束功能\n");
					break;
				}
				else if (sign != 9999)
				{
					printf("删除后：");
					echo(p);
				}
				else
					printf("error\n");
			}
		}
		else if (c == 4)
		{	
			printf("输入[要插入的值],输入9999退出功能\n");
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

			printf("存奇数项的表L1初始值: ");
			echo(p1);
			printf("存偶数项的表L2初始值: ");
			echo(p2);
			printf("将奇偶项分开后\n");
			divide(p, p1, p2);
			printf("原L表: ");
			echo(p);
			printf("存奇数项的表L1的值: ");
			echo(p1);
			printf("存偶数项的表L2的值: ");
			echo(p2);
		}
		else if (c == 6)
		{
			printf("输入表L1的值：");
			addelement(p1);
			printf("表L1的值: ");
			echo(p1);
			printf("输入表L2的值：");
			addelement(p2);
			printf("表L2的值: ");
			echo(p2);
			same(p1, p2, p3);
			printf("含L1,L2公共元素的表L3的值为: ");
			echo(p3);
		}
		else if (c == 7)
		{
			printf("初始值L:\n");
			echo(p);
			printf("删除L的重复元素后了L:\n");
			delsame(p);
			echo(p);
		}
		printf("\n");
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include "2.h"


int main()
{
	node* p = (node*)malloc(sizeof(node));
	int i = 1,ii,value;
	p->next = NULL;
	while (i != 0)
	{
		printf("\n----------------------------------------\n");
		printf("1.尾插法创建单链表\n2.头插法创建单链表\n3.销毁单链表\n4.求链表长度\n5.求单链表中第i个元素\n6.在第i个结点前插入值为x的结点\n");
		printf("7.链表中查找元素值为x的结点\n8.删除单链表中第i个元素结点\n9.在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性\n");
		printf("10.将单链表Ｌ中的奇数项和偶数项结点分解开,分别放入新的单链表中\n11.求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中\n12.删除递增有序单链表中的重复元素\n13.递增有序单链表L1、L2，不申请新结点，利用原表结点对2表进行合并，并使得合并后成为一个集合，合并后用L1的头结点作为头结点，删除L2的头结点\n");
		printf("\n----------------------------------------\n");
		printf("输入功能以继续\n");
		scanf_s("%d", &i);
		switch (i)
		{
			case 1: f1(p);break;
			case 2: f2(p); break;
			case 3: f3(p); break;
			case 4: f4(p); break;
			case 5: printf("请输入i\n"); scanf_s("%d", &ii); f5(p, ii); break;
			case 6: printf("请输入i和值\n"); scanf_s("%d %d", &ii,&value); f6(p, ii,value); break;
			case 7: printf("请输入值\n"); scanf_s("%d", &value); f7(p, value); break;
			case 8: printf("请输入i\n"); scanf_s("%d", &ii); f8(p, ii); break;
			case 9: printf("请输入值\n"); scanf_s("%d", &value); f9(p, value); break;
			case 10: f10(p); break;
			case 11: f11(); break;
			case 12: f12(p); break;
			case 13: f13(); break;
		}
			

	}
	
	return 0;
}
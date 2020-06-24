#include<stdio.h>
#include<stdlib.h>
#include "2.h"

int main()
{
	int choice=1,i,value;
	node *p=(node*)malloc(sizeof(node));
	p->next=NULL;

	while(choice!=0)
	{
		printf("\n----------------------------------------\n");
		printf("<1>尾插法创建单链表\n<2>头插法创建单链表\n<3>销毁单链表。\n<4>求链表长度。\n<5>求单链表中第i个元素\n<6>在第i个结点前插入值为x的结点。\n<7>链表中查找元素值为x的结点\n<8>删除单链表中第i个元素结点。\n<9>在一个递增有序的单链表L中插入一个值为x的元素，并保持其递增有序特性。\n<10>将单链表Ｌ中的奇数项和偶数项结点分解开（元素值为奇数、偶数）\n<11>求两个递增有序单链表L1和L2中的公共元素，放入新的单链表L3中。\n<12>删除递增有序单链表中的重复元素\n<13>递增有序单链表L1、L2，不申请新结点，利用原表结点对2表进行合并\n");
		printf("输入序号以继续,0退出"); 
		printf("\n----------------------------------------\n");
		scanf("%d",&choice);
		switch(choice)
		{
			i=0;
			case 1:f1(p); break;
			case 2:f2(p); break;
			case 3:f3(p); break;
			case 4:f4(p); break;
			case 5:while(i!=9999){printf("请输入i: ");scanf("%d",&i);if(i==9999)break;f5(p,i);} break;
			case 6:while(i!=9999){printf("请输入i value: ");scanf("%d %d",&i,&value);if(i==9999)break;f6(p,i,value); }break;
			case 7:while(i!=9999){printf("请输入x: ");scanf("%d",&i);if(i==9999)break;f7(p,i); }break;
			case 8:while(i!=9999){printf("请输入i: ");scanf("%d",&i);if(i==9999)break;f8(p,i);} break;
			case 9:while(i!=9999){printf("请输入x: ");scanf("%d",&i);if(i==9999)break;f9(p,i); }break;
			case 10:f10(p); break;
			case 11:f11(); break;
			case 12:f12(p); break;
			case 13:f13(); break;
		}
	}
	
	return 0;
}

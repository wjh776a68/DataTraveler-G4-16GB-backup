#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#include "9.h"

int main()
{
	system("mode con:cols=400 lines=300");
	int choice;
	do {
		system("cls");
		printf("实验九 查找实验\n");
		printf("\n--------------------\n");
		printf("1.对下列数据表，分别采用二分查找算法实现查找，给出查找过程依次所比较的元素（的下标），并以二分查找的判定树来解释\n2.设计出在二叉排序树中插入结点的算法，在此基础上实现构建二叉排序树的算法\n3.设计算法在二叉排序树中查找指定值的结点\n4.设计算法在二叉排序树中删除特定值的结点\n5.已知整型数组A[1..26]递增有序，设计算法以构造一棵平衡的二叉排序树来存放该数组中的所有元素\n");
		printf("6.创建数组到文件\n");
		printf("\n--------------------\n");
		printf("输入选项以继续：\n");
		scanf("%d", &choice);
		fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 0:
			printf("程序退出\n");
			return 0;
			break;
		case 1:
			f1();
			break;
		case 2:
			f2();
			break;
		case 3:
			f3();
			
			break;
		case 4:
			f4();
			break;
		case 5:
			f5();
			break;		
		case 6:		
			createfile();
			break;
		}
		printf("返回上一级...");
		system("pause>nul");

	} while (choice != 0);
	
}

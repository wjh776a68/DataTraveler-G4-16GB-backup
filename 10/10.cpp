#pragma warning(disable : 4996)
#include <stdio.h>
#include <windows.h>
#include "10.h"


int main()
{
	system("mode con cols=150");	
	int choice;	
	do{
		system("cls");
		printf("实验十 排序实验\n");
		printf("************************************************************\n");
		printf("1.采用不同实验数据来观察快速排序的实验中比较和交换元素的次数，并分析数据的规模和初始特性与比较与交换次数之间的函数关系。\n2.完成下面功能：将一个整型数组调整为这样的数组：所有３的倍数在最左边，所有除以３余１的数在中间，而所有除以３余２的数在最右边。要求算法的时间尽可能少\n3.实现shell排序算法，并观察在采用不同的步长选取方法对排序过程中数据的比较和移动次数的影响\n");
		printf("4.设计算法实现快速排序，要求能用数组或树来演示排序过程，以清晰地表示出排序过程。\n5.以数组和二叉树形式动态演示堆排序算法的排序过程\n6.利用二路归并方法进行排序\n");
		printf("7.创建数据文件\n");
		printf("************************************************************\n");
		printf("输入功能序号以继续：\n");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 0:printf("程序退出\n");return 0;break;
			case 1:f1();break;
			case 2:f2();break;
			case 3:f3();break;
			case 4:f4();break;
			case 5:f5();break;
			case 6:f6();break;
			case 7:writefile();break;
		}
		fflush(stdin);
		printf("返回上一级\n");
		system("pause>nul");
	}while(choice!=0);
	
	return 0;
}

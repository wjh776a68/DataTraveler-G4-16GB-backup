//#include<iostream>
#pragma warning(disable : 4996)
#include<stdio.h>
#include<windows.h>
#include "8.1.h"


int main()
{
	int choice;
	system("mode con cols=150");
	//printf("*********************************************************************\n");
	do
	{
		printf("**********************************************************************\n");
		printf("*                      实验八 图实验                                 *\n");
		printf("**********************************************************************\n");
		printf("\
*   0.退出                                                           *\n\
*   1.打印图（网）的遍历序。                                         *\n\
*   2-求给定图中的边（或弧）的数目。                                 *\n\
*   3-从V0出发深度优先遍历图G，并构造出相应的生成树或生成森林。      *\n\
*   4-从V0出发广度优先遍历图G，并构造出相应的生成树或生成森林。      *\n\
*   5-Prim算法，求解图G的最小生成树。                                *\n\
*   6-Kruskal算法，求解图G的最小生成树。                             *\n\
*   7-Dijkstra算法，求解图G指定顶点到其余顶点之间的最短路径。        *\n\
*   8-Floyd算法，求解图G各顶点之间的最短路径。                       *\n\
*   9-求解图G的拓扑序列。                                            *\n\
*   10-求解AOE网的关键路径。                                         *\n");
		printf("**********************************************************************\n");
		printf("输入选项以继续:\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 0:
				printf("程序退出\n");
				system("pause>nul");
				return 0;
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
				f6();
				break;
			case 7:
				f7();
				break;
			case 8:
				f8();
				break;
			case 9:
				f9();
				break;
			case 10:
				f10();
				break;
		}
		printf("返回上一级...");
		system("pause>nul");
		system("cls");




	}
	while (choice != 0);

	return 0;
}

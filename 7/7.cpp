#include<stdio.h>
#include<windows.h>
#include"createTree.h"

int main()
{
	
	int choice=1;
	int color=0;
	pTree T;
	while (choice != 0)
	{
		printf("实验七 树与森林实验\n");
		printf("--------------------------------------------------\n");
		printf("1.按先序、后序、层次遍历森林。\n2.求森林的高度。\n3.求森林结点总数\n4.求森林叶子结点数。\n5.求森林的度。\n6.先序输出结点值及其层次号。\n7.输出广义表表示的树。\n8.导入树\n9.%s模式\n",color==0?"亮色":"暗色");
		printf("\n--------------------------------------------------\n输入选项以继续>");
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
			printf("先序遍历：");
			preTraverse(T);
			printf("\n后序遍历：");
			postTraverse(T);
			printf("\n层次遍历：");
			levelTraverse(T);			
		break;
		case 2:
			TreeHeight(T);			
		break;
		case 3:
			TreeAmount(T);	
		break;
		case 4:
			TreeLeaveCount(T);
		break;
		case 5:
			TreeDegree(T);
		break;
		case 6:
			levelTraverse2(T);
		break;
		case 7:
			structureprintf(T);
		break;
		case 8:
			if (CreateTreeFromFile(T))
				printf("导入成功\n");
		break;
		case 9:
			if(color==1)
			{
				color=0;
				system("color 07");	
			}					
			else
			{
				color=1;
				system("color F0");	
			}
			printf("应用成功\n");				
		break;

		}
		printf("\n返回上级菜单...");
		system("pause>nul");
		system("cls");
		
	}
	return 0;
}

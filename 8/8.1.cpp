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
		printf("*                      ʵ��� ͼʵ��                                 *\n");
		printf("**********************************************************************\n");
		printf("\
*   0.�˳�                                                           *\n\
*   1.��ӡͼ�������ı�����                                         *\n\
*   2-�����ͼ�еıߣ��򻡣�����Ŀ��                                 *\n\
*   3-��V0����������ȱ���ͼG�����������Ӧ��������������ɭ�֡�      *\n\
*   4-��V0����������ȱ���ͼG�����������Ӧ��������������ɭ�֡�      *\n\
*   5-Prim�㷨�����ͼG����С��������                                *\n\
*   6-Kruskal�㷨�����ͼG����С��������                             *\n\
*   7-Dijkstra�㷨�����ͼGָ�����㵽���ඥ��֮������·����        *\n\
*   8-Floyd�㷨�����ͼG������֮������·����                       *\n\
*   9-���ͼG���������С�                                            *\n\
*   10-���AOE���Ĺؼ�·����                                         *\n");
		printf("**********************************************************************\n");
		printf("����ѡ���Լ���:\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 0:
				printf("�����˳�\n");
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
		printf("������һ��...");
		system("pause>nul");
		system("cls");




	}
	while (choice != 0);

	return 0;
}

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
		printf("ʵ��� ����ʵ��\n");
		printf("\n--------------------\n");
		printf("1.���������ݱ��ֱ���ö��ֲ����㷨ʵ�ֲ��ң��������ҹ����������Ƚϵ�Ԫ�أ����±꣩�����Զ��ֲ��ҵ��ж���������\n2.��Ƴ��ڶ����������в�������㷨���ڴ˻�����ʵ�ֹ����������������㷨\n3.����㷨�ڶ����������в���ָ��ֵ�Ľ��\n4.����㷨�ڶ�����������ɾ���ض�ֵ�Ľ��\n5.��֪��������A[1..26]������������㷨�Թ���һ��ƽ��Ķ�������������Ÿ������е�����Ԫ��\n");
		printf("6.�������鵽�ļ�\n");
		printf("\n--------------------\n");
		printf("����ѡ���Լ�����\n");
		scanf("%d", &choice);
		fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 0:
			printf("�����˳�\n");
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
		printf("������һ��...");
		system("pause>nul");

	} while (choice != 0);
	
}

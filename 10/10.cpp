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
		printf("ʵ��ʮ ����ʵ��\n");
		printf("************************************************************\n");
		printf("1.���ò�ͬʵ���������۲���������ʵ���бȽϺͽ���Ԫ�صĴ��������������ݵĹ�ģ�ͳ�ʼ������Ƚ��뽻������֮��ĺ�����ϵ��\n2.������湦�ܣ���һ�������������Ϊ���������飺���У��ı���������ߣ����г��ԣ��ࣱ�������м䣬�����г��ԣ��ࣲ���������ұߡ�Ҫ���㷨��ʱ�価������\n3.ʵ��shell�����㷨�����۲��ڲ��ò�ͬ�Ĳ���ѡȡ������������������ݵıȽϺ��ƶ�������Ӱ��\n");
		printf("4.����㷨ʵ�ֿ�������Ҫ�����������������ʾ������̣��������ر�ʾ��������̡�\n5.������Ͷ�������ʽ��̬��ʾ�������㷨���������\n6.���ö�·�鲢������������\n");
		printf("7.���������ļ�\n");
		printf("************************************************************\n");
		printf("���빦������Լ�����\n");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 0:printf("�����˳�\n");return 0;break;
			case 1:f1();break;
			case 2:f2();break;
			case 3:f3();break;
			case 4:f4();break;
			case 5:f5();break;
			case 6:f6();break;
			case 7:writefile();break;
		}
		fflush(stdin);
		printf("������һ��\n");
		system("pause>nul");
	}while(choice!=0);
	
	return 0;
}

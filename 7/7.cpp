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
		printf("ʵ���� ����ɭ��ʵ��\n");
		printf("--------------------------------------------------\n");
		printf("1.�����򡢺��򡢲�α���ɭ�֡�\n2.��ɭ�ֵĸ߶ȡ�\n3.��ɭ�ֽ������\n4.��ɭ��Ҷ�ӽ������\n5.��ɭ�ֵĶȡ�\n6.����������ֵ�����κš�\n7.���������ʾ������\n8.������\n9.%sģʽ\n",color==0?"��ɫ":"��ɫ");
		printf("\n--------------------------------------------------\n����ѡ���Լ���>");
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
			printf("���������");
			preTraverse(T);
			printf("\n���������");
			postTraverse(T);
			printf("\n��α�����");
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
				printf("����ɹ�\n");
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
			printf("Ӧ�óɹ�\n");				
		break;

		}
		printf("\n�����ϼ��˵�...");
		system("pause>nul");
		system("cls");
		
	}
	return 0;
}

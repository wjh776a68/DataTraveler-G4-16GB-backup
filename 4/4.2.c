#include<stdio.h>
#include"4.2.h"

int main()
{
	int choice = 1;
	node* aqueue = (node*)malloc(sizeof(node));
	cmd* acmd = (cmd*)malloc(sizeof(cmd));
	while (choice != 0)
	{
		printf("\n----------------------------------------\n");
		printf("1.��ʼ��һ�����С�\n2.�ж��Ƿ�ӿա�\n3.�ж��Ƿ������\n4.���\n5.����\n6.ȡ��ͷԪ��\n7.��ǰ������Ԫ�ظ���\n8.��д�㷨ʵ��: \n	�ٳ�ʼ����ѭ�����У�\n		�ڵ�������������ʱ����������ӣ�\n	�۵���������ż��ʱ����ͷ���ӣ�\n	�ܵ���������0ʱ���㷨�˳���\n	��ÿ����������������ǰ�����е�����Ԫ�ء�\n");
		printf("\n----------------------------------------\n");
		printf("����ѡ���Լ���\n");

		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: f1(aqueue,acmd); break;
		case 2: printf("%s", f2(aqueue,acmd) == 1 ? "Yes" : "NO"); break;
		//case 3: printf("%s", f3(aqueue, acmd) == 1 ? "Yes" : "NO"); break;
		case 4: f4(aqueue, acmd); break;
		case 5: f5(aqueue, acmd); break;
		case 6: f6(aqueue, acmd); break;
		case 7: f7(aqueue, acmd); break;
		case 8: f8(); break;
		}
	}
	return 0;
}
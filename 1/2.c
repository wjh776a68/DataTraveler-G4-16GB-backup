#include<stdio.h>
#include<stdlib.h>
#include "2.h"


int main()
{
	node* p = (node*)malloc(sizeof(node));
	int i = 1,ii,value;
	p->next = NULL;
	while (i != 0)
	{
		printf("\n----------------------------------------\n");
		printf("1.β�巨����������\n2.ͷ�巨����������\n3.���ٵ�����\n4.��������\n5.�������е�i��Ԫ��\n6.�ڵ�i�����ǰ����ֵΪx�Ľ��\n");
		printf("7.�����в���Ԫ��ֵΪx�Ľ��\n8.ɾ���������е�i��Ԫ�ؽ��\n9.��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ��������������������\n");
		printf("10.����������е��������ż������ֽ⿪,�ֱ�����µĵ�������\n11.������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3��\n12.ɾ���������������е��ظ�Ԫ��\n13.������������L1��L2���������½�㣬����ԭ�����2����кϲ�����ʹ�úϲ����Ϊһ�����ϣ��ϲ�����L1��ͷ�����Ϊͷ��㣬ɾ��L2��ͷ���\n");
		printf("\n----------------------------------------\n");
		printf("���빦���Լ���\n");
		scanf_s("%d", &i);
		switch (i)
		{
			case 1: f1(p);break;
			case 2: f2(p); break;
			case 3: f3(p); break;
			case 4: f4(p); break;
			case 5: printf("������i\n"); scanf_s("%d", &ii); f5(p, ii); break;
			case 6: printf("������i��ֵ\n"); scanf_s("%d %d", &ii,&value); f6(p, ii,value); break;
			case 7: printf("������ֵ\n"); scanf_s("%d", &value); f7(p, value); break;
			case 8: printf("������i\n"); scanf_s("%d", &ii); f8(p, ii); break;
			case 9: printf("������ֵ\n"); scanf_s("%d", &value); f9(p, value); break;
			case 10: f10(p); break;
			case 11: f11(); break;
			case 12: f12(p); break;
			case 13: f13(); break;
		}
			

	}
	
	return 0;
}
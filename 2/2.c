#include<stdio.h>
#include<stdlib.h>
#include "2.h"

int main()
{
	int choice=1,i,value;
	node *p=(node*)malloc(sizeof(node));
	p->next=NULL;

	while(choice!=0)
	{
		printf("\n----------------------------------------\n");
		printf("<1>β�巨����������\n<2>ͷ�巨����������\n<3>���ٵ�����\n<4>�������ȡ�\n<5>�������е�i��Ԫ��\n<6>�ڵ�i�����ǰ����ֵΪx�Ľ�㡣\n<7>�����в���Ԫ��ֵΪx�Ľ��\n<8>ɾ���������е�i��Ԫ�ؽ�㡣\n<9>��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�\n<10>����������е��������ż������ֽ⿪��Ԫ��ֵΪ������ż����\n<11>������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3�С�\n<12>ɾ���������������е��ظ�Ԫ��\n<13>������������L1��L2���������½�㣬����ԭ�����2����кϲ�\n");
		printf("��������Լ���,0�˳�"); 
		printf("\n----------------------------------------\n");
		scanf("%d",&choice);
		switch(choice)
		{
			i=0;
			case 1:f1(p); break;
			case 2:f2(p); break;
			case 3:f3(p); break;
			case 4:f4(p); break;
			case 5:while(i!=9999){printf("������i: ");scanf("%d",&i);if(i==9999)break;f5(p,i);} break;
			case 6:while(i!=9999){printf("������i value: ");scanf("%d %d",&i,&value);if(i==9999)break;f6(p,i,value); }break;
			case 7:while(i!=9999){printf("������x: ");scanf("%d",&i);if(i==9999)break;f7(p,i); }break;
			case 8:while(i!=9999){printf("������i: ");scanf("%d",&i);if(i==9999)break;f8(p,i);} break;
			case 9:while(i!=9999){printf("������x: ");scanf("%d",&i);if(i==9999)break;f9(p,i); }break;
			case 10:f10(p); break;
			case 11:f11(); break;
			case 12:f12(p); break;
			case 13:f13(); break;
		}
	}
	
	return 0;
}

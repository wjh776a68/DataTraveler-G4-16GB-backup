#include<stdio.h>
#include<stdlib.h>
#include "3.h"



int main()
{
	int i=1;
	while(i!=0)
	{
		printf("\n----------------------------------------\n");
		printf("1.����˳��ջʵ�ֽ�10������ת��Ϊ16������\n2.�ж����еĸ������Ƿ���ƥ���\n3.������ջʵ�ֽ�10������ת��Ϊ16������\n4.�ж����еĸ������Ƿ���ƥ��\n");
		printf("----------------------------------------\n");
		printf("ѡ���Լ���\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: f1();break;
			case 2: f2();break;
			case 3: f3();break;
			case 4: f4();break;
				
		}
	}

	return 0;
}

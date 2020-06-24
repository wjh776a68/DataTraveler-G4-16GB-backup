#include<stdio.h>
#include<stdlib.h>
#include "3.h"



int main()
{
	int i=1;
	while(i!=0)
	{
		printf("\n----------------------------------------\n");
		printf("1.利用顺序栈实现将10进制数转换为16进制数\n2.判断其中的各括号是否是匹配的\n3.利用链栈实现将10进制数转换为16进制数\n4.判断其中的各括号是否是匹配\n");
		printf("----------------------------------------\n");
		printf("选项以继续\n");
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

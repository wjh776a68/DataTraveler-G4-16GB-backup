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
		printf("1.初始化一个队列。\n2.判断是否队空。\n3.判断是否队满。\n4.入队\n5.出队\n6.取队头元素\n7.求当前队列中元素个数\n8.编写算法实现: \n	①初始化空循环队列；\n		②当键盘输入奇数时，此奇数入队；\n	③当键盘输入偶数时，队头出队；\n	④当键盘输入0时，算法退出；\n	⑤每当键盘输入后，输出当前队列中的所有元素。\n");
		printf("\n----------------------------------------\n");
		printf("输入选项以继续\n");

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
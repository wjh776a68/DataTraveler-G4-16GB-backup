#include<stdio.h>
#include "BiTree.h"


int main()
{
	int choice;
	tree *tr;
	do{
		printf("\n--------------------\n");
		printf("1.打印出二叉树的三种遍历序\n2.设计算法按中序次序输出二叉树中各结点的值及其所对应的层次数\n3.求二叉树的高度\n4.求二叉树的结点数\n5.求二叉树的叶子结点数\n6.求二叉树的度为2的结点数\n7.键盘输入一个元素x，求其父节点、兄弟结点、子结点的值，不存在时给出相应提示信息。对兄弟结点和孩子结点，存在时要明确指出是左兄弟、左孩子、右兄弟或右孩子。\n8.键盘输入一个元素x，求其在树中的层次。不存在时给出相应提示信息。\n9.将按顺序方式存储在数组中的二叉树转换为二叉链表形式\n10.交换二叉树中每个结点的左右孩子指针的值\n11.复制一棵二叉树T到T1\n12.输出二叉树从每个叶子结点到根结点的路径\n13.对二叉链表表示的二叉树，按从上到下，从左到右打印结点值，即按层次打印\n14.对二叉链表表示的二叉树，求2个结点最近的共同祖先。\n15.求二叉树中一条最长的路径长度（边数），并输出路径上的个结点值。\n");
		printf("16.导入数据\n17.存入数据\n");
		printf("\n--------------------\n");
		printf("please input the choice\n");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:f1(tr); break;
			case 2:{				
				f2(tr,1);
				printf("\n");
				 break;
			}
			case 3:{
				int tmp=0;
				int *max=&tmp;
				f3(tr,0,max);
				printf("%d\n",*max);
				 break;
			}
			case 4:{
				int tmp=0;
				int *n=&tmp;
				f4(tr,n);
				printf("%d\n",*n);
				break;
			}
			case 5:
			{
				int tmp=0;
				int *n=&tmp;
				f5(tr,n);
				printf("%d\n",*n);
				break;
			}
			case 6:
			{
				int tmp=0;
				int *n=&tmp;
				f6(tr,n);
				printf("%d\n",*n);
				break;
			} 
			case 7:{
				int tmp2=0;
				int *found=&tmp2;
				char tmp;
				char *value=&tmp;
				printf("请输入元素值:");
				scanf("%c",value);
				
				//printf("%d::",*found);
				f7(tr,NULL,-1,value,found);
				//printf("%d::",*found);
				if(*found!=1)
					printf("没有找到\n");
				break;
			}
			case 8:{
				int tmp2=0;
				int *found=&tmp2;
				char tmp;
				char *value=&tmp;
				printf("请输入元素值:");
				scanf("%c",value);			
				f8(tr,0,value,found);
				if(*found!=1)
					printf("没有找到\n");
					
				break;
			}
			case 9:f9(tr); break;
			case 10:f10(tr); break;
			case 11:
			{
				tree *tr2=f11(tr);
				printf("旧树:\n");
				f1(tr);
				printf("复制的新树:\n");
				f1(tr2);
				break;
			}
			case 12:f12(tr); break;
			case 13:f13(tr); break;
			case 14:f14(tr); break;
			case 15:f15(tr); break;
			case 16:read(tr); break;
			case 17:write(tr); break;

		}
		
	}while(choice);
	
	return 0;
}

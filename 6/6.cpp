#include<stdio.h>
#include "BiTree.h"


int main()
{
	int choice;
	tree *tr;
	do{
		printf("\n--------------------\n");
		printf("1.��ӡ�������������ֱ�����\n2.����㷨�������������������и�����ֵ��������Ӧ�Ĳ����\n3.��������ĸ߶�\n4.��������Ľ����\n5.���������Ҷ�ӽ����\n6.��������Ķ�Ϊ2�Ľ����\n7.��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ��������ʱ������Ӧ��ʾ��Ϣ�����ֵܽ��ͺ��ӽ�㣬����ʱҪ��ȷָ�������ֵܡ����ӡ����ֵܻ��Һ��ӡ�\n8.��������һ��Ԫ��x�����������еĲ�Ρ�������ʱ������Ӧ��ʾ��Ϣ��\n9.����˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ\n10.������������ÿ���������Һ���ָ���ֵ\n11.����һ�ö�����T��T1\n12.�����������ÿ��Ҷ�ӽ�㵽������·��\n13.�Զ��������ʾ�Ķ������������ϵ��£������Ҵ�ӡ���ֵ��������δ�ӡ\n14.�Զ��������ʾ�Ķ���������2���������Ĺ�ͬ���ȡ�\n15.���������һ�����·�����ȣ��������������·���ϵĸ����ֵ��\n");
		printf("16.��������\n17.��������\n");
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
				printf("������Ԫ��ֵ:");
				scanf("%c",value);
				
				//printf("%d::",*found);
				f7(tr,NULL,-1,value,found);
				//printf("%d::",*found);
				if(*found!=1)
					printf("û���ҵ�\n");
				break;
			}
			case 8:{
				int tmp2=0;
				int *found=&tmp2;
				char tmp;
				char *value=&tmp;
				printf("������Ԫ��ֵ:");
				scanf("%c",value);			
				f8(tr,0,value,found);
				if(*found!=1)
					printf("û���ҵ�\n");
					
				break;
			}
			case 9:f9(tr); break;
			case 10:f10(tr); break;
			case 11:
			{
				tree *tr2=f11(tr);
				printf("����:\n");
				f1(tr);
				printf("���Ƶ�����:\n");
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

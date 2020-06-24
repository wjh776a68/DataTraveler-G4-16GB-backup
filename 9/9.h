#pragma once
//#pragma warning(disable : 4996)
//#include<stdio.h>
//#include<stdlib.h>
#include<math.h>
#include"__Treecodes.h"

//#include<windows.h>
//#include"virtualscreen.h"



void find_f1(int*,int, int);
void Show_Array(int*,int);
void f1()
{
	int choice, value;
	int a[] = { 1,2,3,4,6,7,8,9,10,11,12,13,17,18,19,20,24,25,26,30,35,40,45,50,80,100 };
	int b[] = { 2,3,5,7,8,10,12,15,18,20,22,25,30,35,40,45,50,55,60,80,100 };

	printf("请输入所要使用的数组: [1/2]\n");
	printf("第一组数据：(1,2,3,4,6,7,8,9,10,11,12,13,17,18,19,20,24,25,26,30,35,40,45,50,?80,100)\n");
	printf("第二组数据：(2,3,5,7,8,10,12,15,18,20,22,25,30,35,40,45,50,55,60,80,100)\n");
	scanf("%d", &choice);
	//printf("%d\n", sizeof(a) / sizeof(int));
	printf("请输入所要查找的元素:\n");
	scanf("%d", &value);
	switch (choice)
	{
	case 1:
		Show_Array(a,sizeof(a)/sizeof(int));
		find_f1(a, sizeof(a) / sizeof(int),value);
		
		break;
	case 2:
		Show_Array(b,sizeof(b) / sizeof(int));
		find_f1(b,sizeof(a) / sizeof(int), value);
		
	}
}



void buildorderedtree(TreeNode *&newtree,int *SourceArray,int front,int rear,int argument)
{
	if(front<=rear)
	{
			atr *newnode=new atr(*(SourceArray+(int)(front+rear)/2));
			if(argument==1)
				newtree->Lchild=newnode;
			else if(argument==2)
				newtree->Rchild=newnode;
			else if(argument==3)
				newtree=newnode;	
		buildorderedtree(newnode,SourceArray,front,(int)(front+rear)/2-1,1);
		buildorderedtree(newnode,SourceArray,(int)(front+rear)/2+1,rear,2);
	}

}




void Show_Array(int *SourceArray,int SourceArray_Len)
{

	//int SourceArray_Len = sizeof(SourceArray)/sizeof(int);
	int i = 0,start=0,number=SourceArray_Len,head=0;
	int *newSourceArray=(int * )malloc(SourceArray_Len*(sizeof(int)));
	printf("元素下标: ");
	while (i < SourceArray_Len)
	{
		printf("%-3d ",i);
		i++;
	}
	printf("\n");
	printf("元素的值: ");
	i = 0;
	while (i < SourceArray_Len)
	{
		printf("%-3d ", SourceArray[i]);
		i++;
	}
	printf("\n");

	printf("二分查找的判定树如图所示：\n");
	

	//adjustorder(SourceArray,newSourceArray, SourceArray_Len,1,head);
	// 打印二叉树bt
	
	atr *newtree=NULL;
	buildorderedtree(newtree,SourceArray,0,SourceArray_Len-1,3);
	//newtree= createTreeFromArray(SourceArray, SourceArray_Len, -1);
	bt_print(newtree);
	//addline(screen,0,0,3,0);	
	//show(SourceArray,SourceArray_Len,start,number); 	
}

void find_f1(int *SourceArray, int SourceArray_Len, int value)
{
	//int SourceArray_Len=sizeof(SourceArray)/ sizeof(int);
	int i = 0, j = SourceArray_Len-1;
	while (i <= j)
	{
		printf("比较的元素下标为%d,其值为%d\n", (i + j) / 2,*(SourceArray+(i+j)/2));
		if (SourceArray[(i + j) / 2]==value)
		{
			printf("所要查找的元素下标为%d\n", (i + j) / 2);
			break;
		}
		else if (SourceArray[(i + j) / 2] < value)
		{
			i = (i + j) / 2;
			i++;
		}
		else if (SourceArray[(i + j) / 2] > value)
		{
			j = (i + j) / 2;
			j--;
		}
	}
	if (i >= j)
	{
		printf("未找到\n");
	}

	


}



void insertwithorder(atr *otr,int value,bool finished)
{
	if (value < otr->val)
	{
			if (otr->Lchild == NULL)
			{
				//tr* newnode = new tr;
				//newnode->data = value;
				atr *newnode=new atr(value);
				finished = 1;
				//newnode->Lchild = newnode->Rchild = NULL;
				otr->Lchild = newnode;
			}
			else
			{
				insertwithorder(otr->Lchild, value, finished);
			}
	}	
	else if (value > otr->val)
	{
			if (otr->Rchild == NULL)
			{
				//tr* newnode = new tr;
				//newnode->data = value;
				atr *newnode=new atr(value);	
				finished = 1;
			//	newnode->Lchild = newnode->Rchild = NULL;
				otr->Rchild = newnode;
			}
			else
			{
				insertwithorder(otr->Rchild, value, finished);
			}
	}
	else
	{
		printf("OH NO! How can you make two elements with same value.!!!\n");
		finished = 1;
	}
}

void showorderedtree(atr *otr)
{
	if (otr != NULL)
	{
		showorderedtree(otr->Lchild);
		printf("%d ",otr->val);
		showorderedtree(otr->Rchild);
	}
}

void showorderedtree2(atr *otr)
{
	if (otr != NULL)
	{
		printf("%d ",otr->val);
		showorderedtree2(otr->Lchild);		
		showorderedtree2(otr->Rchild);
	}
}

void cleanorderedtree(atr* otr)
{
	if (otr != NULL)
	{
		cleanorderedtree(otr->Lchild);
		cleanorderedtree(otr->Rchild);
		free(otr);
	}
}


void f2()
{
	int a;
	//tr* otr = (tr*)malloc(sizeof(tr));
	//otr->Lchild = otr->Rchild = NULL;
	
	printf("请输入序列(-1退出):\n");	
	scanf("%d", &a);
	//otr->data = a;
	atr *otr=new atr(a);
	while(a!=-1) {
		scanf("%d", &a);
		if (a != -1)
		{
			insertwithorder(otr, a,0);
			bt_print(otr);
		}
			
	}
	printf("生成的二叉树为:\n");
	bt_print(otr);
	//printf("排序完成的中序序列为：\n");
	//showorderedtree(otr);
	printf("\n");
	printf("开始释放所用内存空间:\n");
	cleanorderedtree(otr);
	printf("释放完毕\n");
	fflush(stdin);
}

void arraytotree(atr *tree,int a)
{
		if (a > tree->val)
		{
			if (tree->Rchild == NULL)
			{
				atr *newnode=new atr(a);
				tree->Rchild = newnode;
			}
			else
			{
				arraytotree(tree->Rchild, a);
			}

		}
		else if (a < tree->val)
		{
			if (tree->Lchild == NULL)
			{
				atr *newnode=new atr(a);
				tree->Lchild = newnode;
			}
			else
			{
				arraytotree(tree->Lchild, a );
			}
		}
		else
		{
			printf("OH NO! How can you make two elements with same value.!!!\n");
			
		}
}

void findorderedtree(atr*& otr,atr *&ret,int value,int &finished)
{
	if (otr != NULL && finished==0)
	{
		printf("正在查找%d是否与之匹配\n",otr->val);
		if (otr->val == value)
		{
			finished = 1;
			
			ret = otr;
			
		}
		else if(otr->val > value)
		findorderedtree(otr->Lchild,ret,value,finished);	
		else if (otr->val < value)
		findorderedtree(otr->Rchild,ret,value,finished);
	}

}

void f3()
{
	int a[] = { 1,2,3,4,6,7,8,9,10,11,12,13,17,18,19,20,24,25,26,30,35,40,45,50,80,100 };
	//int b[] = { 2,3,5,7,8,10,12,15,18,20,22,25,30,35,40,45,50,55,60,80,100 };
	int find,i,finished=0;
	int arrayend = sizeof(a) / sizeof(int);
	atr *tree=new atr(*a);
	atr *ret=NULL;
	buildorderedtree(tree, a, 0, arrayend-1, 3);
	printf("已将<1>中第一组数据填入\n");
	//showorderedtree(tree);
	bt_print(tree);	
	//printf("\n");
	printf("请输入要查找的值:(-1退出)");
	do {
		scanf("%d", &find);
		fflush(stdin);
		if (find != -1)
		{
			findorderedtree(tree,ret,find,finished);
			if (finished!=1)
			{
				printf("未找到\n");
			}
			else
				printf("已找到该节点，其值为%d\n", ret->val);		
		}
		finished=0;
	} while (find != -1);
	printf("开始释放所用内存空间:\n");
	cleanorderedtree(tree);
	printf("释放完毕\n");
	fflush(stdin);

}


atr* getSuccessor(atr* delNode) {
	atr* curr = delNode->Rchild;
	atr* successor = curr;
	atr* sucParent = NULL;
	while (curr != NULL) {
		sucParent = successor;
		successor = curr;
		curr = curr->Lchild;
	}
	if (successor != delNode->Rchild) {
		//将后继节点的子节点（仅仅可能有右节点）替补到后继节点的位置上
		sucParent->Lchild = successor->Rchild;
		//将被删除的右孩子连接到后继节点的右节点上
		successor->Rchild = delNode->Rchild;
		//将被删除的左孩子连接到后继节点的右节点上（就是用后继节点替换掉被删除的节点）
	}
	return successor;
}

boolean delnode(int key, atr*& root) {
	atr* curr = root;//保存当前节点
	atr* parent = root;//保存当前节点父节点
	boolean isLeft = true;//记录是否是左几点
	//定位到将被删除的节点 
	while (key != curr->val) {
		if (key <= curr->val) {
			isLeft = true;//经过左节点
			if (curr->Lchild != NULL) {
				parent = curr;
				curr = curr->Lchild;
			}
		}
		else {
			isLeft = false;//经过右节点
			if (curr->Rchild != NULL) {
				parent = curr;
				curr = curr->Rchild;
			}
		}
		if (curr == NULL) {
			return false;
		}
	}
	//假设被删除节点是叶子节点
	if (curr->Lchild == NULL && curr->Rchild == NULL) {
		if (curr == root) {
			root = NULL;
		}
		else if (isLeft) {
			parent->Lchild = NULL;
		}
		else {
			parent->Rchild = NULL;
		}
		//假设被删除节点仅仅有左节点
	}
	else if (curr->Rchild == NULL) {
		if (curr == root) {
			root = root->Lchild;
		}
		else if (isLeft) {
			parent->Lchild = curr->Lchild;
		}
		else {
			parent->Rchild = curr->Lchild;
		}
		//假设被删除节点仅仅有右节点
	}
	else if (curr->Lchild == NULL) {
		if (curr == root) {
			root = root->Rchild;
		}
		else if (isLeft) {
			parent->Lchild = curr->Rchild;
		}
		else {
			parent->Rchild = curr->Rchild;
		}
	}
	else {
		atr* successor = getSuccessor(curr);
		//将后继节点与被删除的父节点进行连接，完毕整个替换过程
		if (curr == root) {
			root = successor;
		}
		else if (curr == parent->Lchild) {
			parent->Lchild = successor;
		}
		else {
			parent->Rchild = successor;
		}
		successor->Lchild = curr->Lchild;
	}
	return true;

}










void f4()
{
	int a[] = { 1,2,3,4,6,7,8,9,10,11,12,13,17,18,19,20,24,25,26,30,35,40,45,50,80,100 };
	//int b[] = { 2,3,5,7,8,10,12,15,18,20,22,25,30,35,40,45,50,55,60,80,100 };
	int find, i, finished = 0;
	int arrayend = sizeof(a) / sizeof(int);
	atr *tree=new atr(a[0]);
	atr* ret = NULL;

	buildorderedtree(tree, a, 0, arrayend-1, 3);
	printf("已将<1>中第一组数据填入\n");
	bt_print(tree);
	printf("\n");	
	do {
		printf("请输入要删除的值:(-1退出)");	
		scanf("%d", &find);
		fflush(stdin);
		if (find != -1)
		{
			findorderedtree(tree, ret, find, finished);		
			//delorderedtree(tree, find, finished);
			if (finished != 1)
			{
				printf("未找到\n");
			}
			else
			{
				delnode(find, tree);
				printf("已删除该节点，删除后二叉树为\n");
				bt_print(tree);
				//showorderedtree(tree);
				printf("\n");
			}
				
		}
		finished = 0;
	} while (find != -1);
	printf("开始释放所用内存空间:\n");
	cleanorderedtree(tree);
	printf("释放完毕\n");
	fflush(stdin);
}

void treeheight(atr *btr,int &maxfloor,int floor=0)
{
	if(btr!=NULL)
	{
		treeheight(btr->Lchild,maxfloor,floor+1);
		treeheight(btr->Rchild,maxfloor,floor+1);
		
	}
	else
	{
		if(floor>maxfloor)
			maxfloor=floor;
	}
}



void balancedtree(atr *btr,int newdata)
{
	if(newdata<btr->val)
	{
		if(btr->Lchild==NULL)
		{
			atr *newnode=new atr(newdata);
			btr->Lchild=newnode;
		}
		else
		{
			balancedtree(btr->Lchild,newdata);	
		}		
	}
	else if(newdata>btr->val)
	{
		if(btr->Rchild==NULL)
		{
			atr *newnode=new atr(newdata);
			btr->Rchild=newnode;
		}
		else
		{
			balancedtree(btr->Rchild,newdata);	
		
		}		
	}
	else
	{
		printf("error,two same value\n");
	}

}


void keepbalanced_worker(atr*& yuan,atr *btr,atr *lbtr,int &change)
{
	if (btr != NULL)
	{
		if(change==0)
		keepbalanced_worker(yuan,btr->Lchild,btr,change);
		if(change==0)
		keepbalanced_worker(yuan,btr->Rchild,btr,change);
		if(change==0)
		{
			
			int maxfloorL = 0, maxfloorR = 0;
			treeheight(btr->Lchild, maxfloorL);
			treeheight(btr->Rchild, maxfloorR);
			bt_print(yuan);
			if(maxfloorL-maxfloorR>1)
			{
				change=1;
				atr *sbtr=btr->Lchild;
				int smaxfloorL = 0, smaxfloorR = 0;
				treeheight(sbtr->Lchild, smaxfloorL);
				treeheight(sbtr->Rchild, smaxfloorR);
				
				if(smaxfloorL>smaxfloorR)  //LL
				{
					if(yuan==btr)
					{
						yuan=sbtr;
						btr->Lchild=sbtr->Rchild;
						sbtr->Rchild=btr;
					}

					
					else if(lbtr->Lchild==btr)
					{
						lbtr->Lchild=sbtr;
						btr->Lchild=sbtr->Rchild;
						sbtr->Rchild=btr;

					}
					else if(lbtr->Rchild==btr)
					{
						lbtr->Rchild=sbtr;
						btr->Lchild=sbtr->Rchild;
						sbtr->Rchild=btr;

					}
					else
					{
						printf("LL");
						getchar();
					}
					
				}
				else if(smaxfloorL<smaxfloorR)  //LR
				{
					if(yuan==btr)
					{
						yuan=sbtr;
						btr->Lchild=sbtr->Rchild;
						sbtr->Rchild=btr;

					}

					else if(lbtr->Lchild==btr)
					{
						lbtr->Lchild=sbtr->Rchild;
						btr->Lchild=lbtr->Lchild->Rchild;
						sbtr->Rchild=lbtr->Lchild->Lchild;
						lbtr->Lchild->Rchild=btr;
						lbtr->Lchild->Lchild=sbtr;

					}
					else if(lbtr->Rchild==btr)
					{
						lbtr->Rchild=sbtr->Rchild;
						btr->Lchild=lbtr->Rchild->Rchild;
						sbtr->Rchild=lbtr->Rchild->Lchild;
						lbtr->Rchild->Rchild=btr;
						lbtr->Rchild->Lchild=sbtr;
					}
					else
					{
						printf("LR");
						getchar();
					}
				}			
				else
				{
					printf("warning 1 !!");
					getchar();
				}
			}
			else if(maxfloorR-maxfloorL>1)
			{
				change=1;
				atr *sbtr=btr->Rchild;
				int smaxfloorL = 0, smaxfloorR = 0;
				treeheight(sbtr->Lchild, smaxfloorL);
				treeheight(sbtr->Rchild, smaxfloorR);
				if(smaxfloorL>smaxfloorR)   //RL
				{
					if(yuan==btr)
					{
						yuan=sbtr;
						btr->Rchild=sbtr->Lchild;
						sbtr->Lchild=btr;

					}
					
					else if(lbtr->Lchild==btr)
					{
						lbtr->Lchild=sbtr->Lchild;
						btr->Rchild=lbtr->Lchild->Lchild;
						sbtr->Lchild=lbtr->Lchild->Rchild;
						lbtr->Lchild->Lchild=btr;
						lbtr->Lchild->Rchild=sbtr;

					}
					else if(lbtr->Rchild==btr)
					{
						lbtr->Rchild=sbtr->Lchild;
						btr->Rchild=lbtr->Rchild->Lchild;
						sbtr->Lchild=lbtr->Rchild->Rchild;
						lbtr->Rchild->Lchild=btr;
						lbtr->Rchild->Rchild=sbtr;

					}
					else
					{
						printf("RL");
						getchar();
					}
				}
				else if(smaxfloorL<smaxfloorR)  //RR
				{
					if(yuan==btr)
					{
						yuan=sbtr;
						btr->Rchild=sbtr->Lchild;
						sbtr->Lchild=btr;
				
					}

					else if(lbtr->Lchild==btr)
					{
						lbtr->Lchild=sbtr;
						btr->Rchild=sbtr->Lchild;
						sbtr->Lchild=btr;
				
					}
					else if(lbtr->Rchild==btr)
					{
						lbtr->Rchild=sbtr;
						btr->Rchild=sbtr->Lchild;
						sbtr->Lchild=btr;
	
					}
					else
					{
						printf("RR");
						getchar();
					}
				}
				else
				{
					printf("warning 2 !!");
					getchar();
				}
				
			}
		}

	}
	
}

void f5()
{
	char path[30]={0};
	int newdata;
	atr* btr=new atr(0);
	printf("请输入数据文件路径:");	
	scanf("%s",path);	
	
	FILE *fp=fopen(path,"r");
	if (fp != NULL)
	{
		if (!feof(fp))
		{
			fscanf(fp, "%d ", &newdata);
			btr->val = newdata;
		}

		while (!feof(fp))
		{
			int change = 0;
			fscanf(fp, "%d ", &newdata);
			balancedtree(btr, newdata);
			do
			{
				change = 0;
				keepbalanced_worker(btr, btr, btr,  change);
				getchar();
			}		
			while (change == 1);
			printf("平衡二叉树为 :\n");
			bt_print(btr);
			getchar();
		}
		
		fclose(fp);
		printf("平衡二叉树为 :\n");
		bt_print(btr);
	}
	else
	{
		printf("未找到该文件\n");
	}
	
	
	
	
}

void createfile()
{
	char path[32]={0};
	int x;
	printf("请输入保存路径:");
	scanf("%s",path);
	FILE *fp=fopen(path,"w+");
	printf("请输入数组数字：\n");
	do
	{
		scanf("%d",&x);
		fflush(stdin);
		if(x!=-1)
			fprintf(fp,"%d ",x);		
	}while(x!=-1);
	printf("输入完成\n");
	rewind(fp);
	fclose(fp);
	fflush(stdin);
}






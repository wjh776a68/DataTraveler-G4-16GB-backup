/*二叉树生成与打印程序*/
#pragma once
#include<stdio.h>


// Definition for a binary tree node.
typedef struct TreeNode {
	int val;
	TreeNode* Lchild;
	TreeNode* Rchild;
	TreeNode(int x) : val(x), Lchild(NULL), Rchild(NULL) {}
}atr;

//在二叉排序树中插入查找关键字key
struct TreeNode* InsertBST(TreeNode * t, int key)
{
	if (t == NULL)
	{
		t = new TreeNode(key);
		t->Lchild = t->Lchild = NULL;
		//t->val = key;
		return t;
	}

	if (key < t->val)
		t->Lchild = InsertBST(t->Lchild, key);
	else
		t->Rchild = InsertBST(t->Rchild, key);

	return t;
}

//n个数据在数组d中，tree为二叉排序树根
void CreateBiTree(TreeNode *&tree, int d[], int n)
{
	
	for (int i = 0; i < n; i++)
		tree = InsertBST(tree, d[i]);
}

// 从nums数组生成二叉树。数组元素须为小于等与999的正整数，空节点以numMeansNull表示。
struct TreeNode* createTreeFromArray(int* nums, int numsSize);
// 打印二叉树bt
void bt_print(TreeNode* bt);
void calTreeDepth(TreeNode* t);
void setPrintBuffer(TreeNode* t);

// 由二维数组生成二叉树
atr* createTreeFromArray(int* nums, int numsSize) {
	atr* nodes = (atr*)malloc(numsSize * sizeof(atr));
	for (int i = 0; i < numsSize; i++) {
		(nodes + i)->val = nums[i];
		(nodes + i)->Lchild = (i * 2 + 1 < numsSize) ? (nodes+ i * 2 + 1) : NULL;
		(nodes + i)->Rchild = (i * 2 + 2 < numsSize) ? (nodes + i * 2 + 2) : NULL;
	}
	return nodes;
}

// 当前节点的深度
int depth = 0;
// 该树的深度，如果只有根节点则深度为1
int depthMax = 0;
// 打印缓冲区的宽度，当前应打印的列数，上次打印位置的列数
int width = 0, column = 0, lastColumn = 0;
char** printBuffer = NULL;

void bt_print(TreeNode* bt) {
	depth = 0;
	column = 0;
	lastColumn = 0;
	depthMax = 0;
	// 根据树的大小申请内存
	calTreeDepth(bt);
	width = 3 * ((1 << (depthMax - 1)) * 2 - 1);
	int height = 1 + (depthMax - 1) * 3;
	printBuffer = (char**)malloc(height * sizeof(char*));
	for (int i = 0; i < height; i++) {
		printBuffer[i] = (char*)malloc(width * sizeof(char));
		memset(printBuffer[i], ' ', width);
		printBuffer[i][width - 1] = '\0';
	}
	depth = 0;
	column = width / 2;
	lastColumn = column;
	setPrintBuffer(bt);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", printBuffer[i][j]);
		}
		printf("\n");
	}

}

// 递归找到该树的最大深度
void calTreeDepth(TreeNode* t) {
	if (t) {
		depth++;
		depthMax = depthMax < depth ? depth : depthMax;
		calTreeDepth(t->Lchild);
		calTreeDepth(t->Rchild);
		depth--;
	}
}

// 先序遍历，将数据设置到打印缓冲区
void setPrintBuffer(TreeNode* t) {
	if (t) {
		depth++;
		int val = t->val;
		for (int i = 0; val>0; i++) {
			printBuffer[(depth - 1) * 3 ][column + 1 - i] = val % 10 + 0x30;
			val /= 10;
		}
		if (depth > 1) {
			int i;
			if (column < lastColumn)
			{
				for (i = column; i < lastColumn; i++)
					printBuffer[(depth - 1) * 3 - 2][i] = '-';
			}
			else
			{
				for (i = lastColumn; i <= column; i++)
					printBuffer[(depth - 1) * 3 - 2][i] = '-';
			}
			printBuffer[(depth - 1) * 3 - 1][column] = '|';
		}
		int step = (1 << (depthMax - depth - 1)) * 3;
		lastColumn = column;
		column -= step;
		setPrintBuffer(t->Lchild);
		column += step;
		lastColumn = column;
		column += step;
		setPrintBuffer(t->Rchild);
		column -= step;
		depth--;
	}
}

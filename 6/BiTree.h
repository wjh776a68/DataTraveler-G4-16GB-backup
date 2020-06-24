#include<stdio.h>
#include<stdlib.h>



typedef struct tr {
	char data;
	struct tr *lchild, *rchild;
}tree;

typedef struct tra{
	char data[200];
}treearray;
//void generate(FILE *fp,tree*& btr,int direction);

typedef struct block{
	char data[200];
	int top;
}stack;

void push(stack *&name,char in)
{
	name->data[(++name->top)]=in;
}

char pop(stack *&name)
{
	return name->data[(name->top--)];
}

void deverseshowstack(stack *name)
{
	int x;
	for(x=name->top;x>-1;x--)
	{
		printf("%c->",name->data[x]);
	}
}

void showstack(stack *name)
{
	int x;
	for(x=0;x<=name->top;x++)
	{
		printf("%c ",name->data[x]);
	}
}
void generate(FILE *fp,tree*& btr,int direction)
{
	char data;
	char l,r;
	
	fscanf(fp,"%c %c %c\n",&data,&l,&r);	
	tree *newp=(tree*)malloc(sizeof(tree));
	newp->data=data;
	newp->lchild=NULL;
	newp->rchild=NULL;
//	printf("%c\n",newp->data);
	if(direction==0)
		btr->lchild=newp;
	else if(direction==1)
		btr->rchild=newp;
	else if(direction==-1)
		btr=newp;
	
	if(l=='1')
	{
		generate(fp,newp,0);
	}
	if(r=='1')
	{
		generate(fp,newp,1);
	}
	
}

void read(tree *&tr)
{
	char path[100];	
	printf("请输入文件相对路径：\n");
	scanf("%s", path);
	
	FILE *fp=fopen(path, "r");
//	printf("break");
	if(fp!=NULL)
	{
		generate(fp,tr,-1);
	}
	else
	{
		printf("文件未找到\n");
	}
	 fclose(fp);
	
}

void qian(tree *btr)
{
	if(btr!=NULL)
	{
		printf("%c ",btr->data);
		qian(btr->lchild);
		qian(btr->rchild);
	}
}

void zhong(tree *btr)
{
	if(btr!=NULL)
	{		
		zhong(btr->lchild);
		printf("%c ",btr->data);
		zhong(btr->rchild);
	}

}

void hou(tree *btr)
{
	if(btr!=NULL)
	{		
		hou(btr->lchild);
		hou(btr->rchild);
		printf("%c ",btr->data);
	}
}

void f1(tree *btr)
{
	printf("先序序列：");
	qian(btr);
	printf("\n");
	printf("中序序列：");
	zhong(btr);
	printf("\n");
	printf("后序序列：");
	hou(btr);
	printf("\n");
}

void f2(tree *btr,int floor)
{
	if(btr!=NULL)
	{		
		f2(btr->lchild,floor+1);
		printf("%c:%d",btr->data,floor);
		f2(btr->rchild,floor+1);
	}

}

void f3(tree *btr,int floor,int *max)
{
	if(btr!=NULL)
	{
		f3(btr->lchild,floor+1,max);
		f3(btr->rchild,floor+1,max);
	}
	else
	{
		if(floor>*max)
			*max=floor;
	}
}

void f4(tree *btr,int *&n)
{
	if(btr!=NULL)
	{		
		(*n)++;
		f4(btr->lchild,n);		
		f4(btr->rchild,n);
	}

}

void f5(tree *btr,int *&n)
{
	if(btr!=NULL)
	{		
		if(btr->lchild==NULL&&btr->rchild==NULL)
			(*n)++;
		f5(btr->lchild,n);		
		f5(btr->rchild,n);
	}
}

void f6(tree *btr,int *&n)
{
	if(btr!=NULL)
	{		
		if(btr->lchild!=NULL&&btr->rchild!=NULL)
			(*n)++;
		f6(btr->lchild,n);		
		f6(btr->rchild,n);
	}
}

void f7(tree *btr,tree *parent,int position,char *&n,int *&found)
{
//	printf("%d::",*found);
	if(btr!=NULL&&*found==0)
	{		
	//		printf("%c::",*n);
		if(btr->data==*n)
		{
			if(parent!=NULL)
				printf("父节点：%c，\n",parent->data);
			if(position==0&&parent->rchild!=NULL)			
				printf("右兄弟结点：%c，",parent->rchild->data);
			else if(position==1&&parent->lchild!=NULL)
				printf("左兄弟结点：%c，\n",parent->lchild->data);
			if(btr->lchild!=NULL)
				printf("左子节点：%c，",btr->lchild->data);
			if(btr->rchild!=NULL)
				printf("右子节点：%c。\n",btr->rchild->data);
			(*found)=1;
		//	printf("%d::",*found);
		}		
		if(*found==0)
		{
			f7(btr->lchild,btr,0,n,found);		
		}
		if(*found==0)
		{	
			f7(btr->rchild,btr,1,n,found);
		}
	}
}

void f8(tree *btr,int floor,char *&value,int *&found)
{
	
	if(btr!=NULL)
	{
		//printf("%c",btr->data);
		if(btr->data==*value)
		{
			printf("层次为：%d\n",floor+1);		
			(*found)=1;
		}
		if(*found==0)
		{
			f8(btr->lchild,floor+1,value,found);
		}
		if(*found==0)
		{
			f8(btr->rchild,floor+1,value,found);
		}
		
	}

}

void generatebyarray(tree *&parent,int size,treearray *newp,int position,int maxlen)
{
	
	tree *newl=(tree*)malloc(sizeof(tree));
	newl->lchild=newl->rchild=NULL;
	newl->data=newp->data[position];	
	
	if(size==0)
		parent->lchild=newl;
	else if(size==1)
		parent->rchild=newl;
	else if(size==-1)
		parent=newl;
	//printf("%c:%c:%c ",newp->data[position],newp->data[2*position],newp->data[2*position+1]);
	if(2*position<maxlen&&newp->data[2*position]!='^')
	{	
		//btr->lchild=newl;
		generatebyarray(newl,0,newp,2*position,maxlen);
	}
	
	if(2*position+1<maxlen&&newp->data[2*position+1]!='^')
	{
		//btr->lchild=newr;
		generatebyarray(newl,1,newp,2*position+1,maxlen);
	}
	
}

void f9(tree *&btr)
{
	
	printf("请输入数组型二叉树（^表示空，！提前结束输入）：\n");
	int i=1;
	treearray *newp=(treearray*)malloc(sizeof(treearray));
	while(i<200&&newp->data[i-1]!='!')
	{
		scanf("%c",&newp->data[i]);
		if(newp->data[i]==' ')
			continue;
		i++;
	}
//	printf("%d::\n",i-1);
	generatebyarray(btr,-1,newp,1,i-1);
	
	
}

void f10(tree *btr)
{
	if(btr!=NULL)
	{		
		tree *tmp;
		if(btr->lchild!=NULL&&btr->rchild!=NULL)
		{
		//	printf("%c %c\n",btr->lchild->data,btr->rchild->data);
			tmp=btr->lchild;
			btr->lchild=btr->rchild;
			btr->rchild=tmp;
		//	printf("%c %c\n",btr->lchild->data,btr->rchild->data);
		}
		f10(btr->lchild);		
		f10(btr->rchild);
	}
}

tree *f11(tree *btr)
{
	if(btr!=NULL)
	{
		tree *newp=(tree*)malloc(sizeof(tree));
		newp->data=btr->data;		
		newp->lchild=f11(btr->lchild);
		newp->rchild=f11(btr->rchild);
		return newp;
	}
	else
		return NULL;
}

void f122(tree *btr,stack *news)
{
	if(btr!=NULL)
	{
		push(news,btr->data);
		if(btr->lchild==NULL&&btr->rchild==NULL)
		{
			deverseshowstack(news);
			printf("NULL\n");
		}
		f122(btr->lchild,news);
		f122(btr->rchild,news);
		pop(news);
				
	}
		
}

void f12(tree *btr)
{
	stack *news=(stack*)malloc(sizeof(stack));
	news->top=-1;
	f122(btr,news);
}


void f133(tree *btr,int job,int floor,stack **level)   //job : 0 normal 1 first 2 final 3 root
{
	if(btr!=NULL)
	{
		if(job!=0)		
		{
			if(job==1)
			{
			//	printf("first:%c:: ",btr->data);
			//	printf(":%d:: ",floor);
				push((*(level+floor)),btr->data);
			//	printf("first:%c::end ",btr->data);
				f133(btr->lchild,1,floor+1,level);
				f133(btr->rchild,0,floor+1,level);
			}
			else if(job==2)
			{			
			//	printf("final:%c:: ",btr->data);
			//	printf(":%d:: ",floor);
				push((*(level+floor)),btr->data);
			//	printf("final:%c::end ",btr->data);
				printf("第%d层: ",floor+1);
				showstack((*(level+floor)));
				printf("\n");
		
				f133(btr->lchild,0,floor+1,level);
				f133(btr->rchild,2,floor+1,level);
			}
			else if(job==3)
			{
				
				push((*(level+floor)),btr->data);
				printf("第%d层: ",floor+1);
				showstack((*(level+floor)));
				printf("\n");
				f133(btr->lchild,1,floor+1,level);
				f133(btr->rchild,2,floor+1,level);
			}
		}
		else
		{
		//	printf("normal:%c:: ",btr->data);	
		//	printf(":%d:: ",floor);
			push((*(level+floor)),btr->data);
		//	printf("normal:%c::end ",btr->data);
			f133(btr->lchild,0,floor+1,level);
			f133(btr->rchild,0,floor+1,level);
		}
		
	}
}

void f13(tree *btr)
{
	int tmp=0;
	int i;
	int *max=&tmp;
	f3(btr,0,max);
	stack *levelyuan[*max+1];
	
	for(i=0;i<*max+1;i++)
	{
		levelyuan[i]=(stack*)malloc(sizeof(stack));
		levelyuan[i]->top=-1;
	}
	
	stack **level=&levelyuan[0];
//	printf(":%d:: ",(*(level+floor))->top);
//	(*level+3)->data[1]='a';
//	printf("%c ",(*level+3)->data[1]);
//	printf("%c ",((*level)+3)->data[1]);
////	printf("%c",(*(level+3))->data[1]);
	f133(btr,3,0,level);
}


void f144(tree *btr,stack *&news,char *need,int *signal)
{
	if(btr!=NULL&&*signal==0)
	{
		push(news,btr->data);
		if(btr->data==*need)
		{
	//		deverseshowstack(news);
	//		printf("NULL\n");
			*signal=1;
			//return;
		}
		
		f144(btr->lchild,news,need,signal);
		f144(btr->rchild,news,need,signal);
		if(*signal==0)
			pop(news);
				
	}
		
}

void f14(tree *btr)
{
	char a,b;
	char *first=&a;
	char *second=&b;
	int signal1=0,signal2=0;
	char tmp1,tmp2;
	int i;
	printf("请输入两个节点：\n");
	scanf("%c %c",&a,&b);
	fflush(stdin);
	stack *news=(stack*)malloc(sizeof(stack));
	news->top=-1;
	stack *news2=(stack*)malloc(sizeof(stack));
	news2->top=-1;
	f144(btr,news,first,&signal1);
	f144(btr,news2,second,&signal2);
//	deverseshowstack(news);
//	printf("\n");
//	deverseshowstack(news2);
//	printf("\n");
	if(news->top>news2->top)
	{
		for(i=news->top-news2->top;i>0;i--)
		{
			pop(news);
		}
	}
	else
	{
		for(i=news2->top-news->top;i>0;i--)
		{
			pop(news2);
		}
	}
	
	while(true)
	{
		tmp1=pop(news);
		tmp2=pop(news2);
		if(tmp1==tmp2)
		{
			printf("%c",tmp1);
			break;
		}
	}
	
}



void f155(tree *btr,stack *news,int *max,int floor)
{
	if(btr!=NULL)
	{
		push(news,btr->data);
		if(btr->lchild==NULL&&btr->rchild==NULL)
		{
			if(*max==floor+1)
			{
				deverseshowstack(news);
				printf("NULL\n");
			}

		}
		f155(btr->lchild,news,max,floor+1);
		f155(btr->rchild,news,max,floor+1);
		pop(news);
				
	}
		
}

void f15(tree *btr)
{
	stack *news=(stack*)malloc(sizeof(stack));
	int tmp;
	int *max=&tmp;
	news->top=-1;
	f3(btr,0,max);
	printf("最长边长度为：%d\n",*max);
	f155(btr,news,max,0);
}



void build(FILE *fp,tree *&btr,int direction)
{
	char l,r;
	char data,cache;
	getchar();
	scanf("%c %c %c",&data,&l,&r);
	fprintf(fp,"%c %c %c\n",data,l,r);
	//printf("data:%c l:%c r:%c\n",data,l,r);
	tree *newp=(tree*)malloc(sizeof(tree));
	newp->data=data;
	newp->lchild=NULL;
	newp->rchild=NULL;
	
	if(direction==0)
		btr->lchild=newp;
	else if(direction==1)
		btr->rchild=newp;
	else if	(direction==-1)
		btr=newp;
	if(l=='1')
	{
		build(fp,newp,0);
	}
	if(r=='1')
	{
		build(fp,newp,1);
	}
	
}

void write(tree*& btr)
{

	char path[100];	
	printf("请输入文件相对路径：\n");
	scanf("%s", path);
	FILE* fp = fopen(path, "w+");
	printf("按照 数据 是否有左孩子 是否有右孩子 输入数据: \n");	
	build(fp,btr,-1);
	printf("输入完毕\n");
	fclose(fp);
}




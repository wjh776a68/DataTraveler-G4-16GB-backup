#pragma once
#include<stdio.h>
#include"virtualscreen.h"
#include"grpAdjMatrix.h"
#include"createGrpAdjMatrix.h"


void visitedclean()
{
	int i;
	for(i=0; i<MaxVerNum+1; i++)
		visited[i]=false;
}

typedef struct queue
{
	int data[MaxVerNum];
	int front;
	int rear;
} qlist;

typedef struct stack
{
	int data[MaxVerNum];
	int top;
} piece;

typedef struct edgestruct
{
	int start;
	int edge;
	int end;

} edge;

typedef struct sequence
{
	int data[MaxVerNum];
	int len;
} seqlist;

typedef struct edgeslist
{
	edge data[MaxVerNum];
	int len;
	int edgeslen;
} edgelist;

//typedef struct branch{
//	int data[MaxVerNum];
//	int BranchLeavesNum;
//}branchlist;
//
//typedef struct tree
//{
//	branchlist data[MaxVerNum];
//	int TreeBranchNum;
//}treelist;
//
//typedef struct forest{
//	treelist data[MaxVerNum];
//	int ForestTreeNum;
//}forestlist;


bool isfull(qlist aqueue)
{
	if((aqueue.rear+1)%MaxVerNum==aqueue.front)
		return true;
	return false;
}
bool isfull(piece astack)
{
	if(astack.top==MaxVerNum-1)
		return true;
	return false;
}


bool isempty(qlist aqueue)
{
	if(aqueue.rear==aqueue.front)
	{
		//	printf("and ");
		return true;
	}
	return false;
}
bool isempty(piece astack)
{
	if(astack.top==-1)
	{
		return true;
	}
	return false;
}

int min(int a,int b)
{
	return a>b?a:b;
}

void showqueue(qlist aqueue)
{
	int i=aqueue.front;
	while(i!=aqueue.rear)
	{
		printf("%d ",aqueue.data[i]);
		i=(i+1)%MaxVerNum;

	}
	printf("\n");
}

void showstack(piece astack)
{
	int i=0;
	while(i<=astack.top)
	{
		printf("%d ",astack.data[i]);
		i++;
	}
	printf("\n");
}

void inqueue(qlist &aqueue,int value)
{
	if(isfull(aqueue)==false)
	{
		aqueue.data[aqueue.rear]=value;
		aqueue.rear=(aqueue.rear+1)%MaxVerNum;
		//	printf("::%d::",aqueue.data[aqueue.rear]);
		//printf("nane");
	}

}

int outqueue(qlist &aqueue)
{
	if(isempty(aqueue)==false)
	{
		aqueue.front=(aqueue.front+1)%MaxVerNum;
		//printf("here");
		return aqueue.data[(aqueue.front-1+MaxVerNum)%MaxVerNum];

	}
	else if(isempty(aqueue)==true)
		return 0;

}

void instack(piece &astack,int value)
{
	if(isfull(astack)==false)
	{
		astack.top++;
		astack.data[astack.top]=value;
	}
}

int outstack(piece &astack)
{
	if(isempty(astack)==false)
	{
		return astack.data[astack.top--];
	}
	return 0;
}




void f1()
{

	qlist queue;
	queue.rear=0;
	queue.front=0;
	int total;
	Graph G;
	char path[32];
	int v;
	int ret;
	int tmp;
	piece stack;
	stack.top=-1;

	printf("��������Ҫ������ļ�·��:\n");
	scanf("%s",path);
	CreateGrpFromFile(path,G);
	printGraph(G);

	visitedclean();   //hint important

	printf("---------------------------------------------------\n");
	printf("���������������������ʾ��\n");
	total=1;
	while(total<=G.VerNum)
	{
		if(visited[total]==true)
		{
			total++;
			continue;
		}
		v=total;
		printf("\n");
		while(v!=0)
		{
			//if(visited[v]==false)
			//{
				visit(G,v);
			//}
			ret=firstAdj(G,v);
			while(ret!=0)
			{
				inqueue(queue,ret);
				ret=nextAdj(G,v,ret);
			}
			do
			{
				v=outqueue(queue);
			}
			while(visited[v]==true);
		}


	}
	printf("\n");
	printf("������������������\n");
	printf("------------------------------------------\n");
	visitedclean();

	printf("�����������������ʼ\n");

	total=1;
	while(total<=G.VerNum)
	{

		if(visited[total]==true)
		{
			total++;
			continue;
		}
		v=total;
		printf("\n");

		while(v!=0)
		{
			visit(G,v);
			ret=firstAdj(G,v);
			while(visited[ret]==true)
			{
				ret=nextAdj(G,v,ret);
				if(ret==0)
					break;
			}
			tmp=ret;
			if(ret!=0 && visited[ret]==false)
			{
				do
				{
					ret=nextAdj(G,v,ret);
					if(ret!=0 && visited[ret]==false)
					{
						instack(stack,ret);
					}

				}
				while(ret!=0);
				v=tmp;
			}
			else
				do
					v=outstack(stack);
				while(visited[v]==true && v!=0);
		}
	}
	printf("\n");
	printf("������������������\n");


}

void  f2()
{
	Graph G;
	int total;
	int ret;
	qlist queue;
	queue.rear = 0;
	queue.front = 0;
	int v;
	int count_edge = 0;
	char path[32];
	printf("��������Ҫ������ļ�·��:\n");
	scanf("%s", path);
	CreateGrpFromFile(path, G);
	printGraph(G);
	visitedclean();
	printf("��ʼ����ͼ�ı���:");
	total = 1;
	while (total <= G.VerNum)
	{
		if (visited[total] == true)
		{
			total++;
			continue;
		}
		v = total;
		printf("\n");
		while (v != 0)
		{
			if (visited[v] == false)
			{
				visited[v] = true;
				//visit(G, v);
			}
			ret = firstAdj(G, v);

			while (ret != 0)
			{
				count_edge++;
				inqueue(queue, ret);
				ret = nextAdj(G, v, ret);
			}
			do
			{
				v = outqueue(queue);
			}
			while (visited[v] == true);
		}
	}
	if(G.gKind==0 || G.gKind == 1)
		printf("��ͼ�ı���Ϊ%d\n", count_edge / 2);
	else
		printf("��ͼ�ı���Ϊ%d\n", count_edge);

	visitedclean();


}

//typedef struct treenode{
//	char data;
//	struct treenode* brothernode;
//	struct treenode* childnode;
//	
//}node;

/*void build_tree(int *forest,int count,int floor,Graph G,node* parentnode);
void add_child(int *forest,int count,int floor,Graph G,node* eldernode,bool isfirstchild)
{
	int i;
	int forestnum=1;
	while(i<=count)                                                      //ignore ( and ) start
	{
		if(*(forest+count*count*forestnum+floor*count+i)==1)
		{
			node* newnode=new node;
			newnode->brothernode=newnode->childnode=NULL;
			newnode->data=G.Data[i];
			printf("%c ",newnode->data);
			if(isfirstchild==1)
			{
				isfirstchild=0;
				eldernode->childnode=newnode;
				build_tree(forest,count,i,G,newnode);
				eldernode=newnode;
			}
			else
			{
				eldernode->brothernode=newnode;
				build_tree(forest,count,i,G,newnode);
				eldernode=newnode;
			}			
			//break;
		}
		i++;
	}
}



void build_tree(int *forest,int count,int floor,Graph G,node* parentnode)
{
//	int i=1;
	if(floor<=count)
	{
		int forestnum=1;
		node* newnode=parentnode;
	//	node* newnode=new node;
	//	newnode->brothernode=newnode->childnode=NULL;
	//	newnode->data=G.Data[floor];
	//	parentnode->childnode=newnode;
		
		
		//build_tree(forest,count,floor,G,newnode);
		add_child(forest,count,floor,G,newnode,1);
		
	}
	

	//printf(" %c ",G.Data[floor]);//*(forest+count*count*forestnum+floor*count+i));
	//while(i<=count)                                                    
	//{
	//	if(*(forest+count*count*forestnum+floor*count+i)==1)
	//	{
			
			//break;
	//	}
	//	i++;
	//}

} 
*/
void print_level(int *forest,int count,int floor,Graph G,int level,int &finished)
{
	int i=1;
	//int forestnum=1;
	//if(floor<=count)
	//printf(" %c ",G.Data[floor]);//*(forest+count*count*forestnum+floor*count+i));
	while(i<=count)                                                      //ignore ( and ) start
	{
		if(*(forest+count*count*level+floor*count+i)==1)
		{
			break;
		}
		i++;
	}
	if(i==count+1 && finished==0)
		return ;  								 //ignore ( and ) end
		
		
		
	printf(" %c ",G.Data[floor]);//*(forest+count*count*forestnum+floor*count+i));
	finished++;
	printf("(");
	i=1;
	while(i<=count)
	{
	//	printf("achieve");
	//	printf("%d ",*(forest+count*count*(forestnum)-1+floor*count+i));
		if(*(forest+count*count*level+floor*count+i)==1)
		{
			
			print_level(forest,count,i,G,level,finished);
		}
		i++;
	}
	printf(")");
}

void print_sheet(int *forest,int count,int floor,Graph G)
{
//	int tmp;
//	printf("%d_____",count);
//	while(tmp<count*count*count)
//	{
//		printf("%d ",*(forest+tmp));
//		if(*(forest+tmp)==1)
//		printf("%d_____",tmp);
//		if(tmp%count==0)
//			printf("\n");
//		tmp++;
//	}
	int level=1;
	int finished=0;
	while(level<=count)
	{
		print_level(forest,count,level,G,level,finished);
		if(finished!=0)
		{
			printf("\n");
			finished=0;
		}
		
		level++;
		
	}
	
	
}
/*void print_child(node* forest,DRAW *dp,int yleft,int floor);

int get_brother_num(node* branch)
{
	int count=0;
	while(branch!=NULL)
	{
		branch=branch->brothernode;
		count++;
	}
	return count;
	
}

void print_brother(node* firstchild,int &left,int floor,DRAW *dp)
{
	
	while(firstchild!=NULL)
	{
		addpixelc(dp,left,floor,firstchild->data);
		//	drawsmart(dp);
		//	getchar();
		left+=3;
		printf("%c ",firstchild->data);
		print_child(firstchild->childnode,dp,left,floor+1);
		firstchild=firstchild->brothernode;		
	}
}

void print_child(node* forest,DRAW *dp,int yleft,int floor)
{
	int left=yleft;
	while(forest!=NULL)
	{
		
		//printf("%c ",forest->data);
		print_brother(forest,left,floor,dp);
		forest=forest->childnode;
	//	left=yleft;
		printf("\n");
	}	
}

void print_tree(node* forest)
{
	forest=forest->childnode;
	DRAW *dp=drawstart(150,50);
	print_child(forest,dp,0,1);
	printf("\n*****\n");
	drawsmart(dp);
	drawclose(dp);
}*/



void f3()
{

	Graph G;
	int total;
	int ret;
	piece stack;
	stack.top = -1;
	int tmp;
	int v;
	bool tvisited[MaxVerNum]={1,1};
	//forest aforest;
	//aforest.ForestTreeNum=0;
	
	char path[32];
	printf("��������Ҫ������ļ�·��:\n");
	scanf("%s", path);
	CreateGrpFromFile(path, G);
	printGraph(G);
	int forest[G.VerNum+1][G.VerNum+1][G.VerNum+1]={0};	
	int treenum,branchnum,leafnum;
	visitedclean();
	printf("�����������������ʼ\n");

	total = 1;
	while (total <= G.VerNum)
	{

		if (visited[total] == true)
		{
			total++;
			continue;
		}
		v = total;
		printf("\n");
		treenum=v;
		while (v != 0)
		{
			
			visit(G, v);
			
			ret = firstAdj(G, v);
			while (visited[ret] == true)
			{
				
				ret = nextAdj(G, v, ret);
				if (ret == 0)
					break;
			}
			tmp = ret;
		//	lv=v;
			if(tvisited[ret]==false)
			{
				forest[treenum][v][ret]=1;
			//	printf("      %c - %c\n",G.Data[v],G.Data[ret]);
				tvisited[ret]=true;
			}	
					
			if (ret != 0 && visited[ret] == false)
			{
				do
				{
//					if(tvisited[ret]==false)
//					{
//						forest[1][lv][ret]=1;
//						tvisited[ret]=true;
//					}	
					
					ret = nextAdj(G, v, ret);
					if (ret != 0 && visited[ret] == false)
					{
						
						if(tvisited[ret]==false)
						{
						forest[treenum][v][ret]=1;
						tvisited[ret]=true;
						}
						
						instack(stack, ret);
					}

				}
				while (ret != 0);
				v = tmp;
				//printf("(");
			}
			else
			{
				do
				{
					v = outstack(stack);
				//	lv=v;
					
				}					
				while (visited[v] == true && v != 0);
			
						//printf(")");
			}
				
				
		}
	}
	printf("\n");
	printf("�������������������\n");

	visitedclean();
		printf("�߼���\n");
	int x=1,y=1,z=1;
	while(x<=G.VerNum)
	{
		y=1;
		while(y<=G.VerNum)
		{
			z=1;
			while(z<=G.VerNum)
			{
				if(forest[x][y][z]==1)
					printf("      %c - %c\n",G.Data[y],G.Data[z]);
			//	printf("%d ",forest[x][y][z]);
				z++;
			}
			//printf("\n");
			y++;
		}
		//printf("\n");
		x++;
	}
		printf("\n");
	
	
	
	printf("���ֵĹ�����ʾ��"); 
	print_sheet(&forest[0][0][0],G.VerNum+1,1,G);
	printf("\n");
	
	/*node* treeheadnode=new node;
	treeheadnode->brothernode=treeheadnode->childnode=NULL;
	treeheadnode->data='T';
	build_tree(&forest[0][0][0],G.VerNum+1,1,G,treeheadnode);
	print_tree(treeheadnode);*/
}



void f4()
{
	Graph G;
	int total;
	int ret;
	qlist queue;
	queue.rear = 0;
	queue.front = 0;
	int v,lv=1;
	char path[32];		
	printf("��������Ҫ������ļ�·��:\n");
	scanf("%s", path);
	CreateGrpFromFile(path, G);
	printGraph(G);
	int forest[G.VerNum+1][G.VerNum+1][G.VerNum+1]={0};
	bool tvisited[MaxVerNum]={1,1};
	
	int treenum,branchnum,leafnum;
//	treenum=branchnum=leafnum=0;
	visitedclean();
	printf("���������������������ʾ��\n");

	total = 1;
	while (total <= G.VerNum)
	{
		if (visited[total] == true)
		{
			total++;
			continue;
		}

		treenum=total;
		v = total;
		
		while (v != 0)
		{
			printf("%4c",G.Data[v]);
			visited[v]=true;
			branchnum=lv;
			//printf("%d ( ",lv);
			ret = firstAdj(G, v);
			while (ret != 0)
			{

				if(tvisited[ret]==false)
				{
					//printf("%c ",G.Data[ret]);
					forest[treenum][branchnum][ret]=1;
					
					tvisited[ret]=true;
				}

				inqueue(queue, ret);
				ret = nextAdj(G, v, ret);
			
			}
			//printf(")");
			
			do
			{
				v = outqueue(queue);
				
				lv=v;
			}
			while (visited[v] == true);
			
			
		}


	}	
	printf("\n");
	printf("������������������\n");
	visitedclean();
	
		printf("�߼���\n");
	int x=1,y=1,z=1;
	while(x<=G.VerNum)
	{
		y=1;
		while(y<=G.VerNum)
		{
			z=1;
			while(z<=G.VerNum)
			{
				if(forest[x][y][z]==1)
					printf("      %c - %c\n",G.Data[y],G.Data[z]);
			//	printf("%d ",forest[x][y][z]);
				z++;
			}
		//	printf("\n");
			y++;
		}
	//	printf("\n");
		x++;
	}
		printf("\n");
		
		
	printf("���ֵĹ�����ʾ��"); 
	print_sheet(&forest[0][0][0],G.VerNum+1,1,G);
	printf("\n");
	
	
	/*printf("������:\n");
	node* treeheadnode=new node;
	treeheadnode->brothernode=treeheadnode->childnode=NULL;
	treeheadnode->data='T';
	build_tree(&forest[0][0][0],G.VerNum+1,1,G,treeheadnode);
		printf("**********\n");
	print_tree(treeheadnode);*/
}

int isinTE(edgelist TE, edge identify)
{
	int i;
	for (i = 0; i < TE.len; i++)
	{
		if (identify.start == TE.data[i].start && identify.edge == TE.data[i].edge && identify.end == TE.data[i].end)
			return 1;
		else if(identify.end == TE.data[i].start && identify.edge == TE.data[i].edge && identify.start == TE.data[i].end)
			return 1;
	}
	return 0;
}



void insertalledge(edgelist &WE,int v,Graph G,edgelist TE)
{
	int ret;
	ret=firstAdj(G,v);
	while(ret!=0)
	{

		edge newedge;
		newedge.start=v;
		newedge.edge=G.AdjMatrix[v][ret];
		newedge.end=ret;
		//printf("%d    ",newedge.edge);
		//	getchar();
		if(isinTE(TE,newedge)==0 && visited[ret]==false)
		{
			WE.data[WE.len] = newedge;

			WE.len++;

		}


		ret=nextAdj(G,v,ret);
	}
}



int findminedge(edgelist WE,Graph G,edgelist TE)  //WE a point with an unknown point,
{

	int i;
	int min=0;
	while(isinTE(TE,WE.data[min])==1 ||  visited[WE.data[min].end]==true)
	{
		min++;
		if(min>WE.len)
		{
			//	printf("end");
			return -1;
		}
	}



	for (i = 0; i < WE.len; i++)
	{
		//	printf("%d     ",WE.data[i].edge);
		if (WE.data[i].edge < WE.data[min].edge && isinTE(TE,WE.data[i])==0 && visited[WE.data[i].end]==false)
		{

			min = i;
		}
	}
//	printf("\n");
	return min;


}




void deledge(edgelist &WE,int min,edgelist &TE)
{
	int i;

	TE.data[TE.len]=WE.data[min];
	TE.len++;
	for (i = min; i < WE.len; i++)
	{
		WE.data[i].start = WE.data[i + 1].start;
		WE.data[i].end = WE.data[i+1].end;
		WE.data[i].edge = WE.data[i + 1].edge;

	}
	WE.len--;



}

bool isVisitedAll(Graph G)
{
	int i;
	for(i=1; i<G.VerNum; i++)
	{
		if(visited[i]==false)
			return false;
	}
	return true;
}


void f5()
{
	Graph G;
	int total;
	int edge_count=0;
	int ret;
	qlist queue;
	queue.rear = 0;
	queue.front = 0;
	int v;
	char path[32];
	printf("��������Ҫ������ļ�·��:\n");
	scanf("%s", path);
	CreateGrpFromFile(path, G);
	printGraph(G);
	visitedclean();
	seqlist S, U;
	edgelist WE, TE;
	S.len=U.len=WE.len=TE.len=0;
	v=1;
	printf("prim������ʼ\n");
	insertalledge(WE, v, G,TE);
	while(isVisitedAll(G)==false)
	{
		//S.data[S.len]=v;
		//S.len++;



		visited[v]=true;
		ret=findminedge(WE, G, TE);
		if(ret==-1)
		{
			break;
		}
		printf(" %d -> %d ",WE.data[ret].start,WE.data[ret].end);
		edge_count+=WE.data[ret].edge;
		v=WE.data[ret].end;
		//printf("  v:%d  ",v);
		deledge(WE,ret,TE);
		insertalledge(WE, v, G,TE);
		//getchar();
	}
	printf("·������Ϊ%d.\n",edge_count);
	visitedclean();
	printf("prim�������\n");


}

void samelabel(int a,int b,Graph G,int VerLabel[])
{

	int tmp1=VerLabel[a-1],tmp2=VerLabel[b-1],i;
//	printf(" samelabel(%d,%d) ",tmp1,tmp2);
	for(i=0; i<G.VerNum; i++)
	{
		if(VerLabel[i]==tmp1)
			VerLabel[i]=tmp2;
	}
}

void insertalledge_kruskal(edgelist &WE,int v,Graph G,int VerLabel[])
{
	int ret;
	ret=firstAdj(G,v);
	while(ret!=0)
	{

		edge newedge;
		newedge.start=v;
		newedge.edge=G.AdjMatrix[v][ret];
		newedge.end=ret;
		//printf("%d    ",newedge.edge);
		//	getchar();

		//samelabel(v,ret,G,VerLabel);
		WE.data[WE.len] = newedge;
		WE.len++;
		ret=nextAdj(G,v,ret);
	}
}

int findminedge_kruskal(edgelist WE,Graph G,edgelist TE,int VerLabel[])  //WE a point with an unknown point,
{

	int i;
	int min=0;
	while(isinTE(TE,WE.data[min])==1 ||  visited[WE.data[min].end]==true)
	{
		min++;
		if(min>WE.len)
		{
			//	printf("end");
			return -1;
		}
	}

	for (i = 0; i < WE.len; i++)
	{

		//	printf("%d     ",WE.data[i].edge);
		if (WE.data[i].edge < WE.data[min].edge && isinTE(TE,WE.data[i])==0 )
		{

			if( VerLabel[WE.data[i].end-1]==VerLabel[WE.data[i].start-1])
			{
				//	printf("(%d and %d)",WE.data[i].end,WE.data[i].start);
				continue;
			}

			min = i;
		}
	}
//	printf("\n");
	return min;
}


void f6()
{
	edgelist WE,TE;
	WE.len=TE.len=0;
	Graph G;
	int total;
	int ret;
	piece stack;
	stack.top = -1;
	int tmp;
	int v;
	int VerLabel[MaxVerNum]= {0};
	int edge_count=0,edge_number=0;
	char path[32];
	printf("��������Ҫ������ļ�·��:\n");
	scanf("%s", path);
	CreateGrpFromFile(path, G);
	printGraph(G);

	visitedclean();
	printf("kruskal�㷨��ʼ\n");
	total = 1;
	while (total <= G.VerNum)
	{

		if (visited[total] == true)
		{
			total++;
			continue;
		}
		v = total;

		while (v != 0)
		{
			//	visit(G, v);
			insertalledge_kruskal(WE,v,G,VerLabel);
			visited[v]=true;
			VerLabel[v-1]=v;
			//	if(v==0)
			//	{
			//		printf("what");
			//	}
			ret = firstAdj(G, v);
			while (visited[ret] == true)
			{
				ret = nextAdj(G, v, ret);
				if (ret == 0)
					break;
			}
			tmp = ret;
			if (ret != 0 && visited[ret] == false)
			{
				do
				{
					ret = nextAdj(G, v, ret);
					if (ret != 0 && visited[ret] == false)
					{
						instack(stack, ret);
					}

				}
				while (ret != 0);
				v = tmp;
			}
			else
				do
					v = outstack(stack);
				while (visited[v] == true && v != 0);
		}
	}
	visitedclean();

	while( edge_number<G.VerNum-1)
	{
		ret=findminedge_kruskal(WE,G,TE,VerLabel);
		printf(" %d -> %d ",WE.data[ret].start,WE.data[ret].end);
		edge_count+=WE.data[ret].edge;
		edge_number++;
		//visited[WE.data[ret].start]=visited[WE.data[ret].end]=true;
		samelabel(WE.data[ret].start,WE.data[ret].end,G,VerLabel);
		//	samelabel(WE.data[ret].start,WE.data[ret].end,G,VerLabel);
		//	int i;
		//	for(i=0;i<G.VerNum;i++)
		//		printf("%d  ",VerLabel[i]);

		//deledge(WE,ret,TE);
	}


	printf("\n");
	printf("·������Ϊ%d.\n",edge_count);
	printf("kruskal�㷨���\n");
}



int isinTE_dijkstra(edgelist TE, edge identify)
{
	int i;
	for (i = 0; i < TE.len; i++)
	{
		if (identify.start == TE.data[i].start && identify.edge == TE.data[i].edge && identify.end == TE.data[i].end)
			return 1;
		else if(identify.end == TE.data[i].start && identify.edge == TE.data[i].edge && identify.start == TE.data[i].end)
			return 1;
	}
	return 0;
}



void insertalledge_dijkstra(edgelist &WE,int v,Graph G,edgelist TE,edgelist shortpath[])
{
	int ret;
	ret=firstAdj(G,v);
	while(ret!=0)
	{

		edge newedge;
		newedge.start=v;
		newedge.edge=G.AdjMatrix[v][ret];
		newedge.end=ret;
		//printf("%d    ",newedge.edge);
		//	getchar();

		if(isinTE(TE,newedge)==0 && visited[ret]==false)
		{
			//	printf("(%d %d)",shortpath[ret].edgeslen,shortpath[v].edgeslen+G.AdjMatrix[v][ret]);
			if(shortpath[ret].edgeslen>shortpath[v].edgeslen+G.AdjMatrix[v][ret])
			{

				shortpath[ret].len=shortpath[v].len;
				shortpath[ret].edgeslen=shortpath[v].edgeslen;
				for(int tmp=0 ; tmp<shortpath[ret].len ; tmp++)
				{
					shortpath[ret].data[tmp].start=shortpath[v].data[tmp].start;
					shortpath[ret].data[tmp].edge=shortpath[v].data[tmp].edge;
					shortpath[ret].data[tmp].end=shortpath[v].data[tmp].end;
				}


				shortpath[ret].data[shortpath[ret].len]=newedge;
				shortpath[ret].len++;
				shortpath[ret].edgeslen+=newedge.edge;
				//	printf("::::::::%d ",shortpath[ret].edgeslen);
			}

			WE.data[WE.len] = newedge;

			WE.len++;

		}


		ret=nextAdj(G,v,ret);
	}
}



int findminedge_dijkstra(edgelist WE,Graph G,edgelist TE)  //WE a point with an unknown point,
{

	int i;
	int min=0;
	while(isinTE(TE,WE.data[min])==1 ||  visited[WE.data[min].end]==true)
	{
		min++;
		if(min>WE.len)
		{
			//	printf("end");
			return -1;
		}
	}



	for (i = 0; i < WE.len; i++)
	{
		//	printf("%d     ",WE.data[i].edge);
		if (WE.data[i].edge < WE.data[min].edge && isinTE(TE,WE.data[i])==0 && visited[WE.data[i].end]==false)
		{

			min = i;
		}
	}
//	printf("\n");

	return min;


}




void deledge_dijkstra(edgelist &WE,int min,edgelist &TE)
{
	int i;

	TE.data[TE.len]=WE.data[min];
	TE.len++;
	for (i = min; i < WE.len; i++)
	{
		WE.data[i].start = WE.data[i + 1].start;
		WE.data[i].end = WE.data[i+1].end;
		WE.data[i].edge = WE.data[i + 1].edge;

	}
	WE.len--;



}




void f7()
{
	Graph G;
	int total;
//	int edge_count=0;
	int ret;
	int i;

	qlist queue;
	queue.rear = 0;
	queue.front = 0;
	int v;
	char path[32];
	printf("��������Ҫ������ļ�·��:\n");
	scanf("%s", path);
	CreateGrpFromFile(path, G);
	printGraph(G);
	edgelist shortpath[G.VerNum+1];
	for(i=1; i<=G.VerNum; i++)
	{

		shortpath[i].len=0;
		shortpath[i].edgeslen=INF;
	}

	visitedclean();
	printf("������ָ������:");
	fflush(stdin);
	scanf("%d",&v);
//	yv=v;
	seqlist S, U;
	edgelist WE, TE;
	S.len=U.len=WE.len=TE.len=0;
//	v=1;

	printf("dijkstra������ʼ\n");
//	insertalledge_dijkstra(WE, v, G,TE,shortpath);



	ret=firstAdj(G,v);
	while(ret!=0)
	{
		shortpath[ret].data[shortpath[ret].len].start=v;
		shortpath[ret].data[shortpath[ret].len].edge=G.AdjMatrix[v][ret];
		shortpath[ret].data[shortpath[ret].len].end=ret;
		//	printf(" %d ",shortpath[ret].data[shortpath[ret].len].start);
		//	printf(" %d ",shortpath[ret].data[shortpath[ret].len].edge);
		//	printf(" %d ",shortpath[ret].data[shortpath[ret].len].end);
		shortpath[ret].edgeslen=G.AdjMatrix[v][ret];
		shortpath[ret].len++;
		ret=nextAdj(G,v,ret);
	}

	/*	for(int tmp=1;tmp<=G.VerNum;tmp++)
		{
			printf("%d->%d : %d\n",shortpath[tmp].data[0].start,shortpath[tmp].data[shortpath[tmp].len-1].end,shortpath[tmp].edgeslen);
		}
		printf("---------\n");
		*/
	insertalledge(WE,v,G,TE);
	while(isVisitedAll(G)==false)
	{
		//S.data[S.len]=v;
		//S.len++;



		visited[v]=true;
		ret=findminedge_dijkstra(WE, G, TE);
		if(ret==-1)
		{
			break;
		}
		//	if(shortpath[ret]>shortpath[v].edgeslen+WE.data[ret].edge)
		//	{
		//		int i;
		//		for(i=0;i<shortpath[v])
		//	}
		//

		//printf(" %d -> %d ",WE.data[ret].start,WE.data[ret].end);
		//edge_count+=WE.data[ret].edge;
		v=WE.data[ret].end;
		//printf("  v:%d  ",v);
		deledge_dijkstra(WE,ret,TE);

//		for(int tmp=1;tmp<=G.VerNum;tmp++)
//	{
//		printf("%d->%d : %d\n",shortpath[tmp].data[0].start,shortpath[tmp].data[shortpath[tmp].len-1].end,shortpath[tmp].edgeslen);
//	}
//	printf("---------\n");

		insertalledge_dijkstra(WE, v, G,TE,shortpath);
		//getchar();
	}
	//printf("·������Ϊ%d.\n",edge_count);
	visitedclean();

	for(int tmp=1; tmp<=G.VerNum; tmp++)
	{
		if(shortpath[tmp].edgeslen==INF)
		{
			//printf("%d->%d, no available way\n",shortpath[tmp].data[0].start,shortpath[tmp].data[shortpath[tmp].len-1].end);
			continue;
		}
		int t,ii;
		printf("%2d-->%2d:  %2d->",shortpath[tmp].data[0].start,shortpath[tmp].data[shortpath[tmp].len-1].end,shortpath[tmp].data[0].start);
		for(t=0; t<shortpath[tmp].len-1; t++)
		{
			printf("%2d->",shortpath[tmp].data[t].end);
		}
		printf("%2d",shortpath[tmp].data[t].end);
		for(ii=0; ii<12+4*G.VerNum-4*t; ii++)
			printf(" ");
		printf("  total:%2d\n",shortpath[tmp].edgeslen);
		//printf("%d->%d : %d\n",shortpath[tmp].data[0].start,shortpath[tmp].data[shortpath[tmp].len-1].end,shortpath[tmp].edgeslen);
	}


	printf("dijkstra�������\n");
}

void f8()
{
	Graph G;
	int total;
//	int edge_count=0;
	int ret;
	int i;

	qlist queue;
	queue.rear = 0;
	queue.front = 0;
	int v,yv=1;
	char path[32];
	printf("��������Ҫ������ļ�·��:\n");
	scanf("%s", path);
	CreateGrpFromFile(path, G);
	printGraph(G);
	edgelist shortpath[G.VerNum+1];
	seqlist S, U;
	edgelist WE, TE;


	printf("floyd������ʼ\n");

	while(yv<G.VerNum)
	{

		for(i=1; i<=G.VerNum; i++)
		{

			shortpath[i].len=0;
			shortpath[i].edgeslen=INF;
		}
		S.len=U.len=WE.len=TE.len=0;
		visitedclean();
		v=yv;


		ret=firstAdj(G,v);
		while(ret!=0)
		{
			shortpath[ret].data[shortpath[ret].len].start=v;
			shortpath[ret].data[shortpath[ret].len].edge=G.AdjMatrix[v][ret];
			shortpath[ret].data[shortpath[ret].len].end=ret;
			shortpath[ret].edgeslen=G.AdjMatrix[v][ret];
			shortpath[ret].len++;
			ret=nextAdj(G,v,ret);
		}
		insertalledge(WE,v,G,TE);
		while(isVisitedAll(G)==false)
		{

			visited[v]=true;
			ret=findminedge_dijkstra(WE, G, TE);
			if(ret==-1)
			{
				break;
			}
			v=WE.data[ret].end;
			deledge_dijkstra(WE,ret,TE);

			insertalledge_dijkstra(WE, v, G,TE,shortpath);
		}


		for(int tmp=1; tmp<=G.VerNum; tmp++)
		{
			if(shortpath[tmp].edgeslen==INF)
			{
				continue;
			}
			printf("%2d-->%2d",shortpath[tmp].data[0].start,shortpath[tmp].data[shortpath[tmp].len-1].end);
			printf("  total:%2d\n",shortpath[tmp].edgeslen);
		}

		yv++;
	}

	visitedclean();

	printf("floyd�������\n");
}

int topoList[MaxVerNum+1];
int topoList2[MaxVerNum+1];


//��ʼ����ȡÿ���������ȣ������������inds[]��
void GetInDegrees(Graph &G, int inds[])
{
	int i,j;
	for(j=1;j<=G.VerNum;j++)  //�ڽӾ�����ѭ��
	{
		for(i=1;i<=G.VerNum;i++)  //�ڽӾ�����ѭ��
		{
			if(G.AdjMatrix[i][j]>=1 && G.AdjMatrix[i][j]<INF)
				inds[j]++;  //���j����ȼ�1.
		}
	}

	//for(i=1;i<=G.VerNum;i++)  //���ÿ������ĳ�ʼ���
	//{
	//	cout<<i<<"--"<<inds[i]<<endl;
	//}
}

//���������㷨--ʹ��ջ
int TopologicalSortS(Graph &G, int topoList[])
{
	int inds[MaxVerNum];  //���嶥���������
	piece S;  //����һ��˳��ջ���������Ϊ0�Ķ���
	int i;
	int v;  //������
	int vCount=0; //��¼�������Ϊ0�Ķ�����
	
	S.top=-1;  //��ʼ��ջ

	for(i=1;i<=G.VerNum;i++)
		inds[i]=0;  //��������ʼ��

	//�������������ʼ��
	for(i=1;i<G.VerNum;i++)		
		topoList[i]=-1;  //��ʼ��������Ϊ-1

	//���ڽӾ����ȡͼ�и�������ĳ�ʼ���
	GetInDegrees(G, inds);

	//���Ϊ0�Ķ�����ջ
	for(i=1;i<=G.VerNum;i++)
	{
		if(inds[i]==0)
			instack(S,i);
	}

	while(!isempty(S))
	{
		v=outstack(S);  //��ջ������һ�����Ϊ0�Ķ����ŵ�v
		topoList[vCount+1]=v;  //��ǰ���Ϊ0����v��������������
		vCount++;  //�Ѵ����㣨���Ϊ0������1		

		//��v�ڽӵĶ������ȼ�1
		for(i=1;i<=G.VerNum;i++)
		{			
			if(G.AdjMatrix[v][i]>=1 && G.AdjMatrix[v][i]<INF && inds[i]>0)
			{
				inds[i]--;  //��v�ڽӵĶ���i����ȼ�1
				if(inds[i]==0) //����i������Ѿ�Ϊ0����ջ
					instack(S,i);
			}
		}
	}

	if(vCount==G.VerNum)
		return 1;  //�����޻�·���
	else	
		return 0;  //�л�·�����ܲ�����������
}


void f9()
{
	Graph G;
	int total;
//	int edge_count=0;
	int ret;
	int i;

	qlist queue;
	queue.rear = 0;
	queue.front = 0;
	int v,yv=1;
	char path[32];
	printf("��������Ҫ������ļ�·��:\n");
	scanf("%s", path);
	CreateGrpFromFile(path, G);
	printGraph(G);
	
	
	if(TopologicalSortS(G, topoList)) //�������������㷨--��ʹ��ջ�����У�����һ��solved[]����
			{
				printf("\n");
				printf("��ͼ��������ɹ����������У�\n");
				for(i=1;i<=G.VerNum;i++)  //�Զ����������������
					printf("%d\t",topoList[i]);
				printf("\n or \n");
				for(i=1;i<=G.VerNum;i++)  //�Զ���Ԫ�������������
					printf("%c\t",G.Data[topoList[i]]);
				printf("\n\n");
			}
			else
			{
				printf("\n��ͼ���л�·����������ʧ�ܡ�\n\n");
			}
		

}



int n;
int a[100][100];//ÿ�����ֱ�Ӻ��?
int b[100][100];//ÿ�����ֱ��ǰ��
int ea[10000];//ĳ���ߵ����
int eb[10000];//ĳ���ߵ��յ�?
int Ve[100];//�¼������緢��ʱ��?
int Vl[100];//�¼�����ٷ���ʱ��
int early[10000];//������翪ʼʱ��
int late[10000];//�����ٷ���ʱ��
int le[10000];//�����?
bool guanjian[10000];//�ؼ�·��?
void dfs(int p)
{
	if (p == n)
		return;
	for (int i = p + 1; i <= n; i++)
	{
		int temp;
		if (a[p][i] != -1)
		{
			temp = Ve[p] + a[p][i];
			if (temp > Ve[i])
			{
				Ve[i] = temp;
			}
			dfs(i);
		}
	}
}
void dfs2(int p)
{
	if (p == 1)
		return;
	for (int i = p; i >= 1; i--)
	{
		int temp;
		if (b[p][i] != -1)
		{
			temp = Vl[p] - b[p][i];
			if (temp < Vl[i])
			{
				Vl[i] = temp;
			}
			dfs2(i);
		}
	}
}


void f10()

{
	Graph G;
	int total;
	//	int edge_count=0;
	int ret;
	int i,m;
	int v, yv = 1;
	int compare;
	char path[32];
	printf("��������Ҫ������ļ�·��:\n");
	scanf("%s", path);
	CreateGrpFromFile(path, G);
	printGraph(G);
	
	n = G.VerNum;
	

	int s, e, p;
	memset(a, -1, sizeof(a));
	memset(b, -1, sizeof(b));
	memset(ea, -1, sizeof(ea));
	memset(eb, -1, sizeof(eb));
	memset(guanjian, 0, sizeof(guanjian));
	//�����е������д�����
	int m = 0;
	//while (1)
	{
		//scanf("%d%d%d", &s, &e, &p);
		int x, y;
		for (x = 1; x <= G.VerNum; x++)
		{
			for (y = 1; y <= G.VerNum; y++)
			{
				if (G.AdjMatrix[x][y] < INF && G.AdjMatrix[x][y] >= 1)
				{
					s = x;
					e = y;
					p = G.AdjMatrix[x][y];
					m++;
					//if (s == 0)
					//	break;
					ea[m] = s;
					eb[m] = e;
					a[s][e] = p;
					b[e][s] = p;//��Ȼֻ��һ���ߣ��������ǿ���������ȷ���ҵ�ֱ��ǰ��?

				}
			}
		}


		
	//}
	m--;
	//��ȡÿ�������Ve��Vl
	memset(Ve, 0, sizeof(Ve));
	memset(Vl, 0, sizeof(Ve));
	int start = 1;
	dfs(1);
	printf("Ve:\n");
	for (int i = 1; i <= n; i++)
	{
		Vl[i] = 9999999;
		printf("%d ", Ve[i]);
	}
	Vl[n] = Ve[n];
	printf("\n");
	dfs2(n);
	printf("Vl:\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", Vl[i]);
	}
	printf("\n");
	for (int i = 1; i <= m; i++)
	{
		early[i] = Ve[ea[i]];
		late[i] = Vl[eb[i]] - a[ea[i]][eb[i]];
		le[i] = late[i] - early[i];
	}

	printf("edge ?e ? l ? l-e\n");
	for (int i = 1; i <= m; i++)
	{
		printf("%3d %3d %3d %3d\n", i, early[i], late[i], le[i]);

	}
	printf("���Թؼ�·���ǣ�\n");
	for (int i = 1; i <= m; i++)
	{
		if (!le[i])
		{
			printf("a%d ", i);
		}
	}
	printf("\n");
	
}
//
//#include"aoe.h"
//
//void f10()
//{
//	Graph G;
//	char path[32];
//	printf("��������Ҫ������ļ�·��:\n");
//	scanf("%s", path);
//	CreateGrpFromFile(path, G);
//	printGraph(G);
//	 fflush(stdin);
//	 
//	ALGraph *AG;
//    CreateAOE(&AG,G);//����AOE��
//    T.top=-1;
//    //initStack(&T);
//    TopologicalOrder(*AG);
//   // printf("break");
//    CriticalPath(*AG);
//
//
//}


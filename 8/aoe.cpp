
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>



#include"grpAdjMatrix.h"
#include"createGrpAdjMatrix.h"

void indegree(Graph G,int vd[])
{
	int count=G.VerNum,i,detect;
	for(i=1;i<=count;i++)
	{
		for(detect=1;detect<=count;detect++)
		{
			if(G.AdjMatrix[detect][i]<INF && G.AdjMatrix[detect][i]>=1)
			{
				break;
			}
		}
		//printf("%d ",visited[i]);
		if(detect==count+1 && visited[i]==false)
		{
			detect=i;
			for(i=1;i<=count;i++)
			{
			
				if(G.AdjMatrix[detect][i]<INF && G.AdjMatrix[detect][i]>=1)
				{
					vd[i]=vd[i]>G.AdjMatrix[detect][i]+vd[detect]?vd[i]:G.AdjMatrix[detect][i]+vd[detect];
			//		printf("%d ",G.AdjMatrix[detect][i]);
			//		printf("%d ",vd[i]);
				}
			}
			for(i=1;i<=count;i++)
			{
				G.AdjMatrix[detect][i]=INF;
			}
			visited[detect]=true;
		//	printf("%d \n",detect);
		//	getchar();
			i=1;
		}
		
	}
}

void  outdegree(Graph G,int vd[])
{
	int count=G.VerNum,i,detect;
	for(i=1;i<=count;i++)
	{
		for(detect=1;detect<=count;detect++)
		{
			if(G.AdjMatrix[i][detect]<INF && G.AdjMatrix[i][detect]>=1)
			{
				break;
			}
		}
	//	printf("%d?? ",i);
		if(detect==count+1 && visited[i]==false)
		{
			
			detect=i;
			for(i=1;i<=count;i++)
			{
			
				if(G.AdjMatrix[i][detect]<INF && G.AdjMatrix[i][detect]>=1)
				{
				
					vd[i]=vd[i]<vd[detect]-G.AdjMatrix[i][detect]?vd[i]:vd[detect]-G.AdjMatrix[i][detect];
					//printf("G.AdjMatrix[i][detect]:%d ",G.AdjMatrix[i][detect]);
					//printf("vd[detect]:%d ",vd[detect]);
					//printf("vd[i]:%d ",vd[i]);
				}
			}
			for(i=1;i<=count;i++)
			{
				G.AdjMatrix[i][detect]=INF;
			}
			visited[detect]=true;
		//	printf("detect:%d \n",detect);
		//	getchar();
			i=1;
		}
		
	}
}


void visitedclean()
{
	int i;
	for(i=0;i<MaxVerNum;i++)
		visited[i]=false;
}


void printpath(Graph G,int vd[],int vo[],int startpoint,piece &astack)
{
	int ret;
	ret=firstAdj(G,startpoint);
	do
	{
		if(vd[ret]==vo[ret])
		{
			//printf("%d-",ret);
			instack(astack,ret);
			printpath(G,vd,vo,ret,astack);
			outstack(astack);
		}			
		ret=nextAdj(G,startpoint,ret);
		if(ret==0)
		{
			showstack()
		}
	}while(ret!=0);
}

int main()
{
	piece stack;
	Graph  G;
	int i;
	char filepath[32]="1.grp";
	CreateGrpFromFile( filepath,G);
	printGraph(G);
	int vd[G.VerNum+1]={0};
	int vo[G.VerNum+1]={0};
	visitedclean();
	indegree(G,vd);
	for(i=1;i<=G.VerNum;i++)
	{
		printf("%d ",vd[i]);
	}
	printf("early: ");
	for(i=1;i<=G.VerNum;i++)
	{
		vo[i]=vd[G.VerNum];
		//vo[i]=0;
	}
//vo[G.VerNum]=vd[G.VerNum];
	printf("\n");
	visitedclean();
	outdegree(G,vo);
	printf("late: ");
	for(i=1;i<=G.VerNum;i++)
	{
		printf("%d ",vo[i]);
	}
	printf("\n");
	visitedclean();
	
	printpath(G,vd,vo,1,stack);	
	
	printf("\n");
	return 0;
}

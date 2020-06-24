#pragma once
#include "virtualscreen.h"
#include <math.h>
void 
quicksort(int *data,int start,int end,int n,int *ret)
{
	//printf("start:%d end:%d mid:%d\n",start,end,*(data+start));
//	int compare_count=0,exchange_count=0;
//	int *ret[2]= {&compare_count,&exchange_count};

	int mid=start;
	int i;
	int ystart=start;
	int yend=end;
	int init=*(data+mid);
	//start++;
	while(start<=end)
	{

		while(start<=end && *(data+end)>init)
		{
			(*ret)++;
			//		printf("%d ? %d\n",*(data+end),init);
			end--;
		}

		if(start>end)
			break;
		//	printf("%d < %d: ",*(data+end),init);
		(*(ret+1))++;
		*(data+mid)=*(data+end);
		mid=end;
		end--;

	//	for(i=0; i<n; i++)
	//	{
	//		printf("%d ",*(data+i));
	//	}
	//	printf("\n");

		while(start<=end && *(data+start)<init)
		{
			(*ret)++;
			//	printf("%d ? %d\n",*(data+start),init);
			start++;
		}

		if(start>end)
			break;
		//	printf("%d > %d: ",*(data+start),init);
		(*(ret+1))++;
		*(data+mid)=*(data+start);
		mid=start;
		start++;

//		for(i=0; i<n; i++)
	//	{
	//		printf("%d ",*(data+i));
	//	}
	//	printf("\n");
//		while(1) {
//			if(*(data+end)<init) {
//
//				*(data+mid)=*(data+end);
//				mid=end;
//				end--;
//				printf("%d < %d: ",*(data+end),init);
//				for(i=0; i<n; i++) {
//
//					printf("%d ",*(data+i));
//				}
//				printf("\n");
//				break;
//			}
//
//			end--;
//
//
//		}
//		while(1) {
//			if(*(data+start)>init) {
//				*(data+mid)=*(data+start);
//				mid=start;
//				start++;
//				printf("%d > %d: ",*(data+end),init);
//				for(i=0; i<n; i++) {
//
//					printf("%d ",*(data+i));
//				}
//				printf("\n");
//				break;
//			}
//
//			start++;
//
//
//		}

	}
	(*(ret+1))++;
	*(data+mid)=init;

	//for(i=0; i<n; i++) {

	//	printf("%d ",*(data+i));
	//}
	//printf("----------------------------\n");
	//getchar();
	if(ystart<mid-1)
	{
		//printf("start:%d end:%d\n",ystart,mid-1);
		quicksort(data,ystart,mid-1,n,ret);
	}

	if(mid+1<yend)
	{
		//printf("start:%d end:%d\n",mid+1,yend);
		quicksort(data,mid+1,yend,n,ret);
	}
//	printf("???????%d %d!!!!!!!!!!!",exchange_count,compare_count);
//	return *ret;
//	return mid;
}

void f1()
{
	int *data=NULL;
	int n,i;
	int ret[2]={0};
	
	printf("请输入所要求的数据个数:");
	scanf("%d",&n);
	srand(n);
	fflush(stdin);
	data=(int*)calloc(sizeof(int),n);
	printf("快速排序前：\n");
	for(i=0; i<n; i++)
	{
		*(data+i)=rand()%1000;
		printf("%d ",*(data+i));
	}
	printf("\n");
	printf("快速排序每趟过程：\n");
	quicksort(data,0,n-1,n,ret);
	printf("快速排序后：\n");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("\n");
	printf("交换次数:%d ; ",ret[1]);
	printf("比较次数:%d\n",ret[0]);
	printf("开始释放内存\n");
	free(data);
	printf("释放内存完毕\n");
}

void quicksortmod(int *data,int start,int end,int n,int *ret)
{

	int tmp,i;
	int mod1start=start,mod2end=end;
	while(start<mod2end)
	{
		while(*(data+start)%3==1)
		{
			(*(ret))++;
			start++;
		}
		for(i=0; i<n; i++)
		{
			printf("%d ",*(data+i));
		}
		printf("\n");
	//	getchar();
		if(*(data+start)%3==0)
		{
			tmp=*(data+mod1start);
			*(data+mod1start)=*(data+start);
			*(data+start)=tmp;
			mod1start++;
			(*(ret+1))++;
			//start++;
		}
		if(*(data+start)%3==2)
		{
			tmp=*(data+mod2end);
			*(data+mod2end)=*(data+start);
			*(data+start)=tmp;
			mod2end--;
			(*(ret+1))++;
		}
		//start++;

	}
//	printf(":%d",start);
	//*(data+mod)=init;

}

void f2()
{
	int *data=NULL;
	int i;
	int n;
	char path[32];
	int ret[2]={0};
	printf("请输入数据文件路径:");
	scanf("%s",path);
	fflush(stdin);
	FILE *fp=fopen(path,"rb");
	if(fp==NULL)
	{
		printf("error,cannot find the file.");
		return;
	}
	fread(&n,sizeof(int),1,fp);
	data=(int*)calloc(sizeof(int),n);
	fread(data,sizeof(int),n,fp);
	printf("文件读入完毕\n");
	fclose(fp);
	printf("分组前：\n");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("\n");
	printf("分组中：\n");
	quicksortmod(data,0,n-1,n,ret);
	printf("分组后：\n");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("\n");
	printf("交换次数:%d ; ",ret[1]);
	printf("比较次数:%d\n",ret[0]);
	printf("开始释放内存\n");
	free(data);
	printf("释放内存完毕\n");
}

void directsort(int *data,int n)
{
	int count=0;
	int i,wall=1,tmp,j;
	int dn=1;

	while(dn>0)
	{

		for(i=dn; i<=n; i++)
		{
			tmp=*(data+i);
			j=i;
			while(j>=dn && tmp<*(data+j-dn))
			{
				count++;
				*(data+j)=*(data+j-dn);
				j=j-dn;
			}
			*(data+j)=tmp;
		}

		dn/=2;
	}
	printf("直接排序完成后:");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("共移动元素%d次\n",count);
	printf("\n");
}

void shellsort(int *data,int n,int initd,int div)
{
	int count=0;
	int i,wall,tmp,ii,iii,j;
	int dn=initd;

	while(dn>0)
	{

		for(i=dn; i<=n; i++)
		{
			tmp=*(data+i);
			j=i;
			while(j>=dn && tmp<*(data+j-dn))
			{
				count++;
				*(data+j)=*(data+j-dn);
				j=j-dn;
			}
			*(data+j)=tmp;
		}

		dn/=div;
	}

	printf("shell排序完成后:");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("共移动元素%d次\n",count);
	printf("\n");
}


void f3()
{
	int *data=NULL;
	int i;
	int n;
	int initd;
	int div;
	char path[32];
	printf("请输入数据文件路径:");
	scanf("%s",path);
	fflush(stdin);
	FILE *fp=fopen(path,"rb");
	if(fp==NULL)
	{
		printf("error,cannot find the file.");
		return;
	}
	fread(&n,sizeof(int),1,fp);
	data=(int*)calloc(sizeof(int),n);
	fread(data,sizeof(int),n,fp);
	printf("文件读入完毕\n");
	fclose(fp);
	printf("请输入初始步长：");
	scanf("%d", &initd);
	printf("请输入步长变化率：");
	do {
		scanf("%d", &div);
		if (div <= 1)
		{
			printf("请重新输入div, div应大于1");
		}
	} while (div <= 1);
	
	//printf("排序前：\n");
	//for(i=0; i<n; i++)
	//{
	//	printf("%d ",*(data+i));
	//}
	//printf("\n");

	//directsort(data,n);



	//fp=fopen(path,"rb");

	//fread(&n,sizeof(int),1,fp);
	//if(fp==NULL)
	//{
		//printf("error,cannot find the file.");
		//return;
	//}
	//fread(data,sizeof(int),n,fp);
	//printf("文件重新读入完毕\n");
	//fclose(fp);
	printf("排序前：\n");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("\n");
	shellsort(data,n, initd, div);


}


void quicksort_step(int *data,int start,int end,int n)
{

	int mid=start;
	int i;
	int ystart=start;
	int yend=end;
	int init=*(data+mid);
	while(start<=end)
	{

		while(start<=end && *(data+end)>init)
		{
			end--;
		}

		if(start>end)
			break;
		*(data+mid)=*(data+end);
		mid=end;
		end--;
		for(i=0; i<n; i++)
		{
			printf("%d ",*(data+i));
		}
		printf("\n");
		while(start<=end && *(data+start)<init)
		{
			start++;
		}
		if(start>end)
			break;
		*(data+mid)=*(data+start);
		mid=start;
		start++;

		for(i=0; i<n; i++)
		{
			printf("%d ",*(data+i));
		}
		printf("\n");
	}
	*(data+mid)=init;
	if(ystart<mid-1)
	{

		quicksort_step(data,ystart,mid-1,n);
	}

	if(mid+1<yend)
	{

		quicksort_step(data,mid+1,yend,n);
	}

}




void f4()
{
	int *data=NULL;
	int i;
	int n;
	char path[32];
	printf("请输入数据文件路径:");
	scanf("%s",path);
	fflush(stdin);
	FILE *fp=fopen(path,"rb");
	if(fp==NULL)
	{
		printf("error,cannot find the file.");
		return;
	}
	fread(&n,sizeof(int),1,fp);
	data=(int*)calloc(sizeof(int),n);
	fread(data,sizeof(int),n,fp);
	printf("文件读入完毕\n");
	fclose(fp);

	printf("快速排序前：\n");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("\n");
	printf("快速排序每趟过程：\n");
	quicksort_step(data,0,n-1,n);
	printf("快速排序后：\n");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("\n");
	printf("开始释放内存\n");
	free(data);
	printf("释放内存完毕\n");

}

typedef struct tree
{
	int data;
	int Lchild;
	int Rchild;
} tr;



void sift(int *data,int start,int end)
{
	int tmp;
	int yend=end;
	int unfinished=1;
	while(unfinished==1)
	{
		unfinished=0;
		end=yend;
		while(end>=start && (end-1+start)/2>=start)
		{
			if(*(data+(end+start-1)/2)>*(data+end))
			{
				tmp=*(data+(end+start-1)/2);
				*(data+(end+start-1)/2)=*(data+end);
				*(data+end)=tmp;




				unfinished=1;
			}
			end--;
		}
	}




}

void drawtree(int *data,int n,int c,DRAW *dp,int i,int floor,int leftspace,int direction=2)   //direction: 0 is left 1 is right
{
	if (i < n)
	{
		int count=i+1-pow(2,floor/2);
		int ii;
	//	printf("%d ",*(data+i));
		//float div=(float)(3*(2*n-1)-3* pow(2, floor))/(pow(2, floor) +1);
		
		//int leftspace = (3 * (2 * n - 1) - 3 * pow(2, floor) - div * (pow(2, floor) - 1)) / 2;
	//	int div=(3*(2*c-1)-2*leftspace)/(pow(2, floor) -1);
		int div=3*(c)*pow(2,-floor/2)-3;
		//if (count > 1)

		//	div= (3 * (2 * n - 1) - leftspace * 2 - 3 * count)/(count-1);
		
		//for (count = 0; count < pow(2, floor); count++)
		//{
		//printf("leftspace:%d\n", leftspace);
		//for (ii = 0; ii < leftspace + div * count + 1;ii++)
		//	addpixels(dp, ii, 0, 1);
		//	printf(" ");
		//printf("%d\n", *(data + i));
		//addpixel(dp, leftspace + div * count , floor, 121);
		//addpixel(dp, 5, 4, 22);

			addpixels(dp,leftspace+ (div)*count + 3*(count), floor, *(data+i));
			
			if(direction==0)
				addline(dp,leftspace+ (div)*count + 3*(count),floor-1,2*leftspace+3+ (3*(c)*pow(2,-(floor-2)/2)-3)*(i/2+1-pow(2,(floor-1)/2)) + 3*(i/2+1-pow(2,(floor-1)/2)),floor-1);
			else if(direction==1)
				addline(dp,leftspace+ (div)*count + 3*(count),floor-1,2*leftspace+3+ (3*(c)*pow(2,-(floor-2)/2)-3)*(i/2-pow(2,(floor-1)/2)) + 3*(i/2-pow(2,(floor-1)/2)),floor-1);
		//	if( *(data+i)==870 ||  *(data+i)==815)
		//	{
		//		printf("count:%d leftspace:%d div:%d x:%d floor:%d data:%d\n",count,leftspace,div,leftspace+ (div)*count + 3*(count),floor,*(data+i));
		//	}
		//}
		
		drawtree(data, n,c, dp, 2 * i + 1,floor+2,(leftspace-3)/2,0);   //0 is left 1 is right
		
		drawtree(data, n,c, dp, 2 * i + 2,floor+2,(leftspace-3)/2,1);
	}
	
	
}


void stacksort(int *data,int n)
{
	int i=n-1,ii;
	int tmp;
	int *buffer=NULL;
	for(i=0; i<n-1; i++)
	{
		sift(data,i,n-1);
		for(ii=0; ii<n; ii++)
		{
			printf("%d ",*(data+ii));
		}
		printf("\n\n");
		
		int c=1;
		while(c-1<=n)
		{
			c*=2;
		}
		buffer=(int*)calloc(sizeof(int),n-i);
		for(tmp=i;tmp<n;tmp++)
		{
			*(buffer+tmp-i)=*(data+tmp);
		}
		
		DRAW* dp = drawstart( 3 * c + 3 * (c - 1)+20, c / 2);
		//addline(dp, 3 * n + 3 * (n - 1)-1, 0, 3 * n + 3 * (n - 1)-1, n / 2-1);
		drawtree(buffer, n-i,c,dp,0,0,3 * (c/2 - 1));
		drawsmart(dp);
		drawclose(dp);
		
		free(buffer);
		getchar();
	}
}








void f5()
{
	int *data=NULL;
	int i;
	int n;
	char path[32];
	printf("请输入数据文件路径:");
	scanf("%s",path);
	fflush(stdin);
	FILE *fp=fopen(path,"rb");
	if(fp==NULL)
	{
		printf("error,cannot find the file.");
		return;
	}
	fread(&n,sizeof(int),1,fp);
	data=(int*)calloc(sizeof(int),n);
	fread(data,sizeof(int),n,fp);
	printf("文件读入完毕\n");
	fclose(fp);
	printf("堆排序前：\n");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("\n");
	printf("堆排序过程：\n");
	stacksort(data,n);
	printf("堆排序后：\n");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("\n");

	printf("开始释放内存\n");
	free(data);
	printf("释放内存完毕\n");

}

void mergesort(int *data,int start,int end,int n)
{

	if(end-start>1)
	{
	//	fflush(stdin);
	//	getchar();
		//printf("%d %d %d\n",start,end,(end+start)/2);
		int tmp;
		int i1=start,i2=(end+start)/2,i=0;
		//int *newdata1=(int*)calloc(sizeof(int),(end+start)/2-start);
		//int *newdata2=(int*)calloc(sizeof(int),end-(end+start)/2);
		int *newdata=(int*)calloc(end-start,sizeof(int));
//		for(i=0; i<(end+start)/2-start; i++)
//		{
//			*(newdata1+i)=9999;
//		}
//		
//		
//		for(i=0; i<end-(end+start)/2; i++)
//		{
//			*(newdata2+i)=9999;
//		}
//		i=0;
		
		mergesort(data,start,(end+start)/2,n);
		mergesort(data,(end+start)/2,end,n);
		
//		for(i=0; i<(end+start)/2-start; i++)
//		{
//			printf("%d ",*(newdata1+i));
//		}
//		printf("\n");
//		
//		for(i=0; i<end-(end+start)/2; i++)
//		{
//			printf("%d ",*(newdata2+i));
//		}
//		printf("\n");
	//	printf("while");
	//	fflush(stdin);
	//	getchar();
		while(i1<(end+start)/2 && i2<end)
		{
			if(*(data+i1)<*(data+i2))
			{
			//	printf("!");
			//	tmp=*(data+i);
				*(newdata+i)=*(data+i1);
			//	*(data+i1)=tmp;
				i++;
				i1++;
			}
			else if(*(data+i1)>*(data+i2))
			{
			//	printf("?");
			//	tmp=*(data+i);
				*(newdata+i)=*(data+i2);
			//	*(data+i2)=tmp;
				i++;
				i2++;
			}
			else
			{
				
				
			//	tmp=*(data+i);
				*(newdata+i)=*(data+i2);
			//	*(data+i2)=tmp;
				
				
				i++;
				
			
				//tmp=*(data+i);
				*(newdata+i)=*(data+i1);
			//	*(data+i1)=tmp;
			
				
				i++;
				i1++;
				i2++;
			}
		}
		
	
		
		while(i1<(end+start)/2)
		{
			
		//	tmp=*(data+i);
			*(newdata+i)=*(data+i1);
		//	*(data+i1)=tmp;
		
			i++;
			i1++;
		}
		while(i2<end)
		{
			//tmp=*(data+i);
			*(newdata+i)=*(data+i2);
		//	*(data+i2)=tmp;
		
			i++;
			i2++;
		}
		
		for(i=start; i<end; i++)
		{
			
			*(data+i)=*(newdata+i-start);
		}
		
		for(i=0; i<n; i++)
		{
			
			printf("%d ",*(data+i));
		}
		printf("\n");
		
		//free(newdata1);
		//free(newdata2);
		free(newdata);
	}
	//else if(end-start==1)
//	{
		//*(data+start)=*(data+start);
		//	printf("%d ",*(data+start));
//	}
//	else
//	{
//		printf("plaa");
//	}

}







void f6()
{
	int *data=NULL;
	int i;
	int n;
	char path[32];
	printf("请输入数据文件路径:");
	scanf("%s",path);
	fflush(stdin);
	FILE *fp=fopen(path,"rb");
	if(fp==NULL)
	{
		printf("error,cannot find the file.");
		return;
	}
	fread(&n,sizeof(int),1,fp);
	data=(int*)calloc(sizeof(int),n);
	fread(data,sizeof(int),n,fp);
	printf("文件读入完毕\n");
	fclose(fp);

	printf("二路归并排序前：\n");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("\n");
	printf("二路归并排序过程：\n");
	//int *newdata=(int*)calloc(sizeof(int),n);
	mergesort(data,0,n,n);

	printf("二路归并排序后：\n");
	for(i=0; i<n; i++)
	{
		printf("%d ",*(data+i));
	}
	printf("\n");










	printf("开始释放内存\n");
	free(data);
	printf("释放内存完毕\n");
}

void writefile()
{
	int *data,i,n;
	char path[32];
	printf("请输入所要求的数据数量:");
	scanf("%d",&n);
	data=(int*)calloc(sizeof(int),n);
	printf("请输入所要求的数据:");
	for(i=0; i<n; i++)
	{
		scanf("%d",(data+i));
	}
	fflush(stdin);
	printf("请输入数据文件路径:");
	scanf("%s",path);
	FILE *fp=fopen(path,"wb+");
	if(fp==NULL)
	{
		printf("error,cannot find the file.");
		return;
	}
	fwrite(&n,sizeof(int),1,fp);
	fwrite(data,sizeof(int),n,fp);
	printf("文件写入完毕\n");
	fclose(fp);
	printf("开始释放内存\n");
	free(data);
	printf("释放内存完毕\n");
}

//#pragma once
#include<stdlib.h>
#include<stdio.h>
#define int2char_const 90000


typedef struct  {
	int *sp;
	int width;
	int height;
}spvar,DRAW;

/******************************
function: make char could live with normal int
input: char
output: int
******************************/ 
int char2int(char x)
{
	return x+int2char_const;
}

/******************************
function: make char lived with normal int recover to char
input: int
output: char
******************************/ 
char int2char(int x)
{
	return x-int2char_const;
}

/******************************
function: change a pixel of the drawing area. with int variety
input: the DRAW pointer,the x ,y the value using int encode
output: void
error: print out : error:illegal screen range
******************************/
void addpixel(DRAW *&sp,int width, int height,int value)
{
	//printf("%d %d::",sp->width,sp->height) ;
	if ((sp->width) * (height) + width < (sp->width) * (sp->height))
	{
		*(sp->sp + (sp->width) * (height) + width) = value;

	}
	else
	{
		printf("\nerror:illegal screen range\n");
	}
}

/******************************
function: change a pixel of the drawing area. with char variety
input: the DRAW pointer,the x ,y the value using int encode
output: void
error: print out : error:illegal screen range
******************************/
void addpixelc(DRAW *&sp,int width, int height,char value)
{
	//printf("%d %d::",sp->width,sp->height) ;
	if ((sp->width) * (height ) + width < (sp->width) * (sp->height))
	{
		*(sp->sp + (sp->width) * (height ) + width) = char2int(value);

	}
	else
	{
		printf("\nerror:illegal screen range\n");
	}
}

/******************************
function: show the drawing area ,with ascii encode
input: the DRAW pointer
output: void
******************************/
void draw(DRAW *&sp)
{
	int i=0;

	while (i < (sp->width) * (sp->height))
	{
		printf("%c", int2char(*((sp->sp) + i)));
		if ((i+1) % (sp->width) == 0)
			printf("\n");
		i++;
	}
}

/******************************
function: show the drawing area ,with int encode
input: the DRAW pointer
output: void
******************************/
void drawsmart(DRAW *&sp)
{
	int i=0;
	while (i < (sp->width) * (sp->height))
	{
		
			
		if(*((sp->sp) + i)==char2int('/') || *((sp->sp) + i)==char2int('\\') || *((sp->sp) + i)==char2int('|') || *((sp->sp) + i)==char2int('-'))// || (*((sp->sp) + i)<='z'&&*((sp->sp) + i)>='a') || (*((sp->sp) + i)<='Z'&&*((sp->sp) + i)>='A'))
		{
			//printf("%d", *((sp->sp) + i));	
			printf("%c", int2char(*((sp->sp) + i)));	
		}
		else if(*((sp->sp) + i)!=char2int(' '))
			printf("%d", *((sp->sp) + i));	
		else
			printf(" ");
		if ((i+1) % (sp->width) == 0)
			printf("\n");
		i++;
	}
}

/******************************
function: show the drawing area ,with int encode
input: the spvar pointer
output: void
******************************/
void drawint(DRAW *&sp)
{
	int i=0;
	while (i < (sp->width) * (sp->height))
	{
		printf("%d ", (int)*((sp->sp) + i));
		if ((i+1) % (sp->width) == 0)
			printf("\n");
		i++;
	}
}

/******************************
function: tranform (x,y) to array element's label ,with int encode
input: the spvar pointer, (x,y)
output: label
error: (x,y) is too big for this area
******************************/
int axis2array(DRAW *&sp,int x,int y)
{
	if(y*x<((sp->width)*(sp->height)))
		return (sp->width)*(y)+x;
	else
		printf("\nerror:(%d,%d) is too big for this area\n",x,y);
	return -1;
}
/******************************
function: clean the drawing area ,make it blank
input: the spvar pointer
output: void
******************************/
void cleandraw(DRAW *&sp)
{
	int i = 0;
	//printf("cleandraw %d %d");
	while (i < (sp->width) * (sp->height))
	{
		*((sp->sp) + i) = char2int(' ');
	
		i++;
	}
}

/******************************
function: draw a line using '/' or '\' or '|' or '-' or '.',make it straight
input: the spvar pointer start point x,y ; end point x,y
output: void
error: (x1,y1) overflow; (x2,y2) overflow;
******************************/
void addline(DRAW *&sp,int x1,int y1,int x2,int y2)
{
	int i = 0,tmp;
	float k,b;
	int fillchar;	
	//printf("cleandraw %d %d");
	if (x1*y1 < (sp->width) * (sp->height) && x2*y2 < (sp->width) * (sp->height))
	{
		if(x1==x2)
		{
			if(y1>y2)
			{
				//tmp=x1;
				//x1=x2;
				//x2=tmp;
				tmp=y1;
				y1=y2;
				y2=tmp;
			}
			
			if((x1-x2)==0 && (y1-y2)==0)
				fillchar=char2int('.');
			else if((x1-x2)==0)
				fillchar=char2int('|');
			for(i=y1;i<=y2;i++)
			{
				*((sp->sp) + axis2array(sp,x1,i))=(int)fillchar;
			}
			
		}
		else
		{
			if(x1>x2)
			{
				tmp=x1;
				x1=x2;
				x2=tmp;
				tmp=y1;
				y1=y2;
				y2=tmp;
			}
	
			if((x1-x2)*(y1-y2)<0)
				fillchar=char2int('/');
			else if((x1-x2)*(y1-y2)>0)
				fillchar=char2int('\\');		
			else if((y1-y2)==0)
				fillchar=char2int('-');
				//printf("%d",fillchar);
			for(i=x1;i<=x2;i++)
			{
				k=(float)(y1-y2)/(x1-x2);
				b=(float)(y2*x1-y1*x2)/(x1-x2);
				*((sp->sp) + axis2array(sp,i,k*i+b)) = (int)fillchar;
				//i++;
			}
		}
		
		
		
		
	}
	else
	{
		if(x1*y1 > (sp->width) * (sp->height))
			printf("\nError:Start point :(%d,%d) overflow\n",x1,y1);
		if(x2*y2 > (sp->width) * (sp->height))
			printf("\nError:End point :(%d,%d) overflow\n",x2,y2);
	}
}

/*******************************
function: inital and optimize the size of a painting-paper
input : width, height (the argument of the painting range)
output: an spvar pointer with the arguments of the painting-paper
*******************************/
spvar* drawstart(int width, int height)
{
	int *screen = (int*)malloc(width * height*sizeof(int));
	DRAW* sp = (DRAW*)malloc(sizeof(DRAW));
	sp->sp = screen;	
	sp->width = width;
	sp->height = height;
	cleandraw(sp);
	return sp;
}

/*******************************
function: close a painting-paper
input : the DRAW pointer
output: void
*******************************/
void drawclose(DRAW *sp)
{	
	free(sp->sp);	
	free(sp);
}


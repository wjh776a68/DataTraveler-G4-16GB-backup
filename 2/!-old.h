#pragma once
#ifndef _2_H_
typedef struct slist {
	int data;
	struct slist* next;
}node;

void f1(node* p);
void f2(node* p);
void f3(node* p);
void f4(node* p);
void f5(node* p,int i);

void show(node* p);

#endif
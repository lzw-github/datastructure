#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"

void LinkDispaly(LinkList L) { //头结点跳过
	//printf("%d ", L->data);
	while (L = L->next)
	{
		printf("%d ", L->data);
	}
}

void LinkInsert(LinkList L, int i, ElemType e) //有头结点
{
	if (i<=0)
	{
		return ;
	}
	for (int j = 1; j <= i - 1 && (L = L->next); j++);//&& (L = L->next)

	LinkList s = (LinkList)malloc(sizeof(Lnode));

		s->data = e;
		s->next = L->next;
		L->next = s;

}

void LinkInit(LinkList& L) { //初始化头结点
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
}

void LinkDelete(LinkList L, int i) {    //有头结点
	for (int j = 1; j <= i - 1 && (L = L->next); j++);
	LinkList s = L->next;
	L->next = s->next;
	free(s);
}

ElemType LinkGet(LinkList L, int i) {   //有头结点，i为第几个数，除去头结点
	for (int j = 1; j <= i - 1 && (L = L->next); j++);
	if (L->next)
	{
		return L->next->data;
	}
	else
	{
		return 0;
	}
}

void LinkCreate(LinkList L, ElemType* array, int n) { //有头结点，头结点data为NULL
	for (int i = 0; i <n; i++)
	{
		LinkList s = (LinkList)malloc(sizeof(Lnode));
		s->next = L->next;
		L->next = s;
		s->data = *array;
		array++;
		L = L->next;
	}
}

void LinkDestroy(LinkList L){  //所有节点释放
	while (L->next)
	{
		LinkList s = L;
		L = L->next;
		free(s);
	}
	free(L);
}
//int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//LinkList L;
//LinkInit(L);
//LinkCreate(L, a, 10);
//
//LinkDispaly(L);

void PolynominalCreate(Poly  L, ElemType* index, ElemType* data, int n){
	L->index = *index;
	L->data = *data;
	for (int  i = 0; i < n; i++)
	{
		Poly s = (Poly)malloc(sizeof(Polynominal));
		s->next = L->next;
		L->next = s;
		s->data = *data;
		s->index = *index;
		data++;
		index++;
		L = L->next;
	}
}

void Operate(ElemType one, ElemType two) {

}


void PolynominalOperate(Poly Lone, Poly Ltwo, void(*Operate)(ElemType, ElemType)) {

}

void PolynominalDispaly(Poly L) {
	printf("%dX%d \n", L->data, L->index);
	while (L = L->next)
	{
		printf("%dX%d \n",L->data,L->index);
	}
}
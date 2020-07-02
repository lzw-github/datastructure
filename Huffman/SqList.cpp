#include <stdio.h>
#include <malloc.h>
#include "SqList.h"

void ListDispaly(SqList& L) {
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.elem[i]);

	}
	printf("len=%d", L.length);
	printf("\n");
}

int LnitList(SqList& L) {
	L.elem = (ElemType*)malloc(Mixsize * sizeof(ElemType));
	if (!L.elem)
	{
		return 0;
	}
	L.length = 0;
	return 1;
}



void ListInsert(SqList& L, int i, ElemType e) { 
	if (i < 0 || i>=Mixsize)
	{
		return;
	}
	if (L.length == Mixsize) {
		return;
	}
	for (int j = L.length;j>=i;j--){
		L.elem[j] = L.elem[j-1];
	}
	L.elem[i-1] = e;
	L.length++;
}




ElemType ListDelete(SqList& L, int i) {
	ElemType data;
	if (i<0||i>Mixsize)
	{
		return 0;
	}
	data = L.elem[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}
	return data;
}

int  compare(ElemType a, ElemType b) {
	return (a > b) ? 1:0;
}

int LocateElem(SqList& L, ElemType e, int(*compare)(ElemType, ElemType)) {
	int i =1;
	ElemType* p = L.elem;
	while (i < L.length && !(*compare)(*p++, e)) i++;
	if (i<L.length)
	{
		return i;
	}
	else
	{
		return 0;
	}
}
//SqList L;
//LnitList(L);
//for (int i = 1; i <= 20; i++)
//{
//	ListInsert(L, i, i);
//}
//ListDispaly(L);
//ListInsert(L, 5, 16);
//ListDispaly(L);
//ListDelete(L, 19);
//ListDispaly(L);
////printf("%d", LocateElem(L, 3, compare));




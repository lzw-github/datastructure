#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED
typedef int ElemType;
#define true OK;
#define Mixsize 20
typedef struct SqList{
	ElemType *elem;
	ElemType length;
}SqList;

int LnitList(SqList& L);

void ListInsert(SqList& L,int i,ElemType e);

ElemType ListDelete(SqList& L, int i);

int  compare(ElemType a, ElemType b);

int LocateElem(SqList& L, ElemType e, int(*compare)(ElemType, ElemType));

void ListDispaly(SqList &L);
#endif

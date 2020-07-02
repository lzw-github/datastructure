#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED


typedef int ElemType;
typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode,*LinkList;

void LinkDispaly(LinkList L);

void LinkInsert(LinkList L, int i,ElemType e);

void LinkInit(LinkList& L);

void LinkDelete(LinkList L, int i);

ElemType LinkGet(LinkList L, int i);

void LinkCreate(LinkList L, ElemType* array, int n);

void LinkDestroy(LinkList L);


typedef struct Polynominal
{
	ElemType index;
	ElemType data;
	struct Polynominal* next;
}Polynominal,*Poly;

void PolynominalCreate(Poly L,ElemType *index,ElemType*data,int n);

void Operate(ElemType one, ElemType two);


void PolynominalOperate(Poly Lone, Poly Ltwo,void(*Operate)(ElemType,ElemType));

void PolynominalDispaly(Poly L);
#endif

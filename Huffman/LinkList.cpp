#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"
///////////////////////////////////////////////////////////////////////////////
void LinkDispaly(LinkList L) { 
	//printf("%d ", L->data);
	while (L = L->next)
	{
		printf("%d ", L->data);
	}
	printf("\n");
}

void LinkInsert(LinkList L, int i, ElemType e) 
{
	if (i<=0)	return ;
	//for (int j = 1; j <= i - 1 && (L = L->next); j++);//&& (L = L->next)
	int  j = 0;
	while ( L&&j<i-1){
		L = L->next;
		j++;
	}
	if (!L) return;
	LinkList s = (LinkList)malloc(sizeof(Lnode));
	s->data = e;
	s->next = L->next;
	L->next = s;

}

void LinkInit(LinkList& L) { 
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
}

void LinkDelete(LinkList L, int i) {    
	//for (int j = 1; j < i && (L = L->next); j++);
	LinkList s;
	int  j = 0;
	while (L && j < i - 1) {
		L = L->next;
		j++;
	}

	if (!(L)||j>i-1)
	{
		return;
	}
	
	s = L->next;
	L->next = s->next;
	free(s);
}
ElemType LinkGet(LinkList L, int i) {   
	//for (int j = 1; j <= i - 1 && (L = L->next); j++);
	//if (L->next)
	//{
	//	return L->next->data;
	//}
	//else
	//{
	//	return 0;
	//}
	int j=1;
	L = L->next;
	while (L&&j<i)
	{
		L = L->next;
		j++;
	}
	return L->data;
}
void LinkC(LinkList Lone, LinkList Ltwo, LinkList Lthree) { 
	Lone = Lone->next;Ltwo = Ltwo->next;
	while (Ltwo&&Lone)
	{
		if (Lone->data <= Ltwo->data) {
			Lthree->next = Lone;
			Lthree = Lthree->next;
			Lone = Lone->next;
		}
		else
		{
			Lthree->next = Ltwo;
			Lthree = Lthree->next;
			Ltwo = Ltwo->next;
		}
	}
	if (!Lone) {
		Lthree->next = Ltwo;
	}
	else{	
		Lthree->next = Lone;
	}
}
void LinkCreate(LinkList L, ElemType* array, int n) { 
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
void LinkDestroy(LinkList L){  
	LinkList s;
	while (L) //L->next
	{
		s = L;
		L = L->next;
		free(s);
	}
	//free(L);
}
LinkList LinkMerge(LinkList Lone, LinkList Ltwo) {   
	LinkList s;
	Lone = Lone->next;Ltwo = Ltwo->next;
	if (Ltwo->data > Lone->data) {
		s = Lone;Lone = Ltwo;Ltwo = s;
	}
	while (Ltwo&&Lone->next)
	{
		if (Ltwo->data <= Lone->next->data)
		{
			s = Ltwo;
			Ltwo = Ltwo->next;
			s->next = Lone->next;
			Lone->next = s;
			Lone = Lone->next;
		}
		else {
			Lone = Lone->next;
		}

	}
	if(!Lone)	Lone->next = Ltwo;
	return 0;
}


void LinkRemove(LinkList L) {    

	LinkList s,q,pre,t;
	s = L;
	s = s->next;

	while (s)
	{
		q = s->next;
		pre = s;
		while (q)
		{
			if (q->data == s->data) {
				t = q;
				q = q->next;
				pre->next = t->next;
				free(t);
			}
			else{
				pre = q;
				q = q->next;
			}		
		}
		s = s->next;
	}
}    
void LinkReverse(LinkList L) {
	LinkList s;
	LinkList q = L;
	LinkList pre = NULL;
	q = q->next;
	while (q)
	{
		s = q;    q = q->next;
		s->next = pre;    pre = s;
	}
	L->next = s;
}


void LinkAlternatingMerging(LinkList La, LinkList Lb) {
	LinkList Lb_pre,La_pre;
	La = La->next;
	Lb = Lb->next;
	while (La && Lb)
	{
		Lb_pre = Lb;
		La_pre = La;
		Lb = Lb->next;
		La = La->next;
		Lb_pre->next = La_pre->next;
		La_pre->next = Lb_pre;
	}
	if (!La) {
		Lb_pre->next= Lb;
	}
	
}

LinkList LinkIntersection(LinkList La, LinkList Lb) {
	LinkList Lc, re, s;
	re = Lc = La;
	La = La->next;
	LinkList q = Lb->next;
	while (La)
	{
		while (q) {
			if (q->data == La->data) Lc->next = La;
			q=q->next;
		}
		if (Lc->next) {
			Lc = Lc->next;La = La->next;
		}
		else{
			s = La;	La = La->next;free(s);
	    }
		q = Lb->next;
	    Lc->next = NULL;
	}
	LinkDestroy(Lb);
	return re;
}
void LinkDeleteOne(LinkList L, ElemType e) {
	LinkList s,L_pre;
	L_pre = L;
	L = L->next;
	while (L)
	{
		if(L->data == e){
			s = L;
			L_pre->next = L->next;
			L = L->next;
			free(s);
		}
		else
		{
			L_pre = L;
			L = L->next;
		}
	}
}
void LinkDeleteC_AB(LinkList La, LinkList Lb, LinkList Lthree) {

	LinkList re = LinkIntersection(La, Lb);
	printf("交集为:");
	LinkDispaly(re);
	printf("删除前:");
	LinkDispaly(Lthree);
	re = re->next;
	while (re)
	{
		LinkDeleteOne(Lthree, re->data);
		re = re->next;
	}
	printf("删除后:");
	LinkDispaly(Lthree);


}
//////////////////////////////////////////////////////////////////////////////

void PolynominalCreate(Poly  L, ElemType* index, ElemType* data, int n){
	L->index = *index++;
	L->data = *data++;

	for (int  i = 1; i < n; i++)
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

void Operateone(Poly one, Poly two) {
	 one->data = one->data+two->data;
}


void PolynominalOperating(Poly Lone, Poly Ltwo, void(*Operateone)(Poly, Poly)){  //多项式相加
	Poly s;
	Poly s_pre =NULL;
	while (Ltwo->next)
	{
		if (Lone->index > Ltwo->index) {
			
			s = Ltwo;
			Ltwo = Ltwo->next;
			if (s_pre)
			{
				s_pre->next = s;
			}
			s->next = Lone;
			s_pre = s;
			
		}
		else if (Lone->index < Ltwo->index)
		{
			if (Ltwo->index<Lone->next->index)
			{
				s = Ltwo->next;
				Ltwo->next = Lone->next;
				Lone->next = Ltwo;
				s_pre = Lone;
				Lone = Lone->next;
				Ltwo = s;
			}
			else if(Ltwo->index > Lone->next->index)
			{
				s_pre = Lone;
				Lone = Lone->next;
			}
			else
			{
				s_pre = Lone;
				Operateone(Lone->next, Ltwo);
				s = Ltwo;
				Ltwo = Ltwo->next;Lone = Lone->next;
				free(s);
			}
		}
		else
		{
			s_pre = Lone;
			Operateone(Lone, Ltwo);
			s = Ltwo;
			Ltwo = Ltwo->next;Lone = Lone->next;
			free(s);
		}
	}
	if (!Lone) Lone->next = Ltwo;
}   

void PolynominalDispaly(Poly L) {
	printf("%dX%d \n", L->data, L->index);
	while (L = L->next)
	{
		printf("%dX%d \n",L->data,L->index);
	}
}
void PolynominalInit(Poly& L) {
	L = (Poly)malloc(sizeof(Polynominal));
	L->data = 0;
	L->index = 0;
	L->next = NULL;
}
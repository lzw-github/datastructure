#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include"GlobalVar.h"
typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode,*LinkList;

void LinkDispaly(LinkList L); //显示链表，头结点跳过

void LinkInsert(LinkList L, int i,ElemType e);//链表插入

void LinkInit(LinkList& L);//初始化头结点

void LinkDelete(LinkList L, int i);//删除节点，i为第几个

ElemType LinkGet(LinkList L, int i);//有头结点，i为第几个数，除去头结点

void LinkCreate(LinkList L, ElemType* array, int n);//有头结点，头结点data为NULL，根据数组创建

void LinkDestroy(LinkList L);//单链表整个删除

void LinkC(LinkList Lone, LinkList Ltwo, LinkList Lthree); //合并，书上的

LinkList LinkMerge(LinkList Lone, LinkList Ltwo);//单链表合并

void LinkRemove(LinkList L); //单链表去重

void LinkReverse(LinkList L);//单链表就地翻转

void LinkAlternatingMerging(LinkList La, LinkList Lb);//交替合并俩张单链表

LinkList LinkIntersection(LinkList La, LinkList Lb);//俩个单链表求交集，返回新链表，修改La链表做返回值，并删除多余La和Lb节点
//int a[8] = { 1,4,5,7,10,11,12,13 };
//int b[7] = { 1,2,3,5,11,13,14 };
//LinkList Lone, Ltwo;
//LinkInit(Lone);LinkInit(Ltwo);
//LinkCreate(Lone, a, 8);LinkCreate(Ltwo, b, 7);
//LinkDispaly(Lone);
//LinkDispaly(Ltwo);
//LinkDispaly(LinkIntersection(Lone, Ltwo));
void LinkDeleteOne(LinkList L, ElemType e);//删除链表所有值为e的元素

void LinkDeleteC_AB(LinkList A,LinkList B,LinkList C);//删除C中A&B的部分


typedef struct Polynominal//多项式相加
{
	ElemType index;//次方
	ElemType data;//系数
	struct Polynominal* next;
}Polynominal,*Poly;

void PolynominalCreate(Poly L,ElemType *index,ElemType*data,int n);//根据index，data数组创建链表，n为节点个数

void Operate(ElemType one, ElemType two);//多项式加法


void PolynominalOperate(Poly Lone, Poly Ltwo,void(*Operate)(ElemType,ElemType));//将Ltwo加到Lone上，并释放相加后多余的Ltwo节点

void PolynominalDispaly(Poly L);//链表显示
//Poly Lone;
//Poly Ltwo;
//int index_one[10] = { 1,5,6,7,9,10,11,12,13,14 };
//int index_two[6] = { 1,2,4,5,7,9 };
//int data_one[10] = { 3,4,5,6,7,8,9,10,11,23 };
//int data_two[6] = { 1,2,3,4,5,6 };
//PolynominalInit(Lone);
//PolynominalInit(Ltwo);
//PolynominalCreate(Lone, index_one, data_one, 10);
//PolynominalCreate(Ltwo, index_two, data_two, 6);
////PolynominalDispaly(Lone);
////printf("\n");
////PolynominalDispaly(Ltwo);
//PolynominalOperating(Lone, Ltwo, Operateone);
//PolynominalDispaly(Lone);

#endif

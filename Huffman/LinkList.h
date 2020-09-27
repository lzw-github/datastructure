#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include"GlobalVar.h"
typedef struct Lnode {
	ElemType data;
	struct Lnode* next;
}Lnode,*LinkList;

void LinkDispaly(LinkList L); //��ʾ����ͷ�������

void LinkInsert(LinkList L, int i,ElemType e);//�������

void LinkInit(LinkList& L);//��ʼ��ͷ���

void LinkDelete(LinkList L, int i);//ɾ���ڵ㣬iΪ�ڼ���

ElemType LinkGet(LinkList L, int i);//��ͷ��㣬iΪ�ڼ���������ȥͷ���

void LinkCreate(LinkList L, ElemType* array, int n);//��ͷ��㣬ͷ���dataΪNULL���������鴴��

void LinkDestroy(LinkList L);//����������ɾ��

void LinkC(LinkList Lone, LinkList Ltwo, LinkList Lthree); //�ϲ������ϵ�

LinkList LinkMerge(LinkList Lone, LinkList Ltwo);//������ϲ�

void LinkRemove(LinkList L); //������ȥ��

void LinkReverse(LinkList L);//������͵ط�ת

void LinkAlternatingMerging(LinkList La, LinkList Lb);//����ϲ����ŵ�����

LinkList LinkIntersection(LinkList La, LinkList Lb);//�����������󽻼��������������޸�La����������ֵ����ɾ������La��Lb�ڵ�
//int a[8] = { 1,4,5,7,10,11,12,13 };
//int b[7] = { 1,2,3,5,11,13,14 };
//LinkList Lone, Ltwo;
//LinkInit(Lone);LinkInit(Ltwo);
//LinkCreate(Lone, a, 8);LinkCreate(Ltwo, b, 7);
//LinkDispaly(Lone);
//LinkDispaly(Ltwo);
//LinkDispaly(LinkIntersection(Lone, Ltwo));
void LinkDeleteOne(LinkList L, ElemType e);//ɾ����������ֵΪe��Ԫ��

void LinkDeleteC_AB(LinkList A,LinkList B,LinkList C);//ɾ��C��A&B�Ĳ���


typedef struct Polynominal//����ʽ���
{
	ElemType index;//�η�
	ElemType data;//ϵ��
	struct Polynominal* next;
}Polynominal,*Poly;

void PolynominalCreate(Poly L,ElemType *index,ElemType*data,int n);//����index��data���鴴������nΪ�ڵ����

void Operate(ElemType one, ElemType two);//����ʽ�ӷ�


void PolynominalOperate(Poly Lone, Poly Ltwo,void(*Operate)(ElemType,ElemType));//��Ltwo�ӵ�Lone�ϣ����ͷ���Ӻ�����Ltwo�ڵ�

void PolynominalDispaly(Poly L);//������ʾ
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

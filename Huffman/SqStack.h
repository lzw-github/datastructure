#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED
#include"GlobalVar.h"
typedef struct {
	SElemType* base;
	SElemType* top;
	int size;
}SqStack,*ListStack;
void StackInit(ListStack& S);//��ʼ��

void StackPush(ListStack S,SElemType e);//��ջ

SElemType StackPop(ListStack S);//����

void StackDisplay(ListStack S);//��ӡ

SElemType StackGet(ListStack S);//ȡֵ

SElemType  FormatConvert(SElemType data, int n);//����ת����dataΪʮ���ƣ�nΪת�����ƣ�ֱ�Ӵ�ӡ���

void find(int* map, int cow, int culumn, int start, int end);//�Թ����

int IfContinue(int* map, int culumn, int position);//�Թ�����
//int map[10][10] = { {1,1,1,1,1,1,1,1,1,1},
//				{1,0,0,1,0,0,0,1,0,1},
//				{1,0,0,1,0,0,0,1,0,1},
//				{1,0,0,0,0,1,1,0,0,1},
//				{1,0,1,1,1,0,0,0,0,1},
//				{1,0,0,0,1,0,0,0,0,1},
//				{1,0,1,0,0,0,1,0,0,1},
//				{1,0,1,1,1,0,1,1,0,1},
//				{1,1,0,0,0,0,0,0,0,1},
//				{1,1,1,1,1,1,1,1,1,1} };
//
//find(map[0], 10, 10, 11, 88);



#endif
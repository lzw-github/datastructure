#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED
#include"GlobalVar.h"
typedef struct {
	SElemType* base;
	SElemType* top;
	int size;
}SqStack,*ListStack;
void StackInit(ListStack& S);//初始化

void StackPush(ListStack S,SElemType e);//入栈

SElemType StackPop(ListStack S);//弹出

void StackDisplay(ListStack S);//打印

SElemType StackGet(ListStack S);//取值

SElemType  FormatConvert(SElemType data, int n);//进制转换，data为十进制，n为转换进制，直接打印输出

void find(int* map, int cow, int culumn, int start, int end);//迷宫求解

int IfContinue(int* map, int culumn, int position);//迷宫方向
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
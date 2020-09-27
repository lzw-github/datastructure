#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "SqStack.h"
void StackInit(ListStack& S) {
	S = (ListStack)malloc(sizeof(SqStack));
	S->base = (SElemType*)malloc(maxsize * sizeof(SElemType));
	S->top = S->base;
	S->size = maxsize;
}
void StackPush(ListStack S,SElemType e) {
	if (S->base==S->top - S->size)
	{
		return;
	}
	*S->top++ = e;
	
}
SElemType StackPop(ListStack S) {
	if (S->base==S->top) return 0;
	SElemType e;
	e = *(--S->top);
	return e;
}
void StackDisplay(ListStack S) {
	for (SElemType *i = S->base ; i < S->top; i++)
	{
		printf("%d ", *i);             //×Ö·ûÐÞ¸Ä
	}
}
SElemType StackGet(ListStack S) {
	if (S->base == S->top) { return 0; }
	else { return *(S->top - 1); }
}

SElemType  FormatConvert(SElemType data, int n) {
	ListStack S;
	StackInit(S);
	int i = 0;
	while (data!=0)
	{
		StackPush(S, data % n);
		data = data / n;
		i++;
	}
	for (;i > 0;i--) {
		printf("%d", *(--S->top));
	}
	return 0;
}
int IfContinue(int* map, int culumn, int position) {
	int cow_run = position / culumn;
	int culumn_run = position % culumn;
	if (*(map + (cow_run - 1) * culumn + culumn_run) == 0) {
		return 1;
	}
	else if (*(map + cow_run * culumn + culumn_run + 1) == 0)
	{
		return 2;
	}
	else if (*(map + (cow_run + 1) * culumn + culumn_run) == 0)
	{
		return 3;
	}
	else if (*(map + cow_run * culumn + culumn_run - 1) == 0)
	{
		return 4;
	}
	else
	{
		return 0;
	}

}
void find(int* map, int cow, int culumn, int start, int end) {
	ListStack S;StackInit(S);
	StackPush(S, start);
	int cow_run, culumn_run;
	cow_run = start / culumn;culumn_run = start % culumn;
	while (cow_run != (end / culumn) || culumn_run != (end % culumn))
	{
		if (cow_run != StackGet(S) / culumn || culumn_run != StackGet(S) % culumn) {
			StackPush(S, cow_run * culumn + culumn_run);
		}
		*(map + cow_run * culumn + culumn_run) = 1;
		switch (IfContinue(map, culumn, cow_run * culumn + culumn_run))
		{
		case 1:cow_run -= 1;break;
		case 2:	culumn_run += 1;break;
		case 3:	cow_run += 1;break;
		case 4:	culumn_run -= 1;break;
		case 0:StackPop(S); cow_run = StackGet(S) / culumn;
			culumn_run = StackGet(S) % culumn;break;
		}
		StackDisplay(S);
		printf("\n");
		for (int i = 0; i < culumn; i++)
		{
			for (int j = 0; j < culumn; j++)
			{
				printf("%d ", *(map + i * culumn + j));
			}
			printf("\n");
		}
		printf("\n");
	}



}


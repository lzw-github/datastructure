#include <stdio.h>
#include<malloc.h>
#include"LoopQueue.h"
void LoopQueueInit(SqQueue& Q) {
	Q.base = (QElemType*)malloc(maxsize * sizeof(QElemType));
	Q.front = 0;
	Q.rear = 0;
	Q.base[(maxsize + Q.front - 1) % maxsize] = 0;
}

void LoopQueueInsert(SqQueue& Q, QElemType e) {
	if (Q.front==(Q.rear+1)%maxsize)  return;
	else
	{		
		Q.base[Q.rear] = e;
		Q.rear = (Q.rear + 1) % maxsize;
	}
	Q.base[(maxsize + Q.front - 1)%maxsize] += 1;
	
}

QElemType LoopQueueDelete(SqQueue& Q) {
	QElemType re;
	if (Q.front == Q.rear) return NULL;
	else
	{
		 re = Q.base[Q.front];
		 Q.base[Q.front] = Q.base[(maxsize + Q.front - 1) % maxsize]-1;
		Q.front = (Q.front + 1) % maxsize;
	}
	return re;
}

int LoopQueueLength(SqQueue Q) {
	return Q.base[(maxsize + Q.front - 1) % maxsize];
}

QElemType LoopQueueGet(SqQueue Q) {
	return Q.base[Q.front];
}
void LoopQueueDisplay(SqQueue Q) {
	if (Q.front >= Q.rear) {
		for (int i = Q.front; i < Q.rear + maxsize; i++)
		{
			printf("%d ", Q.base[i % maxsize]);
		}
	}
	else
	{
		for (int i = Q.front; i < Q.rear; i++)
		{
			printf("%d ", Q.base[i]);
		}
	}
}
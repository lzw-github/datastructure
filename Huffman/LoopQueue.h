#ifndef __LOOPQUEUE_H__
#define __LOOPQUEUE_H__
#include"GlobalVar.h"
typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;
void LoopQueueInit(SqQueue& Q);

void LoopQueueInsert(SqQueue& Q, QElemType e);

QElemType LoopQueueDelete(SqQueue& Q);

int LoopQueueLength(SqQueue Q);

QElemType LoopQueueGet(SqQueue Q);

void LoopQueueDisplay(SqQueue Q);
#endif

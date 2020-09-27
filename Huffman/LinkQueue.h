#ifndef LINKQUQUE_H_INCLUDED
#define LINKQUQUE_H_INCLUDED
#include"GlobalVar.h"
typedef struct QNode{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

void QueueInit(LinkQueue& Q);//初始化

void QeueInsert(LinkQueue& Q, QElemType e);//插入

QElemType QeueDelete(LinkQueue& Q);//删除

void QueueDisplay(LinkQueue Q);//打印

int QueueLength(LinkQueue Q);//长度

void QueueDestroy(LinkQueue& Q);//销毁

QElemType QueueHead(LinkQueue Q);//取头部

void QueueClear(LinkQueue& Q);//清空

QElemType QueueGet(LinkQueue Q,int n);//取值

QElemType Visit(QueuePtr node);//对节点操作

void QueueTraverse(LinkQueue& Q, QElemType (*Visit)(QueuePtr node));//遍历

void QueneCreate(LinkQueue& Q, int* data);//创建



#endif

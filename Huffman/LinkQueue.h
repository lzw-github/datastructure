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

void QueueInit(LinkQueue& Q);//��ʼ��

void QeueInsert(LinkQueue& Q, QElemType e);//����

QElemType QeueDelete(LinkQueue& Q);//ɾ��

void QueueDisplay(LinkQueue Q);//��ӡ

int QueueLength(LinkQueue Q);//����

void QueueDestroy(LinkQueue& Q);//����

QElemType QueueHead(LinkQueue Q);//ȡͷ��

void QueueClear(LinkQueue& Q);//���

QElemType QueueGet(LinkQueue Q,int n);//ȡֵ

QElemType Visit(QueuePtr node);//�Խڵ����

void QueueTraverse(LinkQueue& Q, QElemType (*Visit)(QueuePtr node));//����

void QueneCreate(LinkQueue& Q, int* data);//����



#endif

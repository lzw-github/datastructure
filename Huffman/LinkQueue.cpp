#include <stdio.h>
#include<malloc.h>
#include"LinkQueue.h"

void QueueInit(LinkQueue& Q) {
	QueuePtr node = (QueuePtr)malloc(sizeof(QNode));
	node->next = NULL;
	Q.front = node;
	Q.rear = node;
}

void QeueInsert(LinkQueue& Q, QElemType e) {
	QueuePtr node = (QueuePtr)malloc(sizeof(QNode));
	Q.rear->data = e;
	node->next = Q.rear->next;
	Q.rear->next = node;
	Q.rear = node;
}

QElemType QeueDelete(LinkQueue& Q) {
	if (Q.front == Q.rear) {
		return 0;
	}
	QueuePtr s;
	QElemType data;
	data = Q.front->data;
	s = Q.front;
	Q.front = Q.front->next;
	free(s);
	return data;
}

void QueueDisplay(LinkQueue Q) {
	while (Q.front!=Q.rear)
	{
		printf("%d ", Q.front->data);                       //ÐÞ¸Ä·ûºÅ
		Q.front = Q.front->next;
	}
	printf("\n");
}

int QueueLength(LinkQueue Q) {
	int count = 0;
	while (Q.front != Q.rear)
	{
		count++;
		Q.front = Q.front->next;
	}
	return count;
}

void QueueDestroy(LinkQueue& Q) {
	QueuePtr s;
	while (Q.front)
	{
		s = Q.front;
		Q.front = Q.front->next;
		free(s);
	}
}

QElemType QueueHead(LinkQueue Q) {
	return Q.front->data;
}

void QueueClear(LinkQueue& Q) {
	while (Q.front != Q.rear)
	{
		Q.front->data = NULL;
		Q.front = Q.front->next;
	}
}

QElemType QueueGet(LinkQueue Q,int n) {
	if (Q.front == Q.rear) return 0;
	for (int i = 0; i < n; i++)
	{
		Q.front = Q.front->next;
	}
	return Q.front->data;
}

QElemType Visit(QueuePtr node) {
	printf("%d", node->data);
	return 0;
}

void QueueTraverse(LinkQueue& Q, QElemType(*Visit)(QueuePtr node)) {
	while (Q.front != Q.rear)
	{
		Visit(Q.front);
		Q.front = Q.front->next;
	}
}
void QueneCreate(LinkQueue& Q, int* data) {
	if (Q.front!=Q.rear)
	{
		return;
	}
	while (*data)
	{
		QueuePtr node = (QueuePtr)malloc(sizeof(QNode));
		Q.rear->data = *data;
		node->next = Q.rear->next;
		Q.rear->next = node;
		Q.rear = node;
		data++;
	}

}
#include<stdio.h>
#include<malloc.h>
#include"ThreadedBinaryTree.h"
void CreateBiThrTree(BiThrTree& T) {
	char ch;
	ch = getchar();
	if (ch == '#') {
		T = NULL;
		return;
	}
	else
	{
		T = (BiThrTree)malloc(sizeof(BiThrNode));
		T->LTag = Link;
		T->RTag = Link;
		T->data = ch;
		CreateBiThrTree(T->lchild);
		CreateBiThrTree(T->rchild);
	}
}
void recursiveInOrderThreading(BiThrTree T,BiThrTree &pre) {//BiThrTree pre = T;用之前需要声明一个全局变量
	if (T) {
		recursiveInOrderThreading(T->lchild,pre);
		if (T->lchild == NULL) {
			T->lchild = pre;
			T->LTag = Thread;
		}
		if (pre != NULL && pre->rchild == NULL) {
			pre->RTag = Thread;
			pre->rchild = T;
		}
		pre = T;
		recursiveInOrderThreading(T->rchild,pre);
	}
	else
	{
		return;
	}
}
void InOrderTaverseThreadedTree(BiThrTree T) {
	while (T)
	{
		while (T->LTag == Link) {
			T = T->lchild;
	    }
		if (T) printf("%c ",T->data);
		while (T->RTag==Thread){
			T = T->rchild;
			if (T) printf("%c ", T->data);
		}
		T = T->rchild;
	}
}

void recursivePreOrderThreading(BiThrTree T, BiThrTree& pre) {
	if (T) {
		if (T->lchild == NULL) {
			T->lchild = pre;
			T->LTag = Thread;
		}
		if (pre != NULL && pre->rchild == NULL) {
			pre->RTag = Thread;
			pre->rchild = T;
		}
		pre = T;
		if (T->LTag == 0) {
			recursivePreOrderThreading(T->lchild, pre);
		}
		if (T->RTag == 0) {
			recursivePreOrderThreading(T->rchild, pre);
		}
	}
}
void recursivePostOrderThreading(BiThrTree T, BiThrTree& pre) {
	if (T) {
		recursivePostOrderThreading(T->lchild, pre);
		recursivePostOrderThreading(T->rchild, pre);
		if (!T->lchild) { T->LTag = Thread;T->lchild = pre; }
		if (!pre->rchild) { pre->RTag = Thread, pre->rchild = T; }
		pre = T;
	}
}
void Threading(BiThrTree T, int TYPE) {
	BiThrTree pre = NULL;
	if (TYPE == 1&&T) {
		recursiveInOrderThreading(T, pre);
	}
	else if (TYPE==2&&T)
	{
		recursivePreOrderThreading(T, pre);
	}
	else
	{
		recursivePostOrderThreading(T, pre);
	}
}

BiThrTree GetPreNext(BiThrTree T) {
	if (T->RTag == Thread) {
		return T->rchild;
	}
	else if (T->LTag == Link && T->lchild) {
		return T->lchild;
	}
	else
	{
		return T->rchild;
	}
}
BiThrTree GetInNext(BiThrTree T) {
	if (T->RTag == Thread) return T->rchild;
	else
	{
		BiThrTree q;
		q = T->rchild;
		while (q->LTag==0)
		{
			q = q->lchild;
		}
		return q;
	}
}
BiThrTree GetInPre(BiThrTree T) {
	if (T->LTag == Thread) return T->lchild;
	else
	{
		BiThrTree q;
		q = T->lchild;
		while (q->RTag == 0)
		{
			q = q->rchild;
		}
		return q;
	}
}
BiThrTree GetPostPre(BiThrTree T) {
	if (T->LTag == Thread) {
		return T->lchild;
	}
	else
	{
		if (T->rchild) return T->rchild;
		else
		{
			return T->lchild;
		}
	}
}
void PreOrderTaverseThreadedTree(BiThrTree T) {
	BiThrTree p=T;
	while (p)
	{
		printf("%c", p->data);
		p = GetPreNext(p);
	}	
}
void InOrderTaverseThreadedTree_two(BiThrTree T) {
	BiThrTree p = T;
	while (p)
	{
		printf("%c", p->data);
		p = GetInNext(p);
	}
}

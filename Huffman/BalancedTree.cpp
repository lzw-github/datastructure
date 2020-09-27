#include<malloc.h>
#include<stdio.h>
#include"BalancedTree.h"
void InsertBSTree(BalTNode*& T, SElemType data) {
	if (T == NULL) {
		T = (BalTNode*)malloc(sizeof(BalTNode));
		T->data = data;
		T->lchild = T->rchild = NULL;
		return;
	}
	else
	{
		if (T->data == data) {
			printf("重复插入，未能插入:%d\n", data);
			return;
		}
		else if (T->data>data)
		{
			InsertBSTree(T->lchild, data);

		}
		else
		{
			InsertBSTree(T->rchild, data);
		}
	}
}
void CreateBSTree(BalTNode*& T, SElemType data[],int n) {

	for (int i = 0; i < n; i++)
	{
		InsertBSTree(T, data[i]);
	}
}

void TaverseBSTree(BalBiTree T,int TYPE) {
	if (T) {
		if (TYPE == 1) {
			printf("%d ", T->data);
			TaverseBSTree(T->lchild, TYPE);
			TaverseBSTree(T->rchild, TYPE);
		}
		else if (TYPE == 2)
		{
			TaverseBSTree(T->lchild, TYPE);
			printf("%d ", T->data);
			TaverseBSTree(T->rchild, TYPE);
		}
		else
		{
			TaverseBSTree(T->lchild, TYPE);
			TaverseBSTree(T->rchild, TYPE);
			printf("%d ", T->data);
		}
	}
	else
	{
		return;
	}
}

void DeleteBSTree(BalBiTree T, int data) {
	BalBiTree pre;
	int type;
	while (T)
	{
		if (T->data > data)
		{
			pre = T;
			T = T->lchild;
			type = 0;
		}
		else if (T->data < data)
		{
			pre = T;
			T = T->rchild;
			type = 1;
		}
		else
		{
			if (!T->lchild && !T->rchild) {
				if (type == 1) {
					pre->rchild = NULL;
				}
				else
				{
					pre->lchild = NULL;
				}
				free(T);
				return;
			}
			else if (T->lchild && !T->rchild) {
				if (type == 0)  pre->lchild = T->lchild;
				else   pre->rchild = T->lchild;
				free(T); return;
			}
			else if (!T->lchild && T->rchild) {
				if (type == 0) pre->lchild = T->rchild;
				else  pre->rchild = T->rchild;
				free(T);return;
			}
			else {
				BalBiTree s = T;
				s = s->lchild;
				while (s->rchild)
				{
					pre = s;
					s = s->rchild;
				}
				T->data = s->data;
				if (!s->lchild && !s->rchild) {
					free(s);
					return;
				}
				else if (s->lchild && !s->rchild) {
					if (type == 0)  pre->lchild = s->lchild;
					else   pre->rchild = s->lchild;
					free(s); return;
				}
				else if (!s->lchild && s->rchild) {
					if (type == 0) pre->lchild = s->rchild;
					else  pre->rchild = s->rchild;
					free(s);return;
				}
			}
		}
	}
}

int JudBSTree(BalBiTree T,int pre){
	int b1, b2;
	if (T == NULL) return 1;
	else
	{
			b1 = JudBSTree(T->lchild, pre);
			if (pre > T->data || b1 == 0) {
				return 0;
			}
			pre = T->data;
			b2 = JudBSTree(T->rchild, pre);
			return b2;
	}
}

int  JudBBTree(BalBiTree T, int* data) {
	if (!T)
	{
		return 0;
	}
	if (!T->lchild && !T->rchild) {
		return 1;
	}
	int lheight;
	int rheight;
	int lc = JudBBTree(T->lchild, &lheight);
	int rc = JudBBTree(T->rchild, &rheight);
	*data = lheight > rheight ? lheight + 1 : rheight + 1;
	if (JudInt(lc) && JudInt(rc)){
		int e = lheight - rheight;
			if (JudInt(e)) {
				return e;
			}
			else {
				return 2;
			}
	}
	else {
		return 2;
	}
}
int JudInt(int c) {
	if ((c == -1 || c == 0 || c == 1) ){
		return 1;
	}
	else
	{
		return 0;
	}
}
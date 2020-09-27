#ifndef BALANCEDTREE_H_INCLUDED
#define BALANCEDTREE_H_INCLUDED
#include"GlobalVar.h"
typedef struct BalTNode{
	SElemType data;
	struct BalTNode* lchild, * rchild;
}BalTNode,*BalBiTree;
void InsertBSTree(BalTNode*& T, SElemType data);//����������
void CreateBSTree(BalTNode*& T, SElemType data[], int n);//����������
void DeleteBSTree(BalBiTree T, int data);//ɾ���������ڵ�
int JudBSTree(BalBiTree T, int pre);//�ж��Ƿ�Ϊ������

int JudInt(int c);
void InsertBalanceTree(int *data, BalTNode* T);
int JudBBTree(BalBiTree T,int *data);
int SearchBalanceTree(int key, BalTNode* T);
void TaverseBSTree(BalBiTree T,int TYPE);//���ֱ���

#endif // !BALANCEDTREE_H_INCLUDED

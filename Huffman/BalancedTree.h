#ifndef BALANCEDTREE_H_INCLUDED
#define BALANCEDTREE_H_INCLUDED
#include"GlobalVar.h"
typedef struct BalTNode{
	SElemType data;
	struct BalTNode* lchild, * rchild;
}BalTNode,*BalBiTree;
void InsertBSTree(BalTNode*& T, SElemType data);//插入排序树
void CreateBSTree(BalTNode*& T, SElemType data[], int n);//创建排序树
void DeleteBSTree(BalBiTree T, int data);//删除排序树节点
int JudBSTree(BalBiTree T, int pre);//判断是否为排序树

int JudInt(int c);
void InsertBalanceTree(int *data, BalTNode* T);
int JudBBTree(BalBiTree T,int *data);
int SearchBalanceTree(int key, BalTNode* T);
void TaverseBSTree(BalBiTree T,int TYPE);//三种遍历

#endif // !BALANCEDTREE_H_INCLUDED

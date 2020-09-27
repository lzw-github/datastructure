#ifndef THREADEDBINARYTREE_H_INCLUDED
#define THREADEDBINARYTREE_H_INCLUDED
#include"GlobalVar.h"
typedef enum PointerTag{Link,Thread};
typedef char TElemType;
typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode* lchild, * rchild;
	PointerTag LTag, RTag;
}BiThrNode,*BiThrTree;
void CreateBiThrTree(BiThrTree& T);//���򴴽�
void recursiveInOrderThreading(BiThrTree T,BiThrTree &pre);//����������ݹ�
void recursivePreOrderThreading(BiThrTree T, BiThrTree& pre);
void recursivePostOrderThreading(BiThrTree T, BiThrTree& pre);
void Threading(BiThrTree T,int TYPE);

BiThrTree GetPreNext(BiThrTree T);
BiThrTree GetInPre(BiThrTree T);
BiThrTree GetInNext(BiThrTree T);
BiThrTree GetPostPre(BiThrTree T);


void InOrderTaverseThreadedTree(BiThrTree T);//��������
void PreOrderTaverseThreadedTree(BiThrTree T);
void InOrderTaverseThreadedTree_two(BiThrTree T);
#endif // !THREADEDBINARYTREE_H_INCLUDED


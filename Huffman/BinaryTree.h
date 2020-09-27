#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include"GlobalVar.h"
#define maxsize 30

typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;//树节点

typedef BiTNode* STElemType;

typedef struct {
	STElemType* base;
	STElemType* top;
	int size;
	int queuecount;
}Stack, * LStack;//树栈


typedef struct QNodeT {
	STElemType data;
	struct QNodeT* next;
}QNodeT, * QueueTPtr;//树链表节点
typedef struct {
	QueueTPtr front;
	QueueTPtr rear;
}LinkQueueT;//队列

typedef struct HuffMan {
	BiTree node;
	int weight;
	struct HuffMan* next;
}HuffMan, * HuffNode;

void StackInit(LStack& S);//初始化
void StackPush(LStack S, STElemType e);//入栈
STElemType StackPop(LStack S);//弹出
STElemType StackGet(LStack S);//取值
bool StackEmpty(LStack S);//栈空

void QueueTInit(LinkQueueT& Q);//队列操作
void QueueTInsert(LinkQueueT& Q, STElemType e);
STElemType QueueTDelete(LinkQueueT& Q);
int QueueTLength(LinkQueueT Q);
bool QueueTEmpty(LinkQueueT Q);



void CreateBitree(BiTree& T);//先序创建
int PreOrderTraverse(BiTree T, void (*Visit)(TElemType e));//先序非递归
void PreOrderTraverserecursive(BiTree T, void (*Visit)(TElemType e));//先序递归
void InOrderTraverse(BiTree T, void (*Visit)(TElemType e));//中序非递归
void InOrderTraverserecursive(BiTree T, void (*Visit)(TElemType e));//中序递归
void PostOrderTraverse(BiTree T, void (*Visit)(TElemType e));//后序非递归
bool IfPostcur(STElemType e, STElemType cur);
void PostOrderTraverserecursive(BiTree T, void (*Visit)(TElemType e));//后序递归
void LevelOrderTraverse(BiTree T, void (*Visit)(TElemType e));//层序遍历非递归
void TreeDispalyone(TElemType e, int n);
void TreeDispaly(BiTree T);//打印
int TreeDepth(BiTree T);//树的深度
void Visit(TElemType e);
BiTree CreateBitree_Pre_In(TElemType pre[], TElemType In[], int L1, int R1, int L2, int R2);//通过前序中序序列创建二叉树
void PrintPath(BiTree T,TElemType print[ ],int n);//打印二叉树的根节点到所有节点的所有路径




void InsertOrder(HuffNode T, HuffNode node);//顺序插入
HuffNode GetMinNode(HuffNode T);//得到权重最小节点
void HuffManGenerate(HuffNode T);//生成哈夫曼树
void Getcode(char** CodeStorage, BiTree T, char* cd, int n);//生成编码表
void Coding(char* str);//编码
#endif // !BINARYTREE_H_INCLUDED






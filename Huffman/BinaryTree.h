#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include"GlobalVar.h"
#define maxsize 30

typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;//���ڵ�

typedef BiTNode* STElemType;

typedef struct {
	STElemType* base;
	STElemType* top;
	int size;
	int queuecount;
}Stack, * LStack;//��ջ


typedef struct QNodeT {
	STElemType data;
	struct QNodeT* next;
}QNodeT, * QueueTPtr;//������ڵ�
typedef struct {
	QueueTPtr front;
	QueueTPtr rear;
}LinkQueueT;//����

typedef struct HuffMan {
	BiTree node;
	int weight;
	struct HuffMan* next;
}HuffMan, * HuffNode;

void StackInit(LStack& S);//��ʼ��
void StackPush(LStack S, STElemType e);//��ջ
STElemType StackPop(LStack S);//����
STElemType StackGet(LStack S);//ȡֵ
bool StackEmpty(LStack S);//ջ��

void QueueTInit(LinkQueueT& Q);//���в���
void QueueTInsert(LinkQueueT& Q, STElemType e);
STElemType QueueTDelete(LinkQueueT& Q);
int QueueTLength(LinkQueueT Q);
bool QueueTEmpty(LinkQueueT Q);



void CreateBitree(BiTree& T);//���򴴽�
int PreOrderTraverse(BiTree T, void (*Visit)(TElemType e));//����ǵݹ�
void PreOrderTraverserecursive(BiTree T, void (*Visit)(TElemType e));//����ݹ�
void InOrderTraverse(BiTree T, void (*Visit)(TElemType e));//����ǵݹ�
void InOrderTraverserecursive(BiTree T, void (*Visit)(TElemType e));//����ݹ�
void PostOrderTraverse(BiTree T, void (*Visit)(TElemType e));//����ǵݹ�
bool IfPostcur(STElemType e, STElemType cur);
void PostOrderTraverserecursive(BiTree T, void (*Visit)(TElemType e));//����ݹ�
void LevelOrderTraverse(BiTree T, void (*Visit)(TElemType e));//��������ǵݹ�
void TreeDispalyone(TElemType e, int n);
void TreeDispaly(BiTree T);//��ӡ
int TreeDepth(BiTree T);//�������
void Visit(TElemType e);
BiTree CreateBitree_Pre_In(TElemType pre[], TElemType In[], int L1, int R1, int L2, int R2);//ͨ��ǰ���������д���������
void PrintPath(BiTree T,TElemType print[ ],int n);//��ӡ�������ĸ��ڵ㵽���нڵ������·��




void InsertOrder(HuffNode T, HuffNode node);//˳�����
HuffNode GetMinNode(HuffNode T);//�õ�Ȩ����С�ڵ�
void HuffManGenerate(HuffNode T);//���ɹ�������
void Getcode(char** CodeStorage, BiTree T, char* cd, int n);//���ɱ����
void Coding(char* str);//����
#endif // !BINARYTREE_H_INCLUDED






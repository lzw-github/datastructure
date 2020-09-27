#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
#include<cstdlib>
#include"BinaryTree.h"
void StackInit(LStack& S) {
	S = (LStack)malloc(sizeof(Stack));
	S->base = (STElemType*)malloc(maxsize * sizeof(STElemType));
	S->top = S->base;
	S->size = maxsize;
	S->queuecount = 0;
}
void StackPush(LStack S, STElemType e) {
	if (S->base == S->top - S->size)
	{
		return;
	}
	*S->top++ = e;

}
STElemType StackPop(LStack S) {

	if (S->base == S->top) return NULL;
	STElemType e;
	e = *(--S->top);
	
	return e;
}

STElemType StackPopBase(LStack S) {
	if (S->base == S->top) return NULL;
	STElemType e;
	S->queuecount++;
	e = S->base[S->queuecount - 1];
	return e;
}

STElemType StackGet(LStack S) {
	if (S->base == S->top) { return NULL; }
	else { return *(S->top - 1); }
}
bool StackEmpty(LStack S) {
	if (S->base == S->top) 		return 1;
	else	return 0;	
}


void CreateBitree(BiTree& T) {
	char ch = getchar();
	if (ch=='#') {
		T = NULL;
		return;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
}
int maxcount(int a, int b) {
	return a > b ? a : b;
}
int  PreOrderTraverse(BiTree T, void (*Visit)(TElemType e)) {
	LStack S;
	int re = 0;
	StackInit(S);
	StackPush(S, T);
	while (T||!StackEmpty(S))
	{
		if (T){
			Visit(T->data);
			T = T->lchild;
			StackPush(S, T);
		}
		else {
			T = StackPop(S);//if (!StackEmpty(S)){T = StackPop(S);T = T->rchild;StackPush(S, T);}
				if (T) {
					T = T->rchild;
					StackPush(S, T);
				}
			}
		
	}
	return re;
}
void PreOrderTraverserecursive(BiTree T, void (*Visit)(TElemType e)) {
	if (T) {
		Visit(T->data);
		PreOrderTraverserecursive(T->lchild, Visit);
		PreOrderTraverserecursive(T->rchild, Visit);
	}
	else 	return;
	
}
void InOrderTraverse(BiTree T, void (*Visit)(TElemType e)) {
	LStack S;
	StackInit(S);
	StackPush(S, T);
	while (T || !StackEmpty(S))
	{
		if (T) {
			T = T->lchild;
			StackPush(S, T);
		}
		else {
			T = StackPop(S);
			if (T) {
				Visit(T->data);
				T = T->rchild;
				StackPush(S, T);
			}
		}

	}
}
void InOrderTraverserecursive(BiTree T, void (*Visit)(TElemType e)) {
	if (T) {
		PreOrderTraverserecursive(T->lchild, Visit);
		Visit(T->data);
		PreOrderTraverserecursive(T->rchild, Visit);
	}
	else 	return;
}
bool IfPostcur(STElemType e,STElemType cur) {
	if (e) 	return (e->lchild != cur) && (e->rchild != cur);
	else	return 0;
}
void PostOrderTraverse(BiTree T, void (*Visit)(TElemType e)) {
	BiTree cur=T;
	LStack S;
	StackInit(S);
	StackPush(S, T);
	while (T || !StackEmpty(S))
	{
		if ((T = StackGet(S)) && IfPostcur(T,cur)){
			StackPush(S, T->rchild);
			StackPush(S, T->lchild);
		}
		else{
			T = StackPop(S);
			if (T)  Visit(T->data);
			cur = T;
		}
	}

}
void PostOrderTraverserecursive(BiTree T, void (*Visit)(TElemType e)) {
	if (T) {
		PreOrderTraverserecursive(T->lchild, Visit);
		PreOrderTraverserecursive(T->rchild, Visit);
		Visit(T->data);
	}
	else 	return;
}
void LevelOrderTraverse(BiTree T, void (*Visit)(TElemType e)) {
	LStack S;
	StackInit(S);
	StackPush(S, T);
	while (S->top-S->base!=S->queuecount)
	{
		T = StackPopBase(S);
		if (T)
		{
			Visit(T->data);
			StackPush(S, T->lchild);
			StackPush(S, T->rchild);
		}  
	}
}
int TreeDepth(BiTree T) {
	if (!T) return 0;
	int DepthL = 0;
	int DepthR = 0;
	DepthL = TreeDepth(T->lchild);
	DepthR = TreeDepth(T->rchild);

	return DepthL > DepthR ? DepthL + 1 : DepthR + 1;

}


void Visit(TElemType e) {
	printf("%c", e);
}
void TreeDispalyone(TElemType e, int n) {
	for (int i = 0; i < n; i++)
	{
		printf(" ");
	}
	printf("%c", e);
}
void QueueTInit(LinkQueueT& Q) {
	QueueTPtr node = (QueueTPtr)malloc(sizeof(QNodeT));
	node->next = NULL;
	Q.front = node;
	Q.rear = node;
}

void QueueTInsert(LinkQueueT& Q, STElemType e) {
	QueueTPtr node = (QueueTPtr)malloc(sizeof(QNodeT));
	Q.rear->data = e;
	node->next = Q.rear->next;
	Q.rear->next = node;
	Q.rear = node;
}

STElemType QueueTDelete(LinkQueueT& Q) {
	if (Q.front == Q.rear) {
		return 0;
	}
	QueueTPtr s;
	STElemType data;
	data = Q.front->data;
	s = Q.front;
	Q.front = Q.front->next;
	free(s);
	return data;
}
int QueueTLength(LinkQueueT Q) {
	int count = 0;
	while (Q.front != Q.rear)
	{
		count++;
		Q.front = Q.front->next;
	}
	return count;
}
bool QueueTEmpty(LinkQueueT Q) {
	if (Q.front == Q.rear)return 1;
	else return 0;
}
void TreeDispaly(BiTree T) {
	int Depth = TreeDepth(T);
	int count = 1;
	LinkQueueT Queue;
	QueueTInit(Queue);
	QueueTInsert(Queue, T);
	while (count<Depth+1)
	{
		int length = QueueTLength(Queue);
		for (int i = 0; i < length; i++)
		{
			T = QueueTDelete(Queue);
			if (T) {
				if (i == 0) TreeDispalyone(T->data, pow(2, Depth - count) - 1);
				else  TreeDispalyone(T->data, pow(2, Depth - count+1) - 1);
				QueueTInsert(Queue, T->lchild);
				QueueTInsert(Queue, T->rchild);
			}else{
				if (i == 0) TreeDispalyone(' ', pow(2, Depth - count) - 1);
				else  TreeDispalyone(' ', pow(2, Depth - count+1) - 1);
				QueueTInsert(Queue, NULL);
				QueueTInsert(Queue, NULL);
			}
		}
		printf("\n");
		count++;
	}
}


void InsertOrder(HuffNode T, HuffNode node) {
	while (T->next)
	{
		if (node->weight < T->next->weight) {
			node->next = T->next;
			T->next = node;
			return;
		}
		T = T->next;
	}
	T->next = node;
	node->next = NULL;
}
HuffNode GetMinNode(HuffNode T) {
	HuffNode re;
	if (T->next) {
		re = T->next;
	}
	T->next = re->next;
	return re;
}
void HuffManGenerate(HuffNode T) {
	while (T->next->next)
	{
		HuffNode nodeminone, nodemintwo;
		nodeminone = GetMinNode(T);
		nodemintwo = GetMinNode(T);
		HuffNode node = (HuffNode)malloc(sizeof(HuffMan));
		node->node = (BiTree)malloc(sizeof(BiTNode));
		node->weight = nodeminone->weight + nodemintwo->weight;
		node->node->lchild = nodeminone->node;
		node->node->rchild = nodemintwo->node;
		InsertOrder(T, node);
	}
}
void Getcode(char** CodeStorage,BiTree T,char *cd,int n) {
	if (!(T->lchild)&&!(T->rchild)) {
		cd[n] = '\0';
		CodeStorage[T->data] = (char*)malloc(sizeof(char) * (strlen(cd) + 1));
		strcpy(CodeStorage[T->data], cd);
	}
	if (T->lchild) {
		cd[n] = '0';
		Getcode(CodeStorage, T->lchild, cd, n + 1);
	}
	if (T->rchild) {
		cd[n] = '1';
		Getcode(CodeStorage, T->rchild, cd, n + 1);
	}
	
}
void Coding(char* str) {
	int data[256];
	char* convertstr = str;
	for (int i = 0; i < 256; i++)
	{
		data[i] = 0;
	}
	while (*str!='\0')
	{
		data[*str]++;
		str++;
	}
	HuffMan T;
	T.node = NULL;
	T.next = NULL;
	HuffNode p = &T;
	for (int i = 0; i < 256; i++)
	{
		if (data[i] > 0) {
			HuffNode node = (HuffNode)malloc(sizeof(HuffMan));
			node->node = (BiTree)malloc(sizeof(BiTNode));
			node->node->lchild = NULL;
			node->node->rchild = NULL;
			node->weight = data[i];
			node->node->data = i;
			InsertOrder(&T, node);
		}
	}
	HuffManGenerate(&T);
	BiTree huffmantree = T.next->node;
	
	int length = strlen(convertstr);
	char** CodeStorage = (char**)malloc(256 * sizeof(char*));
	char* cd = (char*)malloc((length + 1)*sizeof(char));
	Getcode(CodeStorage, huffmantree, cd, 0);
	while (*convertstr!='\0')
	{
		printf("%s", CodeStorage[*convertstr]);
		convertstr++;
	}
}
BiTree CreateBitree_Pre_In(TElemType pre[], TElemType In[], int L1, int R1, int L2, int R2) {
	BiTree s= (BiTree)malloc(sizeof(BiTNode));
	int i;
	if (L2 > R2) return NULL;
	s->lchild = s->rchild = NULL;
	for (i = L2; i < R2;i++)
	{
		if (In[i] == pre[L1])
			break;
	}
	s->data = In[i];
	s->lchild = CreateBitree_Pre_In(pre, In, L1 + 1, L1 + i - L2, L2, i - 1);
	s->rchild = CreateBitree_Pre_In(pre, In, L1 + i - L2 + 1, R1, i + 1, R2);
	return s;
}
void PrintPath(BiTree T, TElemType print[], int n) {
	if (T) {
		print[n] = T->data;
	}
	else
	{
		return;
	}
	/*
	if(!T->lchild&&!T->rchild){ //打印叶子节点到跟节点
		for (int i = n; i >= 0; i--)
		{
			printf("%c", print[i]);
		}
		printf("\n");
	}*/
	for (int i = n; i >= 0; i--)//打印所有节点到跟节点
	{
		printf("%c", print[i]);
	}
	printf("\n");
	PrintPath(T->lchild, print, n + 1);
	PrintPath(T->rchild, print, n + 1);
	
}
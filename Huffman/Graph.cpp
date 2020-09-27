#include<stdio.h>
#include<malloc.h>
#include<limits.h>
#include <cstdint>
#include"Graph.h"


void InitMGraph(MGraph* M, int* num[], char* info, int nv, int ns) {
	M->n = nv;
	M->e = ns;
	for (int i = 0; i < nv; i++)
	{
		for (int j = 0; j < nv; j++)
		{
			M->edges[i][j] = *(num[i] + j);
		}
		M->vex[i].no = i;
		M->vex[i].info = info[i];
	}
}

int getNextMGraph(MGraph* M,int v, int v0) {
	
	for (int  i = v0+1; i <M->n; i++)
	{
		if (M->edges[v][i] != 0&& M->edges[v][i] != INT16_MAX) {
			return i;
		}
	}
	return -1;
}
void DFS(MGraph* M, int v,int *visit) {
	visit[v] = 1;
	printf("%c", M->vex[v].info);
	int p = getNextMGraph(M, v, -1);
	while (p!=-1)
	{
		if (visit[p] == 0) {
			DFS(M, p, visit);
		}
		p = getNextMGraph(M, v, p);
	}
}
void dfs(MGraph* M) {
	int* visit = (int*)malloc(M->e * sizeof(int));
	for (int i = 0; i < M->n; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < M->n; i++)
	{
		if (visit[i] == 0) {
			DFS(M, i, visit);
		}
	}
}
void InitAGraph(AGraph* A, int nsize, int esize) {
	A->adjlist = (VNode*)malloc(nsize * sizeof(VNode));
	A->e = esize;
	A->n = nsize;
	for (int i = 0; i < nsize; i++)
	{
		A->adjlist[i].firstsrc = NULL;
	}
}
void DFSAGraph(AGraph* A, int v, int* visit) {
	visit[v] = 1;
	ArcNode* p;
	printf("%c", A->adjlist[v].data);
	p = A->adjlist[v].firstsrc;
	while (p!=NULL)
	{
		if (visit[p->adjvex] == 0) {
			DFSAGraph(A, p->adjvex,visit);
		}
		p = p->nextarc;
	}
}
void insertAGraph(AGraph* A, ArcNode* node,int i) {
	ArcNode* p;
	while (A->adjlist[i].firstsrc != NULL)
	{
		p = A->adjlist[i].firstsrc;

		while (p->nextarc != NULL)
		{
			p = p->nextarc;
		}
		p->nextarc = node;
		return;
	}
	A->adjlist[i].firstsrc = node;
}
void GraphConvert(MGraph* M, AGraph* A) {
	for (int k = 0; k < M->n; k++)
	{
		A->adjlist[k].data = M->vex[k].info;
	}
	for (int i = 0; i < M->n; i++)
	{
		for (int j = 0; j < M->n; j++)
		{
			if (M->edges[i][j] !=0&&M->edges[i][j]!=INT16_MAX) {
				ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
				node->adjvex = j;
				node->nextarc = NULL;
				node->info = M->edges[i][j];
				insertAGraph(A, node, i);
			}
		}
	}
}
void dfsa(AGraph* A) {
	int* visit = (int*)malloc(A->n * sizeof(int));
	for (int i = 0; i < A->n; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < A->n; i++)
	{
		if (visit[i] == 0) {
			DFSAGraph(A, i, visit);
		}
	}
}
void BFSAGraph(AGraph* A, int* visit,int v) {
	int rear, front;
	int j;
	rear = front = 0;
	ArcNode* p;
	int* que;
	que = (int*)malloc(sizeof(int) * A->n);
	visit[v] = 1;
	printf("%c", A->adjlist[v].data);
	rear = (rear + 1) % A->n;
	que[rear] = v;
	while (rear!=front)
	{
		front = (front + 1) % A->n;
		j = que[front];
		p = A->adjlist[j].firstsrc;
		while (p!=NULL)
		{
			if (visit[p->adjvex] == 0) {
				printf("%c", A->adjlist[p->adjvex].data);
				visit[p->adjvex] = 1;
				rear = (rear + 1) % A->n;;
				que[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
}
void bfsa(AGraph* A) {
	int* visit = (int*)malloc(sizeof(int) * A->n);
	for (int i = 0; i < A->n; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < A->n; i++)
	{
		if (visit[i] == 0) {
			BFSAGraph(A, visit, i);
		}
	}
}

void BFSMGraph(MGraph* M, int v, int* visit) {
	int rear, front;
	rear = front = 0;
	int i;
	int* que = (int*)malloc(sizeof(int) * M->n);
	visit[v] = 1;
	printf("%c", M->vex[v].info);
	rear = (rear + 1) % M->n;
	que[rear] = v;
	while (rear!=front)
	{
		int j = -1;
		front = (front + 1) % M->n;
		i = que[front];
		j = getNextMGraph(M, i, j);
		while (j!=-1)
		{
			if (visit[j] == 0) {
				visit[j] = 1;
				printf("%c", M->vex[j].info);
				rear = (rear + 1) % M->n;
				que[rear] = j;
			}
			j = getNextMGraph(M, i, j);
		}
	}
}
void bfs(MGraph* M) {
	int* visit = (int*)malloc(M->e * sizeof(int));
	for (int i = 0; i < M->n; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < M->n; i++)
	{
		if (visit[i] == 0) {
			BFSMGraph(M, i, visit);
		}
	}
}
int prim(MGraph* M, int v0, char* path) {
	int sum,k;
	int v;
	int *lowcost = (int*)malloc(M->n * sizeof(int));
	int* vset = (int*)malloc(M->n * sizeof(int));
	*path = M->vex[v0].info;
	for (int i = 0;i < M->n;i++) {
		lowcost[i] = M->edges[v0][i];
		vset[i] = 0;
	}
	vset[v0] = 1;
	sum = 0;
	for (int i = 0; i < M->n-1; i++)
	{
		int min = INT16_MAX;
		for (int j = 0; j <M->n ; j++)
		{
			if (vset[j] == 0 && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
		}
		vset[k] = 1;
		sum = sum + min;
		v = k;
		path++;
		*path = M->vex[v].info;
		for (int j = 0;j < M->n;j++) {
			if (vset[j] == 0 && lowcost[j] > M->edges[v][j]) {
				lowcost[j] = M->edges[v][j];
			}
		}
	}
	return sum;
}
void graphSort(MGraph* M, edges* &road) {
	road = (edges*)malloc(sizeof(edges) * M->e);
	int count = 0;
	for (int i = 0; i < M->n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (M->edges[i][j] != 0 && M->edges[i][j] != INT16_MAX) {
				road[count].a_info = M->vex[i].info;
				road[count].b_info = M->vex[j].info;
				road[count].a_no = i;
				road[count].b_no = j;
				road[count].weight = M->edges[i][j];
				count++;
			}
		}
	}
	edges temp;
	int j;
	for (int  i = 0; i < count; i++)
	{
		temp = road[i];
		j = i - 1;
		while (j>=0&&temp.weight<road[j].weight)
		{
			road[j + 1] = road[j];
			--j;
		}
		road[j + 1] = temp;
	}
	
}
int getRoot(int *v, int a) {
	while (a!=v[a])
	{
		a = v[a];
	}
	return a;
}
int Kruskal(MGraph* M, edges* road) {
	int a, b;
	int sum = 0;
	int* v = (int*)malloc(sizeof(int) * M->n);
	for (int i = 0; i < M->n; i++)
	{
		v[i] = i;
	}
	for (int i = 0; i < M->e; i++)
	{
		a = getRoot(v,road[i].a_no);
		b = getRoot(v, road[i].b_no);
		if (a != b) {
			v[a] = b;
			sum += road->weight;
		}
	}
	return sum;
}
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#define graphSize 5
typedef struct {
	int no;
	char info;
}VertexType;
typedef struct {
	int edges[graphSize][graphSize];
	int n, e;
	VertexType vex[graphSize];
}MGraph;
//�ڽӾ���

typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
	int info;
}ArcNode;
typedef struct {
	char data;
	ArcNode* firstsrc;
}VNode;
typedef struct {
	VNode *adjlist;
	int n, e;
}AGraph;
//�ڽӱ�
typedef struct edges {
	int a_no, b_no;
	int weight;
	char a_info, b_info;
}edges;
void InitMGraph(MGraph* M, int* num[], char* info, int nv, int ns);//��ʼ���ڽӾ���
int getNextMGraph(MGraph* M, int v, int v0);//�õ��ڱ�
void DFS(MGraph* M, int v, int* visit);//����ڽӾ���
void dfs(MGraph* M);//����ڽӾ���


void dfsa(AGraph*A);//�����ӱ�
void GraphConvert(MGraph* M, AGraph* A);//�ڽӾ�����ڽӱ�ת��
void InitAGraph(AGraph* A,int nsize,int esize);//��ʼ���ڽӱ�
void DFSAGraph(AGraph* A, int v,int* visit);//�����ӱ�
void insertAGraph(AGraph* A, ArcNode* node, int i);//������ӱ�

void BFSMGraph(MGraph* M,int v,int *visit);//����ڽӾ���
void bfs(MGraph* M);//����ڽӾ���
void BFSAGraph(AGraph* A, int* visit,int v);//�����ӱ�
void bfsa(AGraph* A);//�����ӱ�
int prim(MGraph* M, int v0, char* path);

void graphSort(MGraph* M, edges* &road);
int getRoot(int* v, int a);
int Kruskal(MGraph* M, edges* road);


#endif // !GRAPH_H_INCLUDED


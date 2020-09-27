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
//邻接矩阵

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
//邻接表
typedef struct edges {
	int a_no, b_no;
	int weight;
	char a_info, b_info;
}edges;
void InitMGraph(MGraph* M, int* num[], char* info, int nv, int ns);//初始化邻接矩阵
int getNextMGraph(MGraph* M, int v, int v0);//得到邻边
void DFS(MGraph* M, int v, int* visit);//深度邻接矩阵
void dfs(MGraph* M);//深度邻接矩阵


void dfsa(AGraph*A);//深度领接表
void GraphConvert(MGraph* M, AGraph* A);//邻接矩阵和邻接表转化
void InitAGraph(AGraph* A,int nsize,int esize);//初始化邻接表
void DFSAGraph(AGraph* A, int v,int* visit);//深度领接表
void insertAGraph(AGraph* A, ArcNode* node, int i);//插入领接表

void BFSMGraph(MGraph* M,int v,int *visit);//广度邻接矩阵
void bfs(MGraph* M);//广度邻接矩阵
void BFSAGraph(AGraph* A, int* visit,int v);//广度领接表
void bfsa(AGraph* A);//广度领接表
int prim(MGraph* M, int v0, char* path);

void graphSort(MGraph* M, edges* &road);
int getRoot(int* v, int a);
int Kruskal(MGraph* M, edges* road);


#endif // !GRAPH_H_INCLUDED


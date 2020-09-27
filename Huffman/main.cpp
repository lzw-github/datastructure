#include<conio.h>
#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include<concrt.h>
#include<cstdlib>
#include<graphics.h>
#include<dos.h>
#include<limits.h>
#include<conio.h>
#include<easyx.h>
#include"LinkList.h"
#include"LinkQueue.h"
#include"LoopQueue.h"
#include"SqList.h"
#include"SqStack.h"
#include"KMP.h"
#include"CatalogueSearch.h"
#include"BinaryTree.h"
#include"ThreadedBinaryTree.h"
#include"Search.h"
#include"BalancedTree.h"
#include"Graph.h"
int main(){
	MGraph M;
	AGraph A;
	//int buff[7][7] = {  {0,1,1,1,1,1,1},
	//					{1,0,1,0,0,0,0},
	//					{1,1,0,0,0,0,0},
	//					{1,0,0,0,1,0,0},
	//					{1,0,0,1,0,0,0},
	//					{1,0,0,0,0,0,1},
	//					{1,0,0,0,0,1,0} };
	int buff[5][5] = { {0,           5,       1,     2,       INT16_MAX},
					   {5,           0,       3,   INT16_MAX,    4},
					   {1,           3,       0,     6,          2},
					   {2,       INT16_MAX,   6,     0,          3},
					   {INT16_MAX,   4,       2,     3,          0} };
	int* graph[5] = { buff[0],buff[1] ,buff[2] ,buff[3] ,buff[4] };
	char* data = "ABCDE";
	InitMGraph(&M, graph, data, 5, 8);
	InitAGraph(&A, 5, 8);
	GraphConvert(&M, &A);
	bfs(&M);
	char path[7];
	edges* road;
	printf("\n%d", prim(&M, 0, path));
	graphSort(&M, road);
	printf("\n%d", Kruskal(&M, road));
	return 0;
	
}

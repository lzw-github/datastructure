#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include"GlobalVar.h"
typedef struct TreeNode {
	TElemType data;
	struct TreeNode* firstchild, * nextsibling;
}CSNode,*CSTree;//�����ֵ���
#endif // !TREE_H_INCLUDED

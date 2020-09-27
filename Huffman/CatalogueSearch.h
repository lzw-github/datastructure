#ifndef CATALOGUESEARCH_H_INCLUDED
#define CATALOGUESEARCH_H_INCLUDED
#include"GlobalVar.h"
typedef struct {
	long position;
	char *index;
}Library;
void BookInsert(char* index, char* book, int* i, Library INDEX[]);
void BookFind(char* index,int i,Library INDEX[]);

#endif // !CATALOGUESEARCH_H_INCLUDED


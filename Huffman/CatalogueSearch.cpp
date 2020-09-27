#include <stdio.h>
#include<malloc.h>
#include<string.h>
#include"CatalogueSearch.h"
void BookInsert(char* index, char* book,int*i,Library INDEX[]) {
	FILE *file = fopen("C:\\Users\\Administrator\\Desktop\\数据结构\\库\\Library.txt", "a+");
	fseek(file, 0L, SEEK_END);
	long position = ftell(file);
	INDEX[*i].position = position;
	INDEX[*i].index = (char*)malloc(strlen(index) * sizeof(char));
	strcpy(INDEX[*i].index, index);
	(*i)++;
	//fprintf(file, "%s ", index);
	fprintf(file, "%s\n", book);
	fclose(file);
}
void BookFind(char* index,int i, Library INDEX[]) {
	FILE* file = fopen("C:\\Users\\Administrator\\Desktop\\数据结构\\库\\Library.txt", "r");
	long position;
	for (int j = 0; j < i; j++)
	{
		if (strcmp(INDEX[j].index, index) == 0) {
			position = INDEX[j].position;

			fseek(file, position, SEEK_SET);
			char ch;
			while ((ch = getc(file)) != '\n')
			{
				putchar(ch);
			}
		}
	}
}

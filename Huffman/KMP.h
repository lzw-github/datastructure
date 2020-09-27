#ifndef KMP_H_INCLUDED
#define KMP_H_INCLUDED

void get_next(char* T, int* next);
void get_nextfix(char* T, int* next);
int KMP(char* S, char* T, int pos);//获取相同字符的前一个字符的位置
int KMPfix(char* S, char* T, int pos);//获取相同字符的第一个字符的位置
void get_nextval(char* T, int* next);
void get_nextvalfix(char* T, int* next);


#endif 


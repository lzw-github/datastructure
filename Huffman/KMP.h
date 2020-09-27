#ifndef KMP_H_INCLUDED
#define KMP_H_INCLUDED

void get_next(char* T, int* next);
void get_nextfix(char* T, int* next);
int KMP(char* S, char* T, int pos);//��ȡ��ͬ�ַ���ǰһ���ַ���λ��
int KMPfix(char* S, char* T, int pos);//��ȡ��ͬ�ַ��ĵ�һ���ַ���λ��
void get_nextval(char* T, int* next);
void get_nextvalfix(char* T, int* next);


#endif 


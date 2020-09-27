#include<stdio.h>
#include<string.h>
#include"KMP.h"

void get_next(char* T, int* next) { //数组[0]不占用,T,next;
	int  i = 1;
	int j = 0;
	int n = strlen(T);
	next[1] = 0;
	while (i < n)
	{
		if (j==0 ||T[i] == T[j]){
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];      
		}
	}
}

int KMP(char* S, char* T, int pos) {//数组[0]不占用,
	int i = pos;
	int j = 1;
	int next[255];
	get_next(T, next);
	while (i < strlen(S) && j < strlen(T)) {
		if (j == 0 || T[j] == S[i]) {
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}

	}
	if (j > strlen(T)-1) {
		return i - strlen(T);
	}
	else
	{
		return 0;
	}
}
int KMPfix(char* S, char* T, int pos) {
	int i = pos;
	int j = 0;
	int next[255];
	get_next(T, next);
	while (i < strlen(S) && j < strlen(T)) {
		if (j == 0 || T[j] == S[i]) {
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}

	}
	if (j > strlen(T) - 1) {
		return i - strlen(T);
	}
	else
	{
		return 0;
	}
}
void get_nextval(char* T, int* next) {
	int  i = 1;
	int j = 0;
	int n = strlen(T);
	next[1] = 0;
	while (i < n)
	{
		if (j == 0 || T[i] == T[j]) {
			i++;
			j++;
			if (T[i] == T[j])	next[i] = next[j];
			else			next[i] = j;
			
		}
		else
		{
			j = next[j];
		}
	}
}

void get_nextfix(char* T, int* next) {
	int j = -1;
	int i = 0;
	next[0] = -1;
	int n = strlen(T);
	while (i<n)
	{
		if (j == -1) {
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			while (T[i]==T[j])
			{
				i++;
				j++;
				next[i] = j;
			}
			j = next[j];
		}
	}
}
void get_nextvalfix(char* T, int* next) {
	int j = -1;
	int i = 0;
	next[0] = -1;
	int n = strlen(T);
	while (i < n)
	{
		if (j == -1) {
			i++;
			j++;
			if (T[i] == T[j]) next[i] = next[j];
			else     next[i] = j;
		}
		else
		{
			while (T[i] == T[j])
			{
				i++;
				j++;
				
				if (T[i] == T[j]) next[i] = next[j];
				else     next[i] = j;
			}
			j = next[j];
		}
	}
}
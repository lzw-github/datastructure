#include<stdio.h>
#include"Search.h"
int  Search_Bin(SElemType *array,int length,SElemType key) {
	int low = 0, high = length - 1;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (array[mid] == key) {
			return mid;
		}
		else if(array[mid]<key){
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
}
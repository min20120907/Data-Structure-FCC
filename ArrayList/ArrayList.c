#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

int *array_init(int size) {
	int *tmp = (int*) malloc(sizeof(int) * size);
       return tmp;	
}

int *array_add(int *arr, int size, int elem) {
	int *tmp = (int*) malloc(sizeof(int)*size + 4);
	int i;
	for (i=0;i<size;i++) tmp[i] = arr[i];	
	tmp[size] = elem;
	return tmp;
}

size_t getSize(int *arr){
	return n = (&arr)[1] - arr;
}

int *array_del(int *arr, int size, int idx) {
	int *tmp = (int*) malloc(sizeof(int) *size -4);
	int i,j;
	
	for(j=0;j<idx;j++) tmp[j] = arr[j];
	for(i=idx; i<size+1;i++) tmp[i] = arr[i+1];
	
	return tmp;
}

void array_print(int *arr, int size){
	int i;
	for(i=0;i<size;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


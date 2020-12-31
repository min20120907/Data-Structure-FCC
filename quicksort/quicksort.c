#include <stdio.h>
#include "partition.h"

void quicksort(int *arr, int s_idx, int e_idx, cmp_fun cmp, swap_fun swap) {
	if(s_idx < e_idx) {	// if the start index is less than end index
		int pivot=partition1(arr, s_idx, e_idx, cmp, swap);	// get pivot
		quicksort(arr, s_idx, pivot-1, cmp, swap);	// sort left
		quicksort(arr, pivot+1, e_idx, cmp, swap);	// sort right 
	}
}

void print_array(int *arr, int size) {
	int i;
	for(i = 0; i<size;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

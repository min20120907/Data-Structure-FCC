#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *merge(int arr[], int front, int mid, int end) {
	// Declare the sizes of subset a and subset b
	int size_a = mid-front+1;
	int size_b = end-(mid+1) +1;
	int a[size_a], b[size_b];

	// copy to tmp arrays
	// proclaim three iterators:
	// i indicates the iterator of a;
	// j indicates the iterator of b;
	// k indicates the iterator of global array arr.
	int i=0, j=0,k=0;
	for(;i<size_a;i++){
		a[i] = arr[front+i];
	}
	for(;j<size_b;j++){
		b[j] = arr[mid+1+j];
	}

	// merge back in-place
	// reset the iterators
	i=0; j=0; k=front;

	// case 1: while the iterations of the both aren't end
	while (i<size_a && j<size_b) {
		if(a[i]<b[j]){
			arr[k] = a[i];
			i++;
		}else {
			arr[k] = b[j];
			j++;
		}
		k++;
	}
	// case 2: while the iteration of a isn't end.
	while(i<size_a){
		arr[k] = a[i];
		i++; k++;
	}
	// case 3: while the iteration of b isn't end.
	while(j<size_b) {
		arr[k] = b[j];
		j++; k++;
	}	
}

void mergesort(int test[], int front, int end){
	if (front < end) {
		int mid = (front+end) / 2;
		mergesort(test, front, mid);
		mergesort(test, mid+1, end);
		merge(test, front, mid, end);
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size ; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int argc, char **argv) {
	int test[] = {9,1,8,2,3,8,4,7,5,6};
	printArray(test, 9);
	mergesort(test,0,8);
	printArray(test, 9);
	return 0;
}

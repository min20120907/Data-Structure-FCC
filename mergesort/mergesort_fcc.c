#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int a[], int p1_n, int n) {
	// r indicates the result buffer
	int *r,i,j,k;
	// allocate the buffer
	r = (int*) malloc(sizeof(int) * n);
	for (i=0,j=p1_n,k=0;k<n;k++) {
		// case 1
		// if(i==p1_n && j<n) r[k] = a[j++];
		// case 2
		// else if(i<p1_n && j<=n && a[i]<a[j]) r[k] = a[i++];
		// case 3 
		// else if(i<p1_n && a[i] && a[i]>=a[j]) r[k] = a[j++];
		// hidden case: when the i and j terminated the partition
		// it never occurs, because the loop terminates when r reaches n
		
		// merged expression
		if(i<p1_n && (j==n || a[i]<a[j])) r[k] = a[i++];
		else r[k] = a[j++];
		
	}
	memcpy(a, r, sizeof(int) * n);
	free(r);
}	

void mergesort(int a[], int n) {
	// proclaim the sizes of the partitions
	int p1_n, p2_n;
	// the base case of recursion
	if(n<2) return;
	// cut in two partitions
	p1_n = n/2; p2_n = n-p1_n;
	// merge two partition back in-place
	mergesort(a, p1_n);
	mergesort(a+p1_n, p2_n);
	merge(a, p1_n, n);
}


void print_array(int a[], int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(int argc, char **argv) {
	int *a, n;
	
	// Input prompt
	printf("Please input the number of array: \n");
	scanf("%d", &n);
	
	// array initial allocation
	a = (int*) malloc(sizeof(int) * n);
	
	// read the values of the array
	int i;
	for (i=0;i<n;i++)
		scanf("%d", &a[i]);
	// test the output
	// print_array(a, n);
	
	// merge sort the array
	mergesort(a, n);

	print_array(a, n);
	// free the array
	free(a);
	return 0;
}

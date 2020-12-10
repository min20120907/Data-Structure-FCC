#include <stdio.h>
#include <stdlib.h>
int swap(int *a, int *b){
	*a += *b;
	*b = *a-*b;
	*a -= *b;
}
int main() {
	int arr[9] = {9,8,2,3,4,7,5,6,1};
	int max=0, min=arr[0];
	// Min max finder
	for (int i = 0;i<9;i++){
		if(arr[i]>max) max=arr[i];
	        if(arr[i]<min) min=arr[i];	
	}
	
	printf("max: %d, min: %d\n", max, min);
	
	printf("Before: \n");
	for(int i=0; i<9; i++) printf("%d ",arr[i]);
	printf("\n");
	// Selection Sorting
	min = arr[0];
	for(int a=0; a<9; a++) {
		for (int i=8;i>=0;i--){
			if(arr[i]<arr[a]){
				min = arr[i];
				swap(&arr[i], &arr[a]);
				printf("Swapping... %d\n", arr[a]);
			}
		}
	}
	
	printf("After: \n");
	for(int i=0; i<9; i++) printf("%d ",arr[i]);
       	printf("\n");
		
	return 0;
}

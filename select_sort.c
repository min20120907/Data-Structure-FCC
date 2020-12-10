#include <stdio.h>
#include <stdlib.h>

// Swap Function
int swap(int *x, int *y){
  int t;
     t   = *x;
    *x   = *y;
    *y   =  t;	
}

// Print Function
void printArray(int *arr, int len){
for(int i=0; i<9; i++) printf("%d ",arr[i]);
}

// Main Function
int main() {
	int arr[9] = {2,5,9,7,100,999,332,444,222};
	int max=0, min=arr[0],min_idx=0;

	// Min max finder
	for (int i = 0;i<9;i++){
		if(arr[i]>max) max=arr[i];
	        if(arr[i]<min) {
			min=arr[i];
			min_idx=i;
		}
	}
	
	printf("max: %d, min: %d\n", max, min);
	
	printf("Before: \n");
	for(int i=0; i<9; i++) printf("%d ",arr[i]);
	printf("\n");
	// Selection Sorting
	
	for(int a=0; a<8; a++) {	// compare 2 numbers
		min_idx = a;	// reset the index
		for (int i=a+1;i<9;i++){	// every 2 numbers compared, we increase the index one more
			if(arr[i] < arr[min_idx]){	// if the number smaller than the minimum in the progress zone, we swap
				min_idx=i;	// update the index
			}
		}
		swap(&arr[a], &arr[min_idx]);	//swap the value
	}
	
	printf("After: \n");
	for(int i=0; i<9; i++) printf("%d ",arr[i]);
       	printf("\n");
		
	return 0;
}

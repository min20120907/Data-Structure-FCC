#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *shiftDown(int key, int *arr, int root_idx, int last_idx){

	return 0;
}
int *heapify(int *arr, int len){
	int idx, root;
	for(idx = len/2; 2 * idx > 0;idx--){
		int left_idx=2*idx, right_idx=2*idx+1, parent_idx=idx/2;
		int self = arr[idx-1], parent = arr[parent_idx-1];
		if(left_idx<=len&&right_idx<=len){
			// if both nodes are valid.
			int left = arr[left_idx-1], right = arr[right_idx-1];
			if(idx == 1){
				// if the index is 1, then it is the root node
				root = self;
				
			}
		}else if(right_idx>len && left_idx<=len){
			// left exist, right gone.
			int left = arr[left_idx-1];

		}else if(right_idx>len && left_idx>len){
			// both gone.
		}
	}
	return NULL;
}

int main(){
	return 0;
}

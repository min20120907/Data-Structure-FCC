#include <stdio.h>
#include "partition.h"
#include "quicksort.h"

// Compare Function
// By the conditions with the following return value
// i1 = i2 -> 0
// i1 < i2 -> -1
// i1 > i2 -> 1
int cmp_int(void *a, int idx1, int idx2) {
	int *i1, *i2;
	i1 = ((int*)a)+idx1; i2 = ((int*)a)+idx2;
	if (*i1 == *i2) {
		return 0;
	} else if (*i1 < *i2) {
		return -1;
	} else {
		return 1;
	}
}

// The swap function in the main program (integer swapping)
void swap_int(void *a, int idx1, int idx2) {
	// proclaim i1 -> the integer-converted idx1th element in a
	// i2 -> the integer-converted idx2th element in a
	int tmp, *i1, *i2;
	i1 = ((int*)a)+idx1; i2 = ((int*)a)+idx2;
	tmp = *i1; *i1 = *i2; *i2 =tmp;
}

int main(int argc, char **argv) {
	int a[14] = {3,2,41,24,21,44,7,4,100,233,432,998,1034,2313};
	printf("Before: ");
	print_array(a, 14);
	quicksort(a, 0,13, cmp_int, swap_int);
	printf("After: ");
	print_array(a,14);
	return 0;
}

#include <stidio.h>

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
	int a[] = {53, 12, 98, 63, 18, 32, 80, 46, 72, 21};
	int p, s_idx=0, e_idx=9;
	
	/* the 7th smallest, index 6 */
	while ((p=partition1(a, s_idx, e_idx, cmp_int, swap_int))!=6) {
		if (p<6) {
			s_idx = p+1;
		} else {
			e_idx = p-1;
		}
	}
	
	printf("pivot[%d] = %d\n", p, a[p]);
	
	return 0;
}

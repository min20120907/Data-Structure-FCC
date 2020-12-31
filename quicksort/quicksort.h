#include "partition.h"
#ifndef quicksort_h
#define quicksort_h
// define a quick sort function
void quicksort(int *arr, int s_idx, int e_idx, cmp_fun cmp, swap_fun swap);
void print_array(int *arr, int size);
#endif

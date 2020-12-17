#ifndef _partition_h
#define _partition_h

// Define each of the comparing function and swap function
typedef int (*cmp_fun) (void *p1, int idx1, int idx2);
typedef void (*swap_fun) (void *p1, int idx1, int idx2);

// Partition Function
// Arguments:
// 1. Unknown Type a
// 2. s_idx -> Start Index
// 3. e_idx -> End index
// 4. cmp -> Compare Function
// 5. swap-> Swap 
int partition1 (void *a, int s_idx, int e_idx, cmp_fun cmp, swap_fun swap);

#endif

#include <stdio.h>
#include "partition.h"

int partition1(void *a, int s_idx, int e_idx, cmp_fun cmp, swap_fun swap)
{
    int lastSmall = s_idx;
    // Iterating from start index to end index
    int i;
    for (i = s_idx + 1; i <= e_idx; i++)
    {
        // compare the start and the iterator between start and end
        if (cmp(a, i, s_idx) < 0)
        {
            lastSmall++;
            swap(a, i, lastSmall);
        }
    }
    swap(a, s_idx, lastSmall);
    return lastSmall;
}

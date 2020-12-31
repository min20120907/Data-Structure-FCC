#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
int main(int argc, char **argv) {
	int arr[] ={1,2,3,4,5}, *r;
	array_print(arr, 5);
	r = array_add(arr, 5, 100);
	array_print(r, 6);
	r= array_del(r, 6, 3);
	array_print(r, 5);
	return 0;
}

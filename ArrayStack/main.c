#include <stdio.h>
#include "array_stack.h"
int main(int argc, char **argv){
	ArrayStackPtr stack = create_array_stack();

	printf("Is full? %d: Is Empty? %d\n", is_full(stack), is_empty(stack));

	free_array_stack(stack);
	return 0;
}

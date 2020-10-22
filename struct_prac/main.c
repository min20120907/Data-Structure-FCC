#include "array_stack.h"
#include <stdio.h>
int main(int argc, char **argv){
	ArrayStack stack = create_array_stack();

	printf("Is full? %d: Is Empty? %d\n", is_full(stack), is_empty(stack));

	free_array_stack(stack);
	return 0;
}

#include "array_stack.h"
#include <stdlib.h>

ArrayStackPtr create_empty_array_stack(){
	ArrayStackPtr stack = (ArrayStackPtr) malloc(sizeof(ArrayStack));
	stack -> top = -1;
	return stack;
}

int is_empty(){
	return stack -> top == -1;
}

int is_full (ArrayStackPtr stack, UserData udata) {
	return stack -> top == 4;
}

UserData pop_value(ArrayStackPtr stack) {
	stack -> top++;
	stack -> data[stack -> top] = udata;
}

UserData peek_value(ArrayStackPtr stack) {
	UserData udata;
	udata = stack->data[stack->top];
	return udata;
}

void free_array_stack(ArrayStackPtr stack) {
	free(stack);
}

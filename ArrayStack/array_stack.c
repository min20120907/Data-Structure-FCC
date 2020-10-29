#include "array_stack.h"
#include <stdlib.h>

ArrayStackPtr create_array_stack(){
	ArrayStackPtr stack = (ArrayStackPtr) malloc(sizeof(ArrayStack));
	stack -> top = -1;
	return stack;
}

int is_empty(ArrayStackPtr stack){
	return stack -> top == -1;
}

int is_full (ArrayStackPtr stack) {
	return stack -> top == 4;
}

void push_value(ArrayStackPtr stack, UserData udata){
	stack -> top++;
	stack->data[stack->top];
}

UserData pop_value(ArrayStackPtr stack) {
	UserData udata;
	udata = stack->data[stack->top];
	stack -> top--;
	return udata;
}

UserData peek_value(ArrayStackPtr stack) {
	UserData udata;
	udata = stack->data[stack->top];
	return udata;
}

void free_array_stack(ArrayStackPtr stack) {
	free(stack);
}

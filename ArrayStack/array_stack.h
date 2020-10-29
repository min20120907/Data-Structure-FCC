#include "user_data.h"
#ifndef _array_stack_h
#define _array_stack_h

typedef struct _ArrayStack{
	int top;
	UserData data[5];
} ArrayStack, *ArrayStackPtr;

ArrayStackPtr create_array_stack();
int is_empty(ArrayStackPtr stack);
int is_full(ArrayStackPtr stack);
void push_value(ArrayStackPtr stack, UserData udata);
UserData pop_value(ArrayStackPtr stack);
UserData peek_value(ArrayStackPtr stack);
void free_array_stack(ArrayStackPtr stack);


#endif 

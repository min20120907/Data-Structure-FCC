#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../ArrayStack/array_stack.h"
#include <string.h>

int main(int argc, char **argv){
	ArrayStackPtr s ;
	while(1){
		char c;
		int a = scanf("%c", &c);
		push_value(s, c);
		if(!a) break;
	}
	return 0;
}

char *to_postfix_s(const char *infix) {
	char *postfix = "";
	int i;
	for (i=0; i<strlen(); i++)
	return postfix
}

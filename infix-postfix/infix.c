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
	char s[10];
	char *c, *result;
	int top = -1, end = -1;
	c = infix;
	result = (char*) malloc(101);

	while(*c != '\0'){
		if(is_operator(*c)){
			if(is_subexpr_end(*c)){
				// pop and output
				char op;
				while((op=s[top--])!='(') {
					result[++end] = op;
				}
			}else{
				// pop higher precedence op
				while(get_precedence(s[top]) > get_precedebce(*c)){
					result[++end] = s[top--];
				}
				s[++top] = *c;
			}
		}else{
			result[++end] = *c;
		}
		c++;
	}

	return s;
}


int is_subexpr_end(char c){
	return c == ')';
}

int is_operator(char c){
	return c=='+' || c=='-' || c=='*' || c=='/' || c='(' || c=')' ;
}
int get_precedence(char c){
	switch(c) {
		case '+': case '-':
			return 1;
		case '*': case '/':
			return 2;
		case '(': case ')':
			return 3;
	}
}

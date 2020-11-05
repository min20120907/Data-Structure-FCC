#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../ArrayStack/array_stack.h"
#include <string.h>
char *to_postfix_s(const char *infix);
int is_operator(char c);
int is_subexpr_end(char c);
int get_precedence(char c);

int main(int argc, char **argv){
	printf("%s\n", to_postfix_s("1+2/3"));
	return 0;
}

char *to_postfix_s(const char *infix) {
	char *s = malloc (sizeof (char) * 10);
	char *c, *result;
	int top = -1, end = -1;
	c = (char *) infix;
	result = (char*) malloc(101);

	while(*c != '\0'){
		if(end!=-1)
			result[++end]=' ';
		if(is_operator(*c)){
			if(is_subexpr_end(*c)){
				// pop and output
				char op;
				while((op=s[top--])!='(') {
					result[++end] = op;
				}
				
			}else{
				// pop higher precedence op
				while(get_precedence(s[top])!=0&&get_precedence(*c)!=0&&get_precedence(s[top]) >= get_precedence(*c)){
					result[++end] = s[top];
					printf("s[top]: %d, *c: %d\n", get_precedence(s[top]), get_precedence(*c));
				}
				s[++top] = ' ';
				s[++top] = *c;
			}
		}else{
			result[++end] = *c;
		}
		c++;
	}
	result = strcat(result, s);

	return result;
}


int is_subexpr_end(char c){
	return c == ')';
}

int is_operator(char c){
	return c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' ;
}
int get_precedence(char c){
	switch(c) {
		case '+': case '-':
			return 1;
			break;
		case '*': case '/':
			return 2;
			break;
		case '(': case ')':
			return 3;
			break;
	}
	return 0;
}

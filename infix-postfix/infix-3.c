#include<stdio.h>
#include<stdlib.h>

int priority(char op) { 
    switch(op) { 
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        default:            return 0;
    } 
}
int is_operator(char c){
        return c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='%' ;
}

char *to_postfix(const char *infix) {
    
    char *postfix = malloc(sizeof(char)*101);
    char *stack = malloc(sizeof(char)*50);

    int i, j, top, k=1;

    for(i = 0, j = 0, top = 0; infix[i] != '\0'; i++){
        
   switch(infix[i]) { 
        case '(': 
            stack[++top] = infix[i]; 
            break; 
        case '+': case '-': case '*': case '/': 
            while(priority(stack[top]) >= priority(infix[i])) { 
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            } 
            if(stack[top+1]!=' '||stack[top]!=' ') stack[++top] = ' ';
            stack[++top] = infix[i];  
            break; 
        case ')': 
           while(stack[top] != '(') { 
                postfix[j++] = stack[top--];
            } 
            top--;  
            break; 
        case ' ': 
        break;
        default:
            postfix[j++] = infix[i];
            while(infix[i+k]==' ')
                k++;
            if(is_operator(infix[i+k])){
                postfix[j++] = ' ';
                k=1;
            }
    }
    }
    if(stack[top+2]!=' ') stack[++top] = ' ';
    while(top > 0) { 
        //printf("stack: %c\n", stack[top--]);
        //top++;
        postfix[j++] = stack[top--];
    }
    int l=0;
    int spaced = 0;
    int spaces = 0;
    while (l<j){	
	if((postfix[l]==' ' && postfix[l+1]==' ' )|| spaced) {
		postfix[l] = postfix[l-1];
		spaces++;
		spaced = 1;
		//printf("too much white spaces");
	}
	l++;
    }
    //printf("%d", spaces);
    int m = 1;
    for(;m<=spaces;m++) postfix[l-m] = 0;

    return postfix;
}
int main(int argc, char**argv){
	puts(to_postfix("(21+3*(2+2)-(4.3+21.79))"));
}




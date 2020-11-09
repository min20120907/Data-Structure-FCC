#include<stdio.h>
#include<stdlib.h>
void removeSubstr (char *string, char *sub) {
	char *match;
	int len = strlen(sub);
	while ((match = strstr(string, sub))) {
		*match = '\0';
		strcat(string, match+len);
	}
}
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

    int i, j, top;

    for(i = 0, j = 0, top = 0; infix[i] != '\0'; i++){
        
   switch(infix[i]) { 
       
        case '(': 
            stack[++top] = infix[i]; 

            break; 
        case '+': case '-': case '*': case '/': 
        while(priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = stack[top--];
                //postfix[j++] = ' ';
            } 
            postfix[j++] = ' ';
            
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
        case '.':
        postfix[j++] = infix[i];
        break;
        default:
            postfix[j++] = infix[i];
    }   
    
    }


    while(top > 0) { 
        
        postfix[j++] = ' ';
        postfix[j++] = stack[top--];
        
    }
    int m = 0;
    int wrong_spaces = 0;
    int *space_indice = malloc(sizeof(int)*100);
    int n = 0;
    for(;m<j;m++){
        if(is_operator(postfix[m+1])&&postfix[m] != ' '){
            wrong_spaces++;
            space_indice[n++] = m+1;
            //printf("space indice: %d \n", m+1);
            char *tmp=malloc(sizeof(char)*100);
            memcpy(tmp, postfix, m+1 );
            
            char *tmp2=malloc(sizeof(char)*100);
            memcpy(tmp2, postfix, strlen(postfix)+1);
            removeSubstr(tmp2,tmp);
            //tmp2 = strcat(" ", tmp2);
            //printf("tmp,tmp2:%s %s\n",tmp,tmp2);
            sprintf(postfix, "%s %s", tmp, tmp2);
            
        }
    }

    //printf("wrong spaces: %d\n", wrong_spaces);
    //printf("new string: %s\n", str);

return postfix;
}
int main(int argc, char **argv)
{
    puts(to_postfix("(21+3*(2+2)-(4.3+21.79))"));
}

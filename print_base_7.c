#include <stdio.h>
#include <stdlib.h>

void print_base7(int n) {
    typedef struct _N {
        int d;
        struct _N *next;
    } N, *NPtr;
    
    NPtr top = NULL;
    
    while (n>0) {
        NPtr node = (NPtr)malloc(sizeof(N));
        node->d = n%7;
        node->next = top;
        top = node;
        n /= 7;
    }
    
    while (top!=NULL) {
        NPtr p = top;
        printf("%c", top->d+'0');
        top = top->next;
        free(p);
    }
}


int main(int argc, char **argv) {
	print_base7(3000);	
	return 0;
}

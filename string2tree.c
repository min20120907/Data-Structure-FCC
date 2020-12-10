#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Tree {
	int value;
	struct _Tree *left, *right;
}intTreeNode, *intTreeNodePtr;

intTreeNodePtr buildTreeFromString(char *s) {
	char a[strlen(s)];
    for (int i = 0; i< strlen(s);i++){
        a[i] =s[i];
    }
    char *word= strtok(a, " ");

    if(strcmp("@",s)==0) return NULL;
    else if(strcmp(word, "@")==0) {
        printf("NULL!!!!\n");
        return NULL;
    }
    else{
        intTreeNodePtr tmp = malloc(sizeof(intTreeNode));
        
        tmp->value = atoi(word);
        
        printf("%d len: %ld\n", atoi(word), strlen(s)-strlen(word));
        int len = strlen(word)+1;
        char b[100];
        strncpy(b, s+len, strlen(s));
        printf("%s\n", b);
        //buildTreeFromString(b);
        tmp->left = buildTreeFromString(b);
        tmp->right = buildTreeFromString(b);
        word = strtok(NULL," ");
        return tmp;
    }
    return NULL;
}
void printInorder(intTreeNodePtr node) 
{ 
    if (node == NULL) 
        return; 
    /* first recur on left child */
    printInorder(node->left); 
    /* then print the data of node */
    printf("%d ", node->value); 
    /* now recur on right child */
    printInorder(node->right); 
} 
  
int main(){
	char *test = "20 @ 30 @ @";
	printf("In-order: ");
	printInorder(buildTreeFromString(test));
	printf("\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int v;
    struct _Node *next;
} Node, *NodePtr;

NodePtr array2list(int a[], int n_elem) {
    int i;
    NodePtr head = NULL;

    for (i=n_elem;--i>=0;) {
        NodePtr n;
        n = (NodePtr)malloc(sizeof(Node));
        n->next = head;
        n->v = a[i];
        head = n;
    }
    return head;
}

int main(int argc, char **argv) {
	NodePtr example = array2list((int[]){1,2,3,4,5});
	return 0;
}

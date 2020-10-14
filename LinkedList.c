#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	double data;
	struct Node *next;
}node, *node_p;

node_p append_node(double member){
	node_p tmp = (node_p) malloc(sizeof(node));
	tmp -> data = member;
	tmp -> next = NULL;
	return tmp;
}

void print_list(node_p head){
	node_p cur = head;
	while(cur != NULL){
		printf("%lf \n", cur->data);
		cur = cur->next;
	}
}

void concat_nodes(node_p a, node_p b){
	a -> next = b;
	b -> next = NULL;
}

int main(int argc, char** argv){
	/*
	node_p a = NULL;
	node_p b = NULL;
	node_p c = NULL;

	a = (node_p) malloc(sizeof(node));
	b = (node_p) malloc(sizeof(node));
	c = (node_p) malloc(sizeof(node));
	
	a -> data = 1.0;
	a -> next = b;

	b -> data = 2.3;
	b -> next = c;
	
	c -> data = 3.75;
	c -> next = NULL;
	*/
	
	node_p head = append_node(4323.123);
	node_p a = append_node(1123.234);
	node_p b = append_node(12342.41);

	//concat_nodes(a, b);
	//print_list(a);
	
	concat_nodes(head, a);
	concat_nodes(a, b);
	
	//concat_nodes(head, a);
	print_list(head);
	
	//free the memory
	free(head);
	free(a);
	free(b);

	return 0;
}

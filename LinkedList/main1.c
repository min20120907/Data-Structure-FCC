#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

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
	
	//head = add_head_node(head, append_node(124));
	head = add_tail_node(head, append_node(123));	
	//concat_nodes(a,b);
	print_list(a);
	
	//free the memory
	free(head);
	free(a);
	free(b);

	return 0;
}

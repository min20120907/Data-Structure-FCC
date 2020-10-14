#include<stdio.h>
#include<stdlib.h>


//Define what is node_p and node
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

//add head node
node_p add_head_node (node_p head, node_p node_ptr){
	node_p new_head;
	new_head = head;
	
	if(node_ptr != NULL){
		node_ptr -> next = head;
		new_head = node_ptr; 
	}

	return new_head;
}


//get the length
int count_list(node_p head){
	node_p cur = head;
	//if nothing inside
	if(cur == NULL){
		return 0;
	}else if(cur->next==NULL){
		return 1;
	}else{
	
	while (cur!=NULL && cur->next!=NULL){
		int counter = 1;
		counter++;
		cur = cur->next;
		return counter;
	}

	}
}

//find tail node
node_p find_tail_node(node_p head){
	node_p cur = head;

	while(cur!= NULL && cur-> next != NULL)
		cur = cur-> next;
	return head;	
}

//add Tail node
node_p add_tail_node (node_p head, node_p node_ptr) {
	node_p tail_ptr;
	tail_ptr = find_tail_node(head);
	if(tail_ptr!=NULL)
		tail_ptr -> next = node_ptr;
	return tail_ptr;
}


//print function
void print_list(node_p head){
	node_p cur = head;
	while(cur != NULL){
		printf("%lf \n", cur->data);
		cur = cur->next;
	}
}

//concatenate the nodes
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

	head = add_head_node(head, a);
		
	//concat_nodes(head, a);
	print_list(head);
	
	//free the memory
	free(head);
	free(a);
	free(b);

	return 0;
}

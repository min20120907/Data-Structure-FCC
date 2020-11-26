#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "../LinkedList/LinkList.h"
queuePtr touchQueue(){
	queuePtr tmp = (queuePtr) malloc(sizeof(queue));
	node_p tmp_data = append_node();
	tmp->head = tmp_data;
	tmp->tail = tmp_data;
	return tmp;
}

void enqueue(queuePtr q, UserData udata){
	node_p node = append_node();
	if(!(q->head)) {
		q->head = node;
		q->tail = node;
	}
	q->tail->next = node;
	q->tail = node;
}

void dequeue(queuePtr q){
	if(q->head == q->tail){
		free(q->head);
		q->head = NULL;
		q->tail = NULL;
	}else {
		node_p curr = q->head;
		q->head = curr->next;
		free(curr);
	}
}

int is_full(queuePtr q){
	return q->tail->next==q->head;
}

int is_empty(queuePtr q){
	return q->tail->next==NULL&&q->head->next==NULL;
}

UserData peek(queuePtr q) {
	return q->head->data;
}

int main(int argc, char **argv){
	
	// Proclaim Queue and the linked list
	queuePtr test = touchQueue();
	node_p new1 = append_node();
	node_p new2 = append_node();
	node_p new3 = append_node();
	
	// Initialize the values
	new1->data = 23.5;
	new2->data = 77.8;
	new3->data = 92.1;

	// connect the nodes into the list
	new1 -> next = new2;
	new2 -> next = new3;
	new3 -> next = NULL;
	printf("Created LinkedList: \n");
	print_list(new1);
	
	// Set both of them into the same arraylist
	test->head=new1;
	test->tail=new3;
	
	printf("head: %lf tail: %lf \n", test->head->data, test->tail->data);
	printf("Peeking value: %lf\n", peek(test));
	
	// enqueuing
	UserData tmp = 222.22;
	enqueue(test, tmp);
	printf("enqueuing......\n");
	printf("head: %lf tail: %lf \n", test->head->data, test->tail->data);
	printf("Peeking value: %lf\n", peek(test));
	
	// dequeuing
	printf("dequeuing......\n");
	dequeue(test);
	printf("head: %lf tail: %lf \n", test->head->data, test->tail->data);
	printf("Peeking value: %lf\n", peek(test));
	return 0;
}

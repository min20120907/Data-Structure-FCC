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

void enqueue(queuePtr q){
	q->tail = q->tail->next;
}

void dequeue(queuePtr q){
	q->head = q->head->next;
}

int is_full(queuePtr q){
	return q->tail->next->data==q->head->data;
}

int is_empty(queuePtr q){
	return q->tail->next->data==-1&&q->head->next->data==-1;
}

int main(int argc, char **argv){
	return 0;
}
